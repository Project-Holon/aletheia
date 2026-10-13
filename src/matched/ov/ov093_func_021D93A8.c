/*
 * unit: yes
 * function: HAND_TOKUSEI_LeafGuardBlockOwnerEvent, HAND_TOKUSEI_GetLeafGuardHandlers
 * address: 0x021D93A8
 * packet: pkt_ov093_021D93A8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   gLeafGuardHandlers 0x021F0A40 data a4
 */
extern int BTL_EVENT_GetVar(int);
typedef unsigned char  u8;
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);
extern unsigned int gLeafGuardHandlers;
void HAND_TOKUSEI_LeafGuardBlockOwnerEvent(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(b) == 1) BTL_EVENT_OverwriteVar(0x41, 1);
}
void *HAND_TOKUSEI_GetLeafGuardHandlers(int *p) { *p = 3; return &gLeafGuardHandlers; }
