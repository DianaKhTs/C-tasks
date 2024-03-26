#include "array.c"
void create_sorted_array(struct sorted_array* arr,int  n)
{

	for (int i = 0; i < n; i++){
        scanf("%d", &(arr[i]._val));
        printf("%x\n", &(arr[i]._val));
    }
    InsertSort(arr, arr+n-1);
    //printf("%x", &(arr[0]._val));
   // printf(" arrray created\n");
}

void test_1(){
    int n;
    scanf("%d",&n);
    printf("type %d elements: ", n);
    struct sorted_array arr[n];
    create_sorted_array(arr, n); 
    struct iterator it = iter_begin(arr);
    print_array(arr, n);

    while(it.cur != iter_end(arr, n).cur){
        //printf("%d ", it.cur->_val);
        iter_inc(&it);
    }

    add_elem(iter_begin(arr), iter_end(arr,n), 5);
    printf("elem is added\n");

    
    
}

void test_2(){
    int n;
    scanf("%d",&n);
    printf("type %d elements: ", n);
    struct sorted_array arr[n];
    create_sorted_array(arr, n); 
    struct iterator it = iter_begin(arr);
    print_array(arr, n);
    add_elem(iter_begin(arr), iter_end(arr,n++), 6);
    printf("elem is added\n\n");
    printf("found address: %x", find_elem(iter_begin(arr), iter_end(arr, n+1), 7));
    
}

void test_3(){
    int n;
    scanf("%d",&n);
    printf("type %d elements: ", n);
    struct sorted_array arr[n];
    create_sorted_array(arr, n); 
    struct iterator it = iter_begin(arr);
    print_array(arr, n);
    add_elem(iter_begin(arr), iter_end(arr,n++), 6);
    print_array(arr, n);
    printf("elem is added\n\n");
    int rem_el = arr[5]._val;
    rem_elem(iter_begin(arr), iter_end(arr,n),arr[5]._val);
    print_array(arr, n);
    printf("found address: %x", find_elem(iter_begin(arr), iter_end(arr, n+1), 5));


}

void test_4(){
    int n;
    scanf("%d",&n);
    printf("type %d elements: ", n);
    struct sorted_array arr[n];
    create_sorted_array(arr, n); 
    struct iterator it = iter_begin(arr);
    print_array(arr, n);

    while(it.cur != iter_end(arr, n).cur){
        //printf("%d ", it.cur->_val);
        iter_inc(&it);
    }

    add_elem(iter_begin(arr), iter_end(arr,n++), 5);
    printf("elem is added\n\n");
    add_elem(iter_begin(arr), iter_end(arr,n++), 10);
    printf("elem is added\n\n");
    int rem_el = arr[1]._val;
    rem_elem(iter_begin(arr), iter_end(arr,n--), 1);
    print_array(arr, n);
    printf("%d is removed\n\n", rem_el);
    rem_el = arr[2]._val;
    rem_elem(iter_begin(arr), iter_end(arr,n--), 2);
    print_array(arr, n);
    printf("%d is removed\n\n", rem_el);
}


int main(){
    printf("test_1\n");
    test_1();
    printf("\ntest_2\n");
    test_2();
    printf("\ntest_3\n");
    test_3();
    printf("\ntest_4\n");
    test_4();


    //printf("%x", find_elem(iter_begin(arr), iter_end(arr, n+1), 7));
    
/*
    printf("%d ", it.cur->_val);
    printf("%x ", iter_inc(&it));
    printf("%d ", it.cur->_val);
*/


/*
    printf("%x ", iter_inc(&it));
    printf("%x ", iter_inc(&it));
    printf("%x ", iter_inc(&it));
    printf("%x ", dec_inc(&it));

*/   


    return 0;

}