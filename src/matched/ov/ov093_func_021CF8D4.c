/*
 * function: func_021CF8D4
 * address:  0x021CF8D4
 * packet:   pkt_ov093_021CF8D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CF89C  0x021CF89C  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021CF9B4  0x021CF9B4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021CF89C(u8 *p, void *q);
extern u16 func_021D5B40(void *q);
extern u32 func_021CF9B4(u8 *p, void *q, u8 *a, u16 *b);

u32 func_021CF8D4(u8 *p, void *q, u8 *a, u16 *b)
{
    u32 r;
    if (func_021CF89C(p, q) != 0) {
        if (func_021D5B40(q) == 0x127) {
            return 4;
        }
    }
    r = func_021CF9B4(p, q, a, b);
    if (r == 4) {
        *a = 0x1f;
        *b = 0;
        r = 4;
    }
    return r;
}
