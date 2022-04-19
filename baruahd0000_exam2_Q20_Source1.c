#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct request
{
    int request_track_number;
    bool visited;
};

int main()
{
while(1)
    {
        //int select;
        //printf("Enter the Disk Algorithm \n For FCFS Enter 1\n For SCAN Enther 2\n For C-SCAN Enter 3\n");
        //scanf("%d",&select);
        
        int i_FCFS,no_of_requests = 1000,initial_head;
        //printf("Enter the number of requests: ");
        //scanf("%d",&no_of_requests);
        int request[no_of_requests];
        for(int i_FCFS = 0; i_FCFS < 1000; i_FCFS++)
            request[i_FCFS] = rand()%5000;
        //printf("Enter the requests: ");
        //for (i = 0; i < no_of_requests; ++i)
        //{
        //    scanf("%d",&request[i]);
        //}
        printf("Enter initial position of R/W head: ");
        scanf("%d",&initial_head);
        int seek_time_FCFS=0;
        printf("\n******FCFS******\n\n%d -> ",initial_head );
        for(i_FCFS=0;i_FCFS<no_of_requests;i_FCFS++)
        {
            if(i_FCFS== no_of_requests-1)
                printf("%d\n", request[i_FCFS] );
            else
                printf("%d -> ", request[i_FCFS] );
            seek_time_FCFS += abs(request[i_FCFS] - initial_head);
            initial_head = request[i_FCFS];
        }
        printf("\n\n\nTotal Head movement required for FCFS: %d\n\n\n", seek_time_FCFS);
        
    int i_SCAN,limit = 5000,j_SCAN,choice_SCAN,previous_head_SCAN;
    
    //printf("Enter the number of requests: ");
    //scanf("%d",&no_of_requests);
    struct request req[no_of_requests];
    //printf("Enter the requests: ");
    for (i_SCAN = 0; i_SCAN < no_of_requests; ++i_SCAN)
    {
        req[i_SCAN].request_track_number = rand()%5000;
        //scanf("%d",&req[i].request_track_number);
        req[i_SCAN].visited = false;
    }
    //printf("Enter initial position of R/W head: ");
    //scanf("%d",&initial_head);
    previous_head_SCAN = initial_head;
    //printf("Enter the previous position of R/W head: ");
    //scanf("%d",&previous_head);

    //printf("Enter the cylinder size: ");
    //scanf("%d",&limit);

    if(previous_head_SCAN - initial_head > 0 )
    {
        choice_SCAN = 2;
    }
    else
        choice_SCAN = 1;
    //scanf("%d",&choice);
    int seek_time_SCAN=0;
    printf("\n******SCAN******\n\n%d -> ",initial_head );
    if(choice_SCAN == 1)
    {
        for(i_SCAN=initial_head;i_SCAN<limit;i_SCAN++)
        {
            for(j_SCAN=0;j_SCAN<no_of_requests;j_SCAN++)
            {
                if(req[j_SCAN].request_track_number == i_SCAN && req[j_SCAN].visited == false)
                {
                    printf("%d -> ", req[j_SCAN].request_track_number);
                    req[j_SCAN].visited = true;
                    seek_time_SCAN += abs(req[j_SCAN].request_track_number - initial_head);
                    initial_head = req[j_SCAN].request_track_number;
                }
            }
        }
        printf("%d -> ", limit-1);
        seek_time_SCAN += abs(limit-1 - initial_head);
        initial_head = limit-1;
        for(i_SCAN=initial_head;i_SCAN>=0;i_SCAN--)
        {
            for(j_SCAN=0;j_SCAN<no_of_requests;j_SCAN++)
            {
                if(req[j_SCAN].request_track_number == i_SCAN && req[j_SCAN].visited == false)
                {
                    printf("%d -> ", req[j_SCAN].request_track_number);
                    req[j_SCAN].visited = true;
                    seek_time_SCAN += abs(req[j_SCAN].request_track_number - initial_head);
                    initial_head = req[j_SCAN].request_track_number;
                }
            }
        }
        seek_time_SCAN += abs(initial_head - 0);
        printf("0 \n");
    }
    else if(choice_SCAN == 2)
    {
        for(i_SCAN=initial_head;i_SCAN>=0;i_SCAN--)
        {
            for(j_SCAN=0;j_SCAN<no_of_requests;j_SCAN++)
            {
                if(req[j_SCAN].request_track_number == i_SCAN && req[j_SCAN].visited == false)
                {
                    printf("%d -> ", req[j_SCAN].request_track_number);
                    req[j_SCAN].visited = true;
                    seek_time_SCAN += abs(req[j_SCAN].request_track_number - initial_head);
                    initial_head = req[j_SCAN].request_track_number;
                }
            }
        }
        printf("%d -> ", 0);
        seek_time_SCAN += abs(0 - initial_head);
        initial_head = 0;
        for(i_SCAN=initial_head;i_SCAN<limit;i_SCAN++)
        {
            for(j_SCAN=0;j_SCAN<no_of_requests;j_SCAN++)
            {
                if(req[j_SCAN].request_track_number == i_SCAN && req[j_SCAN].visited == false)
                {
                    printf("%d -> ", req[j_SCAN].request_track_number);
                    req[j_SCAN].visited = true;
                    seek_time_SCAN += abs(req[j_SCAN].request_track_number - initial_head);
                    initial_head = req[j_SCAN].request_track_number;
                }
            }
        }
        seek_time_SCAN += abs(limit-1 - initial_head );
        printf("%d \n", limit-1);

    }
    printf("\n\n\nTotal Head movement required for SCAN: %d\n\n\n", seek_time_SCAN);

//
    int i_C_SCAN,j_C_SCAN,choice_C_SCAN,previous_head_C_SCAN;
    //printf("Enter the number of requests: ");
    //scanf("%d",&no_of_requests);
    struct request req_C_SCAN[no_of_requests];
    //printf("Enter the requests: ");
    for (i_C_SCAN = 0; i_C_SCAN < no_of_requests; ++i_C_SCAN)
    {
        //scanf("%d",&req_C_SCAN[i_C_SCAN].request_track_number);
        req_C_SCAN[i_C_SCAN].request_track_number = rand()%5000;
        req_C_SCAN[i_C_SCAN].visited = false;
    }
    //printf("Enter initial position of R/W head: ");
    //scanf("%d",&initial_head);

    //printf("Enter the previous position of R/W head: ");
    //scanf("%d",&previous_head_C_SCAN);

    //printf("Enter the cylinder size: ");
    //scanf("%d",&limit);
    previous_head_C_SCAN = initial_head;
    if(previous_head_C_SCAN - initial_head > 0 )
    {
        choice_C_SCAN = 2;
    }
    else
        choice_C_SCAN = 1;
    //scanf("%d",&choice);
    int seek_time_C_SCAN=0;
    printf("\n******C_SCAN******\n\n%d -> ",initial_head );
    int cp_initial_head = initial_head;
    if(choice_C_SCAN == 1)
    {
        for(i_C_SCAN=initial_head;i_C_SCAN<limit;i_C_SCAN++)
        {
            for(j_C_SCAN=0;j_C_SCAN<no_of_requests;j_C_SCAN++)
            {
                if(req_C_SCAN[j_C_SCAN].request_track_number == i_C_SCAN && req_C_SCAN[j_C_SCAN].visited == false)
                {
                    printf("%d -> ", req_C_SCAN[j_C_SCAN].request_track_number);
                    req_C_SCAN[j_C_SCAN].visited = true;
                    seek_time_C_SCAN += abs(req_C_SCAN[j_C_SCAN].request_track_number - initial_head);
                    initial_head = req_C_SCAN[j_C_SCAN].request_track_number;
                }
            }
        }
        printf("%d -> \n", limit-1);
        seek_time_C_SCAN += abs(limit-1 - initial_head);
        initial_head = 0;
        for(i_C_SCAN=0;i_C_SCAN<cp_initial_head;i_C_SCAN++)
        {
            for(j_C_SCAN=0;j_C_SCAN<no_of_requests;j_C_SCAN++)
            {
                if(req_C_SCAN[j_C_SCAN].request_track_number == i_C_SCAN && req_C_SCAN[j_C_SCAN].visited == false)
                {
                    printf("%d -> ", req_C_SCAN[j_C_SCAN].request_track_number);
                    req_C_SCAN[j_C_SCAN].visited = true;
                    seek_time_C_SCAN += abs(req_C_SCAN[j_C_SCAN].request_track_number - initial_head);
                    initial_head = req_C_SCAN[j_C_SCAN].request_track_number;
                }
            }
        }
        printf("\n");
    }
    else if(choice_C_SCAN == 2)
    {
        for(i_C_SCAN=initial_head;i_C_SCAN>=0;i_C_SCAN--)
        {
            for(j_C_SCAN=0;j_C_SCAN<no_of_requests;j_C_SCAN++)
            {
                if(req_C_SCAN[j_C_SCAN].request_track_number == i_C_SCAN && req_C_SCAN[j_C_SCAN].visited == false)
                {
                    printf("%d -> ", req[j_C_SCAN].request_track_number);
                    req_C_SCAN[j_C_SCAN].visited = true;
                    seek_time_C_SCAN += abs(req_C_SCAN[j_C_SCAN].request_track_number - initial_head);
                    initial_head = req_C_SCAN[j_C_SCAN].request_track_number;
                }
            }
        }
        printf("%d -> ", 0 );
        seek_time_C_SCAN += abs(initial_head - 0);
        initial_head = limit-1;
        for(i_C_SCAN=limit;i_C_SCAN>cp_initial_head;i_C_SCAN--)
        {
            for(j_C_SCAN=0;j_C_SCAN<no_of_requests;j_C_SCAN++)
            {
                if(req_C_SCAN[j_C_SCAN].request_track_number == i_C_SCAN && req_C_SCAN[j_C_SCAN].visited == false)
                {
                    printf("%d -> ", req_C_SCAN[j_C_SCAN].request_track_number);
                    req_C_SCAN[j_C_SCAN].visited = true;
                    seek_time_C_SCAN += abs(req_C_SCAN[j_C_SCAN].request_track_number - initial_head);
                    initial_head = req_C_SCAN[j_C_SCAN].request_track_number;
                }
            }
        }
        printf("\n");
    }
    printf("Total Head movement required for C_SCAN: %d\n\n\n", seek_time_C_SCAN + 5000);
    
    }
    
    //else
        //printf("Selected Algorithm doesn't exits\n\n");

}

