/*
 * function: func_021C88E4
 * address:  0x021C88E4
 * packet:   pkt_ov093_021C88E4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC96C  0x021CC96C  thumb  ov093
 *   func_021CC9A4  0x021CC9A4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021CC96C(void *p);
extern u32 func_021CC9A4(void *p);

int func_021C88E4(u8 *p)
{
    if (func_021CC96C(p + 0x1D74) != 0) {
        if (func_021CC9A4(p + 0x1D74) != 0) return 2;
        return 1;
    }
    return 0;
}
