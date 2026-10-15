/*
 * function: BILLBOARD_SetField10
 * address:  0x0204ED70
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Copy the caller's 12-byte record into the actor at +0x10.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204ED70 and its body ends at 0x0204ED80.
 *
 * symbols:
 *   none (no external calls, no data references)
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Blk3 {
    u32 w[3];
};

void BILLBOARD_SetField10(u8 *dst, struct Blk3 *src)
{
    *(struct Blk3 *)(dst + 0x10) = *src;
}
