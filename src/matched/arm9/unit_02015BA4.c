/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02015BA4
 * packet:   pkt_02015BA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MCSS_Del, MCSS_SetOrthoMode, MCSS_ResetOrthoMode, MCSS_SetOrthoBillboardFlag,
 *           MCSS_ResetOrthoBillboardFlag
 *
 * symbols:
 *   MCSS_FreeResource  0x02016BA0  thumb
 *   MCSS_DeleteTextureTask  0x02016C0C  thumb
 *   MCSS_DeletePaletteTask  0x02016C38  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * alias: MCSS_Del tears down an object: it calls MCSS_FreeResource(obj), then
 * for each of the three word fields at +0, +4 and +8 that is non-zero it
 * passes that field's *value* (not the object) to a cleanup call
 * (MCSS_DeleteTextureTask for +0, MCSS_DeletePaletteTask for +4 and +8) and zeroes the field;
 * it then clears a slot this object owns in an array reached through
 * sys->+0x14, indexed by the object's own field at +0x148, and finally
 * hands the object to func_020307B0 through an interworking blx.
 *
 * The four followers are unlabelled leaf accessors on the same class of
 * object, found in the .word run disasm.py left undecoded immediately
 * after MCSS_Del (its prologue has no register-saving push that a
 * two-word bit-flag accessor shares); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Two work a
 * flag at +0x2c: MCSS_SetOrthoMode clears then re-sets bit 0 (a clear/set pair
 * rather than a plain |=, which is what tells apart the extra bics), and
 * MCSS_ResetOrthoMode only clears it. The other two work a flag at +0x140, too far
 * from the object base for an immediate str, which is why the compiler
 * computes the offset into a register instead of folding it into the
 * instruction: MCSS_SetOrthoBillboardFlag sets bit 0x1D (0x20000000) and MCSS_ResetOrthoBillboardFlag
 * clears it via the pool word 0xDFFFFFFF immediately after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02015BA4.c \
 *       --addr 0x02015BA4 --thumb
 */
#include "../include/Obj02638.h"
#include "../include/Obj03429.h"
#include "../include/Obj11824.h"
#include "../include/Obj17197.h"
#include "../include/Obj17198.h"
#include "../include/Obj17199.h"

typedef unsigned int  u32;
typedef unsigned char u8;

extern void MCSS_FreeResource(void *obj);
extern void MCSS_DeleteTextureTask(void *id);
extern int MCSS_DeletePaletteTask(int a0);
extern u32 func_020307B0(void *p);

void MCSS_Del(void *sys, void *obj)
{
    u32 *p = (u32 *)obj;
    u32 idx;
    u32 *arr;

    MCSS_FreeResource(obj);

    if (p[0] != 0) {
        MCSS_DeleteTextureTask((void *)p[0]);
        p[0] = 0;
    }
    if (p[1] != 0) {
        MCSS_DeletePaletteTask(p[1]);
        p[1] = 0;
    }
    if (p[2] != 0) {
        MCSS_DeletePaletteTask(p[2]);
        p[2] = 0;
    }

    idx = ((struct Obj02638 *)obj)->f148;
    arr = *(u32 * *)&((struct Obj03429 *)sys)->f14;
    arr[idx] = 0;

    func_020307B0(obj);
}

void MCSS_SetOrthoMode(void *obj)
{
    ((struct Obj11824 *)obj)->f2C &= ~1;
    ((struct Obj11824 *)obj)->f2C |= 1;
}

void MCSS_ResetOrthoMode(void *obj)
{
    ((struct Obj17197 *)obj)->f2C &= ~1;
}

void MCSS_SetOrthoBillboardFlag(void *obj)
{
    ((struct Obj17198 *)obj)->f140 |= 0x20000000;
}

void MCSS_ResetOrthoBillboardFlag(void *obj)
{
    ((struct Obj17199 *)obj)->f140 &= ~0x20000000;
}
