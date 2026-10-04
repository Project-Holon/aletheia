/*
 * function: func_02075618
 * address:  0x02075618
 * packet:   pkt_02075618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Four-step open path, each step gated on its predecessor's result and each
 * early exit answering 0: resolve the media handle (func_02074388), take the
 * object the handle points at and look up its record (func_0207466C), bind the
 * record to the caller's key (func_02075B54), then hand seven values to
 * func_02075794 - the caller's first argument, three fields of the record
 * (bytes at +9 and +8, the halfword at +4) and four words parked on the stack
 * (the record itself, the looked-up object, and the caller's second and third
 * arguments).
 *
 * UNBLOCKED 2026-09-22 (wave 7, pkt_02075404).  This file was previously capped
 * at MATCH on the `matched` class: func_02075794 (the PC24 at +0x0074) has no
 * branch outside 02075618..02075698, and the callee was left DIFF at 200 vs 196
 * bytes by an earlier lane (docs/notes/func_02075794.c.txt), so it could not be
 * filed and could not attest this call.  That DIFF was a compiler question, not
 * a source one: the same body is byte-exact under `--cc ../2.0/sp2` and is now
 * src/matched/func_02075794.c, so this site resolves as `matched` and all four
 * of this file's relocations resolve.  Compiled 128 bytes, original 128 bytes.
 * This file itself stays on the project default 1.1p1; the cluster is mixed,
 * see docs/families/cluster_02074A34.h.
 *
 * symbols:
 *   func_02074388  0x02074388  arm
 *   func_0207466C  0x0207466C  arm
 *   func_02075B54  0x02075B54  arm
 *   func_02075794  0x02075794  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern void *func_02074388(int index);
extern u32   func_0207466C(u32 a);
struct Entry;
struct Table;
extern struct Entry *func_02075B54(struct Table *t, int idx);
extern u32 func_02075794(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u8 *s1, u32 s2, u32 s3);

u32 func_02075618(u32 a, u32 b, u32 c)
{
    u8 *r;
    u32 q;
    u8 *st;

    r = (u8 *)func_02074388(b);
    if (r == 0) {
        return 0;
    }

    q = func_0207466C(*(u32 *)r);
    if (q == 0) {
        return 0;
    }

    st = (u8 *)func_02075B54((struct Table *)q, c);
    if (st == 0) {
        return 0;
    }

    return func_02075794(a, st[9], *(u16 *)(st + 4), st[8], st, (u8 *)q, b, c);
}
