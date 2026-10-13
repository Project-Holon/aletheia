/*
 * unit: yes
 * function: HAND_TOKUSEI_TechnicianBoostWeakMove, HAND_TOKUSEI_GetTechnicianHandlers
 * address: 0x021D90E8
 * packet: pkt_ov093_021D90E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   gTechnicianHandlers 0x021F0608 data a4
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int, int);
extern unsigned int gTechnicianHandlers;
void HAND_TOKUSEI_TechnicianBoostWeakMove(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && (unsigned int)BTL_EVENT_GetVar(0x30) <= 0x3c) BTL_EVENT_MultiplyVar(0x31, 0x30 << 7);
}
void *HAND_TOKUSEI_GetTechnicianHandlers(int *p) { *p = 1; return &gTechnicianHandlers; }
