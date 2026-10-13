/*
 * function: WIFICLUB_StateWaitMessage
 * address: 0x021BFB04
 * packet: pkt_ov099_021BFB04
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0203CB00 has no outside witness.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes; copied from
 *   ov099_func_021BEB68.c (leaf-cb00-r1.log).
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 * symbols:
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   WIFICLUB_OnFatalError 0x021BE900 thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_ShowMessage 0x021BAADC thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_StartBgmFade 0x021C24A4 thumb ov099
 *   WIFICLUB_StateSyncTimingStart 0x021BFB90 thumb ov099
 */
typedef unsigned char u8;
extern int GFL_NET_STATE_IsFatalError(void);
extern void WIFICLUB_OnFatalError(char *);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern int WIFICLUB_UpdateTalkStream(char *);
typedef unsigned int   u32;
extern u32 KEY_GetTrg(void);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void WIFICLUB_ShowMessage(char *, int, int);
extern void WIFICLUB_SetOwnStatusAndPublish(char *p, int kind, int value);
extern void WIFICLUB_StartBgmFade(char *, int);
extern int WIFICLUB_StateSyncTimingStart(char *, int);
int WIFICLUB_StateWaitMessage(char *p, int ret)
{
    if (GFL_NET_STATE_IsFatalError()) {
        WIFICLUB_OnFatalError(p);
        return ret;
    }
    if (DWC_RAP_GetTargetFriendIndex() < 0) {
        WIFICLUB_ShowStreamedMessage(p, 0x10, 0);
        *(int *)(p + 0x1cc) = 0x13;
        return ret;
    }
    if (WIFICLUB_UpdateTalkStream(p)) {
        if (KEY_GetTrg() & 3) {
            WIFICLUB_ClearTalkWindow(p);
            WIFICLUB_ShowMessage(p, 0x7b, 0);
            WIFICLUB_SetOwnStatusAndPublish(p, 4, 4);
            WIFICLUB_StartBgmFade(p, 0);
            *(u8 *)(p + 0x1355) = 0;
            *(int *)(p + 0x1cc) = 0x10;
        } else {
            WIFICLUB_StateSyncTimingStart(p, ret);
        }
    }
    return ret;
}
