/*
 * function: WIFICLUB_StateLobbyMain
 * address: 0x021BF2C4
 * packet: pkt_ov099_021BF2C4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0203CB00 at +001A lacks an outside code witness.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes; copied from
 *   ov099_func_021BFB04.c, itself copied from ov099_func_021BEB68.c
 *   (leaf-cb00-r1.log).
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 * shape: the nested record test preserves its branch-to-branch;
 *   the named call-result value fixes cmp r0,r1 at +0176.
 * prototype: 021C1968 tail forwards the result read by this caller;
 *   0203D7B0/0203D7BC keep the visible r0 argument; 021C2864's
 *   r1 stays full-width because neither call site truncates it.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   GFL_NET_STATE_GetWifiState 0x0203C3EC arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_02005728 0x02005728 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   DWC_RAP_GetNewClientAid 0x02156B8C thumb ov009
 *   DWC_RAP_SetVchatEnabled 0x02156BC4 thumb ov009
 *   DWC_RAP_GetCanceledPeerIndex 0x02156BA8 thumb ov009
 *   DWC_RAP_GetVchatEnabled 0x02156B70 thumb ov009
 *   WIFICLUB_OnFatalError 0x021BE900 thumb ov099
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_ShowMessage 0x021BAADC thumb ov099
 *   WIFICLUB_DrawPlayerInfoWindow 0x021BAEDC thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_UpdatePeerActors 0x021BF280 thumb ov099
 *   WIFICLUB_RedrawSlotPanelIfPending 0x021C1BEC thumb ov099
 *   WIFICLUBACTOR_RestartBlink 0x021B9B54 thumb ov099
 *   WIFICLUBACTOR_GetMode 0x021B98FC thumb ov099
 *   WIFICLUB_ToggleOwnSeat 0x021C1968 thumb ov099
 *   WIFICLUB_ClosePanelIfTouchActive 0x021C1A30 thumb ov099
 *   WIFICLUB_ClosePartnerPanel 0x021C19DC thumb ov099
 *   WIFICLUB_UpdateSlotPanel 0x021C1B04 thumb ov099
 *   WIFICLUB_FindPeerActor 0x021BE2A8 thumb ov099
 *   WIFICLUBACTOR_ShowMarkerAtActor 0x021B989C thumb ov099
 *   WIFICLUB_ReleaseSlotActors 0x021BF29C thumb ov099
 *   WIFICLUBACTOR_HideMarker 0x021B98F0 thumb ov099
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_IsPeerAddrOfStatus 0x021C27F8 thumb ov099
 *   WIFICLUB_GetStatusChangeCount 0x021C2874 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_IsKindActive 0x021BDDA8 thumb ov099
 *   WIFICLUB_IsNetStateConnected 0x021BF03C thumb ov099
 *   WIFICLUB_IsNetStateDisconnecting 0x021BF068 thumb ov099
 *   WIFICLUB_GetStatusSeatFlag 0x021C27E0 thumb ov099
 *   WIFICLUB_SetStatusModeFlag 0x021C2864 thumb ov099
 *   WIFICLUBACTOR_Update 0x021B96D0 thumb ov099
 *   WIFICLUBACTOR_TickBlink 0x021B9B64 thumb ov099
 *   WIFICLUBACTOR_StartBlinkOnTile 0x021B9B24 thumb ov099
 *   WIFICLUBACTOR_GetPickResult 0x021B97F4 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_NET_STATE_IsFatalError(void);
extern void GFL_NET_STATE_SetError(int, u32, u32, u32);
extern int GFL_NET_STATE_GetWifiState(void);
typedef signed short   s16;
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern u32 KEY_GetTrg(void);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern u32 func_02005728(u32);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);
extern void MI_CpuCopy8(void *, void *, int);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern int DWC_RAP_GetNewClientAid(void);
extern void DWC_RAP_SetVchatEnabled(int);
extern int DWC_RAP_GetCanceledPeerIndex(void);
extern s16 DWC_RAP_GetVchatEnabled(void);
extern void WIFICLUB_OnFatalError(char *);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern void WIFICLUB_ShowMessage(char *, int, int);
extern void WIFICLUB_DrawPlayerInfoWindow(char *);
extern void WIFICLUB_SetOwnStatusAndPublish(char *, int, int);
extern void WIFICLUB_UpdatePeerActors(void *a, void *b);
extern void WIFICLUB_RedrawSlotPanelIfPending(u8 *p);
extern void WIFICLUBACTOR_RestartBlink(char *);
extern u32 WIFICLUBACTOR_GetMode(char *);
extern int WIFICLUB_ToggleOwnSeat(char *);
extern void WIFICLUB_ClosePanelIfTouchActive(u8 *p, int v);
extern void WIFICLUB_ClosePartnerPanel(char *, int);
extern u8 WIFICLUB_UpdateSlotPanel(char *, int);
extern void *WIFICLUB_FindPeerActor(char *, int);
extern void WIFICLUBACTOR_ShowMarkerAtActor(void *, void *);
extern void WIFICLUB_ReleaseSlotActors(char *);
extern void WIFICLUBACTOR_HideMarker(void *p);
extern int WIFICLUB_GetFriendStatus(int i);
extern int WIFICLUB_IsPeerAddrOfStatus(char *p, char *q);
extern int WIFICLUB_GetStatusChangeCount(void *);
extern u8 WIFICLUB_GetStatusKind(char *, void *);
extern u8 WIFICLUB_GetStatusPhase(char *, void *);
extern int WIFICLUB_IsKindActive(int x);
extern int WIFICLUB_IsNetStateConnected(char *);
extern int WIFICLUB_IsNetStateDisconnecting(char *);
extern int WIFICLUB_GetStatusSeatFlag(void *);
extern void WIFICLUB_SetStatusModeFlag(void *, int);
extern u32 WIFICLUBACTOR_Update(char *);
extern void WIFICLUBACTOR_TickBlink(char *);
extern void WIFICLUBACTOR_StartBlinkOnTile(char *);
extern u8 WIFICLUBACTOR_GetPickResult(char *);
int WIFICLUB_StateLobbyMain(char *p, int ret)
{
    u32 action = 0, kind;
    int index, i, key, value;
    void *record;
    *(u8 *)(p + 0x1356) = 0;
    if (WIPE_SYS_EndCheck() == 0) return ret;
    if (GFL_NET_STATE_IsFatalError()) { WIFICLUB_OnFatalError(p); return ret; }
    if (*(int *)(p + 0x1f0) != -1) {
        if (++*(int *)(p + 0x1c8) > 0xe10) { GFL_NET_STATE_SetError(0, 0, 0, 0x3f1); return ret; }
    }
    if (GFL_NET_STATE_GetWifiState() == 4) {
        WIFICLUB_SetPartnerNameWord(p, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(p, 15, 0);
        *(int *)(p + 0x1cc) = 21;
        WIFICLUB_SetOwnStatusAndPublish(p, 1, 2);
        GFL_NET_STATE_WifiDisconnect(1);
        return ret;
    }
    WIFICLUB_UpdatePeerActors(p, (void *)33);
    WIFICLUB_RedrawSlotPanelIfPending((u8 *)p);
    WIFICLUBACTOR_RestartBlink(p + 0x274);
    if (WIFICLUBACTOR_GetMode(p + 0x274) == 0) {
        if (DWC_RAP_GetNewClientAid() == -1 && (KEY_GetTrg() & 0x400)) {
            if (WIFICLUB_ToggleOwnSeat(p)) WIFICLUB_ShowMessage(p, 57, 0);
            else WIFICLUB_ShowMessage(p, 58, 0);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            WIFICLUB_DrawPlayerInfoWindow(p);
            *(int *)(p + 0x1cc) = 12;
            WIFICLUB_ClosePanelIfTouchActive((u8 *)p, 33);
            return ret;
        }
        key = WIFICLUB_UpdateSlotPanel(p, 33);
        record = WIFICLUB_FindPeerActor(p, key);
        if (key != 0) {
            if (record != 0) WIFICLUBACTOR_ShowMarkerAtActor(p + 0x274, record);
            else { WIFICLUB_ReleaseSlotActors(p); WIFICLUBACTOR_HideMarker(p + 0x274); }
        } else { WIFICLUB_ReleaseSlotActors(p); WIFICLUBACTOR_HideMarker(p + 0x274); }
    }
    for (i = 0; i < 32; i++) {
        index = func_02005728(32);
        if (WIFICLUB_IsPeerAddrOfStatus(*(void **)(p + 8), (char *)WIFICLUB_GetFriendStatus(index)) != 0) {
            value = WIFICLUB_GetStatusChangeCount((void *)WIFICLUB_GetFriendStatus(index));
            if (value != *(*(u8 **)(p + 0x248) + index + 0x24)) {
            WIFICLUB_GetStatusKind(p, (void *)WIFICLUB_GetFriendStatus(index));
            WIFICLUB_GetStatusPhase(p, (void *)WIFICLUB_GetFriendStatus(index));
            *(u16 *)(p + 0x242) = index + 1;
            GFL_USE_PlaySeInSlot((void *)0x806, 0);
            *(int *)(p + 0x1cc) = 63;
            return ret;
            }
        }
    }
    if (WIFICLUB_IsNetStateConnected(p) && *(int *)(p + 0x1f0) != -1) {
        GFL_USE_PlaySeInSlot((void *)0x806, 0);
        GFL_NET_SetAutoExit(1);
        GFL_NET_SetLoginOption(1);
        *(int *)(p + 0x1cc) = 40;
        return ret;
    }
    if (*(int *)(p + 0x1f0) == -1 && DWC_RAP_GetNewClientAid() != -1) {
        index = DWC_RAP_GetNewClientAid();
        *(int *)(p + 0x1f0) = index;
        WIFICLUB_SetPartnerNameWord(p, index);
        if (!*(u8 *)(p + 0x1351)) WIFICLUB_ShowStreamedMessage(p, 46, 0);
        *(int *)(p + 0x1c8) = 0;
    } else if (*(int *)(p + 0x1f0) != -1 && DWC_RAP_GetNewClientAid() == -1) {
        DWC_RAP_SetVchatEnabled(0);
        WIFICLUB_SetStatusModeFlag(*(void **)(p + 8), WIFICLUB_GetStatusSeatFlag(*(void **)(p + 8)));
        WIFICLUB_SetPartnerNameWord(p, *(int *)(p + 0x1f0));
        WIFICLUB_ShowStreamedMessage(p, 15, 0);
        GFL_NET_STATE_WifiDisconnect(1);
        *(int *)(p + 0x1cc) = 19;
        return ret;
    }
    if (WIFICLUB_IsNetStateDisconnecting(p) && *(int *)(p + 0x1f0) != -1) {
        WIFICLUB_SetPartnerNameWord(p, DWC_RAP_GetCanceledPeerIndex());
        WIFICLUB_ShowStreamedMessage(p, 15, 0);
        *(int *)(p + 0x1cc) = 19;
        return ret;
    }
    if (DWC_RAP_GetVchatEnabled() == 1 && DWC_RAP_GetNewClientAid() == -1) {
        DWC_RAP_SetVchatEnabled(0);
        WIFICLUB_SetStatusModeFlag(*(void **)(p + 8), WIFICLUB_GetStatusSeatFlag(*(void **)(p + 8)));
    }
    kind = WIFICLUB_GetStatusKind(p, *(void **)(p + 8));
    if (*(int *)(p + 0x1f0) == -1) {
        if ((KEY_GetTrg() & 2) && WIFICLUB_IsKindActive(kind)) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            *(int *)(p + 0x1cc) = 31;
            WIFICLUB_ClosePartnerPanel(p, 33);
            return ret;
        }
        action = WIFICLUBACTOR_Update(p + 0x274);
        WIFICLUBACTOR_TickBlink(p + 0x274);
    }
    switch (action) {
    case 0: return ret;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if (WIFICLUB_IsKindActive(kind)) *(int *)(p + 0x1cc) = 31;
        else {
            *(int *)(p + 0x1d0) = 0;
            *(int *)(p + 0x1cc) = 49;
            WIFICLUB_ShowStreamedMessage(p, 25, 1);
        }
        WIFICLUB_ClosePanelIfTouchActive((u8 *)p, 33);
        return ret;
    case 3:
        if (kind == 1) {
            *(int *)(p + 0x135c) = 1;
            GFL_USE_PlaySeDefaultVolume(0x54c);
            WIFICLUBACTOR_StartBlinkOnTile(p + 0x274);
            *(int *)(p + 0x1cc) = 28;
            WIFICLUB_ClosePanelIfTouchActive((u8 *)p, 33);
            *(u8 *)(p + 0x1351) = 0;
            return ret;
        }
        break;
    case 2:
        if (kind == 1) {
            index = WIFICLUBACTOR_GetPickResult(p + 0x274);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            MI_CpuCopy8((void *)WIFICLUB_GetFriendStatus(index - 1), p + 0x24c, 32);
            *(int *)(p + 0x1cc) = 34;
            WIFICLUB_ClosePanelIfTouchActive((u8 *)p, 33);
            return ret;
        }
        break;
    }
    return ret;
}
