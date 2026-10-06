/*
 * function: func_02070730
 * address:  0x02070730
 * packet:   pkt_0207010C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02070524    0x02070524  arm
 *   func_02070624    0x02070624  arm
 *
 * Samples one animated node's six tracks (two scale, one rotation pair, two
 * translation) out of the per-node track descriptor record, writing the
 * results into the output block and maintaining the three "unchanged" bits of
 * its flags word.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md). Under
 * the pinned default dsi/1.1p1 -O4,p this body is 4 bytes short at +0x00A0;
 * under ../2.0/sp2 the same C is 256 bytes with ZERO concrete mismatches.
 * The one source change from the note was the order of the two translation
 * stores, which the 2.0 diff named directly (+0x0078/+0x007C emitted in
 * source order). Measurement and the probe are in docs/notes/func_02070730.c.txt.
 *
 * Parked at MATCH for lack of WITNESSES, not for lack of bytes: all 5
 * relocation sites (4x func_02070524, 1x func_02070624) are unresolved
 * because neither callee is EXACT in a shard and this function is their only
 * caller in the image, so every witness would fall inside 02070730..02070830
 * and no cut can free them. It becomes EXACT once those two are filed EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02070730.c \
 *       --func func_02070730 --addr 0x02070730 --cc ../2.0/sp2 --arm
 */
#include "../include/Obj02329.h"
#include "../include/Obj16645.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Rec70730 {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24;
};

struct Out70730 {
    u32 f00;
    u32 pad04[5];
    u32 f18, f1c, f20, f24, f28;
};

struct Node70730 {
    u8  pad00[9];
    u8  b09;
    u8  pad0a[4];
    u16 h0e;
};

s32 func_02070524(u32 *base, u32 flags, u32 off, u32 idx);
int func_02070624(u32 *base, u32 flags, u32 off, u32 idx);

void func_02070730(struct Node70730 *node, u32 idx, u32 t, struct Out70730 *out)
{
    u8 *tbl;
    u32 fl;
    s32 a, b;
    struct Rec70730 *r;

    tbl = (u8 *)node + 8;
    if (tbl != 0 && idx < node->b09) {
        u8 *p = tbl + node->h0e;
        r = (struct Rec70730 *)(((struct Obj16645 *)p)->f0 * idx + (u32)(p + 4));
    } else {
        r = 0;
    }

    fl = out->f00;

    a = func_02070524((u32 *)node, r->f18, r->f1c, t);
    b = func_02070524((u32 *)node, r->f20, r->f24, t);
    if (a == 0 && b == 0) {
        fl |= 4;
    } else {
        out->f24 = (u32)a;
        out->f28 = (u32)b;
        fl &= ~4u;
    }

    a = func_02070624((u32 *)node, r->f10, r->f14, t);
    if (a == 0x10000000) {
        fl |= 2;
        goto rot_done;
    }
    {
        u32 rv = (u32)a;
        ((struct Obj02329 *)out)->f20 = (u16)rv;
        rv >>= 16;
        ((struct Obj02329 *)out)->f22 = (u16)rv;
    }
    fl &= ~2u;
rot_done:
    ;

    a = func_02070524((u32 *)node, r->f00, r->f04, t);
    b = func_02070524((u32 *)node, r->f08, r->f0c, t);
    if (a == 0x1000 && b == 0x1000) {
        fl |= 1;
    } else {
        out->f18 = a;
        out->f1c = b;
        fl &= ~1u;
    }

    out->f00 = fl;
}
