/*
 * function: MIi_SetWramBankEnable_B
 * address:  0x027302DC
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Function with no listing label.
 */
typedef unsigned char u8;
typedef unsigned int u32;

/* Register field writer: bit 7 of a byte register set or cleared by a flag. */
void MIi_SetWramBankEnable_B(u32 a, u32 on)
{
    volatile u8 *p = (volatile u8 *)(a + 0x04004044);
    u32 v = on ? 0x80 : 0;
    *p = (*p & ~0x80) | v;
}
