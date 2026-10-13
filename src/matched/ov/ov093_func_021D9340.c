/*
 * unit: yes
 * function: HAND_TOKUSEI_HalveResidualDamage, HAND_TOKUSEI_GetHalveResidualDamageHandlers
 * address: 0x021D9340
 * packet: pkt_ov093_021D9340
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   gHalveResidualDamageHandlers 0x021F06B8 data a4
 */
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);
extern unsigned int gHalveResidualDamageHandlers;
void HAND_TOKUSEI_HalveResidualDamage(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2)) BTL_EVENT_OverwriteVar(0x20, BTL_EVENT_GetVar(0x20) << 1);
}
void *HAND_TOKUSEI_GetHalveResidualDamageHandlers(int *p) { *p = 1; return &gHalveResidualDamageHandlers; }
