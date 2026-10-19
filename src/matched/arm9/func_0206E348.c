/*
 * unit:     no
 * function: NNS_G3dAllocRenderObj
 * address:  0x0206E348
 * packet:   pkt_0206DB40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_FndAllocFromAllocator  0x02061330  arm
 */

typedef unsigned int   u32;
struct Obj02061330;
extern void NNS_FndAllocFromAllocator(struct Obj02061330 *o, u32 x);
void NNS_G3dAllocRenderObj(int a0, int a1, int a2, int a3){ NNS_FndAllocFromAllocator((struct Obj02061330 *)((int)a0), (int)0x54); }
