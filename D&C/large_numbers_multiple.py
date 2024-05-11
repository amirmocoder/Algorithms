def pro(u,v):
    s = 2
    n = max(len(str(u)),len(str(v)))
    if u == 0 or v == 0 :
        return 0
    elif n<=s :
        return u*v
    else:
        m = n // 2
        x = u // (10**m)
        y = u % (10**m)
        w = v // (10**m)
        z = v % (10**m)
        return pro(x,w)*(10**(2*m))+pro(x,z)+(pro(y,w)*(10**(m)))+pro(y,z)