/*
 * function: func_0204B7F0
 * address:  0x0204B7F0
 * packet:   pkt_0204B764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * u16 field read at +0x5c.  Unlabelled in the current listings: the prologue
 * saves nothing, so disasm.py never auto-labelled it (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  It sits
 * between the literal pool of func_0204B7C8 and func_0204B800.
 *
 * symbols:
 *   none (no external calls, no data references)
 */

typedef unsigned char  u8;
typedef unsigned short u16;

u16 func_0204B7F0(u8 *p)
{
    return *(u16 *)(p + 0x5c);
}
