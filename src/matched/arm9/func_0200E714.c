/*
 * function: GREETING_SAVEDATA_SetSentence
 * address:  0x0200E714
 * packet:   pkt_0200E714
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf that follows MISC_SAVEDATA_CopyQuadRecord: copy one 8-byte record to dst[idx].
 *
 * symbols:
 *   (none - no relocations)
 */

typedef unsigned short u16;

struct Rec0200E714 {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
};

void GREETING_SAVEDATA_SetSentence(struct Rec0200E714 *dst, int idx, struct Rec0200E714 *src)
{
    dst[idx] = *src;
}
