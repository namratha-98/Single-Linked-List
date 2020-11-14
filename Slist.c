#include <stdlib.h>
#include <assert.h>
#include "Slist.h"

Slist       slist_new() {
    Slist s1= {NULL, NULL, 0};
    return s1;
}
uint32_t slist_length(const Slist *list){
    assert (list!=NULL);
    return list->length;
}

//helper function which is not visible outside

static Node*    _get_new_node(int32_t val){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=NULL;

    return newnode;

}

//Adding a head node
Slist*  slist_addnode_head(Slist *list, int32_t val){
    assert(list!=NULL);
    Node *new_node = _get_new_node(val);

    new_node->next=list->head;
    list->head=new_node;
    if(list->tail==NULL){
        list->tail=new_node;
    }
    ++list->length;


    assert((list->length==1&&list->head==list->tail) ||
           (list->length>1 && list->head!=list->tail)
           );
    return list;
}

//Adding tail node
Slist* slist_addnode_tail(Slist *list, int32_t val){
    assert(list!=NULL);
    Node *new_node=_get_new_node(val);
    if(list->tail != NULL){
        list->tail->next=new_node;
        list->tail=new_node;
    }else{
        list->head=list->tail=new_node;
    }
    ++list->length;
    assert((list->length==1 && list->head==list->tail) ||
            (list->length>1 && list->head !=list->tail));

    return list;
}

//Searching a node
uint8_t slist_lookup(const Slist *list, int32_t key) {
    assert(list!=NULL);
    Node *cur=list->head;

    for (cur=list->head; cur!=NULL; cur=cur->next){
        if(cur->data==key){
            break;
        }

    }
    return (cur!=NULL);//return zero if cur not equal to Null
}
//deleting a node in head
Slist* slist_delnode_head(Slist *list){
	assert(list!=NULL);
	Node *temp;
	if(list->head != NULL){
		temp = list->head;
		list->head = list->head->next;
		if(list->head == NULL){
			list->tail=NULL;            // if only one node is there and we deleted it so tail should also be null
		}
		--list->length;
		free(temp);
	}
	return list;
}

//deleting a node in tail
Slist* slist_delnode_tail(Slist *list){
	assert(list!=NULL);
	Node *last, *cur;
	cur=list->head;
	if(list->tail!=NULL){
		last=list->tail;
		if(list->head==list->tail){
            list->head=list->tail=NULL;
		}
	else{
		for(cur=list->head;cur->next!=last;cur=cur->next);
		list->tail=cur;
		cur->next=NULL;
	}
		--list->length;
		free(last);
	}

	return list;
}

//Maximum element in the list
int32_t slist_max(Slist *list){
    assert(list!=NULL);
    Node *cur=list->head;
    int32_t max_element=0;
    while(cur!=NULL){
        if(cur->data>max_element){
            max_element=cur->data;
        }
        cur=cur->next;
    }
    return max_element;
}

//Minimum element in the list
int32_t slist_min(Slist *list){
    assert(list!=NULL);
    Node *cur=list->head;
    int32_t min_element=list->head;
    while(cur!=NULL){
        if(cur->data<min_element){
            min_element=cur->data;
        }
        cur=cur->next;
    }
    return min_element;
}

//Add new element after a specified element
Slist* add_spec_new(Slist *list, int32_t ele_new, int32_t val){
    assert(list!=NULL);
    Node *new_node=_get_new_node(val);
    Node *cur;
    for(cur=list->head;cur!=NULL;cur=cur->next){
        if(cur->data==ele_new)
        {
            new_node->next=cur->next;
            cur->next=new_node;
            if(cur->next==NULL){
                assert(cur->next==NULL);
                list->tail=new_node;
            }
        }
    }
    ++list->length;
    return list;
}

//Delete specified element from the list

Slist*  del_spec_new(Slist *list, int32_t ele_new){
    assert(list!=NULL);
    Node *last, *cur;
    last->next=NULL;
    cur=list->head;
    if(list->length==1){
        list->head=NULL;
        list->tail=NULL;
        list->length=0;
    }
    else if(cur!=NULL && cur->data==ele_new){
        list->head=cur->next;
        --list->length;
        return list;
    }
    else{
        for(cur=list->head;cur!=NULL;cur=cur->next){
            if(cur->data==ele_new){
                last->next=cur->next;
            }
            last=cur;
        }
        free(cur);
        --list->length;
    }
    return list;

}

//Reverse the list
Slist* rev_list(Slist *list){
assert(list!=NULL);
Node *last=NULL, *cur, *cur_temp, *temp=NULL;
cur=list->head;
cur_temp=cur;
while(cur!=NULL){
    temp=cur->next;
    cur->next=last;
    last=cur;
    cur=temp;
}
list->tail=cur_temp;
list->head=last;
return list;
}


//Comparing list
uint32_t compare_list(Slist *list1, Slist *list2){
    assert(list1!=NULL);
    assert(list2!=NULL);
    Node *cur_list1, *cur_list2;
    cur_list1=list1->head;
    cur_list2=list2->head;
    while(cur_list1!=NULL && cur_list2!=NULL){
        if(cur_list1->data == cur_list2->data){
            return 1;
        }
    else{
        return 0;
    }
    cur_list1=cur_list1->next;
    cur_list2=cur_list2->next;
    }
    return(list1==NULL && list2==NULL);

}

//Union of two lists
Slist*  union_list(Slist *uni_list, Slist *list1, Slist *list2){
    assert(list1!=NULL);
    assert(list2!=NULL);
    Node *cur_list1, *cur_list2;
    cur_list1=list1->head;
    cur_list2=list2->head;
    while(cur_list1!=NULL){
        if(!(slist_lookup(uni_list, cur_list1->data))){
            uni_list=slist_addnode_tail(uni_list, cur_list1);
        }
        cur_list1=cur_list1->next;
    }
    while(cur_list2!=NULL){
        if(!(slist_lookup(uni_list, cur_list2->data))){
            uni_list=slist_addnode_tail(uni_list, cur_list2);
        }
        cur_list2=cur_list2->next;
    }
    return uni_list;

}

//intersection of two lists
Slist*  inter_list(Slist *intersec_list, Slist *list1, Slist *list2){
    assert(list1!=NULL);
    assert(list2!=NULL);

    Node *cur_list1, *cur_list2;
    cur_list1=list1->head;
    cur_list2=list2->head;
    while(cur_list1!=NULL){
        if(slist_lookup(list2, cur_list1->data)){
            intersec_list=slist_addnode_tail(intersec_list, cur_list1->data);

        }
        cur_list1=cur_list1->next;
    }
return intersec_list;
}


//Lists with only unique elements
Slist*  unique_ele(Slist* list, uint32_t val){
    assert(list!=NULL);
    Node *cur;
    cur=list->head;
    while(cur!=NULL){
        if(!(slist_lookup(list, val))){
            list=slist_addnode_tail(list, val);
        }
        cur=cur->next;
    }
    return list;
}
