//Problem Description

There is a test of Algorithms. Teacher provides a question bank consisting of N questions and guarantees all the questions in the test will be from this question bank. Due to lack of time and his laziness, Codu could only practice M questions. There are T questions in a question paper selected randomly. Passing criteria is solving at least 1 of the T problems. Codu can't solve the question he didn't practice. What is the probability that Codu will pass the test?

Constraints

0 < T <= 10000

0 < N, T <= 1000

0 <= M <= 1000

M,T <= N

Input Format

First line contains single integer T denoting the number of test cases.

First line of each test case contains 3 integers separated by space denoting N, T, and M.

Output

For each test case, print a single integer.

If probability is p/q where p & q are co-prime, print (p*mulInv(q)) modulo 1000000007, where mulInv(x) is multiplicative inverse of x under modulo 1000000007.

Timeout

1


Test Case

Example 1

Input

1

4 2 1

Output

500000004

Explanation

The probability is ½. So output is 500000004. 
//
#include<stdio.h>
int combinations(int n,int r)
{
int itr;
  int numerator=1,denominator=1,result;
  for(itr=1;itr<=r;itr++)
  {
    denominator=denominator*itr;
    numerator=numerator*(n-(itr-1));
  }
  result=numerator/denominator;
  return result;
}
int calcGCD(int num1,int num2)
{
  int rem;
  rem=num1%num2;
  while(1)
  {
    rem=num1%num2;
    if(rem=0)
    return num2;
  if(rem!=0)
  {
    num1=num2;
    num2=rem;
  }
}
}
int mulInv(int a)
{
  int m=1000000007,itr,b;
  for(itr=1;itr<m;itr++)
  {
    if((itr*m+1)%a==0)
    {
      b=(itr*m+1)/a;
      break;
    }
  }
  return b;
}

int main()
{
  int qb_questions=5,learnt=2,chosen=2,unknown;
  int waysOfChoosing,waysOfFailing,p,q,gcd,result;
  unknown=qb_questions-learnt;
  waysOfChoosing=combinations(qb_questions,chosen);
  waysOfFailing=combinations(unknown,chosen);
  p=waysOfChoosing-waysOfFailing;
  q=waysOfChoosing;
  printf("%d/%d\n",p,q);
  gcd=calcGCD(p,q);
  if(gcd!=1)
  {
    p=p/gcd;
    q=q/gcd;
  }
  result=(p*mulInv(q))%1000000007;
  printf("%d",result);
  printf("%d\n",gcd);
    return 0;
}