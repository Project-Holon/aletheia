/*
 * function: CLACT_SetActorAutoAnimSpeed
 * address:  0x0204B954
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A leaf setter for the word at +0x54 of the cell-actor record: two
 * instructions, no frame, no relocation.  It saves no lr, so `disasm.py`
 * would not have labelled it on its own; it is only visible because the
 * worklist walks the packet by address
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorAutoAnimSpeed.c \
 *       --func CLACT_SetActorAutoAnimSpeed --addr 0x0204B954 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Actor {
    u8  pad_00[0x54];
    u32 unk_54;   /* 0x54 */
};

void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v)
{
    a->unk_54 = v;
}
