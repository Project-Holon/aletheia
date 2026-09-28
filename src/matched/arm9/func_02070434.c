/*
 * function: func_02070434
 * address:  0x02070434
 * packet:   pkt_02070360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Per-node sampling driver for the packed-halfword tracks: resolves the
 * node's descriptor record through the shared +8 table idiom (inlined
 * GetRec, the same body func_02070730 spells out), samples four tracks with
 * func_0207010C into two packed words at out+4/out+8 (low | high << 16,
 * each keeping its own bit 15 as a flag), and one with func_02070274 into
 * bits 16-20 of out+0xc.  The frame is anim->frame >> 12 (20.12 fixed).
 *
 * Levers: the index is narrowed at the call into a u32-parameter inline
 * helper (`GetRec(node, (u16)idx)`), which gives the image's unsigned
 * `cmp b09, idx, lsr #16` / `bls`; a u16 parameter compares signed.  The
 * permuter's type:l(t:s32->u32) fixed the last r5/r6 swap: the frame local
 * is u32 (the callee takes u32), the shift on the s32 field stays `asr`.
 * Byte-identical under dsi/1.1p1 and ../2.0/sp2; filed at the default.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070434.c
 *       --func func_02070434 --addr 0x02070434 --arm
 *
 * symbols:
 *   func_0207010C  0x0207010C  arm
 *   func_02070274  0x02070274  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Rec70434 { u32 f00, f04, f08, f0c, f10; };
struct Out70434 { u32 f00, f04, f08, f0c; };
struct Node70434 { u8 pad00[9]; u8 b09; u8 pad0a[4]; u16 h0e; };
struct Anim70434 { s32 frame; u32 f04; struct Node70434 *node; };

u16 func_0207010C(u8 *base, u32 flags, u32 idx);
u16 func_02070274(u8 *base, u32 flags, u32 idx);

static inline struct Rec70434 *GetRec(struct Node70434 *node, u32 idx)
{
    u8 *tbl = (u8 *)node + 8;
    if (tbl != 0 && idx < node->b09) {
        u8 *p = tbl + node->h0e;
        return (struct Rec70434 *)(*(u16 *)p * idx + (u32)(p + 4));
    }
    return 0;
}

void func_02070434(struct Out70434 *out, struct Anim70434 *anim, u32 idx)
{
    struct Node70434 *node = anim->node;
    u32 t = anim->frame >> 12;
    struct Rec70434 *r;
    u32 a, b;

    r = GetRec(node, (u16)idx);

    a = func_0207010C((u8 *)node, r->f00, t);
    b = func_0207010C((u8 *)node, r->f04, t);
    out->f04 = a | (b << 16) | (((out->f04 & 0x8000) ? 1 : 0) << 15);

    a = func_0207010C((u8 *)node, r->f0c, t);
    b = func_0207010C((u8 *)node, r->f08, t);
    out->f08 = b | (a << 16) | (((out->f08 & 0x8000) ? 1 : 0) << 15);

    a = func_02070274((u8 *)node, r->f10, t);
    out->f0c = (out->f0c & ~0x1F0000) | (a << 16);
}
