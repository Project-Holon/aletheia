/*
 * function: func_021D8520
 * address: 0x021D8520
 * packet: pkt_ov120_021D8520
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 0x021D858E.
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj04490.h"
typedef unsigned short u16;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, unsigned int index, void *dest);
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, unsigned char c, unsigned char d, unsigned char slot);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
typedef signed short   s16;
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D8520(char *p, u16 n)
{
    void *q;
    func_02045CAC(((struct Obj04490 *)p)->fC, n, (void *)(((struct Obj04490 *)p)->f18));
    if (!((struct Obj04490 *)p)->f68) ((struct Obj04490 *)p)->f68 = (void *)func_020450F0(1, 0, 0, 14, 2, 11, 1);
    q = ((struct Obj04490 *)p)->f68;
    func_02043B5C(func_02045770(q), 0);
    func_0201DD78(15, 2, 0);
    func_0201C7A4(func_02045770(q), 2, 2, (void *)(((struct Obj04490 *)p)->f18), (void *)(((struct Obj04490 *)p)->f14));
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}
