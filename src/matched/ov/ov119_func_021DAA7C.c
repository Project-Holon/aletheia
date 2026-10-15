/*
 * function: POKETRADE_PROC_StepSendTradeData
 * address: 0x021DAA7C
 * packet: pkt_ov119_021DAA7C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_3D_UploadCubeTextures 0x021E31FC thumb ov119
 *   POKETRADE_PROC_StepWaitSyncThenWipe 0x021DAA4C thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_PROC_SetStep(void *,int),POKETRADE_3D_UploadCubeTextures(void *),POKETRADE_PROC_StepWaitSyncThenWipe(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);
void POKETRADE_PROC_StepSendTradeData(char *p) {
 if(POKETRADE_PROC_IsNetSession(p)) {
  if(GFL_NET_SendData((unsigned)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0e,0x2d6,(u32)(p+16),0,0,1)) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,8);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitSyncThenWipe);
  }
 } else {POKETRADE_3D_UploadCubeTextures(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitSyncThenWipe);}
}
