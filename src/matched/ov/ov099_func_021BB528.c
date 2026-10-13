/*
 * function: WIFICLUB_DrawPartnerPanel
 * address: 0x021BB528
 * packet: pkt_ov099_021BB528
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declaring mon before kind and form restores their original spill-slot order.
 * symbols:
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   func_02009864 0x02009864 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   WIFICLUB_SetFriendNameWord 0x021C2370 thumb ov099
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_GetVisitorMessageId 0x021BB918 thumb ov099
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   WIFICLUB_DrawPhaseIcon 0x021BE4BC thumb ov099
 *   WIFICLUB_GetStatusModeFlag 0x021C285C thumb ov099
 *   WIFICLUB_DrawTileBlock 0x021BE3CC thumb ov099
 *   WIFICLUB_CreateTrainerActor 0x021BB374 thumb ov099
 *   WIFICLUB_CreateTouchBar 0x021BB460 thumb ov099
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
#include "../include/Obj07942.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void GF_FONT_SetDefaultTextColor(void);
typedef signed short   s16;
typedef unsigned int   u32;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Sub020097BCObj;
struct WordSet;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void WIFICLUB_SetFriendNameWord(char *,int);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_Print(void *,short,short,void *,void *);
extern int WIFICLUB_GetFriendStatus(int i);
extern unsigned WIFICLUB_GetStatusKind(char *,void *);
extern unsigned WIFICLUB_GetStatusPhase(char *,void *);
extern int WIFICLUB_GetVisitorMessageId(void *w, unsigned int idx, int *unused);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041B6C(unsigned);
extern void WIFICLUB_DrawPhaseIcon(char *p, int a, int b, int c, int d, unsigned int e, int f);
extern int WIFICLUB_GetStatusModeFlag(void *);
extern void WIFICLUB_DrawTileBlock(char *p, int a, u8 b, u8 c, u32 d, int e);
extern void WIFICLUB_CreateTrainerActor(char *,int,int);
extern void WIFICLUB_CreateTouchBar(char *,int);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
#define PTR(off) (*(void **)(p+(off)))
void WIFICLUB_DrawPartnerPanel(char *p,int v)
{
    int index;
    void *mon;
    unsigned kind,form;
    int unused;
    int message;
    GF_FONT_SetDefaultTextColor();
    index=((struct Obj07942 *)p)->f8ED-1;
    func_02009864(PTR(4),index,9);
    GF_FONT_SetTextColor(15,2,0);
    WIFICLUB_SetFriendNameWord(p,index);
    MSGDATA_ReadString(PTR(0xe0),33,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    PRINTSYS_Print(BMP_WIN_GetBmp(PTR(0x958)),25,0,PTR(0xf8),PTR(0xe8));
    mon=(void *)WIFICLUB_GetFriendStatus(index);
    kind=WIFICLUB_GetStatusKind(p,mon);
    form=WIFICLUB_GetStatusPhase(p,mon);
    message=WIFICLUB_GetVisitorMessageId((void *)kind,form,&unused);
    if(message>=141 && message<=144)message-=81;
    MSGDATA_ReadString(PTR(0xe0),message,PTR(0xf0));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(PTR(0x958)),96,0,PTR(0xf0),PTR(0xe8),0x3c40);
    MSGDATA_ReadString(PTR(0xe0),35,PTR(0xf8));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(PTR(0x95c)),104,0,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,2),4,1,1);
    MSGDATA_ReadString(PTR(0xe0),36,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(PTR(0x95c)),176,24,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,3),4,1,1);
    MSGDATA_ReadString(PTR(0xe0),37,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(PTR(0x95c)),176,40,PTR(0xf8),PTR(0xe8),0x3c40);
    MSGDATA_ReadString(PTR(0xe0),38,PTR(0xf8));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(PTR(0x95c)),104,64,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,4),4,1,1);
    MSGDATA_ReadString(PTR(0xe0),39,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(PTR(0x95c)),188,64,PTR(0xf8),PTR(0xe8),0x3c40);
    MSGDATA_ReadString(PTR(0xe0),42,PTR(0xf8));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(PTR(0x95c)),8,96,PTR(0xf8),PTR(0xe8),0x3c40);
    message=func_02009864(PTR(4),index,7);
    if(message){
        func_0201EFA4(PTR(0x8b0),2,message,2,0,1);
        func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,5),4,1,1);
        func_0201EFA4(PTR(0x8b0),1,func_02009864(PTR(4),index,6),2,0,1);
        MSGDATA_ReadString(PTR(0xe0),44,PTR(0xf0));
        func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(PTR(0x95c)),152,96,PTR(0xf8),PTR(0xe8),0x3c40);
    }
    BMP_WIN_MakeScreen(PTR(0x95c));
    BMP_WIN_TransferChars(PTR(0x95c));
    BMP_WIN_MakeScreen(PTR(0x958));
    BMP_WIN_TransferChars(PTR(0x958));
    func_02041B6C(7);
    WIFICLUB_DrawPhaseIcon(p+0x898,6,2,1,kind,form,32);
    WIFICLUB_DrawTileBlock(p+0x898,6,28,1,WIFICLUB_GetStatusModeFlag(mon)?47:43,0);
    WIFICLUB_CreateTrainerActor(p,index,v);
    WIFICLUB_CreateTouchBar(p,(u16)v);
    BG_SYS_SetSubPlaneVisible(16,1);
}
