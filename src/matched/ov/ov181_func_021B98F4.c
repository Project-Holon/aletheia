/*
 * function: STAFF_ROLL_SetupVramBanks
 * address:  0x021B98F4
 * packet:   pkt_ov181_021B98F4
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   d_021BABFC     0x021BABFC  data  a4
 */

typedef unsigned int   u32;
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern int  d_021BABFC[];

void STAFF_ROLL_SetupVramBanks(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BABFC);
}
