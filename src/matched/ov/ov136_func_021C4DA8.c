/*
 * function: func_021C4DA8
 * address:  0x021C4DA8
 * packet:   pkt_ov136_021C4DA8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C4DA8 0x021C4DA8 thumb
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "../include/Obj01751.h"
typedef unsigned char u8;
struct Bank;
struct Obj;
struct PrintSys;
extern void PMS_DRAW_Delete(struct Obj *p);
extern void func_0201C4C0(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 func_0204B1CC(struct Bank *bank);
void func_021C4DA8(u8 *p)
{
    PMS_DRAW_Delete(((struct Obj01751 *)p)->f148);
    func_0201C4C0(((struct Obj01751 *)p)->f158);
    ((struct Obj01751 *)p)->f158 = 0;
    func_0204B1CC(((struct Obj01751 *)p)->f154);
}
