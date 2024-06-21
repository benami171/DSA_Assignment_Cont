#include <stdio.h>

int main() {
    int pos, i, val, choice, size, flag = 0, len= 0;

    printf("Enter the maximum size of the array (up to 10): ");
    scanf("%d", &size);

    if (size > 10 || size <= 0) {
        printf("Invalid size. Size must be between 1 and 10.\n");
        return 1;
    }

    int arr[size];

    for (i = 0; i < size; i++) {
        arr[i] = 0;
    }

    while (1) {
       err:
       printf("\n1.Print \n2.Update\n3.Search\n4.Insert\n5.Delete (bonus)\n0.EXIT");
       printf("\n\nEnter choice: ");
       scanf("%d", &choice);

       if(choice == 1) {
            printf("\nEnter the index to print: ");
            scanf("%d", &pos);
            printf("\nThe val at index %d: %d", pos, arr[pos]);

       }else if (choice == 2){
            printf("\nEnter the index to update: ");
            scanf("%d", &pos);
            printf("\nEnter the new value: ");
            scanf("%d", &val);
            arr[pos] = val;
            printf("The new val at index %d: %d", pos, arr[pos]);

        }else if (choice == 3){

            printf("Enter the value you want to search: \n");
            scanf("%d", &val);

            for (i = 0; i < size; i++) {
                if (arr[i] == val) {
                    flag++;
                    printf("%d found at index %d\n", val, i);
                }
            }
            if (flag == 0) {
                printf("Not found\n");
            }
        }else if (choice == 4){

            printf("Enter the position where you want to insert : ");
            scanf("%d", &pos);

            if (pos < 0 || pos > len || len ==size) {
                printf("Invalid position\n");
                break;
            }

            printf("The value you want to insert: ");
            scanf("%d", &val);

            if (pos == len) {
                arr[len] = val;
            }
            else{
                for (int i = len; i > pos; i--) {
                    arr[i] = arr[i-1];
                }
                    arr[pos] = val;
            }
                len++;

            printf("\nCurrent arraylist: \n");
            for (i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }

        }else if (choice == 5) {
            printf("Current array: \n");
            for (i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            int pos;
            printf("The Position of Element/Value you want to delete: ");
            scanf("%d", &pos);
            if (pos > size) {
                printf("Index out of bounds. Give choice again\n");
                goto err;
            }

            else{
                for(int i= pos; i<size-1;i++){
                    arr[i]= arr[i+1];
                }
            }
            printf("Updated array: \n");
            for (i = 0; i < size; i++) {
                printf(" %d", arr[i]);
            }
            printf("\n");
        }
        else if (choice == 0) {
            printf("Thank you\n");
            break;
        }
        else {
            printf("Invalid choice. Select again: \n");
        }
    }

    return 0;
}
