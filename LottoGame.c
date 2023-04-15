/*
Program Description:
This program simulates a Lotto game.
The program is menu-driven and displays a main menu when run. The menu includes the following options:

1. Enter 6 different numbers (1-42 inclusive)
2. Display your chosen numbers
3. Sort your chosen numbers from smallest to largest
4. Compare your chosen numbers with the winning numbers
5. Display frequency of chosen numbers
6. Exit program

The program continually runs and re-displays the main menu after each option has completed.
The program only terminates when the user enters option 6 (i.e. Exit Program).
The user can only select options 2-5 if they have completed option 1.

Author: Sarah Barron C21415904
Date: 20/03/2022
*/

#include <stdio.h>

#define SIZE 6 // size of array for lotto numbers
#define ALL 42 // used in count_arr function to store frequencies of numbers

void enter_arr(int *);             // function to allow user to enter guesses for lotto numbers
void display_arr(int *);           // function to display user's chosen numbers
void sort_arr(int *);              // function to sort user's chosen numbers from smallest to largest
void comp_arr(int *, int *);       // function to determine prize the user wins
void count_arr(int, int *, int *); // function to count frequency of all numbers entered in option 1 before program terminates
int *end_program(int *);           // function to end program

int main()
{
    int user_choice = 0;                     //  variable for option user chooses
    int option1 = 0;                         // used to check when option 1 has been used
    int option5 = 0;                         // used to check when option 5 has been selected
    int *end = 0;                            // used to terminate program
    int win_arr[SIZE] = {1, 3, 5, 7, 9, 11}; // winning numbers
    int user_arr[SIZE];                      // array to hold user's chosen numbers
    int all_nums[ALL] = {0};                 // array to hold frequencies of all numbers entered

    // while the user has not entered option 6 to terminate the program
    while (end == 0)
    {
        // reprint menu until user enters valid input
        do
        {
            printf("\n\n--------------Lotto Game Menu--------------");
            printf("\n\n 1. Enter 6 different numbers (1-42 inclusive)");
            printf("\n 2. Display your chosen numbers");
            printf("\n 3. Sort your chosen numbers from smallest to largest");
            printf("\n 4. Compare your chosen numbers with the winning numbers");
            printf("\n 5. Display frequency of chosen numbers");
            printf("\n 6. Exit program");
            printf("\n\n-------------------------------------------");

            printf("\n\nChoose an option: ");

            // read in user's choice
            scanf("%d", &user_choice);

            // discards unwanted characters before user presses enter key
            while (getchar() != '\n');

            // display error message if invalid input
            if (user_choice < 1 || user_choice > 6)
            {
                printf("Please select a valid option!");
            }

        } while (user_choice < 1 || user_choice > 6);

        // switch statement which calls functions based on user's menu selection
        switch (user_choice)
        {
            // if user inputs 1
            case 1:
            {
                enter_arr(user_arr);
                count_arr(0, user_arr, all_nums);
                option1 = 1;
                break;

            } // end case

            // if user inputs 2
            case 2:
            {
                if (option1 == 1)
                {
                    display_arr(user_arr);
                }
                else
                {
                    printf("\nPlease select option 1 before you select any other options. ");
                }

                break;

            } // end case

            // if user inputs 3
            case 3:
            {
                //if option 1 has been selected 
                if (option1 == 1)
                {
                    sort_arr(user_arr);
                }
                else
                {
                    printf("\nPlease select option 1 before you select any other options. ");
                }

                break;

            } // end case

            // if user inputs 4
            case 4:
            {
                //if option 1 has been selected
                if (option1 == 1)
                {
                    comp_arr(win_arr, user_arr);
                }
                else
                {
                    printf("\nPlease select option 1 before you select any other options. ");
                }

                break;
            } // end case

            // if user inputs 5
            case 5:
            {
                // if option 1 has been selected
                if (option1 == 1)
                {
                    sort_arr(user_arr);
                    count_arr(1, user_arr, all_nums);
                }
                else
                {
                    printf("\nPlease select option 1 before you select any other options. ");
                }

                break;
            } // end case

            // if user inputs 6
            case 6:
            {
                end_program(end);
                break;
            } // end case
            
            default:
            {           
                printf("\nInvalid option. Try again: \n");
                break;
            }

        } // end switch

    } // end while

    return 0;
}

void enter_arr(int *num_arr)
{
    int same = 0;
    int i = 0;

    printf("\nEnter six numbers (1-42):\n");

    // repeat loop 6 times (size of the array)
    while (i < SIZE)
    {
        // take numbers into the array until valid input
        do
        {
            scanf("%d", &*(num_arr + i));

            // discards unwanted characters before user presses enter key
            while (getchar() != '\n');

            // display error message if invalid input 
            if (*(num_arr + i) < 1 || *(num_arr + i) > 42)
            {
                printf("\nPlease enter a number between 1-42:\n");
            }

        } while (*(num_arr + i) < 1 || *(num_arr + i) > 42);

        i++;
    } // end while

    for (int j = 0; j < SIZE - 1; j++)
    {
        for (int k = j + 1; k < SIZE; k++)
        {
            if (*(num_arr + j) == *(num_arr + k))
            {
                printf("\nPlease enter 6 distinct numbers: ");
                enter_arr(num_arr);
            } // end if

        } // end for k

    } // end for j

} // end enter_arr()

void display_arr(int *print_arr)
{
    // print array
    for (int i = 0; i < SIZE; i++)
    {
        // print each element with a comma unless it's the last element
        if (i == SIZE - 1)
        {
            printf("%d", *(print_arr + i));
        } // end if
        else
        {
            printf("%d,", *(print_arr + i));
        } // end else

    } // end for

} // end function display_arr()

void sort_arr(int *order_arr)
{
    // Selection Sort algorithm - repeatedly finds minimum and puts it at the beginning
    int min, temp;

    // 
    for (int i = 0; i < (SIZE - 1); i++)
    {
        min = i;

        for (int j = i + 1; j < SIZE; j++)
        {

            if (*(order_arr + j) < *(order_arr + min))
            {
                min = j;

            } // end if

        } // end for j 

        // swapping elements if they are not in the correct position
        if (*(order_arr + i) != *(order_arr + min))
        {
            temp = *(order_arr + min);
            *(order_arr + min) = *(order_arr + i);
            *(order_arr + i) = temp;

        } // end if

    } // end for i

} // end function sort_arr()

void comp_arr(int *win_nums, int *cmp_arr)
{
    int same = 0;

    // counting how many matches between winning numbers and user's numbers
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (*(win_nums + i) == *(cmp_arr + j))
            {
                same++;
            } // end if

        } // end for j

    } // end for i

    switch (same)
    {
        // if 6 matches
        case 6:
        {
            printf("Jackpot!");
            break;
        } // end case

        // if 5 matches
        case 5:
        {
            printf("New car!");
            break;
        } // end case

        // if 4 matches
        case 4:
        {
            printf("Weekend away!");
            break;
        } // end case

        // if 3 matches
        case 3:
        {
            printf("Cinema pass!");
            break;
        } // end case

        // if less than three matches
        default:
        {
            printf("You lose...");
            break;
        } // end case

    } // end switch

} // end function comp_arr()

void count_arr(int opt5, int *freq_arr, int *all_arr)
{
    // if option 5 has not been selected
    if (opt5 == 0)
    {
        // increment index corresponding to element by 1
        for (int i = 0; i < SIZE; i++)
        {
            (*(all_arr + (*(freq_arr + i) - 1)))++;
        } // end for

    } // end if

    // if option 5 has been selected
    else if (opt5 == 1)
    {
        for (int k = 0; k < ALL; k++)
        {
            // if value is greater than 1 then print the frequency
            if (*(all_arr + k) > 0)
            {
                printf("\n%d has been selected %d times\n", (k + 1), *(all_arr + k));
            }
        } // end for

    } // end else if

} // end function count_arr()

int *end_program(int *end_all)
{
    printf("Thanks for playing!");
    (*end_all)++;
    return (end_all);

} // end function end_program()
