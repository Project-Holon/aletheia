/*
 * function: func_02157E08
 * address: 0x02157E08
 * packet: pkt_ov010_02157E08
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203CBAC 0x0203CBAC arm
 *   d_02172868 0x02172868 data a1
 *   d_02172808 0x02172808 data a1
 */
typedef unsigned char u8;
extern int func_0203CD98(void);
extern void func_0203CBAC(void *, void (*)(void), void *);
extern u8 d_02172868[];
extern u8 d_02172808[];
int func_02157E08(void *p)
{
    if (func_0203CD98() != 0)
        return 0;
    d_02172868[7] = *(int *)p;
    func_0203CBAC(d_02172808, 0, p);
    return 1;
}
