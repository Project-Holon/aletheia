/*
 * function: BTLV_CLACT_LoadActor
 * address: 0x02201B20
 * packet: pkt_ov094_02201B20
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlvClactDefaultActorInit 0x0220A368 data a4
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_CreateAffineActor 0x0204B324 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj03216.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct Config { s16 x, y; u32 rest[2]; u32 a, b, last; } Config;
extern const Config gBtlvClactDefaultActorInit;
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
struct PalAnmSlot;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern int BTLV_EFFECT_GetPalanm(void);
extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern struct Obj *CLACT_CreateAffineActor(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);
extern void ARC_TOOL_DeleteHandle(void *);
int BTLV_CLACT_LoadActor(char *p, u32 archiveId, int a, u32 b, int c, int d, s16 x, s16 y, u32 e, u32 f)
{
    Config cfg = gBtlvClactDefaultActorInit;
    void *archive = func_020490F4(archiveId, (u16)((((struct Obj03216 *)p)->f80 & 0x7fff) | 0x8000));
    int i, off;
    void *slots;
    u32 pal;
    for (i = 0; i < 7; i++) {
        if (*(u32 *)(p + i * 16 + 8) == 0) break;
    }
    off = i * 16;
    *(int *)(p + 12 + off) = CLACT_RegisterCharacter(archive, a, 0, 0, ((struct Obj03216 *)p)->f80);
    *(int *)(p + 16 + off) = CLACT_RegisterPaletteCompressed(archive, b, 0, (u16)(i * 32 + 0x140), ((struct Obj03216 *)p)->f80);
    *(int *)(p + 20 + off) = CLACT_RegisterCellAnim(archive, c, d, ((struct Obj03216 *)p)->f80);
    slots = (void *)BTLV_EFFECT_GetPalanm();
    pal = CLACT_GetPaletteVramAddress(*(int *)(p + 16 + off), 0);
    PALANM_LoadArcPaletteToSlot(slots, archiveId, b, ((struct Obj03216 *)p)->f80, 2, 32, (pal & 0x3ff) >> 1);
    cfg.x = x;
    cfg.y = y;
    if (e == 0 && f == 0) {
        *(u32 *)(p + 8 + off) = (u32)CLACT_CreateActor((void *)((struct Obj03216 *)p)->f4, *(u32 *)(p + 12 + off), *(u32 *)(p + 16 + off), *(u32 *)(p + 20 + off), &cfg, 0, ((struct Obj03216 *)p)->f80);
    } else {
        cfg.a = e;
        cfg.b = f;
        *(u32 *)(p + 8 + off) = (u32)CLACT_CreateAffineActor(((struct Obj03216 *)p)->f4, *(u32 *)(p + 12 + off), *(u32 *)(p + 16 + off), *(u32 *)(p + 20 + off), (u32)(&cfg), 0, ((struct Obj03216 *)p)->f80);
    }
    CLACT_SetActorAutoAnim((struct Obj *)*(u32 *)(p + 8 + off), 1);
    ARC_TOOL_DeleteHandle(archive);
    return i;
}
