/*
 * function: func_02019D58
 * address:  0x02019D58
 * packet:   pkt_02019D58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +0028 ABS32 sub_0209E280_Map       : 0209E280 (data, from header) has no witness outside 02019D58..02019D84
 * symbols:
 *   sub_0209E280_Map  0x0209E280  data
 */

typedef unsigned short u16;

extern u16 sub_0209E280_Map[];

int func_02019D58(u16 a, int b)
{
    u16 i;

    if (b != 0) {
        for (i = 0; i < 4; i++)
            if (sub_0209E280_Map[i] == a)
                return 0;
    }
    return b;
}
