/*
 * function: BTL_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent4
 * address: 0x021DB200
 * packet: pkt_ov093_021DB200
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_ClearFactorSkipCheck 0x021D7324 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
typedef unsigned char  u8;
extern void BTL_EVENT_ClearFactorSkipCheck(u8 *p);
void BTL_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent4(char *a, int b, int c, int *d) { if (c == BTL_EVENT_GetVar(2) && *d == 1) { BTL_EVENT_ClearFactorSkipCheck((u8 *)a); *d = 0; } }
