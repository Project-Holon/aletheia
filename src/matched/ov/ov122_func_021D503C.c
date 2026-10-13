/*
 * function: func_021D503C
 * address: 0x021D503C
 * packet: pkt_ov122_021D503C
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: zero padding at 0x021D50B2; next function at 0x021D50B4.
 * symbols:
 *   func_02158630 0x02158630 thumb ov010
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj00265.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct Ctx;
struct Obj;
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158630(int a);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021D503C(char *p)
{
    switch (func_02158630(func_02012138(((struct Obj00265 *)p)->f354))) {
    case 0:
    case 1:
        if (CLACT_GetActorAnimSeq(((struct Obj00265 *)p)->f390) == 20) {
            func_0204B92C(((struct Obj00265 *)p)->f390, 0);
            func_0204B878(((struct Obj00265 *)p)->f390, 12);
        }
        break;
    case 2:
    case 3:
        if (CLACT_GetActorAnimSeq(((struct Obj00265 *)p)->f390) == 12) {
            func_0204B92C(((struct Obj00265 *)p)->f390, 1);
            func_0204B878(((struct Obj00265 *)p)->f390, 20);
        }
        break;
    }
}
