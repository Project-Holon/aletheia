/*
 * function: FLD_PARTICLE_Create
 * address:  0x021C1A08
 * packet:   pkt_ov021_021C1A08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   PARTICLE_InitManager  0x02050B80  arm
 *   d_021DE3C8     0x021DE3C8  data  ov021  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12917.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void PARTICLE_InitManager(u32);
extern u8 d_021DE3C8;

u32 *FLD_PARTICLE_Create(u32 a)
{
    u32 *r;

    r = func_02030734(a, 0x10, 1, (const char *)&d_021DE3C8, 0x2e);
    ((struct Obj12917 *)r)->f4 = a;
    PARTICLE_InitManager(a);
    r[2] = (u32)func_02030734(a, 0x4800, 1, (const char *)&d_021DE3C8, 0x34);
    return r;
}
