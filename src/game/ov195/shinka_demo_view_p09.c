/*
 * file:     shinka_demo_view_p09.c
 * unit:     yes
 * function: func_022067B0, func_022067BC, func_022067FC, func_0220682C, func_0220685C, func_02206A3C
 * address:  0x022067B0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022081A4 0x022081A4 thumb ov195
 *   func_022083CC 0x022083CC thumb ov195
 *   func_02208420 0x02208420 thumb ov195
 *   d_02208F68 0x02208F68 data
 *   func_02030734 0x02030734 arm
 *   func_02043678 0x02043678 arm
 *   func_0202D060 0x0202D060 thumb
 *   func_0202D064 0x0202D064 thumb
 *   func_0202D0D4 0x0202D0D4 thumb
 *   func_02049E34 0x02049E34 arm
 *   func_02049F34 0x02049F34 arm
 *   func_020437D4 0x020437D4 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_02082A90 0x02082A90 arm
 *   func_02044F64 0x02044F64 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_020437AC 0x020437AC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj10826.h"
#include "../../matched/include/Obj00300.h"
#include "../../matched/include/Obj10827.h"

struct Fade;
struct Bmp;
struct Obj020437AC;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct Grid_022067BC {
    u8 pad00[0x28];
    int state;
} Grid_022067BC;

typedef struct Work {
    u32 f00;
    u32 f04;
    Grid_022067BC *grid[2];
} Work;

typedef struct Owner {
    u16 heap;
    u8 pad02[0x56];
    Work *work;
} Owner;

typedef struct CharData {
    u8 pad00[0x14];
    u8 *raw;
} CharData;

typedef struct PlttData {
    u8 pad00[0xc];
    void *raw;
} PlttData;

typedef struct Grid_0220685C {
    CharData *chr;
    PlttData *pltt;
    void *chrRes;
    void *plttRes;
    void *canvas;
    u32 tex;
    u32 plttAddr;
    u8 rest[0xA278 - 0x1c];
} Grid_0220685C;

typedef signed int     s32;

extern void func_022081A4(struct Fade *p, int unused, u16 color, s16 cur, s16 end, s16 wait, s16 step);
extern int func_022083CC(char *, u16);
extern int func_02208420(char *, u16);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern int func_0202D060(void);
extern s32 func_0202D064(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern struct Bmp *func_02044F64(struct Bmp *src, u32 keep, u16 heap);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
void func_022067B0(char *a, int b, int c, int d, int e);
void func_022067BC(Owner *o);
int func_022067FC(char *a);
int func_0220682C(char *a);
Grid_0220685C *func_0220685C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 tex, u32 pltt, u16 heap);
void func_02206A3C(char *p, int a1);
extern char d_02208F68[];


void func_022067B0(char *a, int b, int c, int d, int e)
{
    ((struct Obj10826 *)a)->f1C = c;
    *(int *)(a + 0x1c + 4) = d;
    *(int *)(a + 0x1c + 8) = e;
}


void func_022067BC(Owner *o)
{
    int heap = o->heap;
    Work *w = o->work;
    u8 i;
    Grid_022067BC *g;

    for (i = 0; i < 2; i++) {
        g = w->grid[i];
        if (g != 0) {
            g->state = 5;
            func_022081A4((struct Fade *)g, heap, 0x7fff, 31, 0, 0, -1);
        }
    }
}


int func_022067FC(char *a)
{
    u16 id = ((struct Obj00300 *)a)->f0;
    char *t = *(char * *)&((struct Obj00300 *)a)->f58;
    int r = 1;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(char **)(t + i * 4 + 8) != 0 && func_022083CC(*(char **)(t + i * 4 + 8), id) == 0)
            r = 0;
    }
    return r;
}


int func_0220682C(char *a)
{
    u16 id = ((struct Obj00300 *)a)->f0;
    char *t = *(char * *)&((struct Obj00300 *)a)->f58;
    int r = 1;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(char **)(t + i * 4 + 8) != 0 && func_02208420(*(char **)(t + i * 4 + 8), id) == 0)
            r = 0;
    }
    return r;
}


Grid_0220685C *func_0220685C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 tex, u32 pltt, u16 heap)
{
    Grid_0220685C *g = func_02030734(heap, sizeof(Grid_0220685C), 1, d_02208F68, 0x720);
    u32 chrFile;
    u32 plttFile;
    u8 *src;
    u8 *buf;
    int i, j;
    int k;

    g->canvas = func_02043678(16, 16, 32, heap);
    g->tex = tex;
    g->plttAddr = pltt;
    chrFile = func_0202D064(func_0202D060(), a0, a1, a2, a3, a4, a5);
    plttFile = func_0202D0D4(func_0202D060(), a0, a1, a2, a3, a4, a5);
    g->chr = 0;
    g->pltt = 0;
    g->chrRes = func_02049E34(func_0202D060(), chrFile, 1, (u32)(&g->chr), heap);
    g->plttRes = func_02049F34(func_0202D060(), plttFile, (u32)(&g->pltt), heap);
    src = g->chr->raw;
    buf = func_020437D4(g->canvas);
    func_02082A7C(0, buf, 0x2000);
    k = 0;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 0; j < 8; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    func_02044F64(g->canvas, 0, heap);
    func_02061CA4(0, tex, (u32)func_020437D4(g->canvas), 0x2000);
    func_02061CA4((void *)1, pltt, (u32)g->pltt->raw, 0x20);
    return g;
}


void func_02206A3C(char *p, int a1)
{
    func_020437AC(((struct Obj10827 *)p)->f10);
    func_020307B0(((struct Obj10827 *)p)->f8);
    func_020307B0(((struct Obj10827 *)p)->fC);
    func_020307B0(p);
}
