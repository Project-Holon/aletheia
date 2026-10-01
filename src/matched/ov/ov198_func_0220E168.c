/*
 * function: func_0220E168
 * address: 0x0220E168
 * packet: pkt_ov198_0220E168
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: global pointer re-read at 0220E17C and 0220E196 before func_0201CCE4.
 * symbols:
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { char *volatile global; } Context;
struct Descriptor;
struct Cfg;
extern unsigned func_0201DD78(unsigned,unsigned,unsigned);
extern int func_02012FFC(unsigned);
extern int func_0201CCE4(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
void func_0220E168(char *p)
{
    int v;
    void *obj;
    v = func_02012FFC(func_0201DD78(1,2,0));
    *(int *)(p + 0x1eb0) = func_0201CCE4(*(unsigned *)(p+0x1f68),0,0,*(unsigned *)(p+0x1ea8),*(unsigned *)(((Context *)p)->global+12),v,*(unsigned *)(p+0x1d4),10,*(u16 *)(((Context *)p)->global+16),15);
    obj = *(void **)(p+0x1f68);
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
}
