/*
 * function: func_02070948
 * address:  0x02070948
 * packet:   pkt_02070360
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Third member of the func_02070360 / func_02070830 binder set.  Same body
 * with two differences: it also records the source resource in ctx->f08
 * (the u32 store is why the clear's size re-reads ctx->b19 from memory: the
 * store may alias it), and its name dictionary sits at src+0xc (count at
 * +0xd, entry offset at +0x12) instead of src+8.  Seeds ctx->f0c from
 * data_020A822C (= &func_02070B64).  Same levers: GetName/Lookup inline
 * helpers, `volatile` count byte, `i` declared before `names`, ../2.0/sp2.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070948.c
 *       --func func_02070948 --addr 0x02070948 --arm --cc ../2.0/sp2
 *
 * symbols:
 *   MIi_CpuClear16   0x02082A48  arm
 *   func_0206E7EC    0x0206E7EC  arm
 *   data_020A822C    0x020A822C  data
 */
#include "../include/Obj16648.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Src70948 {
    u8  pad00[12];
    u8  b0c;
    volatile u8 b0d;
    u8  pad0e[4];
    u16 h12;
};

struct Ctx70948 {
    u8  pad00[8];
    u32 f08;
    u32 f0c;
    u8  pad10[9];
    u8  b19;
    u16 h1a[1];
};

struct Arg70948 {
    u8  pad00[8];
    u32 f08;
    u8  pad0c[12];
    u8  b18;
};

extern u32 data_020A822C;

void MIi_CpuClear16(u16 value, void *dest, u32 size);
s32 func_0206E7EC(void *name, void *ent);

static inline void *GetName(struct Src70948 *src, u32 idx)
{
    u8 *tbl = (u8 *)src + 0xc;
    if (tbl != 0 && idx < src->b0d) {
        u8 *q = tbl + src->h12;
        return q + ((struct Obj16648 *)q)->f2 + idx * 0x10;
    }
    return 0;
}

static inline s32 Lookup(u8 *names, void *ent)
{
    if (names != 0)
        return func_0206E7EC(names + 4, ent);
    return -1;
}

void func_02070948(struct Ctx70948 *ctx, struct Src70948 *src, struct Arg70948 *arg)
{
    u32 i;
    u8 *names;

    if (arg != 0 && arg->f08 != 0)
        names = (u8 *)arg + arg->f08;
    else
        names = 0;

    ctx->f0c = data_020A822C;
    ctx->b19 = arg->b18;
    ctx->f08 = (u32)src;
    MIi_CpuClear16(0, ctx->h1a, (u32)ctx->b19 * 2);

    for (i = 0; i < src->b0d; i++) {
        s32 slot = Lookup(names, GetName(src, i));
        if (slot >= 0)
            ctx->h1a[slot] = (u16)(i | 0x100);
    }
}
