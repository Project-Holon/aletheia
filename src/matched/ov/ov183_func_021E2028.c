/*
 * function: func_021E2028
 * address: 0x021E2028
 * packet: pkt_ov183_021E2028
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E39B4 0x021E39B4 data a4
 *   func_02034714 0x02034714 arm
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021E214C 0x021E214C thumb ov183
 *   func_0201C440 0x0201C440 thumb
 *   func_021E23C8 0x021E23C8 thumb ov183
 *   func_021FD760 0x021FD760 thumb ov186
 */
typedef unsigned short u16;
extern char d_021E39B4[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u16 func_021F9B9C(int);
extern char *func_0203159C(int,int,int);
extern void func_02082BCC(void *,int,int);
extern int func_021FD6D8(void *,void *,u16);
extern void func_021E214C(int *task, int *state, char *p);
extern int func_0201C440(u16);
extern void func_021E23C8(char *,char *);
extern int func_021FD760(int,int,int,u16);
int func_021E2028(int obj,int unused,char *arg)
{
    char *p;
    int i;
    if (*(int *)arg>=4) func_02034714(d_021E39B4,0,d_021E39B4);
    p=func_0203159C(obj,40,func_021F9B9C(*(int *)(arg+0x10)));
    func_02082BCC(p,0,40);
    *(char **)(p+0x20)=arg;
    *(u16 *)(p+0x1c)=func_021F9B9C(*(int *)(arg+0x10));
    *(int *)(p+8)=func_021FD6D8(p,func_021E214C,*(u16 *)(p+0x1c));
    *(int *)p=func_0201C440(*(u16 *)(p+0x1c));
    func_021E23C8(p,arg);
    for (i=0;i<2;i++) *(int *)(p+i*4+0x14)=func_021FD760(*(int *)(arg+8),*(int *)(arg+0xc),i,*(u16 *)(p+0x1c));
    return 1;
}
