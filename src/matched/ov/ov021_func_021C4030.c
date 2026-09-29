/*
 * function: func_021C4030
 * address:  0x021C4030
 * packet:   pkt_ov021_021C4030
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017ED8  0x02017ED8  thumb
 *   func_021C4078  0x021C4078  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_02017E1C(u32 a, u32 b, u32 c);
extern int func_02017ED8(u32 a, u32 b);
extern u32 func_021C4078(void);

void func_021C4030(u32 *p, u32 *q)
{
    int i = 0;
    u32 a = func_02017E1C(p[0], 0xc, 0);

    if (a == func_02017E1C(p[1], 0xc, 0))
        return;
    if (func_02017ED8(q[0xc], q[0xd]) != 0)
        return;
    do {
        q[0xd] = func_021C4078();
        if (func_02017ED8(q[0xc], q[0xd]) != 0)
            return;
        i++;
    } while (i < 5);
}
