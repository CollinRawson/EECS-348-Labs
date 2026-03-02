#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    float temp;
    char temp_type;
    char convert_to;
    bool valid_input = false;
    float fahrenheit_to_celsius(float);
    float celsius_to_fahrenheit(float);
    float celsius_to_kelvin(float);
    float kelvin_to_celsius(float);
    float fahrenheit_to_kelvin(float);
    float kelvin_to_fahrenheit(float);
    void categorize_temperature(float);
    while (valid_input == false)
    {
        printf("Enter a temperature value: ");
        scanf("%f", &temp);
        printf("Enter the temperature's unit (F, C, or K): ");
        scanf(" %c", &temp_type);
        printf("Enter the unit to convert to (F, C, or K): ");
        scanf(" %c", &convert_to);
        temp_type = toupper(temp_type);
        convert_to = toupper(convert_to);
        if ((temp_type != 'F' && temp_type != 'C' && temp_type != 'K') || (convert_to != 'F' && convert_to != 'C' && convert_to != 'K') || temp_type == convert_to || (temp_type == 'K' && temp < 0))
        {
            printf("Invalid input, please try again.\n");
        }
        else
        {
            valid_input = true;
        }
    }
    if (temp_type == 'F' && convert_to == 'C')
    {
        printf("%f degree(s) Fahrenheit is %f degrees Celsius.\n",temp, fahrenheit_to_celsius(temp));
        categorize_temperature(fahrenheit_to_celsius(temp));
    }
    else if (temp_type == 'C' && convert_to == 'F')
    {
        printf("%f degree(s) Celsius is %f degrees Fahrenheit.\n",temp, celsius_to_fahrenheit(temp));
        categorize_temperature(temp);
    }
    else if (temp_type == 'F' && convert_to == 'K')
    {
        printf("%f degree(s) Fahrenheit is %f degrees Kelvin.\n",temp, fahrenheit_to_kelvin(temp));
        categorize_temperature(fahrenheit_to_celsius(temp));
    }
    else if (temp_type == 'K' && convert_to == 'F')
    {
        printf("%f degree(s) Kelvin is %f degrees Fahrenheit.\n",temp, kelvin_to_fahrenheit(temp));
        categorize_temperature(kelvin_to_celsius(temp));
    }
    else if (temp_type == 'C' && convert_to == 'K')
    {
        printf("%f degree(s) Celsius is %f degrees Kelvin.\n",temp, celsius_to_kelvin(temp));
        categorize_temperature(temp);
    }
    else if (temp_type == 'K' && convert_to == 'C')
    {
        printf("%f degree(s) Kelvin is %f degrees Celsius.\n",temp, kelvin_to_celsius(temp));
        categorize_temperature(kelvin_to_celsius(temp));
    }
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit-32)*(5.0/9.0);
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius*(9.0/5.0)+32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return fahrenheit_to_celsius(fahrenheit) + 273.15;
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin-273.15);
}

void categorize_temperature(float celsius) {
    if (celsius<0)
    {
        printf("Freezing. Stay Indoors.");
    }
    else if (celsius<10)
    {
        printf("Cold. Wear a jacket.");
    }
    else if (celsius<25)
    {
        printf("Comfortable. Enjoy the outdoors.");
    }
    else if (celsius<35)
    {
        printf("Hot. Drink water.");
    }
    else
    {
        printf("Extreme Heat. Restrict physical activity.");
    }
    
}