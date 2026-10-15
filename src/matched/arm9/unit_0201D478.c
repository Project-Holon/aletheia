/*
 * unit:     yes
 * address:  0x0201D478
 * packet:   pkt_0201CEE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GF_FONT_CountControlTag
 *
 * Counts the control tags of a message string for which GF_FONT_CheckD5CC returns
 * true.  The walk is the one every routine in this neighbourhood uses: 0xF000
 * opens a tag and GF_FONT_SkipTag steps over it, anything else is one halfword,
 * and 0xFFFF ends the string.
 *
 * The counter and the cursor are interchanged unless the cursor is declared
 * first: the original keeps the cursor in r4 and the counter in r5 while the
 * counter is the one initialised first, which is
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md read in
 * the direction that costs the time.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D478.c \
 *       --addr 0x0201D478 --thumb
 *
 * symbols:
 *   STRBUF_GetChars  0x02045A90  arm
 *   GF_FONT_CheckD5CC  0x0201D5CC  thumb
 *   GF_FONT_SkipTag  0x0201D688  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct U16Vec;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u32  GF_FONT_CheckD5CC(const u16 *p);
extern u16 *GF_FONT_SkipTag(u16 *p);

u32 GF_FONT_CountControlTag(void *s)
{
    u16 *p;
    u16 n = 0;

    p = STRBUF_GetChars(s);

    while (p[0] != 0xFFFF) {
        if (p[0] == 0xF000) {
            if (GF_FONT_CheckD5CC(p) != 0) {
                n = (u16)(n + 1);
            }
            p = GF_FONT_SkipTag(p);
        } else {
            p = p + 1;
        }
    }
    return n;
}
