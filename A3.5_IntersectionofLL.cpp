static int get_length(LinkedListNode* head) {
  int list_length = 0;
  while(head != nullptr) {
    head = head->next;
    list_length++;
  }
  return list_length;
}

LinkedListNode* intersect(
    LinkedListNode* head1,
    LinkedListNode* head2) {
  
  LinkedListNode* list1node = nullptr;
  int list1length = get_length(head1);
  LinkedListNode* list2node = nullptr;
  int list2length = get_length(head2);

  int length_difference = 0;
  if(list1length >= list2length) {
    length_difference = list1length - list2length;
    list1node = head1;
    list2node = head2;
  } else {
    length_difference = list2length - list1length;
    list1node = head2;
    list2node = head1;
  }

  while(length_difference > 0) {
    list1node = list1node->next;
    length_difference--;
  }

  while(list1node != nullptr) {
    if(list1node == list2node) {
      return list1node;
    }
    list1node = list1node->next;
    list2node = list2node->next;
  }
  return nullptr;
}

int main(int argc, char* argv[]) {
    vector<int> v1 = {1, 2, 3, 4 , 5};
    LinkedListNode* list_head_1 = LinkedList::create_linked_list(v1);

    vector<int> v2 = {5, 4, 3, 2, 1};
    LinkedListNode* list_head_2 = LinkedList::create_linked_list(v2);
    
    LinkedListNode* intersect_node = intersect(list_head_1, list_head_2);
    assert(intersect_node == nullptr);

    LinkedListNode* node1 = new LinkedListNode(8);
    LinkedListNode* node2 = new LinkedListNode(9);

    LinkedList::insert_at_tail(list_head_1,node1);
    LinkedList::insert_at_tail(list_head_1,node2);

    LinkedList::insert_at_tail(list_head_2,node1);

    intersect_node = intersect(list_head_1, list_head_2);
    printf("\nIntersection node: %d", intersect_node->data);
    assert(intersect_node == node1);

    assert(intersect(nullptr, nullptr) == nullptr);

}
