#include "llrec.h"


//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void checkEndLarger(Node*& largeEnd, int pievot){
	if (!largeEnd){
		return;
	}else{
		if (largeEnd->next){
			if (largeEnd->val > pievot && largeEnd->next->val <= pievot){
				largeEnd->next = largeEnd->next->next;
			}
		}
	}
}


void checkEndSmaller(Node*& smallEnd, int peevot){
	if (!smallEnd){
		return;
	}else{
		if (smallEnd->next){
			if (smallEnd->val <= peevot && smallEnd->next->val > peevot){
				smallEnd->next = smallEnd->next->next;
			}
		}
	}
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
	if (!head){
		checkEndSmaller(smaller, pivot);
		checkEndLarger(larger, pivot);
		return;
	}else{
		
		if (head->val <= pivot){
			if (!smaller){
				smaller = head;
				llpivot(head->next, smaller, larger, pivot);
			}else{
				smaller->next = head;
				llpivot(head->next, smaller->next, larger, pivot);
			}
			
		}else if (head->val > pivot){
			if (!larger){
				larger = head;
				llpivot(head->next, smaller, larger, pivot);
			}else{
				larger->next = head;
				llpivot(head->next, smaller, larger->next, pivot);
			}
		}


	}
}

