/*
 * function: func_0203A27C
 * address:  0x0203A27C
 * packet:   pkt_0203A27C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203A338  0x0203A338  arm
 *
 * A message-table handler that forwards to func_0203A338 with the message's
 * first byte as its only argument.  The five-argument table shape puts the
 * message pointer in r2, so the whole body is `ldrb r0,[r2]` followed by the
 * tail call, which one section per function forces to be a pool word and a
 * `bx ip` rather than a displacement branch
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The remaining
 * parameters are leftovers and are not passed
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A27C.c \
 *       --func func_0203A27C --addr 0x0203A27C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0203A338(u32 a0);

void func_0203A27C(u32 a0, u32 a1, u8 *msg, u32 a3, u32 a4)
{
    func_0203A338(*msg);
}
