/*
 * function: func_021A5B7C
 * address:  0x021A5B7C
 * packet:   pkt_ov021_021A5B7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A66F8  0x021A66F8  thumb  ov021
 *   func_021A6B08  0x021A6B08  thumb  ov021
 *   func_021A6B30  0x021A6B30  thumb  ov021
 *   func_021A6B50  0x021A6B50  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19806.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern int  func_021A66F8(u8 *p, u32 f);
extern void func_021A6B08(u8 *p, u32 v);
extern void func_021A6B30(u8 *p);
extern void func_021A6B50(u8 *p, u32 v);

void func_021A5B7C(u8 *p)
{
    if (func_021A66F8(p, 8)) {
        func_021A6B08(p + 8, 0);
    } else if (func_021A66F8(p, 0x10)) {
        func_021A6B08(p + 8, 1);
    } else {
        func_021A6B30(p + 8);
    }
    func_021A6B50(p + 8, ((struct Obj19806 *)p)->f1C);
}
