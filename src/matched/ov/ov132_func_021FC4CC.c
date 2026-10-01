/*
 * function: func_021FC4CC
 * address: 0x021FC4CC
 * packet: pkt_ov132_021FC4CC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two-byte zero alignment padding at 021FC53A.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F9DDC 0x021F9DDC thumb ov132
 *   func_021F6F14 0x021F6F14 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(void *);
extern void *func_021F9DD4(void *);
extern void *func_021F9DDC(void *,u8);
extern void func_021F6F14(void *,void *,u16,u8);
int func_021FC4CC(int a,char **p)
{
    char *q;
    u32 v,w,x,y,z;
    void *r,*s;
    q=p[0];
    v=func_0201134C(p[1]);
    w=func_0201134C(p[1]);
    x=func_0201134C(p[1]);
    y=func_0201134C(p[1]);
    z=func_0201134C(p[1]);
    r=func_021F9DD4(*(void **)(q+0x34));
    s=func_021F9DDC(*(void **)(q+0x34),v);
    func_021F6F14(r,s,(u8)w|((u8)x<<5)|((u8)y<<10),z);
    return 0;
}
