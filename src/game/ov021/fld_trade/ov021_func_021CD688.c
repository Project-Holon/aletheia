/*
 * function: func_021CD688
 * address:  0x021CD688
 * packet:   pkt_ov021_021CD688
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD6D0  0x021CD6D0  thumb  ov021
 *   func_021CDAB8  0x021CDAB8  thumb  ov021
 *   func_021CDD5C  0x021CDD5C  thumb  ov021
 *   func_021CDF18  0x021CDF18  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj00011.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern int func_021CD6D0(u8 *p);
extern int func_021CDAB8(u8 *p);
extern int func_021CDD5C(u8 *p);
extern int func_021CDF18(u8 *p);

u32 func_021CD688(u8 *p)
{
    int r;

    switch (p[0x51f]) {
    case 0:
        r = func_021CD6D0(p);
        break;
    case 1:
        r = func_021CDAB8(p);
        break;
    case 2:
        r = func_021CDD5C(p);
        break;
    case 3:
        r = func_021CDF18(p);
        break;
    }
    if (r == 1) {
        return ((struct Obj00011 *)p)->f2C;
    }
    return 0;
}
