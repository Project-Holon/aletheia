/*
 * function: func_0204EDBC
 * address:  0x0204EDBC
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte field store into the actor at +0x25 straight from the value
 * parameter: there is no load in the image at all.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDBC and its body ends at 0x0204EDC4.
 *
 * symbols:
 *   none (no external calls, no data references)
 */

typedef unsigned char u8;

void func_0204EDBC(u8 *dst, u8 val)
{
    *(u8 *)(dst + 0x25) = val;
}
