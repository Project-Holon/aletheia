/*
 * function: func_021EAA34
 * address:  0x021EAA34
 * packet:   pkt_ov093_021EAA34
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EAA4C  0x021EAA4C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021EAA4C(int a, u8 *out);

int func_021EAA34(u8 *o, u8 *out)
{
    if (func_021EAA4C(*(int *)(o + 0x180), out) != 0) {
        return 1;
    }
    return 0;
}
