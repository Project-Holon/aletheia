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
 * is not a tag is measured with func_0201DC6C.
 *
 * The halfword under the cursor has to be a named local.  Written as `p[0]` at
 * each of its five uses the compiler caches it in r1, which is the second
 * argument register, and the call to func_0201DC6C then needs no move; the
 * original caches it in r2 and spends `adds r1, r2, #0`, which is two bytes and
 * is the only difference between the two spellings.  That is the argument form
 * of docs/idioms/cmp-operand-order-names-the-temporary.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D528.c \
 *       --addr 0x0201D528 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_02045A90(void *s);
extern u32  func_0201DC6C(void *p, u16 ch);

u32 func_0201D528(void *s, u32 b, void *c, u32 d)
{
    u32 acc = 0;
    u16 *p;
    u32 t;
    u16 ch;

    p = func_02045A90(s);
    while (p[0] != 0xFFFF) {
        ch = p[0];
        if (p[0] == 0xFFFE) {
            acc = 0;
            p = p + 1;
        } else if (p[0] != 0xF000) {
            acc = acc + (d + func_0201DC6C(c, ch));
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
