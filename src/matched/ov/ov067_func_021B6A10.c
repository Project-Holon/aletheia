/*
 * unit:     yes
 * function: func_021B6A10, func_021B6A1C
 * address:  0x021B6A10
 * packet:   pkt_ov067_021B6A10
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two ARM9 tail calls on the pointer loaded from offset 0.
 *
 * symbols:
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   func_0204B84C  0x0204B84C  arm
 */
#include "../include/Obj20614.h"
#include "../include/Obj20615.h"

typedef unsigned int   u32;
struct Node;
void func_021B6A10(void *p, unsigned int v)
{
    void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
    CLACT_SetActorDrawPriority(((struct Obj20614 *)p)->f0, v);
}

void func_021B6A1C(void *p, unsigned int v)
{
    void func_0204B84C(void *, unsigned int);
    func_0204B84C(((struct Obj20615 *)p)->f0, v);
}
