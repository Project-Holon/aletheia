/*
 * function: BTL_SERVER_FLOW_ProcPokeHpChangeFinish
 * address: 0x021C2314
 * packet: pkt_ov093_021C2314
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the return at 0x021C232A.
 * interface: BTL_SERVER_FLOW_KillPoke reads r0/r1/r2 and forwards r2 unchanged;
 * BTL_SERVER_FLOW_ProcFaintedPoke has two arguments in its existing DIFF note.
 * symbols:
 *   BTL_SERVER_FLOW_KillPoke 0x021C5BE4 thumb ov093
 *   BTL_SERVER_FLOW_ProcFaintedPoke 0x021C4F64 thumb ov093
 */
typedef unsigned char u8;
extern void BTL_SERVER_FLOW_KillPoke(u8 *, u8 *, int);
extern int BTL_SERVER_FLOW_ProcFaintedPoke(u8 *, u8 *);
int BTL_SERVER_FLOW_ProcPokeHpChangeFinish(u8 *p, u8 *a)
{
    BTL_SERVER_FLOW_KillPoke(p, a, 0);
    return BTL_SERVER_FLOW_ProcFaintedPoke(p, a);
}
