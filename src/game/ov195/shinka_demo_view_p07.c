/*
 * file:     shinka_demo_view_p07.c
 * unit:     yes
 * function: func_02206274, func_022063AC, func_022063E0
 * address:  0x02206274
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
 *   func_02015F0C 0x02015F0C thumb
 *   func_02015F1C 0x02015F1C thumb
 *   func_02015F14 0x02015F14 thumb
 *   func_02015C78 0x02015C78 thumb
 *   _ffltu 0x0209BE04 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fgr 0x0209BBB0 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02015C30 0x02015C30 thumb
 *   func_02015C48 0x02015C48 thumb
 *   d_02208F68 0x02208F68 data
 *   d_02208E74 0x02208E74 data
 *   d_02208E80 0x02208E80 data
 *   FX_SinCosTable_ 0x020A1B38 data
 *   func_02030734 0x02030734 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017F00 0x02017F00 thumb
 *   func_02017EAC 0x02017EAC thumb
 *   func_02048A24 0x02048A24 arm
 *   func_0220685C 0x0220685C thumb ov195
 *   func_02206A5C 0x02206A5C thumb ov195
 *   func_02206E2C 0x02206E2C thumb ov195
 *   func_022081A4 0x022081A4 thumb ov195
 *   func_02208478 0x02208478 thumb ov195
 *   func_02206768 0x02206768 thumb ov195
 */
#include "../../matched/include/Obj10822.h"

#define FX_F32_TO_FX32(x) \
    ((fx32)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
struct Quad;
struct Fade;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct Owner_02206274 {
    u8 pad00[0x44];
    float scale;
    u8 pad48[0x50 - 0x48];
    void *obj[2];
} Owner_02206274;

typedef signed short   s16;

typedef struct Cell {
    u8 pad00[0x14];
    u8 visible;
    u8 pad15[0x80 - 0x15];
} Cell;

typedef struct Row {
    Cell cell[0x12];
} Row;

typedef struct Grid {
    u8 pad00[0x28];
    int state;
    u8 pad2c[0x74 - 0x2c];
    Row row[0x12];
} Grid;

typedef struct Work {
    u32 f00;
    void *camera;
    Grid *grid[2];
    void *quad;
} Work;

typedef struct Owner_022063E0 {
    u16 heap;
    u16 pad02;
    void *res0;
    u32 f08;
    u16 f0c;
    u16 pad0e;
    void *res1;
    u8 pad14[0x58 - 0x14];
    Work *work;
} Owner_022063E0;

extern u16 func_02015F0C(void *p);
extern s16 func_02015F1C(void *p);
extern s16 func_02015F14(void *p);
extern void func_02015C78(void *p, u32 *src);
extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u8 func_02017F00(void *p);
extern u32 func_02017EAC(void *p);
extern void *func_02048A24(u32 a0, fx32 sin, fx32 cos, fx32 aspect, u32 a4, fx32 a5,
                           fx32 a6, u32 a7, VecFx32 *a8, VecFx32 *a9, VecFx32 *a10,
                           u16 heap);
extern Grid *func_0220685C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7,
                           u16 heap);
extern void func_02206A5C(Grid *g, u16 heap);
extern void func_02206E2C(Grid *g, u16 heap);
extern void func_022081A4(struct Fade *p, int unused, u16 color, s16 cur, s16 end, s16 wait, s16 step);
extern struct Quad *func_02208478(u32 tex, u32 pltt, u16 heap);
extern void func_02206768(char *a, u32 x, u32 y, u32 z);
void func_02206274(Owner_02206274 *o);
void func_022063AC(char *a, u32 v);
void func_022063E0(Owner_022063E0 *o);
extern char d_02208F68[];
extern const VecFx32 d_02208E74;
extern const VecFx32 d_02208E80;
extern const s16 FX_SinCosTable_[];


/*
 * mwccarm calls the add helper (0x0209C95C) _fadd and the subtract helper
 * (0x0209CB8C) _fsub, as layout/runtime_arm9.txt now does (swapped there
 * until 2026-09-28).
 */
void func_02206274(Owner_02206274 *o)
{
    u8 i;
    float w, h, d;
    float x, y;
    VecFx32 pos;

    for (i = 0; i < 2; i++) {
        if (o->obj[i] != 0) {
            w = func_02015F0C(o->obj[i]);
            h = func_02015F1C(o->obj[i]);
            d = func_02015F14(o->obj[i]);
            w = w * (o->scale / 16.0f);
            if (w > 96.0f)
                w = 96.0f;
            h = h * (o->scale / 16.0f);
            d = d * (o->scale / 16.0f);
            x = ((96.0f - w) / 2.0f + h) * 0.33f;
            y = (0.0f - d) * 0.33f;
            pos.x = FX_F32_TO_FX32(y);
            pos.y = FX_F32_TO_FX32(x);
            pos.z = 0;
            func_02015C78(o->obj[i], (u32 *)(&pos));
        }
    }
}


void func_022063AC(char *a, u32 v)
{
    u32 buf[3];
    u8 i;

    for (i = 0; i < 2; i++) {
        char *p = a + i * 4;
        if (((struct Obj10822 *)p)->f50 != 0) {
            func_02015C30((void *)(((struct Obj10822 *)p)->f50), buf);
            buf[0] = v;
            func_02015C48((void *)(((struct Obj10822 *)p)->f50), buf);
        }
    }
}


static inline fx32 FX_SinIdx(int idx)
{
    return FX_SinCosTable_[idx * 2];
}


static inline fx32 FX_CosIdx(int idx)
{
    return FX_SinCosTable_[idx * 2 + 1];
}


void func_022063E0(Owner_022063E0 *o)
{
    Work *w = func_02030734(o->heap, sizeof(Work), 1, d_02208F68, 0x54c);
    Grid *g;
    u32 a, b, c;
    u8 j, k;

    w->grid[0] = 0;
    w->grid[1] = 0;
    w->quad = 0;
    if (o->f08 == 0)
        w->f00 = 0;
    else
        w->f00 = 3;

    a = func_02017E1C(o->res0, 5, 0);
    b = func_02017E1C(o->res0, 0x6f, 0);
    c = func_02017F00(o->res0);
    g = w->grid[0] = func_0220685C(a, b, c, func_02017EAC(o->res0), 0, 0, 0x26000, 0x960, o->heap);
    if (o->f08 == 0) {
        func_02206A5C(g, o->heap);
        g->state = 3;
        func_022081A4((struct Fade *)g, o->heap, 0x7fff, 31, 31, 0, 31);
    } else {
        func_02206E2C(g, o->heap);
    }

    if (o->f08 == 0) {
        a = func_02017E1C(o->res1, 5, 0);
        b = func_02017E1C(o->res1, 0x6f, 0);
        c = func_02017F00(o->res1);
        g = w->grid[1] = func_0220685C(a, b, c, func_02017EAC(o->res1), 0, 0, 0x28000, 0x980, o->heap);
        func_02206A5C(g, o->heap);
        g->state = 3;
        func_022081A4((struct Fade *)g, o->heap, 0x7fff, 31, 31, 0, 31);
        for (j = 0; j < 0x12; j++) {
            for (k = 0; k < 0x12; k++)
                g->row[j].cell[k].visible = 0;
        }
    }

    if (o->f08 == 0)
        w->quad = func_02208478(0x26000, 0x960, o->heap);
    o->work = w;
    func_02206768((char *)o, 0x100000, -0x800, 0);
    {
        VecFx32 v1 = d_02208E74;
        VecFx32 v2 = d_02208E80;
        VecFx32 v3 = {0, 0, 0};

        w->camera = func_02048A24(0, FX_SinIdx(0xe3), FX_CosIdx(0xe3),
                                  0x1555, 0, 0x1000, 0x400000, 0, &v1, &v2, &v3, o->heap);
    }
}
