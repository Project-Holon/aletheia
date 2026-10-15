/*
 * function: COMM_PLAYER_Resume
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
 *   ICA_ANIME_Check2114  0x02012114  thumb
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_COMM_ACTOR_CTRL_Create  0x02194284  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   COMM_PLAYER_Add  0x021675D0  thumb
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
struct Ctx;
extern u32 ICA_ANIME_Check2114(const struct Ctx *p);
extern void *ICA_ANIME_GetField20(const struct Ctx *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void *FIELD_COMM_ACTOR_CTRL_Create(int a, void *b, int heap, int c);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void MI_CpuFill8(void *p, int v, int n);
extern void COMM_PLAYER_Add(struct Work *w, int idx, int a2, struct Src *src);

void COMM_PLAYER_Resume(Work *w)
{
    Src t;
    Slot *s;
    int i;

    if (ICA_ANIME_Check2114(w->sys) != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (w->obj != 0)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    w->obj = FIELD_COMM_ACTOR_CTRL_Create(w->f8e, FIELDMAP_GetMmdlSys(ICA_ANIME_GetField20(w->sys)), w->f8c, w->f90);
    MI_CpuFill8(&t, 0, 0x14);
    s = (Slot *)w;
    s = (Slot *)((char *)s + 0x1C);
    for (i = 0; i < 4; i++) {
        if (s[i].pend == 1) {
            t.pos = *(Vec3 *)&w->e[i].pos;
            t.f10 = w->e[i].f10;
            t.f0 = 0;
            t.dir = s[i].dir;
            COMM_PLAYER_Add(w, i, w->e[i].f12, &t);
        }
    }
}
