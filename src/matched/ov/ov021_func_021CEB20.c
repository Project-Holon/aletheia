/*
 * function: func_021CEB20
 * address:  0x021CEB20
 * packet:   pkt_ov021_021CEB20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190A20  0x02190A20  thumb  ov021
 *   func_021CEF1C  0x021CEF1C  thumb  ov021
 *   func_0219097C  0x0219097C  thumb  ov021
 *   data_021DB478  0x021DB478  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00659.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188C54(u8 *p);
extern u32 func_02190A20(u32, u32);
extern void func_021CEF1C(u8 *p);
extern u32 func_0219097C(u32, const void *, u32);
extern const u8 data_021DB478[];

void func_021CEB20(u8 *p)
{
    u32 h;

    h = func_02188C54((u8 *)(((struct Obj00659 *)p)->f0));
    ((struct Obj00659 *)p)->f13C = func_02190A20(0x10, ((struct Obj00659 *)p)->f528);
    func_021CEF1C(p);
    ((struct Obj00659 *)p)->f140 = func_0219097C(h, data_021DB478, ((struct Obj00659 *)p)->f13C);
    p[0x40c] = 0;
}
