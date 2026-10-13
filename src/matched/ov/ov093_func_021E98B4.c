/*
 * function: BTLV_CORE_PollMoveMenu
 * address: 0x021E98B4
 * packet: pkt_ov093_021E98B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * interface: eight-byte ldr-r3/bx-r3 stub forwards only live r0;
 * target body reads only r0. Original caller compares returned r0 with zero.
 * symbols:
 *   BTLV_CORE_RunStep 0x021E9738 thumb ov093
 */
typedef unsigned int u32;
struct S;
extern int BTLV_CORE_RunStep(struct S *s);
u32 BTLV_CORE_PollMoveMenu(void *p)
{
    return BTLV_CORE_RunStep(p);
}
