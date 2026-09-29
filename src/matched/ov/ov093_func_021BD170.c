/*
 * function: func_021BD170
 * address:  0x021BD170
 * packet:   pkt_ov093_021BD170
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCAAC  0x021BCAAC  thumb  ov093
 *   func_021BCB98  0x021BCB98  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 *func_021BCAAC(u8 *p, u8 *q, u8 i);
extern int func_021BCB98(u8 *p, u8 *x, int i);

int func_021BD170(u8 *p, u8 *q)
{
    int i = 0;
    int r;
    u8 *x = func_021BCAAC(p, q, 0);
    r = 0;
    while (x) {
        i = func_021BCB98(p, x, i);
        if (i < 0) break;
        i++;
        x = func_021BCAAC(p, q, i);
        r = 1;
    }
    return r;
}
