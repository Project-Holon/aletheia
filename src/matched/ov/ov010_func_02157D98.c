/*
 * function: func_02157D98
 * address: 0x02157D98
 * packet: pkt_ov010_02157D98
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D0DC 0x0203D0DC arm
 *   func_02157960 0x02157960 thumb ov010
 *   func_02157D68 0x02157D68 thumb ov010
 */
extern void func_0203D0DC(int);
extern void func_02157960(int, int, int);
extern void func_02157D68(int *p);
void func_02157D98(int p)
{
    func_0203D0DC(0);
    func_02157960(p, (int)func_02157D68, 0x1B7);
}
