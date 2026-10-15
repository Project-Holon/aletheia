/*
 * unit:     no
 * function: VM_Exit
 * address:  0x02010D98
 * packet:   pkt_02010A5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */
#include "../include/Obj15617.h"

struct S020314B8;
extern void func_0203133C(struct S020314B8 *p);
struct Proc;
extern void func_020315D4(struct Proc *p);

int VM_Exit(int a0, int a1, int a2, int a3){ int t2; func_0203133C((struct S020314B8 *)((struct Obj15617 *)((char *)(a3)))->f8); func_020315D4((struct Proc *)((a0 + 0) + 0)); t2 = GFL_HEAP_DeleteChecked((int)0x5b); return 1; }
