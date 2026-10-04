/*
 * function: func_021CCF60
 * address:  0x021CCF60
 * packet:   pkt_ov021_021CCF60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Dispatches on a selector below two to func_021CD184, otherwise to func_021CD1AC, on the object from func_02020D0C.
 *
 * symbols:
 *   func_02020D0C  0x02020D0C  thumb
 *   func_021CD184  0x021CD184  thumb  ov021
 *   func_021CD1AC  0x021CD1AC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern u32 func_02020D0C(u8 *p);
extern void func_021CD184(void *p, u32 sel);
extern void func_021CD1AC(void *p);

void func_021CCF60(void *a, u32 sel)
{
    void *p = (void *)func_02020D0C(a);
    if (sel < 2)
        func_021CD184(p, sel);
    else
        func_021CD1AC(p);
}
