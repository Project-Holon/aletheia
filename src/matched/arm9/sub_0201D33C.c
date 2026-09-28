/*
 * function: sub_0201D33C
 * address:  0x0201D33C
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
 *   sub_0201D26C  0x0201D26C  thumb
 *
 * printsys.c: fills a caller-supplied array with the pixel width of each line
 * of a string object, at most `max` of them, and returns how many were
 * written.  sub_0201D26C measures one line and hands back the cursor for the
 * next through its fourth argument; the cursor is a stack local because its
 * address is taken.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201D33C.c
 *       --func sub_0201D33C --addr 0x0201D33C --cc 1.1p1 --thumb
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
extern u32  sub_0201D26C(u16 *cur, u32 a, u32 b, u16 **next);

u32 sub_0201D33C(struct StrObj *s, u32 a, u32 b, u32 *out, u32 max)
{
    u16 *p;
    u32 i;

    p = sub_02045A90(s);
    i = 0;
    while (i < max) {
        if (*p == 0xFFFF) {
            break;
        }
        out[i] = sub_0201D26C(p, a, b, &p);
        i++;
    }
    return i;
}
