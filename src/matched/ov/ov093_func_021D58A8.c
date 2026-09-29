/*
 * function: func_021D58A8
 * address:  0x021D58A8
 * packet:   pkt_ov093_021D58A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D587C  0x021D587C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D587C(void *p, int k);
extern int func_021D59B4(void *p, int v);

int func_021D58A8(u8 *p, int k)
{
    int v = func_021D587C(p, k);
    switch (v) {
    case 8:
        return *(u16 *)(p + 0xee);
    case 9:
        return *(u16 *)(p + 0xf0);
    case 10:
        return *(u16 *)(p + 0xf2);
    case 11:
        return *(u16 *)(p + 0xf4);
    case 12:
        return *(u16 *)(p + 0xf6);
    case 6:
        return 6;
    case 7:
        return 6;
    }
    return func_021D59B4(p, v);
}
