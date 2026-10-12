/*
 * file:     bmp_oam.c
 * unit:     yes
 * function: func_02025318, func_02025358, func_02025360, func_020253D4, func_02025404, func_02025440, func_02025470, func_020254BC, func_02025508, func_02025518, func_02025538, func_02025588, func_020255A0, func_0202570C, func_02025774, func_020257C4, func_020257D0, func_020258E8, func_0202590C, func_0202597C, func_020259C4, func_02025A0C, func_02025A54, func_02025A9C, func_02025B18, func_02025B38, func_02025B3C, func_02025B64, func_02025B94, func_02025BA0, func_02025BB8, func_02025BD0, func_02025BE8, func_02025BEC, func_02025C1C, func_02025C30, func_02025C44
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
 *   sub_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B688  0x0204B688  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204AF28  0x0204AF28  arm
 *   sub_0204AFD8  0x0204AFD8  arm
 *   sub_02025B3C_Table  0x0209FA34  data
 *   g_0209FA34  0x0209FA34  data
 *   g_0209FA3D  0x0209FA3D  data
 *   sub_02025BA0_Table  0x0209FA36  data
 *   d_0209FA34 0x0209FA34 data
 *   d_0209FA35 0x0209FA35 data
 *   g_0209FA38  0x0209FA38  data
 *   g_0209FA3C  0x0209FA3C  data
 */
#include "../../matched/include/Obj08785.h"
#include "../../matched/include/Obj07093.h"
#include "../../matched/include/Obj00934.h"
#include "../../matched/include/Obj06909.h"
#include "../../matched/include/Obj08786.h"
#include "../../matched/include/Obj08787.h"
#include "../../matched/include/Obj08788.h"
#include "../../matched/include/Obj08789.h"
#include "../../matched/include/Obj08790.h"

struct ActorTool;
struct PalAnmSlot;
struct Obj02025774;
struct Actor;
struct Bmp;
struct Obj_02025318;
struct Vec2;
struct Node;
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

struct Point_02025318 {
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

struct Grid {
    u32 pad_0;
    void * a[25];
    void * b[24];
    u16 flags;
    u8 cols;
    u8 rows;
};

typedef signed char    s8;

struct Obj_02025318 {
    void *bmp;
    u8    pad04[0x64 - 4];
    u32   engine;
    u32   cell[24];
    u8    padC8[2];
    u8    cols;
    u8    rows;
};

struct PtS {
    s16 x;
    s16 y;
};

struct Obj02025774_020258E8 {
    u8            pad00[4];
    struct Actor *actor;
    u8            pad08[0xc0];
    u16           space;
};


struct Obj_020258E8 {
    u32 field_0;
    u16 field_4;
    u16 field_6;
    u32 field_8;
    u32 slot[3];
};

struct Obj02025774_02025B18 {
    u8  pad[0xc];
    s32 slots[3];
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_0204ADA4(u32 a0);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *p);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern s32 func_0204A7A0(u32 size, u32 a2, u16 heapId);
extern struct Obj_02025318 *func_0204B294(void *a, u32 res, u32 c, u32 d, const void *pt,
                           u16 f, u16 g);
extern void func_0204B6F4(struct Obj_02025318 *o, u32 v, u32 flag);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204A8D4(u32 i);
extern void func_0204B3B4(struct Obj_02025318 *p);
extern void func_0204B3DC(struct Obj_02025318 *p, unsigned int v);
extern u32 func_0204B3F4(struct Obj_02025318 *p);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void  func_020862F0(void *p, u32 n);
extern int func_0204ABBC(u32 idx, u32 flag);
extern void  GX_LoadOBJ(void *src, u32 off, u32 n);
extern void  GXS_LoadOBJ(void *src, u32 off, u32 n);
extern void sub_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj_020258E8 *p, const struct Vec2 *delta, u32 which);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B84C(void *p, u32 a);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void sub_0204AFD8(u32 slot);
extern u8 sub_02025B64(u32 v);
u8 *func_02025318(u32 a0, u8 a1, u8 a2);
void func_02025358(void *p);
int func_02025360(struct ActorTool *p, int len, u32 bank);
void func_020253D4(struct ActorTool *p, u32 i, u32 bank);
s32 func_02025404(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
int func_02025440(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
u32 func_02025470(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
u32 func_020254BC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
unsigned int func_02025508(int a0, int a1, int a2);
void func_02025518(u32 a0, u32 a1, u32 a2);
void *func_02025538(u32 a0, void *a1);
void func_02025588(void *p);
struct Grid_020255A0 *func_020255A0(struct Sys *sys, const struct Param *param);
void func_0202570C(struct Grid *g);
void func_02025774(u8 *g, u32 a);
int func_020257C4(const int *p);
void func_020257D0(struct Obj_02025318 *o);
void func_020258E8(struct Obj02025774_020258E8 *p, s16 *out_x, s16 *out_y);
void func_0202590C(struct Grid *g, s16 x, s16 y);
void func_0202597C(u8 *g, u32 a);
void func_020259C4(u8 *g, u32 a);
void func_02025A0C(u8 *g, u32 a);
void func_02025A54(u8 *g, u32 a);
u32 func_02025A9C(struct Obj_020258E8 *obj, u32 engine, u32 arg);
void func_02025B18(struct Obj02025774_02025B18 *p);
int func_02025B38(void);
u32 func_02025B3C(u32 key);
u8 func_02025B64(u32 v);
u32 func_02025B94(u32 a);
u32 func_02025BA0(u32 idx);
u32 func_02025BB8(u32 i);
u32 func_02025BD0(u32 i);
int func_02025BE8(void);
u32 func_02025BEC(u32 a, u32 b, u32 c);
u32 sub_02025C1C(u32 a, u32 b, u32 c);
u32 sub_02025C30(u32 a, u32 b, u32 c);
int func_02025C44(u32 a0, u32 *a1, u32 *a2);
extern char  g_020A7484[];
extern u32   g_020A7494[];
extern const struct ModeEntry gModeTable[];
extern const u8 sub_02025B3C_Table[];
extern u8 g_0209FA34[];
extern u8 g_0209FA3D[];
extern const u8 sub_02025BA0_Table[];
extern const unsigned char d_0209FA34[];
extern const unsigned char d_0209FA35[];
extern u8  g_0209FA38[];
extern u8  g_0209FA3C[];



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
    func_02025B18((struct Obj02025774_02025B18 *)p);
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
    struct Point_02025318 pt;
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
            mode = func_02025A9C((struct Obj_020258E8 *)((struct Obj_02025318 *)sys), param->f14, engine);
            cell = row + j * 4;
            ((struct Obj06909 *)cell)->f68 =
                (void *)func_0204A7A0(gModeTable[mode].size, param->f14, sys->f4);
            pt.x = (s16)(param->x + (j << 5));
            pt.y = (s16)(param->y + yoff);
            f8 = param->f8;
            pt.f6 = param->f10;
            pt.f7 = param->f11;
            {
                void *act = (struct Obj *)func_0204B294((void *)sys->f0, (u32)((struct Obj06909 *)cell)->f68,
                                          f8, sys->slot[mode], &pt,
                                          param->f12, sys->f4);
                u32 fc = (u8)param->fc;
                ((struct Obj06909 *)cell)->f4 = act;
                func_0204B6F4((struct Obj_02025318 *)act, fc, 0);
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
void func_0202570C(struct Grid *g)
{
    u8 i, j;

    for (i = 0; i < g->rows; i++) {
        for (j = 0; j < g->cols; j++) {
            func_0204A8D4((u32)g->b[j + i * g->cols]);
            func_0204B3B4((struct Obj_02025318 *)(g->a[j + i * g->cols]));
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
            func_0204B3DC((struct Obj_02025318 *)(*(void **)(g + 4 + (i * ((struct Obj08786 *)g)->fCA + j) * 4)), a);
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
    return func_0204B3F4((struct Obj_02025318 *)p[1]);
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
void func_020257D0(struct Obj_02025318 *o)
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



void func_020258E8(struct Obj02025774_020258E8 *p, s16 *out_x, s16 *out_y)
{
    struct PtS pt;

    sub_0204B454(p->actor, &pt, p->space);
    *out_x = pt.x;
    *out_y = pt.y;
}



/*
 * bmp_oam.c.  The x/y parameters are s16, not int: only the narrow
 * parameter type puts the two spills ahead of the object copy in the
 * prologue.
 * Repositions every cell of the rows x cols grid: each cell
 * gets the base position offset by its column (x, step 32) and its row
 * (y, step 16), passed as a packed s16 pair.
 */
void func_0202590C(struct Grid *g, s16 x, s16 y)
{
    struct PtS pt;
    int i, j;

    for (i = 0; i < g->rows; i++) {
        for (j = 0; j < g->cols; j++) {
            pt.x = (s16)(x + (j << 5));
            pt.y = (s16)(y + (i << 4));
            func_0204B404((struct Obj_020258E8 *)(g->a[j + i * g->cols]), (const struct Vec2 *)(&pt), g->flags);
        }
    }
}



void func_0202597C(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08787 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08787 *)g)->fCA; j++) {
            func_0204B688(*(void **)(g + 4 + (i * ((struct Obj08787 *)g)->fCA + j) * 4), a);
        }
    }
}



void func_020259C4(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08788 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08788 *)g)->fCA; j++) {
            func_0204B800(*(void **)(g + 4 + (i * ((struct Obj08788 *)g)->fCA + j) * 4), a);
        }
    }
}



void func_02025A0C(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08789 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08789 *)g)->fCA; j++) {
            func_0204B84C(*(void **)(g + 4 + (i * ((struct Obj08789 *)g)->fCA + j) * 4), a);
        }
    }
}



void func_02025A54(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08790 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08790 *)g)->fCA; j++) {
            func_0204B6F4((struct Obj_02025318 *)(*(void **)(g + 4 + (i * ((struct Obj08790 *)g)->fCA + j) * 4)), a, 0);
        }
    }
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02025A9C.c \
 *       --func func_02025A9C --addr 0x02025A9C --thumb
 *
 * Map the engine's DISPCNT OBJ-mapping bits (mask 0x00300010) to a slot
 * index 0/1/2 and lazily fill that slot through func_0204AF28 with the
 * gModeTable record's two ids (docs/families/bmp_oam.h, section 5).
 *
 * Closed in wave 13.  The two bytes the 2026-09-21 note could not move
 * (`bne default` against `beq merge` at +0x24) are the 0x00200010 arm: it
 * is NOT empty, it sets mode = 0 itself, and it is written FIRST of the
 * four arms.  The body is then cross-jumped onto default's identical
 * `mode = 0`, which is why the image branches to the same address on both
 * sides of the last compare.  With the arm empty the compiler jumps past
 * the zeroing; with `mode = 0` in any other position it lays the arm out
 * separately (55 bytes out).
 */
u32 func_02025A9C(struct Obj_020258E8 *obj, u32 engine, u32 arg)
{
    volatile u32 *reg;
    u32 mode;

    if (engine == 0) {
        reg = (volatile u32 *)0x04000000;
    } else {
        reg = (volatile u32 *)0x04001000;
    }

    switch (*reg & 0x00300010) {
    case 0x00200010:
        mode = 0;
        break;
    case 0x00100010:
        mode = 1;
        break;
    case 0x00000010:
        mode = 2;
        break;
    default:
        mode = 0;
        break;
    }

    if (obj->slot[mode] != (u32)-1) {
        return mode;
    }

    obj->slot[mode] = (u32)func_0204AF28((void *)arg, gModeTable[mode].a,
                                         gModeTable[mode].b, obj->field_4);
    return mode;
}



void func_02025B18(struct Obj02025774_02025B18 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (p->slots[i] != -1) {
            sub_0204AFD8(p->slots[i]);
            p->slots[i] = -1;
        }
    }
}


int func_02025B38(void)
{
    return 19;
}



/*
 * A linear search over a fixed 19-entry, 12-byte-stride table, matching
 * on the first byte of each record; returns the matching index, or 0
 * (not -1) when nothing matches, which is why the caller cannot
 * distinguish "matched slot 0" from "no match".
 *
 * The table pointer is a plain pool word to private data outside this
 * range; left as an untyped byte-stride index rather than a struct
 * pointer since nothing else in this file constrains its layout.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02025B3C.c \
 *       --func func_02025B3C --addr 0x02025B3C --cc 1.1p1 --thumb
 */
u32 func_02025B3C(u32 key)
{
    u32 i;

    for (i = 0; i < 0x13; i++) {
        if (key == sub_02025B3C_Table[i * 0xc]) {
            return i;
        }
    }
    return 0;
}



u8 func_02025B64(u32 v)
{
    u32 i;

    for (i = 0; i < 0x13; i++) {
        if (v == g_0209FA34[i * 0xc]) {
            return g_0209FA3D[i * 0xc];
        }
    }
    return 0;
}



/*
 * A two-stage lookup: map a caller value to a record index with
 * func_02025B3C (src/matched/sub_02025B3C.c), then map that index to a
 * message/asset id with func_02025BA0 (src/matched/sub_02025BA0.c). The
 * first call's result is left in its return register and flows straight
 * into the second call's argument.
 *
 * This is the blocker for src/pending/sub_0201F094.c's wordset.c setter,
 * which is promoted alongside this file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02025B94.c \
 *       --func func_02025B94 --addr 0x02025B94 --cc 1.1p1 --thumb
 */
u32 func_02025B94(u32 a)
{
    return func_02025BA0(func_02025B3C(a));
}



/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by
 * the C.
 *
 * Parked at MATCH by the evidence rather than by the C: every concrete
 * byte is reproduced (confirmed against the exact shape below), but the
 * one relocation, the table pointer, has no witness outside this
 * function's own range. The only other occurrence of the word
 * 0x0209FA36 in the image is at 0x02025BB4, inside the unlabelled filler
 * that immediately follows this function and that this compile's own
 * trailing bytes overlap, so the honesty rule discards it. The table is
 * two bytes into the same record array func_02025B3C searches
 * (src/matched/sub_02025B3C.c, whose own table symbol at 0x0209FA34 does
 * have outside witnesses), but declaring this address as an offset off
 * that symbol changes the code shape mwccarm emits for the pointer
 * arithmetic and no longer reproduces the bytes, so the two are kept as
 * separate declarations. func_02025B94 (src/matched/sub_02025B94.c)
 * calls this function and reaches EXACT anyway, because the `label`
 * class attests the call itself from a second caller in ov186 at
 * 0x02185CC6, independently of this file's own status.
 *
 * Bounds-checked lookup into a 19-entry (0x13) table of u16, 12-byte
 * stride, at offset +2 into the record func_02025B3C indexes. Out of
 * range returns the sentinel 0xE7.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02025BA0.c \
 *       --func func_02025BA0 --addr 0x02025BA0 --cc 1.1p1 --thumb
 */
u32 func_02025BA0(u32 idx)
{
    if (idx < 0x13) {
        return *(const u16 *)(sub_02025BA0_Table + idx * 0xc);
    }
    return 0xE7;
}


u32 func_02025BB8(u32 i)
{
    if (i < 19)
        return d_0209FA34[i * 12];
    return 0;
}


u32 func_02025BD0(u32 i)
{
    if (i < 19)
        return d_0209FA35[i * 12];
    return 18;
}


/*
 * 4 bytes. Returns the constant 0x69. Filed in wave D6 as the unlabelled leaf
 * that ov219 func_02183D14 calls.
 */
int func_02025BE8(void)
{
    return 0x69;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * func_02025BEC is a three-argument predicate: out of range (`a >= 0xE9`)
 * fails immediately; otherwise it looks `a` up through sub_02025B64
 * (src/pending/sub_02025B64.c, parked at MATCH) and fails if the result
 * is below `b`; otherwise, when `c == 1`, it fails unless `a` is one of
 * two special-cased values (0x69 or 0). Every early exit is a direct
 * `return`, not a shared tail, because each guard sits right after the
 * comparison that produces it with nothing in between
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-
 * conjunction.md does not apply here: the guards are not adjacent, they
 * are separated by the calls and comparisons that feed the next one).
 *
 * sub_02025C1C and sub_02025C30 both wrap the predicate with the same
 * shape, "return the value on success, 0 on failure", differing only in
 * which argument is guarded: the first, or the second. Both forward all
 * three arguments to func_02025BEC unchanged; the wrapped argument is
 * kept in its own register (r4) only for the return, which is why the
 * call still carries the original registers.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02025BEC.c \
 *       --addr 0x02025BEC --thumb
 */
u32 func_02025BEC(u32 a, u32 b, u32 c)
{
    if (a >= 0xE9) {
        return 0;
    }
    if (sub_02025B64(a) < b) {
        return 0;
    }
    if (c == 1) {
        if (a != 0x69 && a != 0) {
            return 0;
        }
    }
    return 1;
}



u32 sub_02025C1C(u32 a, u32 b, u32 c)
{
    u32 r = a;

    if (!func_02025BEC(a, b, c)) {
        r = 0;
    }
    return r;
}



u32 sub_02025C30(u32 a, u32 b, u32 c)
{
    u32 r = b;

    if (!func_02025BEC(a, b, c)) {
        r = 0;
    }
    return r;
}



int func_02025C44(u32 a0, u32 *a1, u32 *a2)
{
    u32 i = func_02025B3C(a0);
    u32 off;

    if (i == 0) {
        return 0;
    }
    off = i * 12;
    *a1 = *(u32 *)(g_0209FA38 + off);
    *a2 = g_0209FA3C[off];
    return 1;
}
