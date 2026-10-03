/*
 * function: func_021AF1E8
 * address:  0x021AF1E8
 * packet:   pkt_ov021_021AF1E8
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
extern int func_02006224(u32 a0);

void func_021AF1E8(u32 a)
{
    int i;
    u8 *p;

    p = func_02158F88(a);

    for (i = 0; i < 5; i++) {
        if (*p & (1 << i)) {
            if (func_02006224(i) == 0)
                *p &= ~(1 << i);
        }
    }
}
