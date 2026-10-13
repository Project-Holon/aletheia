/*
 * function: MIi_SetWramBankEnable
 * address:  0x0273032C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_027301F8 0x027301F8 data twl
 */
typedef unsigned int u32;

extern void (*const data_027301F8[])(u32, u32);

void MIi_SetWramBankEnable(u32 i, u32 a, u32 b)
{
    data_027301F8[i](a, b);
}
