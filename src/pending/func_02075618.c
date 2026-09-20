/*
 * function: func_02075618
 * address:  0x02075618
 * packet:   pkt_02075618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
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
 * Blocked at MATCH on the `matched` class: func_02075794 (the PC24 at +0x0074)
 * has no branch outside 02075618..02075698, so the site stays wildcarded.  The
 * callee is pkt_02075794's 196-byte lead function, which this lane attempted and
 * left DIFF (200 vs 196 bytes, register allocation at the prologue - see
 * docs/notes/func_02075794.c.txt), so it cannot be filed and cannot attest this
 * call.  The other three sites resolve (func_02074388, func_0207466C and
 * func_02075B54) and every concrete byte here reproduces: compiled 128 bytes,
 * original 128 bytes.
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

extern void *func_02074388(u32 a);
extern u32   func_0207466C(u32 a);
extern void *func_02075B54(u32 a, u32 b);
extern u32   func_02075794(u32 a0, u32 a1, u32 a2, u32 a3, void *s0, u32 s1,
                           u32 s2, u32 s3);

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

    st = (u8 *)func_02075B54(q, c);
    if (st == 0) {
        return 0;
    }

    return func_02075794(a, st[9], *(u16 *)(st + 4), st[8], st, q, b, c);
}
