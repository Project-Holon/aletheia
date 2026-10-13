/*
 * file:     cg_help.c
 * unit:     yes
 * function: func_021D4240, func_021D4280, func_021D42A0, func_021D43F0, func_021D43F8, func_021D4504, func_021D4534, func_021D4558, func_021D4698, func_021D46BC, func_021D485C, func_021D48A4, func_021D4940, func_021D49C8, func_021D4B14, func_021D4B84
 * address:  0x021D4240
 * region:   ov124
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_02030EAC 0x02030EAC arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_02041B6C 0x02041B6C arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02040618 0x02040618 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0207D63C 0x0207D63C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021D4CC4 0x021D4CC4 data a4
 *   d_021D4BF4 0x021D4BF4 data a4
 *   d_021D4C44 0x021D4C44 data a4
 *   d_021D4C64 0x021D4C64 data a4
 *   d_021D4C84 0x021D4C84 data a4
 *   d_021D4C24 0x021D4C24 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_02049F78 0x02049F78 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   func_020307B0 0x020307B0 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   d_021D4BE4 0x021D4BE4 data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   func_02012204 0x02012204 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_02030734 0x02030734 arm
 *   func_02041090 0x02041090 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   d_021D4CF4 0x021D4CF4 data a4
 *   d_021D4CA4 0x021D4CA4 data a4
 *   d_021D4D4C 0x021D4D4C data a1
 *   d_021D4C04 0x021D4C04 data a4
 *   d_021D4BE0 0x021D4BE0 data a2
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   KEY_GetCont 0x0203630C arm
 *   func_0200854C 0x0200854C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   WIPE_ResetWndMask  0x02022224  thumb  arm9
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb  arm9
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb  arm9
 *   APP_TASKMENU_WIN_ResetDecide  0x020282A4  thumb  arm9
 *   APP_TASKMENU_WIN_ClearScreen  0x0202843C  thumb  arm9
 *   APP_TASKMENU_WIN_TransChar  0x02028454  thumb  arm9
 *   MYSTATUS_Create  0x0200846C  thumb  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb  arm9
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb  arm9
 */
#include "../../matched/include/Obj00068.h"
#include "../../matched/include/Obj00991.h"
#include "../../matched/include/Obj00122.h"
#include "../../matched/include/Obj22992.h"
#include "../../matched/include/Obj22993.h"

struct Node;
struct Descriptor;
struct Obj;
struct PrintSys;
struct Cfg;
struct DispConfig;
struct DispVram;
struct BgTemplate;
struct Bank;
struct Sub0200852CObj;
struct CharBuf;
struct GfFont;
struct MsgBank;
struct R;
struct U16Vec;
struct Rec;
struct TaskMenuState;
struct Ctx;
struct Vec2;
struct Obj0203159C;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 a, b; u8 c, d, e, f; u32 g; u16 h, i, j, k, l, m; } Config;

typedef struct { u16 x, y, z; u8 a, b; } Request_021D4240;

typedef signed int     s32;

typedef struct { u32 text; u16 color; u16 pad; u32 flag; } Request_021D4698;

typedef struct { u8 bytes[16]; } Table16;

typedef short s16;

typedef struct { s16 x, y; } Vec;

extern void *func_020056A0(void *,void *,int);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned,unsigned);
extern void func_02030EAC(struct Node *);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern u32 KEY_GetTrg(void);
extern void func_02041B6C(u32 bit);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void CLACT_DrawSystem(void);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
extern void APP_TASKMENU_WIN_ClearScreen(u8 *p);
extern void APP_TASKMENU_WIN_TransChar(u8 *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_ResetSubDisplay(void), BG_SYS_ClearMainPlanes(void), BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32, u32);
extern u32 WIPE_ResetWndMask(void *);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203F8F4(u16), BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_020403F4(u32);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(u32);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u32 func_020307B0(void *p);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern u8 func_0201F548(int);
extern void func_0201DD68(void);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_0201F73C(void *, int, int, int);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 APP_TASKMENU_WIN_Create(u32, u32, u32, u32, u8, u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern unsigned int APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u32 func_02012204(const struct Ctx *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int func_02061CA4(void *, u32, u32, int);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *MYSTATUS_Create(int a0);
extern unsigned int KEY_GetCont(void);
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
void func_021D4240(char *p);
void func_021D4280(char *p);
int func_021D42A0(char *p);
void func_021D43F0(void);
void func_021D43F8(char *p);
void func_021D4504(char *p);
void func_021D4534(const struct BgTemplate *p, int layer, int type);
void func_021D4558(char *p);
void func_021D4698(char *p);
void func_021D46BC(char *p);
void func_021D485C(char *p);
void func_021D48A4(char *p);
void func_021D4940(char *p,int n);
void func_021D49C8(char *p, u32 n);
int func_021D4B14(void *a,int b,void *c);
int func_021D4B84(struct S020315D4 *task,int b,int keep,char *p);
extern const Config gClActorInitParam;
extern const u32 d_021D4CC4[], d_021D4BF4[], d_021D4C44[], d_021D4C64[], d_021D4C84[], d_021D4C24[];
extern const Table16 d_021D4BE4;
extern const u32 d_021D4CF4[], d_021D4CA4[], d_021D4C04[];
extern const char d_021D4D4C[];
extern const Vec d_021D4BE0;



void func_021D4240(char *p)
{
    ((struct Obj00068 *)p)->f10 = 0;
    func_021D43F8(p);
    func_021D4558(p);
    func_021D46BC(p);
    ((struct Obj00068 *)p)->f14 = func_020056A0(func_021D43F0,p,8);
    ((struct Obj00068 *)p)->f18 = 0;
    ((struct Obj00068 *)p)->fC = 1;
    func_021D4940(p,((struct Obj00068 *)p)->f18);
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj00068 *)p)->f0);
}



void func_021D4280(char *p) {func_02030EAC(*(struct Node * *)&((struct Obj00991 *)p)->f14);func_021D485C(p);func_021D4698(p);func_021D4504(p);}



/*
 * extent: existing follower 021D43F0 remains in its separately verified file.
 */
int func_021D42A0(char *p)
{
    switch(((struct Obj00122 *)p)->f10) {
    case 0:
        WIPE_SYS_Start((void *)4,1,1,0,6,1,((struct Obj00122 *)p)->f0);
        ((struct Obj00122 *)p)->f10=1;
        break;
    case 1:
        if(WIPE_SYS_EndCheck()==1) ((struct Obj00122 *)p)->f10=4;
        break;
    case 2:
        if(APP_TASKMENU_WIN_IsFinish(((struct Obj00122 *)p)->f40)==1) {
            WIPE_SYS_Start((void *)4,0,0,0,6,1,((struct Obj00122 *)p)->f0);
            ((struct Obj00122 *)p)->f10=3;
        }
        break;
    case 3:
        if(WIPE_SYS_EndCheck()==1) return 1;
        break;
    case 4:
        if(!((struct Obj00122 *)p)->f1C) func_021D48A4(p);
        if(KEY_GetTrg()&4) func_02041B6C(4);
        break;
    }
    PRINTSYS_QUE_Main(((struct Obj00122 *)p)->f30);
    CLACT_DrawSystem();
    if(((struct Obj00122 *)p)->f3C) APP_TASKMENU_WIN_Update(((struct Obj00122 *)p)->f3C);
    if(((struct Obj00122 *)p)->f38) APP_TASKMENU_WIN_Update(((struct Obj00122 *)p)->f38);
    APP_TASKMENU_WIN_Update(((struct Obj00122 *)p)->f40);
    if(((struct Obj00122 *)p)->f1C==1 && PRINTSYS_QUE_IsFinished(((struct Obj00122 *)p)->f30)==1 &&
       (APP_TASKMENU_WIN_IsFinish(((struct Obj00122 *)p)->f3C)==1 || APP_TASKMENU_WIN_IsFinish(((struct Obj00122 *)p)->f38)==1 || ((struct Obj00122 *)p)->fC==1)) {
        BMP_WIN_TransferChars(((struct Obj00122 *)p)->f20);
        BMP_WIN_TransferChars(((struct Obj00122 *)p)->f24);
        ((struct Obj00122 *)p)->f1C=0;
        ((struct Obj00122 *)p)->fC=0;
        func_021D49C8(p,((struct Obj00122 *)p)->f18);
        if(((struct Obj00122 *)p)->f18==11) {
            APP_TASKMENU_WIN_ResetDecide(((struct Obj00122 *)p)->f3C);
            APP_TASKMENU_WIN_ClearScreen(((struct Obj00122 *)p)->f3C);
        } else {
            APP_TASKMENU_WIN_TransChar(((struct Obj00122 *)p)->f3C);
            APP_TASKMENU_WIN_ResetDecide(((struct Obj00122 *)p)->f3C);
        }
        if(((struct Obj00122 *)p)->f18==0) {
            APP_TASKMENU_WIN_ResetDecide(((struct Obj00122 *)p)->f38);
            APP_TASKMENU_WIN_ClearScreen(((struct Obj00122 *)p)->f38);
        } else {
            APP_TASKMENU_WIN_TransChar(((struct Obj00122 *)p)->f38);
            APP_TASKMENU_WIN_ResetDecide(((struct Obj00122 *)p)->f38);
        }
    }
    func_02040618(7,5,1);
    return 0;
}



/*
 * extent: 8-byte tail stub; labelled function 021D43F8 follows.
 */
void func_021D43F0(void)
{
    CLACT_VBlankSystem();
}



static inline void visible(int plane)
{
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x1f00) | (plane << 8);
}



static inline void subvisible(int plane)
{
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0x1f00) | (plane << 8);
}



/*
 * volatile: display read-modify-writes 021D440E/021D4416, 021D4418/021D441C; POWCNT1 021D443E/021D4444.
 */
void func_021D43F8(char *p)
{
    Config cfg;
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    visible(0);
    subvisible(0);
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)d_021D4CC4);
    func_0203F8F4(((struct Obj00068 *)p)->f0);
    BMP_WIN_Init(((struct Obj00068 *)p)->f0);
    func_0203FC28((struct DispConfig *)d_021D4BF4);
    func_021D4534((const struct BgTemplate *)d_021D4C44, 4, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C64, 5, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C84, 6, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C24, 7, 0);
    func_0207D63C(0x04001050, 4, 8, 15, 4);
    cfg = gClActorInitParam;
    cfg.h = 0x40;
    CLACT_InitSystem((const struct Cfg *)(&cfg), (u32)d_021D4CC4, ((struct Obj00068 *)p)->f0);
    ((struct Obj00068 *)p)->f4C = CLACT_CreateUnit(0x30, 0, ((struct Obj00068 *)p)->f0);
    CLACT_SetUnitDefaultRenderer(((struct Obj00068 *)p)->f4C);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}



void func_021D4504(char *p) {CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj00991 *)p)->f4C);CLACT_ExitSystem();func_020403F4(4);func_020403F4(5);func_020403F4(6);func_020403F4(7);BMP_WIN_Exit();func_0203F9B4();}



/* 020414AC's legacy asm prototype says void, but its body forwards entry r0. */
void func_021D4534(const struct BgTemplate *p, int layer, int type) {func_0203FCA0(layer,p,type);func_02040588(layer,1);func_020414AC(layer);func_020409B4(layer);}



void func_021D4558(char *p)
{
    u32 handle;
    Request_021D4240 req;
    handle = (u32)func_020490F4((u32)((void *)0x1d), ((struct Obj00068 *)p)->f0);
    func_02049B68((void *)handle, 1, 4, 0, 0, ((struct Obj00068 *)p)->f0);
    func_02049658((void *)handle, 4, 6, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_020498F4((void *)handle, 10, 6, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_02049658((void *)handle, 4, 7, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_020498F4((void *)handle, 9, 7, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    ARC_TOOL_DeleteHandle(handle);
    handle = (u32)func_020490F4((u32)((void *)0x1e), ((struct Obj00068 *)p)->f0);
    if (func_02008550(**(void ** *)&((struct Obj00068 *)p)->f4) == 0)
        ((struct Obj00068 *)p)->f50 = CLACT_RegisterPaletteEx((void *)handle, 19, 1, 0, 0, 15, ((struct Obj00068 *)p)->f0);
    else
        ((struct Obj00068 *)p)->f50 = CLACT_RegisterPaletteEx((void *)handle, 12, 1, 0, 0, 15, ((struct Obj00068 *)p)->f0);
    *(int *)&((struct Obj00068 *)p)->f54 = CLACT_RegisterCharacter((void *)handle, 22, 0, 1, ((struct Obj00068 *)p)->f0);
    *(int *)&((struct Obj00068 *)p)->f58 = CLACT_RegisterCellAnim((void *)handle, 21, 20, ((struct Obj00068 *)p)->f0);
    func_02049658((void *)handle, 0, 4, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    ((struct Obj00068 *)p)->f44 = func_02049F78((void *)handle, 13, (u32)(p + 0x48), ((struct Obj00068 *)p)->f0);
    ARC_TOOL_DeleteHandle(handle);
    req.x = 32;
    req.y = 48;
    req.z = 0;
    req.a = 0;
    req.b = 0;
    ((struct Obj00068 *)p)->f5C = CLACT_CreateActor(((struct Obj00068 *)p)->f4C, *(u32 *)&((struct Obj00068 *)p)->f50, ((struct Obj00068 *)p)->f54, ((struct Obj00068 *)p)->f58, &req, 1, ((struct Obj00068 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj00068 *)p)->f5C, 0);
    CLACT_SetActorAutoAnim(((struct Obj00068 *)p)->f5C, 1);
}



void func_021D4698(char *p) {func_020307B0(((struct Obj00991 *)p)->f44);CLACT_DeleteActor(*(struct Obj * *)&((struct Obj00991 *)p)->f5C);CLACT_ReleasePalette(((struct Obj00991 *)p)->f50);CLACT_ReleaseCharacter(((struct Obj00991 *)p)->f54);CLACT_ReleaseCellAnim(((struct Obj00991 *)p)->f58);}



void func_021D46BC(char *p)
{
    Request_021D4698 req;
    ((struct Obj00068 *)p)->f28 = GF_FONT_Create(23, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    GF_FONT_SetTextColor(15, 2, 0);
    ((struct Obj00068 *)p)->f2C = func_02045B38(0, 2, 21, ((struct Obj00068 *)p)->f0);
    func_02049B40(23, 5, 4, 480, 32, ((struct Obj00068 *)p)->f0);
    func_0201F5BC(5, 1, 13, 0, ((struct Obj00068 *)p)->f0);
    func_02049B40(5, func_0201F548(0), 4, 416, 64, ((struct Obj00068 *)p)->f0);
    func_0201DD68();
    *(u32 *)&((struct Obj00068 *)p)->f30 = PRINTSYS_QUE_Create((void *)(u32)((struct Obj00068 *)p)->f0);
    ((struct Obj00068 *)p)->f34 = APP_TASKMENU_RES_Create(4, 11, *(u32 *)&((struct Obj00068 *)p)->f28, *(u32 *)&((struct Obj00068 *)p)->f30, ((struct Obj00068 *)p)->f0);
    *(u32 *)&((struct Obj00068 *)p)->f24 = BMP_WIN_Create(5, 2, 4, 28, 4, 15, 1);
    *(u32 *)&((struct Obj00068 *)p)->f20 = BMP_WIN_Create(5, 2, 9, 28, 12, 15, 1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00068 *)p)->f24), 1);
    BMP_WIN_TransferChars((struct Descriptor *)*(u32 *)&((struct Obj00068 *)p)->f24);
    BMP_WIN_MakeScreen((struct Cfg *)(*(u32 *)&((struct Obj00068 *)p)->f24));
    func_0201F73C(((struct Obj00068 *)p)->f24, 1, 1, 14);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00068 *)p)->f20), 0);
    BMP_WIN_TransferChars((struct Descriptor *)*(u32 *)&((struct Obj00068 *)p)->f20);
    BMP_WIN_MakeScreen((struct Cfg *)(*(u32 *)&((struct Obj00068 *)p)->f20));
    func_020409B4(5);
    func_020409B4(4);
    ((struct Obj00068 *)p)->f1C = 0;
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 24);
    req.color = 0x39e3;
    req.flag = 0;
    ((struct Obj00068 *)p)->f3C = APP_TASKMENU_WIN_Create(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 11, 21, 11, ((struct Obj00068 *)p)->f0);
    STRBUF_Delete((void *)req.text);
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 26);
    *(u32 *)&((struct Obj00068 *)p)->f38 = APP_TASKMENU_WIN_Create(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 0, 21, 11, ((struct Obj00068 *)p)->f0);
    STRBUF_Delete((void *)req.text);
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 25);
    req.flag = 1;
    ((struct Obj00068 *)p)->f40 = APP_TASKMENU_WIN_Create(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 22, 21, 10, ((struct Obj00068 *)p)->f0);
    STRBUF_Delete((void *)req.text);
    APP_TASKMENU_WIN_ClearScreen(*(u8 * *)&((struct Obj00068 *)p)->f38);
    *(u16 *)0x050005e2 = 0;
}



void func_021D485C(char *p)
{
    if (((struct Obj00991 *)p)->f3C) APP_TASKMENU_WIN_Delete(((struct Obj00991 *)p)->f3C);
    if (((struct Obj00991 *)p)->f38) APP_TASKMENU_WIN_Delete(((struct Obj00991 *)p)->f38);
    APP_TASKMENU_WIN_Delete(((struct Obj00991 *)p)->f40);
    APP_TASKMENU_RES_Delete(((struct Obj00991 *)p)->f34);
    PRINTSYS_QUE_Delete(((struct Obj00991 *)p)->f30);
    BMP_WIN_Delete(((struct Obj00991 *)p)->f20);
    BMP_WIN_Delete(((struct Obj00991 *)p)->f24);
    MSGDATA_Delete(((struct Obj00991 *)p)->f2C);
    GF_FONT_Delete(((struct Obj00991 *)p)->f28);
    func_0201DD68();
}



void func_021D48A4(char *p)
{
    Table16 table;
    table = d_021D4BE4;
    switch (TOUCHPANEL_HitTrg(&table)) {
    case 0:
        if (((struct Obj00122 *)p)->f18 != 0) {
            (((struct Obj00122 *)p)->f18)--;
            func_021D4940(p,((struct Obj00122 *)p)->f18);
            APP_TASKMENU_WIN_SetDecide(((struct Obj00122 *)p)->f38,1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
        }
        break;
    case 1:
        if (((struct Obj00122 *)p)->f18 < 11) {
            (((struct Obj00122 *)p)->f18)++;
            func_021D4940(p,((struct Obj00122 *)p)->f18);
            APP_TASKMENU_WIN_SetDecide(((struct Obj00122 *)p)->f3C,1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
        }
        break;
    case 2:
        APP_TASKMENU_WIN_SetDecide(((struct Obj00122 *)p)->f40,1);
        *(int *)&((struct Obj00122 *)p)->f10 = 2;
        GFL_USE_PlaySeDefaultVolume(0x551);
        break;
    }
    if (func_02012204(((struct Obj22992 *)(*(char * *)&((struct Obj00122 *)p)->f4))->f4) == 1) {
        APP_TASKMENU_WIN_SetDecide(((struct Obj00122 *)p)->f40,1);
        *(int *)&((struct Obj00122 *)p)->f10 = 2;
    }
}



void func_021D4940(char *p,int n)
{
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00068 *)p)->f24),1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00068 *)p)->f20),0);
    q = func_02045EC0(((struct Obj00068 *)p)->f2C,n);
    PRINTSYS_PrintQueColor(((struct Obj00068 *)p)->f30,(u32)BMP_WIN_GetBmp(((struct Obj00068 *)p)->f24),40,8,(u32)q,(u32)(((struct Obj00068 *)p)->f28),0x3c40);
    STRBUF_Delete(q);
    n += 12;
    q = func_02045EC0(((struct Obj00068 *)p)->f2C,n);
    PRINTSYS_PrintQueColor(((struct Obj00068 *)p)->f30,(u32)BMP_WIN_GetBmp(((struct Obj00068 *)p)->f20),0,0,(u32)q,(u32)(((struct Obj00068 *)p)->f28),0x3c40);
    STRBUF_Delete(q);
    ((struct Obj00068 *)p)->f1C = 1;
}



/*
 * lever: the two-halfword delta is a struct assignment; field stores differ by 13 bytes.
 */
void func_021D49C8(char *p, u32 n)
{
    u16 *q;
    u8 i, j;
    Vec delta;
    CLACT_SetActorAnimSeq(((struct Obj00122 *)p)->f5C, d_021D4CF4[n]);
    CLACT_SetActorDrawEnable(((struct Obj00122 *)p)->f5C, 1);
    if (n <= 7) {
        func_02061CA4((void *)31, 320, (u32)(*(char * *)&((struct Obj22993 *)(*(char * *)&((struct Obj00122 *)p)->f48))->fC + d_021D4CA4[n] * 32), 32);
        q = func_02030734(((struct Obj00122 *)p)->f0, 32, 1, d_021D4D4C, 0x2ac);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                q[i * 4 + j] = j + d_021D4C04[n] + i * 32 + 0xa000;
            }
        }
        func_02041090(4, (u32)q, 2, 4, 4, 4);
        func_020307B0(q);
    } else {
        q = func_02030734(((struct Obj00122 *)p)->f0, 32, 1, d_021D4D4C, 0x2bb);
        func_02041090(4, (u32)q, 2, 4, 4, 4);
        func_020307B0(q);
    }
    func_020409B4(4);
    delta = d_021D4BE0;
    CLACT_AddActorSurfacePos(((struct Obj00122 *)p)->f5C, (const struct Vec2 *)(&delta), 1);
    if (n == 10) {
        CLACT_SetActorAutoAnim(((struct Obj00122 *)p)->f5C, 0);
        CLACT_SetActorAnimIndex((int)(((struct Obj00122 *)p)->f5C), 1);
    } else if (n == 11) {
        CLACT_SetActorAutoAnim(((struct Obj00122 *)p)->f5C, 0);
        CLACT_SetActorAnimIndex((int)(((struct Obj00122 *)p)->f5C), 0);
    } else {
        CLACT_SetActorAutoAnim(((struct Obj00122 *)p)->f5C, 1);
    }
}



int func_021D4B14(void *a,int b,void *c)
{
    char *p;
    void **q;
    GFL_HEAP_CreateChildHeap(1,0x8a,0x60000);
    p = PROCSYS_AllocProcWork(a,0x60,0x8a);
    q = c;
    if (!q) {
        q = func_02030734(0x8a,8,1,d_021D4D4C,0x2f3);
        *q = MYSTATUS_Create(0x8a);
        if (KEY_GetCont() & 0x100) func_0200854C(*q,1);
        else func_0200854C(*q,0);
    }
    ((struct Obj00068 *)p)->f4 = q;
    ((struct Obj00068 *)p)->f0 = 0x8a;
    func_021D4240(p);
    return 1;
}



int func_021D4B84(struct S020315D4 *task,int b,int keep,char *p) {func_021D4280(p);if(keep==0){func_020307B0(**(void ** *)&((struct Obj00991 *)p)->f4);func_020307B0(((struct Obj00991 *)p)->f4);}func_020315D4(task);func_020306F0(0x8a);return 1;}
