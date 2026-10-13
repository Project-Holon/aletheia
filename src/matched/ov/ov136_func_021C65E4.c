/*
 * function: func_021C65E4
 * address:  0x021C65E4
 * packet:   pkt_ov136_021C65E4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 */
#include "../include/Obj10606.h"

typedef unsigned char u8;
typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleasePalette(u32 i);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
void func_021C65E4(u8 *p)
{
    CLACT_ReleaseCellAnim((u32)(((struct Obj10606 *)p)->f230));
    CLACT_ReleasePalette((u32)(((struct Obj10606 *)p)->f250));
    CLACT_DeleteUnit(((struct Obj10606 *)p)->f1EC);
    CLACT_ExitSystem();
}
