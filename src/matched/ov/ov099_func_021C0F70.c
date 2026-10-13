/*
 * function: WIFICLUB_StateWaitJoinAnswer
 * address: 0x021C0F70
 * packet: pkt_ov099_021C0F70
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: 0x0203C5EC ARM verified EXACT 20 bytes in blocker-c5ec-one.log.
 *   extern char *d_021469DC;
 *   int GFL_NET_STATE_IsWifiDisconnectFinal(void) { return *(unsigned char *)(d_021469DC + 0x4a); }
 *   symbols: d_021469DC 0x021469DC data a4.
 * blocker: ov009 02156D5C is code in matched unit ov009_func_02156CF4.c,
 *   but its function: header lists only CF4; no duplicate leaf permitted.
 * extent-policy: no follower C filed while ARM9 also blocks this caller.
 * extent: 236-byte lead followed by two 4-byte return-r1 stubs at 105C/1060.
 * prototype: D7B0/D7BC preserve the caller's visible integer input through veneers.
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   WIFICLUBACTOR_GetPickResult 0x021B97F4 thumb ov099
 *   WIFICLUB_FindPeerActor 0x021BE2A8 thumb ov099
 *   WIFICLUBACTOR_RestoreActorUpdate 0x021B9AE0 thumb ov099
 *   GFL_NET_STATE_GetWifiState 0x0203C3EC arm
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   DWC_RAP_GetResult 0x02156D5C thumb ov009
 *   GFL_NET_STATE_IsWifiDisconnectFinal 0x0203C5EC arm
 *   WIFICLUB_CopyZeroToDeviceAddr 0x021C282C thumb ov099
 *   WIFICLUB_PublishOwnStatus 0x021BE6E4 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUBACTOR_AddNetCommands 0x021BA7D8 thumb ov099
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 */
extern int WIFICLUB_UpdateTalkStream(void *);
extern int WIFICLUBACTOR_GetPickResult(char *);
extern void *WIFICLUB_FindPeerActor(char *, int);
typedef unsigned char  u8;
extern void WIFICLUBACTOR_RestoreActorUpdate(void *w, u8 *s);
extern int GFL_NET_STATE_GetWifiState(void);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern unsigned DWC_RAP_GetResult(void);
extern int GFL_NET_STATE_IsWifiDisconnectFinal(void);
extern int WIFICLUB_CopyZeroToDeviceAddr(unsigned char *);
extern void WIFICLUB_PublishOwnStatus(char *);
extern unsigned char WIFICLUB_GetStatusKind(char *, void *);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void WIFICLUBACTOR_AddNetCommands(void *p);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
int WIFICLUB_StateWaitJoinAnswer(char *p, int ret)
{
    void *selection;
    WIFICLUB_UpdateTalkStream(p);
    if (--*(int *)(p + 0x1c4) < 0) {
        selection = WIFICLUB_FindPeerActor(p, WIFICLUBACTOR_GetPickResult(p + 0x274));
        if (selection) WIFICLUBACTOR_RestoreActorUpdate(p + 0x274, selection);
        *(int *)(p + 0x1cc) = 61;
    } else if (GFL_NET_STATE_GetWifiState() == 5) {
        WIFICLUB_SetPartnerNameWord(p, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (DWC_RAP_GetResult() == 5) {
        WIFICLUB_SetPartnerNameWord(p, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(p, 12, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (DWC_RAP_GetResult() == 4 || GFL_NET_STATE_IsWifiDisconnectFinal() != 0) {
        WIFICLUB_SetPartnerNameWord(p, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
    } else if (GFL_NET_STATE_GetWifiState() == 1) {
        WIFICLUB_CopyZeroToDeviceAddr(*(unsigned char **)(p + 8));
        WIFICLUB_PublishOwnStatus(p);
        WIFICLUB_GetStatusKind(p, *(void **)(p + 8));
        *(int *)(p + 0x1cc) = 41;
        WIFICLUB_ClearTalkWindow(p);
        WIFICLUBACTOR_AddNetCommands(p);
        *(int *)(p + 0x1e0) = 30;
        GFL_NET_SetAutoExit(1);
        GFL_NET_SetLoginOption(1);
    }
    return ret;
}
