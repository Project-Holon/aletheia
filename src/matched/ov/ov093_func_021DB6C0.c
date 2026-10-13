/*
 * function: BTL_TOKUSEI_Klutz_InstallSkipCheckOnEntry
 * address: 0x021DB6C0
 * packet: pkt_ov093_021DB6C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_TOKUSEI_Klutz_InstallSkipCheck 0x021DB6A4 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern void BTL_TOKUSEI_Klutz_InstallSkipCheck(void *,int,int,int *);
void BTL_TOKUSEI_Klutz_InstallSkipCheckOnEntry(void *a,int b,int c,int *d) { if(c==BTL_EVENT_GetVar(2)) BTL_TOKUSEI_Klutz_InstallSkipCheck(a,b,c,d); }
