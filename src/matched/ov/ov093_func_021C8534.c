/*
 * function: func_021C8534
 * address:  0x021C8534
 * packet:   pkt_ov093_021C8534
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021C8578  0x021C8578  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021B8DDC(u32 x);
extern int func_021C8578(u8 *p, int v, u32 *out);

int func_021C8534(u8 *p)
{
    u32 i;
    u32 buf;
    for (i = 0; i < p[0x785]; i++) {
        if (func_021C8578(p + 0x1ab8, func_021B8DDC(p[0x791 + i]), &buf)) {
            return 1;
        }
    }
    return 0;
}
