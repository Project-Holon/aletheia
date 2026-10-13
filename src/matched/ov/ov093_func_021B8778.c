/*
 * function: BTL_MAIN_DecodeMessageCode
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
 *   BTL_MAIN_DecodeMessageCodeBasic  0x021B87E8  thumb  ov093
 *   BTL_MAIN_ExpandPosDouble  0x021B8834  thumb  ov093
 *   BTL_MAIN_ExpandPosTriple  0x021B88EC  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021B8CB0 { u32 f0; u32 mode; };
extern u8 BTL_MAIN_DecodeMessageCodeBasic(void *p, u32 k, u32 v, u8 *out);
extern u8 BTL_MAIN_ExpandPosDouble(void *p, u32 k, u8 v, u8 *out);
extern u8 BTL_MAIN_ExpandPosTriple(void *p, u32 k, u32 v, u8 *out);

u8 BTL_MAIN_DecodeMessageCode(struct Unk021B8CB0 **p, int k, u8 *out)
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
            return BTL_MAIN_DecodeMessageCodeBasic(p, hi, lo, out);
        case 1:
            return BTL_MAIN_ExpandPosDouble(p, hi, lo, out);
        case 2:
            return BTL_MAIN_ExpandPosTriple(p, hi, lo, out);
        case 3:
            return BTL_MAIN_DecodeMessageCodeBasic(p, hi, lo, out);
        }
    }
    *out = 6;
    return 0;
}
