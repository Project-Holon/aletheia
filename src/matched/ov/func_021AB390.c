/*
 * function: func_021AB390
 * address:  0x021AB390
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Terrain-id predicate: func_021AB370 (0x19) or func_021AB37C (0x0b, 0x0c, 0x23).
 *
 * symbols:
 *   func_021AB370  0x021AB370  thumb
 *   func_021AB37C  0x021AB37C  thumb
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

extern BOOL func_021AB370(u16 id);
extern BOOL func_021AB37C(u16 id);


BOOL func_021AB390(u16 id)
{
    if (func_021AB370(id) || func_021AB37C(id)) {
        return 1;
    }

    return 0;
}
