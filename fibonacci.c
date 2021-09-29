#include<stdio.h>
#include<time.h>


#define MAX 4500

char answer[MAX],temp_1[MAX],temp_2[MAX];

void summation(){
    int carry = 0;
    for(int i=MAX-1;i>=0;i--){
        int digit  = (temp_1[i]-'0')+(temp_2[i]-'0')+carry;
        answer[i] = (digit%10) + '0';
        carry = digit/10;
    }
}


void fibonacci(int N){
    if(N==1||N==0){
        printf("%d",N);
        return;
    }
    for(int i=2;i<=N;i++){
        summation();
        for(int i=0;i<MAX;i++){
            temp_1[i]=temp_2[i];
            temp_2[i]=answer[i];
            
        }
    }
  int firstDigit = 0;
  for (int i = 0; i < MAX; i++)
  {
    if (firstDigit == 0 && answer[i] == '0')
    {
      continue;
    }

    if (firstDigit == 0 && answer[i] != '0')
    {
      firstDigit = 1;
    }
    printf("%c", answer[i]);
  }
  
}



int main(){
    int N;
    printf("Enter the index of the fibonacci number to be found :\n");
    scanf("%d",&N);
    //  clock_t t;
    //  t = clock();
    for(int i=0;i<MAX;i++){
        temp_1[i]='0';
        temp_2[i]='0';
        answer[i]='0';
    }
    temp_2[MAX-1]='1';
    printf("The %dth fibonacci number is : \n",N);
    fibonacci(N);
    printf("\n");
    // t = clock() - t;
    // double time_taken = ((double)t)/CLOCKS_PER_SEC;
    // printf("Took %f seconds to execute \n", time_taken);

return 0;
}
