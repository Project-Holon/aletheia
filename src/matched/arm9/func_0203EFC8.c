/*
 * unit:     no
 * function: GF_STANDARD_CompareBytes
 * address:  0x0203EFC8
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * memcmp over unsigned bytes.  The count is tested and decremented in one
 * expression (`n-- != 0`), which is what puts the `sub r2, r2, #1` between
 * the `cmp` and the branch at the head and again in the loop's tail.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_CompareBytes.c \
 *       --func GF_STANDARD_CompareBytes --addr 0x0203EFC8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n)
{
    while (n-- != 0) {
        if (*a != *b) {
            return *a - *b;
        }
        a++;
        b++;
    }
    return 0;
}
