/*
 * function: func_0273112C
 * address:  0x0273112C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732F6C 0x02732F6C data twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 data_02732F6C[3][8];

u32 func_0273112C(u32 ch, u32 idx)
{
    return (data_02732F6C[ch][idx] & 3) != 3;
}
