#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
//#include <unistd.h>
 
 
main(int argc, char **argv)
{
        int index;
        int c;
        List *head;
        head = create_list();
        opterr = 0;
 
        while ((c = getopt(argc, argv, "pc:a:")) != -1)
                switch (c)
                {
                case 'p':
                        show(head);
                        break;
                case 'a':
                        while ((optind < argc) && (argv[optind][0] != '-'))
                        {
                                // more arguments
                                append_to_list(&head, argv[optind]);
                                ++optind;
                        }
                        printf("\n");
                        break;
                case 'c':
                        clear_list(head);
                        break;
                case 'd':
                        while ((optind < argc) && (argv[optind][0] != '-'))
                        {
                                // more arguments
                                remove_nth_element(&head, argv[optind]);
                                ++optind;
                        }
                        printf("\n");
                        break;
                case 's':
                        sort_list(head);
                        break;
 
                case 'r':
                        reverse_list(&head);
                        break;
                default:
                        abort();
                }
 
        printf("end of parsing \n");
 
        for (index = optind; index < argc; index++)
                printf("Non-option argument %s\n", argv[index]);
 
        return 0;
}