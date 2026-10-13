/*
 * function: MI_GetWramBankMaster
 * address:  0x02730388
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_027301E0 0x027301E0 data twl
 */
typedef unsigned int u32;

extern u32 (*const data_027301E0[])(u32);

u32 MI_GetWramBankMaster(u32 i, u32 a)
{
    return data_027301E0[i](a);
}
