#include "euler.hpp"

using namespace std;
using namespace euler;

// time to build a beautiful tree
struct CollatzNode {
    long value;
    vector<CollatzNode*> children;

    CollatzNode(long val) : value(val) {

    }

    void addChild(CollatzNode* node) {
        children.push_back(node);
    }

    void print() {
        vector<CollatzNode*> q;
        for (CollatzNode* node : children) {
            q.push_back(node);
        }

        long counter = 1;
        while (q.size()>0) {
            vector<CollatzNode*> new_q;
            long last_value = 0;
            for (size_t i=0; i < q.size(); i++) {
                CollatzNode* node = q[i];
                last_value = node->value;
                for (CollatzNode* child: node->children) {
                    new_q.push_back(child);
                }
            }

            // cout << "\n";
            // empty out vector
            q = new_q;
            counter++;
            if (q.size() == 0) {
                cout << "Level " << counter << " Number " << last_value << "\n";
            }
        }
    }
};

void add_node(long i, std::unordered_map<size_t, std::optional<CollatzNode*>>& imap) {
    // cout << "attempting to add node " << i << "\n";
    if (imap.count(i) > 0) {
        // cout << "node " << i << " aleady added, leaving\n";
        return;
    }
    // create node and link it
    imap[i] = new CollatzNode(i);

    // try to add the next node
    long nextNode = 0;
    if (i%2 == 0) {
        nextNode = i/2;
    } else {
        nextNode = i*3+1;
    }
    add_node(nextNode, imap);

    // then link it
    CollatzNode* child = imap[i].value();
    imap[nextNode].value()->addChild(child);
}

void build_tree(long counter) {
    std::unordered_map<size_t, std::optional<CollatzNode*>> imap;
    CollatzNode* root = new CollatzNode(1);
    imap[1] = root;

    for (long i=2; i < counter; i++) {
        add_node(i, imap);
    }

    // print depth
    imap[1].value()->print();
}


int main(int, char**) {
    build_tree(1000000);
    return 0;
}
