/*
 * function: NNSi_G3dGetNodeScaleFromMdl
 * address:  0x0206EC50
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gCurrentRS      0x02148DB0  data
 *
 * Resolves the current node through the global stash at 0x02148DB0 (root ->
 * bank at +0xD4, bank -> entry through the halfword-indexed table at
 * bank+6, entry -> node by the relative offset at entry+0), skips the node's
 * optional header blocks by its flag bits, and hands the payload to the
 * root's hook at +0xE8.  NNSi_G3dAnmCalcJntAnmNode calls it for the third flag group.
 *
 * Closing levers over the 23-30 byte register residue recorded in
 * docs/notes/pkt_0206EB00.c.txt (which no respelling of a flat goto body
 * could move):
 *   - the resolve is TWO NESTED INLINE HELPERS, entry_of() and resolve().
 *     Inlining is what renumbers the values so that the root lands in ip and
 *     the bank in r4; the same statements written flat in the body stay at
 *     7-16 bytes out whatever the declaration order (tools/permuter.py hill
 *     and anneal, 4000+ compiles, found nothing);
 *   - the hook takes FOUR arguments, (arg, payload, root->h, flags): the
 *     image loads root->h into r2 at 0x0206EC5C and never writes r2 again,
 *     and the flag word stays in r3 up to the `blx`.  The same four-argument
 *     hook, with root->h as its third argument, is what NNSi_G3dAnmCalcJntAnmNode calls
 *     at its emit tail.  A three-argument call is 21 bytes out.
 *
 * Front end: filed under the packet's ../2.0/sp2 unit pin.  With the inline
 * helpers this function is compiler-neutral (EXACT under dsi/1.1p1 as well,
 * measured 2026-09-22): the "kept branches" double `beq` the earlier note
 * attributed to the front end is what the nested inline produces under both.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dGetNodeScaleFromMdl.c \
 *       --func NNSi_G3dGetNodeScaleFromMdl --addr 0x0206EC50 --cc ../2.0/sp2 --arm
 */
#include "../include/Obj16624.h"
#include "../include/G_Root.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { u8 unk00; u8 idx01; } Hdr;
typedef struct { u8 unk00; u8 cnt01; u8 unk02[4]; u16 off06; } Bank;
typedef struct Root Root;
typedef struct { u32 rel00; } Ent;

extern struct Root *gCurrentRS;

static inline u8 *entry_of(Bank *b, u32 idx)
{
    u8 *t;
    if (b != 0 && idx < b->cnt01) {
        t = (u8 *)b + b->off06;
        return t + 4 + (((struct Obj16624 *)t)->f0) * idx;
    }
    return 0;
}

static inline u8 *resolve(Bank *b, u32 idx)
{
    u8 *e;
    if (b != 0) {
        e = entry_of(b, idx);
        if (e != 0)
            return (u8 *)b + ((Ent *)e)->rel00;
    }
    return 0;
}

void NNSi_G3dGetNodeScaleFromMdl(void *arg)
{
    Root *r = gCurrentRS;
    Hdr *h = r->h;
    u8 *p;
    u32 f;

    p = resolve(r->bank, h->idx01);
    f = ((u16 *)p)[0];
    p = p + 4;
    if ((f & 1) == 0) p += 0xc;
    if ((f & 2) == 0) { if ((f & 8) != 0) p += 4; else p += 0x10; }
    r->hook(arg, p, h, f);
}
