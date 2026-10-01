/*
 * function: func_021AF26C
 * address:  0x021AF26C
 * packet:   pkt_ov021_021AF26C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_02158F88  0x02158F88  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u8 *func_02158F88(u32 a);
extern void func_020061F8(int i);

void func_021AF26C(u32 a)
{
    int i;
    u8 *p;

    p = func_02158F88(a);

    for (i = 0; i < 5; i++) {
        if (*p & (1 << i))
            func_020061F8(i);
    }
    *p = 0;
}
