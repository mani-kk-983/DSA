class Solution {
public:
    int reverse(int x) {
        long  rev=0;
        while(x!=0){
            rev=rev*10+(x%10);
            x=x/10;
        }
        // 2^32= 429496296-> 1/2-> 214783648 
        //cyclic property of variable 

     if(rev>2147483647||rev<-2147483648){return 0;}
     return (int)rev;
    }
};