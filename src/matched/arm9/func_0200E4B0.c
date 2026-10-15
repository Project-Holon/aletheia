/*
 * function: MISC_SAVEDATA_GetTallyValue
 * address:  0x0200E4B0
 * packet:   pkt_0200E4B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MISC_SAVEDATA_GetAnswerMessageOffset  0x0200E488  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 MISC_SAVEDATA_GetAnswerMessageOffset(u32 a1, u32 a2);

u32 MISC_SAVEDATA_GetTallyValue(u8 *a0, u32 a1, u32 a2)
{
    if (a2 == 0)
        return 0;
    return *(a0 + MISC_SAVEDATA_GetAnswerMessageOffset(a1, a2) + 0x3c);
}
