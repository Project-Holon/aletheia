/*
 * function: WF2DMAP_TOUCH_TransferScreen
 * address:  0x021CA4B4
 * packet:   pkt_021CA4B4
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(unsigned);

void WF2DMAP_TOUCH_TransferScreen(char *p)
{
    BMP_WIN_MakeScreen((struct Cfg *)p);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)p));
}
