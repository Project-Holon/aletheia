/*
 * function: func_02177A34
 * address:  0x02177A34
 * packet:   pkt_ov014_02177A34
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data   a4
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_02178E38  0x02178E38  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *g_021797A4;
extern int func_02178E4C(void);
extern u32 func_02178E38(void);

int func_02177A34(u32 n)
{
    if (g_021797A4 == 0)
        return 0;
    if (func_02178E4C() != 4 && func_02178E4C() != 5)
        return 0;
    if (func_02178E38() & (1 << n))
        return 1;
    return 0;
}
