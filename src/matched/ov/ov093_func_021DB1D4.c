/*
 * function: HAND_TOKUSEI_MoldBreaker_InstallSkipCheck
 * address: 0x021DB1D4
 * packet: pkt_ov093_021DB1D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: BTL_EVENT_SetFactorSkipCheck stores the full r1 payload unchanged at +12;
 * callback type records the observed pointer, with no arithmetic/narrowing.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_SetFactorSkipCheck 0x021D7320 thumb ov093
 *   HAND_TOKUSEI_MoldBreaker_SkipCheck 0x021DB1A8 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
typedef unsigned int   u32;
struct QS;
extern void BTL_EVENT_SetFactorSkipCheck(struct QS *p, u32 v);
extern int HAND_TOKUSEI_MoldBreaker_SkipCheck(int,int,int,int,unsigned short);
void HAND_TOKUSEI_MoldBreaker_InstallSkipCheck(char *a, int b, int c, int *d) { if (c == BTL_EVENT_GetVar(3) && *d == 0) { BTL_EVENT_SetFactorSkipCheck((struct QS *)a,(u32)HAND_TOKUSEI_MoldBreaker_SkipCheck); *d = 1; } }
