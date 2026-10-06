/*
 * function: func_021A1698
 * address:  0x021A1698
 * packet:   pkt_021A1698
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021A1780  0x021A1780  thumb  ov021
 *   func_021A1750  0x021A1750  thumb  ov021
 *   func_021A16EC  0x021A16EC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07216.h"
#include "../include/Obj17994.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021A16EC(u8 *d, void *a, const u8 *s, u32 n);
extern int func_021A1750(u32 a);
extern u32 func_021A1780(u8 *p);

int func_021A1698(u32 a, int b, void *c, int d)
{
if (func_021A1780((u8 *)(a + 32)) != 0) {
    func_021A1750((a + 32));
}
func_021A16EC((u8 *)(a + 32), (void *)b, (const u8 *)c, d);
((struct Obj07216 *)((u8 *)(a)))->f1F = ((struct Obj17994 *)((u8 *)(c)))->f8;
((struct Obj07216 *)((u8 *)(a)))->f14 = (1 << 12);
((struct Obj07216 *)((u8 *)(a)))->f18 = (1 << 12);
((struct Obj07216 *)((u8 *)(a)))->f1C = 0;
return 0;
}

