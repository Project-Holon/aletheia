/*
 * function: func_021BB9E4
 * address:  0x021BB9E4
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears +0x10/+0x14 then runs the 0x84/0x88/0x8c/0x90 handles through the five
 * resource teardown entry points.
 *
 * symbols:
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00024.h"

typedef unsigned int u32;

struct Actor;
struct Obj;
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021BB9E4(void *a0, char *a1)
{
    *(u32 *)&((struct Obj00024 *)a1)->f10 = 0;
    *(u32 *)&((struct Obj00024 *)a1)->f14 = 0;
    CLACT_RestartActorAnim(((struct Obj00024 *)a1)->f84);
    CLACT_RestartActorAnim(((struct Obj00024 *)a1)->f88);
    CLACT_RestartActorAnim(((struct Obj00024 *)a1)->f8C);
    CLACT_SetActorAnimFrame(((struct Obj00024 *)a1)->f84, 0);
    CLACT_SetActorAnimFrame(((struct Obj00024 *)a1)->f88, 0);
    func_0204B92C(((struct Obj00024 *)a1)->f84, 0);
    func_0204B92C(((struct Obj00024 *)a1)->f88, 0);
    func_0204B3DC(((struct Obj00024 *)a1)->f84, 0);
    func_0204B3DC(((struct Obj00024 *)a1)->f88, 0);
    func_0204B3DC(((struct Obj00024 *)a1)->f8C, 0);
    func_0204B3DC(((struct Obj00024 *)a1)->f90, 0);
}
