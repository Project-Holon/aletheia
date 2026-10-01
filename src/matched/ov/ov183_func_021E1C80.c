/*
 * function: func_021E1C80
 * address: 0x021E1C80
 * packet: pkt_ov183_021E1C80
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021E1DA8 0x021E1DA8 thumb ov183
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   d_021E38E0 0x021E38E0 data a4
 */
typedef unsigned short u16;
typedef struct {int a,b;} Pair;
extern const Pair d_021E38E0;
extern u16 func_021F9B9C(int);
extern char *func_0203159C(int,int,int);
extern void func_02082BCC(void *,int,int);
extern int func_021FD6D8(void *,void *,u16);
extern void func_021E1DA8(int,int *,char *);
extern int func_0201C440(u16);
extern int func_021FD12C(int,int,u16);
extern void func_021FD170(int,int,int);
extern int func_021FD760(int,int,int,u16);
extern void func_021FD860(int,int,Pair *);
int func_021E1C80(int obj,int unused,char *arg)
{
    char *p;
    int i;
    Pair pair;
    p=func_0203159C(obj,32,func_021F9B9C(*(int *)(arg+0xc)));
    func_02082BCC(p,0,32);
    *(char **)(p+0x18)=arg;
    *(u16 *)(p+8)=func_021F9B9C(*(int *)(arg+0xc));
    *(int *)(p+4)=func_021FD6D8(p,func_021E1DA8,*(u16 *)(p+8));
    *(int *)p=func_0201C440(*(u16 *)(p+8));
    *(int *)(p+0xc)=func_021FD12C(*(int *)(arg+8),*(int *)p,*(u16 *)(p+8));
    func_021FD170(*(int *)(p+0xc),*(int *)(arg+8),111);
    for (i=0;i<2;i++) *(int *)(p+i*4+0x10)=func_021FD760(*(int *)(arg+4),*(int *)(arg+8),i,*(u16 *)(p+8));
    pair=d_021E38E0;
    func_021FD860(*(int *)(p+0x10),4,&pair);
    return 1;
}
