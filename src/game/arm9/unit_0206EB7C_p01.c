/*
 * file:     unit_0206EB7C_p01.c
 * unit:     yes
 * function: func_0206EB7C, func_0206EBB8, func_0206EC50
 * address:  0x0206EB7C
 * region:   arm9
 * compiler: dsi/../2.0/sp2p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0206EE60    0x0206EE60  arm
 *   g_02148DB0      0x02148DB0  data
 */
#include "../../matched/include/Obj16622.h"
#include "../../matched/include/Obj16624.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int s32;

typedef struct { u32 unk00; u32 unk04; u32 *p08; } Cur;

typedef unsigned char u8;

typedef struct { u8 unk00; u8 idx01; } Hdr;

typedef struct { u8 unk00; u8 cnt01; u8 unk02[4]; u16 off06; } Bank;

typedef struct Root { Hdr *h; u8 pad[0xD0]; Bank *bank; u8 pad2[0x10];
                 void (*hook)(void *, void *, Hdr *, u32); } Root;

typedef struct { u16 flags; u32 f04; u32 f08; u32 f0C; } Node;

typedef struct { u32 rel00; } Ent;

extern void func_0206EE60(u32 *tab, u32 b, s32 c, void *a);
void func_0206EB7C(void *a, Cur *c, u32 b);
void func_0206EBB8(u32 *out);
void func_0206EC50(void *arg);
extern Root *g_02148DB0;


/*
 *           branch anywhere in the image to 0x0206EE60 is this one, so
 *           `label` refuses it and nothing else attests it. Filing 0x0206EE60
 *           (940 B, still OPEN in this packet) as EXACT promotes this file to
 *           EXACT with no change to the C. --suggest-split offers nothing:
 *           single function, the one site's only witness is inside the range.
 *
 * Clamps a 20.12 fixed-point cursor into [0, (count<<12)-1] and forwards.
 *
 * Shape note that cost the previous two passes: the callee takes FOUR
 * arguments and the caller's own first argument is the FOURTH, not the first
 * (the image's `mov r3, r0` at 0x0206EB80 is that argument being parked in
 * r3 before r0 is reloaded with the table pointer). Written as a three-
 * argument forward of r0 the compiler lands at 56 bytes against 60.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206EB7C.c \
 *       --func func_0206EB7C --addr 0x0206EB7C --cc 1.1p1 --arm
 */
void func_0206EB7C(void *a, Cur *c, u32 b)
{
    s32 t;
    s32 lim;
    u32 *tab;

    tab = c->p08;
    lim = (s32)((u32)((u16 *)tab)[2] << 12);
    t = (s32)c->unk00;
    if (t >= lim) {
        t = lim - 1;
    } else if (t < 0) {
        t = 0;
    }
    func_0206EE60(tab, b, t, a);
}



/*
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md).
 * The image keeps `tst r1, #1` at 0x0206EC18 and `beq 0x0206EC30` at
 * 0x0206EC1C over the four-instruction guard body at 0x0206EC20..0x0206EC2C
 * (`ldr r1,[r0]` / `orr r1,r1,#4` / `str r1,[r0]` / `bx lr`); dsi/1.1p1
 * -O4,p predicates it to ldrne/orrne/strne/bxne, giving 148 bytes against
 * the original's 152. Under ../2.0/sp2 the same C is 152 bytes, 0 mismatches.
 *
 * Same inlined two-step resolve as src/matched/unit_0206E394.c, but over the
 * global stash at 0x02148DB0: root -> bank (+0xD4), bank -> entry (indexed
 * table at bank+6), entry -> node (relative offset at entry+0).
 */
void func_0206EBB8(u32 *out)
{
    Root *r = g_02148DB0;
    Bank *b;
    Node *n;
    u8 *t;
    u32 idx;

    idx = r->h->idx01;
    b = r->bank;
    if (b == 0) goto none;
    if (b == 0) goto nullent;
    if (idx >= b->cnt01) goto nullent;
    t = (u8 *)b + b->off06;
    idx = (u32)(t + 4 + (((struct Obj16622 *)t)->f0) * idx);
    goto have;
nullent:
    idx = 0;
have:
    if (idx == 0) goto none;
    n = (Node *)((u8 *)b + ((Ent *)idx)->rel00);
    goto set;
none:
    n = 0;
set:
    if ((n->flags & 1) != 0) {
        out[0] |= 4;
        return;
    }
    out[0x13] = n->f04;
    out[0x14] = n->f08;
    out[0x15] = n->f0C;
}



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



/*
 * Resolves the current node through the global stash at 0x02148DB0 (root ->
 * bank at +0xD4, bank -> entry through the halfword-indexed table at
 * bank+6, entry -> node by the relative offset at entry+0), skips the node's
 * optional header blocks by its flag bits, and hands the payload to the
 * root's hook at +0xE8.  func_0206EE60 calls it for the third flag group.
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
 *     hook, with root->h as its third argument, is what func_0206EE60 calls
 *     at its emit tail.  A three-argument call is 21 bytes out.
 *
 * Front end: filed under the packet's ../2.0/sp2 unit pin.  With the inline
 * helpers this function is compiler-neutral (EXACT under dsi/1.1p1 as well,
 * measured 2026-09-22): the "kept branches" double `beq` the earlier note
 * attributed to the front end is what the nested inline produces under both.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206EC50.c \
 *       --func func_0206EC50 --addr 0x0206EC50 --cc ../2.0/sp2 --arm
 */
void func_0206EC50(void *arg)
{
    Root *r = g_02148DB0;
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
