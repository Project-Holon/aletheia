/*
 * function: UNION_COMMAND_RecvConnectSync
 * address: 0x021739A8
 * packet: pkt_ov012_021739A8
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02172EDC 0x02172EDC thumb ov012
 */
typedef unsigned char u8;
extern void func_02172EDC(u8 *p);
void UNION_COMMAND_RecvConnectSync(int a, int b, void *c, u8 *p)
{
    func_02172EDC(p);
    p[0x288e] |= (u8)(1 << a);
}
