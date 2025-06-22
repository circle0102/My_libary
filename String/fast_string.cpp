#include <iostream>
#include <string>
#include <vector>
#include <stack>

// ここから: FastString ライブラリ（ロープ実装）
namespace faststring {

struct Node {
    Node* left;
    Node* right;
    std::string* leaf;
    size_t len;
    // leaf node
    Node(std::string* s) : left(nullptr), right(nullptr), leaf(s), len(s->size()) {}
    // internal node
    Node(Node* l, Node* r) : left(l), right(r), leaf(nullptr), len(0) {
        if (l) len += l->len;
        if (r) len += r->len;
    }
};

class FastString {
public:
    FastString() : root(nullptr) {}
    // クリア
    void clear() {
        root = nullptr;
    }
    // 末尾にマージ (O(1))
    void merge(const FastString &other) {
        if (!other.root) return;
        if (!root) {
            root = other.root;
        } else {
            root = new Node(root, other.root);
        }
    }
    // 文字列リテラルを末尾に追加
    void merge_literal(const std::string &s) {
        if (s.empty()) return;
        std::string* ps = new std::string(s);
        Node* leaf = new Node(ps);
        if (!root) root = leaf;
        else root = new Node(root, leaf);
    }
    // 完全置換 (O(1))
    void replace(const FastString &other) {
        root = other.root;
    }
    // 結果を取得
    std::string to_string() const {
        if (!root) return std::string();
        std::string out;
        out.reserve(root->len);
        // iterative flatten
        std::stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* cur = st.top(); st.pop();
            if (!cur) continue;
            if (cur->leaf) {
                out.append(*cur->leaf);
            } else {
                // push right then left for correct order
                if (cur->right) st.push(cur->right);
                if (cur->left)  st.push(cur->left);
            }
        }
        return out;
    }

private:
    Node* root;
};

} // namespace faststring

int main() {
    using namespace std;
    using namespace faststring;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//コード例　ABC411 D
  /*
  FastString A;  　　　FastString型の文字列
  A.replace(B)  　　　　AをBで置換
  A.merge_literal(B);  Aの後ろにBをマージ
  server.to_string();  結果を取得
  */
    int N, Q;
    cin >> N >> Q;

    vector<FastString> pc(N + 1);
    FastString server;

    for (int i = 0; i < Q; ++i) {
        int type, p;
        cin >> type >> p;
        if (type == 1) {
            pc[p].replace(server);
        } else if (type == 2) {
            string s;
            cin >> s;
            pc[p].merge_literal(s);
        } else if (type == 3) {
            server.replace(pc[p]);
        }
    }

    cout << server.to_string();
}
