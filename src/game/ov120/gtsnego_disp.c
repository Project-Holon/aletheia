/*
 * file:     gtsnego_disp.c
 * unit:     yes
 * function: func_021D4240, func_021D4244, func_021D424C, func_021D4278, func_021D42A8, func_021D42D8, func_021D435C, func_021D437C, func_021D439C, func_021D43BC, func_021D444C, func_021D4474, func_021D4490, func_021D44AC, func_021D44EC, func_021D4544, func_021D4584, func_021D4608, func_021D46A4, func_021D4774, func_021D4798, func_021D47D4, func_021D4808, func_021D4864, func_021D48F0, func_021D4930, func_021D4988, func_021D4A20, func_021D4B48, func_021D4C98, func_021D4CC4, func_021D4D28, func_021D4EC0, func_021D4F70, func_021D4F98, func_021D4FC0, func_021D4FD0, func_021D4FF4, func_021D505C, func_021D50A0, func_021D50C4, func_021D5188, func_021D51D4, func_021D5208, func_021D5230, func_021D5284, func_021D52D4, func_021D5318, func_021D5334, func_021D5758, func_021D57B0, func_021D588C, func_021D593C, func_021D596C, func_021D5980, func_021D59E0, func_021D5A84, func_021D5AD4, func_021D5BEC, func_021D5C60, func_021D5D74, func_021D5E30, func_021D5E88, func_021D5F98, func_021D5FC4, func_021D60FC, func_021D6100, func_021D6328, func_021D63F4, func_021D6530, func_021D6568, func_021D6810, func_021D6814, func_021D68C4, func_021D692C, func_021D6988, func_021D698C, func_021D69A0, func_021D69F4
 * address:  0x021D4240
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021D7E88 0x021D7E88 thumb ov120
 *   func_021D7E9C 0x021D7E9C thumb ov120
 *   func_021D7EB0 0x021D7EB0 thumb ov120
 *   func_021D6B84 0x021D6B84 thumb ov120
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   d_021D8904 0x021D8904 data a2
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_021D8430 0x021D8430 thumb ov120
 *   func_021D8484 0x021D8484 thumb ov120
 *   func_021D7A74 0x021D7A74 thumb ov120
 *   func_021D7F5C 0x021D7F5C thumb ov120
 *   func_021D80D4 0x021D80D4 thumb ov120
 *   func_021D880C 0x021D880C thumb ov120
 *   func_021D74B0 0x021D74B0 thumb ov120
 *   func_0217BC90 0x0217BC90 arm ov009
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   func_0200ED48 0x0200ED48 thumb
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_02008510 0x02008510 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   func_0217BC44 0x0217BC44 arm ov009
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   func_02009EA8 0x02009EA8 thumb
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   func_021D7C10  0x021D7C10  thumb  ov120
 *   func_021D8638  0x021D8638  thumb  ov120
 *   func_021D7B38  0x021D7B38  thumb  ov120
 *   func_021D8648  0x021D8648  thumb  ov120
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *   GFL_NET_STATE_GetWifiState  0x0203C3EC  arm
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   func_0216CB30 0x0216CB30 arm ov009
 *   func_02009EC8 0x02009EC8 thumb
 *   func_02009E74 0x02009E74 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 *   func_021D8590 0x021D8590 thumb ov120
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   func_02009CA8 0x02009CA8 thumb
 *   func_0216C8DC 0x0216C8DC arm ov009
 *   func_0208D7E0 0x0208D7E0 arm
 *   DWC_RAP_StartMatchWithFilter 0x0215580C thumb ov009
 *   GFL_NET_STATE_WifiEnterFriendMatch 0x0203C35C arm
 *   DWC_RAP_SetVchatEnabled 0x02156BC4 thumb ov009
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   d_021D8B40 0x021D8B40 data a2
 *   d_021D8B50 0x021D8B50 data a1
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D7550 0x021D7550 thumb ov120
 *   func_021D8520 0x021D8520 thumb ov120
 *   TOUCHBAR_IsBusy 0x021B6498 thumb ov067
 *   func_020355C4 0x020355C4 arm
 *   func_021D6A9C 0x021D6A9C thumb ov120
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021D88D0 0x021D88D0 data a4
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   func_02040588 0x02040588 arm
 *   func_021D7EC4 0x021D7EC4 thumb ov120
 *   TOUCHBAR_SetAllButtonsVisible 0x021B64D0 thumb ov067
 *   func_021D7D3C 0x021D7D3C thumb ov120
 *   func_021D7DC8 0x021D7DC8 thumb ov120
 *   func_021D7ECC 0x021D7ECC thumb ov120
 *   GAME_DATA_GetSaveBlock1F 0x02012F14 thumb
 *   func_02009E8C 0x02009E8C thumb
 *   func_02009E54 0x02009E54 thumb
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   func_021D761C 0x021D761C thumb ov120
 *   func_021D883C 0x021D883C thumb ov120
 *   func_021D8664 0x021D8664 thumb ov120
 *   func_021D6D94 0x021D6D94 thumb ov120
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   func_021D8418 0x021D8418 thumb ov120
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   func_021D6FD8 0x021D6FD8 thumb ov120
 *   func_021D8358 0x021D8358 thumb ov120
 *   func_021D6E50 0x021D6E50 thumb ov120
 *   func_021D6FF8 0x021D6FF8 thumb ov120
 *   func_021D82D8 0x021D82D8 thumb ov120
 *   func_021D6E1C 0x021D6E1C thumb ov120
 *   func_021D822C 0x021D822C thumb ov120
 *   func_021D702C 0x021D702C thumb ov120
 *   func_021D6D10 0x021D6D10 thumb ov120
 *   func_021D82F8 0x021D82F8 thumb ov120
 *   func_021D7260 0x021D7260 thumb ov120
 *   func_021D824C 0x021D824C thumb ov120
 *   func_021D7220 0x021D7220 thumb ov120
 *   KEY_GetRepeat 0x0203633C arm
 *   func_021D7020 0x021D7020 thumb ov120
 *   func_021D70C8 0x021D70C8 thumb ov120
 *   func_021D733C 0x021D733C thumb ov120
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   func_021D6E70 0x021D6E70 thumb ov120
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_021D7374 0x021D7374 thumb ov120
 *   func_021D82A8 0x021D82A8 thumb ov120
 *   func_021D72A0 0x021D72A0 thumb ov120
 *   func_021D6D48 0x021D6D48 thumb ov120
 *   d_021D88D8 0x021D88D8 data
 *   d_021D88C8 0x021D88C8 data
 *   func_021D6BB0 0x021D6BB0 thumb ov120
 *   func_021D81E0 0x021D81E0 thumb ov120
 *   func_021D70F0 0x021D70F0 thumb ov120
 *   func_0200F800 0x0200F800 thumb
 *   func_021D7D6C 0x021D7D6C thumb ov120
 *   func_02012934 0x02012934 thumb
 *   POKEPARTY_GetNonEggCount 0x0201AA1C thumb
 *   func_021D6AC0  0x021D6AC0  thumb
 *   func_021D7B60 0x021D7B60 thumb ov120
 *   func_021D846C 0x021D846C thumb ov120
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_021D7724 0x021D7724 thumb ov120
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021D88EC 0x021D88EC data a4
 *   func_0200F7E8 0x0200F7E8 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_0200FB24 0x0200FB24 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   func_021D7858 0x021D7858 thumb ov120
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   func_0200F7DC 0x0200F7DC thumb
 *   func_0200F7F4 0x0200F7F4 thumb
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   func_021D7898 0x021D7898 thumb ov120
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02030734 0x02030734 arm
 *   func_02034AC4 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_020056A0 0x020056A0 thumb
 *   d_021D8BC8 0x021D8BC8 data a1
 *   ov_id 0x00000043 data
 *   d_021D8B98 0x021D8B98 data a4
 *   d_021D8974 0x021D8974 data a4
 *   d_021D8B60 0x021D8B60 data a4
 *   CLACT_DrawSystem 0x0204A600 arm
 *   BLINK_PALANM_Update 0x0202EA40 thumb
 *   func_021D75F4 0x021D75F4 thumb ov120
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_021D6ED8 0x021D6ED8 thumb ov120
 *   func_021D6C64 0x021D6C64 thumb ov120
 *   func_020307B0 0x020307B0 arm
 *   func_021D6B5C 0x021D6B5C thumb ov120
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_0202EA20 0x0202EA20 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02034A5C 0x02034A5C arm
 *   d_021D89B0      0x021D89B0  data
 *   func_0203FCA0   0x0203FCA0  arm
 *   func_020414AC   0x020414AC  arm
 *   func_020409B4   0x020409B4  arm
 *   func_02040C14   0x02040C14  arm
 *   func_02041300   0x02041300  arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   PALANM_GetTransWork 0x02021730 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   d_021D8920 0x021D8920 data a4
 *   d_021D891C 0x021D891C data a4
 *   d_021D8918 0x021D8918 data a4
 *   d_021D895C 0x021D895C data a4
 *   d_021D896C 0x021D896C data a4
 *   d_021D894C 0x021D894C data a4
 *   d_021D8954 0x021D8954 data a4
 *   d_021D8944 0x021D8944 data a4
 *   d_021D8964 0x021D8964 data a4
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_02040618 0x02040618 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BLINK_PALANM_Create 0x0202E940 thumb
 *   BLINK_PALANM_LoadPalettes 0x0202E9AC thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021D6AF0 0x021D6AF0 thumb ov120
 *   d_021D8990 0x021D8990 data a4
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   TOUCHBAR_Delete  0x021B639C  thumb  ov067
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   d_021D8B70 0x021D8B70 data a1
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 */
#include "ov120_types.h"
struct GtsnegoDispCtx;
struct GtsnegoDispCtx2;
struct GtsnegoDispCtx_f48;

struct GtsnegoDispCtx {
    void *f0;
    unsigned int f4;
    unsigned char pad_8[4];
    unsigned short fC;
    unsigned char pad_E[2];
    unsigned int f10;
    int f14;
    unsigned int f18;
    unsigned char pad_1C[16];
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    unsigned int f44;
    void *f48;
    unsigned char pad_4C[236];
    int f138;
    int f13C;
    int f140;
    int f144;
    int f148;
    unsigned int f14C;
    int f150;
    unsigned char pad_154[4];
    int f158;
    int f15C;
    int f160;
    int f164;
    unsigned char pad_168[8];
    int f170;
    unsigned char pad_174[8];
    int f17C;
    unsigned char pad_180[4];
    int f184;
    unsigned short f188;
    unsigned char pad_18A[22];
    void *f1A0;
    unsigned char pad_1A4[4];
    int f1A8;
    unsigned short f1AC;
    unsigned char pad_1AE[2];
    unsigned int f1B0;
    unsigned int f1B4;
};

struct GtsnegoDispCtx2 {
    int f0;
    unsigned char pad_4[20];
    void *f18;
};

struct GtsnegoDispCtx_f48 {
    unsigned char pad_0[24];
    void *f18;
    unsigned char pad_1C[404];
    int f1B0;
};

#define I(k) (*(int *)(p + (k)))
struct Entry;
struct Link;
struct Obj;
struct Obj05353;
struct Sub0200852CObj;
struct MsgBank;
struct Rec;
struct U16Vec;
struct L0200ED54;
struct Rec44;
struct Sub24;
struct Rec0200E6FC;
struct Sub02009D9CObj;
struct S;
struct TaskMenu;
struct Ctx;
struct BigObj;
struct Obj0203159C;
struct Big;
struct S020315D4;
struct DispVram;
struct Bank;
struct Cfg;
struct Row;
struct Node;
struct Obj0202EA20;
struct Chan02021FD8;
struct PalAnmSlot;
struct CodeIn;
struct Actor;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 v[4]; } Halfwords;

typedef struct { u32 value; u8 kind; u8 pad; u16 detail; u32 tail; } Record_021D47D4;

typedef signed int     s32;

typedef struct Ctx {
    u8 pad0[0x2C];
    void *f2C;
    u8 pad30[4];
    void *f34;
    u8 pad38[4];
    u8 *f3C;
    void *f40;
    u8 pad44[0x148 - 0x44];
    int f148;
    u8 pad14C[4];
    int f150;
    u8 pad154[4];
    int f158;
    u8 pad15C[8];
    int f164;
} Ctx;

struct DispConfig { u32 a,b,c,d; };

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct Pair { int a,b; } Pair;

typedef struct Word { int a; } Word;

typedef struct Data { u32 w[8]; } Data;

typedef struct Config { Data *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1c; } Config;

typedef struct PosRecord { u16 x, y, z; u8 a, b; } PosRecord;

typedef signed short s16;

typedef struct Entry { u8 code, x, y, other; } Entry;

typedef struct Vec { s16 x, y; } Vec;

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *);
extern void func_02082D44(const void *,void *,u32);
extern int MYSTATUS_GetSize(void);
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021D7E88(char *p, int i);
extern void func_021D7E9C(char *p, int i);
extern void func_021D7EB0(char *p, int i);
extern void func_021D6B84(u8 *p, u32 n);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *,u32);
extern u32 WIPE_SYS_EndCheck(void);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern int GFL_NET_GetRunState(void);
extern void func_021D8430(u8 *p, void *q);
extern void func_021D8484(struct Obj05353 *p, void *n);
extern void func_021D7A74(u8 *p, int n);
extern void func_021D7F5C(char *p, u16 n);
extern void func_021D80D4(char *p);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void func_021D880C(char *p, void *q, u32 n);
extern void func_021D74B0(u8 *p, int n);
extern int func_0217BC90(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void MYSTATUS_Copy(void *src, void *dst);
extern void *func_0200ED48(void *p);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern void *func_02008510(void *, int);
extern void MI_CpuFill8(void *, u8, u32);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 STRBUF_GetEosChar(void);
extern int func_0217BC44(u16 **, int, char *, int, char *, int *, int);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,u32,u32);
extern int GFL_NET_SendToHandle(void *,u16,u16,u32);
extern int func_021D7AF4(char *p);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern void *func_0200E6E8(u32 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void *GAME_DATA_GetSaveBlock1F(void **h);
extern u32 func_02009EA8(const struct Sub02009D9CObj *obj);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern int func_021D7C10(char *p);
extern u32 KEY_GetTrg(void);
extern void func_021D8638(unsigned char *p);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern int GFL_NET_STATE_GetWifiState(void);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void func_021D7B38(char *p);
extern void func_021D8648(u8 *p);
extern int func_0216CB30(int, int, int);
extern void *func_02009EC8(void *);
extern u32 func_02009E74(struct Sub02009D9CObj *obj, u32 id);
extern void func_021D8590(u8 *, int, int);
extern void GFL_NET_SetWaitMode(int);
extern void func_02009CA8(void *account, void *out);
extern u8 func_0216C8DC(u8 keyID, char *keyString, int *valueSrc);
extern int func_0208D7E0(char *, const char *, ...);
extern int DWC_RAP_StartMatchWithFilter(int, int, int, int);
extern u32 GFL_NET_STATE_WifiEnterFriendMatch(void);
extern void DWC_RAP_SetVchatEnabled(int);
extern void GFL_NET_STATE_SetError(int, u32, u32, u32);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void func_02041B6C(u32 bit);
extern void func_021D79F4(u8 *p, u16 n);
extern void func_021D7550(u8 *p);
extern void func_021D8520(char *p, u16 n);
extern int TOUCHBAR_IsBusy(u8 *);
extern u8 func_020355C4(void);
extern int func_021D6A9C(u8 *p, u32 n);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021D7EC4(u8 *p);
extern void TOUCHBAR_SetAllButtonsVisible(u8 *, u32);
extern void func_021D7D3C(char *p);
extern void func_021D7DC8(char *p, int a, int b, int c, int d, int e);
extern void *func_021D7ECC(char *p, u16 n);
extern int func_02009E8C(void *);
extern void *func_02009E54(void *,int);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_021D761C(u8 *);
extern void func_021D883C(char *);
extern int func_021D8664(u8 *p);
extern void func_021D6D94(u8 *p);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void func_021D8418(int);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021D6FD8(u8 *p, u32 flag);
extern void *func_021D8358(char *p, int n);
extern int func_021D6E50(void *unused, int *p);
extern void func_021D6FF8(u8 *p, int state);
extern void func_021D82D8(char *p, void *q, int n);
extern int func_021D6E1C(void *unused, int *p);
extern void func_021D822C(char *p, void *q, int index);
extern int func_021D702C(u8 *p, int *out);
extern void func_021D6D10(u8 *p, void *list, int first);
extern void func_021D82F8(char *p);
extern void func_021D7260(u8 *p, void *q);
extern void func_021D824C(char *p);
extern void func_021D7220(u8 *p, void *q);
extern u32 KEY_GetRepeat(void);
extern void func_021D7020(u8 *p);
extern void func_021D70C8(u8 *p, int flag);
extern void func_021D733C(u8 *p, int index, int count);
extern void func_021D6E70(void *unused, int *p, int n);
extern int TOUCHPANEL_HitCont(const void *t);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int func_021D7374(char *p, int y, int count);
extern void func_021D82A8(char *p, void *q, int start);
extern void func_021D72A0(u8 *p, void *list, int n);
extern void func_021D6D48(u8 *p);
extern void func_021D6BB0(u8 *, int);
extern void func_021D81E0(char *, void *);
extern void func_021D70F0(void *);
extern void func_0200F800(void);
extern void func_021D7D6C(char *p, int a, int b);
extern void *func_02012934(const struct BigObj *p);
extern u32 POKEPARTY_GetNonEggCount(void *);
extern int func_021D6AC0(u8 *p);
extern void *func_021D7B60(char *p, int n);
extern void func_021D846C(u8 *);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern char *func_021D7724(u32 heap, u32 n);
extern void WIPE_SetBrightnessFadeOut(u32, u32);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 func_0201283C(const struct BigObj *p);
extern void GFL_NET_COMMAND_AddCommandTable(u32, u32, u32, u32);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern void func_0200F7E8(u32 value);
extern u32 func_0200FB24(void);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void APP_TASKMENU_UpdateMenu(void *);
extern void func_021D7858(u8 *p);
extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);
extern void func_0200F7DC(void);
extern void func_0200F7F4(void);
extern void GFL_NET_COMMAND_DeleteCommandTable(unsigned int);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void func_021D7898(char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern int func_02034AC4(int);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void func_0204363C(u32 swap);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void func_0203FC28(struct DispConfig *);
extern void *func_020056A0(void (*)(void *,u8 *),void *,int);
extern void CLACT_DrawSystem(void);
extern s32 BLINK_PALANM_Update(struct Row *p);
extern void func_021D75F4(char *p);
extern void CLACT_DeleteActor(struct Obj *p);
extern void func_021D6ED8(u8 *);
extern void func_021D6C64(u8 *);
extern u32 func_020307B0(void *p);
extern void func_021D6B5C(u8 *);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02040DA8(u32,u32,u32);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
extern void func_02034A5C(int handle);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u32, u32, u32, u32, u8, u8, u8);
extern void *PALANM_Create(u32);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int PALANM_GetTransWork(char *,int);
extern void func_020862F0(void *,unsigned long);
extern void func_0207E5D0(void *,int,int);
extern void func_0207E468(void *,int,int);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void CLACT_VBlankSystem(void);
extern void func_02040618(u32,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct CodeIn *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap);
extern void BLINK_PALANM_LoadPalettes(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021D6AF0(u8 *, u16, u16, int);
extern void *TOUCHBAR_Create(Config *, int);
extern void TOUCHBAR_Delete(u8 *p);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void func_021D4240(void **p, void *v);
void func_021D4244(void *p, void *fn, int line);
void func_021D424C(u32 id,int b,const void *src,struct GtsnegoDispCtx *p,struct Entry *entry);
void func_021D4278(u32 id,int b,const void *src,struct GtsnegoDispCtx *p,struct Entry *entry);
void func_021D42A8(u32 id,int b,const void *src,u8 *p,struct Entry *entry);
int func_021D42D8(int n, u8 *p);
void func_021D435C(int n, char *p);
void func_021D437C(int n, char *p);
void func_021D439C(int n, char *p);
int func_021D43BC(int n, char *p);
int func_021D444C(int n,char *p);
void func_021D4474(int n,char *p);
void func_021D4490(u8 *p);
void func_021D44AC(struct GtsnegoDispCtx *p);
void func_021D44EC(u8 *a);
void func_021D4544(struct GtsnegoDispCtx *a);
void func_021D4584(struct GtsnegoDispCtx *p);
void func_021D4608(struct GtsnegoDispCtx *p);
void func_021D46A4(u8 *p);
void func_021D4774(u8 *p);
void func_021D4798(struct GtsnegoDispCtx *p);
void func_021D47D4(u8 *p);
void func_021D4808(struct GtsnegoDispCtx *a);
void func_021D4864(u8 *p);
void func_021D48F0(int *a);
void func_021D4930(struct GtsnegoDispCtx *a);
void func_021D4988(struct GtsnegoDispCtx *a);
int func_021D4A20(int a, u8 *p);
void func_021D4B48(u8 *p);
void func_021D4C98(void *p,int n,u8 *s);
void func_021D4CC4(struct GtsnegoDispCtx *p);
void func_021D4D28(u8 *p);
void func_021D4EC0(u8 *p);
void *func_021D4F70(void **p,int i);
void *func_021D4F98(void **p,int i);
void func_021D4FC0(u8 *p);
void func_021D4FD0(struct GtsnegoDispCtx *p);
void func_021D4FF4(struct GtsnegoDispCtx *p);
void func_021D505C(int a, int b, int *p);
void func_021D50A0(struct GtsnegoDispCtx *p);
void func_021D50C4(struct GtsnegoDispCtx *p);
void func_021D5188(struct GtsnegoDispCtx *p);
void func_021D51D4(struct GtsnegoDispCtx *p);
void func_021D5208(struct GtsnegoDispCtx *p);
int func_021D5230(u8 *p);
int func_021D5284(u8 *p);
void func_021D52D4(struct GtsnegoDispCtx *p);
void func_021D5318(u8 *p);
void func_021D5334(Ctx *p);
void func_021D5758(struct GtsnegoDispCtx *p);
void func_021D57B0(struct GtsnegoDispCtx *p);
void func_021D588C(u8 *p);
int func_021D593C(u8 *p,int n);
int func_021D596C(struct GtsnegoDispCtx *p, int x);
void func_021D5980(struct GtsnegoDispCtx *p);
void func_021D59E0(struct GtsnegoDispCtx *p);
void func_021D5A84(struct GtsnegoDispCtx *p);
void func_021D5AD4(u8 *p);
void func_021D5BEC(u8 *p);
int func_021D5C60(void *a, int unused, u8 *q);
int func_021D5D74(int a, int b, int c, u8 *p);
int func_021D5E30(void *p, int a, int b, struct GtsnegoDispCtx *q);
u8 *func_021D5E88(u32 heap,void *arg);
void func_021D5F98(struct GtsnegoMsgCtx *p);
void func_021D5FC4(u8 *p);
u32 func_021D60FC(struct GtsnegoDispCtx *p);
void func_021D6100(u8 *a0);
void func_021D6328(struct GtsnegoMsgCtx *p,int bank,int *offset,int *size,int count);
void func_021D63F4(struct GtsnegoMsgCtx *p,int flag,int mode);
void func_021D6530(void *unused,u8 *p);
void func_021D6568(u8 *p);
void func_021D6810(u8 *a0, int a1);
void func_021D6814(u8 *p);
void func_021D68C4(u8 *p);
void func_021D692C(u8 *p, int n);
u32 func_021D6988(u8 *p);
void func_021D698C(u8 *p);
void func_021D69A0(u8 *p);
void func_021D69F4(u8 *p, void *q, u32 n);
extern const Halfwords d_021D8904;
extern const u16 d_021D8B40[];
extern const char d_021D8B50[];
extern const u32 d_021D88D0[];
extern const u8 d_021D88D8[];
extern const u8 d_021D88C8[];
extern const u32 d_021D88EC[];
extern const char d_021D8BC8[];
extern const u8 ov_id[];
extern const struct DispVram d_021D8B98;
extern const u32 d_021D8974[];
extern struct DispConfig d_021D8B60;
extern const struct BgTemplate d_021D89B0[8];
extern const Word d_021D8920,d_021D891C,d_021D8918;
extern const Pair d_021D895C,d_021D896C,d_021D894C,d_021D8954,d_021D8944,d_021D8964;
extern const Data d_021D8990;
extern const Entry d_021D8B70[];




void func_021D4240(void **p, void *v) { *p=v; }




void func_021D4244(void *p, void *fn, int line) { func_021D4240(p, fn); }




void func_021D424C(u32 id,int b,const void *src,struct GtsnegoDispCtx *p,struct Entry *entry) { u8 *q; q=*(u8 * *)&p->f48; if(entry==GFL_NET_HANDLE_GetCurrentHandle() && id!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) func_02082D44(src,q+12,8); }




void func_021D4278(u32 id,int b,const void *src,struct GtsnegoDispCtx *p,struct Entry *entry) { u8 *q; q=*(u8 * *)&p->f48; if(entry==GFL_NET_HANDLE_GetCurrentHandle() && id!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) func_02082D44(src,((struct GtsnegoDispCtx2 *)q)->f18,MYSTATUS_GetSize()); }




void func_021D42A8(u32 id,int b,const void *src,u8 *p,struct Entry *entry) { if(entry==GFL_NET_HANDLE_GetCurrentHandle() && id!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) func_02082D44(src,p+0x174,12); }




/*
 * extent: existing matched followers 021D435C, 021D437C, 021D439C remain separate.
 */
int func_021D42D8(int n, u8 *p)
{
    ((struct GtsnegoDispCtx *)p)->f138 = n;
    func_020355D8(1);
    if (((struct GtsnegoDispCtx *)p)->f184 == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        return 1;
    }
    if (n == 0) {
        ((struct GtsnegoDispCtx *)p)->f15C = 0;
        func_021D69F4(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f34, 0);
        func_021D593C(p, ((struct GtsnegoDispCtx *)p)->f15C);
        func_021D4244(p, func_021D5980, 0x177);
    } else {
        ((struct GtsnegoDispCtx *)p)->f15C = 1;
        func_021D69F4(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f34, 1);
        func_021D593C(p, ((struct GtsnegoDispCtx *)p)->f15C);
        func_021D4244(p, func_021D5980, 0x17e);
    }
    return 1;
}




/*
 * follower: separately filed 021D437C.
 */
void func_021D435C(int n, char *p) {
    ((struct GtsnegoDispCtx *)p)->f13C+=n;
    if(((struct GtsnegoDispCtx *)p)->f13C>=5) ((struct GtsnegoDispCtx *)p)->f13C=0;
    else if(((struct GtsnegoDispCtx *)p)->f13C<0) ((struct GtsnegoDispCtx *)p)->f13C=4;
}




/*
 * follower: separately filed 021D439C.
 */
void func_021D437C(int n, char *p) {
    ((struct GtsnegoDispCtx *)p)->f140+=n;
    if(((struct GtsnegoDispCtx *)p)->f140>=5) ((struct GtsnegoDispCtx *)p)->f140=0;
    else if(((struct GtsnegoDispCtx *)p)->f140<0) ((struct GtsnegoDispCtx *)p)->f140=4;
}




void func_021D439C(int n, char *p) {
    ((struct GtsnegoDispCtx *)p)->f144+=n;
    if(((struct GtsnegoDispCtx *)p)->f144>=4) ((struct GtsnegoDispCtx *)p)->f144=0;
    else if(((struct GtsnegoDispCtx *)p)->f144<0) ((struct GtsnegoDispCtx *)p)->f144=3;
}




int func_021D43BC(int n, char *p) {
    int result=0;
    switch(n) {
    case 0:func_021D439C(-1,p);result=2;func_021D7E88((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f144);break;
    case 1:func_021D439C(1,p);result=2;func_021D7E88((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f144);break;
    case 2:func_021D435C(-1,p);result=3;func_021D7E9C((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f13C);break;
    case 3:func_021D435C(1,p);result=3;func_021D7E9C((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f13C);break;
    case 4:func_021D437C(-1,p);result=4;func_021D7EB0((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f140);break;
    case 5:func_021D437C(1,p);result=4;func_021D7EB0((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40),((struct GtsnegoDispCtx *)p)->f140);break;
    }
    if(n>=0 && n<=5) {GFL_USE_PlaySeDefaultVolume(0x548);func_021D6B84((u8 *)(*(int *)&((struct GtsnegoDispCtx *)p)->f3C),n);}
    return result;
}




int func_021D444C(int n,char *p) { int result; if(*(struct Obj * *)&((struct GtsnegoDispCtx *)p)->f34) APP_TASKMENU_WIN_SetActive(*(struct Obj * *)&((struct GtsnegoDispCtx *)p)->f34,0); result=func_021D43BC(n,p); if(result) ((struct GtsnegoDispCtx *)p)->f160=result; return 1; }


void func_021D4474(int n,char *p) { int v; v=((struct GtsnegoDispCtx *)p)->f160-2; if(((struct GtsnegoDispCtx *)p)->f160>=2 || ((struct GtsnegoDispCtx *)p)->f160<=4) func_021D43BC(n+v*2,p); }






void func_021D4490(u8 *p) { if (WIPE_SYS_EndCheck()) func_021D4244(p, 0, 0x213); }






void func_021D44AC(struct GtsnegoDispCtx *p) {
    if (--p->f14<=0) {
        WIPE_SYS_Start(0,0,0,0,6,1,p->fC);
        func_021D4244(p, func_021D4490, 0x21e);
    }
}





void func_021D44EC(u8 *a)
{
    Halfwords table = d_021D8904;
    const Halfwords *p = &table;
    if (GFL_NET_GetRunState() != 0)
        p = (const Halfwords *)(a + 0x174);
    ((struct GtsnegoDispCtx *)a)->f14 = 0xb4;
    func_021D8430((u8 *)(*(int *)&((struct GtsnegoDispCtx *)a)->f40), (void *)(*(int *)&((struct GtsnegoDispCtx *)a)->f3C));
    func_021D8484((struct Obj05353 *)(*(int *)&((struct GtsnegoDispCtx *)a)->f40), (void *)p);
    func_021D4244(a, func_021D44AC, 0x232);
}




void func_021D4544(struct GtsnegoDispCtx *a)
{
    --a->f14;
    if (a->f14 == 20)
        func_021D7A74((u8 *)(*(int *)&a->f40), 0x27);
    if (a->f14 == 0) {
        func_021D7F5C((char *)(*(int *)&a->f40), 0x23);
        func_021D80D4((char *)(*(int *)&a->f40));
        func_021D4244(a, func_021D44EC, 0x241);
    }
}




void func_021D4584(struct GtsnegoDispCtx *p)
{
    u8 *q = *(u8 * *)&p->f48;
    int value;
    int mode = 2;
    if (GFL_NET_GetRunState() == 0) {
        value = (int)func_02012944((void *)(*(int *)&((struct GtsnegoMsgCtx *)q)->f0));
    } else {
        value = *(int *)&((struct GtsnegoMsgCtx *)q)->f18;
        mode = p->f17C;
        *(int *)(q + ((struct GtsnegoMsgCtx *)q)->f1AC * 4 + 0x1c) = func_02008530((const struct Sub0200852CObj *)value);
        ((struct GtsnegoMsgCtx *)q)->f1AC = ((struct GtsnegoMsgCtx *)q)->f1AC + 1;
        if (((struct GtsnegoMsgCtx *)q)->f1AC >= 100)
            ((struct GtsnegoMsgCtx *)q)->f1AC = 0;
    }
    func_021D880C((char *)(*(int *)&p->f40), (void *)value, mode);
    func_021D74B0((u8 *)(*(int *)&p->f3C), func_02008554((const struct Sub0200852CObj *)value));
    p->f14 = 0xb4;
    func_021D4244(((int *)p), func_021D4544, 0x265);
}




void func_021D4608(struct GtsnegoDispCtx *p)
{
    int ready = 0;
    int value = *(int *)&((struct GtsnegoDispCtx_f48 *)p->f48)->f18;
    int active;
    void *message;
    void *text;
    int result;
    active = func_0217BC90() == 2;
    if (active)
        ready = p->f1A8 > 0;
    if (active) {
        if (ready) {
            message = func_02045B38(0, 2, 0x51, 0x1f);
            text = func_02045EC0(message, 15);
            MSGDATA_Delete(message);
            func_020084E4((u16 *)value, text);
            STRBUF_Delete(text);
        }
        MYSTATUS_Copy((void *)value, func_02012950((struct Sub24 *)(*(int *)&p->f2C), 1 - GFL_NET_SYSTEM_GetCurrentAid()));
        result = func_02008530((const struct Sub0200852CObj *)value);
        func_0200ED54(func_0200ED48((void *)(*(int *)&p->f30)), result);
        func_021D4244(((int *)p), func_021D4584, 0x283);
    }
}




/*
 * evidence: 020399A8's r0 is consumed by 02039CB4 despite its void definition.
 * evidence: 020458F8 returns ldrh r0; this caller uses full-word r0+1 without narrowing.
 */
void func_021D46A4(u8 *p)
{
    void *str;
    u16 *chars;
    u32 i;
    void *value = ((struct GtsnegoDispCtx_f48 *)((struct GtsnegoDispCtx *)p)->f48)->f18;
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x22) != 0) {
        str = func_02008510(value, 31);
        MI_CpuFill8(p + 0x188, 0, 40);
        ((struct GtsnegoDispCtx *)p)->f1AC = 31;
        chars = STRBUF_GetChars(str);
        for (i = 0; i < STRBUF_GetLength(str) + 1u; i++) {
            u16 c = chars[i];
            if (c == STRBUF_GetEosChar()) ((u16 *)(p + 0x188))[i] = 0;
            else ((u16 *)(p + 0x188))[i] = c;
        }
        ((struct GtsnegoDispCtx *)p)->f1A0 = p + 0x188;
        *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f1A8 = 0;
        func_0217BC44((u16 **)(p + 0x1a0), 1, 0, 0, (char *)(p + 0x1a4), (int *)(p + 0x1a8), 128);
        STRBUF_Delete(str);
        func_021D4244(((int *)p), func_021D4608, 0x29c);
    }
}




void func_021D4774(u8 *p) { GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),3,34); func_021D4244(p, func_021D46A4, 0x2ac); }




void func_021D4798(struct GtsnegoDispCtx *p) { void *link; int n; link=GFL_NET_HANDLE_GetCurrentHandle(); n=MYSTATUS_GetSize(); if (GFL_NET_SendToHandle(link,0x2201,n,*(u32 *)(*(unsigned int *)&p->f48+20))) func_021D4244(p, func_021D4774, 0x2bd); }








void func_021D47D4(u8 *p) { if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0x2202,12,(u32)(p+360))) func_021D4244(p, func_021D4798, 0x2cf); }









void func_021D4808(struct GtsnegoDispCtx *a)
{
    if (GFL_NET_GetRunState() == 0) {
        func_021D4244(a, func_021D4584, 0x2df);
        return;
    }
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x22) != 0) {
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2200, 8, (u32)(*(char * *)&a->f48 + 4)) != 0)
            func_021D4244(a, func_021D47D4, 0x2e7);
    }
}









void func_021D4864(u8 *p)
{
    u8 *q;
    int value;
    if (func_021D7AF4((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40))) {
        if (GFL_NET_GetRunState() == 0) {
            func_021D4244(((int *)p), func_021D4808, 0x2fe);
            return;
        }
        if (((struct GtsnegoDispCtx *)p)->f14 > 0) {
            ((struct GtsnegoDispCtx *)p)->f14 = ((struct GtsnegoDispCtx *)p)->f14 - 1;
            return;
        }
        if (GFL_NET_HANDLE_GetNegotiationNum() == 2) {
            q = *(u8 * *)&((struct GtsnegoDispCtx *)p)->f48;
            value = (int)func_0200E6E8(*(int *)&((struct GtsnegoDispCtx *)p)->f30);
            *(int *)&((struct GtsnegoMsgCtx *)q)->f4 = ((struct GtsnegoDispCtx *)p)->f144;
            *(int *)&((struct GtsnegoMsgCtx *)q)->f8 = ((struct GtsnegoDispCtx *)p)->f13C;
            func_0200E6FC((struct Rec0200E6FC *)value, 0, (struct Rec0200E6FC *)(p + 0x168));
            ((struct GtsnegoDispCtx *)p)->f170 = func_02009EA8(GAME_DATA_GetSaveBlock1F((void **)(*(int *)&((struct GtsnegoDispCtx *)p)->f2C)));
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x22);
            func_021D4244(((int *)p), func_021D4808, 0x314);
        }
    }
}








void func_021D48F0(int *a)
{
    if (GFL_NET_GetRunState() == 0) {
        func_021D4244(a, func_021D4864, 0x31d);
        return;
    }
    if (GFL_NET_HANDLE_GetNegotiationNum() != 0 && GFL_NET_HANDLE_CheckNegotiation() != 0)
        func_021D4244(a, func_021D4864, 0x322);
}








void func_021D4930(struct GtsnegoDispCtx *a)
{
    if (func_021D7AF4((char *)(*(int *)&a->f40)) != 0) {
        if (a->f14 > 0) {
            a->f14 = a->f14 - 1;
            return;
        }
        if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
            if (GFL_NET_HANDLE_CheckNegotiation() != 0) {
                a->f14 = 0xb4;
                func_021D4244(((int *)a), func_021D4864, 0x33f);
                return;
            }
        } else {
            a->f14 = 0xb4;
            func_021D4244(((int *)a), func_021D48F0, 0x344);
        }
    }
}









/*
 * Blocker resolved: the call to GFL_NET_STATE_GetWifiState (site +0050) was the only
 *          unresolved relocation.  It is an unlabelled ARM leaf in the ARM9
 *          image; it was matched in arm9 (src/matched/GFL_NET_STATE_GetWifiState.c, shard
 *          pkt_0203C3EC) so `attest_matched` now resolves the BL field.  All
 *          17 relocations and all 152 bytes agree.
 */
void func_021D4988(struct GtsnegoDispCtx *a)
{
    func_021D7C10((char *)(*(int *)&a->f40));
    if (KEY_GetTrg() == 2) {
        func_021D8638((unsigned char *)(*(int *)&a->f40));
        if (GFL_NET_GetRunState() != 0)
            GFL_NET_STATE_WifiDisconnect(1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021D4244(a, func_021D4FF4, 0x360);
    }
    if (GFL_NET_GetRunState() == 0) {
        if (KEY_GetTrg() != 1)
            return;
    } else {
        if (GFL_NET_STATE_GetWifiState() != 1)
            return;
        GFL_NET_SetAutoExit(1);
        GFL_NET_SetLoginOption(1);
    }
    func_021D7B38((char *)(*(int *)&a->f40));
    func_021D7A74((u8 *)(*(int *)&a->f40), 0x10);
    a->f14 = 0xb4;
    func_021D8648((u8 *)(*(int *)&a->f40));
    func_021D4244(a, func_021D4930, 0x377);
}








int func_021D4A20(int a, u8 *p)
{
    int mode;
    int x;
    int y;
    int score = -1;
    int id;
    int group;
    int i;
    u8 *q = *(u8 * *)&((struct GtsnegoDispCtx *)p)->f48;
    mode = func_0216CB30(a, (int)(p + 0x76), -1);
    x = func_0216CB30(a, (int)(p + 0x8e), -1);
    y = func_0216CB30(a, (int)(p + 0x82), -1);
    id = func_0216CB30(a, (int)(p + 0x5e), 0);
    group = func_0216CB30(a, (int)(p + 0xb2), 0);
    if (I(0x138) == 1) {
        if (mode == 4) {
            if (I(0x148) == -1) {
                if (func_02009E74(func_02009EC8(((struct GtsnegoDispCtx *)p)->f30), id) != 0)
                    score = 100;
            } else {
                if (I(0x18) == id) score = 100;
            }
        } else {
            if (group == func_02008530((const struct Sub0200852CObj *)func_02012944((void *)(((struct GtsnegoDispCtx2 *)q)->f0)))) {
                if (I(0x148) == -1) {
                    if (func_02009E74(func_02009EC8(((struct GtsnegoDispCtx *)p)->f30), id) != 0)
                        score = 100;
                } else {
                    if (I(0x18) == id) score = 100;
                }
            }
        }
    } else {
        if (I(0x144) == mode) {
            if (I(0x13c) == x) score += 20;
            else if (I(0x13c) == 0 || x == 0) score += 10;
            else score -= 40;
            if (I(0x140) == y) score += 20;
            else if (y == 0 || I(0x140) == 0) score += 10;
            else score -= 40;
            for (i = 0; i < 100; i++) {
                if (id == *(int *)(q + i * 4 + 0x1c) && id != 0) {
                    score = 0;
                    break;
                }
            }
        }
    }
    return score;
}








void func_021D4B48(u8 *p)
{
    u32 values[8];
    void *q;
    int i;
    Record_021D47D4 *r;
    if (func_021D7AF4(((struct GtsnegoDispCtx *)p)->f40)) {
        if (GFL_NET_GetRunState() == 0) {
            func_021D8590(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f40, (int)func_021D505C, (int)p);
            func_021D4244(((int *)p), func_021D4988, 0x3ea);
            return;
        }
        GFL_NET_SetWaitMode(0);
        func_02009CA8((void *)(((struct GtsnegoDispCtx *)p)->f44), values);
        values[0] = ((struct GtsnegoDispCtx *)p)->f14C;
        values[1] = *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f138;
        values[2] = *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f144;
        values[3] = *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f13C;
        values[4] = *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f140;
        values[5] = 0x20015;
        values[6] = 1;
        values[7] = 0;
        if (*(unsigned int *)&((struct GtsnegoDispCtx *)p)->f138 == 1) {
            if (((struct GtsnegoDispCtx *)p)->f148 == -1)
                values[2] = 4;
            else {
                q = func_021D4F70(((struct GtsnegoDispCtx *)p)->f2C, ((struct GtsnegoDispCtx *)p)->f148);
                values[7] = func_02008530(q);
                ((struct GtsnegoDispCtx *)p)->f18 = func_02008530(q);
            }
        }
        for (i = 0; i < 8; i++) {
            r = (Record_021D47D4 *)(p + 0x58) + i;
            func_02082D44(d_021D8B40 + i, &r->detail, 2);
            r->value = values[i];
            r->kind = func_0216C8DC(r->kind, (char *)(&r->detail), (int *)r);
        }
        func_0208D7E0((char *)p + 0xb8, d_021D8B50, *(unsigned int *)&((struct GtsnegoDispCtx *)p)->f138, 1);
        if (DWC_RAP_StartMatchWithFilter((int)p + 0xb8, 2, (int)func_021D4A20, (int)p)) {
            GFL_NET_STATE_WifiEnterFriendMatch();
            DWC_RAP_SetVchatEnabled(0);
            func_021D8590(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f40, (int)func_021D505C, (int)p);
            func_021D4244(((int *)p), func_021D4988, 0x41d);
            return;
        }
        GFL_NET_STATE_SetError(0, 0, 0, 0x3f1);
    }
}







void func_021D4C98(void *p,int n,u8 *s) { if (n==0 && ((struct GtsnegoDispCtx *)s)->f4) { func_021D69F4(*(u8 * *)&((struct GtsnegoDispCtx *)s)->f3C,((struct GtsnegoDispCtx *)s)->f34,9); func_020355D8(1); if ((*(int (**)(void *,void *))(s+4))(p,s)==0) return; } }







void func_021D4CC4(struct GtsnegoDispCtx *p)
{
    if (APP_TASKMENU_WIN_IsFinish(p->f34)) {
        APP_TASKMENU_WIN_Delete(p->f34);
        *(int *)&p->f34 = 0;
        func_02041B6C(5);
        func_021D79F4(p->f40, 14);
        func_021D7550(p->f3C);
        func_021D8520(p->f40, 13);
        func_021D63F4(p->f3C, 1, 2);
        ((struct GtsnegoDispCtx_f48 *)p->f48)->f1B0 = 2;
        func_021D69F4(p->f3C, 0, 9);
        func_021D4244(((int *)p), func_021D4B48, 0x460);
    }
}







void func_021D4D28(u8 *p)
{
    int changed = 0;
    int done = 0;
    u8 *q = (u8 *)func_021D6988(((struct GtsnegoDispCtx *)p)->f3C);
    if (func_021D7AF4(((struct GtsnegoDispCtx *)p)->f40)) {
        if (TOUCHBAR_IsBusy(q) == 0) {
            func_021D7C10((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40));
            if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
                func_021D69F4(((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f34, ((struct GtsnegoDispCtx *)p)->f160);
                func_020355D8(changed);
                return;
            }
            if (KEY_GetTrg() == 0x20) func_021D4474(0, (char *)p);
            if (KEY_GetTrg() == 0x10) func_021D4474(1, (char *)p);
            if (KEY_GetTrg() == 0x40) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed = 1;
                if (((struct GtsnegoDispCtx *)p)->f160 != 2) --((struct GtsnegoDispCtx *)p)->f160;
            }
            if (KEY_GetTrg() == 0x80) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed = 1;
                if (((struct GtsnegoDispCtx *)p)->f160 != 5) ++((struct GtsnegoDispCtx *)p)->f160;
            }
            if (KEY_GetTrg() == 1 && ((struct GtsnegoDispCtx *)p)->f160 == 5) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                func_021D6A9C(((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f160);
                APP_TASKMENU_WIN_SetDecide(((struct GtsnegoDispCtx *)p)->f34, 1);
                func_021D4244(((int *)p), func_021D4CC4, 0x4ca);
                return;
            }
            if (changed)
                func_021D69F4(((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f34, ((struct GtsnegoDispCtx *)p)->f160);
            if (TOUCHPANEL_HitTrg(d_021D88D0) == 0) {
                func_020355D8(1);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                APP_TASKMENU_WIN_SetDecide(((struct GtsnegoDispCtx *)p)->f34, 1);
                func_021D4244(((int *)p), func_021D4CC4, 0x4f2);
                return;
            }
        }
        TOUCHBAR_Update((struct S *)func_021D6988(((struct GtsnegoDispCtx *)p)->f3C));
        if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)func_021D6988(((struct GtsnegoDispCtx *)p)->f3C)) == 1) done = 1;
        if (done) {
            int zero = 0;
            func_02040588(4, 0);
            func_021D69F4(((struct GtsnegoDispCtx *)p)->f3C, ((struct GtsnegoDispCtx *)p)->f34, 9);
            func_021D7EC4(((struct GtsnegoDispCtx *)p)->f40);
            func_021D68C4(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f3C);
            APP_TASKMENU_WIN_Delete(((struct GtsnegoDispCtx *)p)->f34);
            *(int *)&((struct GtsnegoDispCtx *)p)->f34 = zero;
            func_02041B6C(5);
            func_021D4244(((int *)p), func_021D588C, 0x50b);
        }
    }
}







void func_021D4EC0(u8 *p)
{
    ((struct GtsnegoDispCtx *)p)->f138 = 0;
    TOUCHBAR_SetAllButtonsVisible((u8 *)func_021D6988(((struct GtsnegoDispCtx *)p)->f3C), 1);
    func_021D7D3C(((struct GtsnegoDispCtx *)p)->f40);
    func_021D6814(((struct GtsnegoDispCtx *)p)->f3C);
    *(void * *)&((struct GtsnegoDispCtx *)p)->f4 = func_021D444C;
    func_021D7DC8(((struct GtsnegoDispCtx *)p)->f40, (int)func_021D4C98, (int)p, ((struct GtsnegoDispCtx *)p)->f144, ((struct GtsnegoDispCtx *)p)->f13C, ((struct GtsnegoDispCtx *)p)->f140);
    func_021D79F4(((struct GtsnegoDispCtx *)p)->f40, 20);
    ((struct GtsnegoDispCtx *)p)->f34 = func_021D7ECC(((struct GtsnegoDispCtx *)p)->f40, 18);
    if (func_020355C4() == 0) {
        func_021D69F4(((struct GtsnegoDispCtx *)p)->f3C, 0, ((struct GtsnegoDispCtx *)p)->f160);
        if (((struct GtsnegoDispCtx *)p)->f160 == 5)
            APP_TASKMENU_WIN_SetActive(((struct GtsnegoDispCtx *)p)->f34, 1);
    } else {
        func_021D69F4(((struct GtsnegoDispCtx *)p)->f3C, 0, 9);
    }
    func_02041B6C(6);
    func_021D4244(((int *)p), func_021D4D28, 0x537);
}







void *func_021D4F70(void **p,int i) { int n; n=func_02009E8C(GAME_DATA_GetSaveBlock1F(p)); if (i>=n || i<0) return 0; return func_02009E54(GAME_DATA_GetSaveBlock1F(p),i); }






void *func_021D4F98(void **p,int i) { int n; n=func_02009E8C(GAME_DATA_GetSaveBlock1F(p)); if (i<0) i=0; if (i>=n) i=n-1; return func_02009E54(GAME_DATA_GetSaveBlock1F(p),i); }







/*
 * Addresses are Black-image addresses.
 */
void func_021D4FC0(u8 *p)
{
    func_021D588C(p);
    BG_SYS_SetSubVisiblePlanes(0x1f);
}









void func_021D4FD0(struct GtsnegoDispCtx *p) { func_021D761C(*(u8 * *)&p->f3C); func_021D883C(*(char * *)&p->f40); func_021D4244(p, func_021D4FC0, 0x5c5); }










void func_021D4FF4(struct GtsnegoDispCtx *p)
{
    if (func_021D8664(p->f40)) {
        BG_SYS_SetSubVisiblePlanes(8);
        func_021D7EC4(p->f40);
        func_021D68C4(p->f3C);
        func_021D63F4(p->f3C, 0, 0);
        func_021D69F4(p->f3C, 0, 9);
        func_02041B6C(5);
        if (p->f138 == 1) {
            func_02040588(4, 0);
            func_021D6D94(p->f3C);
        }
        func_021D4244(((int *)p), func_021D4FD0, 0x5dd);
    }
}










void func_021D505C(int a, int b, int *p)
{
    if (b == 0 && *(void **)p == func_021D4988) {
        func_021D8638(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f40);
        GFL_NET_STATE_WifiDisconnect(1);
        func_020355D8(1);
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021D4244(p, func_021D4FF4, 0x5f5);
    }
}








void func_021D50A0(struct GtsnegoDispCtx *p) { p->f34=func_021D7ECC(*(char * *)&p->f40,44); func_021D4244(p, func_021D5334, 0x5ff); }







void func_021D50C4(struct GtsnegoDispCtx *p)
{
    int state;
    if (APP_TASKMENU_IsFinish(p->f38)) {
        int zero;
        state = APP_TASKMENU_GetCursorPos(p->f38);
        func_021D8418(*(int *)&p->f38);
        zero = 0;
        *(int *)&p->f38 = zero;
        TOUCHBAR_SetButtonVisible((unsigned char *)func_021D6988(p->f3C), 1, 1);
        switch (state) {
        case 0:
            func_021D79F4(p->f40, 0xe);
            func_021D7550(p->f3C);
            func_021D8520(p->f40, 0xd);
            p->f144 = zero;
            p->f13C = zero;
            p->f140 = zero;
            ((struct GtsnegoDispCtx_f48 *)p->f48)->f1B0 = 3;
            func_021D4244(((int *)p), func_021D4B48, 0x614);
            return;
        case 1:
            func_021D63F4(p->f3C, zero, zero);
            func_021D79F4(p->f40, 0x13);
            if (func_020355C4() == 0)
                func_021D69F4(p->f3C, 0, p->f164);
            else
                func_021D69F4(p->f3C, 0, 9);
            func_021D6FD8(p->f3C, 1);
            func_021D4244(((int *)p), func_021D50A0, 0x620);
            break;
        }
    }
}






void func_021D5188(struct GtsnegoDispCtx *p)
{
    if (func_021D7AF4(p->f40)) {
        TOUCHBAR_SetButtonVisible((unsigned char *)func_021D6988(p->f3C), 1, 0);
        p->f38 = func_021D8358(p->f40, 1);
        func_021D63F4(p->f3C, 1, 1);
        func_021D6FD8(p->f3C, 0);
        func_021D4244(((int *)p), func_021D50C4, 0x634);
    }
}









/*
 * lever: The caller has no halfword truncation before func_021D79F4;
 * widen its copied u16 argument to int. Explicit calls in both branches
 * hoist the shared p+64 load; a ternary places it after the selection.
 */
void func_021D51D4(struct GtsnegoDispCtx *p) { if (p->f148==-1) func_021D79F4(*(u8 * *)&p->f40,45); else func_021D79F4(*(u8 * *)&p->f40,31); func_021D4244(p, func_021D5188, 0x646); }









void func_021D5208(struct GtsnegoDispCtx *p) { func_02040588(4,0); func_021D6D94(*(u8 * *)&p->f3C); func_021D4244(p, func_021D588C, 0x64e); }









/*
 * extent: two zero padding bytes at 0x021D5282 precede labelled 0x021D5284.
 */
int func_021D5230(u8 *p)
{
    int result = func_021D6E50(((struct GtsnegoDispCtx *)p)->f3C, (int *)(p + 0x150));
    switch (result) {
    case 0: break;
    case 1:
        if (((struct GtsnegoDispCtx *)p)->f164 != 6)
            (((struct GtsnegoDispCtx *)p)->f164)--;
        break;
    case 2: {
        int index;
        func_021D6FF8(((struct GtsnegoDispCtx *)p)->f3C, 1);
        index = ((struct GtsnegoDispCtx *)p)->f158 - 1;
        if (index >= 0)
            func_021D82D8(((struct GtsnegoDispCtx *)p)->f40, ((struct GtsnegoDispCtx *)p)->f2C, index);
        break;
    }
    }
    return result;
}









int func_021D5284(u8 *p)
{
    int result = func_021D6E1C(((struct GtsnegoDispCtx *)p)->f3C, (int *)(p + 0x150));
    switch (result) {
    case 0: break;
    case 1:
        if (((struct GtsnegoDispCtx *)p)->f164 != 8)
            (((struct GtsnegoDispCtx *)p)->f164)++;
        break;
    case 2:
        func_021D6FF8(((struct GtsnegoDispCtx *)p)->f3C, 2);
        func_021D822C(((struct GtsnegoDispCtx *)p)->f40, ((struct GtsnegoDispCtx *)p)->f2C, ((struct GtsnegoDispCtx *)p)->f158 + 2);
        break;
    }
    return result;
}









void func_021D52D4(struct GtsnegoDispCtx *p)
{
    if (APP_TASKMENU_WIN_IsFinish(p->f34)) {
        APP_TASKMENU_WIN_Delete(p->f34);
        *(int *)&p->f34 = 0;
        p->f148 = -1;
        func_021D69F4(p->f3C, 0, 9);
        func_02041B6C(5);
        func_021D4244(((int *)p), func_021D51D4, 0x6ba);
    }
}










void func_021D5318(u8 *p)
{
    if (((struct GtsnegoDispCtx *)p)->f34) {
        APP_TASKMENU_WIN_Delete(((struct GtsnegoDispCtx *)p)->f34);
        func_02041B6C(5);
        *(u32 *)&((struct GtsnegoDispCtx *)p)->f34 = 0;
    }
}









void func_021D5334(Ctx *p)
{
    int out;
    int r;
    int acc = 0;
    int i;
    int sel;
    int x, y;
    out = 0;
    r = func_021D6988(p->f3C);
    if (func_021D7AF4(p->f40) == 0)
        return;
    if (TOUCHBAR_IsBusy((u8 *)r) != 0)
        goto end;
    r = func_021D702C(p->f3C, &out);
    if (out == 1) {
        func_021D6D10(p->f3C, p->f2C, p->f158 - 2);
        func_021D82F8(p->f40);
        func_021D7260(p->f3C, func_021D4F98(p->f2C, p->f158 - 2));
    } else if (out == 2) {
        func_021D6D10(p->f3C, p->f2C, p->f158 - 2);
        func_021D824C(p->f40);
        func_021D7220(p->f3C, func_021D4F98(p->f2C, p->f158 + 3));
    }
    if (r != 0)
        return;
    if (func_020355C4() == 1 && KEY_GetTrg() != 0) {
        func_021D69F4(p->f3C, 0, p->f164);
        func_020355D8(0);
        return;
    }
    if (KEY_GetRepeat() == 0x100) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            r = func_021D5284((u8 *)p);
            acc |= r;
            func_021D7020(p->f3C);
            if (r == 0)
                break;
            if (r == 1) {
                i--;
            } else {
                func_021D70C8(p->f3C, 1);
                func_021D6D10(p->f3C, p->f2C, p->f158 - 2);
                func_021D824C(p->f40);
                func_021D7220(p->f3C, func_021D4F98(p->f2C, p->f158 + 3));
                func_021D69F4(p->f3C, 0, p->f164);
            }
        }
    }
    if (KEY_GetRepeat() == 0x200) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            r = func_021D5230((u8 *)p);
            acc |= r;
            func_021D7020(p->f3C);
            if (r == 0)
                break;
            if (r == 1) {
                i--;
            } else {
                func_021D69F4(p->f3C, 0, p->f164);
                func_021D70C8(p->f3C, 0);
                func_021D6D10(p->f3C, p->f2C, p->f158 - 2);
                func_021D82F8(p->f40);
                func_021D7260(p->f3C, func_021D4F98(p->f2C, p->f158 - 2));
            }
        }
    }
    if (KEY_GetRepeat() == 0x40)
        acc = func_021D5230((u8 *)p);
    if (KEY_GetRepeat() == 0x80)
        acc = func_021D5284((u8 *)p);
    if (acc != 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021D733C(p->f3C, p->f158 + p->f164 - 6, p->f150);
        func_021D69F4(p->f3C, 0, p->f164);
        return;
    }
    if (KEY_GetTrg() == 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        func_021D6A9C(p->f3C, p->f164);
        p->f148 = p->f158 + p->f164 - 6;
        func_021D5318((u8 *)p);
        func_021D4244(((int *)p), func_021D51D4, 0x760);
        return;
    }
    if (KEY_GetTrg() == 8) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        APP_TASKMENU_WIN_SetDecide(p->f34, 1);
        func_021D4244(((int *)p), func_021D52D4, 0x766);
        return;
    }
    sel = TOUCHPANEL_HitTrg(d_021D88D8);
    switch (sel) {
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        APP_TASKMENU_WIN_SetDecide(p->f34, 1);
        func_021D4244(((int *)p), func_021D52D4, 0x770);
        return;
    case 2:
        if (p->f150 < 3)
            break;
    case 1:
        if (p->f150 < 2)
            break;
    case 0:
        func_020355D8(1);
        p->f164 = sel + 6;
        func_021D69F4(p->f3C, 0, p->f164);
        func_021D6A9C(p->f3C, p->f164);
        p->f148 = p->f158 + p->f164 - 6;
        func_021D6E70(p->f3C, &p->f150, sel);
        func_021D733C(p->f3C, p->f158 + p->f164 - 6, p->f150);
        GFL_USE_PlaySeDefaultVolume(0x54C);
        func_021D5318((u8 *)p);
        func_021D4244(((int *)p), func_021D51D4, 0x78B);
        return;
    }
    if (TOUCHPANEL_HitCont(d_021D88C8) != 0)
        goto end;
    if (TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y)) == 1) {
        r = func_021D7374((char *)p->f3C, y, p->f150);
        if (p->f158 != r) {
            p->f158 = r;
            func_021D82A8(p->f40, p->f2C, r - 2);
            func_021D72A0(p->f3C, p->f2C, p->f158 - 2);
            func_021D6D10(p->f3C, p->f2C, p->f158 - 2);
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    }
    return;
end:
    TOUCHBAR_Update((struct S *)func_021D6988(p->f3C));
    if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)func_021D6988(p->f3C)) == 1) {
        func_02040588(4, 0);
        func_02040588(6, 0);
        func_021D5318((u8 *)p);
        func_021D69F4(p->f3C, p->f34, 9);
        func_021D6D48(p->f3C);
        func_021D7D3C(p->f40);
        func_021D4244(((int *)p), func_021D5208, 0x7AD);
    }
}








void func_021D5758(struct GtsnegoDispCtx *p)
{
    if (func_021D7AF4(p->f40)) {
        if (--p->f14 <= 0) {
            func_021D79F4(p->f40, 0x20);
            TOUCHBAR_SetAllButtonsVisible((u8 *)func_021D6988(p->f3C), 1);
            func_021D4244(((int *)p), func_021D5AD4, 0x7c7);
            if (func_020355C4() == 0)
                func_021D69F4(p->f3C, 0, p->f15C);
        }
    }
}








void func_021D57B0(struct GtsnegoDispCtx *p)
{
    int flag = 1;
    int n = func_02009E8C(GAME_DATA_GetSaveBlock1F(*(void ** *)&p->f2C));
    p->f138 = flag;
    if (n == 0) {
        func_021D79F4(p->f40, 0x1d);
        p->f14 = 0x78;
        func_021D4244(((int *)p), func_021D5758, 0x7e7);
        return;
    }
    p->f150 = n;
    func_021D79F4(p->f40, 0x13);
    if (func_020355C4() == 0)
        func_021D69F4(p->f3C, 0, p->f164);
    else
        func_021D69F4(p->f3C, 0, 9);
    func_021D7D3C(p->f40);
    if (n <= 3) flag = 0;
    func_021D6BB0(*(u8 * *)&p->f3C, flag);
    func_021D81E0(*(char * *)&p->f40, p->f2C);
    func_021D82A8(p->f40, p->f2C, p->f158 - 2);
    func_021D72A0(p->f3C, p->f2C, p->f158 - 2);
    func_021D6D10(p->f3C, p->f2C, p->f158 - 2);
    p->f34 = func_021D7ECC(*(char * *)&p->f40, 0x2c);
    func_021D733C(p->f3C, p->f158 + p->f164 - 6, p->f150);
    func_021D4244(((int *)p), func_021D5334, 0x815);
}









void func_021D588C(u8 *p)
{
    func_021D70F0(((struct GtsnegoDispCtx *)p)->f3C);
    if (((struct GtsnegoDispCtx *)p)->f1B0) {
        if ((((struct GtsnegoDispCtx *)p)->f1B4)++ < 3)
            return;
        func_0200F800();
        ((struct GtsnegoDispCtx *)p)->f1B0 = 0;
    }
    if (func_020355C4() == 0)
        func_021D69F4(((struct GtsnegoDispCtx *)p)->f3C, 0, ((struct GtsnegoDispCtx *)p)->f15C);
    else
        func_021D69F4(((struct GtsnegoDispCtx *)p)->f3C, 0, 9);
    func_021D7D6C(((struct GtsnegoDispCtx *)p)->f40, (int)func_021D4C98, (int)p);
    *(void (**)(void))(p + 4) = (void (*)(void))func_021D42D8;
    if ((int)POKEPARTY_GetNonEggCount(func_02012934(((struct GtsnegoDispCtx *)p)->f2C)) < 2)
        ((struct GtsnegoDispCtx *)p)->f184 = 1;
    if (((struct GtsnegoDispCtx *)p)->f184 == 0)
        func_021D79F4(((struct GtsnegoDispCtx *)p)->f40, 0x20);
    else
        func_021D79F4(((struct GtsnegoDispCtx *)p)->f40, 0x2b);
    func_02040588(4, 1);
    func_02040588(6, 1);
    func_021D4244(p, func_021D5AD4, 0x86c);
}









int func_021D593C(u8 *p,int n) { if (func_021D6A9C(((struct GtsnegoDispCtx *)p)->f3C,n)) { TOUCHBAR_SetAllButtonsVisible((u8 *)func_021D6988((u8 *)(((struct GtsnegoDispCtx *)p)->f3C)),0); GFL_USE_PlaySeDefaultVolume(1356); return n; } return 9; }










int func_021D596C(struct GtsnegoDispCtx *p, int x)
{
    if (func_021D6AC0(p->f3C) == 0)
        x = 9;
    return x;
}









void func_021D5980(struct GtsnegoDispCtx *p)
{
    int state = func_021D596C(p, p->f15C);
    if (state == 0) {
        func_021D69F4(p->f3C, p->f34, 9);
        func_021D7D3C(*(char * *)&p->f40);
        func_02041B6C(6);
        func_021D4244(p, func_021D4EC0, 0x8a3);
        return;
    }
    if (state == 1) {
        func_021D69F4(p->f3C, p->f34, 9);
        func_021D4244(p, func_021D57B0, 0x8a7);
    }
}









void func_021D59E0(struct GtsnegoDispCtx *p)
{
    int state;
    if (APP_TASKMENU_IsFinish(p->f38)) {
        state = APP_TASKMENU_GetCursorPos(p->f38);
        func_021D8418(*(int *)&p->f38);
        *(int *)&p->f38 = 0;
        switch (state) {
        case 0:
            ((struct GtsnegoDispCtx_f48 *)p->f48)->f1B0 = 1;
            p->f14 = 0;
            func_021D4244(p, func_021D44AC, 0x8b5);
            return;
        case 1:
            if (p->f184 == 0)
                func_021D79F4(p->f40, 0x20);
            else
                func_021D79F4(p->f40, 0x2b);
            if (func_020355C4() == 0)
                func_021D69F4(p->f3C, 0, p->f15C);
            TOUCHBAR_SetButtonVisible((unsigned char *)func_021D6988(p->f3C), 1, 1);
            func_021D63F4(p->f3C, 0, 0);
            func_021D4244(p, func_021D5AD4, 0x8c3);
            break;
        }
    }
}









void func_021D5A84(struct GtsnegoDispCtx *p)
{
    if (func_021D7AF4(p->f40)) {
        TOUCHBAR_SetButtonVisible((unsigned char *)func_021D6988(p->f3C), 1, 0);
        p->f38 = func_021D7B60(p->f40, 1);
        func_021D63F4(p->f3C, 1, 0);
        func_021D69F4(p->f3C, 0, 9);
        func_021D4244(p, func_021D59E0, 0x8d4);
    }
}









void func_021D5AD4(u8 *p)
{
    int changed = 0;
    u8 *q = (u8 *)func_021D6988(((struct GtsnegoDispCtx *)p)->f3C);
    if (func_021D7AF4(((struct GtsnegoDispCtx *)p)->f40)) {
        if (TOUCHBAR_IsBusy(q) == 0) {
            if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
                func_021D69F4(((struct GtsnegoDispCtx *)p)->f3C, 0, ((struct GtsnegoDispCtx *)p)->f15C);
                func_020355D8(changed);
                return;
            }
            if (KEY_GetTrg() == 1) {
                if (((struct GtsnegoDispCtx *)p)->f184 == 0) {
                    func_021D593C(p, ((struct GtsnegoDispCtx *)p)->f15C);
                    func_021D4244(p, func_021D5980, 0x8f4);
                    return;
                }
                GFL_USE_PlaySeDefaultVolume(0x551);
            }
            if (KEY_GetTrg() == 0x40) {
                changed = 1;
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((struct GtsnegoDispCtx *)p)->f15C = 0;
            }
            if (KEY_GetTrg() == 0x80) {
                changed = 1;
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((struct GtsnegoDispCtx *)p)->f15C = 1;
            }
            if (changed)
                func_021D69F4(((struct GtsnegoDispCtx *)p)->f3C, 0, ((struct GtsnegoDispCtx *)p)->f15C);
            func_021D7C10((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40));
        }
        TOUCHBAR_Update((struct S *)func_021D6988(((struct GtsnegoDispCtx *)p)->f3C));
        if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)func_021D6988(((struct GtsnegoDispCtx *)p)->f3C)) == 1) {
            ((struct GtsnegoDispCtx *)p)->f14 = 1;
            func_021D79F4(((struct GtsnegoDispCtx *)p)->f40, 0x2a);
            if (func_020355C4() == 1)
                func_021D69F4(((struct GtsnegoDispCtx *)p)->f3C, 0, 9);
            func_021D4244(p, func_021D5A84, 0x916);
        }
    }
}









void func_021D5BEC(u8 *p)
{
    if (((struct GtsnegoDispCtx_f48 *)((struct GtsnegoDispCtx *)p)->f48)->f1B0 != 1) {
        int zero = 0;
        GFL_NET_SetAutoExit(0);
        GFL_NET_SetLoginOption(0);
        func_021D846C(*(u8 * *)&((struct GtsnegoDispCtx *)p)->f40);
        func_021D63F4(((struct GtsnegoDispCtx *)p)->f3C, 0, 0);
        func_02040588(4, 0);
        func_021D761C(((struct GtsnegoDispCtx *)p)->f3C);
        func_021D7B38((char *)(*(int *)&((struct GtsnegoDispCtx *)p)->f40));
        func_021D883C(*(char * *)&((struct GtsnegoDispCtx *)p)->f40);
        func_021D69F4(((struct GtsnegoDispCtx *)p)->f3C, 0, 9);
        *(int *)&((struct GtsnegoDispCtx *)p)->f1B0 = 1;
        *(int *)&((struct GtsnegoDispCtx *)p)->f1B4 = zero;
        ((struct GtsnegoDispCtx_f48 *)((struct GtsnegoDispCtx *)p)->f48)->f1B0 = 1;
        func_021D4244(p, func_021D588C, 0x937);
    }
}








/*
 * volatile: hardware halfword registers written at 0x021D5C78 and 0x021D5C7E.
 * prototype: 0203064C r2 explicitly loaded despite two-arg definition;
 * 0203159C r0 allocation result used despite void matched definition.
 */
int func_021D5C60(void *a, int unused, u8 *q)
{
    u8 *p;
    int zero = 0;
    GFL_HEAP_CreateChildHeap(1, 0x1f, 0x38000);
    *(volatile u16 *)0x04000050 = zero;
    *(volatile u16 *)0x04001050 = zero;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    p = PROCSYS_AllocProcWork(a, 0x1b8, 0x1f);
    MI_CpuFill8(p, 0, 0x1b8);
    ((struct GtsnegoDispCtx *)p)->fC = 0x1f;
    *(u8 * *)&((struct GtsnegoDispCtx *)p)->f48 = q;
    ((struct GtsnegoDispCtx *)p)->f3C = func_021D5E88(((struct GtsnegoDispCtx *)p)->fC, ((struct GtsnegoDispCtx *)q)->f0);
    ((struct GtsnegoDispCtx *)p)->f40 = func_021D7724(((struct GtsnegoDispCtx *)p)->fC, 0x28);
    ((struct GtsnegoDispCtx *)p)->f2C = ((struct GtsnegoDispCtx *)q)->f0;
    ((struct GtsnegoDispCtx *)p)->f30 = GAME_DATA_GetSaveControl(((struct GtsnegoDispCtx *)q)->f0);
    ((struct GtsnegoDispCtx *)p)->f44 = func_0201283C(((struct GtsnegoDispCtx *)q)->f0);
    ((struct GtsnegoDispCtx_f48 *)((struct GtsnegoDispCtx *)p)->f48)->f1B0 = 1;
    ((struct GtsnegoDispCtx *)p)->f15C = zero;
    ((struct GtsnegoDispCtx *)p)->f160 = 2;
    ((struct GtsnegoDispCtx *)p)->f164 = 6;
    ((struct GtsnegoDispCtx *)p)->f14C = func_02008530((const struct Sub0200852CObj *)func_02012944(((struct GtsnegoDispCtx *)q)->f0));
    if (GFL_NET_GetRunState())
        GFL_NET_COMMAND_AddCommandTable(0x2200, (u32)d_021D88EC, 3, (u32)p);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, ((struct GtsnegoDispCtx *)p)->fC);
    GFL_USE_CancelChangeAndPlayBgm(0x486, 0xffff);
    GFL_NET_RestartWithDefaultTimeout(1, ((struct GtsnegoDispCtx *)p)->fC);
    func_0200F7E8(1);
    func_021D4244(p, func_021D588C, 0x96a);
    return 1;
}








int func_021D5D74(int a, int b, int c, u8 *p)
{
    void (*callback)(u8 *) = *(void (**)(u8 *))p;
    int result = 1;
    if (callback) {
        if (func_0200FB24() == 0)
            callback(p);
        result = 0;
    }
    if (((struct GtsnegoDispCtx *)p)->f34) {
        void *q = (void *)func_021D6988(((struct GtsnegoDispCtx *)p)->f3C);
        if (q == 0 || TOUCHBAR_IsBusy(q) == 0)
            APP_TASKMENU_WIN_Update(((struct GtsnegoDispCtx *)p)->f34);
    }
    if (((struct GtsnegoDispCtx *)p)->f38)
        APP_TASKMENU_UpdateMenu(((struct GtsnegoDispCtx *)p)->f38);
    func_021D5F98(((struct GtsnegoDispCtx *)p)->f3C);
    func_021D7858(((struct GtsnegoDispCtx *)p)->f40);
    if (GFL_NET_GetRunState()) {
        if (func_0200FB24()) {
            switch (DWC_RAPCOMMON_HandleNetError(1, 1)) {
            case 0: break;
            case 1:
            case 4:
                func_021D5BEC(p);
                break;
            case 2:
                ((struct GtsnegoDispCtx_f48 *)((struct GtsnegoDispCtx *)p)->f48)->f1B0 = 0;
                result = 1;
                WIPE_SetBrightnessFadeOut(0, 0);
                WIPE_SetBrightnessFadeOut(1, 0);
                break;
            case 3:
                func_0200F7DC();
                break;
            }
        }
    } else if (func_0200FB24()) {
        result = 1;
    }
    return result;
}








/*
 * trailing: 2-byte zero alignment padding at 0x021D5E86.
 */
int func_021D5E30(void *p, int a, int b, struct GtsnegoDispCtx *q)
{
    func_0200F7F4();
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GFL_NET_GetRunState()) GFL_NET_COMMAND_DeleteCommandTable(0x2200);
    if (q->f34) APP_TASKMENU_WIN_Delete(q->f34);
    if (q->f38) APP_TASKMENU_CloseMenu(q->f38);
    func_021D7898(q->f40);
    func_021D5FC4(q->f3C);
    func_020315D4(p);
    func_020306F0(31);
    return 1;
}








/*
 * interface: arg is a full-word pointer, as matched caller 021D5C60 supplies.
 * interface: 021D6100 gets p explicitly loaded despite its legacy void(void).
 * volatile: hardware 0x04001000 read/written at 0x021D5EC4/0x021D5ECA.
 */
u8 *func_021D5E88(u32 heap,void *arg)
{
    u8 *p;
    p=func_02030734(heap,0x164,1,d_021D8BC8,258);
    ((struct GtsnegoMsgCtx *)p)->fF4=heap;
    ((struct GtsnegoMsgCtx *)p)->f118=arg;
    func_02034AC4((int)ov_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_0204363C(1);
    *(volatile u32 *)0x04001000|=0x10000;
    func_0207D46C();
    func_0203F8F4(((struct GtsnegoMsgCtx *)p)->fF4);
    CLACT_InitSystem((const struct Cfg *)d_021D8974,(u32)(&d_021D8B98),((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f10=CLACT_CreateUnit(64,0,((struct GtsnegoMsgCtx *)p)->fF4);
    BG_SYS_SetVramBanks(&d_021D8B98);
    func_0203FC28(&d_021D8B60);
    func_021D6100(p);
    func_021D6568(p);
    ((struct GtsnegoMsgCtx *)p)->f14=func_020056A0(func_021D6530,p,0);
    ((struct GtsnegoMsgCtx *)p)->f124=func_02030734(((struct GtsnegoMsgCtx *)p)->fF4,0x200,0,d_021D8BC8,280);
    ((struct GtsnegoMsgCtx *)p)->f128=func_02030734(((struct GtsnegoMsgCtx *)p)->fF4,0x200,0,d_021D8BC8,281);
    func_021D69A0(p);
    func_021D692C(p,0);
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(31);
    return p;
}








void func_021D5F98(struct GtsnegoMsgCtx *p){CLACT_DrawSystem();if(p->fF8)BLINK_PALANM_Update(p->fF8);if(p->fFC)BLINK_PALANM_Update(p->fFC);func_021D75F4((char *)p);}








void func_021D5FC4(u8 *p)
{
    int i;
    CLACT_DeleteActor(((struct GtsnegoMsgCtx *)p)->f134);
    func_021D698C(p);
    func_021D6ED8(p);
    func_021D6C64(p);
    func_020307B0(((struct GtsnegoMsgCtx *)p)->f124);
    func_020307B0(((struct GtsnegoMsgCtx *)p)->f128);
    func_021D6B5C(p);
    CLACT_ReleasePalette((u32)(((struct GtsnegoMsgCtx *)p)->f18));
    CLACT_ReleasePalette((u32)(((struct GtsnegoMsgCtx *)p)->f1C));
    CLACT_ReleaseCharacter((u32)(*(void * *)&((struct GtsnegoMsgCtx *)p)->f28));
    CLACT_ReleaseCharacter((u32)(((struct GtsnegoMsgCtx *)p)->f2C));
    CLACT_ReleaseCellAnim((u32)(*(void * *)&((struct GtsnegoMsgCtx *)p)->f74));
    CLACT_ReleaseCellAnim((u32)(((struct GtsnegoMsgCtx *)p)->f78));
    CLACT_ReleasePalette((u32)(((struct GtsnegoMsgCtx *)p)->f24));
    CLACT_ReleaseCharacter((u32)(((struct GtsnegoMsgCtx *)p)->f70));
    CLACT_ReleaseCellAnim((u32)(((struct GtsnegoMsgCtx *)p)->fBC));
    CLACT_ReleasePalette((u32)(((struct GtsnegoMsgCtx *)p)->f20));
    for(i=0;i<16;i++) {
        CLACT_ReleaseCharacter((u32)(*(void **)(p+i*4+0x30)));
        CLACT_ReleaseCellAnim((u32)(*(void **)(p+i*4+0x7c)));
    }
    func_02030EAC(((struct GtsnegoMsgCtx *)p)->f14);
    CLACT_DeleteUnit(((struct GtsnegoMsgCtx *)p)->f10);
    CLACT_ExitSystem();
    func_0202EA20(((struct GtsnegoMsgCtx *)p)->fF8);
    func_0202EA20(((struct GtsnegoMsgCtx *)p)->fFC);
    func_0203FB44(7,(u16)(*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f8),(u16)(*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f8>>16));
    func_0203FB44(4,(u16)(((struct GtsnegoMsgCtx *)p)->f0),(u16)(((struct GtsnegoMsgCtx *)p)->f0>>16));
    func_0203FB44(0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),(u16)(((struct GtsnegoMsgCtx *)p)->f4>>16));
    func_02040DA8(1,1,0);
    func_02040DA8(5,1,0);
    func_02040DA8(6,1,0);
    func_02040588(5,0);
    for(i=0;i<=7;i++) func_020403F4((u8)i);
    func_0203F9B4();
    func_020307B0(p);
    func_02034A5C((int)ov_id);
}









u32 func_021D60FC(struct GtsnegoDispCtx *p){return p->f10;}









/*
 * BG-layer init: eight copies of the const template table at 0x021D89B0
 * (index order 0,5,1,2,3,4,6,7) passed to func_0203FCA0, each followed by
 * its layer enable / fill sequence.  The local array is written high-to-low
 * (b[7] first) because the original places the first-used slot at the top of
 * the frame.
 */
void func_021D6100(u8 *a0)
{
    struct BgTemplate b[8];

    b[7] = d_021D89B0[0];
    func_0203FCA0(0, &b[7], 0);
    func_020414AC(0);
    func_020409B4(0);
    func_02040588(0, 1);

    b[6] = d_021D89B0[5];
    func_0203FCA0(1, &b[6], 0);
    func_02040588(1, 1);
    func_02040C14(1, 0, 1, 0);
    func_02041300(1, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(1);

    b[5] = d_021D89B0[1];
    func_0203FCA0(2, &b[5], 0);
    func_02040588(2, 1);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(2);

    b[4] = d_021D89B0[2];
    func_0203FCA0(3, &b[4], 0);
    func_02040588(3, 1);
    func_02041300(3, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(3);

    b[3] = d_021D89B0[3];
    func_0203FCA0(4, &b[3], 0);
    func_02040588(4, 1);
    func_020409B4(4);

    b[2] = d_021D89B0[4];
    func_0203FCA0(5, &b[2], 0);
    func_02040588(5, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(5);

    b[1] = d_021D89B0[6];
    func_0203FCA0(6, &b[1], 0);
    func_02040588(6, 1);
    func_02040C14(6, 0, 1, 0);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(6);

    b[0] = d_021D89B0[7];
    func_0203FCA0(7, &b[0], 0);
    func_02040588(7, 1);
    func_020409B4(7);
}








void func_021D6328(struct GtsnegoMsgCtx *p,int bank,int *offset,int *size,int count)
{
    int i;
    void *obj;
    u8 *buffer;
    obj=PALANM_Create(p->fF4);
    PALANM_AllocSlotBuffers(obj,bank,0x200,p->fF4);
    PALANM_CopyHwPaletteToSlot(obj,bank,0,0x200);
    PALANM_BlendChannel(obj,bank,0,0x100,6,0);
    buffer=(u8 *)PALANM_GetTransWork(obj,bank);
    for(i=0;i<count;i++) {
        switch(bank) {
        case 3:
            func_020862F0(buffer+offset[i]*32,size[i]*32);
            func_0207E5D0(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        case 1:
            func_020862F0(buffer+offset[i]*32,size[i]*32);
            func_0207E468(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        }
    }
    PALANM_FreeSlotBuffers(obj,bank);
    PALANM_Delete(obj);
}








/*
 * lever: one-word aggregate locals preserve the early address setup and merge.
 */
void func_021D63F4(struct GtsnegoMsgCtx *p,int flag,int mode)
{
    if(flag) {
        func_02082D44((void *)0x05000600,p->f124,0x200);
        func_02082D44((void *)0x05000400,p->f128,0x200);
        switch(mode) {
        case 2: {
            Word a={0};
            Word b=d_021D8920;
            func_021D6328(p,3,&a.a,&b.a,1);
            break;
        }
        case 0: {
            Word a=d_021D891C;
            Word b=d_021D8918;
            func_021D6328(p,3,&a.a,&b.a,1);
            break;
        }
        case 1: {
            Pair a=d_021D895C;
            Pair b=d_021D896C;
            func_021D6328(p,3,&a.a,&b.a,2);
            break;
        }
        }
        switch(mode) {
        case 0: case 2: {
            Pair a=d_021D894C;
            Pair b=d_021D8954;
            func_021D6328(p,1,&a.a,&b.a,2);
            break;
        }
        case 1: {
            Pair a=d_021D8944;
            Pair b=d_021D8964;
            func_021D6328(p,1,&a.a,&b.a,2);
            break;
        }
        }
    } else {
        func_020862F0(p->f124,0x200);
        func_0207E5D0(p->f124,0,0x200);
        func_020862F0(p->f128,0x200);
        func_0207E468(p->f128,0,0x200);
    }
}








/*
 * extent: two-byte zero alignment padding follows.
 */
void func_021D6530(void *unused,u8 *p){CLACT_VBlankSystem();if(((struct GtsnegoMsgCtx *)p)->f100){func_02040618(4,3,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f104+72);func_02040618(6,3,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f104+72);((struct GtsnegoMsgCtx *)p)->f100=0;}}








void func_021D6568(u8 *p)
{
    int i;
    void *t;
    t=func_020490F4((u32)((void *)144),((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049B68(t,3,4,0,192,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049B68(t,1,4,0,64,((struct GtsnegoMsgCtx *)p)->fF4);
    *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f8=func_02049740(t,6,7,0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,17,7,0,(u16)(*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f8),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f0=func_02049740(t,8,4,0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,18,4,0,(u16)(((struct GtsnegoMsgCtx *)p)->f0),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049B68(t,1,0,0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f4=func_02049740(t,6,0,0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,12,0,0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f70=(void *)CLACT_RegisterCharacter(t,5,0,1,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f24=(void *)CLACT_RegisterPaletteEx(t,0,1,320,0,1,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->fBC=(void *)CLACT_RegisterCellAnim(t,10,22,((struct GtsnegoMsgCtx *)p)->fF4);
    *(void * *)&((struct GtsnegoMsgCtx *)p)->f28=(void *)CLACT_RegisterCharacter(t,7,0,1,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f18=(void *)CLACT_RegisterPaletteEx(t,2,1,256,0,8,((struct GtsnegoMsgCtx *)p)->fF4);
    *(void * *)&((struct GtsnegoMsgCtx *)p)->f74=(void *)CLACT_RegisterCellAnim(t,11,23,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f2C=(void *)CLACT_RegisterCharacter(t,7,0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f1C=(void *)CLACT_RegisterPaletteEx(t,2,0,0,0,8,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f78=(void *)CLACT_RegisterCellAnim(t,11,23,((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->fF8=BLINK_PALANM_Create(0,16,0,((struct GtsnegoMsgCtx *)p)->fF4);
    BLINK_PALANM_LoadPalettes(((struct GtsnegoMsgCtx *)p)->fF8,t,1,0,16);
    ((struct GtsnegoMsgCtx *)p)->fFC=BLINK_PALANM_Create(0,16,7,((struct GtsnegoMsgCtx *)p)->fF4);
    BLINK_PALANM_LoadPalettes(((struct GtsnegoMsgCtx *)p)->fFC,t,1,0,16);
    ARC_TOOL_DeleteHandle(t);
    t=func_020490F4((u32)((void *)32),((struct GtsnegoMsgCtx *)p)->fF4);
    for(i=0;i<16;i++) {
        *(void **)(p+i*4+0x30)=(void *)CLACT_RegisterCharacter(t,i+1,0,1,((struct GtsnegoMsgCtx *)p)->fF4);
        *(void **)(p+i*4+0x7c)=(void *)CLACT_RegisterCellAnim(t,i*2+17,i*2+18,((struct GtsnegoMsgCtx *)p)->fF4);
    }
    ((struct GtsnegoMsgCtx *)p)->f20=(void *)CLACT_RegisterPaletteEx(t,0,1,0,0,8,((struct GtsnegoMsgCtx *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    func_0207D63C((void *)0x04001050,5,24,15,9);
}









void func_021D6810(u8 *a0, int a1){}








void func_021D6814(u8 *p)
{
    void *t;
    func_021D6810(p, 0);
    t = func_020490F4(144, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t, 19, 4, 0, (u16)(((struct GtsnegoMsgCtx *)p)->f0), 0, 0, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t, 20, 4, 0, (u16)(((struct GtsnegoMsgCtx *)p)->f0), 192, 0, ((struct GtsnegoMsgCtx *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    func_021D6AF0(p, 96, 56, 0);
    func_021D6AF0(p, 240, 56, 1);
    func_021D6AF0(p, 120, 96, 0);
    func_021D6AF0(p, 240, 96, 1);
    func_021D6AF0(p, 120, 136, 0);
    func_021D6AF0(p, 240, 136, 1);
}








/*
 * trailing: 2-byte zero alignment padding at 0x021D692A.
 */
void func_021D68C4(u8 *p)
{
    void *t = func_020490F4(144, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_021D6B5C(p);
    func_02041300(6, 0, 0, 0, 32, 32, 17);
    func_02041B6C(6);
    func_02049990(t, 18, 4, 0, (u16)(((struct GtsnegoMsgCtx *)p)->f0), 0, 0, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02041B6C(4);
    ARC_TOOL_DeleteHandle(t);
}








void func_021D692C(u8 *p, int n)
{
    Data data = d_021D8990;
    Config c;
    MI_CpuFill8(&c, 0, 32);
    c.f0 = &data;
    c.f4 = 1;
    c.f8 = *(u32 *)&((struct GtsnegoMsgCtx *)p)->f10;
    c.fC = 7;
    c.f10 = 15;
    c.f18 = 2;
    c.f1c = 0;
    c.f14 = n;
    ((struct GtsnegoMsgCtx *)p)->fC = TOUCHBAR_Create(&c, ((struct GtsnegoMsgCtx *)p)->fF4);
}









u32 func_021D6988(u8 *p){return *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->fC;}









void func_021D698C(u8 *p)
{
    if (((struct GtsnegoMsgCtx *)p)->fC) {
        TOUCHBAR_Delete(((struct GtsnegoMsgCtx *)p)->fC);
        *(u32 *)&((struct GtsnegoMsgCtx *)p)->fC = 0;
    }
}








void func_021D69A0(u8 *p)
{
    PosRecord r;
    r.x = 0; r.y = 0; r.z = 0; r.a = 0; r.b = 2;
    ((struct GtsnegoMsgCtx *)p)->f134 = CLACT_CreateActor((void *)*(u32 *)&((struct GtsnegoMsgCtx *)p)->f10, ((struct GtsnegoMsgCtx *)p)->f28, *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f18, ((struct GtsnegoMsgCtx *)p)->f74, &r, 1, ((struct GtsnegoMsgCtx *)p)->fF4);
    CLACT_SetActorAutoAnim(((struct GtsnegoMsgCtx *)p)->f134, 1);
    CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f134, 0);
    CLACT_SetActorObjMode(((struct GtsnegoMsgCtx *)p)->f134, 1);
}








void func_021D69F4(u8 *p, void *q, u32 n)
{
    Vec v;
    switch (n) {
    case 9:
        CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f134, 0);
        return;
    case 5:
        CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f134, 0);
        if (q) APP_TASKMENU_WIN_SetActive(q, 1);
        return;
    case 2: case 3: case 4: case 6: case 7: case 8:
        if (q) APP_TASKMENU_WIN_SetActive(q, 0);
        break;
    case 0: case 1: default: break;
    }
    v.x = d_021D8B70[n].x;
    v.y = d_021D8B70[n].y;
    CLACT_AddActorSurfacePos(((struct GtsnegoMsgCtx *)p)->f134, (const struct Vec2 *)(&v), 1);
    CLACT_SetActorAnimSeq(((struct GtsnegoMsgCtx *)p)->f134, d_021D8B70[n].code);
    CLACT_SetActorDrawEnable(((struct GtsnegoMsgCtx *)p)->f134, 1);
}
