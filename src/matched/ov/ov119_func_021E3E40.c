/*
 * function: func_021E3E40
 * address:  0x021E3E40
 * packet:   pkt_ov119_021E3E40
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call wrapper after pool_021E3E3C, seeded so that
 * ov117 func_021D4BF4 has a witness: forwards the two ov119 tables and the
 * u16 heap id held at +0x5F4 to the ARM function 0x0204A48C.
 *
 * symbols:
 *   CLACT_InitSystem  0x0204A48C  arm
 *   d_021E7CE4     0x021E7CE4  data  ov119
 *   d_021E7D40     0x021E7D40  data  ov119
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22799.h"

typedef unsigned int   u32;
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern const char d_021E7CE4[];
extern const char d_021E7D40[];

void func_021E3E40(char *p)
{
    CLACT_InitSystem((const struct Cfg *)d_021E7CE4, (u32)d_021E7D40, ((struct Obj22799 *)p)->f5F4);
}
