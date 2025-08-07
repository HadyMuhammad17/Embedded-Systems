

   /* struct Node* two = (struct Node*)malloc(sizeof(struct Node));
    node* one = (node*)malloc(sizeof(node));
    node* three = (node*)malloc(sizeof(node));

    one->value = 10;
    one->next = two ;

    two->value = 20 ;
    two->next = three ;

    three->value = 30 ;


    printf("one %d\n",one->value);
    printf("two %d\n",one->next->value);
    printf("two %d\n",two->value);
    printf("three %d\n",one->next->next->value);
    printf("three %d\n",three->value);


    int* ptr = (int*)malloc(3*sizeof(int));
    int* ptr1 = (int*)malloc(3*sizeof(int));

    int* ptr3 = (int*)realloc(ptr,5);

    free(ptr);

    int n ;
    scanf("%d",&n);
    int* arr = (int*)malloc(n);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    int i ;
    for(i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
    printf("%d ",arr[i]);
    }

    int* ptr = (int*)malloc(2*sizeof(int));//garabag
    *ptr = 10 ;
    *(ptr+1) = 20 ;
    *(ptr+2) = 30 ;

    char* ptr1 = (char*)calloc(2,1);//initial value equal 0*/