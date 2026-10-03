/*
 * function: func_021D7BD4
 * address:  0x021D7BD4
 * packet:   pkt_ov093_021D7BD4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D5814(void *p, int k);
extern int func_021D59B4(u8 *p, int k);

int func_021D7BD4(void *p, int k)
{
    u16 r;

    switch (k) {
    case 4:
        if (func_021D5814(p, 5) != 0) return 0;
        if (func_021D5814(p, 8) != 0) return 0;
        if (func_021D5814(p, 4) != 0) return 0;
        break;
    case 3:
        if (func_021D5814(p, 0xe) != 0) return 0;
        break;
    default:
        return 0;
    }
    r = func_021D59B4(p, 0xe) / 16;
    if (r == 0) r = 1;
    return r;
}
