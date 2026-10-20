/*
 * file:     app_icon.c
 * unit:     yes
 * function: APP_ICON_GetArchiveId, APP_ICON_GetTouchBarFileId, APP_ICON_GetTypePaletteOffset, APP_ICON_GetTypeCellFileId, APP_ICON_GetTypePaletteFileId, APP_ICON_GetTypeAnimFileId, APP_ICON_GetMoveKindPaletteOffset, APP_ICON_GetMoveKindCellFileId, APP_ICON_GetMoveKindPaletteFileId, APP_ICON_GetMoveKindAnimFileId, APP_ICON_GetStatusCellFileId, APP_ICON_GetStatusPaletteFileId, APP_ICON_GetStatusAnimFileId, APP_ICON_GetStatusFrameFileId, APP_ICON_GetStatusDataFileId, APP_ICON_GetStatusExtraFileId, APP_ICON_LoadTouchBar, APP_ICON_GetItemCellFileId, APP_ICON_GetItemPaletteFileId, APP_ICON_GetItemAnimFileId, APP_ICON_GetItemFrameFileId, APP_ICON_GetItemDataFileId, APP_ICON_GetItemExtraFileId, APP_ICON_GetItemAnim2FileId, APP_ICON_GetItemFrame2FileId, APP_ICON_GetSealCellFileId, APP_ICON_GetSealPaletteFileId, APP_ICON_GetSealAnimFileId, APP_ICON_GetSealFrameFileId, APP_ICON_GetStatusIconAnim, APP_ICON_GetBallCellFileId, APP_ICON_GetBallPaletteFileId, APP_ICON_GetBallAnimFileId, APP_ICON_GetBallFrameFileId, APP_ICON_GetBallThrowCellFileId, APP_ICON_GetBallThrowAnimFileId, APP_ICON_GetBallOpenCellFileId, APP_ICON_GetBallOpenPaletteFileId, APP_ICON_GetBallOpenAnimFileId, APP_ICON_GetEffectCellFileId, APP_ICON_GetEffectPaletteFileId, APP_ICON_GetEffectAnimFileId, APP_ICON_GetNoneFileId, APP_ICON_GetGearCellFileId, APP_ICON_GetGearPaletteFileId, APP_ICON_GetGearAnimFileId, APP_ICON_GetGearDataFileId, APP_ICON_GetGearExtraFileId, APP_ICON_GetGearFrameFileId, APP_ICON_GetGearAnim2FileId
 * address:  0x020275E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from app_taskmenu.c by tools/splitfile.py.
 *
 * symbols:
 *   _PokeTypePltOffset  0x0209FCF8  data
 *   _WazaKindPltOffset  0x0209FCEC  data
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   ARC_UTIL_LoadPaletteDataFromHandle  0x02049EF4  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */
#include "beacon_status_shared_types.h"

struct ArcHandle;       /* opened archive */

struct PokemonParam;    /* Pokemon data */

/* ------------------------------------------------------------------ */
/* app common resources                                                */
/* ------------------------------------------------------------------ */

/*
 * A BG screen of 32x24 cells: the touch bar is the last three rows. The
 * screen file data starts 0xC bytes into the loaded file, after the
 * screen header, and has the same layout.
 */
typedef struct BarScreen {
    u16 upperCells[0x2A0];      /* rows 0..20 */
    u16 barCells[0x60];         /* +0x540 rows 21..23 */
} BarScreen;

#include "gfl_heap_wrap.h"

#include "bg_sys.h"

extern void *ARC_UTIL_LoadPaletteDataFromHandle(struct ArcHandle *arc, u32 datId, u32 compressed, void **file, u32 heapId);

#include "mi_memory.h"

#include "poke_tool.h"

u32 APP_ICON_GetArchiveId(void);

u32 APP_ICON_GetTouchBarFileId(void);

u8 APP_ICON_GetTypePaletteOffset(int type);

u32 APP_ICON_GetTypeCellFileId(u32 type);

u32 APP_ICON_GetTypePaletteFileId(u32 mapping);

u32 APP_ICON_GetTypeAnimFileId(u32 mapping);

u8 APP_ICON_GetMoveKindPaletteOffset(u8 kind);

u32 APP_ICON_GetMoveKindCellFileId(u32 kind);

u32 APP_ICON_GetMoveKindPaletteFileId(void);

u32 APP_ICON_GetMoveKindAnimFileId(void);

u32 APP_ICON_GetStatusCellFileId(u32 mapping);

u32 APP_ICON_GetStatusPaletteFileId(u32 mapping);

u32 APP_ICON_GetStatusAnimFileId(void);

u32 APP_ICON_GetStatusFrameFileId(void);

u32 APP_ICON_GetStatusDataFileId(void);

u32 APP_ICON_GetStatusExtraFileId(void);

void APP_ICON_LoadTouchBar(struct ArcHandle *arc, int bgFrame, u32 heapId, int charOffset, u32 palNo);

u32 APP_ICON_GetItemCellFileId(void);

u32 APP_ICON_GetItemPaletteFileId(void);

u32 APP_ICON_GetItemAnimFileId(u32 mapping);

u32 APP_ICON_GetItemFrameFileId(u32 mapping);

u32 APP_ICON_GetItemDataFileId(void);

u32 APP_ICON_GetItemExtraFileId(void);

u32 APP_ICON_GetItemAnim2FileId(u32 mapping);

u32 APP_ICON_GetItemFrame2FileId(u32 mapping);

u32 APP_ICON_GetSealCellFileId(void);

u32 APP_ICON_GetSealPaletteFileId(void);

u32 APP_ICON_GetSealAnimFileId(u32 mapping);

u32 APP_ICON_GetSealFrameFileId(u32 mapping);

int APP_ICON_GetStatusIconAnim(const struct PokemonParam *pp);

int APP_ICON_GetBallCellFileId(int mapping);

int APP_ICON_GetBallPaletteFileId(int mapping);

int APP_ICON_GetBallAnimFileId(int mapping);

int APP_ICON_GetBallFrameFileId(int mapping);

int APP_ICON_GetBallThrowCellFileId(int ballId);

int APP_ICON_GetBallThrowAnimFileId(int ballId);

int APP_ICON_GetBallOpenCellFileId(int ballId, int mapping);

int APP_ICON_GetBallOpenPaletteFileId(int ballId, int mapping);

int APP_ICON_GetBallOpenAnimFileId(void);

int APP_ICON_GetEffectCellFileId(int mapping);

int APP_ICON_GetEffectPaletteFileId(int mapping);

int APP_ICON_GetEffectAnimFileId(int mapping);

int APP_ICON_GetNoneFileId(void);

int APP_ICON_GetGearCellFileId(int mapping);

int APP_ICON_GetGearPaletteFileId(int mapping);

int APP_ICON_GetGearAnimFileId(int mapping);

int APP_ICON_GetGearDataFileId(void);

int APP_ICON_GetGearExtraFileId(int mapping);

int APP_ICON_GetGearFrameFileId(int mapping);

int APP_ICON_GetGearAnim2FileId(int mapping);

extern const u8 _PokeTypePltOffset[];

extern const u8 _WazaKindPltOffset[];

/* ================================================================== */
/* app common resources: file indices in archive 0x53                  */
/* ================================================================== */
u32 APP_ICON_GetArchiveId(void)
{
    return 0x53;
}

u32 APP_ICON_GetTouchBarFileId(void)
{
    return 0x21;
}

/* Palette offset of a type icon; called with a u8 type. */
u8 APP_ICON_GetTypePaletteOffset(int type)
{
    return _PokeTypePltOffset[type];
}

u32 APP_ICON_GetTypeCellFileId(u32 type)
{
    return type + 0x22;
}

u32 APP_ICON_GetTypePaletteFileId(u32 mapping)
{
    return mapping + 0x3b;
}

u32 APP_ICON_GetTypeAnimFileId(u32 mapping)
{
    return mapping + 0x3e;
}

/* Palette offset of a move kind icon. */
u8 APP_ICON_GetMoveKindPaletteOffset(u8 kind)
{
    return _WazaKindPltOffset[kind];
}

u32 APP_ICON_GetMoveKindCellFileId(u32 kind)
{
    return kind + 0x38;
}

u32 APP_ICON_GetMoveKindPaletteFileId(void)
{
    return 0x13;
}

u32 APP_ICON_GetMoveKindAnimFileId(void)
{
    return 0x14;
}

u32 APP_ICON_GetStatusCellFileId(u32 mapping)
{
    return mapping + 0x15;
}

u32 APP_ICON_GetStatusPaletteFileId(u32 mapping)
{
    return mapping + 0x18;
}

u32 APP_ICON_GetStatusAnimFileId(void)
{
    return 0x1b;
}

u32 APP_ICON_GetStatusFrameFileId(void)
{
    return 0x1c;
}

u32 APP_ICON_GetStatusDataFileId(void)
{
    return 0x1d;
}

u32 APP_ICON_GetStatusExtraFileId(void)
{
    return 0x1e;
}

/*
 * Copy the touch bar rows (the last three rows, 0x60 cells) of screen file
 * 0x1D into the screen buffer of bgFrame and re-base each cell: character
 * number + charOffset, palette number palNo in the top nibble.
 *
 * The bar cells are one u16[0x60] field at +0x540 of one struct type, and
 * the file's screen data is that same struct 0xC bytes into the file; with
 * both written as `->barCells` the offset 0x540 is one constant kept in r7
 * and the +0xC is added on its own, which is the image. The re-base is
 * `(palNo << 12) + (charOffset + (cell & 0xfff))`.
 */
void APP_ICON_LoadTouchBar(struct ArcHandle *arc, int bgFrame, u32 heapId, int charOffset, u32 palNo)
{
    BarScreen *scrn;
    void *file;
    void *fileBuf;
    int i;

    scrn = (BarScreen *)BG_SYS_GetBuf(bgFrame);
    fileBuf = ARC_UTIL_LoadPaletteDataFromHandle(arc, 0x1d, 0, &file, heapId);
    MI_CpuCopy8(((BarScreen *)((u8 *)file + 0xc))->barCells, scrn->barCells, 0xc0);
    GFL_HEAP_Free(fileBuf);
    for (i = 0; i < 0x60; i++)
        scrn->barCells[i] = (palNo << 12) + (charOffset + (scrn->barCells[i] & 0xfff));
}

u32 APP_ICON_GetItemCellFileId(void)
{
    return 0x42;
}

u32 APP_ICON_GetItemPaletteFileId(void)
{
    return 0x41;
}

u32 APP_ICON_GetItemAnimFileId(u32 mapping)
{
    return mapping + 0x43;
}

u32 APP_ICON_GetItemFrameFileId(u32 mapping)
{
    return mapping + 0x46;
}

u32 APP_ICON_GetItemDataFileId(void)
{
    return 0x49;
}

u32 APP_ICON_GetItemExtraFileId(void)
{
    return 0x4a;
}

u32 APP_ICON_GetItemAnim2FileId(u32 mapping)
{
    return mapping + 0x4b;
}

u32 APP_ICON_GetItemFrame2FileId(u32 mapping)
{
    return mapping + 0x4e;
}

u32 APP_ICON_GetSealCellFileId(void)
{
    return 0xb;
}

u32 APP_ICON_GetSealPaletteFileId(void)
{
    return 0xc;
}

u32 APP_ICON_GetSealAnimFileId(u32 mapping)
{
    return mapping + 0xd;
}

u32 APP_ICON_GetSealFrameFileId(u32 mapping)
{
    return mapping + 0x10;
}

/*
 * Status icon animation of a Pokemon: 6 when its HP (parameter 0xA0) is 0,
 * else the icon of its status condition (parameter 0x9D, 1..5), 8 for none.
 */
int APP_ICON_GetStatusIconAnim(const struct PokemonParam *pp)
{
    u32 sick;

    if (POKE_TOOL_GetPartyValue((struct PokemonParam *)pp, 0xa0, 0) == 0) {
        return 6;
    }
    sick = POKE_TOOL_GetPartyValue((struct PokemonParam *)pp, 0x9d, 0);
    if (sick == 1) {
        return 1;
    } else if (sick == 2) {
        return 3;
    } else if (sick == 3) {
        return 2;
    } else if (sick == 4) {
        return 5;
    } else if (sick == 5) {
        return 4;
    } else {
        return 8;
    }
}

int APP_ICON_GetBallCellFileId(int mapping)
{
    return mapping + 0x51;
}

int APP_ICON_GetBallPaletteFileId(int mapping)
{
    return mapping + 0x54;
}

int APP_ICON_GetBallAnimFileId(int mapping)
{
    return mapping + 0xa6;
}

int APP_ICON_GetBallFrameFileId(int mapping)
{
    return mapping + 0xa9;
}

/* Ball id 0 is shown as ball 4. */
int APP_ICON_GetBallThrowCellFileId(int ballId)
{
    if (ballId == 0) {
        ballId = 4;
    }
    return ballId + 0x56;
}

int APP_ICON_GetBallThrowAnimFileId(int ballId)
{
    if (ballId == 0) {
        ballId = 4;
    }
    return ballId + 0x6f;
}

/* All balls share the cell and animation files; ballId is not read. */
int APP_ICON_GetBallOpenCellFileId(int ballId, int mapping)
{
    return mapping + 0x89;
}

int APP_ICON_GetBallOpenPaletteFileId(int ballId, int mapping)
{
    return mapping + 0x8c;
}

int APP_ICON_GetBallOpenAnimFileId(void)
{
    return 0x8f;
}

int APP_ICON_GetEffectCellFileId(int mapping)
{
    return mapping + 0x90;
}

int APP_ICON_GetEffectPaletteFileId(int mapping)
{
    return mapping + 0x93;
}

int APP_ICON_GetEffectAnimFileId(int mapping)
{
    return mapping + 0x96;
}

int APP_ICON_GetNoneFileId(void)
{
    return 0;
}

int APP_ICON_GetGearCellFileId(int mapping)
{
    return mapping + 2;
}

int APP_ICON_GetGearPaletteFileId(int mapping)
{
    return mapping + 5;
}

int APP_ICON_GetGearAnimFileId(int mapping)
{
    return mapping + 8;
}

int APP_ICON_GetGearDataFileId(void)
{
    return 0x99;
}

int APP_ICON_GetGearExtraFileId(int mapping)
{
    return mapping + 0x9a;
}

int APP_ICON_GetGearFrameFileId(int mapping)
{
    return mapping + 0x9d;
}

int APP_ICON_GetGearAnim2FileId(int mapping)
{
    return mapping + 0xa0;
}
