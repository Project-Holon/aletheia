/*
 * function: func_020213F8
 * address:  0x020213F8
 * packet:   pkt_020213F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +0030 ABS32 sub_0209E904_Tbl       : 0209E904 (data, from header) has no witness outside 020213F8..0202142C
 * symbols:
 *   sub_0209E904_Tbl  0x0209E904  data
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 sub_0209E904_Tbl[][2];

u16 func_020213F8(u16 a, int b)
{
    u32 i;

    for (i = 0; i < 0x19; i++)
        if (sub_0209E904_Tbl[i][b] == a)
            return sub_0209E904_Tbl[i][b ^ 1];
    return 0;
}
