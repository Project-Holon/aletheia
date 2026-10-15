/*
 * function: DUP_FITTING_Main
 * address: 0x021B63BC
 * packet: pkt_ov133_021B63BC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: both display updates belong inside the counter reset guard; byte counter is +18c1, flag word +18d0. Correct pointer base +187c and descriptor +18ec; typed sentinel/window fields prevent raw-offset CSE.
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   DUP_FITTING_EnterPoseMode 0x021B9818 thumb ov133
 *   DUP_FITTING_UpdateSubMode 0x021B8A30 thumb ov133
 *   DUP_FITTING_UpdatePose 0x021B98A0 thumb ov133
 *   DUP_FITTING_UpdateIdle 0x021B75E0 thumb ov133
 *   DUP_FITTING_SetText 0x021B9C08 thumb ov133
 *   DUP_FITTING_DrawFrames 0x021B918C thumb ov133
 *   DUP_FITTING_HandleTouch 0x021B940C thumb ov133
 *   DUP_FITTING_DrawBackActors 0x021B9784 thumb ov133
 *   MUS_COMM_FUNC_SetTimingSync 0x021FCDEC thumb ov132
 *   MUS_COMM_FUNC_CheckTimingSync 0x021FCE00 thumb ov132
 *   STA_NET_IsTransferDone 0x021FD6A4 thumb ov132
 *   DUP_FITTING_UpdateActorTimers 0x021B9F5C thumb ov133
 *   DUP_FITTING_DrawElems 0x021B8C6C thumb ov133
 *   MUSICAL_MCSS_TickAnim 0x021F51E8 thumb ov112
 *   MUSICAL_MCSS_DrawRenderObj 0x021F51F4 thumb ov112
 *   MUSICAL_MCSS_UpdateObject 0x021F4990 thumb ov112
 *   CLACT_DrawSystem 0x0204A600 arm
 *   func_02047964 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   BG_SYS_ClearLayer 0x0204152C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   DUP_FITTING_SetTextMon 0x021B9C90 thumb ov133
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   DUP_FITTING_ITEM_NoOp 0x021BA0C8 thumb ov133
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   func_0204989C 0x0204989C arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   DUP_FITTING_ITEM_ElemGetData 0x021BA20C thumb ov133
 *   DUP_FITTING_SetTextItem 0x021B9CBC thumb ov133
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 prefix[0x18c1]; u8 counter; u16 timer,pad18c4; u8 brightness,pad; u32 mode,busy,flag; u16 sentinel; u8 pad18d6[0x16]; u32 window; } Context;
#define W(k) (*(u32 *)((u8 *)p+(k)))
#define H(k) (*(u16 *)((u8 *)p+(k)))
#define B(k) (*(u8 *)((u8 *)p+(k)))
#define P(k) (*(u8 **)((u8 *)p+(k)))
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_FadeOutBgm(u32);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void DUP_FITTING_EnterPoseMode(u8 *),DUP_FITTING_UpdateSubMode(u8 *),DUP_FITTING_UpdatePose(u8 *),DUP_FITTING_UpdateIdle(u8 *);
extern void DUP_FITTING_SetText(u8 *,u32,void *),DUP_FITTING_DrawFrames(u8 *),DUP_FITTING_DrawBackActors(u8 *);
extern int DUP_FITTING_HandleTouch(u8 *);
extern void MUS_COMM_FUNC_SetTimingSync(int,int);
struct Board;
struct Camera;
struct Cfg;
struct Descriptor;
struct Lights;
struct O;
struct PrintSys;
extern int MUS_COMM_FUNC_CheckTimingSync(char *p, int id);
extern int STA_NET_IsTransferDone(char *p);
extern void DUP_FITTING_UpdateActorTimers(u8 *);
extern void DUP_FITTING_DrawElems(struct O *p);
extern void MUSICAL_MCSS_TickAnim(u8 *);
extern void MUSICAL_MCSS_DrawRenderObj(void **p);
extern void MUSICAL_MCSS_UpdateObject(void *);
extern void CLACT_DrawSystem(void),func_02047964(void),G3D_SYSTEM_ApplyLookAt(void),G3D_SYSTEM_DrawEnd(void);
extern void BILLBOARD_Draw(struct Board *b, struct Camera *cam, struct Lights *lights);
extern void BG_SYS_ResetSlot(u32,u32,u32);
extern void BG_SYS_ClearLayer(int,u16);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void DUP_FITTING_SetTextMon(u8 *),BMP_MENUWORK_DrawWindow(void *,int,int,int),DUP_FITTING_ITEM_NoOp(u8 *,u8);
extern void BG_SYS_SetVisibleLayer(int,u16),func_0204989C(u32,u32,u32,u32,u32,u32,u16),func_02041B6C(u32);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
struct Descriptor;
extern u32 DUP_FITTING_ITEM_ElemGetData(u8 *p);
extern void DUP_FITTING_SetTextItem(u8 *,u8 *);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u32 func_0200FB24(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
static inline void brightness(u8 *value)
{
    BG_SYS_ResetSlot(6,0,128-*value);
    BG_SYS_ResetSlot(5,0,*value-128);
}
int DUP_FITTING_Main(Context *p)
{
    void *desc;
    switch(W(0x0c)) {
    case 7:
        GFL_USE_PlaySeDefaultVolume(1358); W(0x0c)=8;
    case 8:
        if(WIPE_SYS_EndCheck()==1) {
            if(W(0x1840)==1) DUP_FITTING_EnterPoseMode((u8 *)p);
            else W(0x0c)=1;
        }
        if(W(0x98)==1) DUP_FITTING_UpdateSubMode((u8 *)p);
        break;
    case 9:
        if(WIPE_SYS_EndCheck()==1 && GFL_USE_IsBgmFading()==0) return 2;
        break;
    case 0: DUP_FITTING_UpdatePose((u8 *)p); break;
    case 1: DUP_FITTING_UpdateIdle((u8 *)p); break;
    case 2:
        W(0x10)+=6;
        if((int)W(0x10)>=192) {
            DUP_FITTING_SetText((u8 *)p,1,0); W(0x10)=192; W(0x0c)=3;
            H(0x1838)=0; H(0x183a)=0; H(0x18c4)=0;
        }
        DUP_FITTING_DrawFrames((u8 *)p); break;
    case 6:
        W(0x10)-=6;
        if((int)W(0x10)<0) { W(0x10)=0; W(0x0c)=1; }
        DUP_FITTING_DrawFrames((u8 *)p); break;
    case 3:
        if(DUP_FITTING_HandleTouch((u8 *)p)==2) { W(0x0c)=10; B(0x18c0)=0; CLACT_SetActorDrawEnable((struct Obj *)P(0x18b0),1); }
        break;
    case 10:
        B(0x18c0)++; DUP_FITTING_DrawBackActors((u8 *)p);
        if(B(0x18c0)>60) {
            if(*(u32 *)P(4)==0) {
                WIPE_SYS_Start(0,0,0,0x7fff,18,1,H(0)); GFL_USE_FadeOutBgm(60); W(0x0c)=9; p->mode=1;
            } else {
                DUP_FITTING_SetText((u8 *)p,2,0); MUS_COMM_FUNC_SetTimingSync(*(int *)P(4),69); W(0x0c)=4;
            }
        }
        break;
    case 4:
        if(MUS_COMM_FUNC_CheckTimingSync(*(void **)P(4),69)==1) W(0x0c)=5;
        break;
    case 5:
        if(STA_NET_IsTransferDone(*(void **)P(4))==1) {
            WIPE_SYS_Start(0,0,0,0x7fff,18,1,H(0)); GFL_USE_FadeOutBgm(60); W(0x0c)=9; p->mode=1;
        }
        break;
    }
    DUP_FITTING_UpdateActorTimers((u8 *)p); DUP_FITTING_DrawElems((struct O *)p); MUSICAL_MCSS_TickAnim(P(0x187c));
    MUSICAL_MCSS_UpdateObject(P(0x1884)); CLACT_DrawSystem(); func_02047964(); G3D_SYSTEM_ApplyLookAt();
    MUSICAL_MCSS_DrawRenderObj((void **)P(0x187c)); BILLBOARD_Draw((struct Board *)P(0x188c),(struct Camera *)P(0x1888),0); G3D_SYSTEM_DrawEnd();
    p->counter++;
    if(p->counter>1) {
        p->counter=0;
        BG_SYS_ResetSlot(3,1,1); BG_SYS_ResetSlot(3,5,1);
    }
    if(p->mode==0) {
        if(p->brightness<128) { p->brightness+=8; brightness(&p->brightness); }
        else if(p->flag==0) {
            p->flag=1; BG_SYS_ClearLayer(7,0);
            p->window=BMP_WIN_Create(7,1,19,30,4,14,1);
            if(W(0x1840)==0) DUP_FITTING_SetTextMon((u8 *)p); else DUP_FITTING_SetText((u8 *)p,6,0);
            BMP_MENUWORK_DrawWindow((u8 *)p->window,1,128,12);
        }
    } else {
        if(p->flag==1) {
            DUP_FITTING_ITEM_NoOp((u8 *)p,2); p->flag=0;
            BG_SYS_SetVisibleLayer(7,3); BG_SYS_SetVisibleLayer(4,0); BG_SYS_SetVisibleLayer(5,1); BG_SYS_SetVisibleLayer(6,2);
            DUP_FITTING_ITEM_NoOp((u8 *)p,4); func_0204989C(46,13,7,0,0,0,H(0)); func_02041B6C(7);
            p->busy=0; PRINTSYS_QUE_Clear((struct PrintSys *)P(0x18e8)); BMP_WIN_Delete((struct Descriptor *)p->window); p->window=0; DUP_FITTING_ITEM_NoOp((u8 *)p,6);
        } else if(p->brightness!=0) {
            DUP_FITTING_ITEM_NoOp((u8 *)p,p->brightness+96); p->brightness-=8; brightness(&p->brightness);
        }
    }
    DUP_FITTING_ITEM_NoOp((u8 *)p,8);
    if(p->busy==0 && W(0x0c)==1) {
        if(P(0x38)!=0 && p->sentinel!=*(u16 *)DUP_FITTING_ITEM_ElemGetData(P(0x38))) {
            DUP_FITTING_SetTextItem((u8 *)p,P(0x38)); p->sentinel=*(u16 *)DUP_FITTING_ITEM_ElemGetData(P(0x38));
        } else if(p->sentinel!=255 && P(0x38)==0) { DUP_FITTING_SetTextMon((u8 *)p); p->sentinel=255; }
    }
    DUP_FITTING_ITEM_NoOp((u8 *)p,10);
    if(p->busy==1 && PRINTSYS_QUE_IsFinished((const struct PrintSys *)P(0x18e8))==1) {
        p->busy=0; desc=(u8 *)p->window;
        BMP_WIN_TransferChars(desc); BMP_WIN_MakeScreen(desc); func_02041B6C(BMP_WIN_GetBgLayer(desc));
        BG_SYS_SetVisibleLayer(4,1); BG_SYS_SetVisibleLayer(5,2); BG_SYS_SetVisibleLayer(6,3); BG_SYS_SetVisibleLayer(7,0);
    }
    DUP_FITTING_ITEM_NoOp((u8 *)p,12);
    if(P(0x18e8)!=0) PRINTSYS_QUE_Main((struct PrintSys *)P(0x18e8));
    DUP_FITTING_ITEM_NoOp((u8 *)p,14);
    if(H(0x18c2)!=0) H(0x18c2)--;
    if(*(u32 *)P(4)!=0 && W(0x0c)!=7 && W(0x0c)!=8 && W(0x0c)!=9) {
        DUP_FITTING_ITEM_NoOp((u8 *)p,32);
        if(func_0200FB24()!=0) {
            DUP_FITTING_ITEM_NoOp((u8 *)p,34); WIPE_SYS_Start(0,0,0,0x7fff,18,1,H(0)); GFL_USE_FadeOutBgm(60);
            DUP_FITTING_ITEM_NoOp((u8 *)p,36); W(0x0c)=9; DUP_FITTING_ITEM_NoOp((u8 *)p,38);
        } else DUP_FITTING_ITEM_NoOp((u8 *)p,64);
    }
    DUP_FITTING_ITEM_NoOp((u8 *)p,16);
    return 0;
}
