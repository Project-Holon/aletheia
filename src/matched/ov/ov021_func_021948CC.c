/*
 * function: TALKMSGWIN_SetupAutoBalloon
 * address:  0x021948CC
 * packet:   pkt_ov021_021948CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0206DF3C  0x0206DF3C  arm
 *   TALKMSGWIN_SetupUpperBalloon  0x02194848  thumb  ov021
 *   TALKMSGWIN_SetupLowerBalloon  0x02194888  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0206DF3C(u32 a, int *x, int *y);
extern void TALKMSGWIN_SetupUpperBalloon(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
extern void TALKMSGWIN_SetupLowerBalloon(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);

void TALKMSGWIN_SetupAutoBalloon(u8 *p, int i, u32 a, u32 b, u8 u, u32 v, u32 x)
{
    int px;
    int py;

    func_0206DF3C(a, &px, &py);
    if (py < 0x60)
        TALKMSGWIN_SetupLowerBalloon(p, i, a, b, u, v, 0, x);
    else
        TALKMSGWIN_SetupUpperBalloon(p, i, a, b, u, v, 0, x);
}
