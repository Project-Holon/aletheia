/*
 * function: GSYNC_STATE_StateWaitEndingBgm
 * address: 0x021D7130
 * packet: pkt_ov123_021D7130
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateClearMessageExit 0x021D70BC thumb ov123
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int GSYNC_MESSAGE_UpdateStream(char *);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateClearMessageExit(char *);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32 v);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
void GSYNC_STATE_StateWaitEndingBgm(char *p)
{
    if (GSYNC_MESSAGE_UpdateStream(*(char **)(p + 0x18)) != 0) {
        int n = *(int *)(p + 0x78) - 1;
        *(int *)(p + 0x78) = n;
        if (n <= 0) {
            if (n == 0) {
                GFL_USE_PopBgm();
                GFL_USE_SetBgmPlayerParam(0);
                GFL_USE_FadeInBgmFull(6);
            }
            if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
                GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateClearMessageExit, 0x20B);
            }
        }
    }
}
