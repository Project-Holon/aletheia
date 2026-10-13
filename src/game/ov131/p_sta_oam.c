/*
 * file:     p_sta_oam.c
 * unit:     yes
 * function: P_STA_OAM_CreateManager, P_STA_OAM_DeleteManager, P_STA_OAM_CreateBitmapActors, P_STA_OAM_DeleteBitmapActors, P_STA_OAM_SetBitmapActorsEnabled, P_STA_OAM_TransferBitmap, P_STA_OAM_SetBitmapActorsPos, P_STA_OAM_SwapInts, P_STA_OAM_GetCellResMode, P_STA_OAM_FreeCellRes, P_STA_RIBBON_GetRibbonInfo
 * address:  0x021DBA90
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from p_sta_oam.c: 0x021DBA90-end. Cuts at the __FILE__ anchor functions (layout/file_anchors.txt);
 * the functions in this range use no sub-screen work struct (OAM and bitmap helpers the sub-screens call).
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02030734 0x02030734 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_020437D4 0x020437D4 arm
 *   P_STA_OAM_FileName 0x021DC854 data a1
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_020437EC 0x020437EC arm
 *   func_020862F0 0x020862F0 arm
 *   func_0204ABBC 0x0204ABBC arm
 *   func_0207E780 0x0207E780 arm
 *   func_0207E804 0x0207E804 arm
 *   P_STA_RIBBON_InfoTable 0x021DC2F8 data a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

#include "p_status_types.h"

#define REG_DISPCNT_MAIN 0x04000000
#define REG_DISPCNT_SUB  0x04001000

extern u32 func_020307B0(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204A6C8(void *arc, u32 fileId, u32 a, u32 screen, u16 heapId);
extern int func_0204AF28(void *arc, u32 fileId, u32 a, u32 heapId);
extern void func_02049238(void *arc);
extern void func_0204A8D4(u32 charRes);
extern void func_0204AFD8(u32 cellRes);
extern struct Actor *func_0204B294(void *unit, unsigned int chrRes, unsigned int plttRes, unsigned int cellRes, const void *pos, u16 space, u16 heapId);
extern void func_0204B3DC(struct Actor *actor, u32 enable);
extern void func_0204B3B4(struct Actor *actor);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0204B6F4(struct Actor *actor, u32 animSeq, u32 flag);
extern void func_0204B404(struct Actor *actor, const struct StaOamPoint *delta, u32 space);
extern void *func_020437D4(const struct Bmp *bmp);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_020862F0(void *dst, int size);
extern int func_0204ABBC(u32 charRes, u32 screen);
extern void func_0207E780(void *dst, void *src, u32 size);
extern void func_0207E804(void *dst, void *src, u32 size);
struct StaOamManager *P_STA_OAM_CreateManager(u32 heapId, u32 clunit);
void P_STA_OAM_DeleteManager(struct StaOamManager *mgr);
struct StaOamBitmapActors *P_STA_OAM_CreateBitmapActors(struct StaOamManager *mgr, const struct StaOamBitmapDesc *desc);
void P_STA_OAM_DeleteBitmapActors(struct StaOamBitmapActors *grid);
void P_STA_OAM_SetBitmapActorsEnabled(struct StaOamBitmapActors *grid, int enable);
void P_STA_OAM_TransferBitmap(struct StaOamBitmapActors *grid);
void P_STA_OAM_SetBitmapActorsPos(struct StaOamBitmapActors *grid, s16 x, s16 y);
void P_STA_OAM_SwapInts(int *a, int *b);
int P_STA_OAM_GetCellResMode(struct StaOamManager *mgr, int screen, u32 arc);
void P_STA_OAM_FreeCellRes(struct StaOamManager *mgr);
u32 P_STA_RIBBON_GetRibbonInfo(u32 index, u32 field);
extern const char P_STA_OAM_FileName[];
extern const struct StaRibbonInfo P_STA_RIBBON_InfoTable[];

struct StaOamManager *P_STA_OAM_CreateManager(u32 heapId, u32 clunit) {
    struct StaOamManager *mgr = func_02030734(heapId, 0x14, 1, P_STA_OAM_FileName, 0x5d);
    int i;
    mgr->heapId = heapId;
    mgr->clunit = (void *)clunit;
    for (i = 0; i < 3; i++) mgr->cellRes[i] = -1;
    return mgr;
}

void P_STA_OAM_DeleteManager(struct StaOamManager *mgr)
{
    P_STA_OAM_FreeCellRes(mgr);
    func_020307B0(mgr);
}

/*
 * note (2026-10-02): desc is const-qualified; that frees the desc loads from ordering behind the stack
 */
struct StaOamBitmapActors *P_STA_OAM_CreateBitmapActors(struct StaOamManager *mgr, const struct StaOamBitmapDesc *desc)
{
    struct StaOamActorPos pos = {0};
    struct StaOamBitmapActors *grid;
    u8 cols, rows, i, j;
    void *arc;
    int mode;
    struct Bmp *bmp;
    grid = func_02030734(mgr->heapId, 0x24, 1, P_STA_OAM_FileName, 0x8a);
    bmp = desc->bmp;
    grid->bmp = bmp;
    cols = ((u32)func_020437DC(bmp) >> 6) & 0xff;
    rows = ((u32)func_020437E4(desc->bmp) >> 5) & 0xff;
    if (func_020437DC(desc->bmp) % 64 != 0) cols = cols + 1;
    if (func_020437E4(desc->bmp) % 32 != 0) rows = rows + 1;
    grid->cols = cols;
    grid->rows = rows;
    grid->space = desc->space;
    grid->screen = desc->screen;
    arc = func_020490F4(0x4e, mgr->heapId);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            mode = P_STA_OAM_GetCellResMode(mgr, desc->screen, (u32)arc);
            grid->charRes[i * cols + j] = func_0204A6C8(arc, 7, 0, desc->screen, mgr->heapId);
            pos.x = desc->x + (j << 6);
            pos.y = desc->y + (i << 5);
            pos.drawPriority = desc->drawPriority;
            pos.bgPriority = desc->bgPriority;
            grid->actor[i * cols + j] = func_0204B294(mgr->clunit, (u32)grid->charRes[i * cols + j], desc->plttRes, mgr->cellRes[mode], &pos, desc->space, mgr->heapId);
            func_0204B6F4(grid->actor[j], (u8)desc->animSeq, 0);
        }
    }
    func_02049238(arc);
    return grid;
}

void P_STA_OAM_DeleteBitmapActors(struct StaOamBitmapActors *grid)
{
    u8 i, j;
    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            func_0204A8D4((u32)grid->charRes[j + i * grid->cols]);
            func_0204B3B4(grid->actor[j + i * grid->cols]);
        }
    }
    func_020307B0(grid);
}

void P_STA_OAM_SetBitmapActorsEnabled(struct StaOamBitmapActors *grid, int enable)
{
    u8 i, j;
    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            func_0204B3DC(grid->actor[j + i * grid->cols], enable);
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
    u8 *src;
    u8 k;
    void (*copy)(void *, void *, u32);
    dst0 = func_020437D4(grid->bmp);
    func_020862F0(dst0, func_020437EC(grid->bmp));
    if (grid->screen == 0) copy = func_0207E780; else copy = func_0207E804;
    wt = (u32)func_020437DC(grid->bmp) >> 3;
    rem = (u32)func_020437E4(grid->bmp) >> 3;
    rem = rem % 4;
    edge = func_020437DC(grid->bmp) % 64 / 8 * 32;
    if (edge == 0) edge = 256;
    off = 0;
    for (r = 0; r < grid->rows; r++) {
        for (c = 0; c < grid->cols; c++) {
            if (c == grid->cols - 1) seg = edge; else seg = 256;
            src = (u8 *)func_0204ABBC((u32)grid->charRes[c + r * grid->cols], grid->screen);
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
            func_0204B404(grid->actor[j + i * grid->cols], &pt, grid->space);
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
int P_STA_OAM_GetCellResMode(struct StaOamManager *mgr, int screen, u32 arc)
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
    mgr->cellRes[mode] = func_0204AF28((void *)arc, 0x4d, 0x80, mgr->heapId);
    return mode;
}

void P_STA_OAM_FreeCellRes(struct StaOamManager *mgr) {
    int i;
    for (i = 0; i < 3; i++) {
        if (mgr->cellRes[i] != -1) {
            func_0204AFD8(mgr->cellRes[i]);
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
