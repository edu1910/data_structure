#include <stdlib.h>
#include <string.h>
#include "list.h"

T_ItemList* create_reg(T_List* list, const char* name, const char* phone)
{
    T_ItemList* reg = (T_ItemList*) malloc(sizeof(T_ItemList));

    reg->name = (char*) malloc(strlen(name) + 1);
    strcpy(reg->name, name);

    reg->phone = (char*) malloc(strlen(phone) + 1);
    strcpy(reg->phone, phone);

    return reg;
}

void destroy_reg(T_ItemList* reg)
{
    if (reg->name != NULL)
        free(reg->name);
    if (reg->phone != NULL)
        free(reg->phone);
    free(reg);
}

T_ItemList* create_list(T_List* list, const char* name, const char* phone)
{
    T_ItemList* reg = NULL;

    if ((list != NULL) && (name != NULL) && (phone != NULL))
    {
        reg = create_reg(list, name, phone);

        reg->next = reg;
        reg->prev = reg;

        *list = reg;
    }

    return reg;
}

void destroy_list(T_List* list)
{
    if (LIST_IS_VALID(list))
    {
        while (*list != NULL)
        {
            delete_reg(list, *list);
        }
    }
}

T_ItemList* insert_reg(T_List* list, const char* name, const char* phone)
{
    T_ItemList* reg = NULL;

    if (LIST_IS_VALID(list) && (name != NULL) && (phone != NULL))
    {
        reg = create_reg(list, name, phone);
        T_ItemList* current = *list;
        T_ItemList* next = NULL;

        do
        {
            if (strcmp(name, current->name) < 0)
            {
                next = current;
                break;
            }

            current = current->next;
        } while (current != *list);

        reg->next = current;
        reg->prev = current->prev;
        current->prev = reg;
        reg->prev->next = reg;

        if (next == *list)
            *list = reg;
    }

    return reg;
}

void delete_reg(T_List* list, T_ItemList* reg)
{
    if (LIST_IS_VALID(list) && (reg != NULL))
    {
        if (reg->next == reg)
        {
            destroy_reg(reg);
            *list = NULL;
        }
        else
        {
            reg->prev->next = reg->next;
            reg->next->prev = reg->prev;

            if (*list == reg)
                *list = reg->next;

            destroy_reg(reg);
        }
    }
}

void edit_reg(T_List* list, T_ItemList* reg, const char* name, const char* phone)
{
    //TODO
}

T_ItemList* find_reg(T_List* list, const char* name)
{
    //TODO
    return NULL;
}

T_ItemList* next_reg(T_List* list, T_ItemList* reg)
{
    //TODO
    return NULL;
}

T_ItemList* prev_reg(T_List* list, T_ItemList* reg)
{
    //TODO
    return NULL;
}
