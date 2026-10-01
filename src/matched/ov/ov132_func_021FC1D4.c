/*
 * function: func_021FC1D4
 * address: 0x021FC1D4
 * packet: pkt_ov132_021FC1D4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F6E78 0x021F6E78 thumb ov112
 *   func_021F6F14 0x021F6F14 thumb ov112
 *   func_021F6F1C 0x021F6F1C thumb ov112
 *   func_021F9DE8 0x021F9DE8 thumb ov132
 *   func_021F95E8 0x021F95E8 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(void *);
extern void *func_021F9DD4(void *);
extern void *func_021F6E78(void *,int);
extern void func_021F6F14(void *,void *,u16,u8);
extern void func_021F6F1C(void *,void *,u32,u32);
extern void func_021F9DE8(void *,void *,u8);
extern void func_021F95E8(void *);
int func_021FC1D4(int a,char **p)
{
    char *q;
    u32 x,y;
    void *r,*s;
    q=p[0];
    x=func_0201134C(p[1]);
    y=func_0201134C(p[1]);
    r=func_021F9DD4(*(void **)(q+0x34));
    s=func_021F6E78(r,1);
    func_021F6F14(r,s,0x3ff,0x10);
    func_021F6F1C(r,s,y,0);
    func_021F9DE8(*(void **)(q+0x34),s,x);
    func_021F95E8(*(void **)(q+0x34));
    return 0;
}
