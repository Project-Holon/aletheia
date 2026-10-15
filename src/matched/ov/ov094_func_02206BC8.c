/*
 * function: BTLV_GAUGE_Create
 * address: 0x02206BC8
 * packet: pkt_ov094_02206BC8
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetSealPaletteFileId 0x020276B8 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   APP_ICON_GetSealAnimFileId 0x020276BC thumb
 *   APP_ICON_GetSealFrameFileId 0x020276C0 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetSealCellFileId 0x020276B4 thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   GFL_USE_GetBgmNo 0x02005C44 thumb
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   BTLV_EFFECT_GetMode 0x021F8710 thumb ov094
 *   BTLV_GAUGE_LoadSlotResources 0x02207430 thumb ov094
 *   BTLV_GAUGE_PlaceSlot 0x022079C0 thumb ov094
 *   BTLV_GAUGE_TaskFlashPalettes 0x02208BFC thumb ov094
 *   gBtlvGaugeSourceFileName 0x0220AEC0 data a1
 *   gBtlvGaugeSlideInOffset 0x0220AABC data a2
 */
#include "../include/Obj21804.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct { s16 x, y; } Pt;

typedef struct {
    char pad00[0x40];
    int kind;
    char pad44[0x3c];
} Slot;

typedef struct {
    void *f00;
    void *h04;
    int f08;
    void *f0c;
    void *f10;
    int f14;
    int f18[6];
    int f30, f34, f38, f3c;
    Slot slot[8];
    int f440;
    int f444;
    u16 heap;
} Obj;

typedef struct {
    Obj *obj;
    int pad[3];
} Task;

extern const char gBtlvGaugeSourceFileName[];
extern const Pt gBtlvGaugeSlideInOffset;

typedef signed int     s32;
typedef unsigned char  u8;
struct Bank;
struct PalAnmSlot;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int BTLV_EFFECT_GetPalanm(void);
extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetSealPaletteFileId(void);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 APP_ICON_GetSealAnimFileId(u32 i);
extern u32 APP_ICON_GetSealFrameFileId(u32 i);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 APP_ICON_GetSealCellFileId(void);
extern void PALANM_BlendChannelMask(unsigned, unsigned, u16, unsigned, unsigned);
extern void ARC_TOOL_DeleteHandle(void *);
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u16 GFL_USE_GetBgmNo(void);
extern void *BTLV_EFFECT_GetOwner(void);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern int BTLV_EFFECT_GetMode(void);
extern void BTLV_GAUGE_LoadSlotResources(Obj *, int, int);
extern void BTLV_GAUGE_PlaceSlot(Obj *, int, Pt *);
extern void BTLV_GAUGE_TaskFlashPalettes(void *, void *);

Obj *BTLV_GAUGE_Create(int a, u16 heap)
{
    char *hdr;
    Pt pos;
    Pt base;
    Obj *s;
    int i;
    void *arc;
    Task *t;
    int lo, hi, kind;

    s = func_02030734(heap, sizeof(Obj), 1, gBtlvGaugeSourceFileName, 0x14b);
    s->heap = heap;
    s->h04 = func_020490F4(0xb, (u16)s->heap);
    s->f00 = CLACT_CreateUnit(0x28, 0, s->heap);
    for (i = 0; i < 6; i++) {
        s->f18[i] = CLACT_RegisterPalette(s->h04, 0xa2, 0, (u16)(i * 0x20), s->heap);
        PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), 2, (u16)(CLACT_GetPaletteVramAddress(s->f18[i], 0) >> 1), 0x20);
    }
    arc = func_020490F4(APP_ICON_GetArchiveId(), (u16)((s->heap & 0x7fff) | 0x8000));
    s->f30 = CLACT_RegisterCharacter(arc, APP_ICON_GetSealPaletteFileId(), 0, 0, s->heap);
    s->f34 = CLACT_RegisterCellAnim(arc, APP_ICON_GetSealAnimFileId(1), APP_ICON_GetSealFrameFileId(1), s->heap);
    s->f38 = CLACT_RegisterPalette(arc, APP_ICON_GetSealCellFileId(), 0, 0x100, s->heap);
    s->f3c = CLACT_RegisterPalette(arc, APP_ICON_GetSealCellFileId(), 0, 0x120, s->heap);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), 2, (u16)(CLACT_GetPaletteVramAddress(s->f38, 0) >> 1), 0x20);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), 2, (u16)(CLACT_GetPaletteVramAddress(s->f3c, 0) >> 1), 0x20);
    PALANM_BlendChannelMask((unsigned)BTLV_EFFECT_GetPalanm(), 2, 0x200, 8, 0);
    ARC_TOOL_DeleteHandle(arc);
    s->f10 = ARC_UTIL_LoadScreenDataFromHandle((void *)s->h04, 0xa4, 0, (u32)(&hdr), s->heap);
    s->f14 = ((struct Obj21804 *)hdr)->f14;
    s->f08 = a;
    s->f444 = GFL_USE_GetBgmNo();
    t = func_02030734(heap, sizeof(Task), 1, gBtlvGaugeSourceFileName, 0x185);
    t->obj = s;
    s->f0c = func_02030DA8(BTLV_EFFECT_GetOwner(), BTLV_GAUGE_TaskFlashPalettes, t, 0);
    switch (BTLV_EFFECT_GetMode()) {
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
        base = gBtlvGaugeSlideInOffset;
        pos = base;
        if (i & 1)
            pos.x *= -1;
        BTLV_GAUGE_LoadSlotResources(s, kind, i);
        s->slot[i].kind = kind;
        BTLV_GAUGE_PlaceSlot(s, i, &pos);
    }
    return s;
}
