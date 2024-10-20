#include <stdio.h>
#include <cs50.h>




int main(void)
{
// ask you for your name and stored in a string call name

    string name = get_string("whats your name? ");

// prints hello, (string name)

    printf("hello, %s\n", name);
}