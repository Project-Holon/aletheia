/*
 * file:     comm_player_p02.c
 * unit:     yes
 * function: func_02167590, func_021675D0, func_02167658
 * address:  0x02167590
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02167A74  0x02167A74  thumb
 *   func_02012114  0x02012114  thumb
 *   func_021BB5C8  0x021BB5C8  thumb
 *   func_02194300  0x02194300  thumb  ov021
 *   func_02194354 0x02194354 thumb ov021
 */
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Ent_02167590 {
    u8 pad00[0x14];
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent_02167590;

typedef struct Work_02167590 {
    void *sys;
    void *obj;
    Ent_02167590 e[4];
} Work_02167590;

typedef unsigned long long u64;

typedef struct Blk12 {
    u64 lo;
    u32 hi;
} Blk12;

typedef struct Ent_021675D0 {
    Blk12 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent_021675D0;

typedef struct Work_021675D0 {
    void *sys;
    void *obj;
    Ent_021675D0 e[4];
} Work_021675D0;

typedef struct Src {
    u32 f0;
    Blk12 pos;
    u16 f10;
} Src;

typedef struct { u8 used:1; u8 rest:7; u8 pad[3]; u32 f04; u8 tail[20]; } Slot;

typedef struct { void *sys; void *obj; } Work_02167658;

typedef struct { u8 pad[28]; Slot slot; } Row;

extern void func_02167A74(int a0, int a1);
extern u32 func_02012114(const struct Ctx *p);
extern int func_021BB5C8(u32 v);
extern void func_02194300(u16 *a, int b, int c, u16 *d, int e, int f);
extern void func_02194354(void *, u32);
void func_02167590(void *a, Work_02167590 *w);
void func_021675D0(Work_021675D0 *w, int idx, int a2, Src *src);
void func_02167658(Work_02167658 *p, int i);


void func_02167590(void *a, Work_02167590 *w)
{
    int i;

    func_02167A74((int)a, (int)w);
    if (func_02012114(w->sys) == 1) {
        for (i = 0; i < 4; i++) {
            if (w->e[i].used == 1 && w->e[i].f18 != 0 && func_021BB5C8(w->e[i].f18) == 1)
                w->e[i].f18 = 0;
        }
    }
}


static inline void cpy(Blk12 *d, Blk12 *s)
{
    *d = *s;
}


void func_021675D0(Work_021675D0 *w, int idx, int a2, Src *src)
{
    if (w->obj != 0 && w->e[idx].used != 1) {
        cpy(&w->e[idx].pos, &src->pos);
        *(u16 *)((char *)w + idx * 0x1C + 0x18) = src->f10;
        *(u32 *)((char *)w + idx * 0x1C + 0x14) = src->f0;
        w->e[idx].f12 = a2;
        w->e[idx].pend = 0;
        w->e[idx].used = 1;
        w->e[idx].f18 = 0;
        func_02194300(w->obj, idx, a2, &w->e[idx].f10, (int)(&w->e[idx]), (int)(&w->e[idx].f0c));
    }
}

/*
 * lever: test the one-bit field directly; == 1 inserts an extra cmp.
 * domain: no index bound assumed; flag base and unsigned scaled offset use modulo-32 address arithmetic, with no fixed-array subscript.
 * address lever: separate flags base and off locals preserve the original base/offset registers; a combined raw address folds i+1, while Row accesses share the scaled pointer.
 */
void func_02167658(Work_02167658 *p, int i) {
    Slot *flags;
    u32 off;
    flags = (Slot *)((u32)p + 28u);
    off = (u32)i * 28u;
    if (((Slot *)((u32)flags + off))->used && p->obj != 0) {
        *(u32 *)((u32)p + off + 32u) = 0;
        func_02194354(p->obj, i);
        ((Slot *)((u32)flags + off))->used = 0;
    }
}
