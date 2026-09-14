/*
 * function: sub_0202C3E0
 * address:  0x0202C3E0
 * packet:   pkt_0202C244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FSi_ConvertStringSjisToUnicode  0x02048F74  arm
 *   sub_0202C510                    0x0202C510  thumb
 *   sub_0202C550                    0x0202C550  thumb
 *
 * The last big blocker of src/pending/unit_0202C318.c. Every concrete byte
 * matches: five FSi_ConvertStringSjisToUnicode calls unpack a header field of
 * `a` (4 code units), nine digits into a local array and a separator into a
 * local scalar (all at increasing offsets into `b`), then a count byte at
 * a->unk16 and a value array at a->unk04 sized off that just-written count.
 * A second loop then calls sub_0202C510(a, i) to fetch a pointer out of the
 * object's own array (declared opaquely here; its own file owns the struct)
 * and hands it to sub_0202C550 along with the separator and the matching
 * digit.
 *
 * sub_0202C510 resolves via the `matched` class (src/matched/unit_0202C510.c,
 * EXACT). sub_0202C550 does not: it is one of the nine pool-word-and-bx
 * trampolines; closed when sub_0202C550 was split into its own EXACT file, so a
 * manifest entry covers the address 0x0202C550 even though its own target
 * (func_0202C5C4, EXACT) does. The relocation stays unresolved under the
 * honesty rule until unit_0202C548.c's own sub_0202C550 is split into its
 * own EXACT entry the way sub_0202C4D8.c and sub_0202C510.c were split out
 * of their siblings, or the image acquires a second, non-trampoline caller.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C3E0.c \
 *       --func sub_0202C3E0 --addr 0x0202C3E0 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 FSi_ConvertStringSjisToUnicode(void *dst, u32 term, void *src,
                                           u32 srcOffset, u32 dstSize);
extern u32 sub_0202C510(void *p, u32 idx);
extern u32 sub_0202C550(void *p, u32 a, u32 b);

struct Obj0202C3E0 {
    u8 pad04[4];
    u16 unk04[9];
    u8 unk16;
};

u32 sub_0202C3E0(struct Obj0202C3E0 *a, void *b)
{
    u16 digits[9];
    u16 sep;
    int i;
    u32 off;
    u32 ret;

    i = 0;
    off = 0;
    FSi_ConvertStringSjisToUnicode(a, 0x93, b, off, 4);
    off += 4;

    for (; i < 9; i++, off += 2) {
        FSi_ConvertStringSjisToUnicode(&digits[i], 0x93, b, off, 2);
    }

    FSi_ConvertStringSjisToUnicode(&sep, 0x93, b, off, 2);
    FSi_ConvertStringSjisToUnicode(&a->unk16, 0x93, b, off + 2, 1);
    FSi_ConvertStringSjisToUnicode(a->unk04, 0x93, b, off + 3, a->unk16 * 2);

    i = 0;
    for (; i < 9; i++) {
        ret = sub_0202C550((void *)sub_0202C510(a, i), sep, digits[i]);
    }

    return ret;
}
