/*
 * function: func_0203192C
 * address:  0x0203192C
 * packet:   pkt_020315F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203174C  0x0203174C  arm
 *
 * backup_system.c.  A one-line forwarder: its two arguments go straight
 * through to 0x0203174C together with three zero/one flags, the fifth landing
 * on the stack.  The two zero arguments cost a single `mov r2, #0` plus the
 * `mov r3, r2` copy the compiler makes instead of a second move, and the `1`
 * is materialised into `ip` because an ARM `str` has no immediate form.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203192C.c \
 *       --func func_0203192C --addr 0x0203192C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 func_0203174C(void *a, void *b, u32 c, u32 d, u32 e);

u32 func_0203192C(void *a, void *b)
{
    return func_0203174C(a, b, 0, 0, 1);
}
