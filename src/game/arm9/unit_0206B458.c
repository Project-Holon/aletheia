/*
 * file:     unit_0206B458.c
 * unit:     yes
 * function: func_0206B458, func_0206B4A0, func_0206B63C, func_0206B6A4
 * address:  0x0206B458
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_020A83B8  0x020A83B8  data
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   g_020A829C        0x020A829C  data
 *   g_020A8290        0x020A8290  data
 *   g_020A82A8        0x020A82A8  data
 *   g_02148DB0      0x02148DB0  data
 *   func_02082A7C   0x02082A7C  arm
 */
#include "../../matched/include/Obj07047.h"
#include "../../matched/include/Obj16563.h"
#include "../../matched/include/Obj16564.h"
#include "../../matched/include/Obj16565.h"

typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct Obj0206B4A0 Obj0206B4A0;

typedef void (*Cb0206B458)(Obj0206B4A0 *ctx, u32 arg);

typedef struct Cfg0206B4A0 Cfg0206B4A0;

struct Cfg0206B4A0 {
    u32   f00;
    u8   *f04;
    u8    pad08[0x20 - 0x08];
    u32   f20;
    u8    f24;
    u8    f25;
    u8    pad26[0x28 - 0x26];
    void (*f28)(Obj0206B4A0 *);
    u8    pad2c[0x30 - 0x2c];
    u8   *f30;
};

struct Obj0206B4A0 {
    u8   *f00;
    Cfg0206B4A0 *volatile f04;
    u32   f08;
    u32   f0c[0x20];
    u8    f8c[0x20];
    u8    padac[0xc4 - 0xac];
    u32   fc4;
    u8    padc8[0xd4 - 0xc8];
    u8   *fd4;
    u8   *fd8;
    u8   *fdc;
    u32   fe0;
    u32   fe4;
    u32   fe8;
    u32   fec;
    u32   ff0;
};

typedef unsigned short u16;

typedef struct Node0206B63C Node0206B63C;

struct Node0206B63C {
    u8  pad00[0x10];
    Node0206B63C *f10;
    u8  pad14[0x19 - 0x14];
    u8  f19;
    u16 f1a[1];
};

struct Obj0206B6A4 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
};

extern void MIi_CpuClearFast(u32 val, void *dst, u32 len);
extern void func_02082A7C(u32 val, void *dst, u32 len);
void func_0206B458(Obj0206B4A0 *ctx);
void func_0206B4A0(Obj0206B4A0 *o, Cfg0206B4A0 *cfg);
void func_0206B63C(u32 *bitmap, Node0206B63C *n);
extern Cb0206B458 g_020A83B8[];
extern u32 g_020A829C[];
extern u32 g_020A8290[];
extern u32 g_020A82A8[];
extern u32 g_02148DB0;



/*
 * The object driver loop of the 0x0206B7D0 script family: clear bit 6 of the
 * flag word at +0x08, read the opcode byte through the program pointer at
 * +0x00, dispatch its low five bits through the handler table at 0x020A83B8
 * with the top three bits as the second argument, and repeat until bit 5 of
 * the flag word is set.  2.0/sp2 pin: under dsi/1.1p1 the same source is 72
 * bytes with 9 concrete bytes out (the state pointer takes r0 and the object
 * argument is deferred); see docs/notes/func_0206B458.c.txt.
 */
void func_0206B458(Obj0206B4A0 *ctx)
{
    u32 cmd;

    do {
        ctx->f08 &= ~0x40u;
        cmd = *ctx->f00;
        g_020A83B8[cmd & 0x1f](ctx, cmd & 0xe0u);
    } while ((ctx->f08 & 0x20u) == 0);
}




/*
 * The object constructor of the 0x0206B458 script-object family: zero the
 * whole 0x188-byte object, set the +0xc4 and +0x08 words to 1, take the
 * program pointer from the config's +0x30 override or, absent one, from the
 * script blob's own +0x04 offset, then unpack the blob into the object --
 * three offset-or-null section pointers at +0xd4/+0xd8/+0xdc, three table
 * picks keyed by the blob's +0x15/+0x16 bytes, two words copied from +0x1c
 * and +0x20, an optional (index, byte) pair into the +0x0c/+0x8c arrays,
 * four flag bits mirrored out of the config's +0x00 word, an optional
 * caller hook, and finally the driver loop func_0206B458.
 *
 * Two spellings are load-bearing, both recorded as walls in
 * docs/notes/pkt_0206AFE4.c.txt:
 *   - `volatile` on the +0x04 config pointer.  Without it mwcc fuses the
 *     +0x00 and +0x04 stores into `stm r5, {r0, r4}` and the function comes
 *     out four bytes short; the qualifier restores the original's two
 *     separate `str`s and changes nothing else.  Same lever family as
 *     src/matched/func_0206AF74.c's `volatile s32 *dst`.
 *   - the local `q = cfg->f04;` in front of the +0xd8/+0xdc pointer
 *     assembly.  Spelled through `cfg->f04` directly, the `&&` materialises
 *     a boolean (`movne r1,#1 / cmp r1,#0`) and re-loads the offset, 28
 *     bytes of excess; through the local it is the original's predicated
 *     `cmp / ldrne / cmpne / addne / moveq` chain.  Found by
 *     tools/permuter.py (hill, 800/8, --types), which named
 *     `temp(tmp=(u32 *)(cfg->f04 + 0xc))` and took 440 bytes to 424.
 */
void func_0206B4A0(Obj0206B4A0 *o, Cfg0206B4A0 *cfg)
{
    u8 *q;

    MIi_CpuClearFast(0, o, 0x188);
    o->fc4 = 1;
    o->f08 = 1;
    o->f00 = cfg->f30 != 0 ? cfg->f30 : cfg->f04 + ((struct Obj16563 *)(cfg->f04))->f4;
    o->f04 = cfg;
    o->fd4 = cfg->f04 != 0 ? cfg->f04 + 0x40 : 0;
    q = cfg->f04;
    o->fd8 = q != 0 && ((struct Obj07047 *)q)->f8 != 0 ? q + ((struct Obj07047 *)q)->f8 : 0;
    q = cfg->f04;
    o->fdc = q != 0 && ((struct Obj07047 *)q)->fC != 0 ? q + ((struct Obj07047 *)q)->fC : 0;
    o->fe8 = g_020A829C[cfg->f04[0x15]];
    o->fec = g_020A8290[cfg->f04[0x15]];
    o->ff0 = g_020A82A8[cfg->f04[0x16]];
    o->fe0 = ((struct Obj16564 *)(cfg->f04))->f1C;
    o->fe4 = ((struct Obj16565 *)(cfg->f04))->f20;
    if (cfg->f20 != 0 && cfg->f24 < 0x20) {
        o->f0c[cfg->f24] = cfg->f20;
        o->f8c[cfg->f24] = cfg->f25;
    }
    if (cfg->f00 & 1)   o->f08 |= 0x80;
    if (cfg->f00 & 2)   o->f08 |= 0x100;
    if (cfg->f00 & 4)   o->f08 |= 0x200;
    if (cfg->f00 & 8)   o->f08 |= 0x400;
    if (cfg->f28 != 0) cfg->f28(o);
    func_0206B458(o);
    cfg->f00 &= ~1u;
}




/*
 * Walks the same node list as src/matched/func_0206AF08.c (count byte at
 * +0x19, u16 entry array at +0x1a, next at +0x10) and sets, in the caller's
 * bitmap, one bit per entry whose 0x100 flag is up.  `f19` is a u8 read into
 * an `int i` loop, which is what makes the bound tests the original's signed
 * `ble`/`blt`.
 *
 * 2.0/sp2 pin (docs/notes/pkt_0206AF08.c.txt): dsi/1.1p1 and 1.2 both
 * if-convert the flagged-bit store into asrne/ldrne/orrne/strne and land at
 * 100 bytes against the original's 104.  Callee of
 * src/matched/func_0206B6A4.c.
 */
void func_0206B63C(u32 *bitmap, Node0206B63C *n)
{
    int i;

    while (n != 0) {
        for (i = 0; i < n->f19; i++) {
            if (n->f1a[i] & 0x100) {
                bitmap[i >> 5] |= 1 << (i & 0x1f);
            }
        }
        n = n->f10;
    }
}


/*
 *           --suggest-split offers nothing (single function, all five
 *           unresolved sites' only witnesses are inside this range).
 *
 * Promote-first callee of src/pending/G3D_SYSTEM_DrawRenderObj.c (parks lane 2).
 * Release the object's three eight-byte sub-blocks when the +0x10 flag is
 * up, then run the one-at-a-time teardown through the stash pointer at
 * 0x02148DB0, recording this frame's own work area in it while the call is
 * in flight.
 *
 * Blocked at MATCH with all 220 concrete bytes right: five unresolved sites,
 * three calls to 0x0206B63C and two to 0x0206B4A0, each of which has no
 * witness outside 0x0206B6A4..0x0206B780 - the only branches in the image to
 * either address are these calls.  Filing 0x0206B63C (104 B) and 0x0206B4A0
 * (400 B) as EXACT entries promotes this file and then
 * src/pending/G3D_SYSTEM_DrawRenderObj.c with no change to the C.  (0x0206B63C's own
 * `cmp r1, #0 / popeq` prologue confirms the two-argument call below.)
 *
 * Shape notes, each measured:
 *   - the 2.0 front end: dsi/1.1p1 gives 224 bytes and 1.2 228 for the same
 *     C; 2.0/sp2 gives the original's 220;
 *   - `if (g != 0) {...} else {...}` in that order (the original's `beq`
 *     jumps into the stash arm, and the fall-through arm is the source order);
 *   - the three cleanup calls take TWO arguments, `(block, p->f08)`: the
 *     guard's loaded value is still sitting in r1 at the call and the
 *     original never reloads it.  Passing one argument costs six bytes here
 *     (`ldr r0,[r4,#8] / cmp r0,#0` against the original's r1).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206B6A4.c \
 *       --func func_0206B6A4 --addr 0x0206B6A4 --cc ../2.0/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 *
 * 2026-09 lane5: 0x0206B63C is now an EXACT manifest entry (src/matched/func_0206B63C.c,
 * packet pkt_0206AFE4, --cc ../2.0/sp2), so the three calls to it resolve as
 * `matched` and this file is down to two unresolved sites, both the
 * `bl func_0206B4A0` at +0x00a8/+0x00c0.  0x0206B4A0 is still unfiled:
 * src/matched/func_0206B458.c (72 B) is filed, but 0x0206B4A0 itself is a
 * DIFF near miss (4 bytes short; residue in docs/notes/pkt_0206AFE4.c.txt).
 */
void func_0206B6A4(struct Obj0206B6A4 *p)
{
    u8 work[0x188];

    if ((p->f00 & 0x10) == 0x10) {
        func_02082A7C(0, (char *)p + 0x3c, 8);
        func_02082A7C(0, (char *)p + 0x44, 8);
        func_02082A7C(0, (char *)p + 0x4c, 8);
        if (p->f08 != 0)
            func_0206B63C((u32 *)((char *)p + 0x3c), (Node0206B63C *)p->f08);
        if (p->f10 != 0)
            func_0206B63C((u32 *)((char *)p + 0x44), (Node0206B63C *)p->f10);
        if (p->f18 != 0)
            func_0206B63C((u32 *)((char *)p + 0x4c), (Node0206B63C *)p->f18);
        p->f00 &= ~0x10;
    }
    if (g_02148DB0 != 0) {
        func_0206B4A0((Obj0206B4A0 *)g_02148DB0, (Cfg0206B4A0 *)p);
    } else {
        g_02148DB0 = (u32)work;
        func_0206B4A0((Obj0206B4A0 *)work, (Cfg0206B4A0 *)p);
        g_02148DB0 = 0;
    }
}
