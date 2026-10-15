/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200AB04
 * packet:   pkt_0200A940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: IRC_RANKING_ClearNewFlags, IRC_RANKING_GetSize
 *
 * Two unlabelled leaves at the end of the packet, after func_0200AA68:
 * `push {r4, r5}` with no lr for the first, nothing at all for the second,
 * so both print as `.word` (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The first clears bit 7 of the byte at +0x1b of each of the same 0x1e
 * records of 0x1c bytes the two helpers at 0x0200A9A4 index (that byte's
 * bit 7 is the flag IRC_RANKING_IsEntryNew returns); the second is a four-byte
 * constant getter for 0x34c, which Thumb spells `movs r0, #0xd3; lsls
 * r0, r0, #2`.
 */

typedef unsigned char u8;

struct Bits0200AB04 {
    u8    lo : 7;
    u8    flag : 1;
};

struct Rec0200AB04 {
    u8 pad00[0x1b];
    struct Bits0200AB04 bits;
};

void IRC_RANKING_ClearNewFlags(struct Rec0200AB04 *o)
{
    int i;

    for (i = 0; i < 0x1e; i++)
        o[i].bits.flag = 0;
}

int IRC_RANKING_GetSize(void)
{
    return 0x34c;
}
