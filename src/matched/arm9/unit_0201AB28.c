/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201AB28
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201AB28, sub_0201AB34
 *
 * sub_0201AB28 is the index calculator this whole neighbourhood shares: an
 * entry of an array of 0xDC-byte records starting eight bytes into the
 * object.  sub_0201AB34 looks the entry up and, if it is non-null (in
 * practice it always is; the check reads as a defensive null guard rather
 * than a reachable branch), tail-hands it to sub_0201AD18 (0x0201AC2C..,
 * still open at the time of writing but pinned as an extern here since a
 * `label` witness for it exists outside this range).
 *
 * Immediately in front of sub_0201AB28, at 0x0201AB08..0x0201AB28, are two
 * back to back linker long-branch veneers (`ldr r1,[pc,#4]; ldr r3,[pc,#8];
 * bx r3` plus two pool words each) that this file does not claim; see
 * docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md
 * for the general shape, though here both are Thumb-encoded stubs rather
 * than the ARM long-branch form.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AB28.c \
 *       --addr 0x0201AB28 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

void *sub_0201AB28(void *p, u32 idx)
{
    return (u8 *)p + 8 + idx * 0xDC;
}

extern u32 sub_0201AD18(void *p);

u32 sub_0201AB34(void *p, u32 idx)
{
    void *entry = sub_0201AB28(p, idx);

    if (entry != 0) {
        return sub_0201AD18(entry);
    }
    return 0;
}
