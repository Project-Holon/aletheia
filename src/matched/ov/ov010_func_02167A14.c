/*
 * function: COMM_PLAYER_GetPlayerModel
 * address:  0x02167A14
 * packet:   pkt_ov010_02167A14
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   FIELD_COMM_ACTOR_CTRL_GetMmdl  0x021943EC  thumb  ov021
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

extern u8 d_02172A28[];
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Tbl;
extern u32 FIELD_COMM_ACTOR_CTRL_GetMmdl(struct Tbl *t, u32 key);

u32 COMM_PLAYER_GetPlayerModel(Work *w, int i)
{
    if (w->obj == 0)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (w->e[i].used != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    return FIELD_COMM_ACTOR_CTRL_GetMmdl(w->obj, i);
}
