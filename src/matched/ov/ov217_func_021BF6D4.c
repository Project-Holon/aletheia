/*
 * function: func_021BF6D4
 * address:  0x021BF6D4
 * packet:   pkt_ov217_021BF6D4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020270E0 0x020270E0 thumb
 *   func_021BF834 0x021BF834 thumb ov217
 *   func_021BF9CC 0x021BF9CC thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25931.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 func_020270E0(void);
extern u32 func_021BF834(void *p);
extern u16 func_021BF9CC(u32 a0);
void func_021BF6D4(char *p)
{
    if (func_020270E0() == 1) {
        u16 a = func_021BF834(p);
        if (a != (u16)(u32)func_021BF9CC((u32)p)) {
            ((struct Obj25931 *)p)->f3D8 = 1;
        }
    }
}
