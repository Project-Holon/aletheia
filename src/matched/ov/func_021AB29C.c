/*
 * function: func_021AB29C
 * address:  0x021AB29C
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain-id predicate: the union of the two families below.
 *
 * symbols:
 *   func_021AB250  0x021AB250  thumb
 *   func_021AB270  0x021AB270  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern BOOL func_021AB250(u16 id);
extern BOOL func_021AB270(u16 id);


BOOL func_021AB29C(u16 id)
{
    if (func_021AB250(id) == 1 || func_021AB270(id) == 1) {
        return 1;
    }

    return 0;
}
