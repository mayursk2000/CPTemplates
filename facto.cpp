ll inv[mxn+1],fact_inv[mxn+1],fact[mxn+1];
void inverse(){
    inv[1]=1;//MMI
    int i;
    for(i=2;i<=mxn;i++){
        inv[i]=mod-(mod/i)*inv[mod%i]%mod;
    }
}
void factinv(){//Inverse fact
    int i;
    fact_inv[0]=1;
    for(i=1;i<=mxn;i++){
        fact_inv[i]=fact_inv[i-1]*inv[i]%mod;
    }
}
void facto(){//factorial
    int i;
    fact[0]=1;
    for(i=1;i<=mxn;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
}
