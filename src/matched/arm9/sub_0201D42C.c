/*
 * function: sub_0201D42C
 * address:  0x0201D42C
 * packet:   pkt_0201CEE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02045A90  0x02045A90  arm
 *   sub_0201DC80  0x0201DC80  thumb
 *
 * printsys.c: the pixel height of a string object, i.e. its line count times
 * the font's line height (sub_0201DC80).  The line counter is a u16, so the
 * increment carries the halfword truncation pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D42C.c
 *       --func sub_0201D42C --addr 0x0201D42C --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct StrObj {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 slots[1];
};

struct U16Vec;
extern u16 *sub_02045A90(struct U16Vec *vec);
struct Font;
extern u32 sub_0201DC80(struct Font *p);

u32 sub_0201D42C(struct StrObj *s, void *font)
{
    u16 *p;
    u16 c;
    u16 n;

    p = sub_02045A90((struct U16Vec *)s);
    c = *p;
    n = 0;
    while (c != 0xFFFF) {
        if (c == 0xFFFE) {
            n++;
        }
        if (c == 0xF000) {
            if (c == 0xF000) {
                p = p + 3 + p[2];
            }
        } else {
            p++;
        }
        c = *p;
    }
    return (n + 1) * sub_0201DC80(font);
}
