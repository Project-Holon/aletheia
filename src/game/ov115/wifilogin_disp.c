/*
 * file:     wifilogin_disp.c
 * unit:     yes
 * function: func_021D42A8, func_021D42B8, func_021D42C8, func_021D42E0, func_021D4310, func_021D4360, func_021D43CC, func_021D43F4, func_021D4430, func_021D4474, func_021D4510, func_021D456C, func_021D45D0, func_021D460C, func_021D4644, func_021D46CC, func_021D4708, func_021D4798, func_021D47C4, func_021D4878, func_021D48A4, func_021D4910, func_021D493C, func_021D497C, func_021D4A98, func_021D4AB0, func_021D4B3C, func_021D4B80, func_021D4BB4, func_021D4BC4, func_021D4BFC, func_021D4CE4, func_021D4D10, func_021D4D38, func_021D4DF4, func_021D4E04, func_021D4E58, func_021D4FA4, func_021D50BC, func_021D5214, func_021D532C, func_021D5528, func_021D5598, func_021D57D0, func_021D580C, func_021D584C, func_021D58B4, func_021D5900, func_021D592C, func_021D5938
 * address:  0x021D42A8
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from wifilogin_disp.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_DATA_GetField1A0 0x0201283C thumb
 *   func_02009860 0x02009860 thumb
 *   func_020099C8 0x020099C8 thumb
 *   func_02009C24 0x02009C24 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   WIFILOGIN_COMMON_IsCancelInput 0x021D4240 thumb ov115
 *   GFL_NET_STATE_IsWifiLoginState 0x0203C600 arm
 *   func_0202EB0C 0x0202EB0C thumb
 *   DWC_RAP_IsUserDataChanged 0x02156C84 thumb ov009
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   DWC_RAP_ClearUserDataChanged 0x02156C98 thumb ov009
 *   func_02012944 0x02012944 thumb
 *   WIFILIST_GetGsProfileId 0x02009CC0 thumb
 *   func_02008540 0x02008540 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   GFL_NET_STATE_WifiStartMatch 0x0203C8A8 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   d_021D6560 0x021D6560 data a4
 *   d_021D65C0 0x021D65C0 data a4
 *   gWifiloginDialogId 0x021D6640 data a4
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_STATE_GetError 0x0203CA98 arm
 *   GFL_NET_ERR_ShowSimpleScreen 0x0200F83C thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_0200FBB0 0x0200FBB0 thumb
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   func_0200FBA0 0x0200FBA0 thumb
 *   GFL_NET_STATE_ClearErrorMode 0x0203C968 arm
 *   func_0200FA84 0x0200FA84 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   func_02009800 0x02009800 thumb
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   func_0202EB44 0x0202EB44 thumb
 *   func_0202EB4C 0x0202EB4C thumb
 *   DWC_CheckHasProfile 0x020597C8 arm
 *   DWC_CheckValidConsole 0x02059760 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   DWC_SVLGetTokenAsync 0x02167FA8 arm ov009
 *   d_021D65D0 0x021D65D0 data a4
 *   DWC_SVLProcess 0x02168040 arm ov009
 *   func_02034714 0x02034714 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_020403F4 0x020403F4 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02030734 0x02030734 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   d_021D6614 0x021D6614 data a1
 *   d_021D65E4 0x021D65E4 data a4
 *   d_021D65D4 0x021D65D4 data a4
 *   func_02030EAC 0x02030EAC arm
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   data_021D6364 0x021D6364 data a4
 *   data_021D64C4 0x021D64C4 data a4
 *   data_021D64A4 0x021D64A4 data a4
 *   data_021D6484 0x021D6484 data a4
 *   d_021D6464 0x021D6464 data a4
 *   d_021D6444 0x021D6444 data a4
 *   d_021D6424 0x021D6424 data a4
 *   d_021D6524 0x021D6524 data a4
 *   d_021D63E4 0x021D63E4 data a4
 *   d_021D63C4 0x021D63C4 data a4
 *   d_021D63A4 0x021D63A4 data a4
 *   d_021D6384 0x021D6384 data a4
 *   d_021D6404 0x021D6404 data a4
 *   d_021D6344 0x021D6344 data a4
 *   d_021D64E4 0x021D64E4 data a4
 *   d_021D6504 0x021D6504 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049F78 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   PALANM_BlendColors 0x02021F64 thumb
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0207D63C 0x0207D63C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_02040618 0x02040618 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   sub_02049238 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   GFL_USE_AddHBlankTask 0x02005624 thumb
 *   PMSI_PARAM_MakeSineTable 0x02024230 thumb
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_021D5984 0x021D5984 thumb ov115
 *   func_021D5A88 0x021D5A88 thumb ov115
 *   func_021D5A9C 0x021D5A9C thumb ov115
 *   func_021D5B50 0x021D5B50 thumb ov115
 *   func_021D5C24 0x021D5C24 thumb ov115
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D5C94 0x021D5C94 thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_021D5E34 0x021D5E34 thumb ov115
 *   func_021D5E48 0x021D5E48 thumb ov115
 *   func_021D5E6C 0x021D5E6C thumb ov115
 *   func_021D5EA8 0x021D5EA8 thumb ov115
 *   func_021D5ED8 0x021D5ED8 thumb ov115
 *   func_021D5F7C 0x021D5F7C thumb ov115
 */
#include "../../matched/include/Obj22582.h"
#include "../../matched/include/Obj22583.h"
#include "../../matched/include/Obj22584.h"
#include "../../matched/include/Obj22585.h"
#include "../../matched/include/Obj08038.h"
#include "../../matched/include/Obj22586.h"
#include "../../matched/include/Obj22587.h"
#include "../../matched/include/Obj22588.h"
#include "../../matched/include/Obj06413.h"
#include "../../matched/include/Obj13849.h"
#include "../../matched/include/Obj08039.h"
#include "../../matched/include/Obj22589.h"
#include "../../matched/include/Obj08040.h"
#include "../../matched/include/Obj22590.h"
#include "../../matched/include/Obj08041.h"
#include "../../matched/include/Obj22591.h"
#include "../../matched/include/Obj10330.h"
#include "../../matched/include/Obj22592.h"
#include "../../matched/include/Obj10331.h"
#include "../../matched/include/Obj22593.h"
#include "../../matched/include/Obj10332.h"
#include "../../matched/include/Obj22594.h"
#include "../../matched/include/Obj13850.h"
#include "../../matched/include/Obj02825.h"
#include "../../matched/include/Obj22595.h"
#include "../../matched/include/Obj01719.h"
#include "../../matched/include/Obj04465.h"
#include "../../matched/include/Obj22596.h"
#include "../../matched/include/Obj22597.h"
#include "../../matched/include/Obj22598.h"
#include "../../matched/include/Obj06414.h"
#include "../../matched/include/Obj13851.h"
#include "../../matched/include/Obj00198.h"
#include "../../matched/include/Obj03765.h"
#include "../../matched/include/Obj02170.h"
#include "../../matched/include/Obj03251.h"
#include "../../matched/include/Obj22599.h"
#include "../../matched/include/Obj10333.h"
#include "../../matched/include/Obj22600.h"
#include "../../matched/include/Obj22601.h"
#include "wifilogin_disp_shared_types.h"

#define W(k) (*(int *)(p+(k)))

#define P(k) (*(u8 **)(p+(k)))

struct BigObj;

struct Sub020097BCObj;

struct Sub020097BCFriend;

struct Req;

struct Big;

struct Rec160;

struct Reg2;

struct DWCstAccUserData;

struct DispConfig;

struct DispVram;

struct Node;

struct Bank;

typedef signed int     s32_021D42A8;

typedef struct BgTemplate {
    u32 unk_00, unk_04, bufSize, unk_0c;
    u8 unk_10, unk_11, unk_12, unk_13;
    u32 unk_14;
    u8 unk_18, unk_19, unk_1a, unk_1b;
    u32 unk_1c;
} BgTemplate;

typedef signed short s16_021D5598;

struct Rect { s16_021D5598 x,y; u16 z; u8 kind,mode; };

typedef signed int     s32_021D4FA4;

extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);

extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);

extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);

extern void func_02009C24(struct Sub020097BCObj *obj, int src, int dest);

extern u32 WIPE_SYS_EndCheck(void);

extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32);

extern int WIFILOGIN_COMMON_IsCancelInput(u8 *);

extern int GFL_NET_STATE_IsWifiLoginState(void);

extern u32 func_0202EB0C(void);

extern unsigned char DWC_RAP_IsUserDataChanged(void);

extern int GAME_DATA_SaveMain(u8 *);

extern void DWC_RAP_ClearUserDataChanged(int);

extern u8 *func_02012944(void *);

extern void *WIFILIST_GetGsProfileId(void *);

extern void func_02008540(void *,void *);

extern void GAME_DATA_SaveStart(u8 *);

extern int OS_IsRunOnTwl(void);

extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);

extern void GFL_NET_STATE_WifiStartMatch(void);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern u32 func_0200FB24(void);

extern u32 GFL_NET_STATE_GetError(void);

extern void GFL_NET_ERR_ShowSimpleScreen(void);

extern int GFL_NET_GetRunState(void);

extern u32 func_0200FBB0(void);

extern void GFL_NET_STATE_SetWifiError(void);

extern void func_0200FBA0(void);

extern void GFL_NET_STATE_ClearErrorMode(void);

extern void func_0200FA84(void);

extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32 index);

extern void *BATTLE_COMPETITION_GetFromSave(void *);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern void BATTLE_BOX_ClearLockFlags(struct Obj *p, int v);

extern void *BATTLE_BOX_GetFromSave(void *);

extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32_021D42A8 value);

extern void func_02009800(void *p);

extern s32_021D42A8 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);

extern int func_0202EB44(u8 *);

extern u32 func_0202EB4C(void);

extern int DWC_CheckHasProfile(struct DWCstAccUserData *userdata);

extern int DWC_CheckValidConsole(struct DWCstAccUserData *userdata);

extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

extern void GFL_USE_FadeOutBgm(u32 a);

extern int DWC_SVLGetTokenAsync(char *svl, void *result);

extern int DWC_SVLProcess(void);

extern void func_02034714(const char *,u32,const char *);

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *,int,unsigned);

extern void GFL_USE_CancelChangeAndPlayBgm(int,int);

extern void func_020403F4(u32 i);

extern void func_020315D4(struct S020315D4 *p);

extern void GFL_HEAP_DeleteChecked(unsigned int heap);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void BG_SYS_SetMainVisiblePlanes(u32);

extern void BG_SYS_SetSubVisiblePlanes(u32);

extern void BMP_SetDisplaySwap(u32);

extern void GX_DispOn(void);

extern void BG_SYS_Create(u16);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void func_02030EAC(struct Node *n);

extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void BG_SYS_Delete(void);

extern u32 func_020307B0(void *p);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void BG_SYS_PushTile(u8);

extern void BG_SYS_Init(u32,u32,u32,u32);

extern void BG_SYS_SetTileEntry(u8,int,int,int,u8,u8,u8);

extern void *func_020490F4(u32 id, u32 heap);

extern void func_02049B68(void *, u32, u32, u32, u32, u16);

extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);

extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);

extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);

extern void MI_CpuCopy8(const void *, void *, u32);

extern void PALANM_BlendColors(u16 *, u16 *, int, u8, u16);

extern void DWCi_ScreenDC_FlushRange(void *, int);

extern void *func_020056A0(void *, void *, int);

extern void func_0207D63C(void *, int, int, int, int);

extern void ARC_TOOL_DeleteHandle(void *);

extern void GX_LoadBGPltt(void *, int, int);

extern void func_0207E468(void *, int, int);

extern void func_02040618(u32 layer, u32 a, u32 b);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);

extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

extern s32_021D4FA4 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32_021D4FA4 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern s32_021D4FA4 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void sub_02049238(void *);

extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);

extern void CLACT_SetActorAutoAnim(struct Obj *,u32);

extern void CLACT_SetActorDrawEnable(struct Obj *,u32);

extern void *GFL_USE_AddHBlankTask(u32,u32,u32);

extern void PMSI_PARAM_MakeSineTable(s16_021D5598 *,u32,u16,int);

extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void CLACT_DrawSystem(void);

extern void CLACT_DeleteActor(struct Obj *p);

extern void CLACT_ReleasePalette(u32);

extern void CLACT_ReleaseCharacter(u32);

extern void CLACT_ReleaseCellAnim(u32);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(void);

extern void CLACT_VBlankSystem(void);

void func_021D42A8(u8 *p);

void func_021D42B8(u8 *p);

void func_021D42C8(int a,int b,u8 *p);

void func_021D42E0(u8 *p);

void func_021D4310(u8 *p);

void func_021D4360(u8 *p);

void func_021D43CC(u8 *p);

void func_021D43F4(u8 *p);

void func_021D4430(u8 *p);

void func_021D4474(u8 *p);

void func_021D4510(u8 *p);

void func_021D456C(u8 *p);

void func_021D45D0(u8 *p);

void func_021D460C(u8 *p);

int func_021D4644(u8 *p);

void func_021D46CC(u8 *p);

void func_021D4708(u8 *p);

void func_021D4798(u8 *p);

void func_021D47C4(u8 *p);

void func_021D4878(u8 *p);

void func_021D48A4(u8 *p);

void func_021D4910(u8 *p);

void func_021D493C(u8 *p);

void func_021D497C(u8 *p);

void func_021D4A98(u8 *p);

void func_021D4AB0(unsigned char *a);

void func_021D4B3C(u8 *p);

void func_021D4B80(u8 *p);

void func_021D4BB4(u8 *p);

void func_021D4BC4(u8 *p);

int func_021D4BFC(void *ctx,int unused,u8 *q);

int func_021D4CE4(int a,int b,int c,u8 *p);

int func_021D4D10(u32 a,int b,int c,u8 *p);

u8 *func_021D4D38(u16 heap, u32 mode, int a2);

void func_021D4DF4(u8 *p);

void func_021D4E04(u8 *p);

void func_021D4E58(u32 unused,unsigned long base);

void func_021D4FA4(void *unused, unsigned long base);

void func_021D50BC(void *unused, unsigned long base);

void func_021D5214(void *unused, unsigned long base);

void func_021D532C(char *p);

void func_021D5528(void *unused, u8 *p);

void func_021D5598(u8 *p);

void func_021D57D0(u8 *p);

void func_021D580C(u8 *p);

void func_021D584C(u8 *p);

void func_021D58B4(void *unused, u8 *p);

void func_021D5900(void *task,u8 *p);

void func_021D592C(u8 *p);

void func_021D5938(u8 *p);

u8 *func_021D5984(u32 heap, u32 bank, u32 mode);

void func_021D5A88(u8 *p);

void func_021D5A9C(u8 *p);

void func_021D5B50(void *p, int b);

void func_021D5C24(void *p, int b);

int func_021D5C70(u8 *p);

void func_021D5C94(u8 *p);

void func_021D5CCC(u8 *p, u32 n);

void func_021D5D3C(u8 *p);

void *func_021D5D5C(u8 *p, int mode, int flag, int selected);

void func_021D5E34(u8 *p);

void func_021D5E48(u8 *p);

int func_021D5E6C(u8 *p);

u8 func_021D5EA8(u8 *p);

void func_021D5ED8(u8 *p,u32 n);

void func_021D5F7C(u8 *p);

extern u8 d_021D6560[];

extern u8 d_021D65C0[];

extern u8 gWifiloginDialogId[];

extern char d_021D65D0[];

extern u8 d_021D6614[];

extern u32 d_021D65E4[];

extern u32 d_021D65D4[];

extern const struct BgTemplate data_021D6364,data_021D64C4,data_021D64A4,data_021D6484;

extern const BgTemplate d_021D6464, d_021D6444, d_021D6424, d_021D6524;

extern const BgTemplate d_021D63E4, d_021D63C4, d_021D63A4, d_021D6384;

extern const BgTemplate d_021D6404, d_021D6344, d_021D64E4, d_021D6504;

extern u8 gClActorInitParam[];

void func_021D42A8(u8 *p) { func_02009860((struct Sub020097BCObj *)GAME_DATA_GetField1A0(((struct Obj22582 *)p)->f44)); }

void func_021D42B8(u8 *p) { func_020099C8((void *)GAME_DATA_GetField1A0(((struct Obj22583 *)p)->f44),0); }

/*
 * extent: Two zero bytes of alignment padding follow the return.
 */
void func_021D42C8(int a,int b,u8 *p) { func_02009C24((void *)GAME_DATA_GetField1A0(((struct Obj22584 *)p)->f44),a,b); }

void func_021D42E0(u8 *p) { if(WIPE_SYS_EndCheck() && func_021D5C70((u8 *)(((struct Obj22585 *)p)->f38)) && WIFILOGIN_COMMON_IsCancelInput(p)) WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4AB0); }

void func_021D4310(u8 *p)
{
    if (WIFILOGIN_COMMON_IsCancelInput(p)) {
        func_021D5F7C((u8 *)(((struct Obj08038 *)p)->f38));
        if (((struct Obj22586 *)(*(u8 * *)&((struct Obj08038 *)p)->f40))->f4 == 0)
            func_021D5CCC((u8 *)(((struct Obj08038 *)p)->f38), 0x23);
        if (((struct Obj22587 *)(*(u8 * *)&((struct Obj08038 *)p)->f40))->f10 != 0)
            WIFILOGIN_COMMON_SetStateHandler(p, (u32)func_021D4BB4);
        else
            WIFILOGIN_COMMON_SetStateHandler(p, (u32)func_021D4AB0);
    } else {
        func_021D4644(p);
    }
}

void func_021D4360(u8 *p) {
 if(GFL_NET_STATE_IsWifiLoginState()) { if(W(0x20)) { func_021D5D3C((u8 *)W(0x38)); func_021D5C94((u8 *)W(0x38)); if(func_0202EB0C()) func_021D5ED8((u8 *)W(0x38),44); else func_021D5ED8((u8 *)W(0x38),19); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4310); } else if(*(int *)(P(0x40)+0x10)) { WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4BB4); } else { WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4AB0); } } else func_021D4644(p);
}

void func_021D43CC(u8 *p) { int r; if(DWC_RAP_IsUserDataChanged()) { r=GAME_DATA_SaveMain(*(u8 * *)&((struct Obj22588 *)p)->f44); switch(r) { case 0: case 1: return; default: DWC_RAP_ClearUserDataChanged(r); break; } } func_021D4360(p); }

void func_021D43F4(u8 *p) { void *a; if(func_021D5C70((u8 *)(((struct Obj06413 *)p)->f38))) { a=func_02012944(((struct Obj06413 *)p)->f44); func_02008540(a,WIFILIST_GetGsProfileId(((struct Obj06413 *)p)->f3C)); GAME_DATA_SaveStart(*(u8 * *)&((struct Obj06413 *)p)->f44); ((struct Obj06413 *)p)->f24=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D43CC); } }

void func_021D4430(u8 *p) {
 if(func_021D5C70((u8 *)((int)((u8 *)W(0x38))))) { if(DWC_RAP_IsUserDataChanged() && !W(0x24) && *(int *)(P(0x40)+0x14)!=2) { func_021D5C24((void *)W(0x38),30); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D43F4); } else { func_021D4360(p); } }
}

void func_021D4474(u8 *p) {
 int z; if(OS_IsRunOnTwl()) *(u32 *)(d_021D6560+0x48)=0x79000; else *(u32 *)(d_021D6560+0x48)=0x5e400; if(*(int *)(P(0x40)+0xc)==44) *(u32 *)(d_021D6560+0x48)=0x50000; else if(*(int *)(P(0x40)+0xc)==36) *(u32 *)(d_021D6560+0x48)=0x6e000; if(*(int *)(P(0x40)+0xc)!=10) *(u32 *)(d_021D6560+0x40)=0; z=0; d_021D65C0[7]=*(int *)(P(0x40)+0xc); *(u32 *)gWifiloginDialogId=*(int *)(P(0x40)+0xc); GFL_NET_StartSession((struct Req *)d_021D6560,z,(u32)p); GFL_NET_STATE_WifiStartMatch(); if(!*(int *)(P(0x40)+8)) GFL_NET_RestartWithDefaultTimeout(z,((struct Obj13849 *)p)->fC); else GFL_NET_RestartWithDefaultTimeout(1,((struct Obj13849 *)p)->fC); func_021D5C24((void *)W(0x38),23); func_021D592C(P(0x34)); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4430);
}

void func_021D4510(u8 *p) {
 if(func_021D5E6C((u8 *)W(0x30))) { if(!func_021D5EA8((u8 *)W(0x30))) { *(int *)(P(0x40)+0x1c)=0; WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4474); } else { *(int *)(P(0x40)+0x1c)=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4AB0); } func_021D5F7C((u8 *)W(0x38)); if(!*(int *)(P(0x40)+4)) func_021D5CCC((u8 *)W(0x38),35); func_021D5E34((u8 *)W(0x30)); W(0x30)=0; }
}

void func_021D456C(u8 *p) {
 if(func_021D5E6C((u8 *)W(0x30))) { if(!func_021D5EA8((u8 *)W(0x30))) { *(int *)(P(0x40)+0x1c)=0; WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4474); } else { *(int *)(P(0x40)+0x1c)=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4AB0); } func_021D5F7C((u8 *)W(0x38)); func_021D5C94((u8 *)W(0x38)); func_021D5E34((u8 *)W(0x30)); W(0x30)=0; if(!*(int *)(P(0x40)+4)) func_021D5CCC((u8 *)W(0x38),35); }
}

void func_021D45D0(u8 *p) { if(WIPE_SYS_EndCheck() && func_021D5C70((u8 *)(*(int *)&((struct Obj08039 *)p)->f38))) { ((struct Obj08039 *)p)->f30=func_021D5D5C(*(u8 * *)&((struct Obj08039 *)p)->f38,1,!((struct Obj22589 *)(*(u8 * *)&((struct Obj08039 *)p)->f40))->f4,0); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4510); } }

void func_021D460C(u8 *p) { if(WIPE_SYS_EndCheck()) { func_021D5D3C((u8 *)(*(int *)&((struct Obj08040 *)p)->f38)); ((struct Obj08040 *)p)->f30=func_021D5D5C(*(u8 * *)&((struct Obj08040 *)p)->f38,1,!((struct Obj22590 *)(*(u8 * *)&((struct Obj08040 *)p)->f40))->f4,0); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D456C); } }

int func_021D4644(u8 *p) {
 if(func_0200FB24()) { switch(*(u32 *)(GFL_NET_STATE_GetError()+4)) { case 1: case 2: case 3: case 4: case 5: case 6: func_021D5F7C((u8 *)W(0x38)); func_021D5D3C((u8 *)((int)((u8 *)W(0x38)))); func_021D5C94((u8 *)W(0x38)); GFL_NET_ERR_ShowSimpleScreen(); func_021D5938((u8 *)W(0x34)); if(GFL_NET_GetRunState()) func_0200FBB0(); GFL_NET_STATE_SetWifiError(); func_0200FBA0(); GFL_NET_STATE_ClearErrorMode(); func_021D5ED8((u8 *)W(0x38),37); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D460C); return 1; case 7: func_0200FA84(); break; case 0: default: break; } } return 0;
}

void func_021D46CC(u8 *p) { if(WIPE_SYS_EndCheck() && func_021D5C70((u8 *)(*(int *)&((struct Obj08041 *)p)->f38))) { ((struct Obj08041 *)p)->f30=func_021D5D5C(*(u8 * *)&((struct Obj08041 *)p)->f38,0,!((struct Obj22591 *)(*(u8 * *)&((struct Obj08041 *)p)->f40))->f4,0); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D456C); } }

void func_021D4708(u8 *p) {
 void *v; if(func_021D5E6C((u8 *)W(0x30))) { if(!func_021D5EA8((u8 *)W(0x30))) { v=REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((void *)W(0x44))),0); BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl((void *)W(0x44))),1); REGULATION_Card_SetValue(v,10,5); *(int *)(P(0x40)+0x1c)=0; func_02009800((void *)W(0x3c)); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4474); } else { *(int *)(P(0x40)+0x1c)=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D497C); } func_021D5F7C((u8 *)W(0x38)); if(!*(int *)(P(0x40)+4)) func_021D5CCC((u8 *)W(0x38),35); func_021D5E34((u8 *)W(0x30)); W(0x30)=0; }
}

void func_021D4798(u8 *p) { ((struct Obj10330 *)p)->f30=func_021D5D5C(*(u8 * *)&((struct Obj10330 *)p)->f38,1,!((struct Obj22592 *)(*(u8 * *)&((struct Obj10330 *)p)->f40))->f4,1); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4708);  }

void func_021D47C4(u8 *p) {
 int x; void *v; u32 y; if(func_021D5E6C((u8 *)W(0x30))) { x=func_021D5EA8((u8 *)W(0x30)); func_021D5F7C((u8 *)W(0x38)); if(!*(int *)(P(0x40)+4)) func_021D5CCC((u8 *)W(0x38),35); func_021D5E34((u8 *)W(0x30)); W(0x30)=0; if(!x) { v=REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((void *)W(0x44))),0); x=REGULATION_Card_GetValue(v,2); y=REGULATION_Card_GetValue(v,10); if(x && y>=1 && y<=4) { func_021D5D3C((u8 *)((int)((u8 *)W(0x38)))); func_021D5ED8((u8 *)W(0x38),38); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4798); } else { *(int *)(P(0x40)+0x1c)=0; func_02009800((void *)W(0x3c)); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4474); } } else { *(int *)(P(0x40)+0x1c)=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D497C); } }
}

void func_021D4878(u8 *p) { ((struct Obj10331 *)p)->f30=func_021D5D5C(*(u8 * *)&((struct Obj10331 *)p)->f38,1,!((struct Obj22593 *)(*(u8 * *)&((struct Obj10331 *)p)->f40))->f4,1); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D47C4);  }

void func_021D48A4(u8 *p) {
 if(func_021D5E6C((u8 *)W(0x30))) { if(!func_021D5EA8((u8 *)W(0x30))) { *(int *)(P(0x40)+0x1c)=0; func_021D5D3C((u8 *)((int)((u8 *)W(0x38)))); func_021D5ED8((u8 *)W(0x38),22); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4878); } else { *(int *)(P(0x40)+0x1c)=1; func_021D5F7C((u8 *)W(0x38)); if(!*(int *)(P(0x40)+4)) func_021D5CCC((u8 *)W(0x38),35); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4AB0); } func_021D5E34((u8 *)W(0x30)); W(0x30)=0; }
}

void func_021D4910(u8 *p) { ((struct Obj10332 *)p)->f30=func_021D5D5C(*(u8 * *)&((struct Obj10332 *)p)->f38,1,!((struct Obj22594 *)(*(u8 * *)&((struct Obj10332 *)p)->f40))->f4,1); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D48A4);  }

void func_021D493C(u8 *p) {
 if (WIPE_SYS_EndCheck() && WIFILOGIN_COMMON_IsCancelInput(p)) { func_021D5D3C((u8 *)((int)((u8 *)W(0x38)))); if (func_0202EB0C()) func_021D5ED8((u8 *)W(0x38), 0x2e); else func_021D5ED8((u8 *)W(0x38), 0x15); WIFILOGIN_COMMON_SetStateHandler(p, (u32)func_021D4910); }
}

/*
 * evidence: 0202EB44 leaves r0 live for this caller; entry p is forwarded.
 * 02009860 is bx lr; its unchanged entry pointer feeds both SDK readers.
 * callbacks: both zero-status arms use 42E0; mode2 and final else use 46CC;
 * missing profile uses 45D0, missing console uses 493C, mode1 uses 460C.
 */
void func_021D497C(u8 *p)
{
    if(func_0202EB44(p)==0) {
        func_021D5D3C((u8 *)((int)(P(0x38))));
        func_021D5ED8(P(0x38),39);
        *(int *)(P(0x40)+0x1c)=1;
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D42E0);
        return;
    }
    if(func_0202EB4C()==0) {
        func_021D5D3C((u8 *)((int)(P(0x38))));
        func_021D5ED8(P(0x38),34);
        *(int *)(P(0x40)+0x1c)=1;
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D42E0);
        return;
    }
    if(*(int *)(P(0x40)+0x14)==2) {
        func_021D5B50(P(0x38),17);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D46CC);
        return;
    }
    if(DWC_CheckHasProfile((struct DWCstAccUserData *)func_02009860((struct Sub020097BCObj *)P(0x3c)))==0) {
        ((struct Obj13850 *)p)->f20=1;
        func_021D5D3C((u8 *)((int)(P(0x38))));
        if(func_0202EB0C()==0) func_021D5ED8(P(0x38),18);
        else func_021D5ED8(P(0x38),43);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D45D0);
        return;
    }
    if(DWC_CheckValidConsole((struct DWCstAccUserData *)func_02009860((struct Sub020097BCObj *)P(0x3c)))==0) {
        ((struct Obj13850 *)p)->f20=1;
        func_021D5D3C((u8 *)((int)(P(0x38))));
        if(func_0202EB0C()==0) func_021D5ED8(P(0x38),20);
        else func_021D5ED8(P(0x38),45);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D493C);
        return;
    }
    if(*(int *)(P(0x40)+0x14)==1) {
        func_021D5D3C((u8 *)((int)(P(0x38))));
        func_021D5ED8(P(0x38),37);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D460C);
    } else {
        func_021D5B50(P(0x38),17);
        WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D46CC);
    }
}

void func_021D4A98(u8 *p) { if(WIPE_SYS_EndCheck()) WIFILOGIN_COMMON_SetStateHandler(p,0); }

void func_021D4AB0(unsigned char *a)
{
    int r;

    if (*(int *)(((struct Obj02825 *)a)->f40 + 0x20) != 0 &&
        *(int *)(((struct Obj02825 *)a)->f40 + 0x1c) == 0) {
        r = ((int (*)(int, int)) * (int *)(*(int *)(a + 0x40) + 0x20))(
            ((struct Obj02825 *)a)->f38, *(int *)(((struct Obj02825 *)a)->f40 + 0x24));
        if (r == 2)
            return;
        switch (r) {
        case 0:
            *(int *)(((struct Obj02825 *)a)->f40 + 0x1c) = 0;
            WIFILOGIN_COMMON_SetStateHandler(a, (int)func_021D4B3C);
            break;
        case 1:
            *(int *)(((struct Obj02825 *)a)->f40 + 0x1c) = 1;
            func_021D5F7C((unsigned char *)(((struct Obj02825 *)a)->f38));
            func_021D5D3C((u8 *)((int)((unsigned char *)(((struct Obj02825 *)a)->f38))));
            func_021D5C94((unsigned char *)(((struct Obj02825 *)a)->f38));
            if (GFL_NET_GetRunState() != 0)
                func_0200FBB0();
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
            func_021D5ED8((unsigned char *)(((struct Obj02825 *)a)->f38), 0x25);
            WIFILOGIN_COMMON_SetStateHandler(a, (int)func_021D460C);
            break;
        }
    } else {
        WIFILOGIN_COMMON_SetStateHandler(a, (int)func_021D4B3C);
    }
}

void func_021D4B3C(u8 *p) {
 WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj22595 *)p)->fC); if(!*(int *)(P(0x40)+4) && !*(int *)(P(0x40)+0x18)) GFL_USE_FadeOutBgm(8); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4A98);
}

void func_021D4B80(u8 *p) {
 if(!func_021D4644(p)) { if(DWC_SVLGetTokenAsync(d_021D65D0,(void *)(*(int *)(P(0x40)+0x10)))) WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4BC4); else func_021D4644(p); }
}

void func_021D4BB4(u8 *p) { WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4B80); }

void func_021D4BC4(u8 *p) { int x; if(!func_021D4644(p)) { x=DWC_SVLProcess(); if(x==3) WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4AB0); else if(x==4 || x==0 || x==5) func_021D4644(p); } }

/*
 * evidence: 0203159C leaves its allocation in r0, read here despite legacy void.
 * 021D4D38 r2 is explicitly loaded here and retained in the extern.
 */
int func_021D4BFC(void *ctx,int unused,u8 *q)
{
    u8 *p;
    if(((struct Obj04465 *)q)->fC==0) func_02034714(d_021D65D0,0,d_021D65D0);
    GFL_HEAP_CreateChildHeap(1,120,0x18000);
    p=PROCSYS_AllocProcWork(ctx,72,120);
    MI_CpuFill8(p,0,72);
    ((struct Obj01719 *)p)->fC=120;
    ((struct Obj01719 *)p)->f44=((struct Obj04465 *)q)->f0;
    ((struct Obj01719 *)p)->f34=func_021D4D38(((struct Obj01719 *)p)->fC,((struct Obj04465 *)q)->f4,((struct Obj04465 *)q)->f8);
    ((struct Obj01719 *)p)->f38=func_021D5984(((struct Obj01719 *)p)->fC,232,((struct Obj04465 *)q)->f8);
    ((struct Obj01719 *)p)->f2C=GAME_DATA_GetSaveControl(((struct Obj04465 *)q)->f0);
    ((struct Obj01719 *)p)->f3C=GAME_DATA_GetField1A0(((struct Obj04465 *)q)->f0);
    WIPE_SYS_Start(0,1,1,0,6,1,((struct Obj01719 *)p)->fC);
    *(u8 * *)&((struct Obj01719 *)p)->f40=q;
    if(GFL_NET_GetRunState()) {
        GFL_NET_STATE_SetWifiError();
        GFL_NET_STATE_ClearErrorMode();
        func_0200FBB0();
        func_0200FBA0();
    }
    WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D497C);
    if(((struct Obj22596 *)(*(u8 * *)&((struct Obj01719 *)p)->f40))->f4==0) {
        func_021D5CCC(*(u8 * *)&((struct Obj01719 *)p)->f38,35);
        if(((struct Obj22597 *)(*(u8 * *)&((struct Obj01719 *)p)->f40))->f18==0) GFL_USE_CancelChangeAndPlayBgm(1153,65535);
    } else {
        if(((struct Obj22598 *)(*(u8 * *)&((struct Obj01719 *)p)->f40))->f18==0) GFL_USE_CancelChangeAndPlayBgm(1155,65535);
    }
    return 1;
}

int func_021D4CE4(int a,int b,int c,u8 *p) { int r=1; void (*cb)(u8 *); func_021D4DF4(((struct Obj06414 *)p)->f34); func_021D5A88((u8 *)(((struct Obj06414 *)p)->f38)); cb=*(void (**)(u8 *))p; if(cb) { cb(p); r=0; } if(((struct Obj06414 *)p)->f30) func_021D5E48((u8 *)(((struct Obj06414 *)p)->f30)); return r; }

int func_021D4D10(u32 a,int b,int c,u8 *p) { func_020403F4(7); func_021D5A9C(*(u8 * *)&((struct Obj13851 *)p)->f38); func_021D4E04(*(u8 * *)&((struct Obj13851 *)p)->f34); func_020315D4((struct S020315D4 *)a); GFL_HEAP_DeleteChecked(120); return 1; }

/*
 * volatile: hardware reads/writes 021D4D66, 021D4D70, 021D4D74.
 */
u8 *func_021D4D38(u16 heap, u32 mode, int a2) {
    u8 *p;
    p=func_02030734(heap,0x14bc,1,(const char *)d_021D6614,146);
    ((struct Obj00198 *)p)->fC=heap;
    ((struct Obj00198 *)p)->f8=mode;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050=0;
    BMP_SetDisplaySwap(1);
    *(volatile u32 *)0x04001000 |= 0x10000;
    GX_DispOn();
    BG_SYS_Create(((struct Obj00198 *)p)->fC);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021D65E4);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021D65D4);
    switch (((struct Obj00198 *)p)->f8) {
    case 1:
        func_021D4FA4(p,0);
        func_021D5214(p,4);
        func_021D57D0(p);
        func_021D5598(p);
        break;
    case 0:
        func_021D4E58((u32)p,0);
        func_021D50BC(p,4);
        func_021D532C((char *)p);
        break;
    }
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(31);
    return p;
}

/*
 * trailing: two-byte alignment padding, no follower.
 */
void func_021D4DF4(u8 *p) { if(((struct Obj03765 *)p)->f8==1) func_021D580C(p); }

void func_021D4E04(u8 *p) {
    if (((struct Obj02170 *)p)->f8 == 1) func_021D584C(p);
    else if (((struct Obj02170 *)p)->f10) {
        func_02030EAC(((struct Obj02170 *)p)->f10);
        ((struct Obj02170 *)p)->f10 = 0;
        ((struct Obj02170 *)p)->f14 = 0;
    }
    BG_SYS_SetTileUnit(5, 1, 0);
    BG_SYS_SetTileUnit(6, 1, 0);
    func_020403F4(5);
    func_020403F4(4);
    func_02040588(5, 0);
    BG_SYS_Delete();
    func_020307B0(p);
}

/*
 * lever: initialized wrapping base+1 temporary before the first commit, then layer assignments before the following template copies, preserves the four table/call sequences and the original register webs.
 * ABI: first argument unused; full32 base is incremented with wrapping arithmetic and passed untruncated to40C14, while template/toggle/commit/rectangle calls explicitly truncate8 in the original.
 */
void func_021D4E58(u32 unused,unsigned long base)
{
    struct BgTemplate a,b,c,d;
    unsigned long layer1,layer2,layer3;
    u32 tmp;
    a=data_021D6364;
    BG_SYS_InitBgLayer((u8)base,&a,0);
    BG_SYS_SetPlaneVisible(base,1);
    tmp=(u32)base+1;
    BG_SYS_PushTile(base);
    layer1=tmp;
    b=data_021D64C4;
    BG_SYS_InitBgLayer((u8)layer1,&b,0);
    BG_SYS_SetPlaneVisible(layer1,1);
    BG_SYS_Init(layer1,0,1,0);
    BG_SYS_SetTileEntry(layer1,0,0,0,32,32,17);
    BG_SYS_PushTile(layer1);
    layer2=(u32)base+2;
    c=data_021D64A4;
    BG_SYS_InitBgLayer((u8)layer2,&c,0);
    BG_SYS_SetPlaneVisible(layer2,1);
    BG_SYS_SetTileEntry(layer2,0,0,0,32,32,17);
    BG_SYS_PushTile(layer2);
    layer3=(u32)base+3;
    d=data_021D6484;
    BG_SYS_InitBgLayer((u8)layer3,&d,0);
    BG_SYS_SetPlaneVisible(layer3,1);
    BG_SYS_Init(layer3,0,1,0);
    BG_SYS_SetTileEntry(layer3,0,0,0,32,32,17);
    BG_SYS_PushTile(layer3);
}

/*
 * ABI: base and unsigned-long indices are full 32-bit wrapping values;
 *   only BG calls with original lsls/lsrs pairs take u8.  Template copies
 *   follow index assignment; four distinct 32-byte locals preserve layout.
 */
void func_021D4FA4(void *unused, unsigned long base)
{
    BgTemplate t0, t1, t2, t3;
    unsigned long id1, id2, id3;
    t0 = d_021D6464;
    BG_SYS_InitBgLayer((u8)base, &t0, 0);
    BG_SYS_SetPlaneVisible(base, 1);
    BG_SYS_PushTile(base);
    id1 = base + 1;
    t1 = d_021D6444;
    BG_SYS_InitBgLayer((u8)id1, &t1, 0);
    BG_SYS_SetPlaneVisible(id1, 1);
    BG_SYS_PushTile(id1);
    id2 = base + 2;
    t2 = d_021D6424;
    BG_SYS_InitBgLayer((u8)id2, &t2, 0);
    BG_SYS_SetPlaneVisible(id2, 1);
    BG_SYS_PushTile(id2);
    id3 = base + 3;
    t3 = d_021D6524;
    BG_SYS_InitBgLayer((u8)id3, &t3, 0);
    BG_SYS_SetPlaneVisible(id3, 1);
    BG_SYS_Init(id3, 0, 1, 0);
    BG_SYS_SetTileEntry(id3, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(id3);
}

void func_021D50BC(void *unused, unsigned long base)
{
    BgTemplate t0, t1, t2, t3;
    unsigned long id1, id2, id3;
    t0 = d_021D63E4;
    BG_SYS_InitBgLayer((u8)base, &t0, 0);
    BG_SYS_SetPlaneVisible(base, 1);
    BG_SYS_PushTile(base);
    id1 = base + 1;
    t1 = d_021D63C4;
    BG_SYS_InitBgLayer((u8)id1, &t1, 0);
    BG_SYS_SetPlaneVisible(id1, 1);
    BG_SYS_Init(id1, 0, 1, 0);
    BG_SYS_SetTileEntry(id1, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(id1);
    id2 = base + 2;
    t2 = d_021D63A4;
    BG_SYS_InitBgLayer((u8)id2, &t2, 0);
    BG_SYS_SetPlaneVisible(id2, 1);
    BG_SYS_Init(id2, 0, 1, 0);
    BG_SYS_SetTileEntry(id2, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(id2);
    id3 = base + 3;
    t3 = d_021D6384;
    BG_SYS_InitBgLayer((u8)id3, &t3, 0);
    BG_SYS_SetPlaneVisible(id3, 1);
    BG_SYS_Init(id3, 0, 1, 0);
    BG_SYS_SetTileEntry(id3, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(id3);
}

void func_021D5214(void *unused, unsigned long base)
{
    BgTemplate t0, t1, t2, t3;
    unsigned long id1, id2, id3;
    t0 = d_021D6404;
    BG_SYS_InitBgLayer((u8)base, &t0, 0);
    BG_SYS_SetPlaneVisible(base, 1);
    BG_SYS_PushTile(base);
    id1 = base + 1;
    t1 = d_021D6344;
    BG_SYS_InitBgLayer((u8)id1, &t1, 0);
    BG_SYS_SetPlaneVisible(id1, 1);
    BG_SYS_Init(id1, 0, 1, 0);
    BG_SYS_SetTileEntry(id1, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(id1);
    id2 = base + 2;
    t2 = d_021D64E4;
    BG_SYS_InitBgLayer((u8)id2, &t2, 0);
    BG_SYS_SetPlaneVisible(id2, 1);
    BG_SYS_PushTile(id2);
    id3 = base + 3;
    t3 = d_021D6504;
    BG_SYS_InitBgLayer((u8)id3, &t3, 0);
    BG_SYS_SetPlaneVisible(id3, 1);
    BG_SYS_PushTile(id3);
}

/*
 * note 2026-10-05 (wD9r lane S5): twin of ov123 PDWACC_DISP_LoadResources (same callees, same loop); offsets differ only.
 */
void func_021D532C(char *p)
{
    void *record;
    u16 *base0;
    u16 *base1;
    void *h;
    int done;
    int k;
    int j;
    int i;
    u16 *cur;
    void *allocated;
    int m;
    int t;
    u16 *dst;
    u16 heap;
    h = func_020490F4(0x91, *(u16 *)(p + 0xc));
    j = 0;
    func_02049B68(h, 3, 4, 0, j, *(u16 *)(p + 0xc));
    func_02049658(h, 4, 4, 0, j, j, *(u16 *)(p + 0xc));
    func_020498F4(h, 6, 4, 0, j, j, *(u16 *)(p + 0xc));
    func_02049B68(h, 3, 0, 0, j, *(u16 *)(p + 0xc));
    func_02049658(h, 4, 0, 0, j, j, *(u16 *)(p + 0xc));
    func_020498F4(h, 5, 0, 0, j, j, *(u16 *)(p + 0xc));
    func_02049658(h, 4, 3, 0, j, j, *(u16 *)(p + 0xc));
    func_020498F4(h, 7, 3, 0, j, j, *(u16 *)(p + 0xc));
    heap = *(u16 *)(p + 0xc);
    MI_CpuFill8(p + 0x10, 0, 0x970);
    allocated = func_02049F78(h, 2, (u32)&record, heap);
    MI_CpuCopy8(*(void **)((u8 *)record + 0xc), p + 0x18, 0x1e0);
    MI_CpuCopy8(*(void **)((u8 *)record + 0xc), p + 0x1f8, 0x1e0);
    func_020307B0(allocated);
    for (i = 0; i < 15; i++) {
        base1 = (u16 *)(p + 0x1f8);
        base0 = (u16 *)(p + 0x18);
        t = i + 1;
        if (t >= 15) t -= 15;
        k = 0;
        done = 0;
        cur = (u16 *)(p + t * 32);
        while (1) {
            dst = base0 + i * 16;
            for (m = 4; m < 11; m++) {
                PALANM_BlendColors(dst + m, base1 + j * 16 + m, 1, (u8)(k >> 8), cur[m + 12]);
            }
            j++;
            if (done == 1) break;
            k += 0x600;
            if (k >= 0x1000) {
                k = 0x1000;
                done = 1;
            }
        }
    }
    DWCi_ScreenDC_FlushRange(p + 0x1f8, 0x780);
    *(u32 *)(p + 0x14) = 1;
    *(void **)(p + 0x10) = func_020056A0((void *)func_021D5528, p + 0x10, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    *(u8 *)(p + 0x97c) = 0;
    ARC_TOOL_DeleteHandle(h);
}

void func_021D5528(void *unused, u8 *p) {
    if (((struct Obj03251 *)p)->f4 == 0) return;
    ((struct Obj03251 *)p)->f96B ^= 1;
    if (((struct Obj03251 *)p)->f96B & 1) return;
    GX_LoadBGPltt(p + 0x1f0 + ((struct Obj03251 *)p)->f968 * 32, 40, 14);
    func_0207E468(p + 0x1f0 + ((struct Obj03251 *)p)->f968 * 32, 40, 14);
    ++((struct Obj03251 *)p)->f968;
    if (((struct Obj03251 *)p)->f968 >= 60) ((struct Obj03251 *)p)->f968 = 0;
    func_02040618(((struct Obj03251 *)p)->f96C, 2, 7);
}

/*
 * lever: an enum zero assigned after archive allocation and passed only in full-width outgoing zero slots preserves the independent literal register zeros.
 * checks: fixed one EXACT with all 26 relocations resolved; earlier typed permuter consumed and not repeated.
 * ABI: 49990 fifth argument is explicitly truncated16; B294 result
 *   is consumed by stores and setters despite its legacy void spelling.
 */
void func_021D5598(u8 *p)
{
    enum { Zero=0 } zero;
    u32 res;
    struct Rect a,b;
    res = (u32)ARC_TOOL_CreateHandle((u32)((void *)143), ((struct Obj00198 *)p)->fC);
    zero=Zero;
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)((u32)res),0,4,zero,0,((struct Obj00198 *)p)->fC);
    ((struct Obj00198 *)p)->f0 = ARC_UTIL_RegisterObjCharFromHandle((void *)((u32)res),7,4,zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),18,4,0,(u16)(((struct Obj00198 *)p)->f0),zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),19,6,0,(u16)(((struct Obj00198 *)p)->f0),zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),20,7,0,(u16)(((struct Obj00198 *)p)->f0),zero,0,((struct Obj00198 *)p)->fC);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)((u32)res),0,0,zero,0,((struct Obj00198 *)p)->fC);
    ((struct Obj00198 *)p)->f4 = ARC_UTIL_RegisterObjCharFromHandle((void *)((u32)res),6,0,zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),15,0,0,(u16)(((struct Obj00198 *)p)->f4),zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),16,1,0,(u16)(((struct Obj00198 *)p)->f4),zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),17,2,0,(u16)(((struct Obj00198 *)p)->f4),zero,0,((struct Obj00198 *)p)->fC);
    *(int *)&((struct Obj00198 *)p)->f990 = CLACT_RegisterCharacter((void *)((u32)res),9,0,1,((struct Obj00198 *)p)->fC);
    *(int *)&((struct Obj00198 *)p)->f98C = CLACT_RegisterPaletteEx((void *)((u32)res),3,1,0,0,3,((struct Obj00198 *)p)->fC);
    *(int *)&((struct Obj00198 *)p)->f994 = CLACT_RegisterCellAnim((void *)((u32)res),12,25,((struct Obj00198 *)p)->fC);
    sub_02049238((void *)res);
    a.x=128; a.y=96; a.z=10; a.kind=0; a.mode=2;
    *(struct Obj * *)&((struct Obj00198 *)p)->f99C = CLACT_CreateActor((void *)((struct Obj00198 *)p)->f980,((struct Obj00198 *)p)->f990,((struct Obj00198 *)p)->f98C,((struct Obj00198 *)p)->f994,&a,1,((struct Obj00198 *)p)->fC);
    CLACT_SetActorAutoAnim(*(struct Obj * *)&((struct Obj00198 *)p)->f99C,1);
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00198 *)p)->f99C,1);
    b.x=128; b.y=96; b.z=11; b.kind=1; b.mode=2;
    *(struct Obj * *)&((struct Obj00198 *)p)->f9A0 = CLACT_CreateActor((void *)((struct Obj00198 *)p)->f980,((struct Obj00198 *)p)->f990,((struct Obj00198 *)p)->f98C,((struct Obj00198 *)p)->f994,&b,1,((struct Obj00198 *)p)->fC);
    CLACT_SetActorAutoAnim(*(struct Obj * *)&((struct Obj00198 *)p)->f9A0,1);
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00198 *)p)->f9A0,1);
    func_0207D63C((void *)0x04000050,4,3,6,16);
    func_0207D63C((void *)0x04001050,8,21,6,16);
    ((struct Obj00198 *)p)->f988 = GFL_USE_AddHBlankTask((u32)func_021D58B4,(u32)p,0);
    PMSI_PARAM_MakeSineTable((s16_021D5598 *)(p+0x9ca),192,1456,6144);
    ((struct Obj00198 *)p)->fB4A = 10;
}

void func_021D57D0(u8 *p) { CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32)d_021D65E4,*(u16 *)(p+12)); *(void **)(p+0x980)=CLACT_CreateUnit(40,0,*(u16 *)(p+12)); *(void **)(p+0x984)=func_020056A0((void *)func_021D5900,p,0); }

void func_021D580C(u8 *p) {
    ++((struct Obj03765 *)p)->f9C8;
    if (((struct Obj03765 *)p)->f9C8 >= 192) ((struct Obj03765 *)p)->f9C8 = 0;
    if (((struct Obj03765 *)p)->fB4A) {
        ++((struct Obj03765 *)p)->fB4A;
        if (((struct Obj03765 *)p)->fB4A >= 257) ((struct Obj03765 *)p)->fB4A = 1;
    }
    CLACT_DrawSystem();
}

void func_021D584C(u8 *p) {
    int i;
    for (i = 0; i < 5; ++i) {
        if (*(u32 *)(p + i * 4 + 0x99c)) {
            CLACT_DeleteActor((struct Obj *)(*(u32 *)(p + i * 4 + 0x99c)));
            *(u32 *)(p + i * 4 + 0x99c) = 0;
        }
    }
    CLACT_ReleasePalette(((struct Obj02170 *)p)->f98C);
    CLACT_ReleaseCharacter(((struct Obj02170 *)p)->f990);
    CLACT_ReleaseCellAnim(((struct Obj02170 *)p)->f994);
    if (((struct Obj02170 *)p)->f988) func_02030EAC((struct Node *)(((struct Obj02170 *)p)->f988));
    func_02030EAC((struct Node *)(((struct Obj02170 *)p)->f984));
    CLACT_DeleteUnit((struct Bank *)(((struct Obj02170 *)p)->f980));
    CLACT_ExitSystem();
}

/*
 * lever: bind the hardware scanline before adding the signed counter;
 *        the nested expression moves the first four loads/adds.
 * volatile: hardware reads at 021D58BE, 021D58CC and writes 021D58E2, 021D58EA.
 */
void func_021D58B4(void *unused, u8 *p) {
    int i;
    i = *(volatile u16 *)0x04000006;
    i = (i + (((struct Obj22599 *)p)->f9C8 + 1)) % 192;
    if (*(volatile u16 *)0x04000004 & 2) {
        *(volatile u32 *)0x04000014 = *(s16 *)(p + 0x9ca + i * 2) & 511;
        *(volatile u32 *)0x04001018 = *(s16 *)(p + 0x9ca + i * 2) & 511;
    }
}

void func_021D5900(void *task,u8 *p) { if(((struct Obj10333 *)p)->fB4A>0) { func_02040618(7,0,((struct Obj10333 *)p)->fB4A-1); func_02040618(2,0,((struct Obj10333 *)p)->fB4A-1); } CLACT_VBlankSystem(); }

void func_021D592C(u8 *p) { ((struct Obj22600 *)p)->f9C4 = 1; }

void func_021D5938(u8 *p) {
    switch (((struct Obj22601 *)p)->f8) {
    case 1:
        func_0207D63C((void *)0x04000050, 4, 3, 6, 16);
        func_0207D63C((void *)0x04001050, 8, 21, 6, 16);
        break;
    case 0:
        func_0207D63C((void *)0x04000050, 1, 8, 8, 16);
        break;
    }
}
