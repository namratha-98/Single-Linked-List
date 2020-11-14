#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "Slist.h"

void test_empty_list(){
    Slist s1= slist_new();
    Slist *list=&s1;
    assert (slist_length(list)==0);
}

void test_add_at_head() {
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert(slist_length(list)==0);
    list=slist_addnode_head(list, 10);
    assert(slist_length(list)==1);
    list = slist_addnode_head(list,20);
    list = slist_addnode_head(list,30);
    assert (slist_length(list)==3);
    assert(slist_lookup(list,20)==1);
}


void test_add_at_tail() {
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert(slist_length(list)==0);
    list=slist_addnode_tail(list, 10);
    assert(slist_length(list)==1);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);
    assert (slist_length(list)==3);
}

void test_delete_head() {
    Slist s1 = slist_new();
    Slist *list=&s1;
    list=slist_addnode_head(list, 10);
    list=slist_addnode_head(list, 20);
    list=slist_addnode_head(list, 30);
    list=slist_delnode_head(list);
    assert(slist_length(list)==2);
    assert(slist_lookup(list,30)==0);
    assert(slist_lookup(list,20)==1);
    list=slist_addnode_head(list, 40);
    list=slist_addnode_head(list, 50);
    assert(slist_length(list)==4);
    //assert(slist_length(list)==3);
}

void test_delete_tail() {
    Slist s1 = slist_new();
    Slist *list=&s1;
    list=slist_addnode_tail(list, 10);
    list=slist_addnode_tail(list, 20);
    list=slist_addnode_tail(list, 30);
    list=slist_delnode_tail(list);
    assert(slist_length(list)==2);
    assert(slist_lookup(list,30)==0);
    assert(slist_lookup(list,20)==1);
    list=(slist_delnode_tail(list));
    //list=slist_addnode_tail(list, 40);
    //list=slist_addnode_head(list, 50);
    assert(slist_length(list)==1);
    assert(slist_lookup(list, 20)==0);
}

void test_max(){

    Slist s1 = slist_new();
    Slist *list=&s1;
    list=slist_addnode_tail(list, 10);
    list=slist_addnode_tail(list, 20);
    list=slist_addnode_tail(list, 30);
    list=slist_addnode_tail(list, 40);
    list=slist_addnode_head(list, 50);
    assert(slist_length(list)==5);
    //assert(slist_lookup(list, 40)==1);
    //assert(slist_lookup(list, 50)==1);
    assert(slist_max(list)==50);
}
void test_min() {
    Slist s1 = slist_new();
    Slist *list=&s1;
    list=slist_addnode_tail(list, 10);
    list=slist_addnode_tail(list, 20);
    list=slist_addnode_tail(list, 30);
    list=slist_addnode_tail(list, 40);
    list=slist_addnode_head(list, 50);
    assert(slist_length(list)==5);
    //assert(slist_lookup(list, 40)==1);
    assert(slist_min(list)==10);
}

void test_add_new_ele() {
    Slist s1 = slist_new();
    Slist *list=&s1;
    list=slist_addnode_tail(list, 10);
    list=slist_addnode_tail(list, 20);
    list=slist_addnode_tail(list, 30);
    list=slist_addnode_tail(list, 40);
    list=slist_addnode_head(list, 50);
    assert(slist_length(list)==5);
    //assert(slist_lookup(list, 40)==1);
    //assert(slist_min(list)==10);
    list=add_spec_new(list,40,60);
    assert(slist_lookup(list,60)==1);
}

void test_del_ele() {
    Slist s1 = slist_new();
    Slist *list=&s1;
    list=slist_addnode_tail(list, 10);
    list=slist_addnode_tail(list, 20);
    list=slist_addnode_tail(list, 30);
    list=slist_addnode_tail(list, 40);
    list=slist_addnode_head(list, 50);
    assert(slist_length(list)==5);
    //assert(slist_lookup(list, 40)==1);
    //assert(slist_min(list)==10);
    list=del_spec_new(list,40);
    assert(slist_lookup(list,40)==0);
}


void test_reverse_elements() {
    Slist s1 = slist_new();
    Slist *list=&s1;
    list=slist_addnode_tail(list, 10);
    list=slist_addnode_tail(list, 20);
    list=slist_addnode_tail(list, 30);
    list=slist_addnode_tail(list, 40);
    list=slist_addnode_head(list, 50);
    assert(slist_length(list)==5);
    rev_list(list);
}

void test_compare_list() {
    Slist s1 = slist_new();
    Slist *list1=&s1;
    Slist s2 = slist_new();
    Slist *list2=&s2;

    list1=slist_addnode_tail(list1, 10);
    list1=slist_addnode_tail(list1, 20);
    list2=slist_addnode_tail(list2, 10);
    list2=slist_addnode_tail(list2, 20);
    //list2=slist_addnode_head(list2, 50);
    assert(compare_list(list1, list2)==1);
}

void test_union_list() {
    Slist s1 = slist_new();
    Slist *list1=&s1;
    Slist s2 = slist_new();
    Slist *list2=&s2;
    Slist s3=slist_new();
    Slist *uni_list=&s3;
    list1=slist_addnode_tail(list1, 10);
    list1=slist_addnode_tail(list1, 20);
    list2=slist_addnode_tail(list2, 10);
    list2=slist_addnode_tail(list2, 20);
    list2=slist_addnode_head(list2, 50);
    uni_list=union_list(uni_list, list1, list2);
    //assert(slist_length(uni_list)==4);
    assert(slist_length(uni_list)==5);
}

void test_intersection_list(){
    Slist s1 = slist_new();
    Slist *list1=&s1;
    Slist s2 = slist_new();
    Slist *list2=&s2;
    Slist s3 = slist_new();
    Slist *intersec_list=&s3;

    list1=slist_addnode_tail(list1, 10);
    list1=slist_addnode_tail(list1, 20);
    list1=slist_addnode_tail(list1, 50);
    list2=slist_addnode_tail(list2, 30);
    list2=slist_addnode_tail(list2, 40);
    list2=slist_addnode_head(list2, 50);
    intersec_list=inter_list(intersec_list, list1, list2);
    assert(slist_length(intersec_list)==1);
    //assert(slist_length(intersec_list)==2);

}

void test_unique_elements(){
    Slist s1 = slist_new();
    Slist *list=&s1;
    list=slist_addnode_tail(list, 10);
    list=slist_addnode_tail(list, 20);
    list=slist_addnode_tail(list, 30);
    list=unique_ele(list,40);
    //list=unique_ele(list,10);
    assert(slist_length(list)==4);
    //assert(slist_length(list)==5);
}
int main(){

   // printf("Hello world!\n");
   //test_empty_list();
   //test_add_at_head();
   //test_add_at_tail();
   //test_delete_head();
   //test_delete_tail();
   //test_max();
   //test_min();
   //test_add_new_ele();
   //test_del_ele();
   //test_reverse_elements();
    //test_compare_list();
    //test_union_list();
    //test_intersection_list();
    //test_unique_elements();
    return 0;
}

