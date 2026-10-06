/*
 * file:     bmp_oam_p01.c
 * unit:     yes
 * function: func_02025318, func_02025358, func_02025360, func_020253D4, func_02025404, func_02025440, func_02025470, func_020254BC, func_02025508, func_02025518, func_02025538, func_02025588, func_020255A0, func_0202570C, func_02025774, func_020257C4, func_020257D0
 * address:  0x02025318
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   g_020A7484     0x020A7484  data
 *   func_020307B0  0x020307B0  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_020216D4   0x020216D4  thumb
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_020490F4   0x020490F4  arm
 *   g_020A7494      0x020A7494  data
 *   func_02049238  0x02049238  arm
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_0204A7A0  0x0204A7A0  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204BA20  0x0204BA20  arm
 *   func_02025A9C  0x02025A9C  thumb
 *   gModeTable     0x0209F87C  data
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_020437D4  0x020437D4  arm
 *   func_020437EC  0x020437EC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0204ABBC  0x0204ABBC  arm
 *   GX_LoadOBJ     0x0207E780  arm
 *   GXS_LoadOBJ    0x0207E804  arm
 */
#include "../../matched/include/Obj08785.h"
#include "../../matched/include/Obj07093.h"
#include "../../matched/include/Obj00934.h"
#include "../../matched/include/Obj06909.h"
#include "../../matched/include/Obj08786.h"

struct ActorTool;
struct PalAnmSlot;
struct Obj02025774;
struct Actor;
struct Bmp;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct ActorTool {
    u32 f00;
    u8  count[2];
    u8  slot[2][16];
};

typedef signed int     s32;

typedef signed short   s16;

struct Point {
    s16 x;
    s16 y;
    u16 f4;
    u8  f6;
    u8  f7;
};

struct Grid_020255A0 {
    void *bmp;
    void *act[25];
    void *res[24];
    u16   f_c8;
    u8    cols;
    u8    rows;
};

struct Sys {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 slot[3];
};

struct Param {
    void *bmp;
    s16   x;
    s16   y;
    u32   f8;
    u32   fc;
    u8    f10;
    u8    f11;
    u16   f12;
    u32   f14;
};

struct ModeEntry {
    u32 size;
    u32 a;
    u32 b;
};

struct Grid_0202570C {
    u32   pad_0;
    void *a[25];
    void *b[24];
    u8    pad_C8[2];
    u8    cols;
    u8    rows;
};

typedef signed char    s8;

struct Obj {
    void *bmp;
    u8    pad04[0x64 - 4];
    u32   engine;
    u32   cell[24];
    u8    padC8[2];
    u8    cols;
    u8    rows;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int func_02025360(struct ActorTool *p, int len, u32 bank);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_020253D4(struct ActorTool *p, u32 i, u32 bank);
extern void func_0204ADA4(u32 a0);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *p);
extern void func_02025B18(struct Obj02025774 *p);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern s32 func_0204A7A0(u32 size, u32 a2, u16 heapId);
extern u32 func_02025A9C(struct Obj *obj, u32 engine, u32 arg);
extern struct Obj *func_0204B294(void *a, u32 res, u32 c, u32 d, const void *pt,
                           u16 f, u16 g);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204A8D4(u32 i);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u32 func_0204B3F4(struct Obj *p);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void  func_020862F0(void *p, u32 n);
extern int func_0204ABBC(u32 idx, u32 flag);
extern void  GX_LoadOBJ(void *src, u32 off, u32 n);
extern void  GXS_LoadOBJ(void *src, u32 off, u32 n);
u8 *func_02025318(u32 a0, u8 a1, u8 a2);
void func_02025358(void *p);
s32 func_02025404(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
int func_02025440(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
u32 func_02025470(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
u32 func_020254BC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
unsigned int func_02025508(int a0, int a1, int a2);
void func_02025518(u32 a0, u32 a1, u32 a2);
void *func_02025538(u32 a0, void *a1);
void func_02025588(void *p);
void func_02025774(u8 *g, u32 a);
int func_020257C4(const int *p);
extern char  g_020A7484[];
extern u32   g_020A7494[];
extern const struct ModeEntry gModeTable[];


u8 *func_02025318(u32 a0, u8 a1, u8 a2)
{
    u8 *p = func_02030734(a0, 0x28, 1, g_020A7484, 0x51);
    int i, j;

    p[4] = a1;
    p[5] = a2;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 0x10; j++) {
            p[i * 0x10 + j + 6] = 0xff;
        }
    }
    return p;
}


/*
 * Unlabelled Thumb tail-call thunk: func_020307B0(p).
 */
void func_02025358(void *p)
{
    func_020307B0(p);
}

/*
 * actor_tool.c: allocate a run of len free (0xFF) slots in one bank and
 * stamp every slot of the run with its start index; returns the start, or 0.
 * func_020253D4 frees what this stamps.
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 116/116, 21 out after wave
 * 17, docs/notes/pkt_02025360.c.txt): the scan loop's bound is written
 * `j < i + len` in the loop condition, and `end = i + len` is computed only
 * after the scan for the fill. With `end` assigned before the scan and used
 * as its bound, end / scan base / count pointer rotate through r2/r3/r4
 * instead of the image's r4/r2/r3. Found by tools/permuter.py anneal
 * (seed 2101, mutation expand(end)).
 */
int func_02025360(struct ActorTool *p, int len, u32 bank)
{
    int i, j, end;
    u32 sel = 1;
    u8 *dst;

    if (bank == 0)
        sel = 0;
    i = 0;
    if (i < p->count[sel]) {
        do {
            if (p->slot[sel][i] == 0xff) {
                for (j = i; j < i + len; j++) {
                    if (p->slot[sel][j] != 0xff) {
                        i = j;
                        break;
                    }
                }
                end = i + len;
                if (j == end) {
                    for (j = i; j < end; j++) {
                        dst = (u8 *)p + (sel << 4);
                        dst[j + 6] = (u8)i;
                    }
                    return i;
                }
            }
            i++;
        } while (i < p->count[sel]);
    }
    return 0;
}


/*
 * actor_tool.c: free the run that func_02025360 stamped with index i in
 * one bank: every slot from i on that still holds i goes back to 0xFF.
 * The bank select is the same `sel = 1; if (bank == 0) sel = 0;` as the
 * allocator.  Two declaration facts close it (docs/notes/pkt_020251FC.c.txt
 * had it at 5 bytes): the slots are a 2 x 16 array in the object (the
 * `adds p, i; ldrb [.., #6]` addressing), and the cursor is an INT while
 * the index it starts from is the u32 parameter, which is what makes the
 * image keep the two copies of the cursor (r2 and r3) apart; found by
 * tools/permuter.py --types (type:l(j:u32->int)).
 */
void func_020253D4(struct ActorTool *p, u32 i, u32 bank)
{
    u32 sel = 1;
    int j;

    if (bank == 0)
        sel = 0;
    for (j = i; p->slot[sel][j] == i; j++)
        p->slot[sel][j] = 0xff;
}


s32 func_02025404(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u32 v = func_02025360((struct ActorTool *)a0, a4, a3);

    return func_0204AC18((void *)a1, a2, a3, (v & 0x7ff) << 5, 0, (u16)a4, (u16)a5);
}


int func_02025440(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u32 v = func_02025360((struct ActorTool *)a0, a4, a3);

    return func_0204ACEC((void *)a1, a2, a3, (v & 0x7ff) << 5, (u16)a5);
}


/*
 * Create one map tile: a4's flag word picks the 3-versus-2 mode, the tile is
 * built by func_02025404 over (a1, a2, a3, a4, a5, a6), its width comes back
 * from func_02025508 packed into the low half of a5's shifted word and the
 * tile is handed to func_020216D4 with a5 shifted up five.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02025470.c \
 *       --func func_02025470 --addr 0x02025470 --cc 1.1p1 --thumb
 */
u32 func_02025470(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    u32 mode = 2;
    u32 p;
    u32 v;

    if (a4 != 0) {
        mode = 3;
    }
    p = func_02025404(a1, a2, a3, a4, a5, a6);
    v = func_02025508(a1, p, a4);
    func_020216D4((struct PalAnmSlot *)a0, mode, (u16)(v << 4), a5 << 5);
    return p;
}


/*
 * The wide-tile twin of func_02025470: identical body, but the tile builder
 * is func_02025440 rather than func_02025404.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020254BC.c \
 *       --func func_020254BC --addr 0x020254BC --cc 1.1p1 --thumb
 */
u32 func_020254BC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    u32 mode = 2;
    u32 p;
    u32 v;

    if (a4 != 0) {
        mode = 3;
    }
    p = func_02025440(a1, a2, a3, a4, a5, a6);
    v = func_02025508(a1, p, a4);
    func_020216D4((struct PalAnmSlot *)a0, mode, (u16)(v << 4), a5 << 5);
    return p;
}

unsigned int func_02025508(int a0, int a1, int a2){ int t0 = func_0204AEF4((int)(a1 + 0), (int)(a2 + 0)); return ((unsigned int)(t0) >> 5); }


/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *           Verdict MATCH*: the listing's extent for the original is 32 bytes against 30 compiled.
 */
void func_02025518(u32 a0, u32 a1, u32 a2)
{
    u32 v = func_02025508(a0, a1, a2);

    func_020253D4((struct ActorTool *)a0, v, a2);
    func_0204ADA4(a1);
}


/*
 * Allocate the 0x18-byte header for one 2-D tile set (tag 0x73), record the
 * row count and the pixel base, seed the three column cursors with -1 and
 * allocate the descriptor buffer through func_020490F4 with the palette field
 * forced to a 0x8000-based value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02025538.c \
 *       --func func_02025538 --addr 0x02025538 --cc 1.1p1 --thumb
 */
void *func_02025538(u32 a0, void *a1)
{
    u8 *p;
    int i;

    p = func_02030734(a0, 0x18, 1, (const char *)g_020A7494, 0x73);
    ((struct Obj08785 *)p)->f4 = a0;
    ((struct Obj08785 *)p)->f0 = a1;
    for (i = 0; i < 3; i++) {
        *(u32 *)(p + 0xc + i * 4) = -1;
    }
    ((struct Obj08785 *)p)->f8 = func_020490F4(0x33, (u16)((a0 & 0x7fff) | 0x8000));
    return p;
}


void func_02025588(void *p)
{
    func_02049238(((struct Obj07093 *)p)->f8);
    func_02025B18(p);
    func_020307B0(p);
}


/*
 * bmp_oam.c: build a grid of OAM actors over a bitmap, one 32x16 cell per
 * actor, each with its own character resource allocated by mode.
 *
 * Closed in wave 15 from 8 bytes (two one-instruction scheduling swaps:
 * `adds r3, r5, r3` / `ldr r2, [r4, #8]` and `str r0, [r6, #4]` /
 * `movs r2, #0`).  The lever was the declaration: param is a
 * `const struct Param *`.  With const, the stores into pt and the grid no
 * longer order the param field loads, and both swaps fall into the image's
 * order at once.  Every body spelling tried in waves 13 and 14 held at 8.
 */
struct Grid_020255A0 *func_020255A0(struct Sys *sys, const struct Param *param)
{
    struct Point pt;
    u32 mode;
    struct Grid_020255A0 *g;
    u8 rows;
    u8 i;
    u8 j;
    u32 engine;
    u8 cols;
    u8 *row;
    u8 *cell;
    u32 yoff;
    u32 f8;

    {
        u16 *q = (u16 *)&pt;
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
    }

    g = func_02030734(sys->f4, 0xcc, 1, (const char *)g_020A7494, 0xa3);
    g->bmp = param->bmp;
    cols = (u8)(func_020437DC(g->bmp) >> 5);
    rows = (u8)(func_020437E4(param->bmp) >> 4);
    if ((s32)func_020437DC(param->bmp) % 32 != 0) {
        cols = (u8)(cols + 1);
    }
    if ((s32)func_020437E4(param->bmp) % 16 != 0) {
        rows = (u8)(rows + 1);
    }
    g->cols = cols;
    g->rows = rows;
    g->f_c8 = param->f12;
    ((struct Obj00934 *)g)->f64 = param->f14;

    engine = sys->f8;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            row = (u8 *)g + i * cols * 4;
            yoff = i << 4;
            mode = func_02025A9C((struct Obj *)sys, param->f14, engine);
            cell = row + j * 4;
            ((struct Obj06909 *)cell)->f68 =
                (void *)func_0204A7A0(gModeTable[mode].size, param->f14, sys->f4);
            pt.x = (s16)(param->x + (j << 5));
            pt.y = (s16)(param->y + yoff);
            f8 = param->f8;
            pt.f6 = param->f10;
            pt.f7 = param->f11;
            {
                void *act = func_0204B294((void *)sys->f0, (u32)((struct Obj06909 *)cell)->f68,
                                          f8, sys->slot[mode], &pt,
                                          param->f12, sys->f4);
                u32 fc = (u8)param->fc;
                ((struct Obj06909 *)cell)->f4 = act;
                func_0204B6F4(act, fc, 0);
            }
            func_0204BA20(((struct Obj06909 *)cell)->f4, 0);
        }
    }
    return g;
}


/*
 * bmp_oam.c.  Tears down the window grid: for every cell of the
 * rows x cols grid, releases the cell's two resources, then frees the
 * object itself.
 */
void func_0202570C(struct Grid_0202570C *g)
{
    u8 i, j;

    for (i = 0; i < g->rows; i++) {
        for (j = 0; j < g->cols; j++) {
            func_0204A8D4((u32)g->b[j + i * g->cols]);
            func_0204B3B4(g->a[j + i * g->cols]);
        }
    }
    func_020307B0(g);
}


void func_02025774(u8 *g, u32 a)
{
    u8 i;
    u8 j;

    for (i = 0; i < ((struct Obj08786 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08786 *)g)->fCA; j++) {
            func_0204B3DC(*(void **)(g + 4 + (i * ((struct Obj08786 *)g)->fCA + j) * 4), a);
        }
    }
}


/*
 * Unlabelled Thumb leaf in the ARM9 module: a bare tail call forwarding the
 * word at +4.
 *
 * Addresses are Black-image addresses.
 */
int func_020257C4(const int *p)
{
    return func_0204B3F4((struct Obj *)p[1]);
}


/*
 * Upload a tiled bitmap to OBJ VRAM one cell row at a time.  The engine
 * selector at +0x64 picks GX_LoadOBJ or GXS_LoadOBJ once, up front, and the
 * chosen function pointer is spilled to [sp] and reached through blx r3 for
 * every one of the (rows x cols) transfers.
 *
 * The 0x80-or-remainder width is the tell: a full cell row is 0x80 bytes,
 * and only the last column of the last row uploads the partial remainder
 * ((w % 32) / 8) * 32, which falls back to a whole 0x80 when it lands on
 * zero.  The signed shift quartet around the remainder is what says the
 * width helper hands back a signed int, not the u16 its other callers use.
 */
void func_020257D0(struct Obj *o)
{
    void (*load)(void *, u32, u32);
    u8 *base;
    s32 cols;
    s32 rows;
    s32 x;
    u32 vram;
    s32 y;
    u32 off;
    u32 last;
    u32 odd;
    u32 n;
    u32 rowsz;
    void *src;

    base = (u8 *)func_020437D4(o->bmp);
    func_020862F0(base, func_020437EC(o->bmp));
    if (o->engine == 0) {
        load = GX_LoadOBJ;
    } else {
        load = GXS_LoadOBJ;
    }
    cols = (s32)((u32)func_020437DC(o->bmp) >> 3);
    rows = (s32)((u32)func_020437E4(o->bmp) >> 3);
    last = (u32)((((s32)(u32)func_020437DC(o->bmp) % 32) / 8) * 32);
    if (last == 0) {
        last = 0x80;
    }
    off = 0;
    y = 0;
    rowsz = cols << 5;
    y = 0;
    {
        s32 nr = o->rows;
        if (nr <= 0) {
            return;
        }
    }
    odd = rows & 1;
    do {
        for (x = 0; x < o->cols; x++) {
            if (x == o->cols - 1) {
                n = last;
            } else {
                n = 0x80;
            }
            src = (void *)func_0204ABBC(o->cell[x + y * o->cols], o->engine);
            vram = (u32)src;
            load(base + off, vram, n);
            if (y == o->rows - 1 && odd != 0) {
            } else {
                vram += 0x80;
                load(base + rowsz, vram, n);
            }
            off += n;
            rowsz += n;
        }
        off += cols << 5;
        rowsz += cols << 5;
        y++;
    } while (y < o->rows);
}
