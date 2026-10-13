/*
 * function: MIi_SetWramBankMaster
 * address:  0x02730294
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02730204 0x02730204 data twl
 */
typedef unsigned int u32;

extern void (*const data_02730204[])(u32, u32);

void MIi_SetWramBankMaster(u32 i, u32 a, u32 b)
{
    data_02730204[i](a, b);
}
