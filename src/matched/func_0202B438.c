/*
 * function: func_0202B438
 * address:  0x0202B438
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns 1 when the object's +0x14 sub-object holds a record with the
 * given id, else 0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B438.c \
 *       --func func_0202B438 --addr 0x0202B438 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *func_0202B374(u8 *p, u32 id);

u32 func_0202B438(u8 *p, u32 id)
{
    u8 *q = *(u8 **)(p + 0x14);

    if (q == 0) {
        return 0;
    }
    return func_0202B374(q, id) != 0 ? 1 : 0;
}
