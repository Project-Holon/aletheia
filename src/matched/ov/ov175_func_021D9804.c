/*
 * function: func_021D9804
 * address:  0x021D9804
 * packet:   pkt_021D9804
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E5548  0x021E5548  thumb  ov177
 *   REGULATION_Card_GetValue  0x0200B078  thumb
 *   func_021E7520  0x021E7520  thumb  ov177
 *
 * Lazy create: when the handle at +0x20 is empty, builds it through the eleven-argument ov177 constructor from the +0x0/+0x4/+0x8/+0x10/+0x14/+0x18 words and the heap id at +0x108.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef signed int     s32;
struct Reg2;
extern int func_021E5548(int *p);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern u32 func_021E7520(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g,
                         u32 h, u32 i, u32 j, u32 k);

void func_021D9804(u32 *obj, u32 arg)
{
    if (obj[8] == 0) {
        u32 base = func_021E5548((int *)obj[0]);
        obj[8] = func_021E7520(arg, base, obj[1], obj[2], obj[4], obj[5], obj[6], 0, 1,
                               REGULATION_Card_GetValue((struct Reg2 *)obj[0x42], 0xb), 0x57);
    }
}
