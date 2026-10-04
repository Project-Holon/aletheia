/*
 * function: func_021F8670
 * address: 0x021F8670
 * packet: pkt_ov184_021F8670
 * region: ov184
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021F8624 0x021F8624 thumb ov184
 *   func_021F86EC 0x021F86EC thumb ov184
 */
extern int func_02035D20(int *,int *);
extern int func_021FB4B4(int,int,int);
extern void func_021FD860(int,int,int *);
extern void func_021FD73C(int *p, int v);
extern void func_021F8624(int,int *,char *);
extern void func_021F86EC(int task, unsigned *state, char *p);
void func_021F8670(int a,int b,char *p)
{
    int x,y;
    if (func_02035D20(&x,&y)) {
        if (func_021FB4B4(*(int *)(p+4),x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            func_021FD860(*(int *)(p+24),1,pair);
            *(int *)(*(char **)(p+48)+28)=0;
            func_021FD73C((int *)a,(int)func_021F8624);
        }
        if (func_021FB4B4(*(int *)(p+8),x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            func_021FD860(*(int *)(p+24),1,pair);
            *(int *)(*(char **)(p+48)+28)=1;
            func_021FD73C((int *)a,(int)func_021F86EC);
        }
    }
}
