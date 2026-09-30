/*
 * function: func_021D9EBC
 * address: 0x021D9EBC
 * packet: pkt_ov119_021D9EBC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_021E51A4 0x021E51A4 thumb ov119
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 */

extern int func_02035D20(int *,int *);
extern int func_021E51A4(void *,int,int,int *,int *,int *,int *,int *);
extern int func_021D8DD0(int,int,int,char *);
extern int func_02017E88(int,int,int);
int func_021D9EBC(char *p,int *a,int *b,int *c,int *d) {
    int x,y,z,n;
    if(func_02035D20(&x,&y)==1) {
        if(func_021E51A4(p,x+12,y+12,a,b,c,d,&z)) {
            n=func_021D8DD0(*(int *)(p+0x828),*a,*b,p);
            if(n && func_02017E88(n,0xA9,0)) return 1;
        }
    }
    return 0;
}
