/*
 * function: func_021BF854
 * address:  0x021BF854
 * packet:   pkt_ov217_021BF854
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BF878 0x021BF878 thumb ov217
 *   func_021BF894 0x021BF894 thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25946.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021BF878(void *p);
extern u32 func_021BF894(void *p);
u32 func_021BF854(char *p)
{
    switch (((struct Obj25946 *)p)->f2CC) {
    case 0:
        return func_021BF878(p);
    case 1:
        return func_021BF894(p);
    }
    return 0;
}
