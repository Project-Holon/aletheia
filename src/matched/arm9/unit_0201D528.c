/*
 * unit:     yes
 * address:  0x0201D528
 * packet:   pkt_0201CEE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0201D528
 *
 * Measures a message string up to the 0xBD06 tag whose parameter is the
 * caller's value, in the font c, adding d of spacing per character.  0xFFFE
 * resets the running width, a 0xBD04 tag adds its parameter, and anything that
 * is not a tag is measured with GF_FONT_GetCharWidth.
 *
 * The halfword under the cursor has to be a named local.  Written as `p[0]` at
 * each of its five uses the compiler caches it in r1, which is the second
 * argument register, and the call to GF_FONT_GetCharWidth then needs no move; the
 * original caches it in r2 and spends `adds r1, r2, #0`, which is two bytes and
 * is the only difference between the two spellings.  That is the argument form
 * of docs/idioms/cmp-operand-order-names-the-temporary.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D528.c \
 *       --addr 0x0201D528 --thumb
 *
 * symbols:
 *   GF_FONT_GetCharWidth  0x0201DC6C  thumb
 *   STRBUF_GetChars  0x02045A90  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Font;
struct U16Vec;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u32 GF_FONT_GetCharWidth(struct Font *p, u16 ch);

u32 func_0201D528(void *s, u8 b, void *c, u32 d)
{
    u32 acc = 0;
    u16 *p;
    u32 t;
    u16 ch;

    p = STRBUF_GetChars(s);
    while (p[0] != 0xFFFF) {
        ch = p[0];
        if (p[0] == 0xFFFE) {
            acc = 0;
            p = p + 1;
        } else if (p[0] != 0xF000) {
            acc = acc + (d + GF_FONT_GetCharWidth(c, ch));
            p = p + 1;
        } else {
            if (p[1] == 0xBD06) {
                if (p[0] == 0xF000) {
                    t = p[3];
                } else {
                    t = 0;
                }
                if (b == t) {
                    return (u8)acc;
                }
            }
            if (p[1] == 0xBD04) {
                if (p[0] == 0xF000) {
                    t = p[3];
                } else {
                    t = 0;
                }
                acc = acc + t;
            }
            if (p[0] == 0xF000) {
                p = p + 3 + p[2];
            }
        }
    }
    return 0;
}
