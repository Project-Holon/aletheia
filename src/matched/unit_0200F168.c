/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200F168
 * packet:   pkt_0200F168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0200F168, sub_0200F16C
 *
 * alias: sub_0200F168 is a stub returning 0; sub_0200F16C stamps a
 * three-word header (a type tag, a size, a count) into the caller's struct.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200F168.c \
 *       --addr 0x0200F168 --thumb
 */

typedef unsigned int u32;

struct Sub0200F16CHdr {
    u32 tag;
    u32 size;
    u32 count;
};

u32 sub_0200F168(void)
{
    return 0;
}

void sub_0200F16C(struct Sub0200F16CHdr *hdr)
{
    hdr->tag = 2;
    hdr->size = 4;
    hdr->count = 1;
}
