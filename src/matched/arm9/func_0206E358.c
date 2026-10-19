/*
 * unit:     no
 * function: NNS_G3dFreeRenderObj
 * address:  0x0206E358
 * packet:   pkt_0206DB40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_FndFreeToAllocator  0x02061344  arm
 */

typedef unsigned int   u32;
struct Obj02061330;
extern void NNS_FndFreeToAllocator(struct Obj02061330 *o, u32 x);
void NNS_G3dFreeRenderObj(struct Obj02061330 *ctx, int field){ NNS_FndFreeToAllocator(ctx, field); }
