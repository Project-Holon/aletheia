/*
 * function: func_021B8778
 * address:  0x021B8778
 * packet:   pkt_ov093_021B8778
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B87E8  0x021B87E8  thumb  ov093
 *   func_021B8834  0x021B8834  thumb  ov093
 *   func_021B88EC  0x021B88EC  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021B8CB0 { u32 f0; u32 mode; };
extern u8 func_021B87E8(void *p, u32 k, u32 v, u8 *out);
extern u8 func_021B8834(void *p, u32 k, u8 v, u8 *out);
extern u8 func_021B88EC(void *p, u32 k, u32 v, u8 *out);

u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out)
{
    u8 hi = k >> 8;
    u8 lo = k;

    if (hi == 0) {
        *out = lo;
        return *out != 6;
    }
    if (lo != 6) {
        switch ((*p)->mode) {
        case 0:
        default:
            return func_021B87E8(p, hi, lo, out);
        case 1:
            return func_021B8834(p, hi, lo, out);
        case 2:
            return func_021B88EC(p, hi, lo, out);
        case 3:
            return func_021B87E8(p, hi, lo, out);
        }
    }
    *out = 6;
    return 0;
}
