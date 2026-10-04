/*
 * function: func_02070830
 * address:  0x02070830
 * packet:   pkt_02070360
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Twin of func_02070360, instruction for instruction: the same channel
 * binder, differing only in the handler-table word that seeds ctx->f0c
 * (data_020A8228, which holds &func_02070904, where func_02070360 reads
 * data_020A8230 = &func_02070434).  The table at 0x020A8220.. pairs each
 * binder (0x020A8244.., tagged by a 4-char kind word) with the per-frame
 * driver it installs.  Same levers as func_02070360: the GetName/Lookup
 * inline helpers, `volatile u8 b09`, `i` declared before `names`, and the
 * ../2.0/sp2 pin.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070830.c
 *       --func func_02070830 --addr 0x02070830 --arm --cc ../2.0/sp2
 *
 * symbols:
 *   MIi_CpuClear16   0x02082A48  arm
 *   func_0206E7EC    0x0206E7EC  arm
 *   data_020A8228    0x020A8228  data
 */
#include "../include/Obj16646.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Src70830 {
    u8  pad00[8];
    u8  b08;
    volatile u8 b09;
    u8  pad0a[4];
    u16 h0e;
};

struct Ctx70830 {
    u8  pad00[8];
    u32 f08;
    u32 f0c;
    u8  pad10[9];
    u8  b19;
    u16 h1a[1];
};

struct Arg70830 {
    u8  pad00[8];
    u32 f08;
    u8  pad0c[12];
    u8  b18;
};

extern u32 data_020A8228;

void MIi_CpuClear16(u16 value, void *dest, u32 size);
s32 func_0206E7EC(void *name, void *ent);

static inline void *GetName(struct Src70830 *src, u32 idx)
{
    u8 *tbl = (u8 *)src + 8;
    if (tbl != 0 && idx < src->b09) {
        u8 *q = tbl + src->h0e;
        return q + ((struct Obj16646 *)q)->f2 + idx * 0x10;
    }
    return 0;
}

static inline s32 Lookup(u8 *names, void *ent)
{
    if (names != 0)
        return func_0206E7EC(names + 4, ent);
    return -1;
}

void func_02070830(struct Ctx70830 *ctx, struct Src70830 *src, struct Arg70830 *arg)
{
    u32 i;
    u8 *names;

    if (arg != 0 && arg->f08 != 0)
        names = (u8 *)arg + arg->f08;
    else
        names = 0;

    ctx->f0c = data_020A8228;
    ctx->b19 = arg->b18;
    MIi_CpuClear16(0, ctx->h1a, (u32)ctx->b19 * 2);

    for (i = 0; i < src->b09; i++) {
        s32 slot = Lookup(names, GetName(src, i));
        if (slot >= 0)
            ctx->h1a[slot] = (u16)(i | 0x100);
    }
}
