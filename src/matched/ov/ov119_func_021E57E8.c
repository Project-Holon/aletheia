/*
 * function: POKETRADE_2D_SetDisplayConfig
 * address:  0x021E57E8
 * packet:   pkt_ov119_021E57E8
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   gDisplayConfig 0x021E7D20 data a4
 */
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern const char gDisplayConfig[];
void POKETRADE_2D_SetDisplayConfig(int i)
{
    BG_SYS_SetGraphicsMode((struct DispConfig *)(gDisplayConfig + i * 16));
}
