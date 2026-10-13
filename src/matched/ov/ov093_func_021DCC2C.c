/*
 * unit: yes
 * function: HAND_TOKUSEI_ContraryInvertStatChange,HAND_TOKUSEI_AddContrary
 * address: 0x021DCC2C
 * packet: pkt_ov093_021DCC2C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gContraryHandlers 0x021F0708 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern unsigned char gContraryHandlers[];
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int,unsigned int);
void HAND_TOKUSEI_ContraryInvertStatChange(int a, int b, int c, int *d) { if (c == BTL_EVENT_GetVar(2)) *d = BTL_EVENT_OverwriteVar(32,-BTL_EVENT_GetVar(32)); }
void *HAND_TOKUSEI_AddContrary(int *p) { *p = 1; return gContraryHandlers; }
