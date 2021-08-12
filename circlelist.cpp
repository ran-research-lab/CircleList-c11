#include "circlelist.h"
#include <string>
#include <sstream>
using namespace std;
CircleList::CircleList() : cursor(NULL) { }
CircleList:: ~CircleList() { while (!empty()) remove(); }
bool CircleList::empty() const { return cursor == NULL; }
const Elem& CircleList::back() const { return cursor->elem; }
const Elem& CircleList::front() const { return cursor->next->elem; }
void CircleList::advance()
{ cursor = cursor->next; }


void CircleList::add(const Elem& e) {
    CNode* v = new CNode;
    v->elem = e;
    if (cursor == NULL) {
        v->next = v; cursor = v;
    }else {
        v->next = cursor->next;
        cursor->next = v; }

}
void CircleList::remove() { CNode* old = cursor->next; if (old == cursor)
        // remove node after cursor // the node being removed // removing the only node? // list is now empty
        // link out the old node // delete the old node
        cursor = NULL;
    else
        cursor->next = old->next; delete old;
                          }
string CircleList::toString() const{
    stringstream ss;
    CNode *curr = cursor;
    if (curr != NULL)  {
        ss << curr->elem <<  " ";
        curr = curr->next;
        while (curr != cursor) {
            ss << curr->elem <<  " ";
            curr = curr->next;
        }
    }
    return ss.str();
}
