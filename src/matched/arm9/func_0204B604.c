/*
 * function: CLACT_SetActorFlip
 * address:  0x0204B604
 * packet:   pkt_0204B604
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The setter side of CLACT_GetActorFlip (src/matched/CLACT_GetActorFlip.c): sets or
 * clears bit `which` of the two-bit field f_14 at bits 20..21 of the flag
 * word at +0x60.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorFlip.c \
 *       --func CLACT_SetActorFlip --addr 0x0204B604 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Actor {
    u8  pad_00[0x60];
    u32 f_00 : 8;
    u32 f_08 : 4;
    u32 f_0c : 6;
    u32 f_12 : 2;
    u32 f_14 : 2;
    u32 f_16 : 2;
    u32 f_18 : 8;
};

void CLACT_SetActorFlip(struct Actor *actor, u32 which, u32 set)
{
    u32 mask = (which == 0) ? 1 : 2;

    if (set == 0) {
        actor->f_14 &= ~mask;
        return;
    }

    actor->f_14 |= mask;
}
