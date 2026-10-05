/*
 * function: func_021AB2BC
 * address:  0x021AB2BC
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Terrain-id predicate: the union of the two families below.
 *
 * symbols:
 *   func_021AB27C  0x021AB27C  thumb
 *   func_021AB29C  0x021AB29C  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern BOOL func_021AB27C(u16 id);
extern BOOL func_021AB29C(u16 id);


BOOL func_021AB2BC(u16 id)
{
    if (func_021AB27C(id) == 1 || func_021AB29C(id) == 1) {
        return 1;
    }

    return 0;
}
