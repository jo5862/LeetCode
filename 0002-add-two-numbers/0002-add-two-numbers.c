
struct ListNode {
      int val;
      struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        struct ListNode dummy;  // 결과 저장을 위한 더미(dummy) 노드
    struct ListNode* curr = &dummy;
    dummy.next = NULL;
    
    int carry = 0;  // 올림수 초기화
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int val1 = (l1 != NULL) ? l1->val : 0;  // l1 값 가져오기
        int val2 = (l2 != NULL) ? l2->val : 0;  // l2 값 가져오기
        
        int sum = val1 + val2 + carry;  // 자리수 덧셈 + 올림수
        carry = sum / 10;  // 올림수 계산
        
        // 새로운 노드 생성 및 연결
        curr->next = createNode(sum % 10);
        curr = curr->next;
        
        // 다음 노드로 이동
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
            }
    
    return dummy.next;  // 첫 번째 실제 노드 반환
}

// 연결 리스트 출력 함수
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// 연결 리스트 해제 함수 (메모리 누수 방지)
void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}