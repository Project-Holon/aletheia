/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02016BA0
 * packet:   pkt_02015F2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MCSS_FreeResource, MCSS_DeleteTextureTask
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   TCBL_GetTaskUserData  0x02030EE8  arm
 *   MCSS_DeleteTextureTask  0x02016C0C  thumb
 *
 * alias: a teardown chain on the same object class as unit_02015BA4.c.
 * MCSS_FreeResource releases eight pointer fields of the object through
 * func_020307B0 (a generic release call reached by blx, so it is ARM),
 * zeroes three of them (+0x98, +0xd4, +0xd8, all past the immediate str
 * reach so the compiler adds the offset into a register first), then
 * zeroes the other four (+0xc, +0x1c, +0x14, +0x24, +0x2c) and, if the
 * object's own field at +0 is non-zero, recurses into MCSS_DeleteTextureTask with
 * that field's value before zeroing it too. MCSS_DeleteTextureTask turns an id into
 * an object through TCBL_GetTaskUserData, releases one or two of the object's own
 * pointer fields the same way, releases the object itself, and finally
 * releases the id through func_02030EAC.
 *
 * The immediate follower, MCSS_DeletePaletteTask (38 bytes, same shape over a third
 * field, one level of extra indirection), is a documented near miss: this
 * front end assigns it only two callee-saved registers (padding a filler
 * into r3) where the original spends three (r4, r5, r6), so the second
 * fetch of the inner pointer is a register move here and a reload from
 * memory in every source shape tried. Left out rather than forced.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02016BA0.c \
 *       --addr 0x02016BA0 --thumb
 */
#include "../include/Obj01104.h"
#include "../include/Obj07131.h"

typedef unsigned char u8;

extern unsigned int func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);
typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);
extern void MCSS_DeleteTextureTask(void *id);

void MCSS_FreeResource(void *obj)
{
    u8 *o = (u8 *)obj;

    func_020307B0(((struct Obj01104 *)o)->fC);
    func_020307B0(((struct Obj01104 *)o)->f1C);
    func_020307B0(((struct Obj01104 *)o)->f14);
    func_020307B0(((struct Obj01104 *)o)->f24);
    func_020307B0(((struct Obj01104 *)o)->f98);
    func_020307B0(((struct Obj01104 *)o)->f2C);
    func_020307B0(((struct Obj01104 *)o)->fD4);
    func_020307B0(((struct Obj01104 *)o)->fD8);

    ((struct Obj01104 *)o)->f98 = 0;
    ((struct Obj01104 *)o)->fD4 = 0;
    ((struct Obj01104 *)o)->fD8 = 0;

    {
        void *v = ((struct Obj01104 *)o)->f0;
        ((struct Obj01104 *)o)->fC = 0;
        ((struct Obj01104 *)o)->f1C = 0;
        ((struct Obj01104 *)o)->f14 = 0;
        ((struct Obj01104 *)o)->f24 = 0;
        ((struct Obj01104 *)o)->f2C = 0;
        if (v != 0) {
            MCSS_DeleteTextureTask(v);
            ((struct Obj01104 *)o)->f0 = 0;
        }
    }
}

void MCSS_DeleteTextureTask(void *id)
{
    void *obj = (void *)TCBL_GetTaskUserData(id);

    if (((struct Obj07131 *)obj)->f10 != 0) {
        func_020307B0(((struct Obj07131 *)obj)->f10);
    }
    if (((struct Obj07131 *)obj)->f14 != 0) {
        func_020307B0(((struct Obj07131 *)obj)->f14);
    }
    func_020307B0(obj);
    func_02030EAC(id);
}
