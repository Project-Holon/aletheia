/*
 * function: POKETRADE_PROC_PollGridTouchDrag
 * address: 0x021D9F24
 * packet: pkt_ov119_021D9F24
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * initialization: 02035D20 forwards to 02035CD8, which stores both
 * coordinate outputs before returning 1. Full original 021E51A4 stores
 * all five nonnull outputs before returning the hit object; zero exits
 * precede their reads here. Stack words at 9F4A/9F4C are c's address;
 * 9F42/9F46 are a/b. All payloads and object fields stay full-width.
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   POKETRADE_2D_HitTestBoxIcons 0x021E51A4 thumb ov119
 *   POKETRADE_PROC_LoadSlotMonAlt 0x021D8DD0 thumb ov119
 *   POKETRADE_PROC_IsTradeTargetValid 0x021DBD70 thumb ov119
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepClearPeerSelection 0x021DB9B4 thumb ov119
 *   POKETRADE_NEGO_StepSendOfferRemoval 0x021DF708 thumb ov119
 *   POKETRADE_PROC_ShowDragIcon 0x021D8C84 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   POKETRADE_PROC_CanTradeMon 0x021DD0CC thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowAtPos 0x021E0FF4 thumb ov119
 *   POKETRADE_PROC_StepWaitKeyAfterMessage 0x021DA064 thumb ov119
 *   POKETRADE_PROC_BeginDrag 0x021D8CCC thumb ov119
 *   POKETRADE_PROC_SetDragTarget 0x021D9EA8 thumb ov119
 *   POKETRADE_PROC_RequestBoxRedraw 0x021D8B38 thumb ov119
 */
typedef unsigned int   u32;
struct MsgBank;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int POKETRADE_2D_HitTestBoxIcons(char *p, int x, int y, int *outA, int *outB, int *outSlot, int *outColumn, int *outRow);
extern void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p);
extern int POKETRADE_PROC_IsTradeTargetValid(char *,int,int);
extern int POKETRADE_PROC_IsHostSide(void *);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int POKETRADE_PROC_CanTradeMon(char *,int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepClearPeerSelection(char *p);
extern void POKETRADE_NEGO_StepSendOfferRemoval(void *p);
extern void POKETRADE_PROC_ShowDragIcon(void *);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowAtPos(void *p, int a, int flag);
extern void POKETRADE_PROC_StepWaitKeyAfterMessage(char *p);
extern void POKETRADE_PROC_BeginDrag(void *,int,int,int,int);
extern void POKETRADE_PROC_SetDragTarget(char *,int,int);
extern void POKETRADE_PROC_RequestBoxRedraw(char *p);
#define I(o) (*(int *)(p+(o)))
int POKETRADE_PROC_PollGridTouchDrag(char *p,int save)
{
 int x,y,a,b,c,hit,e,result=0;
 if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))==1) {
  hit=POKETRADE_2D_HitTestBoxIcons(p,x+12,y+12,(int *)(p+0xf80),(int *)(p+0xf7c),&a,&b,&c);
  if(hit) {
   e=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)I(0x828),I(0xf80),I(0xf7c),p);
   if(POKETRADE_PROC_IsTradeTargetValid(p,I(0xf80),I(0xf7c))) {
    GFL_USE_PlaySeDefaultVolume(0x626);
    if(!POKETRADE_PROC_IsHostSide(p)) {POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepClearPeerSelection);return 3;}
    I(0xf98)=I(0xf80);I(0xf94)=I(0xf7c);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendOfferRemoval);return 3;
   }
   POKETRADE_PROC_ShowDragIcon(p);
   if(e && func_02017E88((void *)e,0xa9,0)) {
    if(POKETRADE_PROC_CanTradeMon(p,e)) {
     MSGDATA_ReadString((struct MsgBank *)I(0x720),0x8e,(void *)I(0x738));POKETRADE_SAVE_OpenMessageWindowAtPos(p,1,0);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitKeyAfterMessage);return 2;
    }
    POKETRADE_PROC_BeginDrag(p,hit,c,b,e);POKETRADE_PROC_SetDragTarget(p,a,b);
    if(save) {I(0xf98)=I(0xf80);I(0xf94)=I(0xf7c);}
    POKETRADE_PROC_RequestBoxRedraw(p);result=1;
   }
  }
 }
 return result;
}
