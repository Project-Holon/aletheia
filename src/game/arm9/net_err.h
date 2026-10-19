#ifndef GAME_ARM9_NET_ERR_H
#define GAME_ARM9_NET_ERR_H

/* Public functions of net_err.c, prototypes copied from their definitions. */

void GFL_NET_SetBgmTrackVolumeUnlessVoiceChat(void *eventMask, void *eventValue);
void GFL_NET_ERR_CreateHeap(void);
void GFL_NET_ERR_Init(u32 heapId);
void GFL_NET_ERR_DetectNetError(void);
u32 GFL_NET_ERR_ShowScreen(u32 isFatal);
void GFL_NET_ERR_HaltWithMessage(u32 messageId);
void GFL_NET_ERR_Halt(void);
void GFL_NET_ERR_SetKeepDark(u32 keepDark);
void GFL_NET_ERR_ClearKeepDark(void);
void GFL_NET_ERR_RestoreBrightness(void);
void GFL_NET_ERR_UpdateNetwork(void);
void GFL_NET_ERR_ShowSimpleScreen(void);
void GFL_NET_ERR_HaltIfActive(void);
void GFL_NET_ERR_DrawAndHang(void);
void GFL_NET_ERR_RecordError(void);
u32 GFL_NET_ERR_GetErrorLevel(void);
void GFL_NET_ERR_RequestScreen(void);
void GFL_NET_ERR_RaiseFatal(unsigned int messageId);
void GFL_NET_ERR_ExitAndHalt(void);
void GFL_NET_ERR_ResetState(void);
u32 GFL_NET_ERR_WaitLinkClosed(void);
u32 GFL_NET_ERR_ProcScreen(u32 isFatal);
void GFL_NET_ERR_SaveDisplayAndDraw(u32 screenIndex, u32 isWifiLink);
void GFL_NET_ERR_RestoreDisplay(BOOL keepDark);
BOOL GFL_NET_ERR_IsActive(void);
void GFL_NET_ERR_LoadScreenGraphics(u32 screenIndex);
void GFL_NET_ERR_DrawWindow(u32 messageVariant, u32 useGenericMessage);

#endif
