/*
 * unit: yes
 * function: BTL_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent6A, BTL_TOKUSEI_GetMoldBreakerHandlers
 * address: 0x021DB224
 * packet: pkt_ov093_021DB224
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gMoldBreakerHandlers 0x021F0C24 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_ClearFactorSkipCheck 0x021D7324 thumb ov093
 */
extern const unsigned int gMoldBreakerHandlers[];
extern int BTL_EVENT_GetVar(int);
typedef unsigned char  u8;
extern void BTL_EVENT_ClearFactorSkipCheck(u8 *p);
void BTL_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent6A(char *a, int b, int c, int *d) { if (c == BTL_EVENT_GetVar(2) && *d == 1) { BTL_EVENT_ClearFactorSkipCheck((u8 *)a); *d = 0; } }
const unsigned int *BTL_TOKUSEI_GetMoldBreakerHandlers(int *n) { *n = 5; return gMoldBreakerHandlers; }
