/*
 * function: COMM_PLAYER_Add
 * address:  0x021675D0
 * packet:   pkt_ov010_021675D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_COMM_ACTOR_CTRL_AddActor  0x02194300  thumb  ov021
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

typedef struct Src {
    u32 f0;
    Blk12 pos;
    u16 f10;
} Src;

extern void FIELD_COMM_ACTOR_CTRL_AddActor(u16 *a, int b, int c, u16 *d, int e, int f);

static inline void cpy(Blk12 *d, Blk12 *s)
{
    *d = *s;
}

void COMM_PLAYER_Add(Work *w, int idx, int a2, Src *src)
{
    if (w->obj != 0 && w->e[idx].used != 1) {
        cpy(&w->e[idx].pos, &src->pos);
        *(u16 *)((char *)w + idx * 0x1C + 0x18) = src->f10;
        *(u32 *)((char *)w + idx * 0x1C + 0x14) = src->f0;
        w->e[idx].f12 = a2;
        w->e[idx].pend = 0;
        w->e[idx].used = 1;
        w->e[idx].f18 = 0;
        FIELD_COMM_ACTOR_CTRL_AddActor(w->obj, idx, a2, &w->e[idx].f10, (int)(&w->e[idx]), (int)(&w->e[idx].f0c));
    }
}
