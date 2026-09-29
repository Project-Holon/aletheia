/*
 * function: func_021679C4
 * address:  0x021679C4
 * packet:   pkt_ov010_021679C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021943EC  0x021943EC  thumb  ov021
 *   func_021BB578  0x021BB578  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Blk12 {
    u64 lo;
    u32 hi;
} Blk12;

typedef struct Ent {
    Blk12 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent;

typedef struct Work {
    void *sys;
    void *obj;
    Ent e[4];
} Work;

extern void *func_0201210C(void *sys);
extern void *func_02188CD0(void *p);
extern void *func_021943EC(void *obj, int i);
extern u32 func_021BB578(void *a, void *b, int c, int d);

int func_021679C4(Work *w, int i)
{
    Ent *e;
    void *a;

    e = &w->e[i];
    if (w->obj == 0 || e->used == 0 || e->f18 != 0)
        return 0;
    a = func_02188CD0(func_0201210C(w->sys));
    e->f18 = func_021BB578(a, func_021943EC(w->obj, i), 0, 0);
    return 1;
}
