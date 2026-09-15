/*
 * function: func_021AB11C
 * address:  0x021AB11C
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The walk/collision test: a tile blocks movement when its attribute word
 * is absent (func_021AB100) or when bit 0 of the flag half is set.
 *
 * symbols:
 *   func_021AB0F8  0x021AB0F8  thumb
 *   func_021AB100  0x021AB100  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern u16 func_021AB0F8(u32 attr);
extern BOOL func_021AB100(u32 attr);


BOOL func_021AB11C(u32 attr)
{
    u16 flags;

    flags = func_021AB0F8(attr);

    if (!func_021AB100(attr) || (flags & 1)) {
        return 1;
    }

    return 0;
}
