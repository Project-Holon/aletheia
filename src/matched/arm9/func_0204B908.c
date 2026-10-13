/*
 * function: CLACT_SetActorAnimIndex
 * address:  0x0204B908
 * packet:   pkt_0204B908
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetAnimIndex  0x0204D478  arm
 */

typedef unsigned int   u32;
struct Obj0204D478;
extern void *CLACT_SetAnimIndex(struct Obj0204D478 *o, u32 arg);
void CLACT_SetActorAnimIndex(int a0, int a1){ CLACT_SetAnimIndex((struct Obj0204D478 *)((int)(a0 + 0x68)), (int)a1); }
