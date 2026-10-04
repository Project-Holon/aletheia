/*
 * function: func_02070360
 * address:  0x02070360
 * packet:   pkt_02070360
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Channel binder: seeds ctx->f0c from the handler table word at
 * data_020A8230, copies the slot count, clears the halfword slot table at
 * +0x1a, then for each of src's b09 name entries resolves the name through
 * func_0206E7EC and stores `i | 0x100` at the returned slot.
 *
 * WHAT CLOSED IT (wave 10), after the 10-instruction prologue window of
 * docs/notes/func_02070360.c.txt at 1.1p1: the body is two INLINE HELPERS,
 * a name-entry accessor GetName(src, i) (the +8 table idiom, entries at a
 * 0x10 stride that the compiler strength-reduces into the r8 step) and a
 * guarded lookup Lookup(names, ent) returning -1 when there is no name
 * table.  Written that way the function is size-exact under ../2.0/sp2 and
 * the prologue window is right (the separate `mov r0,#0` for the clear's
 * fill and `mov r6,#0` for the counter is the pin's "kept constants" tell);
 * dsi/1.1p1 on the same C is 204 bytes with an 8-register push.  The last
 * r6/r7 swap is declaration order: `u32 i;` before `u8 *names;`.
 * `volatile u8 b09` is still required (216 bytes without it).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070360.c
 *       --func func_02070360 --addr 0x02070360 --arm --cc ../2.0/sp2
 *
 * symbols:
 *   MIi_CpuClear16   0x02082A48  arm
 *   func_0206E7EC    0x0206E7EC  arm
 *   data_020A8230    0x020A8230  data
 */
#include "../include/Obj16639.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Src70360 {
    u8  pad00[8];
    u8  b08;
    volatile u8 b09;
    u8  pad0a[4];
    u16 h0e;
};

struct Ctx70360 {
    u8  pad00[8];
    u32 f08;
    u32 f0c;
    u8  pad10[9];
    u8  b19;
    u16 h1a[1];
};

struct Arg70360 {
    u8  pad00[8];
    u32 f08;
    u8  pad0c[12];
    u8  b18;
};

extern u32 data_020A8230;

void MIi_CpuClear16(u16 value, void *dest, u32 size);
s32 func_0206E7EC(void *name, void *ent);

static inline void *GetName(struct Src70360 *src, u32 idx)
{
    u8 *tbl = (u8 *)src + 8;
    if (tbl != 0 && idx < src->b09) {
        u8 *q = tbl + src->h0e;
        return q + ((struct Obj16639 *)q)->f2 + idx * 0x10;
    }
    return 0;
}

static inline s32 Lookup(u8 *names, void *ent)
{
    if (names != 0)
        return func_0206E7EC(names + 4, ent);
    return -1;
}

void func_02070360(struct Ctx70360 *ctx, struct Src70360 *src, struct Arg70360 *arg)
{
    u32 i;
    u8 *names;

    if (arg != 0 && arg->f08 != 0)
        names = (u8 *)arg + arg->f08;
    else
        names = 0;

    ctx->f0c = data_020A8230;
    ctx->b19 = arg->b18;
    MIi_CpuClear16(0, ctx->h1a, (u32)ctx->b19 * 2);

    for (i = 0; i < src->b09; i++) {
        s32 slot = Lookup(names, GetName(src, i));
        if (slot >= 0)
            ctx->h1a[slot] = (u16)(i | 0x100);
    }
}
