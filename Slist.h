#include <stdint.h>
#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

typedef struct _node_ Node;
struct _node_{
    int32_t data;
    Node    *next;
};

typedef struct _slist_ Slist;
struct _slist_ {
    Node    *head;
    Node    *tail;
    uint32_t    length;
};

Slist    slist_new();
uint8_t  slist_lookup(const Slist *list, int32_t key);
uint32_t slist_length(const Slist *list);
Slist*   slist_addnode_head(Slist *list, int32_t val);
Slist*   slist_addnode_tail(Slist *list, int32_t val);
Slist*   slist_del_node_head(Slist *list);
Slist*   slist_del_node_tail(Slist *list);
int32_t slist_max(Slist *list);
int32_t slist_min(Slist *list);
Slist*   add_spec_new(Slist *list, int32_t val, int32_t ele_new );
Slist*  del_spec_new(Slist *list, int32_t ele_new);
Slist* rev_list(Slist *list);
uint32_t compare_list(Slist *list1, Slist *list2);
Slist*  union_list(Slist *uni_list, Slist *list1, Slist *list2);
Slist*  inter_list(Slist *intersec_list, Slist *list1, Slist *list2);
Slist*  unique_ele(Slist* list, uint32_t val);
#endif // SLIST_H_INCLUDED
