#include <stdio.h>

float fahr_to_celsius (float f_temp)
{
    float c_temp;
    c_temp = (f_temp - 32)/1.8;
    return c_temp;
}

// Order is important - celcius conversion function needed to occur first to be called in the kelvin conversion
float fahr_to_kelvin (float f_temp)
{
    float k_temp;
    k_temp = fahr_to_celsius(f_temp) + 273.15;
    return k_temp;
}

float fahr_to_N (float f_temp)
{
    float N_temp;
    N_temp = (f_temp - 32)/5.45454555;
    return N_temp;
}


int main () 
{
    float fahrenheit;
    char option; // Initializes a variable called option of the char type

    printf ("Enter a temperature to convert in Fahrenheit:\n");
    scanf ("%f", &fahrenheit);

    printf ("\n");
    printf ("Select A to convert to Celsius\n");
    printf ("Select B to convert to Kelvin\n");
    printf ("Select C to convert to Newton\n");
    printf ("Select Q to quit\n");

    scanf(" %c", &option); // Assigns the input value to the option variable

    switch (option) // Depending on the option input, will print various messages
    {
        case 'A': printf ("Converted to degrees Celsius: %f\n", fahr_to_celsius(fahrenheit));
                  break;

        case 'B': printf ("Converted to Kelvin: %f\n", fahr_to_kelvin(fahrenheit));
                  break;

        case 'C':   printf ("Converted to Newton: %f\n", fahr_to_N(fahrenheit));
                    break;

        case 'Q': break;

        default:  break;
    }

    return 0;
}