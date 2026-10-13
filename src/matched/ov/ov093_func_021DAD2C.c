/*
 * function: HAND_TOKUSEI_TruantToggleLoafing
 * address: 0x021DAD2C
 * packet: pkt_ov093_021DAD2C
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
void HAND_TOKUSEI_TruantToggleLoafing(int a, int b, int c, int *d) { if (c == BTL_EVENT_GetVar(2)) { if (*d != 0) { d[1] = BTL_EVENT_OverwriteVar(34,19); *d = 0; } else *d = 1; } }
