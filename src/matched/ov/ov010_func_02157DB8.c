/*
 * function: func_02157DB8
 * address: 0x02157DB8
 * packet: pkt_ov010_02157DB8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_02157960 0x02157960 thumb ov010
 *   func_02157D98 0x02157D98 thumb ov010
 */
extern int func_0203CD98(void);
extern void func_02157960(int, int, int);
extern void func_02157D98(int);
void func_02157DB8(int p)
{
    if (func_0203CD98() == 1)
        func_02157960(p, (int)func_02157D98, 0x1BE);
}
