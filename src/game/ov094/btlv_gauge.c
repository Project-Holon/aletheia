/*
 * file:     btlv_gauge.c
 * unit:     yes
 * function: func_02206BC8, func_02206E28, func_02206EB4, func_022070C0, func_02207288, func_02207430, func_0220778C, func_0220785C, func_0220793C, func_02207960, BTLV_GAUGE_PlaceSlot, BTLV_GAUGE_StartHpChangeAnimated, BTLV_GAUGE_StartHpChangeInstant, BTLV_GAUGE_StartExpGain, BTLV_GAUGE_RefreshForLevelUp, BTLV_GAUGE_IsAnimating, BTLV_GAUGE_SetSideVisible, BTLV_GAUGE_SetSlotVisible, BTLV_GAUGE_IsSlotOccupied, BTLV_GAUGE_TakeSlotEvent, BTLV_GAUGE_StartHpChange, BTLV_GAUGE_UpdateHpAnim, BTLV_GAUGE_StartExpChange, BTLV_GAUGE_UpdateExpAnim, BTLV_GAUGE_StepValue, BTLV_GAUGE_CalcTileFill, BTLV_GAUGE_CalcPixelChange, BTLV_GAUGE_DrawNickname, BTLV_GAUGE_DrawGender, BTLV_GAUGE_DrawBar, BTLV_GAUGE_DrawHpNumbers, BTLV_GAUGE_DrawLevel, BTLV_GAUGE_DrawCaughtIcon, BTLV_GAUGE_DrawHpLoss, BTLV_GAUGE_UpdateLevelUp, BTLV_GAUGE_BobSlot, BTLV_GAUGE_SetStatusIcon, BTLV_GAUGE_SelectSlot, BTLV_GAUGE_IsLowHpBgmPlaying, BTLV_GAUGE_SetLowHpBgmPlaying, BTLV_GAUGE_SetSavedBgmNo, BTLV_GAUGE_SetBgmReplaced, BTLV_GAUGE_SetLowHpBgmSuppressed, BTLV_GAUGE_GetSlotHealthInfo, BTLV_GAUGE_RequestStop, BTLV_GAUGE_HideSlot, BTLV_GAUGE_UpdateLowHpBgm, BTLV_GAUGE_TaskSlideSlot, BTLV_GAUGE_TaskFlashPalettes, BTLV_GAUGE_SetBgmPlayerParam, BTLV_GAUGE_CalcBarPixels, BTLV_GAUGE_SetSlotBarsVisible
 * address:  0x02206BC8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btlv_effvm.c, btlv_b_gauge.c, btlv_bg.c, btlv_finger_cursor.c by tools/splitfile.py.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA8  0x02030DA8  arm
 *   BTLV_GAUGE_StartHpChangeAnimated  0x02207B4C  thumb  ov094
 *   BTLV_GAUGE_StartHpChangeInstant  0x02207B68  thumb  ov094
 *   BTLV_GAUGE_StartExpGain 0x02207B84 thumb ov094
 *   BTLV_GAUGE_RefreshForLevelUp 0x02207BAC thumb ov094
 *   BTLV_GAUGE_RequestStop 0x022089AC thumb ov094
 *   BTLV_GAUGE_IsAnimating 0x02207C94 thumb ov094
 *   BTLV_GAUGE_SetSideVisible 0x02207CC4 thumb ov094
 *   BTLV_GAUGE_SetSlotVisible  0x02207D04  thumb  ov094
 *   BTLV_GAUGE_SetStatusIcon  0x02208814  thumb  ov094
 *   BTLV_GAUGE_SelectSlot 0x02208870 thumb ov094
 *   BTLV_GAUGE_IsSlotOccupied 0x02207D60 thumb ov094
 *   BTLV_GAUGE_GetSlotHealthInfo 0x02208958 thumb ov094
 *   PALANM_RequestFade  0x0202173C  thumb
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   BTLV_GAUGE_IsLowHpBgmPlaying 0x022088F4 thumb ov094
 *   BTLV_GAUGE_SetLowHpBgmPlaying  0x02208900  thumb  ov094
 *   BTLV_GAUGE_SetLowHpBgmSuppressed  0x0220893C  thumb  ov094
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   BTLV_GAUGE_SetSavedBgmNo  0x02208918  thumb  ov094
 *   BTLV_GAUGE_SetBgmReplaced  0x02208924  thumb  ov094
 *   TCBL_IsDeletePending   0x02030EE8  arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_02030734  0x02030734  arm
 *   func_02082A48  0x02082A48  arm
 *   BTLV_GAUGE_PlaceSlot  0x022079C0  thumb  ov094
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_0202D034 0x0202D034 thumb
 *   BTLV_GAUGE_HideSlot  0x022089BC  thumb  ov094
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BMP_Clear 0x02043B5C arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_02082A60 0x02082A60 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   func_020275E4 0x020275E4 thumb
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   BTLV_GAUGE_TakeSlotEvent  0x02207D78  thumb  ov094
 *   func_020276B8 0x020276B8 thumb
 *   func_020276BC 0x020276BC thumb
 *   func_020276C0 0x020276C0 thumb
 *   func_020276B4 0x020276B4 thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   GFL_USE_GetBgmNo 0x02005C44 thumb
 *   BTLV_GAUGE_TaskFlashPalettes 0x02208BFC thumb ov094
 *   d_0220AEC0 0x0220AEC0 data a1
 *   d_0220AABC 0x0220AABC data a2
 *   BTLV_GAUGE_SetBgmPlayerParam  0x02208D24  thumb  ov094
 *   BTLV_GAUGE_SetSlotBarsVisible 0x02208D50 thumb ov094
 *   BTLV_GAUGE_StepValue 0x02207F6C thumb ov094
 *   BTLV_GAUGE_DrawBar 0x022082FC thumb ov094
 *   BTLV_GAUGE_UpdateHpAnim 0x02207E1C thumb ov094
 *   BTLV_GAUGE_UpdateExpAnim 0x02207EF0 thumb ov094
 *   BTLV_GAUGE_UpdateLevelUp 0x022086F8 thumb ov094
 *   BTLV_GAUGE_BobSlot 0x022087C4 thumb ov094
 *   BTLV_GAUGE_UpdateLowHpBgm 0x022089D4 thumb ov094
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   POKE_TOOL_GetExpForLevel 0x02018584 thumb
 *   BTL_MAIN_CheckZukanSeen 0x021B8724 thumb ov093
 *   BTL_POKEPARAM_GetDisplayMon 0x021D5864 thumb ov093
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   BTL_POKEPARAM_GetSickContRaw 0x021D6314 thumb ov093
 *   BTLV_CORE_IsSlotKind1Index15 0x021E8A78 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   func_0200CED4 0x0200CED4 thumb
 *   POKE_TOOL_GetStatusCondition 0x02017F90 thumb
 *   d_0220AAC8 0x0220AAC8 data
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   BTLV_GAUGE_DrawNickname 0x022080F4 thumb ov094
 *   BTLV_GAUGE_DrawGender 0x02208268 thumb ov094
 *   BTLV_GAUGE_DrawHpNumbers 0x02208420 thumb ov094
 *   BTLV_GAUGE_DrawLevel 0x02208550 thumb ov094
 *   BTLV_GAUGE_DrawCaughtIcon 0x02208650 thumb ov094
 *   BTLV_GAUGE_TaskSlideSlot 0x02208B10 thumb ov094
 *   BTLV_GAUGE_CalcBarPixels 0x02208D38 thumb ov094
 *   d_0220AAB4     0x0220AAB4  data   ov094  a2
 *   CLACT_GetActorImageProxy  0x0204B7C8  arm  arm9
 *   BMP_Create  0x02043678  arm  arm9
 *   BMP_Delete  0x020437AC  arm  arm9
 *   BMP_GetPixels  0x020437D4  arm  arm9
 *   sGaugeBarOffsets  0x0220AAD0  data  ov094  a2
 *   sGaugeStatusIconOffsets  0x0220AAC0  data  ov094  a2
 *   sGaugeDefaultPositions  0x0220AAD8  data  ov094  a2
 *   sGaugeLayout2Positions  0x0220AB0C  data  ov094  a2
 *   sGaugeLayout3Positions  0x0220AB2C  data  ov094  a2
 *   CLACT_GetActorAnimSeq  0x0204B898  arm
 *   func_0220793C  0x0220793C  thumb  ov094
 *   func_0201D304 0x0201D304 thumb
 *   func_0201F35C 0x0201F35C thumb
 *   sGaugeStatusAnimTable     0x0220AAF0  data   ov094  a4
 *   sGaugeHomeOffset     0x0220AAB8  data  ov094  a2
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   func_021F882C 0x021F882C thumb ov094
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   sGaugeFlashMasks 0x0220AB4C data a4
 *   func_0209C2B0  0x0209C2B0  arm
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_021F8720 0x021F8720 thumb ov094
 */
#include "../../matched/include/Obj21804.h"
#include "../../matched/include/Obj00380.h"
#include "../../matched/include/Obj00974.h"
#include "btlv_effvm_types.h"
#include "btlv_b_gauge_types.h"
#include "btlv_effect_shared_types.h"
#include "btlv_effvm_shared_types.h"
#include "btlv_clact_shared_types.h"
#include "btlv_input_shared_types.h"

struct QF;

struct Unk021D62A8;

struct Work_v64CC;

struct Blk37;

typedef struct { s16 x, y; } Pt_02206BC8;

typedef struct {
    Obj_02206BC8 *obj;
    int pad[3];
} Task_v64CC;

typedef enum { SLOT_6E28_0, SLOT_6E28_MAX = 8 } Slot_02206E28;

typedef struct {
    unsigned int lo : 2;
    unsigned int b2 : 1;
} Bf_02206BC8;

typedef struct O_022064CC O_022064CC;

typedef struct S S;

typedef struct { u32 v; } Word;

typedef struct {
    u32 f40, f44, f48, f4c, f50, f54;
    u32 f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
    char pad[0x40];
} Entry_v64CC;

typedef struct {
    u32 f0, f4;
    char pad08[0x10];
    u32 pal[6];
    u32 f30, f34, f38, f3c;
    Entry_v64CC entries[8];
    char pad440[8];
    u16 heap;
} Work_v64CC;

typedef struct {
    void *f40, *f44, *f48, *f4c, *f50, *f54;
    unsigned int f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
    char pad[0x40];
} Entry_v778C;

typedef struct { char pad[0x40]; Entry_v778C entries[8]; } Work_022064CC;

typedef struct E_022064CC {
    void *f00;
    char p04[0x0c];
    void *f10;
    char p14[0x30];
    int f44, f48, f4c, f50, f54, f58, f5c, f60, f64;
    char p68[8];
    u32 lo : 3;
    u32 b3 : 1;
    u32 mid : 12;
    u32 mode : 4;
    u32 hi : 12;
    char p74[8];
    void *f7c;
} E_022064CC;

typedef struct O_0220778C { char pad[0x40]; E_022064CC e[8]; } O_0220778C;

typedef struct {
    short x;
    short y;
} Pt_0220778C;

typedef struct {
    unsigned int lo : 3;
    unsigned int b3 : 1;
} Bf;

extern u32 func_020307B0(void *p);

extern void func_02030EAC(struct Node *n);

extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);

void BTLV_GAUGE_SetStatusIcon(BtlvGaugeWork *work, int status, int slotIdx);

extern int GFL_USE_PopBgm(void);

extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);

extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);

extern u32 KEY_GetTrg(void);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void func_02082A48(u16 data, void *destp, u32 size);

void BTLV_GAUGE_PlaceSlot(BtlvGaugeWork *work, int slotIdx, BtlvGaugePoint *offset);

extern void GFL_USE_StopAllSe(void);

extern void GFL_USE_PlaySeDefaultVolume(u32 seNo);

extern u32 POKE_TOOL_GetPartyValue(void *pokeParam, u32 valueId, void *out);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern unsigned int CLACT_DeleteUnit(struct Bank *bank);

extern void *func_020490F4(u32 id, u32 heap);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);

extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);

extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);

extern void ARC_TOOL_DeleteHandle(void *);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_DeleteActor(struct Obj *p);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);

extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);

extern u32 func_020275E4(void);

extern void CLACT_SetActorDrawEnable(struct ClActor *actor, unsigned int enable);

extern u32 func_020276B8(void);

extern u32 func_020276BC(u32 i);

extern u32 func_020276C0(u32 i);

extern u32 func_020276B4(void);

extern void PALANM_BlendChannelMask(unsigned, unsigned, u16, unsigned, unsigned);

extern void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern u16 GFL_USE_GetBgmNo(void);

void BTLV_GAUGE_TaskFlashPalettes(void *task, BtlvGaugeFlashTask *flash);

void BTLV_GAUGE_SetBgmPlayerParam(int bgmParam);

void BTLV_GAUGE_SetSlotBarsVisible(BtlvGaugeWork *work, int slotIdx, int visible);

int BTLV_GAUGE_StepValue(int maxValue, int value, int delta, int *anim, u8 tileCount, int speed);

void BTLV_GAUGE_DrawBar(BtlvGaugeWork *work, int slotIdx, int kind);

void BTLV_GAUGE_UpdateHpAnim(BtlvGaugeWork *work, int slotIdx);

void BTLV_GAUGE_UpdateExpAnim(BtlvGaugeWork *work, int slotIdx);

void BTLV_GAUGE_UpdateLevelUp(BtlvGaugeWork *work, int slotIdx);

void BTLV_GAUGE_BobSlot(BtlvGaugeWork *work, int slotIdx);

void BTLV_GAUGE_UpdateLowHpBgm(BtlvGaugeWork *work);

extern int func_021D59B4(struct BtlPokeParam *pp, int valueId);

extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *pp);

extern u32 POKE_TOOL_GetExpForLevel(u16 species, u16 form, u16 level);

extern int BTL_MAIN_CheckZukanSeen(char *p, void *m);

extern void *BTL_POKEPARAM_GetDisplayMon(struct Work_v64CC *p);

extern u8 POKE_TOOL_GetGender(void *);

extern Word BTL_POKEPARAM_GetSickContRaw(void *, int);

extern int BTLV_CORE_IsSlotKind1Index15(Word);

extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);

extern u32 func_0200CED4(struct Blk37 *p, u16 id);

extern u32 POKE_TOOL_GetStatusCondition(void *);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

void BTLV_GAUGE_DrawNickname(BtlvGaugeWork *work, BtlvGaugeSlot *slot, void *pokeParam);

void BTLV_GAUGE_DrawGender(BtlvGaugeWork *work, BtlvGaugeSlot *slot);

void BTLV_GAUGE_DrawHpNumbers(const BtlvGaugeWork *work, BtlvGaugeSlot *slot, int hp);

void BTLV_GAUGE_DrawLevel(BtlvGaugeWork *work, BtlvGaugeSlot *slot);

void BTLV_GAUGE_DrawCaughtIcon(BtlvGaugeWork *work, BtlvGaugeSlot *slot);

void BTLV_GAUGE_TaskSlideSlot(void *task, BtlvGaugeSlot *slot);

int BTLV_GAUGE_CalcBarPixels(int value, int maxValue, int scale);

extern void *func_021F86D4(void);

extern int func_021F86E0(void);

int func_021F8710(void);

int func_021F8720(void);

Obj_02206BC8 *func_02206BC8(int a, u16 heap);

void func_02206E28(char *p);

void func_02206EB4(W_02206BC8 *p);

void func_022070C0(W_022070C0 *p, void *a, void *q, int mode, int i);

void func_02207288(W_02207288 *p, void *a, void *q, int mode, int i);

void func_02207430(Work_v64CC *p, int mode, int i);

void func_0220778C(Work_022064CC *p, int i);

void func_0220785C(O_0220778C *o, int unused, int idx, void *data);

extern void func_0220793C(BtlvGaugeSlot *slot);

void func_02207960(char *p, int i);

extern const char d_0220AEC0[];

extern const Pt_02206BC8 d_0220AABC;

extern const Cfg d_0220AAC8;

extern const Pt_0220778C d_0220AAB4;

Obj_02206BC8 *func_02206BC8(int a, u16 heap)
{
    char *hdr;
    Pt_02206BC8 pos;
    Pt_02206BC8 base;
    Obj_02206BC8 *s;
    int i;
    void *arc;
    Task_v64CC *t;
    int lo, hi, kind;

    s = func_02030734(heap, sizeof(Obj_02206BC8), 1, d_0220AEC0, 0x14b);
    s->heap = heap;
    s->h04 = func_020490F4(0xb, (u16)s->heap);
    s->f00 = CLACT_CreateUnit(0x28, 0, s->heap);
    for (i = 0; i < 6; i++) {
        s->f18[i] = CLACT_RegisterPalette(s->h04, 0xa2, 0, (u16)(i * 0x20), s->heap);
        PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(CLACT_GetPaletteVramAddress(s->f18[i], 0) >> 1), 0x20);
    }
    arc = func_020490F4(func_020275E4(), (u16)((s->heap & 0x7fff) | 0x8000));
    s->f30 = CLACT_RegisterCharacter(arc, func_020276B8(), 0, 0, s->heap);
    s->f34 = CLACT_RegisterCellAnim(arc, func_020276BC(1), func_020276C0(1), s->heap);
    s->f38 = CLACT_RegisterPalette(arc, func_020276B4(), 0, 0x100, s->heap);
    s->f3c = CLACT_RegisterPalette(arc, func_020276B4(), 0, 0x120, s->heap);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(CLACT_GetPaletteVramAddress(s->f38, 0) >> 1), 0x20);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(CLACT_GetPaletteVramAddress(s->f3c, 0) >> 1), 0x20);
    PALANM_BlendChannelMask((unsigned)func_021F86E0(), 2, 0x200, 8, 0);
    ARC_TOOL_DeleteHandle(arc);
    s->f10 = ARC_UTIL_LoadScreenDataFromHandle((void *)s->h04, 0xa4, 0, (u32)(&hdr), s->heap);
    s->f14 = ((struct Obj21804 *)hdr)->f14;
    s->f08 = a;
    s->f444 = GFL_USE_GetBgmNo();
    t = func_02030734(heap, sizeof(Task_v64CC), 1, d_0220AEC0, 0x185);
    t->obj = s;
    s->f0c = func_02030DA8(func_021F86D4(), (void (*)(void *, void *))BTLV_GAUGE_TaskFlashPalettes, t, 0);
    switch (func_021F8710()) {
    case 0:
        lo = 0;
        hi = 1;
        kind = 0;
        break;
    case 1:
        lo = 2;
        hi = 5;
        kind = 1;
        break;
    case 2:
    default:
        lo = 2;
        hi = 7;
        kind = 2;
        break;
    case 3:
        lo = 2;
        hi = 7;
        kind = 3;
        break;
    }
    for (i = lo; i <= hi; i++) {
        base = d_0220AABC;
        pos = base;
        if (i & 1)
            pos.x *= -1;
        func_02207430((Work_v64CC *)((Obj_02206BC8 *)s), kind, i);
        s->slot[i].kind = kind;
        BTLV_GAUGE_PlaceSlot((BtlvGaugeWork *)((char *)((Obj_02206BC8 *)s)), i, (BtlvGaugePoint *)((Pt_021FB8F4 *)((Pt_02206BC8 *)&pos)));
    }
    return s;
}

void func_02206E28(char *p)
{
    Slot_02206E28 i;
    int j;

    for (i = SLOT_6E28_0; i < SLOT_6E28_MAX; i++) {
        func_02207960(p, i);
        func_0220778C((Work_022064CC *)p, i);
    }
    if (((Bf_02206BC8 *)(p + 0x440))->b2) {
        GFL_USE_PopBgm();
        BTLV_GAUGE_SetBgmPlayerParam(0);
    }
    for (j = 0; j < 6; j++)
        CLACT_ReleasePalette(*(int *)(p + j * 4 + 0x18));
    CLACT_ReleaseCharacter(((struct Obj00380 *)p)->f30);
    CLACT_ReleaseCellAnim(((struct Obj00380 *)p)->f34);
    CLACT_ReleasePalette(((struct Obj00380 *)p)->f38);
    CLACT_ReleasePalette(((struct Obj00380 *)p)->f3C);
    CLACT_DeleteUnit((struct Bank *)((int)((struct Bank *)(((struct Obj00380 *)p)->f0))));
    func_020307B0(((struct Obj00380 *)p)->f10);
    ARC_TOOL_DeleteHandle((void *)(((struct Obj00380 *)p)->f4));
    func_020307B0((void *)(u32)(W_02206710 * *)TCBL_IsDeletePending((struct S02030EE8 *)(((struct Obj00380 *)p)->fC)));
    func_02030EAC(((struct Obj00380 *)p)->fC);
    func_020307B0(p);
}

/*
 * lever: int mode, i, found puts the scan index in r0 and found in r1; mode, found, i differed at seven bytes.
 */
void func_02206EB4(W_02206BC8 *p)
{
    int mode, i, found;
    KEY_GetTrg();
    if (p->flags.b22) {
        mode = func_021F8710();
        p->flags.b22 = 0;
        if (mode != 0 && mode != 1) {
            found = 0;
            for (i = 0; i < 8; i++) {
                if (p->rows[i].b0) {
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                p->flags.b4 ^= 1;
                for (i = 0; i < 8; i++) {
                    if (!(i & 1) && p->rows[i].b29 == 1 && p->rows[i].b3) {
                        BTLV_GAUGE_SetSlotBarsVisible((BtlvGaugeWork *)((W_02206BC8 *)p), i, 1);
                        BTLV_GAUGE_StepValue(p->rows[i].b, p->rows[i].a, 0, &p->rows[i].f90, 6, 1);
                        BTLV_GAUGE_DrawBar((BtlvGaugeWork *)((struct O_022064CC *)((O_022064CC *)p)), i, 0);
                    }
                }
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (p->rows[i].b0)
            BTLV_GAUGE_UpdateHpAnim((BtlvGaugeWork *)((struct O_022064CC *)((O_022064CC *)p)), i);
        if (p->rows[i].b1) {
            if (p->rows[i].count == 0)
                GFL_USE_PlaySeDefaultVolume(0x56d);
            BTLV_GAUGE_UpdateExpAnim((BtlvGaugeWork *)((struct O_022064CC *)((O_022064CC *)p)), i);
        }
        if (p->rows[i].b28) {
            if (p->rows[i].count < 16)
                p->rows[i].count++;
            if (!p->rows[i].b1 && p->rows[i].count == 16) {
                GFL_USE_StopAllSe();
                p->rows[i].count++;
                p->rows[i].b28 = 0;
            }
        }
        if (p->rows[i].b2)
            BTLV_GAUGE_UpdateLevelUp((BtlvGaugeWork *)((O_022064CC *)p), i);
        if (p->rows[i].b20)
            BTLV_GAUGE_BobSlot((BtlvGaugeWork *)((char *)p), i);
        if (p->rows[i].h != 0 && p->rows[i].b26) {
            if (p->rows[i].flash == 0 || !p->rows[i].b3 || !p->rows[i].b29) {
                CLACT_SetActorDrawEnable((struct ClActor *)((struct Obj *)((struct Obj_02206EB4 *)(p->rows[i].h))), 0);
                p->rows[i].b26 = 0;
            } else {
                CLACT_SetActorDrawEnable((struct ClActor *)((struct Obj *)((struct Obj_02206EB4 *)(p->rows[i].h))), p->rows[i].flash & 1);
                p->rows[i].flash--;
            }
            if (p->flags.b4 && !(i & 1))
                CLACT_SetActorDrawEnable((struct ClActor *)((struct Obj *)((struct Obj_02206EB4 *)(p->rows[i].h))), 0);
        }
    }
    if (!p->flags.b21)
        BTLV_GAUGE_UpdateLowHpBgm((BtlvGaugeWork *)((W_02206BC8 *)p));
}

/*
 * trailing: 02207286..02207288 is two zero alignment bytes.
 *
 * Battle-side twin of func_02207288 (same row layout).
 *
 * lever: BTL_POKEPARAM_GetSickContRaw returns a one-word struct (Word) passed by value to
 * BTLV_CORE_IsSlotKind1Index15, as in the ov093 callers. The struct-return temporary
 * reserves the extra frame word (push r3, sub sp #0x28, slot sp+0x24 never
 * touched) and that one change also flips the row stores to share p + i*0x80
 * in a scratch register; with int prototypes both residues remained
 * (2026-10-01 note: Row pointer local, char* offsets, inline helpers,
 * nested sub-struct, u8 index, x/y locals were all inert).
 */
void func_022070C0(W_022070C0 *p, void *a, void *q, int mode, int i)
{
    u32 exp;
    u16 species;
    int item;

    func_02082A48(0, &p->rows[i].mode, 0x40);
    p->rows[i].a = func_021D59B4(q, 0xd);
    p->rows[i].b = func_021D59B4(q, 0xe);
    p->rows[i].f90 = 0x80000000;
    p->rows[i].fa8 = 0;
    p->rows[i].level = func_021D59B4(q, 0xf);
    p->rows[i].mode = mode;
    p->rows[i].side = i & 1;
    p->rows[i].flags |= 0x08000000;
    if (p->rows[i].level < 100) {
        exp = POKE_TOOL_GetExpForLevel(BTL_POKEPARAM_GetSpecies(q), func_021D59B4(q, 0x13), func_021D59B4(q, 0xf));
        p->rows[i].f94 = func_021D59B4(q, 0x14) - exp;
        p->rows[i].f98 = POKE_TOOL_GetExpForLevel(BTL_POKEPARAM_GetSpecies(q), func_021D59B4(q, 0x13), func_021D59B4(q, 0xf) + 1) - exp;
    } else {
        p->rows[i].f94 = 0;
        p->rows[i].f98 = 0;
    }
    p->rows[i].fa4 = 0x80000000;
    p->rows[i].fa0 = 0;
    p->rows[i].fae = 0;
    p->rows[i].seen = BTL_MAIN_CheckZukanSeen(a, q);
    species = BTL_POKEPARAM_GetSpecies(q);
    if (species != 32 && species != 29)
        p->rows[i].sex = POKE_TOOL_GetGender(BTL_POKEPARAM_GetDisplayMon(q));
    else
        p->rows[i].sex = 2;
    if (BTLV_CORE_IsSlotKind1Index15(BTL_POKEPARAM_GetSickContRaw(q, 5)) == 1 && BTL_POKEPARAM_GetMajorStatusIndex(q) == 5)
        item = 6;
    else
        item = BTL_POKEPARAM_GetMajorStatusIndex(q);
    BTLV_GAUGE_SetStatusIcon((BtlvGaugeWork *)((struct O *)((struct O_022064CC *)((O_022064CC *)p))), item, i);
    BTLV_GAUGE_PlaceSlot((BtlvGaugeWork *)((char *)((Obj_02206BC8 *)((char *)p))), i, (BtlvGaugePoint *)((Pt_021FB8F4 *)((Pt_02206BC8 *)0)));
    BTLV_GAUGE_SetSlotBarsVisible((BtlvGaugeWork *)((W_02206BC8 *)p), i, 1);
    func_0220793C((BtlvGaugeSlot *)((char *)((S *)&p->rows[i])));
    func_0220785C((O_0220778C *)((struct O_022064CC *)p), mode, i, BTL_POKEPARAM_GetDisplayMon(q));
}

/*
 * trailing: 0220742E..02207430 is two zero alignment bytes.
 * lever: rows are an array member of the object; raw offset casts gave 416 bytes and the wrong field-base spills, while the member form gives exact 422 bytes.
 */
void func_02207288(W_02207288 *p, void *a, void *q, int mode, int i)
{
    u32 x, y, exp;
    u16 species;
    func_02082A48(0, &p->rows[i].mode, 0x40);
    p->rows[i].a = POKE_TOOL_GetPartyValue(q, 0xa0, 0);
    p->rows[i].b = POKE_TOOL_GetPartyValue(q, 0xa1, 0);
    p->rows[i].f90 = 0x80000000;
    p->rows[i].fa8 = 0;
    p->rows[i].level = POKE_TOOL_GetPartyValue(q, 0x9e, 0);
    p->rows[i].mode = mode;
    p->rows[i].side = i & 1;
    p->rows[i].flags |= 0x08000000;
    if (p->rows[i].level < 100) {
        x = POKE_TOOL_GetPartyValue(q, 5, 0);
        y = POKE_TOOL_GetPartyValue(q, 0x6f, 0);
        exp = POKE_TOOL_GetExpForLevel(x, y, p->rows[i].level);
        p->rows[i].f94 = POKE_TOOL_GetPartyValue(q, 8, 0) - exp;
        p->rows[i].f98 = POKE_TOOL_GetExpForLevel(x, y, p->rows[i].level + 1) - exp;
    } else {
        p->rows[i].f94 = 0;
        p->rows[i].f98 = 0;
    }
    p->rows[i].fa4 = 0x80000000;
    p->rows[i].fa0 = 0;
    p->rows[i].fae = 0;
    species = POKE_TOOL_GetPartyValue(q, 5, 0);
    p->rows[i].seen = func_0200CED4(a, species);
    if (species != 32 && species != 29)
        p->rows[i].sex = POKE_TOOL_GetGender(q);
    else
        p->rows[i].sex = 2;
    BTLV_GAUGE_SetStatusIcon((BtlvGaugeWork *)((struct O *)((struct O_022064CC *)((O_022064CC *)p))), POKE_TOOL_GetStatusCondition(q), i);
    BTLV_GAUGE_PlaceSlot((BtlvGaugeWork *)((char *)((Obj_02206BC8 *)((char *)p))), i, (BtlvGaugePoint *)((Pt_021FB8F4 *)((Pt_02206BC8 *)0)));
    BTLV_GAUGE_SetSlotBarsVisible((BtlvGaugeWork *)((W_02206BC8 *)((W_02207288 *)p)), i, 1);
    func_0220793C((BtlvGaugeSlot *)((char *)((S *)&p->rows[i])));
    func_0220785C((O_0220778C *)((struct O_022064CC *)p), mode, i, q);
}

void func_02207430(Work_v64CC *p, int mode, int i)
{
    int chr, pal, cell, cpal, j, n, side;
    Cfg cfg;
    switch (mode) {
    case 0:
    case 1:
    default:
        chr = (i & 1) ? 0xa5 : 0xa8;
        pal = (i & 1) ? 0xa6 : 0xa9;
        cell = (i & 1) ? 0xa7 : 0xaa;
        break;
    case 2:
    case 3:
        chr = (i & 1) ? 0xab : 0xae;
        pal = (i & 1) ? 0xac : 0xaf;
        cell = (i & 1) ? 0xad : 0xb0;
        break;
    case 4:
        break;
    }
    if (mode == 3) {
        j = i;
        if (i >= 2)
            j = i - 2;
        cpal = (i < 4) ? 0xa2 : 0xa3;
        CLACT_ReleasePalette(p->pal[j]);
        p->pal[j] = CLACT_RegisterPaletteEx((void *)p->f4, cpal, 0, (u16)(j << 5), 0, 1, p->heap);
        PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(CLACT_GetPaletteVramAddress(p->pal[j], 0) >> 1), 0x20);
    }
    p->entries[i].f58 = CLACT_RegisterCharacter((void *)p->f4, chr, 0, 0, p->heap);
    p->entries[i].f5c = CLACT_RegisterCellAnim((void *)p->f4, pal, cell, p->heap);
    p->entries[i].f60 = CLACT_RegisterCharacter((void *)p->f4, 0xba, 0, 0, p->heap);
    p->entries[i].f64 = CLACT_RegisterCellAnim((void *)p->f4, 0xbb, 0xbc, p->heap);
    p->entries[i].f68 = CLACT_RegisterCharacter((void *)p->f4, 0xb1, 0, 0, p->heap);
    p->entries[i].f6c = CLACT_RegisterCellAnim((void *)p->f4, 0xb2, 0xb3, p->heap);
    p->entries[i].f70 = CLACT_RegisterCharacter((void *)p->f4, 0xb4, 0, 0, p->heap);
    p->entries[i].f74 = CLACT_RegisterCellAnim((void *)p->f4, 0xb5, 0xb3, p->heap);
    side = i & 1;
    if (side == 0) {
        p->entries[i].f78 = CLACT_RegisterCharacter((void *)p->f4, 0xb7, 0, 0, p->heap);
        p->entries[i].f7c = CLACT_RegisterCellAnim((void *)p->f4, 0xb8, 0xb9, p->heap);
    }
    cfg = d_0220AAC8;
    j = i;
    if (i >= 2)
        j = i - 2;
    n = (7 - i) * 3;
    cfg.pri = n + 2;
    p->entries[i].f40 = (u32)CLACT_CreateActor((void *)p->f0, p->entries[i].f58, p->pal[j], p->entries[i].f5c, &cfg, 0, p->heap);
    cfg.pri = n + 1;
    p->entries[i].f44 = (u32)CLACT_CreateActor((void *)p->f0, p->entries[i].f60, p->pal[j], p->entries[i].f64, &cfg, 0, p->heap);
    p->entries[i].f48 = (u32)CLACT_CreateActor((void *)p->f0, p->entries[i].f68, p->pal[j], p->entries[i].f6c, &cfg, 0, p->heap);
    if (func_021F8710() == 3 && i >= 4)
        p->entries[i].f54 = (u32)CLACT_CreateActor((void *)p->f0, p->f30, p->f3c, p->f34, &cfg, 0, p->heap);
    else
        p->entries[i].f54 = (u32)CLACT_CreateActor((void *)p->f0, p->f30, p->f38, p->f34, &cfg, 0, p->heap);
    CLACT_SetActorAutoAnim((struct Obj *)p->entries[i].f54, 1);
    cfg.pri = n;
    p->entries[i].f4c = (u32)CLACT_CreateActor((void *)p->f0, p->entries[i].f70, p->pal[j], p->entries[i].f74, &cfg, 0, p->heap);
    CLACT_SetActorDrawEnable((struct ClActor *)((struct Obj *)p->entries[i].f4c), 0);
    if (side == 0 && mode != 2 && mode != 3)
        p->entries[i].f50 = (u32)CLACT_CreateActor((void *)p->f0, p->entries[i].f78, p->pal[j], p->entries[i].f7c, &cfg, 0, p->heap);
}

/*
 * extent: two zero bytes at 0220785A align the next function.
 * lever: indexed entries in the owning structure retain per-field bases;
 *   a raw offset or cast Entry_v778C array caches the element and is 138/144 bytes.
 */
void func_0220778C(Work_022064CC *p, int i)
{
    if (p->entries[i].f40 == 0)
        return;
    CLACT_ReleaseCharacter(p->entries[i].f58);
    CLACT_ReleaseCharacter(p->entries[i].f60);
    CLACT_ReleaseCharacter(p->entries[i].f68);
    CLACT_ReleaseCharacter(p->entries[i].f70);
    CLACT_ReleaseCellAnim(p->entries[i].f5c);
    CLACT_ReleaseCellAnim(p->entries[i].f64);
    CLACT_ReleaseCellAnim(p->entries[i].f6c);
    CLACT_ReleaseCellAnim(p->entries[i].f74);
    CLACT_DeleteActor(p->entries[i].f40);
    CLACT_DeleteActor(p->entries[i].f44);
    CLACT_DeleteActor(p->entries[i].f48);
    CLACT_DeleteActor(p->entries[i].f4c);
    CLACT_DeleteActor(p->entries[i].f54);
    p->entries[i].f40 = 0;
    p->entries[i].f44 = 0;
    p->entries[i].f48 = 0;
    p->entries[i].f4c = 0;
    p->entries[i].f54 = 0;
    if ((i & 1) == 0) {
        CLACT_ReleaseCharacter(p->entries[i].f78);
        CLACT_ReleaseCellAnim(p->entries[i].f7c);
    }
    if (p->entries[i].f50 != 0) {
        CLACT_DeleteActor(p->entries[i].f50);
        p->entries[i].f50 = 0;
    }
}

void func_0220785C(O_0220778C *o, int unused, int idx, void *data)
{
    BTLV_GAUGE_StepValue(o->e[idx].f4c, o->e[idx].f48, 0, &o->e[idx].f50, 6, 1);
    BTLV_GAUGE_DrawBar((BtlvGaugeWork *)((struct O_022064CC *)o), idx, 0);
    if (o->e[idx].f10 != 0) {
        BTLV_GAUGE_StepValue(o->e[idx].f58, o->e[idx].f54, 0, &o->e[idx].f64, 10, 1);
        BTLV_GAUGE_DrawBar((BtlvGaugeWork *)((struct O_022064CC *)o), idx, 1);
    }
    BTLV_GAUGE_DrawNickname((BtlvGaugeWork *)((O_0220778C *)o), (BtlvGaugeSlot *)((E_022064CC *)(&o->e[idx])), data);
    BTLV_GAUGE_DrawGender((BtlvGaugeWork *)((O_0220778C *)o), (BtlvGaugeSlot *)((E_022064CC *)(&o->e[idx])));
    BTLV_GAUGE_DrawHpNumbers((BtlvGaugeWork *)((O_0220778C *)o), (BtlvGaugeSlot *)((E_022064CC *)(&o->e[idx])), o->e[idx].f48);
    BTLV_GAUGE_DrawLevel((BtlvGaugeWork *)((O_0220778C *)o), (BtlvGaugeSlot *)((E_022064CC *)(&o->e[idx])));
    if (o->e[idx].f44 != 0 && func_021F8720() == 0)
        BTLV_GAUGE_DrawCaughtIcon((BtlvGaugeWork *)((O_0220778C *)o), (BtlvGaugeSlot *)((E_022064CC *)(&o->e[idx])));
    o->e[idx].b3 = 1;
    o->e[idx].mode = 2;
    o->e[idx].f7c = func_02030DA8(func_021F86D4(), (void (*)(void *, void *))BTLV_GAUGE_TaskSlideSlot, &o->e[idx], 0);
}

void func_0220793C(BtlvGaugeSlot *slot)
{
    char *p = (char *)slot;
    int a = ((struct Obj00974 *)p)->f48;
    int b = ((struct Obj00974 *)p)->f4C;

    if (b < 0x30)
        ((struct Obj00974 *)p)->f78 = (unsigned int)BTLV_GAUGE_CalcBarPixels(a << 8, b, 0x30) >> 8;
    else
        ((struct Obj00974 *)p)->f78 = (unsigned int)BTLV_GAUGE_CalcBarPixels(a, b, 0x30);
}

void func_02207960(char *p, int i)
{
    char *q = p + 0xb0;
    int o = i * 128;
    void *t;

    if (((Bf *)(q + o))->b3) {
        Pt_0220778C pt = d_0220AAB4;

        if (i & 1)
            pt.x *= -1;
        BTLV_GAUGE_PlaceSlot((BtlvGaugeWork *)((char *)((Obj_02206BC8 *)p)), i, (BtlvGaugePoint *)((Pt_021FB8F4 *)((Pt_02206BC8 *)&pt)));
        ((Bf *)(q + o))->b3 = 0;
    }
    t = *(void **)(p + o + 0xbc);
    if (t != 0) {
        func_02030EAC(t);
        *(int *)(p + o + 0xbc) = 0;
    }
}

extern void CLACT_AddActorSurfacePos(struct ClActor *actor, const BtlvGaugePoint *delta, u32 space);

extern u16 CLACT_GetActorAnimSeq(struct ClActor *actor);

extern void CLACT_GetActorSurfacePos(struct ClActor *actor, BtlvGaugePoint *out, u16 space);

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

extern struct BmpData *BMP_Create(u32 width, u32 height, u32 depth, u16 heapId);

extern void BMP_Clear(struct BmpData *bmp, u8 value);

extern void GF_FONT_GetTextColor(u8 *fg, u8 *shadow, u8 *bg);

extern void GF_FONT_SetTextColor(u32 fg, u32 shadow, u32 bg);

extern int func_0201D304(struct Strbuf *str, void *font, u32 arg);

extern void PRINTSYS_Print(struct BmpData *bmp, s16 x, s16 y, struct Strbuf *str, void *font);

extern void *BMP_GetPixels(const struct BmpData *bmp);

extern void CLACT_GetActorImageProxy(const struct ClActor *actor, BtlvGaugeImageProxy *dst);

extern void func_02082A60(const void *src, void *dst, int size);

extern void STRBUF_Delete(struct Strbuf *str);

extern void BMP_Delete(struct BmpData *bmp);

extern int func_0202D034(u32 value, u32 maxValue);

extern void func_0201F35C(struct Strbuf *str, int value, u32 digits, u32 mode, u32 padding);

extern void CLACT_SetActorAnimSeq(struct ClActor *actor, u16 animSeq);

extern int GFL_USE_IsBgmFading(void);

extern int func_021F882C(void);

extern void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 arg);

extern void GFL_USE_FadeInBgmFull(u32 frames);

extern int GFL_USE_PushBgm(void);

extern void GFL_USE_FadeOutBgm(u32 frames);

extern int PALANM_RequestFade(void *palAnm, u16 bank, u16 mask, s16 arg3, u8 startLevel, u8 endLevel, u16 frames, void *arg7);

extern u32 PALANM_GetFadeRequestBits(const char *palAnm);

extern int func_0200F300(void);

extern void GFL_USE_SetBgmPlayerParam(int param);

extern int func_0209C2B0(int dividend, int divisor);

void BTLV_GAUGE_StartHpChangeAnimated(BtlvGaugeWork *work, int slotIdx, int newHp);

void BTLV_GAUGE_StartHpChangeInstant(BtlvGaugeWork *work, int slotIdx, int newHp);

void BTLV_GAUGE_StartExpGain(BtlvGaugeWork *work, int slotIdx, int gain);

void BTLV_GAUGE_RefreshForLevelUp(BtlvGaugeWork *work, struct BtlPokeParam *pp, int slotIdx);

int BTLV_GAUGE_IsAnimating(BtlvGaugeWork *work);

void BTLV_GAUGE_SetSideVisible(BtlvGaugeWork *work, int visible, int side);

void BTLV_GAUGE_SetSlotVisible(BtlvGaugeWork *work, int visible, int slotIdx);

int BTLV_GAUGE_IsSlotOccupied(BtlvGaugeWork *work, int slotIdx);

int BTLV_GAUGE_TakeSlotEvent(BtlvGaugeWork *work, int slotIdx);

void BTLV_GAUGE_StartHpChange(BtlvGaugeWork *work, BtlvGaugeSlot *slot, int newHp);

void BTLV_GAUGE_StartExpChange(BtlvGaugeSlot *slot, int gain);

u8 BTLV_GAUGE_CalcTileFill(u32 maxValue, int value, int delta, int *anim, u8 *tileFill, u8 tileCount);

int BTLV_GAUGE_CalcPixelChange(int value, int delta, int maxValue, unsigned int tileCount);

void BTLV_GAUGE_DrawHpLoss(BtlvGaugeWork *work, BtlvGaugeSlot *slot, int barPixels);

void BTLV_GAUGE_SelectSlot(BtlvGaugeWork *work, int selectedSlot);

unsigned int BTLV_GAUGE_IsLowHpBgmPlaying(BtlvGaugeWork *work);

void BTLV_GAUGE_SetLowHpBgmPlaying(BtlvGaugeWork *work, int playing);

void BTLV_GAUGE_SetSavedBgmNo(BtlvGaugeWork *work, int bgmNo);

void BTLV_GAUGE_SetBgmReplaced(BtlvGaugeWork *work, int replaced);

void BTLV_GAUGE_SetLowHpBgmSuppressed(BtlvGaugeWork *work, int suppressed);

int BTLV_GAUGE_GetSlotHealthInfo(BtlvGaugeWork *work, int slotIdx, int *hpState, int *statusAnim);

void BTLV_GAUGE_RequestStop(BtlvGaugeWork *work);

void BTLV_GAUGE_HideSlot(BtlvGaugeWork *work, int slotIdx);

extern const BtlvGaugePointPair sGaugeBarOffsets;

extern const BtlvGaugePointPair sGaugeStatusIconOffsets;

extern const BtlvGaugePointSix sGaugeDefaultPositions;

extern const BtlvGaugePointEight sGaugeLayout2Positions;

extern const BtlvGaugePointEight sGaugeLayout3Positions;

extern s16 FX_SinCosTable_[];

extern BtlvGaugeStatusAnimTable sGaugeStatusAnimTable;

extern const BtlvGaugePoint sGaugeHomeOffset;

extern const BtlvGaugeMaskTable sGaugeFlashMasks;

/* Moves the actors of one gauge to the position of its layout, plus an optional offset. */
void BTLV_GAUGE_PlaceSlot(BtlvGaugeWork *work, int slotIdx, BtlvGaugePoint *offset)
{
    BtlvGaugePointSix defaultPositions;
    BtlvGaugePointEight layout2Positions;
    BtlvGaugePointEight layout3Positions;
    BtlvGaugePoint pos;
    BtlvGaugePointPair barOffsets;
    BtlvGaugePointPair statusOffsets;
    int x;
    int y;

    barOffsets = sGaugeBarOffsets;
    statusOffsets = sGaugeStatusIconOffsets;
    defaultPositions = sGaugeDefaultPositions;
    layout2Positions = sGaugeLayout2Positions;
    layout3Positions = sGaugeLayout3Positions;
    if (work->slots[slotIdx].layout == 2) {
        x = layout2Positions.p[slotIdx].x;
        y = layout2Positions.p[slotIdx].y;
    } else if (work->slots[slotIdx].layout == 3) {
        x = layout3Positions.p[slotIdx].x;
        y = layout3Positions.p[slotIdx].y;
    } else {
        x = defaultPositions.p[slotIdx].x;
        y = defaultPositions.p[slotIdx].y;
    }
    if (offset != 0) {
        x += offset->x;
        y += offset->y;
    }
    pos.x = x;
    pos.y = y;
    CLACT_AddActorSurfacePos(work->slots[slotIdx].frameActor, &pos, 0);
    if ((slotIdx & 1) == 0 && work->slots[slotIdx].layout == 0) {
        pos.x = x + 16;
        pos.y = y + 13;
        CLACT_AddActorSurfacePos(work->slots[slotIdx].hpNumberActor, &pos, 0);
    } else if ((slotIdx & 1) == 0 && work->slots[slotIdx].layout != 1) {
        pos.x = x + 16;
        pos.y = y + 7;
        CLACT_AddActorSurfacePos(work->slots[slotIdx].hpNumberActor, &pos, 0);
    }
    pos.x = x + barOffsets.p[slotIdx & 1].x;
    pos.y = y + barOffsets.p[slotIdx & 1].y;
    CLACT_AddActorSurfacePos(work->slots[slotIdx].hpBarActor, &pos, 0);
    pos.x = x + statusOffsets.p[slotIdx & 1].x;
    pos.y = y + statusOffsets.p[slotIdx & 1].y;
    CLACT_AddActorSurfacePos(work->slots[slotIdx].statusActor, &pos, 0);
    if (work->slots[slotIdx].expBarActor != 0) {
        pos.x = x + 8;
        pos.y = y + 21;
        CLACT_AddActorSurfacePos(work->slots[slotIdx].expBarActor, &pos, 0);
    }
}

/* Starts an HP change with a per-frame speed of 1. */
void BTLV_GAUGE_StartHpChangeAnimated(BtlvGaugeWork *work, int slotIdx, int newHp)
{
    BTLV_GAUGE_StartHpChange(work, &work->slots[slotIdx], newHp);
    work->slots[slotIdx].hpAnimSpeed = 1;
}

/* Starts an HP change that jumps to the target (speed 0). */
void BTLV_GAUGE_StartHpChangeInstant(BtlvGaugeWork *work, int slotIdx, int newHp)
{
    BTLV_GAUGE_StartHpChange(work, &work->slots[slotIdx], newHp);
    work->slots[slotIdx].hpAnimSpeed = 0;
}

/* Starts an EXP gain on a slot. */
void BTLV_GAUGE_StartExpGain(BtlvGaugeWork *work, int slotIdx, int gain)
{
    work->slots[slotIdx].flags.expStep = 0;
    work->slots[slotIdx].flags.startPending = 1;
    BTLV_GAUGE_StartExpChange(&work->slots[slotIdx], gain);
}

/* Reloads HP, level and EXP span from the Pokemon after a level up and fills the EXP bar. */
void BTLV_GAUGE_RefreshForLevelUp(BtlvGaugeWork *work, struct BtlPokeParam *pp, int slotIdx)
{
    int remaining;
    u32 nextLevelExp;

    remaining = work->slots[slotIdx].expMax - work->slots[slotIdx].exp;
    work->slots[slotIdx].hp = func_021D59B4(pp, BTLV_GAUGE_BPP_HP);
    work->slots[slotIdx].maxHp = func_021D59B4(pp, BTLV_GAUGE_BPP_MAX_HP);
    work->slots[slotIdx].hpAnimValue = (int)0x80000000;
    work->slots[slotIdx].hpDelta = 0;
    work->slots[slotIdx].level = func_021D59B4(pp, BTLV_GAUGE_BPP_LEVEL);
    nextLevelExp = POKE_TOOL_GetExpForLevel(BTL_POKEPARAM_GetSpecies(pp), func_021D59B4(pp, BTLV_GAUGE_BPP_FORM), func_021D59B4(pp, BTLV_GAUGE_BPP_LEVEL) + 1);
    work->slots[slotIdx].expPerLevel = nextLevelExp - POKE_TOOL_GetExpForLevel(BTL_POKEPARAM_GetSpecies(pp), func_021D59B4(pp, BTLV_GAUGE_BPP_FORM), func_021D59B4(pp, BTLV_GAUGE_BPP_LEVEL));
    work->slots[slotIdx].flags.levelUpPhase = 0;
    work->slots[slotIdx].flags.levelUpPending = 1;
    work->slots[slotIdx].flags.expStep = 0;
    work->slots[slotIdx].flags.startPending = 1;
    BTLV_GAUGE_StartExpChange(&work->slots[slotIdx], remaining);
}

/* Returns 1 while any gauge animation runs or is requested. */
int BTLV_GAUGE_IsAnimating(BtlvGaugeWork *work)
{
    int i;

    for (i = 0; i < BTLV_GAUGE_SLOT_COUNT; i++) {
        BtlvGaugeSlotFlags *flags;

        flags = &work->slots[i].flags;
        if (flags->hpAnimating || flags->expAnimating || flags->levelUpPending || flags->startPending) return 1;
    }
    return 0;
}

/*
 * Shows or hides the gauges of one side (2 = both sides).
 * Lever: an enum-typed loop counter keeps the entry guard (cmp r4,#8; bge)
 * that a plain int counter rotates away.
 */
void BTLV_GAUGE_SetSideVisible(BtlvGaugeWork *work, int visible, int side)
{
    BtlvGaugeSlotIndex i;

    for (i = BTLV_GAUGE_SLOT_FIRST; i < BTLV_GAUGE_SLOT_COUNT; i = (BtlvGaugeSlotIndex)(i + 1)) {
        if (side == 2 || side == work->slots[i].side) {
            if (work->slots[i].flags.occupied) {
                BTLV_GAUGE_SetSlotVisible(work, visible, (int)i);
            }
        }
    }
}

/* Shows or hides all actors of one gauge. */
void BTLV_GAUGE_SetSlotVisible(BtlvGaugeWork *work, int visible, int slotIdx)
{
    work->slots[slotIdx].flags.visible = visible;
    CLACT_SetActorDrawEnable(work->slots[slotIdx].frameActor, visible);
    BTLV_GAUGE_SetSlotBarsVisible(work, slotIdx, visible);
    if (work->slots[slotIdx].expBarActor != 0) {
        CLACT_SetActorDrawEnable(work->slots[slotIdx].expBarActor, visible);
    }
    if (work->slots[slotIdx].statusActor != 0) {
        if (CLACT_GetActorAnimSeq(work->slots[slotIdx].statusActor) != 0) {
            CLACT_SetActorDrawEnable(work->slots[slotIdx].statusActor, visible);
        }
    }
}

int BTLV_GAUGE_IsSlotOccupied(BtlvGaugeWork *work, int slotIdx)
{
    if (work->slots[slotIdx].flags.occupied) return 1;
    return 0;
}

/* Returns and clears the pending event flag of a slot. */
int BTLV_GAUGE_TakeSlotEvent(BtlvGaugeWork *work, int slotIdx)
{
    int pending = 0;

    if (work->slots[slotIdx].frameActor != 0) {
        BtlvGaugeSlotFlags *flags = &work->slots[slotIdx].flags;

        pending = flags->eventPending;
        flags->eventPending = 0;
    }
    return pending;
}

/*
 * Starts an HP change: the slot goes from its current HP to newHp.
 * Lever: slot->hp is read from the struct in both statements (no local), so
 * the load stays after the 0x50 store.
 */
void BTLV_GAUGE_StartHpChange(BtlvGaugeWork *work, BtlvGaugeSlot *slot, int newHp)
{
    BtlvGaugePoint pos;

    slot->hpAnimValue = 0x80000000;
    slot->hpDelta = slot->hp - newHp;
    if (slot->hp < 0) {
        slot->hp = 0;
    }
    if (slot->hp > slot->maxHp) {
        slot->hp = slot->maxHp;
    }
    slot->flags.hpAnimating = 1;
    if (slot->hpDelta > 0) {
        func_0220793C(slot);
        CLACT_GetActorSurfacePos(slot->hpBarActor, &pos, 0);
        pos.x = pos.x - (s16)(0x30 - slot->hpBarPixels);
        CLACT_AddActorSurfacePos(slot->hpLossActor, &pos, 0);
        CLACT_SetActorDrawEnable(slot->hpLossActor, 1);
        BTLV_GAUGE_DrawHpLoss(work, slot, slot->hpBarPixels);
    }
}

/* One frame of the HP bar animation. */
void BTLV_GAUGE_UpdateHpAnim(BtlvGaugeWork *work, int slotIdx)
{
    BtlvGaugeSlot *slot;
    int shownHp;

    slot = &work->slots[slotIdx];
    shownHp = BTLV_GAUGE_StepValue(slot->maxHp, slot->hp, slot->hpDelta, &slot->hpAnimValue, (int)6, (u16)slot->hpAnimSpeed);
    BTLV_GAUGE_DrawBar(work, slotIdx, 0);
    if (shownHp == -1) {
        slot->hp = slot->hp - slot->hpDelta;
        BTLV_GAUGE_DrawHpNumbers(work, slot, slot->hp);
        slot->flags.hpAnimating = 0;
        slot->hpAnimValue = 0;
        if (slot->hpDelta > 0) {
            slot->flags.hitFlashFrames = 18;
            slot->flags.hitFlashOn = 1;
        }
    } else {
        BTLV_GAUGE_DrawHpNumbers(work, slot, shownHp);
    }
}

/*
 * Starts an EXP change of gain points (clamped to the bar).
 * Lever: the clamp bound slot->expMax is read from the struct twice (no local).
 */
void BTLV_GAUGE_StartExpChange(BtlvGaugeSlot *slot, int gain)
{
    int exp;
    int newExp;

    if (slot->level != 100) {
        exp = slot->exp;
        slot->expAnimValue = 0x80000000;
        newExp = exp + gain;
        if (newExp < 0) {
            gain -= newExp;
        }
        newExp = exp + gain;
        if (newExp > slot->expMax) {
            gain -= newExp - slot->expMax;
        }
        slot->expDelta = -gain;
        if (slot->exp < 0) {
            slot->exp = 0;
        }
        if (slot->exp > slot->expMax) {
            slot->exp = slot->expMax;
        }
        slot->flags.expAnimating = 1;
    }
}

/* One frame of the EXP bar animation. */
void BTLV_GAUGE_UpdateExpAnim(BtlvGaugeWork *work, int slotIdx)
{
    BtlvGaugeSlot *slot;
    int pixelsPerStep;
    int speed;
    int shownExp;

    slot = &work->slots[slotIdx];
    pixelsPerStep = BTLV_GAUGE_CalcPixelChange(slot->exp, slot->expDelta, slot->expMax, 10);
    if (pixelsPerStep == 0) {
        pixelsPerStep = 1;
    }
    speed = slot->expDelta / pixelsPerStep;
    if (speed < 0) {
        speed = -speed;
    }
    if (speed == 0) {
        speed = 1;
    }
    shownExp = BTLV_GAUGE_StepValue(slot->expMax, slot->exp, slot->expDelta, &slot->expAnimValue, (int)10, (u16)speed);
    BTLV_GAUGE_DrawBar(work, slotIdx, 1);
    if (shownExp == -1) {
        slot->exp = slot->exp - slot->expDelta;
        slot->flags.expAnimating = 0;
        slot->expAnimValue = 0;
    }
}

/*
 * Steps a gauge value toward value - delta. anim is the fixed-point
 * accumulator (0x80000000 = not started). Returns the value to show, or -1
 * when the target is reached.
 */
int BTLV_GAUGE_StepValue(int maxValue, int value, int delta, int *anim, u8 tileCount, int speed)
{
    u8 tilePixels;
    int goal;
    int shown;
    int pixelStep;

    tilePixels = tileCount * 8;
    if (*anim == (int)0x80000000) {
        if (maxValue < tilePixels)
            *anim = value << 8;
        else
            *anim = value;
    }
    goal = value - delta;
    if (goal < 0)
        goal = 0;
    else if (goal > maxValue)
        goal = maxValue;
    if (maxValue < tilePixels) {
        if (goal == (*anim >> 8) && (*anim & 0xff) == 0)
            return -1;
    } else if (goal == *anim) {
        return -1;
    }
    if (maxValue < tilePixels) {
        pixelStep = (maxValue << 8) / tilePixels;
        if (delta < 0) {
            *anim += pixelStep;
            shown = *anim >> 8;
            if (shown >= goal || speed == 0) {
                *anim = goal << 8;
                return goal;
            }
        } else {
            *anim -= pixelStep;
            shown = *anim >> 8;
            if ((*anim & 0xff) > 0)
                shown++;
            if (shown <= goal || speed == 0) {
                *anim = goal << 8;
                return goal;
            }
        }
    } else {
        if (delta < 0) {
            *anim += speed;
            if (*anim > goal || speed == 0)
                *anim = goal;
        } else {
            *anim -= speed;
            if (*anim < goal || speed == 0)
                *anim = goal;
        }
        shown = *anim;
    }
    return shown;
}

/*
 * Fills tileFill[0..tileCount-1] with the filled pixels (0..8) of each bar
 * tile and returns the total filled pixels.
 * Levers: tileCount is a u8 stack parameter (ldrb [sp,#0x1c]); the return value is a
 * separate copy `result` of the running count (declared before the loop index j
 * so result takes r2 and j r3).
 */
u8 BTLV_GAUGE_CalcTileFill(u32 maxValue, int value, int delta, int *anim, u8 *tileFill, u8 tileCount)
{
    int goal;
    int i;
    u32 totalPixels;
    u32 pixels;
    u32 result;
    int j;

    goal = value - delta;
    if (goal < 0) {
        goal = 0;
    } else if (goal > (int)maxValue) {
        goal = maxValue;
    }
    totalPixels = tileCount * 8;
    for (i = 0; i < tileCount; i++) {
        tileFill[i] = 0;
    }
    if (maxValue < totalPixels) {
        pixels = (*anim * totalPixels) / maxValue >> 8;
    } else {
        pixels = (*anim * totalPixels) / maxValue;
    }
    result = pixels;
    if (pixels == 0 && goal > 0) {
        result = 1;
        tileFill[0] = 1;
    } else {
        for (j = 0; j < tileCount; j++) {
            if (pixels >= 8) {
                tileFill[j] = 8;
                pixels -= 8;
            } else {
                tileFill[j] = pixels;
                break;
            }
        }
    }
    return result;
}

/* Returns the number of bar pixels that value - delta differs from value. */
int BTLV_GAUGE_CalcPixelChange(int value, int delta, int maxValue, unsigned int tileCount)
{
    int totalPixels;
    int goal;
    int pixelsBefore;
    int pixelsAfter;
    int diff;

    totalPixels = (tileCount << 27) >> 24;
    goal = value - delta;
    if (goal < 0) {
        goal = 0;
    } else if (goal > maxValue) {
        goal = maxValue;
    }
    pixelsBefore = (value * totalPixels) / maxValue;
    pixelsAfter = (goal * totalPixels) / maxValue;
    diff = (signed char)pixelsBefore - (signed char)pixelsAfter;
    diff = (signed char)diff;
    if (diff < 0) {
        diff = -diff;
    }
    return diff;
}

/*
 * Draws the nickname of pokeParam on the frame actor.
 * lever: an enum VRAM base assigned in both copy arms prevents folding
 *   each base-plus-offset into a separate literal pool word.
 */
void BTLV_GAUGE_DrawNickname(BtlvGaugeWork *work, BtlvGaugeSlot *slot, void *pokeParam)
{
    struct Strbuf *name;
    struct BmpData *bmp;
    char *pixels;
    BtlvGaugeImageProxy proxy;
    u8 textColor[3];
    BtlvGaugeVramBase vram;

    name = STRBUF_Create(12, (u16)((work->heapId & 0x7fff) | 0x8000));
    bmp = BMP_Create(8, 2, 32, (u16)((work->heapId & 0x7fff) | 0x8000));
    BMP_Clear(bmp, 0);
    POKE_TOOL_GetPartyValue(pokeParam, 0x73, name);
    GF_FONT_GetTextColor(&textColor[2], &textColor[1], &textColor[0]);
    GF_FONT_SetTextColor(1, 4, 0);
    if (func_0201D304(name, work->font, 0) > 48)
        PRINTSYS_Print(bmp, 2, 5, name, work->font);
    else
        PRINTSYS_Print(bmp, 8, 5, name, work->font);
    GF_FONT_SetTextColor(textColor[2], textColor[1], textColor[0]);
    pixels = BMP_GetPixels(bmp);
    CLACT_GetActorImageProxy(slot->frameActor, &proxy);
    if (slot->side != 0) {
        vram = BTLV_GAUGE_OBJ_VRAM;
        func_02082A60(pixels, (void *)(vram + 0x40 + proxy.vramOffset), 0xc0);
        func_02082A60(pixels + 0x100, (void *)(vram + 0x140 + proxy.vramOffset), 0xc0);
        func_02082A60(pixels + 0xc0, (void *)(vram + 0x400 + proxy.vramOffset), 0x40);
        func_02082A60(pixels + 0x1c0, (void *)(vram + 0x500 + proxy.vramOffset), 0x40);
    } else {
        vram = BTLV_GAUGE_OBJ_VRAM;
        func_02082A60(pixels, (void *)(vram + 0x20 + proxy.vramOffset), 0xe0);
        func_02082A60(pixels + 0x100, (void *)(vram + 0x120 + proxy.vramOffset), 0xe0);
        func_02082A60(pixels + 0xe0, (void *)(vram + 0x400 + proxy.vramOffset), 0x20);
        func_02082A60(pixels + 0x1e0, (void *)(vram + 0x500 + proxy.vramOffset), 0x20);
    }
    STRBUF_Delete(name);
    BMP_Delete(bmp);
}

/* Draws the gender symbol on the frame actor. */
void BTLV_GAUGE_DrawGender(BtlvGaugeWork *work, BtlvGaugeSlot *slot)
{
    BtlvGaugeImageProxy proxy;
    int srcTop;
    int srcBottom;
    BtlvGaugeVramBase vram;

    srcTop = slot->gender * 64 + 0x380;
    srcBottom = slot->gender * 64 + 0x3a0;
    if (slot->gender == 2) {
        srcTop = 0x660;
        srcBottom = 0x660;
    }
    CLACT_GetActorImageProxy(slot->frameActor, &proxy);
    if (slot->side != 0) {
        vram = BTLV_GAUGE_OBJ_VRAM;
        func_02082A60(work->tileGfx + srcTop, (void *)(vram + 0x440 + proxy.vramOffset), 0x20);
        func_02082A60(work->tileGfx + srcBottom, (void *)(vram + 0x540 + proxy.vramOffset), 0x20);
    } else {
        vram = BTLV_GAUGE_OBJ_VRAM;
        func_02082A60(work->tileGfx + srcTop, (void *)(vram + 0x420 + proxy.vramOffset), 0x20);
        func_02082A60(work->tileGfx + srcBottom, (void *)(vram + 0x520 + proxy.vramOffset), 0x20);
    }
}

/*
 * Draws the tiles of a bar: kind 0 is the HP bar, kind 1 the EXP bar.
 * trailing: 0220841E..02208420 is two bytes of zero alignment padding.
 * lever: u8 count retains the result spill; enum VRAM base preserves add
 *   order and register home; zero the loop counter before assigning base.
 */
void BTLV_GAUGE_DrawBar(BtlvGaugeWork *work, int slotIdx, int kind)
{
    BtlvGaugeSlot *slot;
    u8 tileFill[10];
    BtlvGaugeImageProxy proxy;
    int colorOffset, shownValue;
    u8 barPixels, i;
    BtlvGaugeVramBase base;

    slot = &work->slots[slotIdx];
    switch (kind) {
    case 0:
        if (work->flags.altDisplay && !(slotIdx & 1)) break;
        CLACT_GetActorImageProxy(slot->hpBarActor, &proxy);
        barPixels = BTLV_GAUGE_CalcTileFill(slot->maxHp, slot->hp, slot->hpDelta, &slot->hpAnimValue, tileFill, 6);
        shownValue = slot->hpAnimValue;
        if (slot->maxHp < 48) shownValue >>= 8;
        switch (func_0202D034(shownValue, slot->maxHp)) {
        case 0: colorOffset = 0; break;
        case 1: colorOffset = 0x120; break;
        case 2:
        default: colorOffset = 0x240; break;
        }
        for (i = 0; i < 6; i++) {
            base = BTLV_GAUGE_OBJ_VRAM;
            func_02082A60(work->tileGfx + (colorOffset + tileFill[i] * 32), (void *)(proxy.vramOffset + (base + (i + 1) * 32)), 32);
        }
        if (slot->hpDelta > 0) BTLV_GAUGE_DrawHpLoss(work, slot, barPixels);
        break;
    case 1:
        if (slot->expBarActor == 0) break;
        CLACT_GetActorImageProxy(slot->expBarActor, &proxy);
        BTLV_GAUGE_CalcTileFill(slot->expMax, slot->exp, slot->expDelta, &slot->expAnimValue, tileFill, 10);
        if (slot->level == 100) {
            for (i = 0; i < 10; i++) tileFill[i] = 0;
        }
        i = 0;
        base = BTLV_GAUGE_OBJ_VRAM;
        for (; i < 10; i++) {
            func_02082A60(work->tileGfx + (tileFill[i] * 32 + 0x400), (void *)(proxy.vramOffset + (base + (i + 1) * 32)), 32);
        }
        break;
    }
}

/* Draws the "current/max" HP numbers (player side only). */
void BTLV_GAUGE_DrawHpNumbers(const BtlvGaugeWork *work, BtlvGaugeSlot *slot, int hp)
{
    BtlvGaugeImageProxy proxy;
    u16 curTile[3];
    u16 maxTile[3];
    int i, maxHp, maxIdx;
    BtlvGaugeVramBase base;
    if (slot->hpNumberActor != 0) {
        CLACT_GetActorImageProxy(slot->hpNumberActor, &proxy);
        for (i = 0; i < 3; i++) {
            curTile[i] = 0x660;
            maxTile[i] = 0x660;
        }
        if (hp >= 100) {
            curTile[0] = hp / 100 * 32 + 0x520;
            hp %= 100;
        }
        if (hp >= 10 || curTile[0] != 0x660) {
            curTile[1] = hp / 10 * 32 + 0x520;
            hp %= 10;
        }
        curTile[2] = hp * 32 + 0x520;
        maxHp = slot->maxHp;
        maxIdx = 0;
        if (maxHp >= 100) {
            maxTile[maxIdx] = maxHp / 100 * 32 + 0x520;
            maxHp %= 100;
            maxIdx++;
        }
        if (maxHp >= 10 || maxIdx != 0) {
            maxTile[maxIdx] = maxHp / 10 * 32 + 0x520;
            maxHp %= 10;
            maxIdx++;
        }
        maxTile[maxIdx] = maxHp * 32 + 0x520;
        i = 0;
        base = BTLV_GAUGE_OBJ_VRAM;
        for (; i < 3; i++) {
            func_02082A60(work->tileGfx + curTile[i], (void *)(proxy.vramOffset + (base + i * 32)), 32);
            func_02082A60(work->tileGfx + maxTile[i], (void *)(proxy.vramOffset + (base + (i + 4) * 32)), 32);
        }
    }
}

/*
 * Draws the level ("Lv" and number) on the frame actor.
 */
void BTLV_GAUGE_DrawLevel(BtlvGaugeWork *work, BtlvGaugeSlot *slot)
{
    struct Strbuf *text;
    struct BmpData *bmp;
    char *pixels;
    BtlvGaugeImageProxy proxy;
    u8 textColor[3];
    BtlvGaugeVramBase base;
    text = STRBUF_Create(4, (u16)((work->heapId & 0x7fff) | 0x8000));
    bmp = BMP_Create(3, 2, 32, (u16)((work->heapId & 0x7fff) | 0x8000));
    BMP_Clear(bmp, 0);
    func_0201F35C(text, slot->level, 3, 0, 0);
    GF_FONT_GetTextColor(&textColor[2], &textColor[1], &textColor[0]);
    GF_FONT_SetTextColor(1, 4, 0);
    PRINTSYS_Print(bmp, 0, 5, text, work->font);
    GF_FONT_SetTextColor(textColor[2], textColor[1], textColor[0]);
    pixels = BMP_GetPixels(bmp);
    CLACT_GetActorImageProxy(slot->frameActor, &proxy);
    if (slot->side != 0) {
        base = BTLV_GAUGE_OBJ_VRAM;
        func_02082A60(pixels, (void *)(base + 0x480 + proxy.vramOffset), 0x60);
        func_02082A60(pixels + 0x60, (void *)(base + 0x580 + proxy.vramOffset), 0x60);
    } else {
        base = BTLV_GAUGE_OBJ_VRAM;
        func_02082A60(pixels, (void *)(base + 0x460 + proxy.vramOffset), 0x60);
        func_02082A60(pixels + 0x60, (void *)(base + 0x560 + proxy.vramOffset), 0x60);
    }
    STRBUF_Delete(text);
    BMP_Delete(bmp);
}

/* Draws the "already caught" icon (blank when not caught). */
void BTLV_GAUGE_DrawCaughtIcon(BtlvGaugeWork *work, BtlvGaugeSlot *slot)
{
    BtlvGaugeImageProxy proxy;
    int srcOffset;
    BtlvGaugeVramBase vram;

    srcOffset = 0x360;
    if (slot->caught == 0)
        srcOffset = 0x660;
    CLACT_GetActorImageProxy(slot->frameActor, &proxy);
    vram = BTLV_GAUGE_OBJ_VRAM;
    func_02082A60(work->tileGfx + srcOffset, (void *)(vram + 0x120 + proxy.vramOffset), 0x20);
}

/* Draws the tiles of the HP-loss marker: barPixels is the new fill, hpBarPixels the old one. */
void BTLV_GAUGE_DrawHpLoss(BtlvGaugeWork *work, BtlvGaugeSlot *slot, int barPixels)
{
    u8 tileFill[6];
    BtlvGaugeImageProxy proxy;
    int lostPixels;
    int i;
    BtlvGaugeVramBase vram;

    lostPixels = slot->hpBarPixels - barPixels;
    for (i = 0; i < 6; i++)
        tileFill[i] = 8;
    for (i = 5; i >= 0; i--) {
        if (lostPixels >= 8) {
            tileFill[i] = 0;
            lostPixels -= 8;
        } else {
            tileFill[i] = 8 - lostPixels;
            break;
        }
    }
    CLACT_GetActorImageProxy(slot->hpLossActor, &proxy);

    i = 0;
    vram = BTLV_GAUGE_OBJ_VRAM;
    for (; i < 6; i++)
        func_02082A60(work->tileGfx + (tileFill[i] * 32 + 0x6a0), (void *)(vram + i * 32 + proxy.vramOffset), 0x20);
}

/* Level-up sequence of one slot: sound, then redraw of bars, numbers and level. */
void BTLV_GAUGE_UpdateLevelUp(BtlvGaugeWork *work, int slotIdx)
{
    BtlvGaugeSlot *slot;
    slot = &work->slots[slotIdx];
    if (slot->flags.expAnimating == 0) {
        switch (slot->flags.levelUpPhase) {
        case 0:
            GFL_USE_PlaySeDefaultVolume(BTLV_GAUGE_SE_LEVEL_UP);
            slot->flags.levelUpPhase++;
            break;
        case 1:
            slot->flags.levelUpPhase++;
            break;
        case 2:
            slot->exp = 0;
            slot->expMax = slot->expPerLevel;
            slot->expAnimValue = 0x80000000;
            slot->expDelta = 0;
            BTLV_GAUGE_StepValue(slot->maxHp, slot->hp, 0, &slot->hpAnimValue, 6, 1);
            BTLV_GAUGE_StepValue(slot->expMax, slot->exp, 0, &slot->expAnimValue, 10, 1);
            BTLV_GAUGE_DrawBar(work, slotIdx, 0);
            BTLV_GAUGE_DrawBar(work, slotIdx, 1);
            BTLV_GAUGE_DrawHpNumbers(work, slot, slot->hp);
            BTLV_GAUGE_DrawLevel(work, slot);
            slot->flags.levelUpPending = 0;
            break;
        }
    }
}

/*
 * Bobs the gauge of a slot with the sine of the work angle.
 * Lever: the angle is read into an int local (asrs, not lsrs).
 */
void BTLV_GAUGE_BobSlot(BtlvGaugeWork *work, int slotIdx)
{
    BtlvGaugePoint offset;
    int angle;

    offset.x = -16;
    angle = work->flags.bobAngle;
    offset.y = FX_SinCosTable_[2 * (angle >> 4)] / 0x800;
    work->flags.bobAngle += 0x400;
    BTLV_GAUGE_PlaceSlot(work, slotIdx, &offset);
}

/* Sets the status icon of a slot (0 hides it). */
void BTLV_GAUGE_SetStatusIcon(BtlvGaugeWork *work, int status, int slotIdx)
{
    BtlvGaugeStatusAnimTable statusAnim = sGaugeStatusAnimTable;

    if (work->slots[slotIdx].statusActor != 0) {
        if (status == 0) {
            CLACT_SetActorDrawEnable(work->slots[slotIdx].statusActor, 0);
            CLACT_SetActorAnimSeq(work->slots[slotIdx].statusActor, 0);
        } else {
            CLACT_SetActorDrawEnable(work->slots[slotIdx].statusActor, 1);
            CLACT_SetActorAnimSeq(work->slots[slotIdx].statusActor, statusAnim.anim[status]);
        }
    }
}

/* Raises the selected target slot and puts back the previous one (8 = none). */
void BTLV_GAUGE_SelectSlot(BtlvGaugeWork *work, int selectedSlot)
{
    BtlvGaugePoint resetOffset;
    BtlvGaugePoint homeOffset = sGaugeHomeOffset;
    int i;

    for (i = 0; i < 8; i++) {
        if (work->slots[i].frameActor != 0 && work->slots[i].flags.selected) {
            resetOffset = homeOffset;
            work->slots[i].flags.selected = 0;
            BTLV_GAUGE_PlaceSlot(work, i, &resetOffset);
        }
    }
    if (selectedSlot != 8) {
        work->slots[selectedSlot].flags.selected = 1;
        work->flags.bobAngle = 0;
    }
}

unsigned int BTLV_GAUGE_IsLowHpBgmPlaying(BtlvGaugeWork *work)
{
    return work->flags.lowHpBgmPlaying;
}

void BTLV_GAUGE_SetLowHpBgmPlaying(BtlvGaugeWork *work, int playing)
{
    work->flags.lowHpBgmPlaying = playing;
}

void BTLV_GAUGE_SetSavedBgmNo(BtlvGaugeWork *work, int bgmNo)
{
    work->savedBgmNo = bgmNo;
}

void BTLV_GAUGE_SetBgmReplaced(BtlvGaugeWork *work, int replaced)
{
    work->flags.bgmReplaced = replaced;
}

void BTLV_GAUGE_SetLowHpBgmSuppressed(BtlvGaugeWork *work, int suppressed)
{
    work->flags.lowHpBgmSuppressed = suppressed;
}

/* Returns 1 and the HP state and status icon animation of a shown slot, else 0 (state 0, anim 8). */
int BTLV_GAUGE_GetSlotHealthInfo(BtlvGaugeWork *work, int slotIdx, int *hpState, int *statusAnim)
{
    if (work->slots[slotIdx].frameActor == 0 || !work->slots[slotIdx].flags.occupied || work->slots[slotIdx].flags.hidden) {
        *hpState = 0;
        *statusAnim = 8;
        return 0;
    }
    *hpState = func_0202D034(work->slots[slotIdx].hp, work->slots[slotIdx].maxHp);
    *statusAnim = CLACT_GetActorAnimSeq(work->slots[slotIdx].statusActor);
    if (*statusAnim == 0)
        *statusAnim = 8;
    return 1;
}

void BTLV_GAUGE_RequestStop(BtlvGaugeWork *work)
{
    work->flags.stopRequested = 1;
}

void BTLV_GAUGE_HideSlot(BtlvGaugeWork *work, int slotIdx)
{
    if (work->slots[slotIdx].frameActor != 0)
        work->slots[slotIdx].flags.hidden = 1;
}

/* Switches to the low HP music when a player gauge is red and back when none is. */
void BTLV_GAUGE_UpdateLowHpBgm(BtlvGaugeWork *work)
{
    int busy, found, i;
    if (work->flags.bgmChangePending) {
        if (GFL_USE_IsBgmFading() != 0) return;
        work->flags.bgmChangePending = 0;
        if (work->flags.lowHpBgmPlaying) {
            GFL_USE_PopBgm();
            if (!work->flags.bgmReplaced && func_021F882C() != 0) {
                GFL_USE_CancelChangeAndPlayBgm(work->savedBgmNo, 0xffff);
                work->flags.bgmReplaced = 1;
            } else {
                BTLV_GAUGE_SetBgmPlayerParam(0);
            }
            GFL_USE_FadeInBgmFull(24);
        } else {
            BTLV_GAUGE_SetBgmPlayerParam(1);
            GFL_USE_PushBgm();
            GFL_USE_CancelChangeAndPlayBgm(BTLV_GAUGE_BGM_LOW_HP, 0xffff);
        }
        work->flags.lowHpBgmPlaying ^= 1;
        return;
    }
    busy = 0;
    found = 0;
    for (i = 0; i < 8; i++) {
        if (work->slots[i].flags.hpAnimating || work->slots[i].flags.expAnimating || work->slots[i].flags.levelUpPending) {
            busy = 1;
        } else if (work->slots[i].side == 0 && work->slots[i].flags.occupied && work->slots[i].layout != 4) {
            if (func_0202D034(work->slots[i].hp, work->slots[i].maxHp) == 2) found = 1;
        }
    }
    if (!work->flags.lowHpBgmPlaying && work->savedBgmNo != GFL_USE_GetBgmNo()) return;
    if (busy != 0) return;
    if ((work->flags.lowHpBgmPlaying && found == 0) || (!work->flags.lowHpBgmPlaying && found == 1)) {
        work->flags.bgmChangePending = 1;
        GFL_USE_FadeOutBgm(8);
    }
}

/* Task: slides the actors of one slot sideways, eight pixels per frame. */
void BTLV_GAUGE_TaskSlideSlot(void *task, BtlvGaugeSlot *slot)
{
    int step;
    BtlvGaugePoint pos;
    if (slot->side != 0) step = 8;
    else step = -8;
    CLACT_GetActorSurfacePos(slot->frameActor, &pos, 0);
    pos.x += (s16)step;
    CLACT_AddActorSurfacePos(slot->frameActor, &pos, 0);
    CLACT_GetActorSurfacePos(slot->hpBarActor, &pos, 0);
    pos.x += (s16)step;
    CLACT_AddActorSurfacePos(slot->hpBarActor, &pos, 0);
    CLACT_GetActorSurfacePos(slot->statusActor, &pos, 0);
    pos.x += (s16)step;
    CLACT_AddActorSurfacePos(slot->statusActor, &pos, 0);
    if (slot->side == 0) {
        CLACT_GetActorSurfacePos(slot->hpNumberActor, &pos, 0);
        pos.x += (s16)step;
        CLACT_AddActorSurfacePos(slot->hpNumberActor, &pos, 0);
    }
    if (slot->expBarActor != 0) {
        CLACT_GetActorSurfacePos(slot->expBarActor, &pos, 0);
        pos.x += (s16)step;
        CLACT_AddActorSurfacePos(slot->expBarActor, &pos, 0);
    }
    slot->flags.slideCount--;
    if (slot->flags.slideCount == 0) {
        func_02030EAC(task);
        slot->slideTask = 0;
    }
}

/*
 * Task: flashes the palettes of the active slots of the owner three times.
 * lever: owner->slots[i] preserves the base/index register ordering;
 *   raw-offset casts and a named raw owner leave four bytes out.
 */
void BTLV_GAUGE_TaskFlashPalettes(void *task, BtlvGaugeFlashTask *flash)
{
    BtlvGaugeMaskTable masks = sGaugeFlashMasks;
    int i;
    void *palAnm;
    switch (flash->state) {
    case 0:
        flash->mask = 0;
        for (i = 0; i < 8; i++) {
            if (flash->owner->slots[i].active && flash->owner->slots[i].hp > 0)
                flash->mask |= masks.bits[i];
        }
        if (flash->mask) {
            palAnm = (void *)func_021F86E0();
            PALANM_RequestFade(palAnm, 4, flash->mask, 0, 0, 8, 16, func_021F86D4());
            flash->state = 1;
        }
        break;
    case 1:
        if (!PALANM_GetFadeRequestBits((const char *)func_021F86E0())) {
            palAnm = (void *)func_021F86E0();
            PALANM_RequestFade(palAnm, 4, flash->mask, 0, 8, 0, 16, func_021F86D4());
            flash->state = 2;
        }
        break;
    case 2:
        if (!PALANM_GetFadeRequestBits((const char *)func_021F86E0())) {
            flash->count++;
            if (flash->count == 3) {
                flash->count = 0;
                flash->state = 3;
            } else {
                flash->state = 0;
            }
        }
        break;
    case 3:
        for (i = 0; i < 8; i++) {
            if (flash->owner->slots[i].active)
                break;
        }
        if (i == 8)
            flash->state = 0;
        break;
    }
}

/* Sets the BGM player parameter unless the player is locked. */
void BTLV_GAUGE_SetBgmPlayerParam(int bgmParam)
{
    if (func_0200F300() != 1)
        GFL_USE_SetBgmPlayerParam(bgmParam);
}

/* Returns value * scale / maxValue, at least 1 when value is not 0. */
int BTLV_GAUGE_CalcBarPixels(int value, int maxValue, int scale)
{
    int result = func_0209C2B0(value * scale, maxValue);
    if (result == 0 && value != 0)
        result = 1;
    return result;
}

/*
 * Shows or hides the number and bar actors of a slot. On layouts 2 and 3 only one
 * of the two shows, chosen by the alternate display flag.
 * Lever: the flag word at 0x440 is a bitfield struct (bit 4 read as
 * lsls #27 / lsrs #31); a plain u32 with `(f >> 4) & 1` gives lsrs/ands
 * and a different register assignment.
 */
void BTLV_GAUGE_SetSlotBarsVisible(BtlvGaugeWork *work, int slotIdx, int visible)
{
    if ((work->slots[slotIdx].layout == 2 || work->slots[slotIdx].layout == 3) && visible == 1 && (slotIdx & 1) == 0) {
        CLACT_SetActorDrawEnable(work->slots[slotIdx].hpNumberActor, work->flags.altDisplay);
        CLACT_SetActorDrawEnable(work->slots[slotIdx].hpBarActor, work->flags.altDisplay ? 0 : 1);
    } else {
        CLACT_SetActorDrawEnable(work->slots[slotIdx].hpNumberActor, visible);
        CLACT_SetActorDrawEnable(work->slots[slotIdx].hpBarActor, visible);
    }
}
