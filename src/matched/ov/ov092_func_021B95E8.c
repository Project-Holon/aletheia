/*
 * function: EVENT_BATTLE_RETURN_Exit
 * address: 0x021B95E8
 * packet: pkt_ov092_021B95E8
 * region: ov092
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj07738.h"
typedef unsigned int u32;
struct S020314B8;
struct Proc;
struct U16Vec;
extern void func_0203133C(struct S020314B8 *);
extern void STRBUF_Delete(struct U16Vec *);
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int EVENT_BATTLE_RETURN_Exit(struct Proc *p, u32 b, u32 c, u32 d)
{
    func_0203133C(*(struct S020314B8 * *)&((struct Obj07738 *)d)->f40);
    if (*(struct U16Vec * *)&((struct Obj07738 *)d)->f2C) STRBUF_Delete(*(struct U16Vec * *)&((struct Obj07738 *)d)->f2C);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj07738 *)d)->f4);
    func_020315D4(p);
    GFL_HEAP_DeleteChecked(0x52);
    return 1;
}
