/*
 * function: HAND_TOKUSEI_Klutz_InstallSkipCheck
 * address: 0x021DB6A4
 * packet: pkt_ov093_021DB6A4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_SetFactorSkipCheck 0x021D7320 thumb ov093
 *   HAND_TOKUSEI_Klutz_SkipCheck 0x021DB650 thumb ov093
 */
typedef unsigned int   u32;
struct QS;
extern void BTL_EVENT_SetFactorSkipCheck(struct QS *p, u32 v);
extern int HAND_TOKUSEI_Klutz_SkipCheck(int,int,int,int,int,unsigned char);

void HAND_TOKUSEI_Klutz_InstallSkipCheck(void *a, int b, int c, int *d)
{
    if (*d == 0) {
        BTL_EVENT_SetFactorSkipCheck(a, (u32)HAND_TOKUSEI_Klutz_SkipCheck);
        *d = 1;
    }
}
