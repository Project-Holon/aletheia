/*
 * function: func_021AB334
 * address:  0x021AB334
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain-id predicate forwarding to func_021AB31C (id 0x0e).
 *
 * symbols:
 *   func_021AB31C  0x021AB31C  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern BOOL func_021AB31C(u16 id);


BOOL func_021AB334(u16 id)
{
    if (func_021AB31C(id)) {
        return 1;
    }

    return 0;
}
