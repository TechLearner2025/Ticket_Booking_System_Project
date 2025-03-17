#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100  // Maximum number of tickets

// Global variables for QUEUE application
int ticket[MAX_CAPACITY];
int frontIndex = -1, rearIndex = -1;

//Function to clear file at start of every program run
void clearFile()
{
    FILE *filePointer = fopen("ticketRecords.txt", "w"); // Open in write mode to clear
    if (filePointer != NULL)
    {
        fclose(filePointer);
    }
}

//Function to check ticket booking
int isTicketBooked(int queue[], int seatNumber)
{
    for (int i = frontIndex; i <= rearIndex; i++)
    {
        if (queue[i] == seatNumber)
        {
            return 1;  //if ticket is already booked
        }
    }
    return 0;  //incase ticket is not booked
}

//Function to insert an element into the queue i.e. for ticket booking
void bookTicket(int queue[], int seatNumber)
{
    if (rearIndex == -1)
    {
        frontIndex = rearIndex = 0;
        queue[rearIndex] = seatNumber;
    }
    else if (rearIndex == MAX_CAPACITY - 1)
    {
        printf("\n\t\t\t\t!!Theatre is FULL!!!.\n");
        return;
    }
    else if (isTicketBooked(queue, seatNumber))
    {
        printf("\n\t\t\t\t!!Ticket %d is already booked!!\n", seatNumber);
        return;
    }
    else
    {
        rearIndex++;
        queue[rearIndex] = seatNumber;
    }

    // Save the ticket to file when booked
    FILE *filePointer = fopen("ticketRecords.txt", "a");
    if (filePointer != NULL)
    {
        fprintf(filePointer, "Ticket booked: %d\n", seatNumber);
        fclose(filePointer);
    }

    printf("\n\t\t\t\t*!!Ticket booked successfully!!*\n");
}

//Function to remove an element from the queue i.e. if ticket cancellation occurs
void cancelTicket(int queue[], int seatNumber)
{
    if (frontIndex == -1)
    {
        printf("\t\t\t\tTheatre is empty!!\n");
        return;
    }

    int found = 0;
    for (int i = frontIndex; i <= rearIndex; i++)
    {
        if (queue[i] == seatNumber)
        {
            found = 1;
            printf("\n\t\t\t\tTicket cancelled: %d.\n", seatNumber);

            for (int j = i; j < rearIndex; j++)
            {
                queue[j] = queue[j + 1];
            }
            rearIndex--;

            if (rearIndex < frontIndex)
            {
                frontIndex = rearIndex = -1;
            }
            break;
        }
    }

    if (!found)
    {
        printf("\n\t\t\t\t!!Ticket %d is not booked!!\n", seatNumber);
        return;
    }

    // Update the file after cancellation
    FILE *filePointer = fopen("ticketRecords.txt", "w"); // Open in write mode to overwrite
    if (filePointer != NULL)
    {
        for (int i = frontIndex; i <= rearIndex; i++)
        {
            fprintf(filePointer, "Ticket booked: %d\n", queue[i]);
        }
        fclose(filePointer);
    }
}

// Function to showcase booked tickets
void showTickets(int queue[])
{
    if (rearIndex == -1)
    {
        printf("\nTheatre is Empty!!\n");
        return;
    }

    printf("\nBooked Tickets:\n");
    for (int i = frontIndex; i <= rearIndex; i++)
    {
        printf("Ticket booked: %d \n", queue[i]);
    }
}

//Main function
int main()
{
    clearFile(); // Clear file at the start of the program

    int seat,choice;

    while (1)
    {
        printf("\n\n\t\t\t\t**TICKET BOOKING SYSTEM**\n");
        printf("\n\n\t\t\t\tSeats are numbered 1 to 100\n");
        printf("\n\t\t\t\t1: Buy Tickets. \n\t\t\t\t2: Show Tickets. \n\t\t\t\t3: Cancel Tickets. \n\t\t\t\t4: Exit \n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n\t\t\t\tEnter the seat number you want to book: ");
                scanf("%d",&seat);
                bookTicket(ticket,seat);
                break;
            case 2:
                showTickets(ticket);
                break;
            case 3:
                printf("\n\t\t\t\tEnter the seat number you want to cancel: ");
                scanf("%d",&seat);
                cancelTicket(ticket,seat);
                break;
            case 4:
                exit(0);
            default:
                printf("\n\t\t\t\t!!Invalid choice!!\n");
                break;
        }
    }
    return 0;
}
