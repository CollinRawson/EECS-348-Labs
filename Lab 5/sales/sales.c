#include <stdio.h>
#include <string.h>

int find_smallest_index(double array[]) {
    int smallest_index = 0;
    for (int i = 0; i < 12; i++)
    {
        if (array[smallest_index] > array[i]) {smallest_index = i;}
    }
    return smallest_index;
}

int find_biggest_index(double array[]) {
    int biggest_index = 0;
    for (int i = 0; i < 12; i++)
    {
        if (array[biggest_index] < array[i]) {biggest_index = i;}
    }
    return biggest_index;
}

void sort_index_size(double array[], int indices[]) {
    double temp_array[12];
    for (int i=0;i<12;i++) {temp_array[i] = array[i];}
    for (int i = 0; i < 12; i++)
    {
        int temp = find_biggest_index(temp_array);
        indices[i] = temp;
        temp_array[temp] = 0;
    }
}

void print_output(double sales[], char *months[]) {
    double sales_avg=0;
    int sorted_indices[12];
    sort_index_size(sales, sorted_indices);
    for (int i = 0; i < 12; i++)
    {
        sales_avg += sales[i];
    }
    sales_avg /= 12;
    printf("Monthly Sales Report for 2025\n\n");
    printf("Month      Sales\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%-10s %.2f\n", months[i], sales[i]);
    }
    printf("\n\nSales summary report:\n\n");
    printf("Minimum Sales: %.2f (%s)\n", sales[find_smallest_index(sales)], months[find_smallest_index(sales)]);
    printf("Maximum Sales: %.2f (%s)\n", sales[find_biggest_index(sales)], months[find_biggest_index(sales)]);
    printf("Average Sales: %.2f\n", sales_avg);
    printf("\nSix-Month moving average report:\n\n");
    for (int i = 0; i < 7; i++)
    {
        char label[30];
        sprintf(label, "%s-%s", months[i], months[i+5]);
        printf("%-20s %.2f\n", label, (sales[i]+sales[i+1]+sales[i+2]+sales[i+3]+sales[i+4]+sales[i+5])/6);
    }
    printf("\nSales report (highest to lowest):\n\n");
    printf("Month      Sales\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%-10s $%.2f\n", months[sorted_indices[i]], sales[sorted_indices[i]]);
    }
    return;
}

int main() {
    const double sales[12];
    const char *months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    FILE *file;
    file = fopen("salesnums.txt","r");
    for (int i = 0; i < 12; i++)
    {
        fscanf(file, "%lf", &sales[i]);
    }
    
    print_output(sales, months);
    return 0;
}

