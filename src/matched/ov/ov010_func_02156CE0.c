/*
 * function: func_02156CE0
 * address:  0x02156CE0
 * packet:   pkt_ov010_02156CE0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the ov010 stage: four members with their records, the ov112 deal
 * and its split. First draft plus two levers: the pooled 0x70 is ov112_id,
 * and the three colour masks come from one `mask` local shifted.
 *
 * symbols:
 *   func_02156F68  0x02156F68  thumb  ov010
 *   func_02156FD0  0x02156FD0  thumb  ov010
 *   func_0215700C  0x0215700C  thumb  ov010
 *   func_02157028  0x02157028  thumb  ov010
 *   func_02157174  0x02157174  thumb  ov010
 *   func_021F685C  0x021F685C  thumb  ov112
 *   func_021F68BC  0x021F68BC  thumb  ov112
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   ov112_id       0x00000070  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct Member {
    u8 pad00[0x4A];
    u16 total;          /* 0x4A */
} Member;

typedef struct Stage {
    void *f00;          /* 0x00 */
    Member *f04[4];     /* 0x04 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    u8 pad1c[0x20 - 0x1C];
} Stage;

typedef struct Work {
    Stage *stage;       /* 0x00 */
    u32 f04;
    u32 f08;
} Work;

extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(void *ctx, int size, int heap);
typedef signed int     s32;
struct Deal;
struct Src;
extern int func_02034AC4(s32 handle);
extern u8 ov112_id[];
extern Stage *func_02156F68(u32 heap, void *p);
extern void func_02156FD0(Stage *s, u8 idx, u16 id, u8 v, u32 w, u16 x, u16 y);
extern void func_0215700C(Stage *s, u8 idx, u8 j, u16 id, s16 a, u8 b);
extern struct Deal *func_02157028(u32 heap, struct Src *src, u16 lim);
extern void func_02157174(u32 heap, void *d, Stage *s);
extern void *func_021F685C(u32 a);
extern void func_021F68BC(void *p, u32 a, u32 b, u32 c, u32 d);

int func_02156CE0(void *proc, void *unused, Stage *prev)
{
    Work *w;
    u32 mask;

    func_0203064C(1, 0x2E, 0xA8000);
    w = func_0203159C(proc, sizeof(Work), 0x2E);
    if (prev == 0) {
        func_02034AC4((u32)ov112_id);
        w->stage = func_02156F68(0x2E, 0);
        mask = 0xFF000000;
        func_02156FD0(w->stage, 0, 0x147, 0, mask, 60, 0x2E);
        func_02156FD0(w->stage, 1, 0x147, 0, mask >> 8, 120, 0x2E);
        func_02156FD0(w->stage, 2, 0x147, 0, mask >> 16, -3, 0x2E);
        func_02156FD0(w->stage, 3, 0x147, 0, 0x000000FF, -1, 0x2E);
        func_0215700C(w->stage, 0, 7, 0x13, 0, 0);
        func_0215700C(w->stage, 0, 8, 0x13, 0, 1);
        func_0215700C(w->stage, 0, 2, 0x10, 0, 2);
        func_0215700C(w->stage, 1, 1, 0x07, 0, 0);
        func_0215700C(w->stage, 1, 5, 0x09, 0, 1);
        func_0215700C(w->stage, 1, 7, 0x18, 0, 2);
        func_0215700C(w->stage, 1, 8, 0x2B, 0, 3);
        func_0215700C(w->stage, 2, 7, 0x1F, 0, 0);
        func_0215700C(w->stage, 2, 8, 0x1E, 0, 1);
        func_0215700C(w->stage, 2, 2, 0x0F, 0, 2);
        func_0215700C(w->stage, 3, 7, 0x1E, 0, 0);
        func_0215700C(w->stage, 3, 8, 0x1E, 0, 1);
        func_0215700C(w->stage, 3, 2, 0x15, 0, 2);
        *(u32 *)w->stage->f04[1] = 0;
        func_0203064C(1, 0x802C, 0x80000);
        w->stage->f18 = func_021F685C(1);
        func_021F68BC(w->stage->f18, 0, 0, 0, 0x2C);
        w->stage->f14 = func_02157028(0x2E, w->stage->f18, 0);
        func_02157174(0x2E, w->stage->f14, w->stage);
        w->stage->f04[0]->total = 75;
        w->stage->f04[1]->total = 45;
        w->stage->f04[2]->total = 30;
        w->stage->f04[3]->total = 0;
    } else {
        w->stage = prev;
    }
    return 1;
}
