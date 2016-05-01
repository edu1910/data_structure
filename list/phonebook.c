#include <stdio.h>
#include "list.h"

void print_list(T_List* list);

int main()
{
    T_List list = NULL;
    T_ItemList *reg1, *reg2, *reg3;

    create_list(&list, "Gabriel", "234-5678");
    insert_reg(&list, "Eduardo", "123");
    reg2 = insert_reg(&list, "Fabio", "456");
    reg3 = insert_reg(&list, "Zenildo", "789");
    reg1 = insert_reg(&list, "Aldo", "012");
    insert_reg(&list, "Carlos", "345");

    print_list(&list);
    getchar();

    delete_reg(&list, reg1);
    print_list(&list);
    getchar();

    delete_reg(&list, reg2);
    print_list(&list);
    getchar();

    delete_reg(&list, reg3);
    print_list(&list);
    getchar();

    destroy_list(&list);
    print_list(&list);

    return 0;
}

void print_list(T_List* list)
{
    if (LIST_IS_VALID(list))
    {
        T_ItemList* current = *list;

        do
        {
          printf("Contact: %s, %s\n", current->name, current->phone);
          current = current->next;
        } while (current != *list);
    }
    else
    {
        printf("Empty list!\n");
    }
}