/*
 * function: func_021CA294
 * address:  0x021CA294
 * packet:   pkt_021CA294
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CA25C  0x021CA25C  thumb
 *   func_0202EB04  0x0202EB04  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct CodeIn;
extern void func_021CA25C(u32 a, u32 b);
extern void func_0202EB04(struct CodeIn *p);

void func_021CA294(u8 *p, int a)
{
    func_021CA25C(a, 1);
    func_0202EB04(*(void **)(p + 0x184));
}
