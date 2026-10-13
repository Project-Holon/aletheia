/*
 * function: func_021B61D4
 * address: 0x021B61D4
 * packet: pkt_ov180_021B61D4
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B8060 0x021B8060 data a4
 *   d_021B8090 0x021B8090 data a4
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 */
typedef unsigned int u32;
struct DispVram;
extern const struct DispVram d_021B8060;
extern const struct DispVram d_021B8090;
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
void func_021B61D4(int flag)
{
    BG_SYS_ClearGraphicsMemory(0);
    if (flag == 0)
        BG_SYS_SetVramBanks(&d_021B8060);
    else
        BG_SYS_SetVramBanks(&d_021B8090);
}
