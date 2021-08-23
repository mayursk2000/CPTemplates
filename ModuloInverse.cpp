int minv(int a, int m)//Modulo Inverse a inverse(mod m){if a and m are coprime}
{
    int temp=m, q, t, u=0, v=1;
    if(m==1) return 0;
    while(a>1)
    {
        q=a/m;
        t=m;
        m=a%m;
        a=t;
        t=u;
         u=v-q*u;
         v=t;
    }
    if(v<0) v+=temp;
    return v;
}
