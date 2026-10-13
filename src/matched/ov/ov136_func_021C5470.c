/*
 * function: func_021C5470
 * address:  0x021C5470
 * packet:   pkt_ov136_021C5470
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5470 0x021C5470 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 */
#include "../include/Obj23500.h"
typedef unsigned char u8;
struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
void func_021C5470(u8 *p)
{
    CLACT_DeleteUnit(((struct Obj23500 *)p)->fA0);
    CLACT_ExitSystem();
}
