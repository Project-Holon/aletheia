/*
 * function: sub_0201D2C8
 * address:  0x0201D2C8
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
 *
 * printsys.c: counts the lines of a string object, i.e. one plus the number
 * of 0xFFFE line-break codes before the 0xFFFF terminator.  0xF000 opens an
 * embedded block whose halfword length sits at +4, so the walker steps over
 * three header halfwords plus that many payload halfwords.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D2C8.c
 *       --func sub_0201D2C8 --addr 0x0201D2C8 --cc 1.1p1 --thumb
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

u32 sub_0201D2C8(struct StrObj *s)
{
    u16 *p;
    u32 n;
    u16 c;

    p = sub_02045A90((struct U16Vec *)s);
    c = *p;
    n = 1;
    while (c != 0xFFFF) {
        if (c != 0xF000) {
            if (c == 0xFFFE) {
                n++;
            }
            p++;
        } else {
            if (c == 0xF000) {
                p = p + 3 + p[2];
            }
        }
        c = *p;
    }
    return n;
}
