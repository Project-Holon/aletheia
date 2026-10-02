/*
 * function: func_02158614
 * address: 0x02158614
 * packet: pkt_ov010_02158614
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02158344 0x02158344 thumb ov010
 * The callee reads its incoming r0; legacy void prototypes omit it.
 */
typedef unsigned char u8;
extern u8 *func_02158344(void *);
void func_02158614(void *p)
{
    u8 *q = func_02158344(p);
    if (q != 0)
        q[0x93F] |= 4;
}
