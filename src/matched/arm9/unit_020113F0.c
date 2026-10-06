/*
 * unit:     yes
 * function: func_020113F0, func_02011400
 * address:  0x020113F0
 * packet:   pkt_020113F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   tbl_0209DF24  0x0209DF24  data  a1
 *   tbl_0209DF10  0x0209DF10  data  a1
 *
 * vm.c, 0x020113F0..0x02011410: two byte lookups in constant 2D tables,
 * rows of 0x18 and 5 bytes.  Plain subscripts `tbl[row][col]` give the
 * image's `base + row * stride` then `ldrb [col, base]`; the old pending
 * park (byte-offset arithmetic, docs/notes/pkt_020113F0.c.txt) was capped on
 * the two single-pool rodata tables, which sole-ref/self now carries.
 */

typedef unsigned char u8;

extern const u8 tbl_0209DF24[][0x18];
extern const u8 tbl_0209DF10[][5];

int func_020113F0(int row, int col)
{
    return tbl_0209DF24[row][col];
}

u8 func_02011400(int row, int col)
{
    return tbl_0209DF10[row][col];
}
