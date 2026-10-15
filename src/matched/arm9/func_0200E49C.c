/*
 * function: MISC_SAVEDATA_IsTallyFull
 * address:  0x0200E49C
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Returns 1 when MISC_SAVEDATA_GetTallyValue's result is 0x63 or more, else 0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MISC_SAVEDATA_IsTallyFull.c \
 *       --func MISC_SAVEDATA_IsTallyFull --addr 0x0200E49C --thumb --cc 1.1p1
 *
 * symbols:
 *   MISC_SAVEDATA_GetTallyValue  0x0200E4B0  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 MISC_SAVEDATA_GetTallyValue(u8 *p, u32 a, u32 count);

u32 MISC_SAVEDATA_IsTallyFull(u8 *p, u32 a, u32 count)
{
    return MISC_SAVEDATA_GetTallyValue(p, a, count) >= 0x63 ? 1 : 0;
}
