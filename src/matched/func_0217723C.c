/*
 * function: func_0217723C
 * address:  0x0217723C
 * packet:   pkt_0217723C
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Normalises a queried mode: 5 maps to 0, and a zero mode with the predicate
 * set maps to 0x14.
 *
 * symbols:
 *   func_02178E68  0x02178E68  thumb  ov014
 *   func_02177AEC  0x02177AEC  thumb  ov014
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_02178E68(void);
int func_02177AEC(void);

int func_0217723C(void)
{
    int r4 = func_02178E68();

    if (r4 == 5)
        r4 = 0;
    if (func_02177AEC() != 0 && r4 == 0)
        r4 = 0x14;
    return r4;
}
