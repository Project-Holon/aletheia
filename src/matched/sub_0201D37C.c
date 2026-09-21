/*
 * function: sub_0201D37C
 * address:  0x0201D37C
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
 *   sub_0204581C  0x0204581C  arm
 *   sub_02045AFC  0x02045AFC  arm
 *
 * printsys.c: copies line `n` of a string object into a second, freshly
 * cleared string object and returns whether the line existed.  Phase one skips
 * n line breaks, phase two appends the line a halfword at a time and closes it
 * with the 0xFFFF terminator.  Embedded 0xF000 blocks are skipped in phase one
 * and copied verbatim in phase two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D37C.c
 *       --func sub_0201D37C --addr 0x0201D37C --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct StrObj {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 slots[1];
};

extern u16 *sub_02045A90(struct StrObj *s);
extern void sub_0204581C(struct StrObj *s);
extern void sub_02045AFC(struct StrObj *s, u16 c);

u32 sub_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n)
{
    u16 *end;
    u16 *p;
    u16 c;

    p = sub_02045A90(src);
    sub_0204581C(dst);
    while (n != 0) {
        while ((c = *p) != 0xFFFF && c != 0xFFFE) {
            if (c != 0xF000) {
                p++;
            } else {
                if (c == 0xF000) {
                    p = p + 3 + p[2];
                }
            }
        }
        n--;
        if (c == 0xFFFF) {
            break;
        }
        p++;
    }
    if (n == 0 && *p != 0xFFFF) {
        while ((c = *p) != 0xFFFF && c != 0xFFFE) {
            if (c != 0xF000) {
                sub_02045AFC(dst, *p++);
            } else {
                if (c == 0xF000) {
                    end = p + 3;
                end = end + p[2];
                } else {
                    end = p;
                }
                while (p < end) {
                    sub_02045AFC(dst, *p++);
                }
            }
        }
        sub_02045AFC(dst, 0xFFFF);
        return 1;
    }
    return 0;
}

