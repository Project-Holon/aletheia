/*
 * function: sub_02034348
 * address:  0x02034348
 * packet:   pkt_02033CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   Areaman_RunMask  0x020A048C  data
 *
 * areaman.c.  The backward twin of sub_020342F8: same run-mask table, but
 * the cursor walks down from `start` instead of up, so the mask is shifted
 * left each step and the loop ends when the signed cursor goes negative.
 * The cursor really is signed here, which is the only reason the original
 * can reuse the flags of the `subs` that computes it for both the entry
 * guard (`bmi`) and the loop back edge (`bpl`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034348.c \
 *       --func sub_02034348 --addr 0x02034348 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

extern const u8 Areaman_RunMask[];

s32 sub_02034348(u32 bits, u32 start, u32 len)
{
    u8 mask;
    s32 i;

    if (len < 8) {
        i = (s32)(start + 1) - (s32)len;
        mask = Areaman_RunMask[len] >> i;

        while (i >= 0) {
            if ((bits & mask) == 0) {
                return i;
            }
            mask <<= 1;
            i--;
        }
    }

    return -1;
}
