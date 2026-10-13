/*
 * function: func_021C5E30
 * address:  0x021C5E30
 * packet:   pkt_ov136_021C5E30
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5E30 0x021C5E30 thumb
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj10604.h"
#include "../include/Obj23539.h"
#include "../include/Obj23540.h"
#include "../include/Obj23541.h"
typedef unsigned char u8;
struct Bank;
struct Obj;
struct PrintSys;
extern void PMS_DRAW_Delete(struct Obj *p);
extern void func_0201C4C0(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
void func_021C5E30(u8 *p)
{
    PMS_DRAW_Delete(((struct Obj23539 *)(*(u8 * *)&((struct Obj10604 *)p)->f8))->f35C);
    func_0201C4C0(((struct Obj23540 *)(*(u8 * *)&((struct Obj10604 *)p)->f8))->f36C);
    CLACT_DeleteUnit(((struct Obj23541 *)(*(u8 * *)&((struct Obj10604 *)p)->f8))->f368);
}
