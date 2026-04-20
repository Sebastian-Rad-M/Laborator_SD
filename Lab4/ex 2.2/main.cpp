#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) { val = x; next = NULL; }
};

struct CompareNode {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, CompareNode> minQueue;
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i]) minQueue.push(lists[i]);
    }
    
    ListNode dummyNode(0);
    ListNode* tailNode = &dummyNode;
    
    while (!minQueue.empty()) {
        ListNode* currNode = minQueue.top();
        minQueue.pop();
        tailNode->next = currNode;
        tailNode = tailNode->next;
        if (currNode->next) minQueue.push(currNode->next);
    }
    return dummyNode.next;
}
