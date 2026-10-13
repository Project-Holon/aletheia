/*
 * function: func_021EABA0
 * address:  0x021EABA0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_MakeScreen  0x02045374  arm  arm9
 *   BMP_WIN_GetBgLayer  0x02045730  arm  arm9
 *   func_02041B6C  0x02041B6C  arm  arm9
 *
 * Release both children of the object and then a global one.
 */

typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(unsigned int);

void func_021EABA0(void **p)
{
    BMP_WIN_MakeScreen(*p);
    func_02041B6C(BMP_WIN_GetBgLayer(*p));
}

