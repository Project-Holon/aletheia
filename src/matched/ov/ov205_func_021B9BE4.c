/*
 * function: SAVE_SCREEN_NoticeMain
 * address: 0x021B9BE4
 * packet: pkt_ov205_021B9BE4
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   func_0208068C 0x0208068C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   func_02080B98 0x02080B98 arm
 *   SAVE_SCREEN_SetupNoticeBackground 0x021B9D58 thumb ov205
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   SAVE_SCREEN_PrintText 0x021B9DB8 thumb ov205
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   SAVE_SCREEN_DeleteNoticeBackground 0x021B9DAC thumb ov205
 */
#include "../include/Obj01293.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short   s16;
extern u32 KEY_GetTrg(void);
extern void func_0208068C(u32);
extern void MIi_CpuClearFast(u32,u32,u32);
extern void func_02080B98(void);
extern void SAVE_SCREEN_SetupNoticeBackground(u16);
typedef signed int     s32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct Rec;
struct WordSet;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void SAVE_SCREEN_PrintText(char *p, u32 index, s16 x, s16 y);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void BG_SYS_FreeLayerBuf(u32);
extern u32 GF_FONT_Delete(void *ptr);
extern void SAVE_SCREEN_DeleteNoticeBackground(void);
int SAVE_SCREEN_NoticeMain(void *input,u32 *state,u32 unused,char *p)
{
    u32 keys;
    void *obj;
    keys=KEY_GetTrg();
    switch(*state){
    case 0:
        func_0208068C(511);MIi_CpuClearFast(0,0x6800000,0xa4000);func_02080B98();
        SAVE_SCREEN_SetupNoticeBackground(((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->f18=GF_FONT_Create(23,0,0,0,((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->fC=func_02045B38(0,2,37,((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->f10=WORDSET_CreateDefault(((struct Obj01293 *)p)->f0);
        ((struct Obj01293 *)p)->f14=(void *)BMP_WIN_Create(0,2,7,27,15,13,1);
        if(((struct Obj01293 *)p)->f4==0)SAVE_SCREEN_PrintText(p,3,6,0);
        else SAVE_SCREEN_PrintText(p,2,6,0);
        obj=((struct Obj01293 *)p)->f14;
        BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);BG_SYS_PushTile(BMP_WIN_GetBgLayer(obj));
        GFL_NET_RestartWithDefaultTimeout(1,((struct Obj01293 *)p)->f0);BG_SYS_SetMainPlaneVisible(16,1);
        (*state)++;break;
    case 1:
        FADE_Start(3,16,0,0);*(u16 *)0x04000050=0;
        (*state)++;break;
    case 2:
        if(!FADE_IsActive())(*state)++;
        break;
    case 3:
        if((keys&1)||(keys&2)){FADE_Start(3,0,16,0);(*state)++;}
        break;
    case 4:
        if(!FADE_IsActive()){BMP_Clear(BMP_WIN_GetBmp(((struct Obj01293 *)p)->f14),0);(*state)++;}
        break;
    case 5:
        BMP_MENUWORK_DrawWindowBorder(((struct Obj01293 *)p)->f14,0);BMP_WIN_Delete(((struct Obj01293 *)p)->f14);
        WORDSET_DeleteStrbufED04(((struct Obj01293 *)p)->f10);MSGDATA_Delete(((struct Obj01293 *)p)->fC);
        BG_SYS_FreeLayerBuf(0);GF_FONT_Delete(((struct Obj01293 *)p)->f18);SAVE_SCREEN_DeleteNoticeBackground();return 1;
    }
    return 0;
}
