/*
 * function: func_021B9AF4
 * address:  0x021B9AF4
 * packet:   pkt_021B9AF4
 * region:   ov182
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../include/Obj24516.h"

struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_02082BCC(void *, int, int);

void func_021B9AF4(void *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj24516 *)p)->f0));
    CLACT_ExitSystem();
    func_02082BCC(p, 0, 4);
}
