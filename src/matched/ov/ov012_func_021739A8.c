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
 *   UNION_COMM_StartConnectSync 0x02172EDC thumb ov012
 */
typedef unsigned char u8;
extern void UNION_COMM_StartConnectSync(u8 *p);
void UNION_COMMAND_RecvConnectSync(int a, int b, void *c, u8 *p)
{
    UNION_COMM_StartConnectSync(p);
    p[0x288e] |= (u8)(1 << a);
}
