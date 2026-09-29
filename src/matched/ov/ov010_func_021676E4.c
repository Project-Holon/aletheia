/*
 * function: func_021676E4
 * address:  0x021676E4
 * packet:   pkt_ov010_021676E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012114  0x02012114  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02194284  0x02194284  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021675D0  0x021675D0  thumb
 *   d_02172A28     0x02172A28  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Blk12 {
    u64 lo;
    u32 hi;
} Blk12;

typedef struct Flags {
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
} Flags;

typedef struct Ent {
    Blk12 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    Flags fl;
    u8 f15[3];
    u32 f18;
} Ent;

typedef struct Slot {
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 pad[0x1B];
} Slot;

typedef struct Work {
    void *sys;
    void *obj;
    Ent e[4];
    u8 pad78[0x8C - 0x78];
    u16 f8c;
    u8 f8e;
    u8 pad8f;
    u8 f90;
} Work;

typedef struct Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

typedef struct Src {
    u32 f0;
    Vec3 pos;
    u16 f10;
    u8 dir;
} Src;

extern u8 d_02172A28[];
extern int func_02012114(void *sys);
extern void *func_0201210C(void *sys);
extern void *func_02188C7C(void *p);
extern void *func_02194284(u8 a, void *b, u16 c, u8 d);
extern void func_02034714(void *a, int b, void *c);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021675D0(Work *w, int i, u16 a2, Src *src);

void func_021676E4(Work *w)
{
    Src t;
    Slot *s;
    int i;

    if (func_02012114(w->sys) != 1)
        func_02034714(d_02172A28, 0, d_02172A28);
    if (w->obj != 0)
        func_02034714(d_02172A28, 0, d_02172A28);
    w->obj = func_02194284(w->f8e, func_02188C7C(func_0201210C(w->sys)), w->f8c, w->f90);
    func_02082BCC(&t, 0, 0x14);
    s = (Slot *)w;
    s = (Slot *)((char *)s + 0x1C);
    for (i = 0; i < 4; i++) {
        if (s[i].pend == 1) {
            t.pos = *(Vec3 *)&w->e[i].pos;
            t.f10 = w->e[i].f10;
            t.f0 = 0;
            t.dir = s[i].dir;
            func_021675D0(w, i, w->e[i].f12, &t);
        }
    }
}
