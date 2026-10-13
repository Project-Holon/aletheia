/*
 * unit: yes
 * function: func_021C4634, func_021C464C, func_021C465C, func_021C466C
 * address: 0x021C4634
 * packet: pkt_ov127_021C4634
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C5FE4 0x021C5FE4 data a4
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 */
#include "../include/Obj14021.h"
#include "../include/Obj14022.h"
#include "../include/Obj14023.h"
#include "../include/Obj23024.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void (*const d_021C5FE4[])(u8 *);
struct Obj;
extern void CLACT_ChangeActorAnimSeq(struct Obj *p, u16 v);
void func_021C4634(u8 *p)
{
    void (*f)(u8 *);
    f = d_021C5FE4[((struct Obj23024 *)p)->fC];
    if (f) f(p);
}
void func_021C464C(u8 *p, u32 i)
{
    ((struct Obj14021 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14021 *)p)->f4, i);
}
void func_021C465C(u8 *p, u32 i)
{
    ((struct Obj14022 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14022 *)p)->f4, 4);
}
void func_021C466C(u8 *p, u32 i)
{
    ((struct Obj14023 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14023 *)p)->f4, i + 5);
}
