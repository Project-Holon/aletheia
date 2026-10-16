/*
 * function: MICTEST_ClearDisplay
 * address:  0x02183F08
 * packet:   pkt_02183F08
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 */
typedef unsigned int u32;

extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);

void MICTEST_ClearDisplay(void)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FFu;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FFu;
}
