/*
 * function: sub_02022D88
 * address:  0x02022D88
 * packet:   pkt_02022D88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Index into a flat array whose base pointer is the first field of
 * `obj`, with a fixed 0x604-byte stride.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02022D88.c \
 *       --func sub_02022D88 --addr 0x02022D88 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8 *base;
};

void *sub_02022D88(struct Obj *obj, u32 idx)
{
    return obj->base + idx * 0x604;
}
