/*
 * function: sub_020342F8
 * address:  0x020342F8
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
 * areaman.c.  The forward bit-run scanner inside one byte of the bitmap:
 * given the byte, a starting bit and a run length, walk the run mask down
 * from `start` and return the first bit position at which `len` consecutive
 * bits are all clear, or -1.
 *
 * 0x020A048C is a nine byte table, 00 80 C0 E0 F0 F8 FC FE FF, i.e. the
 * mask of the top `len` bits of a byte; the entry for len == 8 is the last,
 * which is why the length guard is `> 8` here and `>= 8` in the backward
 * scanner at 0x02034348 (that one indexes the same table after adding one).
 * The address has three pool words in the image (0x02034344, 0x02034390 and
 * 0x020343BC), so compiling this function alone leaves two of them outside
 * the compared range and the `literal` class closes the site.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020342F8.c \
 *       --func sub_020342F8 --addr 0x020342F8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

extern const u8 Areaman_RunMask[];

s32 sub_020342F8(u32 bits, u32 start, u32 len)
{
    u8 mask;
    u32 last;

    if (len <= 8) {
        last = 8 - len;
        mask = Areaman_RunMask[len] >> start;

        while (start <= last) {
            if ((bits & mask) == 0) {
                return start;
            }
            mask >>= 1;
            start++;
        }
    }

    return -1;
}
