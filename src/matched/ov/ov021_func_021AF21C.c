/*
 * function: func_021AF21C
 * address:  0x021AF21C
 * packet:   pkt_ov021_021AF21C
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

extern u8 *func_02158F88(void *p);
extern int func_02006148(u32 a);

void func_021AF21C(u32 a, u32 b)
{
    u8 *p = func_02158F88((void *)a);

    *p |= 1 << func_02006148(b);
}
