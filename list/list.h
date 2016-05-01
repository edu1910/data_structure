#ifndef _LIST_H_
#define _LIST_H_

#define LIST_IS_VALID(list) (list != NULL) && (*list != NULL)

typedef struct S_ItemList
{
    char* name;
    char* phone;

    struct S_ItemList* prev;
    struct S_ItemList* next;
} T_ItemList;

typedef T_ItemList* T_List;

T_ItemList* create_list(T_List* list, const char* name, const char* phone);
void destroy_list(T_List* list);
T_ItemList* insert_reg(T_List* list, const char* name, const char* phone);
void delete_reg(T_List* list, T_ItemList* reg);
void edit_reg(T_List* list, T_ItemList* reg, const char* name, const char* phone);
T_ItemList* find_reg(T_List* list, const char* name);
T_ItemList* next_reg(T_List* list, T_ItemList* reg);
T_ItemList* prev_reg(T_List* list, T_ItemList* reg);

#endif
