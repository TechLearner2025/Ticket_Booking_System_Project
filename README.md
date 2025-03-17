# Ticket Booking System (Queue Application)

## Project Description
This project is a simple Ticket Booking System implemented using a **Queue data structure** in C. It allows users to book, view, and cancel tickets, where the tickets are managed in a **First-Come, First-Served (FCFS)** manner.

## Features
- **Booking Tickets:** Users can book tickets by providing a seat number (1 to 100).
- **Viewing Booked Tickets:** Displays all currently booked tickets.
- **Canceling Tickets:** Allows cancellation of previously booked tickets.
- **Persistent Storage:** Saves booked tickets to a file (`ticketRecords.txt`) for reference even after program termination.

## Inputs
1. **Ticket Booking (Option 1):** Enter the seat number to book. If the seat is already booked, an appropriate message is displayed.
2. **Show Tickets (Option 2):** Displays a list of all booked tickets.
3. **Cancel Tickets (Option 3):** Enter the seat number to cancel the booking.
4. **Exit (Option 4):** Terminates the program.

## File Structure
- **Main Code File:** Contains the implementation of the ticket booking system.
- **ticketRecords.txt:** Stores the list of booked tickets (updated dynamically).

## Requirements
- Standard C compiler (e.g., GCC).
- Console environment for program interaction.

## Compilation and Usage
1. Compile the code using `gcc -o TicketBooking TicketBooking.c`.
2. Run the executable with `./TicketBooking`.
3. Follow the on-screen prompts for ticket booking, viewing, and cancellation.

## Future Improvements
- Adding file-based persistence for bookings across multiple program runs.
- Improving input validation and error handling.
- Implementing seat visualization for better user experience.

