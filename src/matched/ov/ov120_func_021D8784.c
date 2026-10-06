/*
 * function: func_021D8784
 * address: 0x021D8784
 * packet: pkt_ov120_021D8784
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 */
#include "../include/Obj00131.h"
typedef unsigned short u16;
struct MsgBank;
struct WordSet;
extern void func_0201F02C(struct WordSet *p, unsigned int i, void *a);
extern void func_02045CAC(struct MsgBank *bank, unsigned int index, void *dest);
typedef signed short   s16;
struct WordSet;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, unsigned char c, unsigned char d, unsigned char slot);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
void func_021D8784(char *p, void *n)
{
    void *q;
    func_0201F02C(((struct Obj00131 *)p)->f10, 0, n);
    func_02045CAC(((struct Obj00131 *)p)->fC, 37, (void *)(*(int *)&((struct Obj00131 *)p)->f20));
    func_0201F250(((struct Obj00131 *)p)->f10, (void *)(*(int *)&((struct Obj00131 *)p)->f18), (void *)(*(int *)&((struct Obj00131 *)p)->f20));
    if (!((struct Obj00131 *)p)->f98) ((struct Obj00131 *)p)->f98 = (void *)func_020450F0(1, 11, 10, 10, 3, 11, 1);
    q = ((struct Obj00131 *)p)->f98;
    func_02043B5C(func_02045770(q), 0);
    func_0201DD78(1, 2, 0);
    func_0201C7A4(func_02045770(q), 0, 0, (void *)(*(int *)&((struct Obj00131 *)p)->f18), (void *)(*(int *)&((struct Obj00131 *)p)->f14));
    func_02045334(q);
    func_02045374(q);
}
