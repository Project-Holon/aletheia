/*
 * file:     sta_acting.c
 * unit:     yes
 * function: STA_ACTING_Create, STA_ACTING_Delete, STA_ACTING_Update, STA_ACTING_InitDisplay, STA_ACTING_UploadPalettes, STA_ACTING_SetBaseProgram, STA_ACTING_SetupBg, STA_ACTING_CreateActors, STA_ACTING_CreateActObj, STA_ACTING_CreateActorSys, STA_ACTING_UpdateCamera, STA_ACTING_LoadCharAnims, STA_ACTING_LoadRankAnim, STA_ACTING_LoadAnimMember, STA_ACTING_FadePalette, STA_ACTING_CreateText, STA_ACTING_UpdateText, STA_ACTING_PrintText, STA_ACTING_ClearText, STA_ACTING_UpdateSelection, STA_ACTING_SetSelection, STA_ACTING_MarkDirty, STA_ACTING_RankScores, STA_ACTING_InstallBgm, STA_ACTING_StartSeq, STA_ACTING_StopSeq, STA_ACTING_ReplaceWaveData, STA_ACTING_PlayBgm, STA_ACTING_StopBgm, STA_ACTING_PlayRankSe, STA_ACTING_RequestAction, STA_ACTING_ApplyAction, STA_ACTING_GetCurrentAction, STA_ACTING_GetActionByIndex, STA_ACTING_ProcessRecords, STA_ACTING_AddScore, STA_ACTING_TickActionTimers, STA_ACTING_ScheduleActions, STA_ACTING_CreateAnimHandle, STA_ACTING_DeleteAnimHandle, STA_ACTING_PositionAnim, STA_ACTING_ShowAnim, STA_ACTING_HideAnim, STA_ACTING_GetActorSystem, STA_ACTING_GetActor, STA_ACTING_GetActObj, STA_ACTING_GetSlot, STA_ACTING_SetSlot, STA_ACTING_GetAnimHandle, STA_ACTING_GetAnimSlot, STA_ACTING_SetAnimSlot, STA_ACTING_GetCharSystem, STA_ACTING_GetCharSlot, STA_ACTING_SetCharSlot, STA_ACTING_GetBoard, STA_ACTING_GetCameraPos, STA_ACTING_SetCameraPos, STA_ACTING_GetCameraTarget, STA_ACTING_SetCameraTarget, STA_ACTING_GetActorCount, STA_ACTING_GetSelection, STA_ACTING_GetRecordScore, STA_ACTING_GetBonus, STA_ACTING_SetField10, STA_ACTING_GetRecordScore, STA_ACTING_GetBonus, STA_ACTING_SetField10
 * address:  0x021F8480
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   STA_NET_GetCurrentSlotValue 0x021FD8D4 thumb ov132
 *   func_020490F4 0x020490F4 arm
 *   func_021F6BD8 0x021F6BD8 thumb ov112
 *   func_021F9FEC 0x021F9FEC thumb ov132
 *   func_021FA5B0 0x021FA5B0 thumb ov132
 *   func_021FAAF4 0x021FAAF4 thumb ov132
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   d_021FDCA0 0x021FDCA0 data a1
 *   g_02FFFC3C 0x02FFFC3C data a4
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_USE_StopSeqAndUnload 0x02006504 thumb
 *   GFL_USE_ClearPreloadedBgmBuffers 0x02006518 thumb
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021FAB58 0x021FAB58 thumb ov132
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   func_021FA64C 0x021FA64C thumb ov132
 *   func_021FA04C 0x021FA04C thumb ov132
 *   func_021F6F4C 0x021F6F4C thumb ov112
 *   func_021F6C7C 0x021F6C7C thumb ov112
 *   func_021F9E94 0x021F9E94 thumb ov132
 *   STA_ACT_OBJ_Delete 0x021F6A24 thumb ov112
 *   func_021F7120 0x021F7120 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BILLBOARD_Delete 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_02030EAC 0x02030EAC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021FA6CC 0x021FA6CC thumb ov132
 *   func_021FABD8 0x021FABD8 thumb ov132
 *   func_021F9ECC 0x021F9ECC thumb ov132
 *   func_021FA064 0x021FA064 thumb ov132
 *   func_021F9ED4 0x021F9ED4 thumb ov132
 *   func_021F9E4C 0x021F9E4C thumb ov132
 *   func_021FAD7C 0x021FAD7C thumb ov132
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021F6F64 0x021F6F64 thumb ov112
 *   func_021F7160 0x021F7160 thumb ov112
 *   STA_ACT_OBJ_Update 0x021F6A58 thumb ov112
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F6CB0 0x021F6CB0 thumb ov112
 *   func_021F6E74 0x021F6E74 thumb ov112
 *   func_021F75A0 0x021F75A0 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F718C 0x021F718C thumb ov112
 *   func_021F6F8C 0x021F6F8C thumb ov112
 *   func_02047964 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   d_021FDE80 0x021FDE80 data a4
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02040588 0x02040588 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   BG_SYS_SetLowBit 0x0204044C arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   BILLBOARD_Create 0x0204EBD4 arm
 *   BILLBOARD_SetField10 0x0204ED70 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   d_021FDBA0 0x021FDBA0 data a4
 *   d_021FDAA0 0x021FDAA0 data a4
 *   d_021FDB40 0x021FDB40 data a4
 *   d_021FDB60 0x021FDB60 data a4
 *   d_021FDB80 0x021FDB80 data a4
 *   d_021FDAC0 0x021FDAC0 data a4
 *   d_021FDAE0 0x021FDAE0 data a4
 *   d_021FDB00 0x021FDB00 data a4
 *   d_021FDB20 0x021FDB20 data a4
 *   d_021FDAB0 0x021FDAB0 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   d_021FDA7C 0x021FDA7C data a4
 *   d_021FDBF8 0x021FDBF8 data a4
 *   d_021FDBD4 0x021FDBD4 data a4
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F6F24 0x021F6F24 thumb ov112
 *   MUSICAL_PROGRAM_GetBaseProgramId  0x02157364  thumb  ov010
 *   func_021F6FB0  0x021F6FB0  thumb  ov112
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_021F5164 0x021F5164 thumb ov112
 *   func_021F5438 0x021F5438 thumb ov112
 *   func_021F48C0 0x021F48C0 thumb ov112
 *   func_021F709C 0x021F709C thumb ov112
 *   func_021F760C 0x021F760C thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   d_021FDBE0 0x021FDBE0 data a4
 *   STA_ACT_OBJ_Create 0x021F69E4 thumb ov112
 *   func_021F9E50 0x021F9E50 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F6F04 0x021F6F04 thumb ov112
 *   func_021F7098 0x021F7098 thumb ov112
 *   func_021F75DC 0x021F75DC thumb ov112
 *   STA_ACT_OBJ_SetCount 0x021F6AF0 thumb ov112
 *   func_021FA57C 0x021FA57C thumb ov132
 *   KEY_GetCont 0x0203630C arm
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02040618 0x02040618 arm
 *   d_021FDBEC 0x021FDBEC data a4
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fgr 0x0209BBB0 arm
 *   _ffix 0x0209C494 arm
 *   func_021FAC74 0x021FAC74 thumb ov132
 *   d_021FDBD0 0x021FDBD0 data a1
 *   ARC_UTIL_LoadHandleMember 0x0204A380 arm
 *   func_021FAD0C 0x021FAD0C thumb ov132
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_02061CA4 0x02061CA4 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromMemory 0x02045C44 arm
 *   func_02049B40 0x02049B40 arm
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   func_021FA558 0x021FA558 thumb ov132
 *   func_021FA56C 0x021FA56C thumb ov132
 *   GFL_USE_InstallBgmBuffers  0x02006448  thumb
 *   GFL_USE_StartSeq  0x020064F4  thumb
 *   GFL_USE_ReplaceWaveData  0x020064B8  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021F7A80 0x021F7A80 thumb ov112
 *   STA_NET_SendKindA 0x021FD8C4 thumb ov132
 *   func_021F79A8 0x021F79A8 thumb ov112
 *   func_02005728 0x02005728 thumb
 *   STA_SLOT_GetCurrentKey 0x021FD9FC thumb ov132
 *   STA_SLOT_GetStateByKey 0x021FD9A0 thumb ov132
 *   STA_SLOT_ClearCurrent 0x021FDA18 thumb ov132
 *   STA_SLOT_ResetStateByKey 0x021FD9D0 thumb ov132
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   STA_SLOT_PushRecord 0x021FDA24 thumb ov132
 *   func_021F5140 0x021F5140 thumb ov112
 *   MUSICAL_PROGRAM_GetCategoryShare 0x02157394 thumb ov010
 *   STA_SLOT_SetValueByKey 0x021FD974 thumb ov132
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ll_mul 0x0209C054 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021F9EDC  0x021F9EDC  thumb
 *   func_021F9F58  0x021F9F58  thumb
 *   func_021F9F74 0x021F9F74 thumb ov132
 *   func_021FAAB8  0x021FAAB8  thumb
 *   func_021F4F10 0x021F4F10 thumb ov112
 */
#include "ov132_types.h"

#define FX(x) ((int)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
struct Descriptor;
struct Node;
struct PrintSys;
struct Rec;
struct S02031140;
struct U16Vec;
struct Board;
struct Camera;
struct Lights;
struct BgTemplate;
struct Blk3;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Light;
struct Object;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct Rec3;
struct CharBuf;
typedef unsigned int u32_021F8480;

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32_021F8640;

typedef unsigned u32_021F879C;

typedef unsigned u32_021F899C;

typedef int BOOL;

typedef struct { u32_021F899C w[3]; } Vec3;

typedef struct { Vec3 a,b,c; } Vectors;

typedef struct { u32_021F899C w[7]; } Blob28;

typedef enum { MAIN_SUB=0,SUB_MAIN=1 } GXDispSelect;

typedef unsigned int u32_021F8BD4;

typedef unsigned int   u32;

typedef signed int     s32;

typedef short s16_021F8D88;

struct Vec { int x, y, z; };

struct Slots { u8 pad[0x44]; void *slots[4]; };

typedef struct Object Object;

typedef signed short s16_021F8DC4;

typedef struct { int x, y, z; } Vec;

struct Bytes { u8 a, b, c, d; };

typedef signed char s8;

typedef struct {
    u8 pad[0x168];
    u16 phase;
    u16 base[16];
    s8 dr[16];
    s8 dg[16];
    s8 db[16];
    u16 out[16];
} Fade;

typedef enum { ZERO } Zero;

typedef signed short s16;

typedef enum { ENABLED = 1 } Enabled;

typedef unsigned long long u64;

typedef enum { ACTION7 = 7, ACTION8 = 8 } Action;

extern void *func_02030734(u32_021F8480 heapId, u32_021F8480 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void (*)(void),void *,u32_021F8480);
extern u32_021F8480 STA_NET_GetCurrentSlotValue(char *p);
extern void *func_020490F4(u32_021F8480 id, u32_021F8480 heap);
extern void *func_021F6BD8(u16,void *);
extern char *func_021F9FEC(u32_021F8480,void *,u32_021F8480);
extern char *func_021FA5B0(u32_021F8480,void *,char *);
extern void *func_021FAAF4(u32_021F8480,void *);
extern void GFL_NET_RestartWithDefaultTimeout(u32_021F8480,u32_021F8480);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void GFL_USE_StopSeqAndUnload(void);
extern void GFL_USE_ClearPreloadedBgmBuffers(void);
extern void GXx_SetMasterBrightness_(volatile u16 *,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021FAB58(char *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32_021F8640 MSGDATA_Delete(struct Rec *rec);
extern u32_021F8640 BMP_WIN_Delete(struct Descriptor *d);
extern u32_021F8640 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
extern void func_021FA64C(char *);
extern void func_021FA04C(u8 *p);
extern void func_021F6F4C(u8 *p);
extern void func_021F6C7C(char *p);
extern void func_021F9E94(u8 *p);
extern void STA_ACT_OBJ_Delete(char *p);
extern void func_021F7120(char *p);
extern void func_021F51B0(int a);
extern void func_021F4948(u8 *p);
extern void CLACT_ExitSystem(void);
extern void BILLBOARD_Delete(void *);
extern u32_021F8640 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
extern void func_020403F4(u32_021F8640);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void func_02030EAC(struct Node *n);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32_021F8640 func_020307B0(void *p);
extern void WIPE_SYS_Start(void *,u32_021F879C,u32_021F879C,u32_021F879C,u32_021F879C,u32_021F879C,u32_021F879C);
extern u32_021F879C WIPE_SYS_EndCheck(void);
extern u32_021F879C func_0200FB24(void);
extern int GFL_USE_IsAnySeBusy(void);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(char *p, int id);
extern u8 func_021FAD7C(char *);
extern void func_021FA6CC(char *p);
extern void func_021FABD8(char *p);
extern int func_021F9ECC(u8 *a0);
extern void func_021FA064(char *p);
extern int func_021F9ED4(u8 *a0);
extern void func_021F9E4C(u8 *);
extern void func_021F6F64(u8 *);
extern void func_021F7160(u8 *);
extern void STA_ACT_OBJ_Update(char *p);
extern void func_021F51E8(u8 *);
extern void func_021F6CB0(char *p);
extern void func_021F6E74(u8 *);
extern void func_021F75A0(u8 *);
extern void func_021F51F4(void **p);
extern void func_021F718C(char *p);
extern void func_021F6F8C(u8 *);
extern void func_02047964(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawEnd(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void BILLBOARD_Draw(struct Board *b, struct Camera *cam, struct Lights *lights);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32_021F899C,u32_021F899C);
extern u32_021F899C WIPE_ResetWndMask(void *);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02040588(u32 which, unsigned char enable);
extern void G3D_SYSTEM_Init(u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u16,u16,void (*)(void));
extern void BG_SYS_SetLowBit(u32_021F899C);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32_021F899C,u32_021F899C);
extern void *G3D_CAMERA_Create(u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,u32_021F899C,const Vec3 *,const Vec3 *,const Vec3 *,u16);
extern void func_02048AD0(struct Light *l);
extern void func_0207DCF8(const void *);
extern void *BILLBOARD_Create(u8 *src, void *heap);
extern void BILLBOARD_SetField10(u8 *dst, struct Blk3 *src);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32_021F899C arg, u32_021F899C heapId);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32_021F8BD4 a1, u32_021F8BD4 a2, u32_021F8BD4 a3, u32_021F8BD4 a4, u32_021F8BD4 a5, u16 a6);
extern u32_021F8BD4 func_02049658(void *a, u32_021F8BD4 b, u32_021F8BD4 c, u32_021F8BD4 d, u32_021F8BD4 e, u32_021F8BD4 f, u16 g);
extern void func_020498F4(void *a, u32_021F8BD4 b, u32_021F8BD4 c, u32_021F8BD4 d, u32_021F8BD4 e, u32_021F8BD4 f, u16 g);
extern void func_02049B68(void *a, u32_021F8BD4 b, u32_021F8BD4 c, u32_021F8BD4 d, u32_021F8BD4 e, u16 f);
extern void MIi_CpuCopy16(const void *,void *,u32_021F8BD4);
extern void func_020409B4(u32_021F8BD4);
extern u8 *func_021F6F24(u32_021F8BD4 heap, u32_021F8BD4 v);
extern u8 MUSICAL_PROGRAM_GetBaseProgramId(char *a0);
extern void func_021F6FB0(void *, int);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void func_020414AC(u32);
extern void *func_021F5164(u32);
extern void func_021F5438(void **p, int b);
extern struct Object *func_021F48C0(u32 owner, int count, u16 heap);
extern u8 *func_021F709C(u16 heap, u32 b, u32 c, u32 d, u32 e);
extern void *func_021F760C(void *,void *);
extern void func_021F8054(void *unused, u32 *p, const u32 *q);
extern Object *STA_ACT_OBJ_Create(u16,void *);
extern char *func_021F9E50(unsigned);
extern u32 KEY_GetCont(void);
extern void func_021F8044(void *unused, u32 *p, u32 *q);
extern void func_021F6F04(void *, void *, Vec *);
extern void func_021F7098(u8 *p, u16 v);
extern void func_021F75DC(u8 *p, u16 v);
extern void STA_ACT_OBJ_SetCount(void *, u16);
extern void func_021FA57C(void *unused, int x);
extern void func_02048AFC(void *, const Vec *);
extern void func_02048B44(void *, const Vec *);
extern void func_02040618(u32, u32, u32);
extern void *func_021FAC74(char *p, void *arg, int flag);
extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern char *func_021FAD0C(char *p, char *base, unsigned index, unsigned char flag);
extern int func_02061CA4(void *, u32, u32, int);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromMemory(const void *file, u32 heapId);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *);
extern void TCBL_Main(struct Tcbl *p);
extern unsigned PRINTSYS_PrintStreamGetState(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *PRINTSYS_PrintStream(void *, u32, u32, void *, void *, u32, void *, u32, u16, u32);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_021FA558(char *, int, int);
extern void func_021FA56C(char *, u8);
extern int GFL_USE_InstallBgmBuffers(u32 a0, u32 a1, u32 a2);
extern void GFL_USE_StartSeq(u32 a);
extern int GFL_USE_ReplaceWaveData(u32, u32, u32, u32);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int func_021F7A80(char *,char *);
extern int STA_NET_SendKindA(void *, int);
extern void func_021F79A8(char *, char *, int);
extern u32 func_02005728(u32);
extern int STA_SLOT_GetCurrentKey(char *p);
extern int STA_SLOT_GetStateByKey(void *, unsigned);
extern void STA_SLOT_ClearCurrent(unsigned char *p);
extern void STA_SLOT_ResetStateByKey(unsigned char *p, unsigned char key);
extern u32 GFL_NET_IsParentAid(void);
extern void STA_SLOT_PushRecord(void *, u32, u32, u32);
extern unsigned char func_021F5140(void *p, int i);
extern u16 MUSICAL_PROGRAM_GetCategoryShare(int a0, int a1);
extern void STA_SLOT_SetValueByKey(char *p, u32 key, u8 value);
extern u32 func_0203F0A8(void);
extern char *func_021F9EDC(char *p, u32 a);
extern void func_021F9F58(u8 *unused, u8 *p);
extern void func_021F9F74(char *, unsigned, const int *);
extern void func_021FAAB8(char *p, unsigned flag);
extern u32 func_021F4F10(u8 *);
u8 *STA_ACTING_Create(u8 *input, int heap);
void STA_ACTING_Delete(char *p);
int STA_ACTING_Update(u8 *p);
void STA_ACTING_VBlankCallback(void);
void STA_ACTING_InitDisplay(u8 *p);
void STA_ACTING_UploadPalettes(u8 *p);
void STA_ACTING_SetBaseProgram(u8 *p, u32 a1);
void STA_ACTING_SetupBg(const struct BgTemplate *p,u32 id,u32 type);
void STA_ACTING_CreateActors(u8 *p);
void STA_ACTING_CreateActObj(char *p);
void STA_ACTING_CreateActorSys(char *p);
void STA_ACTING_UpdateCamera(u8 *p);
void STA_ACTING_LoadCharAnims(u8 *p);
void STA_ACTING_LoadRankAnim(u8 *p, u8 n, u8 i);
void STA_ACTING_LoadAnimMember(char *p, u8 n, u8 mask);
void STA_ACTING_FadePalette(Fade *p);
void STA_ACTING_CreateText(u8 *p);
void STA_ACTING_UpdateText(u8 *p);
void STA_ACTING_PrintText(u8 *p, u16 index, u32 speed);
void STA_ACTING_ClearText(u8 *p);
void STA_ACTING_UpdateSelection(char *p);
void STA_ACTING_SetSelection(char *p, u8 v, int c);
void STA_ACTING_MarkDirty(char *p);
void STA_ACTING_RankScores(u8 *p);
void STA_ACTING_InstallBgm(char *p, int a);
void STA_ACTING_StartSeq(char *p, int a);
void STA_ACTING_StopSeq(char *p);
int STA_ACTING_ReplaceWaveData(char *p, u32 a, u32 b, u32 d);
void STA_ACTING_PlayBgm(char *p, int a);
void STA_ACTING_StopBgm(char *p);
void STA_ACTING_PlayRankSe(char *p);
void STA_ACTING_RequestAction(char *p,int value);
void STA_ACTING_ApplyAction(char *p, u32 i, int v);
int STA_ACTING_GetCurrentAction(char *p);
int STA_ACTING_GetActionByIndex(char *p,u32 i);
void STA_ACTING_ProcessRecords(char *p);
int STA_ACTING_AddScore(char *p, unsigned i, unsigned j);
void STA_ACTING_TickActionTimers(char *p);
void STA_ACTING_ScheduleActions(char *p, int mode, u8 slot);
void STA_ACTING_CreateAnimHandle(char *p);
void STA_ACTING_DeleteAnimHandle(char *p);
void STA_ACTING_PositionAnim(char *p, unsigned i);
void STA_ACTING_ShowAnim(char *p);
void STA_ACTING_HideAnim(char *p);
void *STA_ACTING_GetActorSystem(char *p);
void *STA_ACTING_GetActor(char *p,u32 i);
void *STA_ACTING_GetActObj(void *p);
u32 *STA_ACTING_GetSlot(void *p,u8 i);
void STA_ACTING_SetSlot(void *p,void *v,u32 i);
void *STA_ACTING_GetAnimHandle(void *p);
void *STA_ACTING_GetAnimSlot(void *p,u8 i);
void STA_ACTING_SetAnimSlot(void *p,void *v,u32 i);
void *STA_ACTING_GetCharSystem(void *p);
void *STA_ACTING_GetCharSlot(void *p,u8 i);
void STA_ACTING_SetCharSlot(void *p,void *v,u8 i);
void *STA_ACTING_GetBoard(void *p);
u16 STA_ACTING_GetCameraPos(void *p);
void STA_ACTING_SetCameraPos(void *p,u16 v);
u16 STA_ACTING_GetCameraTarget(u8 *p);
void STA_ACTING_SetCameraTarget(u8 *p,u16 v);
u32 STA_ACTING_GetActorCount(u8 *p);
int STA_ACTING_GetSelection(char *p);
extern const char d_021FDCA0[];
extern u32_021F8480 g_02FFFC3C;
extern u32_021F879C d_02FFFC3C;
extern u32_021F879C d_021FDE80;
extern const Vectors d_021FDA7C;
extern const Blob28 d_021FDBF8;
extern const Vec3 d_021FDBD4;
extern const u32_021F899C d_021FDBA0[];
extern const u32_021F899C d_021FDAA0[];
extern const u32_021F899C d_021FDB40[];
extern const u32_021F899C d_021FDB60[];
extern const u32_021F899C d_021FDB80[];
extern const u32_021F899C d_021FDAC0[];
extern const u32_021F899C d_021FDAE0[];
extern const u32_021F899C d_021FDB00[];
extern const u32_021F899C d_021FDB20[];
extern const u32_021F899C d_021FDAB0[];
extern const u32_021F899C gClActorInitParam[];
extern const struct Vec d_021FDBE0;
extern const Vec d_021FDBEC;
extern const struct Bytes d_021FDBD0;
extern const s16_021F8DC4 FX_SinCosTable_[];



u8 *STA_ACTING_Create(u8 *input, int heap)
{
    u8 *p;
    u8 i;
    p=func_02030734(heap,0x1f0,1,d_021FDCA0,0x11a);
    *(u16 *)p=heap;
    *(void **)(p+0x30)=input;
    i=0;
    *(u16 *)(p+2)=0;
    *(u16 *)(p+4)=127;
    *(u16 *)(p+6)=128;
    *(u16 *)(p+8)=0;
    *(u32_021F8480 *)(p+0xb4)=0;
    *(u32_021F8480 *)(p+0x1c)=0;
    *(u32_021F8480 *)(p+0x164)=0;
    *(u32_021F8480 *)(p+0xc)=1;
    *(u32_021F8480 *)(p+0x14)=0;
    *(u32_021F8480 *)(p+0x10)=0;
    *(u32_021F8480 *)(p+0x24)=0;
    *(u32_021F8480 *)(p+0x28)=0;
    *(u32_021F8480 *)(p+0x2c)=0;
    *(void **)(p+0x20)=func_020056A0(STA_ACTING_VBlankCallback,p,64);
    if(**(u32_021F8480 **)(p+0x30)==0){
        for(;i<4;i++){
            if(**(u32_021F8480 **)(*(u8 **)(p+0x30)+4+i*4)==0){p[0xa]=i;break;}
        }
        if(i==4)p[0xa]=1;
    }else p[0xa]=STA_NET_GetCurrentSlotValue((void *)**(u32_021F8480 **)(p+0x30));
    for(i=0;i<4;i++)p[0xf7+i]=0;
    STA_ACTING_RankScores(p);
    *(u32_021F8480 *)(p+0xec)=1;
    p[0xf0]=4;
    p[0xf1]=4;
    p[0xf2]=4;
    p[0x11c]=4;
    *(u16 *)(p+0x11e)=0;
    *(u32_021F8480 *)(p+0x15c)=0;
    *(u16 *)(p+0x168)=0;
    for(i=0;i<4;i++){
        *(u32_021F8480 *)(p+0xfc+i*4)=0;
        *(u16 *)(p+0x124+i*2)=0;
        *(u32_021F8480 *)(p+0x13c+i*8)=0;
        *(u32_021F8480 *)(p+0x140+i*8)=0;
    }
    *(void **)(p+0x18)=func_020490F4(47,*(u16 *)p);
    STA_ACTING_InitDisplay(p);
    STA_ACTING_UploadPalettes(p);
    STA_ACTING_CreateText(p);
    STA_ACTING_CreateActors(p);
    STA_ACTING_CreateActObj((char *)p);
    STA_ACTING_CreateActorSys((char *)p);
    *(void **)(p+0x90)=func_021F6BD8(*(u16 *)p,p);
    *(void **)(p+0xb8)=func_021F9FEC(*(u16 *)p,p,*(u32_021F8480 *)(p+0x30));
    *(void **)(p+0xa4)=func_021FA5B0(*(u16 *)p,p,*(char **)(*(u8 **)(p+0x30)+p[0xa]*4+4));
    *(void **)(p+0xb0)=func_021FAAF4(*(u16 *)p,p);
    STA_ACTING_CreateAnimHandle((char *)p);
    GFL_NET_RestartWithDefaultTimeout(0,*(u16 *)p);
    STA_ACTING_SetBaseProgram(p,0);
    *(u32_021F8480 *)(p+0x1dc)=*(u32_021F8480 *)((*(u8 ***)(p+0x30))[6]+0x14);
    *(u32_021F8480 *)(p+0x1e0)=*(u32_021F8480 *)((*(u8 ***)(p+0x30))[6]+0x18);
    *(u32_021F8480 *)(p+0x1e4)=*(u32_021F8480 *)((*(u8 ***)(p+0x30))[6]+0x1c);
    *(u32_021F8480 *)(p+0x1ec)=g_02FFFC3C;
    return p;
}



/*
 * volatile: hardware display register 0x04000000 read at 0x021F868C.
 */
void STA_ACTING_Delete(char *p)
{
    if(((struct ActingScene *)p)->f2C.u==1)GFL_USE_CancelChangeAndStopBgm();
    if(((struct ActingScene *)p)->f28.u==1)GFL_USE_StopSeqAndUnload();
    if(((struct ActingScene *)p)->f24.u==1)GFL_USE_ClearPreloadedBgmBuffers();
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006c,-16);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106c,-16);
    func_0207D63C((void *)0x04000050,0,0,31,31);
    *(volatile u32_021F8640 *)0x04000000 &= 0xffff1fff;
    STA_ACTING_DeleteAnimHandle(p);
    func_021FAB58(((struct ActingScene *)p)->fB0);
    if(((struct ActingScene *)p)->fE0.p!=0)STRBUF_Delete(((struct ActingScene *)p)->fE0.p);
    PRINTSYS_QUE_Clear(((struct ActingScene *)p)->fE8.p);
    PRINTSYS_QUE_Delete(((struct ActingScene *)p)->fE8.p);
    MSGDATA_Delete(((struct ActingScene *)p)->fDC.p);
    BMP_WIN_Delete(((struct ActingScene *)p)->fD0.p);
    GF_FONT_Delete(((struct ActingScene *)p)->fD4.p);
    TCBL_Destroy(((struct ActingScene *)p)->fCC.p);
    func_021FA64C(*(char * *)&((struct ActingScene *)p)->fA4);
    func_021FA04C(((struct ActingScene *)p)->fB8);
    func_021F6F4C(((struct ActingScene *)p)->f3C);
    func_021F6C7C(((struct ActingScene *)p)->f90);
    func_021F9E94(((struct ActingScene *)p)->f6C);
    STA_ACT_OBJ_Delete(((struct ActingScene *)p)->f54);
    func_021F7120(((struct ActingScene *)p)->f40);
    func_021F51B0((int)(((struct ActingScene *)p)->f34));
    func_021F4948(((struct ActingScene *)p)->f38);
    CLACT_ExitSystem();
    BILLBOARD_Delete(((struct ActingScene *)p)->fAC.p);
    G3D_CAMERA_Delete(((struct ActingScene *)p)->fA8);
    G3D_SYSTEM_Exit();
    func_020403F4(0);
    func_020403F4(1);
    func_020403F4(2);
    func_020403F4(3);
    func_020403F4(5);
    func_020403F4(7);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    func_02030EAC(((struct ActingScene *)p)->f20);
    ARC_TOOL_DeleteHandle(((struct ActingScene *)p)->f18.p);
    func_020307B0(p);
}



/*
 * extent: lead followed by 021F8994 tail-call stub.
 * note: 021F6E74 retains the explicitly loaded pointer despite own void prototype.
 */
int STA_ACTING_Update(u8 *p)
{
    u32_021F879C tick;
    tick=d_02FFFC3C;
    ((struct ActingScene *)p)->f1E8=tick-((struct ActingScene *)p)->f1EC.u;
    ((struct ActingScene *)p)->f1EC.u=tick;
    switch(((struct ActingScene *)p)->f1C) {
    case 0:
        WIPE_SYS_Start(0,1,1,0,6,1,((struct ActingScene *)p)->f0);
        ((struct ActingScene *)p)->f1C=1;
        break;
    case 1:
        if(WIPE_SYS_EndCheck()==1) {
            if(**(u32_021F879C * *)&((struct ActingScene *)p)->f30!=0) {
                ((struct ActingScene *)p)->f1C=7;
                func_021FCDEC(**(int * *)&((struct ActingScene *)p)->f30,200);
            } else ((struct ActingScene *)p)->f1C=4;
        }
        break;
    case 2:
        if(GFL_USE_IsAnySeBusy()==0) {
            WIPE_SYS_Start(0,0,0,0,6,1,((struct ActingScene *)p)->f0);
            ((struct ActingScene *)p)->f1C=3;
        }
        break;
    case 3:
        if(WIPE_SYS_EndCheck()==1) return 1;
        break;
    case 4:
        if((((struct ActingScene *)p)->f2)++ >=60) ((struct ActingScene *)p)->f1C=5;
        break;
    case 5:
        if(((struct ActingScene *)p)->f164==0) {
            ((struct ActingScene *)p)->fB4.u=((struct ActingPartB *)(*(u8 * *)&((struct ActingPartA *)(*(u8 * *)&((struct ActingScene *)p)->f30))->f18))->fC;
            STA_ACTING_LoadCharAnims(p);
            ((struct ActingScene *)p)->f1C=6;
        }
        break;
    case 6:
        if(func_021FAD7C(*(char * *)&((struct ActingScene *)p)->fB0)==0) {
            ((struct ActingScene *)p)->fB4.u=0;
            if(((struct ActingScene *)p)->f164==0) ((struct ActingScene *)p)->f1C=2;
            else ((struct ActingScene *)p)->f1C=255;
        }
        break;
    case 7:
        if(func_021FCE00(*(void **)*(u8 * *)&((struct ActingScene *)p)->f30,200)==1)
            ((struct ActingScene *)p)->f1C=4;
        break;
    }
    STA_ACTING_UpdateCamera(p);
    func_021FA6CC((char *)(*(u8 * *)&((struct ActingScene *)p)->fA4));
    STA_ACTING_ProcessRecords((char *)p);
    if(d_021FDE80==0) func_021FABD8((char *)(*(u8 * *)&((struct ActingScene *)p)->fB0));
    func_021F6F64(*(u8 * *)&((struct ActingScene *)p)->f3C);
    func_021F7160(*(u8 * *)&((struct ActingScene *)p)->f40);
    STA_ACT_OBJ_Update((char *)(*(u8 * *)&((struct ActingScene *)p)->f54));
    func_021F9ECC(*(u8 * *)&((struct ActingScene *)p)->f6C);
    STA_ACTING_UpdateText(p);
    func_021F51E8(*(u8 * *)&((struct ActingScene *)p)->f34);
    func_021F6CB0((char *)(*(u8 * *)&((struct ActingScene *)p)->f90));
    STA_ACTING_UpdateSelection((char *)p);
    func_021FA064((char *)(*(u8 * *)&((struct ActingScene *)p)->fB8));
    STA_ACTING_FadePalette((Fade *)p);
    func_02047964(); G3D_SYSTEM_ApplyLookAt();
    func_021F6E74(*(u8 * *)&((struct ActingScene *)p)->f90);
    func_021F75A0(*(u8 * *)&((struct ActingScene *)p)->f40);
    func_021F51F4((void **)(*(u8 * *)&((struct ActingScene *)p)->f34));
    func_021F718C((char *)(*(u8 * *)&((struct ActingScene *)p)->f40));
    func_021F6F8C(*(u8 * *)&((struct ActingScene *)p)->f3C);
    BILLBOARD_Draw(((struct ActingScene *)p)->fAC.p,((struct ActingScene *)p)->fA8,0);
    func_021F9ED4(*(u8 * *)&((struct ActingScene *)p)->f6C);
    func_021F9E4C(p);
    G3D_SYSTEM_DrawEnd(); CLACT_DrawSystem();
    if(**(u32_021F879C * *)&((struct ActingScene *)p)->f30!=0 && ((struct ActingScene *)p)->f1C!=0 &&
       ((struct ActingScene *)p)->f1C!=1 && ((struct ActingScene *)p)->f1C!=2 &&
       ((struct ActingScene *)p)->f1C!=3 && func_0200FB24()!=0)
        ((struct ActingScene *)p)->f1C=2;
    return 0;
}



void STA_ACTING_VBlankCallback(void) { CLACT_VBlankSystem(); }



static inline void GX_SetVisiblePlane(int plane) { *(volatile u32_021F899C *)0x04000000=(*(volatile u32_021F899C *)0x04000000&~0x1F00u)|((u32_021F899C)plane<<8); }



static inline void GXS_SetVisiblePlane(int plane) { *(volatile u32_021F899C *)0x04001000=(*(volatile u32_021F899C *)0x04001000&~0x1F00u)|((u32_021F899C)plane<<8); }



static inline void GX_SetDispSelect(GXDispSelect sel) { *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304&~0x8000u)|(sel<<15)); }



static inline void G3X_EdgeMarking(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|0x20); else *(volatile u16 *)0x04000060&=(u16)~0x3020; }



static inline void G3X_AntiAlias(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|0x10); else *(volatile u16 *)0x04000060&=(u16)~0x3010; }



static inline void G3X_AlphaBlend(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|8); else *(volatile u16 *)0x04000060&=(u16)~0x3008; }



static inline void GX_SetVisibleWnd(int window) { *(volatile u32_021F899C *)0x04000000=(*(volatile u32_021F899C *)0x04000000&~0xE000u)|((u32_021F899C)window<<13); }



static inline void G2_SetWndOBJInsidePlane(int wnd,BOOL effect) { u32_021F899C tmp; tmp=(*(volatile u16 *)0x0400004A&~0x3F00u)|((u32_021F899C)wnd<<8); if(effect) tmp|=0x2000; *(volatile u16 *)0x0400004A=(u16)tmp; }



static inline void G2_SetWndOutsidePlane(int wnd,BOOL effect) { u32_021F899C tmp; tmp=(*(volatile u16 *)0x0400004A&~0x3Fu)|(u32_021F899C)wnd; if(effect) tmp|=0x20; *(volatile u16 *)0x0400004A=(u16)tmp; }



void STA_ACTING_InitDisplay(u8 *p)
{
    Blob28 big;
    Vec3 small;
    void *light,*board;
    BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
    GX_SetVisiblePlane(0); GXS_SetVisiblePlane(0);
    WIPE_SetBrightnessFadeOut(0,0); WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0); WIPE_ResetWndMask((void *)1);
    GX_SetDispSelect(SUB_MAIN);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021FDBA0);
    BG_SYS_Create(*(u16 *)p); BMP_WIN_Init(*(u16 *)p);
    func_0203FC28((struct DispConfig *)d_021FDAA0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB40,1,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB60,2,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB80,3,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDAC0,5,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDAE0,6,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB00,4,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB20,7,0);
    func_02040588(0,1);
    G3D_SYSTEM_Init(0,2,0,4,0,*(u16 *)p,0);
    BG_SYS_SetLowBit(3);
    G3D_SYSTEM_SetSwapBuffersMode(0,1);
    light=G3D_CAMERA_Create(2,0xC000,0,0,0x10000,0x1000,0x3E8000,0,&d_021FDA7C.c,&d_021FDA7C.a,&d_021FDA7C.b,*(u16 *)p);
    *(void **)(p+0xA8)=light;
    func_02048AD0(light);
    func_0207DCF8(d_021FDAB0);
    G3X_EdgeMarking(0); G3X_AntiAlias(1); G3X_AlphaBlend(1);
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
    big=d_021FDBF8;
    small=d_021FDBD4;
    board=BILLBOARD_Create((u8 *)(&big),(void *)(u32_021F899C)*(u16 *)p);
    *(void **)(p+0xAC)=board;
    BILLBOARD_SetField10(board,(struct Blk3 *)(&small));
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32_021F899C)d_021FDBA0,*(u16 *)p);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
    func_0207D63C((void *)0x04000050,8,1,0,10);
    GX_SetVisibleWnd(4);
    G2_SetWndOBJInsidePlane(23,1);
    G2_SetWndOutsidePlane(31,1);
}



void STA_ACTING_UploadPalettes(u8 *p)
{
    u16 palette[16];
    u8 i=0;
    u16 old,new;
    ARC_UTIL_UploadPaletteFromHandle((void *)(((struct ActingScene *)p)->f18.u),2,0,32,32,32,((struct ActingScene *)p)->f0);
    func_02049658((void *)(((struct ActingScene *)p)->f18.u),8,3,0,0,0,((struct ActingScene *)p)->f0);
    func_020498F4((void *)(((struct ActingScene *)p)->f18.u),14,3,0,0,0,((struct ActingScene *)p)->f0);
    ARC_UTIL_UploadPaletteFromHandle((void *)(((struct ActingScene *)p)->f18.u),3,0,0,0,32,((struct ActingScene *)p)->f0);
    func_02049658((void *)(((struct ActingScene *)p)->f18.u),9,2,0,0,0,((struct ActingScene *)p)->f0);
    func_020498F4((void *)(((struct ActingScene *)p)->f18.u),15,2,0,0,0,((struct ActingScene *)p)->f0);
    func_02049B68((void *)(((struct ActingScene *)p)->f18.u),5,4,0,0,((struct ActingScene *)p)->f0);
    func_02049658((void *)(((struct ActingScene *)p)->f18.u),13,5,0,0,0,((struct ActingScene *)p)->f0);
    func_020498F4((void *)(((struct ActingScene *)p)->f18.u),17,5,0,0,0,((struct ActingScene *)p)->f0);
    func_02049658((void *)(((struct ActingScene *)p)->f18.u),12,6,0,0,0,((struct ActingScene *)p)->f0);
    func_020498F4((void *)(((struct ActingScene *)p)->f18.u),16,6,0,0,0,((struct ActingScene *)p)->f0);
    func_02049658((void *)(((struct ActingScene *)p)->f18.u),11,4,0,0,0,((struct ActingScene *)p)->f0);
    MIi_CpuCopy16((void *)0x05000400,p+0x16a,32);
    MIi_CpuCopy16((void *)0x05000420,palette,32);
    for(i=0;i<16;i++){
        old=*(u16 *)(p+0x16a+i*2);
        new=palette[i];
        p[0x18a+i]=(u8)(new&31)-(u8)(old&31);
        p[0x19a+i]=(u8)((new&0x3e0)>>5)-(u8)((old&0x3e0)>>5);
        p[0x1aa+i]=(u8)((new&0x7c00)>>10)-(u8)((old&0x7c00)>>10);
    }
    func_020409B4(3);
    func_020409B4(5);
    ((struct ActingScene *)p)->f3C=func_021F6F24(((struct ActingScene *)p)->f0,(u32_021F8BD4)p);
}






/*
 * Unblocked by matching MUSICAL_PROGRAM_GetBaseProgramId (ov010, EXACT, Thumb): the +0008 call
 * site now attests as `matched`. ov009 holds ARM code at that address; ov010
 * is the coherent Thumb leaf, so the declaration is thumb/ov010 (the earlier
 * `arm` was wrong).
 *
 * Addresses are Black-image addresses.
 */
void STA_ACTING_SetBaseProgram(u8 *p, u32 a1)
{
    int v = MUSICAL_PROGRAM_GetBaseProgramId(((struct ActingPartA *)((u8 *)((struct ActingScene *)p)->f30))->f14);
    func_021F6FB0(((struct ActingScene *)p)->f3C, v);
}





void STA_ACTING_SetupBg(const struct BgTemplate *p,u32 id,u32 type) { BG_SYS_InitBgLayer(id,p,type); func_02040588(id,1); func_020414AC(id); func_020409B4(id); }





void STA_ACTING_CreateActors(u8 *p)
{
    struct Vec pos;
    u8 i;
    pos = d_021FDBE0;
    ((struct ActingScene *)p)->f34=func_021F5164(((struct ActingScene *)p)->f0);
    func_021F5438(((struct ActingScene *)p)->f34,0x20000);
    ((struct ActingScene *)p)->f38=func_021F48C0(((struct ActingScene *)p)->fAC.u,36,((struct ActingScene *)p)->f0);
    ((struct ActingScene *)p)->f40=func_021F709C(((struct ActingScene *)p)->f0,(u32)p,(u32)(((struct ActingScene *)p)->f34),(u32)(((struct ActingScene *)p)->f38),((struct ActingScene *)p)->fAC.u);
    for (i=0;i<4;i++) *(u32 *)(p+0x44+i*4)=0;
    for (i=0;i<4;i++) {
        ((struct Slots *)p)->slots[i]=func_021F760C(((struct ActingScene *)p)->f40,*(void **)(*(u8 * *)&((struct ActingScene *)p)->f30+4+i*4));
        func_021F8054(((struct ActingScene *)p)->f40,((struct Slots *)p)->slots[i],(const u32 *)(&pos));
        pos.z-=0x1e000;
    }
}





void STA_ACTING_CreateActObj(char *p){int tmp[3]={0};int i;for(i=0;i<5;i++)*(int *)((u32)p+i*4+0x58)=0;*(Object * *)&((struct ActingScene *)p)->f54=STA_ACT_OBJ_Create(((struct ActingScene *)p)->f0,((struct ActingScene *)p)->fAC.p);}





void STA_ACTING_CreateActorSys(char *p){int i;*(char * *)&((struct ActingScene *)p)->f6C=func_021F9E50(((struct ActingScene *)p)->f0);for(i=0;i<8;i++)*(int *)((u32)p+i*4+0x70)=0;}





/*
 * blocker C (read-only root show):
 *   void func_02048AFC(char *p, const Vec *v) { *(Vec *)(p + 0x20) = *v; }
 *   void func_02048B44(char *p, const Vec *v) { *(Vec *)(p + 0x38) = *v; }
 */
void STA_ACTING_UpdateCamera(u8 *p)
{
    Vec v;
    s16_021F8DC4 target;
    u8 index;
    if (KEY_GetCont() & 16) {
        if (*(u16 *)(p + 6) + 2 < 256) *(u16 *)(p + 6) = *(u16 *)(p + 6) + 2;
        else *(u16 *)(p + 6) = 256;
    }
    if (KEY_GetCont() & 32) {
        if (*(u16 *)(p + 6) - 2 > 0) *(u16 *)(p + 6) = *(u16 *)(p + 6) - 2;
        else *(u16 *)(p + 6) = 0;
    }
    if (!(KEY_GetCont() & 48) && !*(int *)(p + 0x14) && !*(int *)(p + 0x10) && !*(int *)(p + 0xC)) {
        if (*(u8 *)(p + 0xF2) == 4) {
            index = *(u8 *)(p + 0xF1);
            if (index == 4) index = *(u8 *)(p + 0xA);
            if (*(void **)(p + 0x44 + index * 4)) {
                func_021F8044(*(void **)(p + 0x40), *(void **)(p + 0x44 + index * 4), (u32 *)(&v));
                target = (float)v.x / 4096.0f - 128.0f;
            }
        } else {
            func_021F6F04(*(void **)(p + 0x90), *(void **)(p + 0x94 + *(u8 *)(p + 0xF2) * 4), &v);
            target = (float)v.x / 4096.0f - 128.0f;
        }
        if (target > 256) target = 256;
        else if (target < 0) target = 0;
        if (target != *(u16 *)(p + 4)) *(u16 *)(p + 6) = target;
    }
    if (*(u16 *)(p + 6) != *(u16 *)(p + 4)) {
        Vec scale = d_021FDBEC;
        Vec translation = {0, 0, 0};
        if (*(u16 *)(p + 4) > *(u16 *)(p + 6)) {
            if (*(u16 *)(p + 4) > 4 && *(u16 *)(p + 4) - 4 > *(u16 *)(p + 6)) *(u16 *)(p + 4) -= 4;
            else *(u16 *)(p + 4) = *(u16 *)(p + 6);
        } else if (*(u16 *)(p + 4) < *(u16 *)(p + 6)) {
            if (*(u16 *)(p + 4) + 4 < *(u16 *)(p + 6)) *(u16 *)(p + 4) += 4;
            else *(u16 *)(p + 4) = *(u16 *)(p + 6);
        }
        scale.x = FX((float)*(u16 *)(p + 4) / 16.0f);
        translation.x = FX((float)*(u16 *)(p + 4) / 16.0f);
        func_02048AFC(*(void **)(p + 0xA8), &scale);
        func_02048B44(*(void **)(p + 0xA8), &translation);
        func_02048AD0(*(void **)(p + 0xA8));
        func_02040618(2, 0, *(u16 *)(p + 4));
        func_021F7098(*(void **)(p + 0x3C), *(u16 *)(p + 4));
        func_021F75DC(*(void **)(p + 0x40), *(u16 *)(p + 4));
        STA_ACT_OBJ_SetCount(*(void **)(p + 0x54), *(u16 *)(p + 4));
        func_021FA57C(*(void **)(p + 0xB8), *(u16 *)(p + 4));
    }
    if (*(u16 *)(p + 8) == 224) *(int *)(p + 0xC) = 0;
    func_02040618(2, 3, *(u16 *)(p + 8));
}





void STA_ACTING_LoadCharAnims(u8 *p)
{
    u8 i;
    u32 *table;
    struct Bytes order;
    table = *(u32 * *)&((struct ActingScene *)p)->fB4;
    order = d_021FDBD0;
    func_021FAC74(((struct ActingScene *)p)->fB0, (u8 *)table + table[0], 1);
    for (i = 0; i < 4; i++) {
        if (table[0] != table[((u8 *)&order)[i]]) {
            func_021FAC74(((struct ActingScene *)p)->fB0, *(u8 * *)&((struct ActingScene *)p)->fB4 + table[((u8 *)&order)[i]], 1);
        }
    }
}





void STA_ACTING_LoadRankAnim(u8 *p, u8 n, u8 i)
{
    void *table;
    u16 score;
    table = ARC_UTIL_LoadHandleMember((void *)(((struct ActingScene *)p)->f18.u), n + 0x37, 0, ((struct ActingScene *)p)->f0);
    score = *(u16 *)(*(u8 **)(*(u8 * *)&((struct ActingScene *)p)->f30 + i * 4 + 4) + 0x4a);
    if (score >= 70) {
        func_021FAD0C(((struct ActingScene *)p)->fB0, table, 0, (u8)(1 << i));
    } else if (score >= 40) {
        func_021FAD0C(((struct ActingScene *)p)->fB0, table, 1, (u8)(1 << i));
    } else {
        func_021FAD0C(((struct ActingScene *)p)->fB0, table, 2, (u8)(1 << i));
    }
}





void STA_ACTING_LoadAnimMember(char *p, u8 n, u8 mask){void *table;table=ARC_UTIL_LoadHandleMember((void *)(((struct ActingScene *)p)->f18.u),n+0x4b,0,((struct ActingScene *)p)->f0);func_021FAD0C(((struct ActingScene *)p)->fB0,table,0,mask);}





/*
 * Palette fade, 16 colours. The object holds a u16 phase at +0x168 (advanced by 0x160, wrapped at
 * 0x10000), 16 base colours at +0x16A, s8 red, green and blue deltas at +0x18A, +0x19A, +0x1AA,
 * and 16 output colours at +0x1BA. The factor is (cos table entry + 0x1000) / 2. Each channel gets
 * (s8 delta * factor >> 12) added, then the colours go to func_02061CA4(31, 0, out, 32).
 * Twins for the channel pack: ov068 021B9D68, ov104 021B89DC.
 * What closed it: a struct view of the object (p->phase, p->base[i], p->out[i]) with no colour
 * local (every channel reads p->base[i], CSE keeps one load), which makes the allocator spill p
 * instead of p + 2i; compound assignment `p->phase += 0x160` in the else wrap
 * arm (the else arm then recomputes the sum, as the image does); `u8 i` declared before
 * `int factor`. final push 2026-10-05 G9L6.
 */
void STA_ACTING_FadePalette(Fade *p)
{
    u8 i;
    int factor;
    if (p->phase + 0x160 >= 0x10000)
        p->phase = p->phase - 0xFEA0;
    else
        p->phase += 0x160;
    factor = (FX_SinCosTable_[(p->phase >> 4) * 2] + 0x1000) / 2;
    for (i = 0; i < 16; i++) {
        u8 b = (p->base[i] & 0x7C00) >> 10;
        u8 r = p->base[i] & 0x1F;
        u8 g = (p->base[i] & 0x3E0) >> 5;
        int B = b + (s8)((p->db[i] * factor) >> 12);
        int R = r + (s8)((p->dr[i] * factor) >> 12);
        int G = g + (s8)((p->dg[i] * factor) >> 12);
        p->out[i] = (B << 10) | (R | (G << 5));
    }
    func_02061CA4((void *)31, 0, (u32)p->out, 32);
}




void STA_ACTING_CreateText(u8 *p)
{
    int zero;
    ((struct ActingScene *)p)->fD0.u=BMP_WIN_Create(1,4,20,24,4,15,1);
    BMP_WIN_TransferChars((struct Descriptor *)((struct ActingScene *)p)->fD0.u);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct ActingScene *)p)->fD0.u));
    func_020409B4(1);
    zero=0;
    ((struct ActingScene *)p)->fD4.u=(u32)GF_FONT_Create(23,0,0,0,((struct ActingScene *)p)->f0);
    ((struct ActingScene *)p)->fDC.u=(u32)MSGDATA_CreateFromMemory(((struct ActingPartB *)(*(u8 * *)&((struct ActingPartA *)(*(u8 * *)&((struct ActingScene *)p)->f30))->f18))->f8,((struct ActingScene *)p)->f0);
    func_02049B40(23,5,0,480,32,((struct ActingScene *)p)->f0);
    ((struct ActingScene *)p)->fCC.u=(u32)TCBL_Create(((struct ActingScene *)p)->f0,((struct ActingScene *)p)->f0,3,256);
    ((struct ActingScene *)p)->fD8.u=zero;
    ((struct ActingScene *)p)->fE0.u=zero;
    ((struct ActingScene *)p)->fE4.u=zero;
    ((struct ActingScene *)p)->fE8.u=PRINTSYS_QUE_Create((void *)(u32)((struct ActingScene *)p)->f0);
}




void STA_ACTING_UpdateText(u8 *p)
{
    TCBL_Main(((struct ActingScene *)p)->fCC.p);
    if (((struct ActingScene *)p)->fD8.p && PRINTSYS_PrintStreamGetState(((struct ActingScene *)p)->fD8.p) == 2) {
        PRINTSYS_PrintStreamDelete(((struct ActingScene *)p)->fD8.p);
        ((struct ActingScene *)p)->fD8.p = 0;
    }
    if (((struct ActingScene *)p)->fE4.s == 1) {
        PRINTSYS_QUE_Main(((struct ActingScene *)p)->fE8.p);
        if (PRINTSYS_QUE_IsFinished(((struct ActingScene *)p)->fE8.p) == 1) {
            BMP_WIN_TransferChars(((struct ActingScene *)p)->fD0.p);
            ((struct ActingScene *)p)->fE4.s = 0;
        }
    }
}




/*
 * abi: 0201CCE4 forwards the pointer result of matched 0201CD10; the caller stores it at d8.
 */
void STA_ACTING_PrintText(u8 *p, u16 index, u32 speed)
{
    Zero zero;
    if (((struct ActingScene *)p)->fD8.p) {
        PRINTSYS_PrintStreamDelete(((struct ActingScene *)p)->fD8.p);
        ((struct ActingScene *)p)->fD8.p = 0;
    }
    if (((struct ActingScene *)p)->fE0.p) {
        STRBUF_Delete(((struct ActingScene *)p)->fE0.p);
        ((struct ActingScene *)p)->fE0.p = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(((struct ActingScene *)p)->fD0.p), 0);
    zero = ZERO;
    ((struct ActingScene *)p)->fE0.p = func_02045EC0(((struct ActingScene *)p)->fDC.p, index);
    if (speed != 255) {
        ((struct ActingScene *)p)->fD8.p = PRINTSYS_PrintStream(((struct ActingScene *)p)->fD0.p, zero, zero,
            ((struct ActingScene *)p)->fE0.p, ((struct ActingScene *)p)->fD4.p, speed,
            ((struct ActingScene *)p)->fCC.p, 2, ((struct ActingScene *)p)->f0, zero);
    } else {
        PRINTSYS_PrintQue(((struct ActingScene *)p)->fE8.p, (u32)BMP_WIN_GetBmp(((struct ActingScene *)p)->fD0.p),
            zero, zero, ((struct ActingScene *)p)->fE0.p, *(u32 *)&((struct ActingScene *)p)->fD4);
        ((struct ActingScene *)p)->fE4.s = 1;
        STRBUF_Delete(((struct ActingScene *)p)->fE0.p);
        ((struct ActingScene *)p)->fE0.p = (void *)zero;
    }
}




void STA_ACTING_ClearText(u8 *p)
{
    if (((struct ActingScene *)p)->fD8.p) {
        PRINTSYS_PrintStreamDelete(((struct ActingScene *)p)->fD8.p);
        ((struct ActingScene *)p)->fD8.p = 0;
    }
    if (((struct ActingScene *)p)->fE0.p) {
        STRBUF_Delete(((struct ActingScene *)p)->fE0.p);
        ((struct ActingScene *)p)->fE0.p = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(((struct ActingScene *)p)->fD0.p), 0);
    BMP_WIN_TransferChars(((struct ActingScene *)p)->fD0.p);
}




void STA_ACTING_UpdateSelection(char *p)
{
    u8 count, i, j, selected, index;
    if (*(int *)(p + 0xEC) != 1) return;
    count = 0;
    i = 0;
    for (; i < 4; i++) func_021FA558(*(char **)(p + 0xB8), i, 0);
    func_021FA56C(*(char **)(p + 0xB8), 255);
    *(u8 *)(p + 0xF1) = 4;
    *(u8 *)(p + 0xF2) = 4;
    for (j = count; j < 4; j = (u8)(j + 1)) {
        if (*(int *)(p + 0x94 + j * 4) != 0) {
            selected = j;
            count = (u8)(count + 1);
        }
    }
    index = *(u8 *)(p + 0x11C);
    if (index < 4) {
        *(u8 *)(p + 0xF1) = index;
        func_021FA558(*(char **)(p + 0xB8), index, 1);
    } else if ((index = *(u8 *)(p + 0xF0)) < 4) {
        *(u8 *)(p + 0xF1) = index;
        func_021FA558(*(char **)(p + 0xB8), index, 1);
    } else if (count == 1) {
        *(u8 *)(p + 0xF2) = selected;
        func_021FA56C(*(char **)(p + 0xB8), selected);
    } else {
        for (j = 0; j < 4; j = (u8)(j + 1)) {
            if (*(u8 *)(p + 0xF3 + j) == 0)
                func_021FA558(*(char **)(p + 0xB8), j, 1);
        }
    }
    *(int *)(p + 0xEC) = 0;
}





/*
 * The original stores p+0xEC = 1 unconditionally after the if/else, so the
 * store is a shared tail reached by both arms (b .end out of the `c == 1`
 * arm); writing it inside the else made the compiler emit two epilogues.
 * See docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 */
void STA_ACTING_SetSelection(char *p, u8 v, int c)
{
    if (c == 1) {
        ((struct ActingScene *)p)->fF0 = v;
    } else {
        ((struct ActingScene *)p)->fF0 = 4;
    }
    ((struct ActingScene *)p)->fEC = 1;
}




void STA_ACTING_MarkDirty(char *p){((struct ActingScene *)p)->fEC=1;}




void STA_ACTING_RankScores(u8 *p)
{
    u8 i, j;
    u16 score;
    for (i = 0; i < 4; i++) p[0xf3 + i] = 0;
    for (i = 0; i < 4; i++) {
        score = (u16)(*(u16 *)((*(u8 ***)(p + 0x30))[i + 1] + 0x4a) + p[0xf7 + i]);
        for (j = 0; j < 4; j++) {
            if (i != j) {
                if ((u16)(*(u16 *)((*(u8 ***)(p + 0x30))[j + 1] + 0x4a) + p[0xf7 + j]) > score) p[0xf3 + i]++;
            }
        }
    }
}





/*
 * Addresses are Black-image addresses.
 */
void STA_ACTING_InstallBgm(char *p, int a)
{
    ((struct ActingScene *)p)->f24.s = 1;
    GFL_USE_InstallBgmBuffers(((struct ActingScene *)p)->f1DC, ((struct ActingScene *)p)->f1E0, a);
}





void STA_ACTING_StartSeq(char *p, int a)
{
    ((struct ActingScene *)p)->f28.s = 1;
    GFL_USE_StartSeq(a);
}




void STA_ACTING_StopSeq(char *p){((struct ActingScene *)p)->f28.s=0;GFL_USE_StopSeqAndUnload();}





/*
 * lever: The matched 020064B8 body reads four arguments; incoming r3 is
 * forwarded unchanged, preventing the erroneous three-argument tail call.
 *
 * Addresses are Black-image addresses.
 */
int STA_ACTING_ReplaceWaveData(char *p, u32 a, u32 b, u32 d)
{
    return GFL_USE_ReplaceWaveData(a, b, ((struct ActingScene *)p)->f1E4, d);
}





void STA_ACTING_PlayBgm(char *p, int a)
{
    ((struct ActingScene *)p)->f2C.s = 1;
    GFL_USE_CancelChangeAndPlayBgm(a, 0xffff);
}




void STA_ACTING_StopBgm(char *p){((struct ActingScene *)p)->f2C.s=0;GFL_USE_CancelChangeAndStopBgm();}




void STA_ACTING_PlayRankSe(char *p)
{
    u8 i;
    u8 min = 255;
    char *a = *(char * *)&((struct ActingScene *)p)->f30;
    for (i = 0; i < 4; i++) {
        u16 v = *(u16 *)(*(char **)(a + i * 4 + 4) + 0x4a) + *(u8 *)(p + i + 0xf7);
        if (min > v) min = v;
    }
    if (min >= 70) GFL_USE_PlaySeDefaultVolume(1578);
    else if (min >= 30) GFL_USE_PlaySeDefaultVolume(1579);
    else if (min >= 1) GFL_USE_PlaySeDefaultVolume(1580);
}



void STA_ACTING_RequestAction(char *p,int value){if(!**(int * *)&((struct ActingScene *)p)->f30)STA_ACTING_ApplyAction(p,((struct ActingScene *)p)->fA,value);else{((struct ActingScene *)p)->f15C=1;((struct ActingScene *)p)->f160=value;}}



void STA_ACTING_ApplyAction(char *p, u32 i, int v)
{
    Enabled one;
    one = ENABLED;
    i = (u32)p + i * 4;
    ((struct ScriptOwner *)i)->fFC = one;
    ((struct ScriptOwner *)i)->f10C = v;
}



int STA_ACTING_GetCurrentAction(char *p){return STA_ACTING_GetActionByIndex(p,((struct ActingScene *)p)->fA);}



int STA_ACTING_GetActionByIndex(char *p,u32 i){if(func_021F7A80(*(char * *)&((struct ActingScene *)p)->f40,*(char **)((u32)p+i*4+0x44))==1)return 1;return *(int *)((u32)p+0xfc+i*4);}



/*
 * lever: slots[count] = i; count++; keeps the byte store before the increment; if/else field stores preserve the shared flag-store block.
 */
void STA_ACTING_ProcessRecords(char *p)
{
    u8 count = 0;
    u8 slots[4];
    u8 i;
    int action;
    int index;
    int result;
    STA_ACTING_TickActionTimers(p);
    if (**(void ** *)&((struct ActingScene *)p)->f30 && ((struct ActingScene *)p)->f15C == 1) {
        if (STA_NET_SendKindA(**(void ** *)&((struct ActingScene *)p)->f30, (u8)((struct ActingScene *)p)->f160) == 1)
            ((struct ActingScene *)p)->f15C = 0;
    }
    if (!**(void ** *)&((struct ActingScene *)p)->f30) {
        for (i = 0; i < 4; i++) {
            if (*(int *)(p + i * 4 + 0xFC) == 1) {
                func_021F79A8(*(char * *)&((struct ActingScene *)p)->f40, *(char **)(p + i * 4 + 0x44), *(int *)(p + i * 4 + 0x10C));
                slots[count] = i;
                count++;
                *(int *)(p + i * 4 + 0xFC) = 0;
                if (*(int *)(p + i * 4 + 0x10C) == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (*(int *)(p + i * 4 + 0x10C) == 8) *(int *)(p + i * 8 + 0x140) = 1;
                STA_ACTING_ScheduleActions(p, 2, i);
            }
        }
        if (count != 0) {
            if (((struct ActingScene *)p)->f11C == 4) ((struct ActingScene *)p)->f120 = 1;
            else ((struct ActingScene *)p)->f120 = 0;
            ((struct ActingScene *)p)->f11E = 180;
            ((struct ActingScene *)p)->f11C = slots[func_02005728(count)];
            ((struct ActingScene *)p)->f11D = *(int *)(p + ((struct ActingScene *)p)->f11C * 4 + 0x10C);
            ((struct ActingScene *)p)->fEC = 1;
        }
    } else {
        index = STA_SLOT_GetCurrentKey(**(void ** *)&((struct ActingScene *)p)->f30);
        if ((unsigned)index < 4) {
            if (((struct ActingScene *)p)->f11C == 4) ((struct ActingScene *)p)->f120 = 1;
            else ((struct ActingScene *)p)->f120 = 0;
            ((struct ActingScene *)p)->f11E = 180;
            ((struct ActingScene *)p)->f11C = index;
            ((struct ActingScene *)p)->f11D = STA_SLOT_GetStateByKey(**(void ** *)&((struct ActingScene *)p)->f30, index);
            ((struct ActingScene *)p)->fEC = 1;
            STA_SLOT_ClearCurrent(**(void ** *)&((struct ActingScene *)p)->f30);
        }
        for (i = 0; i < 4; i++) {
            action = STA_SLOT_GetStateByKey(**(void ** *)&((struct ActingScene *)p)->f30, i);
            if (action != 10) {
                func_021F79A8(*(char * *)&((struct ActingScene *)p)->f40, *(char **)(p + i * 4 + 0x44), action);
                STA_SLOT_ResetStateByKey(**(void ** *)&((struct ActingScene *)p)->f30, i);
                if (action == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (action == 8) *(int *)(p + i * 8 + 0x140) = 1;
                STA_ACTING_ScheduleActions(p, 2, i);
            }
        }
    }
    if (((struct ActingScene *)p)->f11E != 0) {
        if (((struct ActingScene *)p)->f11E > ((struct ActingScene *)p)->f1E8) {
            ((struct ActingScene *)p)->f11E -= (u16)((struct ActingScene *)p)->f1E8;
            return;
        }
        ((struct ActingScene *)p)->f11E = 0;
        if (((struct ActingScene *)p)->f120 == 1) {
            if (!**(void ** *)&((struct ActingScene *)p)->f30) {
                result = STA_ACTING_AddScore(p, ((struct ActingScene *)p)->f11C, ((struct ActingScene *)p)->f11D);
                *(int *)(*(char **)(*(char * *)&((struct ActingScene *)p)->f30 + ((struct ActingScene *)p)->f11C * 4 + 4) + ((struct ActingScene *)p)->f11D * 4 + 0x54) = 1;
                GFL_USE_PlaySeDefaultVolume(result);
            } else if (GFL_NET_IsParentAid() == 1) {
                result = STA_ACTING_AddScore(p, ((struct ActingScene *)p)->f11C, ((struct ActingScene *)p)->f11D);
                if (result == 1580) STA_SLOT_PushRecord(**(void ** *)&((struct ActingScene *)p)->f30, ((struct ActingScene *)p)->f11C, ((struct ActingScene *)p)->f11D, 1);
                else STA_SLOT_PushRecord(**(void ** *)&((struct ActingScene *)p)->f30, ((struct ActingScene *)p)->f11C, ((struct ActingScene *)p)->f11D, 2);
            }
        }
        ((struct ActingScene *)p)->f11C = 4;
        ((struct ActingScene *)p)->fEC = 1;
    }
}



int STA_ACTING_AddScore(char *p, unsigned i, unsigned j)
{
    u16 v;
    u8 old;
    v = MUSICAL_PROGRAM_GetCategoryShare((int)(((struct ActingPartA *)(*(char * *)&((struct ActingScene *)p)->f30))->f14), (u8)(int)func_021F5140((void *)STA_ACTING_GetActorCount((u8 *)p), (u16)(*(u16 *)(*(char **)(*(char * *)&((struct ActingScene *)p)->f30 + i * 4 + 4) + j * 6 + 0x14))));
    old = *(u8 *)(p + 0xf7 + i);
    *(u8 *)(p + 0xf7 + i) = old + v;
    STA_ACTING_RankScores((u8 *)p);
    return (unsigned)v >= 7 ? 1579 : 1580;
}



void STA_ACTING_TickActionTimers(char *p)
{
    u8 i;
    if (**(void ** *)&((struct ActingScene *)p)->f30 != 0 && GFL_NET_IsParentAid() != 1) return;
    for (i = 0; i < 4; i++) {
        if (*(u16 *)(p + i * 2 + 0x124) != 0) {
            *(u16 *)(p + i * 2 + 0x124) -= 1;
            if (*(u16 *)(p + i * 2 + 0x124) == 0) {
                if (**(void ** *)&((struct ActingScene *)p)->f30 == 0) STA_ACTING_ApplyAction(p, i, *(int *)(p + i * 4 + 0x12c));
                else STA_SLOT_SetValueByKey(**(void ** *)&((struct ActingScene *)p)->f30, i, *(int *)(p + i * 4 + 0x12c));
            }
        }
    }
}



static inline u32 random_below(u32 n)
{
    u32 draw;
    draw = func_0203F0A8();
    return ((u64)draw * n) >> 32;
}



/*
 * lever: The final random choice is a ternary; an if/else shares the earlier action-seven assignment and leaves 36 bytes different.
 * ABI: The matched 0203D378 body returns u32(void); the preceding guard loads r0 without an argument to that call.
 */
void STA_ACTING_ScheduleActions(char *p, int mode, u8 slot)
{
    u8 i;
    if (**(void ** *)&((struct ActingScene *)p)->f30 && GFL_NET_IsParentAid() != 1) return;
    for (i = 0; i < 4; i++) {
        int eligible[2] = {0, 0};
        char *record = *(char **)(*(char * *)&((struct ActingScene *)p)->f30 + i * 4 + 4);
        Action action;
        int value;
        if (((struct ActingRecord *)record)->f0 != 2 || STA_ACTING_GetActionByIndex(p, i) == 1 || *(u16 *)(p + i * 2 + 0x124) != 0) continue;
        if (((struct ActingRecord *)record)->f3E != 255 && !*(int *)(p + i * 8 + 0x13C)) eligible[0] = 1;
        if (((struct ActingRecord *)record)->f44 != 255 && !*(int *)(p + i * 8 + 0x140)) eligible[1] = 1;
        if (!eligible[0] && !eligible[1]) continue;
        if (eligible[0] == 1 && eligible[1] == 0) action = ACTION7;
        else if (eligible[1] == 1 && eligible[0] == 0) action = ACTION8;
        else {
            action = (u8)random_below(2) == 0 ? ACTION7 : ACTION8;
        }
        switch (mode) {
        case 1:
            if (((struct ActingRecord *)record)->f78 == 65533 && i == slot) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(30) + 30;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        case 2:
            if (((struct ActingRecord *)record)->f78 == 65535 && random_below(100) < 50) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(60) + 60;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            if (((struct ActingRecord *)record)->f78 == 65534 && random_below(100) < 25) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(60) + 60;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        case 0:
            if (((struct ActingRecord *)record)->f78 != 0 && ((struct ActingRecord *)record)->f78 < 65533) {
                value = ((struct ActingRecord *)record)->f78 + (s8)(random_below(121) - 60);
                if (value < 0) *(u16 *)(p + i * 2 + 0x124) = 0;
                else *(u16 *)(p + i * 2 + 0x124) = value;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        }
    }
}




void STA_ACTING_CreateAnimHandle(char *p)
{
    ((struct ActingScene *)p)->fBC = func_021F9EDC(((struct ActingScene *)p)->f6C, 0x36);
}




void STA_ACTING_DeleteAnimHandle(char *p)
{
    func_021F9F58(((struct ActingScene *)p)->f6C, ((struct ActingScene *)p)->fBC);
}



void STA_ACTING_PositionAnim(char *p, unsigned i)
{
    Vec v;
    u8 j;
    func_021F8044(((struct ActingScene *)p)->f40, *(void **)(p + i * 4 + 0x44), (unsigned int *)(&v));
    v.x /= 16;
    v.y = (0xc0000 - (v.y - 0x20000)) / 16;
    v.z = 0xb4000;
    for (j = 0; j < 3; j++) func_021F9F74(*(char * *)&((struct ActingScene *)p)->fBC, j, &v.x);
    GFL_USE_PlaySeDefaultVolume(1961);
}




void STA_ACTING_ShowAnim(char *p)
{
    func_021FAAB8(((struct ActingScene *)p)->fA4, 1);
}



void STA_ACTING_HideAnim(char *p){func_021FAAB8(((struct ActingScene *)p)->fA4,0);}



void *STA_ACTING_GetActorSystem(char *p){return ((struct ActingScene *)p)->f40;}



void *STA_ACTING_GetActor(char *p,u32 i){return *(void **)((u32)p+4*i+0x44);}



void *STA_ACTING_GetActObj(void *p){return ((struct ActingScene *)p)->f54;}



u32 *STA_ACTING_GetSlot(void *p,u8 i){return *(u32 **)((u8 *)p+(u32)i*4+0x58);}



void STA_ACTING_SetSlot(void *p,void *v,u32 i){*(void **)((u8 *)p+i*4+0x58)=v;}



void *STA_ACTING_GetAnimHandle(void *p){return ((struct ActingScene *)p)->f6C;}



void *STA_ACTING_GetAnimSlot(void *p,u8 i){return *(void **)((u8 *)p+(u32)i*4+0x70);}



void STA_ACTING_SetAnimSlot(void *p,void *v,u32 i){*(void **)((u8 *)p+i*4+0x70)=v;}



void *STA_ACTING_GetCharSystem(void *p){return ((struct ActingScene *)p)->f90;}



void *STA_ACTING_GetCharSlot(void *p,u8 i){return *(void **)((u8 *)p+(u32)i*4+0x94);}



void STA_ACTING_SetCharSlot(void *p,void *v,u8 i){*(void **)((u8 *)p+(u32)i*4+0x94)=v;}



void *STA_ACTING_GetBoard(void *p){return ((struct ActingScene *)p)->fB8;}



u16 STA_ACTING_GetCameraPos(void *p){return ((struct ActingScene *)p)->f8;}



void STA_ACTING_SetCameraPos(void *p,u16 v){((struct ActingScene *)p)->f8=v;}



u16 STA_ACTING_GetCameraTarget(u8 *p) { return ((struct ActingScene *)p)->f4; }



void STA_ACTING_SetCameraTarget(u8 *p,u16 v) { ((struct ActingScene *)p)->f6=v; }



u32 STA_ACTING_GetActorCount(u8 *p) { return func_021F4F10(*(u8 * *)&((struct ActingScene *)p)->f38); }



/*
 * note: unlabelled getter witnessing ov112 021F6CE0.
 */
int STA_ACTING_GetSelection(char *p) { return ((struct ActingScene *)p)->f11C; }

unsigned char STA_ACTING_GetRecordScore(char *p, unsigned int i) { return *(unsigned short *)(((char **)(*(char **)(p + 0x30) + i * 4))[1] + 0x4A); }

unsigned char STA_ACTING_GetBonus(char *p, unsigned int i) { return *(unsigned char *)(p + i + 0xF7); }

void STA_ACTING_SetField10(char *p, unsigned int v) { *(unsigned int *)(p + 0x10) = v; }
