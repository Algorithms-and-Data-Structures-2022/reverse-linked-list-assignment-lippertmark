#include "assignment/linked_list.hpp"

#include <utility>  // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ > 1) {
      Node* curr = front_;
      Node* prev = nullptr;
      while (curr->next != nullptr) {
        Node* n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
      }
      curr->next = prev;
      Node* ver1 = front_;
      Node* ver2 = back_;
      front_ = ver2;
      back_ = ver1;
    }
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ > 1) {
      reverse_recursive_helper(front_->next, front_);
      Node* ver1 = front_;
      Node* ver2 = back_;
      front_ = ver2;
      back_ = ver1;
      back_->next = nullptr;
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {

    if (curr == nullptr){
      return;
    }
    reverse_recursive_helper(curr->next, curr);
    curr->next = prev;
  }

}  // namespace assignment
