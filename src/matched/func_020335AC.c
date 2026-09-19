/*
 * function: func_020335AC
 * address:  0x020335AC
 * packet:   pkt_02033534
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The retry loop is a `while (call(...) == 0) ;` with an uninitialised `v`:
 * zeroing `v` first costs a `mov r4, #0` + `str r4, [sp]` the original does
 * not have, and 8 bytes of frame.  The second call site resolves on the
 * `literal` class (the word 0x020337B8 appears in the callee's own pool).
 *
 * symbols:
 *   func_020336B8  0x020336B8  arm
 *   func_020337B8  0x020337B8  arm
 */

typedef unsigned int u32;

extern u32 func_020336B8(u32 a, u32 b, u32 c);
extern u32 func_020337B8(u32 a, u32 *b, u32 c);

u32 func_020335AC(u32 a, u32 b, u32 c, u32 d)
{
    u32 v;
    u32 h = func_020336B8(a, b, c);

    while (func_020337B8(h, &v, d) == 0) {
        ;
    }
    return v;
}
