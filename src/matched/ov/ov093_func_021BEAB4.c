/*
 * function: BTL_SERVER_FLOW_CheckMoveInterrupt
 * address: 0x021BEAB4
 * packet: pkt_ov093_021BEAB4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The byte loaded and compared in r1 remains the veneer call's second
 * argument. The veneer at 021BEB04 preserves r0/r1 to its target.
 * symbols:
 *   BTL_SERVER_FLOW_DispatchMoveInterruptCheckEvent 0x021BEB14 thumb ov093
 *   func_021BEB04 0x021BEB04 thumb ov093
 */
typedef unsigned char u8;
extern int BTL_SERVER_FLOW_DispatchMoveInterruptCheckEvent(int a, u8 *b, int c, int d, u8 *e, u8 *g);
extern u8 func_021BEB04(u8 *p, int selector);
int BTL_SERVER_FLOW_CheckMoveInterrupt(u8 *p, u8 *a, int b, int c, u8 *q)
{
    u8 buf[2];
    buf[1] = 0x1F;
    buf[0] = 0x1F;
    BTL_SERVER_FLOW_DispatchMoveInterruptCheckEvent((int)p, a, b, c, &buf[1], &buf[0]);
    if (buf[1] != 0x1F) {
        q[7] = (buf[0] != 0x1F) ? func_021BEB04(p + 0x1AB8, buf[0]) : 6;
        q[1] = buf[1];
        q[0] = 1;
        return 1;
    }
    return 0;
}
