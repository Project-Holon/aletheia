/*
 * file:     p_sta_oam.c
 * unit:     yes
 * function: P_STA_OAM_CreateManager, P_STA_OAM_DeleteManager, P_STA_OAM_CreateBitmapActors, P_STA_OAM_DeleteBitmapActors, P_STA_OAM_SetBitmapActorsEnabled, P_STA_OAM_TransferBitmap, P_STA_OAM_SetBitmapActorsPos, P_STA_OAM_SwapInts, P_STA_OAM_GetCellResMode, P_STA_OAM_FreeCellRes, P_STA_RIBBON_GetRibbonInfo, P_STA_RIBBON_GetRibbonDescMsg
 * address:  0x021DBA90
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Split from p_sta_oam.c: 0x021DBA90-end. Cuts at the __FILE__ anchor functions (layout/file_anchors.txt);
 * the functions in this range use no sub-screen work struct (OAM and bitmap helpers the sub-screens call).
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   P_STA_OAM_FileName 0x021DC854 data a1
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   BMP_GetByteSize 0x020437EC arm
 *   DC_FlushRange 0x020862F0 arm
 *   CLACT_GetCharacterVramAddress 0x0204ABBC arm
 *   GX_LoadOBJ 0x0207E780 arm
 *   GXS_LoadOBJ 0x0207E804 arm
 *   P_STA_RIBBON_InfoTable 0x021DC2F8 data a4
 */
#include "../arm9/gx_load2d.h"
#include "../sdk_ioreg.h"
#include "p_status_types.h"

#define REG_DISPCNT_MAIN REG_DISPCNT_ADDR
#define REG_DISPCNT_SUB  REG_DB_DISPCNT_ADDR
#include "../types.h"

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/arc_tool.h"
#include "../arm9/clact.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/os_cache.h"
struct StaOamManager *P_STA_OAM_CreateManager(u32 heapId, struct Unit *clunit);
void P_STA_OAM_DeleteManager(struct StaOamManager *mgr);
struct StaOamBitmapActors *P_STA_OAM_CreateBitmapActors(struct StaOamManager *mgr, const struct StaOamBitmapDesc *desc);
void P_STA_OAM_DeleteBitmapActors(struct StaOamBitmapActors *grid);
void P_STA_OAM_SetBitmapActorsEnabled(struct StaOamBitmapActors *grid, int enable);
void P_STA_OAM_TransferBitmap(struct StaOamBitmapActors *grid);
void P_STA_OAM_SetBitmapActorsPos(struct StaOamBitmapActors *grid, s16 x, s16 y);
void P_STA_OAM_SwapInts(int *a, int *b);
int P_STA_OAM_GetCellResMode(struct StaOamManager *mgr, int screen, void *arc);
void P_STA_OAM_FreeCellRes(struct StaOamManager *mgr);
u32 P_STA_RIBBON_GetRibbonInfo(u32 index, u32 field);
unsigned int P_STA_RIBBON_GetRibbonDescMsg(int ribbonNo);
extern const char P_STA_OAM_FileName[];
extern const struct StaRibbonInfo P_STA_RIBBON_InfoTable[];

struct StaOamManager *P_STA_OAM_CreateManager(u32 heapId, struct Unit *clunit) {
    struct StaOamManager *mgr = GFL_HEAP_Alloc(heapId, sizeof(StaOamManager), 1, P_STA_OAM_FileName, 0x5d);
    int i;
    mgr->heapId = heapId;
    mgr->clunit = (void *)clunit;
    for (i = 0; i < 3; i++) mgr->cellRes[i] = -1;
    return mgr;
}

void P_STA_OAM_DeleteManager(struct StaOamManager *mgr)
{
    P_STA_OAM_FreeCellRes(mgr);
    GFL_HEAP_Free(mgr);
}

/*
 * note (2026-10-02): desc is const-qualified; that frees the desc loads from ordering behind the stack
 */
struct StaOamBitmapActors *P_STA_OAM_CreateBitmapActors(struct StaOamManager *mgr, const struct StaOamBitmapDesc *desc)
{
    struct ActorInitParam pos = {0};
    struct StaOamBitmapActors *grid;
    u8 cols, rows, i, j;
    void *arc;
    int mode;
    struct Bmp *bmp;
    grid = GFL_HEAP_Alloc(mgr->heapId, sizeof(StaOamBitmapActors), 1, P_STA_OAM_FileName, 0x8a);
    bmp = desc->bmp;
    grid->bmp = bmp;
    cols = ((u32)BMP_GetWidth(bmp) >> 6) & 0xff;
    rows = ((u32)BMP_GetHeight(desc->bmp) >> 5) & 0xff;
    if (BMP_GetWidth(desc->bmp) % 64 != 0) cols = cols + 1;
    if (BMP_GetHeight(desc->bmp) % 32 != 0) rows = rows + 1;
    grid->cols = cols;
    grid->rows = rows;
    grid->space = desc->space;
    grid->screen = desc->screen;
    arc = ARC_TOOL_CreateHandle(0x4e, mgr->heapId);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            mode = P_STA_OAM_GetCellResMode(mgr, desc->screen, arc);
            grid->charRes[i * cols + j] = CLACT_RegisterCharacter(arc, 7, 0, desc->screen, mgr->heapId);
            pos.x = desc->x + (j << 6);
            pos.y = desc->y + (i << 5);
            pos.draw_priority = desc->drawPriority;
            pos.bg_priority = desc->bgPriority;
            grid->actor[i * cols + j] = CLACT_CreateActor(mgr->clunit, (u32)grid->charRes[i * cols + j], desc->plttRes, mgr->cellRes[mode], &pos, desc->space, mgr->heapId);
            CLACT_SetActorPaletteOffset((struct ClactActor *)grid->actor[j], (u8)desc->animSeq, 0);
        }
    }
    ARC_TOOL_DeleteHandle(arc);
    return grid;
}

void P_STA_OAM_DeleteBitmapActors(struct StaOamBitmapActors *grid)
{
    u8 i, j;
    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            CLACT_ReleaseCharacter((u32)grid->charRes[j + i * grid->cols]);
            CLACT_DeleteActor((struct ClactActor *)grid->actor[j + i * grid->cols]);
        }
    }
    GFL_HEAP_Free(grid);
}

void P_STA_OAM_SetBitmapActorsEnabled(struct StaOamBitmapActors *grid, int enable)
{
    u8 i, j;
    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            CLACT_SetActorDrawEnable((struct ClactActor *)grid->actor[j + i * grid->cols], enable);
        }
    }
}

void P_STA_OAM_TransferBitmap(struct StaOamBitmapActors *grid)
{
    u8 *dst0;
    int c, r;
    u32 off, seg, edge;
    int rem;
    u32 wt;
    u32 src;
    u8 k;
    void (*copy)(const void *, u32, u32);
    dst0 = BMP_GetPixels(grid->bmp);
    DC_FlushRange(dst0, BMP_GetByteSize(grid->bmp));
    if (grid->screen == 0) copy = GX_LoadOBJ; else copy = GXS_LoadOBJ;
    wt = (u32)BMP_GetWidth(grid->bmp) >> 3;
    rem = (u32)BMP_GetHeight(grid->bmp) >> 3;
    rem = rem % 4;
    edge = BMP_GetWidth(grid->bmp) % 64 / 8 * 32;
    if (edge == 0) edge = 256;
    off = 0;
    for (r = 0; r < grid->rows; r++) {
        for (c = 0; c < grid->cols; c++) {
            if (c == grid->cols - 1) seg = edge; else seg = 256;
            src = CLACT_GetCharacterVramAddress((u32)grid->charRes[c + r * grid->cols], grid->screen);
            for (k = 0; k < 4; k++) {
                if (r == grid->rows - 1 && rem != 0 && k >= rem) continue;
                copy(dst0 + (off + k * (wt * 32)), src, seg);
                src += 256;
            }
            off += seg;
        }
        off += wt * 32;
    }
}

void P_STA_OAM_SetBitmapActorsPos(struct StaOamBitmapActors *grid, s16 x, s16 y)
{
    struct StaOamPoint pt;
    int i, j;
    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            pt.x = (s16)(x + (j << 6));
            pt.y = (s16)(y + (i << 5));
            CLACT_AddActorSurfacePos((struct ClactActor *)grid->actor[j + i * grid->cols], (const struct ClactVec2 *)&pt, grid->space);
        }
    }
}

void P_STA_OAM_SwapInts(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * volatile: hardware register read at 021DBEB4
 */
int P_STA_OAM_GetCellResMode(struct StaOamManager *mgr, int screen, void *arc)
{
    int mode;
    u32 bits;
    bits = *(volatile u32 *)(screen == 0 ? REG_DISPCNT_MAIN : REG_DISPCNT_SUB) & 0x00300010;
    switch (bits) {
    case 0x00200010: mode = 0; break;
    case 0x00100010: mode = 1; break;
    case 0x10: mode = 2; break;
    default: mode = 0; break;
    }
    if (mgr->cellRes[mode] != -1) return mode;
    mgr->cellRes[mode] = CLACT_RegisterCellAnim(arc, 0x4d, 0x80, mgr->heapId);
    return mode;
}

void P_STA_OAM_FreeCellRes(struct StaOamManager *mgr) {
    int i;
    for (i = 0; i < 3; i++) {
        if (mgr->cellRes[i] != -1) {
            CLACT_ReleaseCellAnim(mgr->cellRes[i]);
            mgr->cellRes[i] = -1;
        }
    }
}

u32 P_STA_RIBBON_GetRibbonInfo(u32 index, u32 field)
{
    switch (field) {
    case 0: return P_STA_RIBBON_InfoTable[index].paramId;
    case 1: return P_STA_RIBBON_InfoTable[index].fileId;
    case 2: return P_STA_RIBBON_InfoTable[index].animSeq;
    case 3: return P_STA_RIBBON_InfoTable[index].nameMsg;
    case 4: return P_STA_RIBBON_InfoTable[index].descMsg;
    case 5: return P_STA_RIBBON_InfoTable[index].selector;
    default: return 0;
    }
}

unsigned int P_STA_RIBBON_GetRibbonDescMsg(int ribbonNo) {
 return P_STA_RIBBON_InfoTable[ribbonNo].descMsg;
}
