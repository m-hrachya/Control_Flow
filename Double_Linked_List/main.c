#include "double_linked_list.h"

int main() {
    DLL * double_linked_list;
    construct_list(&double_linked_list);
    push_back(double_linked_list, 12);
    push_front(double_linked_list, 24);
    insert(double_linked_list, 1, 128);
    print_dll(double_linked_list);
    destroy_list(&double_linked_list);
}