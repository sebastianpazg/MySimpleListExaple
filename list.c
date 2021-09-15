#include "list.h"
 
List * create_list(void)
{
        List *head = (List *)malloc(sizeof(List));
        head = NULL;
        return head;
}
 
void destroy_list(List ** list)
{
        while (list != NULL) {
                List * tmp = (*list)->next;
                free(list);
                list = tmp;
        }
        list = NULL;
}
 
int count_elements(List * list)
{
        int counter = 0;
        if (list == NULL) return counter;
        else
        {
                List *current = list;
                do {
                        counter++;
                        current = current->next;
                } while (current != NULL);
        }
        return counter;
}
 
void append_to_list(List ** list, int elem)
{
        if (*list == NULL)
        {
                *list = (List *)malloc(sizeof(List));
                (*list)->value = elem;
                (*list)->next = NULL;
        }
        else
        {
                List *current = *list;
 
                while (current->next != NULL) {
                        current = current->next;
                }
 
                current->next = (List *)malloc(sizeof(List));
                current->next->value = elem;
                current->next->next = NULL;
        }
 
}
 
int get_nth_element(List * list, int index)
{
        int count_ele = count_elements(list);
        if (count_ele > index || index < 0) return -1;
        else
        {
                List * current = list;
                for (int i = 0; i < index-1; i++)
                {
                        current = current->next;
                }
                return current->value;
        }
}
 
void remove_nth_element(List ** list, int index)
{
        if (index == 0)
        {
                List* tmp = NULL;
 
                if (list != NULL) {
                        tmp = (*list)->next;
                        free(*list);
                        *list = tmp;
                }
        }
        else
        {
                List *current = *list;
                List *tmp;
 
                int i = 0;
                while (current->next != NULL && i < index - 1) {
                        current = current->next;
                        i++;
                }
                tmp = current->next;
                current->next = tmp->next;
                free(tmp);
        }
}
 
void clear_list(List * list)
{
        while (list != NULL) {
                List * tmp = list->next;
                free(list);
                list = tmp;
        }
}
 
void insert_to_list(List * list, int elem, int index)
{
        if (index == 0)
        {
                List *current;
                current = (List *)malloc(sizeof(List));
 
                current->value = elem;
                current->next = list;
                list = current;
        }
        else
        {
                int list_size = count_elements(list);
                if (index == list_size) append_to_list(list, elem);
                else
                {
                        List *current = list;
                        List *tmp;
 
                        int i = 0;
                        while (current->next != NULL && i < index - 1) {
                                current = current->next;
                                i++;
                        }
                        tmp = current->next;
                        current->next = (List*)malloc(sizeof(List));
                        current->next->value = elem;
                        current->next->next = tmp;
                }
        }
}
 
void reverse_list(List ** list)
{
        List * p, *pc;
        if (*list)
        {
                pc = *list;
                while (pc->next)
                {
                        p = pc->next;
                        pc->next = p->next;
                        p->next = *list;
                        *list = p;
                }
        }
}
 
void sort_list(List * list)
{
        int swapped, i;
        struct List *ptr1;
        struct List *lptr = NULL;
 
        /* Checking for empty list */
        if (list == NULL)
                return;
 
        do
        {
                swapped = 0;
                ptr1 = list;
 
                while (ptr1->next != lptr)
                {
                        if (ptr1->value > ptr1->next->value)
                        {
                                int temp = ptr1->value;
                                ptr1->value = ptr1->next->value;
                                ptr1->next->value = temp;
                                swapped = 1;
                        }
                        ptr1 = ptr1->next;
                }
                lptr = ptr1;
        } while (swapped);
}
 
void show(List *head)
{
        printf("\n");
        if (head == NULL) printf("List is empty");
        else
        {
                List *current = head;
                do {
                        printf("%i", current->value);
                        printf(" ");
                        current = current->next;
                } while (current != NULL);//może current->next???
 
        }
}