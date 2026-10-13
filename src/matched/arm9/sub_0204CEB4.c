/*
 * unit:     no
 * function: CLACT_UpdateActorAutoAnim
 * address:  0x0204CEB4
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_AddActorAnimFrame  0x0204B8D4  arm
 *
 * Run the object through CLACT_AddActorAnimFrame, but only when the flag word at +0x60
 * has its seventh bit set.
 *
 * `lsl #6; lsr #31` with nothing that could be a type conversion is a
 * one-bit unsigned bitfield
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).  The
 * pair names the bit from the top: `lsl #6` says six bits sit above it, so
 * it is bit 25 counting from the least significant end, and this front end
 * allocates bitfields from the least significant end upward, which means
 * twenty-five bits of padding must be declared before it.  Declaring the
 * six-bit pad first instead gives `lsl #25` and is the whole difference
 * between the two spellings.  The guard is `== 1`, not a plain truth test, which
 * is why the comparison survives as an explicit `cmp r1, #1` instead of
 * folding into the shift's flags.
 *
 * CLACT_AddActorAnimFrame takes one argument; the `ldr r1, [r0, #0x54]` that precedes
 * the call is a second, forwarded value this function reads but that callee
 * ignores (src/pending/CLACT_AddActorAnimFrame.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_UpdateActorAutoAnim.c \
 *       --func CLACT_UpdateActorAutoAnim --addr 0x0204CEB4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8   pad_00[0x54];
    u32  unk_54;
    u8   pad_58[8];
    u32  pad_60_lo : 25;
    u32  enabled   : 1;
    u32  pad_60_hi : 6;
};

extern void CLACT_AddActorAnimFrame(struct Obj *o, u32 arg);

void CLACT_UpdateActorAutoAnim(struct Obj *o)
{
    if (o->enabled == 1) {
        CLACT_AddActorAnimFrame(o, o->unk_54);
    }
}
