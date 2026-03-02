#include <stdio.h>

int main() {
    int score;
    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
    scanf("%d",&score);
    if (score<0)
    {
        while (score<0)
        {
            printf("Invalid score, please try again.\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
            scanf("%d",&score);
        }     
    }
    if (score==0||score==1)
    {
        return 0;
    }  
    else
    {
        printf("Possible combinations of scoring plays if a team's score is %d\n", score);
        for (int td_2pt = 0; td_2pt<=score; td_2pt++)
        {
            for (int td_exp = 0; td_exp<=score; td_exp++)
            {
                for (int td = 0; td<=score; td++)
                {
                    for (int fg = 0; fg<=score; fg++)
                    {
                        for (int sft = 0; sft<=score; sft++)
                        {
                            int total = td_2pt*8+td_exp*7+td*6+fg*3+sft*2;
                            if (total == score)
                            {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_exp, td, fg, sft);
                            }
                        }  
                    }  
                }  
            }  
        }      
    }
}
