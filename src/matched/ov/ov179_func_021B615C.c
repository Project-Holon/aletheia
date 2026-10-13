/*
 * function: func_021B615C
 * address:  0x021B615C
 * packet:   pkt_021B615C
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 */

struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);

void func_021B615C(void)
{
    BG_SYS_SetVramBanks((void *)0x021B68F0);
}
