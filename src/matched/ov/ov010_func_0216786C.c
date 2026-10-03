/*
 * function: func_0216786C
 * address:  0x0216786C
 * packet:   pkt_ov010_0216786C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Report the player's position, zone and facing (from the saved copy
 * while flying, from the ov021 rail object, or from the player object),
 * returning 1 only when it differs from the last report. One lever: the
 * change test written positively so the update block comes before the
 * `return 0`.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014484  0x02014484  thumb
 *   func_02012114  0x02012114  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A34EC  0x021A34EC  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_02012AA0  0x02012AA0  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_0203EFC8  0x0203EFC8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Where {
    VecFx32 pos;        /* 0x00 */
    u16 zone;           /* 0x0C */
    u8 dir : 4;         /* 0x0E */
    u8 flag : 1;
} Where;

typedef struct Report {
    u32 flag;           /* 0x00 */
    VecFx32 pos;        /* 0x04 */
    u16 zone;           /* 0x10 */
    u8 dir;             /* 0x12 */
} Report;

typedef struct Work {
    void *sys;          /* 0x00 */
    u8 pad04[0x78 - 0x04];
    Where last;         /* 0x78 */
    u8 pad88[0x8F - 0x88];
    u8 f8f;             /* 0x8F */
} Work;

struct BigObj;
struct Ctx;
struct Rec44;
struct SaveBlock;
struct Sub02014444Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern void *func_02012B38(const struct BigObj *p);
extern u8 func_02014484(struct Sub02014444Obj *o);
extern u32 func_02012114(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188BE8(void *proc);
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(u8 *p);
extern int func_021A34EC(void *q);
extern void func_021A3038(void *q, VecFx32 *v);
extern void func_02197CCC(void *a, VecFx32 *v);
extern u16 func_021A3050(u8 *p);
extern VecFx32 *func_02012AA0(void *pl);
extern u16 func_02012AE4(void *pl);
extern int func_0203EFC8(const void *a, const void *b, u32 n);

int func_0216786C(Work *w, Report *out)
{
    VecFx32 pos;
    void *a;
    void *pl;
    void *ctx;
    Where *last;
    void *q;
    u32 flag;
    u32 dir;
    u16 zone;

    ctx = func_020120F4(w->sys);
    last = &w->last;
    flag = 0;
    if (w->f8f == 1)
        return 0;
    pl = func_020127A4(ctx);
    dir = func_02012B28(pl);
    if (func_02014484(func_02012B38(ctx)) == 2) {
        zone = last->zone;
        pos = last->pos;
        flag = 1;
        dir = last->dir;
    } else if (func_02012114(w->sys) == 1 && func_02188BE8(func_0201210C(w->sys)) == 1) {
        q = func_02188CB4(func_0201210C(w->sys));
        a = func_021A3074(q);
        if (func_021A34EC(q) == 4)
            func_021A3038(q, &pos);
        else
            func_02197CCC(a, &pos);
        zone = func_021A3050(q);
    } else {
        pos = *func_02012AA0(pl);
        zone = func_02012AE4(pl);
    }
    out->zone = zone;
    out->pos = pos;
    out->flag = flag;
    out->dir = dir;
    if (zone != last->zone || dir != last->dir || flag != last->flag
        || func_0203EFC8(&pos, last, sizeof(VecFx32)) != 0) {
        last->zone = zone;
        last->pos = pos;
        last->dir = dir;
        last->flag = flag;
        return 1;
    }
    return 0;
}
