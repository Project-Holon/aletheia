/*
 * function: func_020213C0
 * address:  0x020213C0
 * packet:   pkt_020213C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  +001C ABS32 sub_0209E968_Map       : 0209E968 (data, from header) has no witness outside 020213C0..020213E0
 * symbols:
 *   sub_0209E968_Map  0x0209E968  data
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 sub_0209E968_Map[];

int func_020213C0(u16 a)
{
    u32 i;

    for (i = 0; i < 0x40; i++)
        if (sub_0209E968_Map[i] == a)
            return 1;
    return 0;
}
