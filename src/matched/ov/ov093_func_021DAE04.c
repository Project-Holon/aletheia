/*
 * function: BTL_ABILITY_DampBlockExplosion
 * address: 0x021DAE04
 * packet: pkt_ov093_021DAE04
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int,unsigned int);
void BTL_ABILITY_DampBlockExplosion(int a, int b, int c, int *d) { unsigned short k; k = BTL_EVENT_GetVar(18); *d = 0; if (k == 153 || k == 120) { if (BTL_EVENT_GetVar(34) == 0) { *d = BTL_EVENT_OverwriteVar(34,19); d[1] = k; } } }
