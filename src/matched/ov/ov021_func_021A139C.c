/*
 * function: func_021A139C
 * address:  0x021A139C
 * packet:   pkt_ov021_021A139C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0217394C  0x0217394C  thumb  ov012
 *   func_021F0054  0x021F0054  thumb  ov031
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Ctx;
struct Obj;
extern void *func_02188C80(void *p);
extern int func_0217394C(const struct Ctx *p);
extern void func_021F0054(struct Obj *p, int mode);

void func_021A139C(u32 *p, u32 a)
{
    u32 h = (u32)func_02188C80((void *)p[5]);
    if (a == 1 && func_0217394C((const struct Ctx *)h) == 0)
        a = 0;
    func_021F0054((struct Obj *)p[8], a);
}
