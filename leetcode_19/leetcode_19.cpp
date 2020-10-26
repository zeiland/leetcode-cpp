
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr || n <= 0)
        {
            return head;
        }

        ListNode *p = head;
        while (p != nullptr)
        {
            p = p->next;
            --n;
            if (n == 0)
            {
                break;
            }
        }

        if (p == nullptr && n != 0)
        {
            return head;
        }
        if (p == nullptr && n == 0)
        {
            ListNode *ret = head->next;
            delete head;
            return ret;
        }

        p = p->next;
        ListNode *pp = head;
        while (p != nullptr)
        {
            pp = pp->next;
            p = p->next;
        }
        ListNode *rm_ptr = pp->next;
        pp->next = pp->next->next;
        delete rm_ptr;
        return head;
    }
};