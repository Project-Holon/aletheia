/*
 * function: FILE_UTIL_GetBankCount
 * address:  0x02020F0C
 * packet:   pkt_02020E60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker FILE_UTIL_GetBankCount.c is now a manifest entry (matched class)
 *
 * Constant answer: 1.
 *
 * symbols:
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/FILE_UTIL_GetBankCount.c \
 *       --func FILE_UTIL_GetBankCount --addr 0x02020F0C --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

int FILE_UTIL_GetBankCount()
{
    return 1;
}
