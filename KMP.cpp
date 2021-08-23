int lps[mxn];

void prefix_function(string s){
    //s=pattern(to find)+"#"+original string(given)

    int n=s.length();
    lps[0]=0;
    for(int i=1;i<n;i++){
        int l=lps[i-1];
        while(l>0&&s[i]!=s[l])
            l=lps[l-1];
        if(s[i]==s[l])
            ++l;
        lps[i]=l;
    }
}
