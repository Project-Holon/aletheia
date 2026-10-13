/*
 * unit:     yes
 * function: G3D_UTIL_GetUnitObjIdx, G3D_UTIL_GetUnitObjCount, G3D_UTIL_GetResource, G3D_UTIL_GetObject
 * address:  0x020489F4
 * packet:   pkt_02048330
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Four twelve-byte accessors on the 8-byte record array that G3D_UTIL_FreeUnitObjects
 * walks: two halfword getters at +0x1a and +0x1c of record `i`, and two word
 * getters through the pointers at +0 and +0xc of a different object.
 *
 * None of them carries a label in the generated listing: they are leaves whose
 * prologue saves nothing, and `disasm.py` only auto-labels a function whose
 * prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They were
 * read out of the bytes.  The worklist's own function list for pkt_02048330
 * stops at the labelled bodies, so these four are the 48-byte hole between
 * G3D_UTIL_FreeUnitObjects and func_02048A24 - the range is contiguous and this unit
 * reproduces all of it.
 *
 * Three of the four instructions in the first pair are the same in both:
 * `add r0, r0, r1, lsl #3` is the record stride of 8 folded into the add, and
 * the halfword offset rides in the load.
 */
#include "../include/Obj17329.h"
#include "../include/Obj17330.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 G3D_UTIL_GetUnitObjIdx(u8 *a0, int i)
{
    return *(u16 *)(a0 + i * 8 + 0x1a);
}

u32 G3D_UTIL_GetUnitObjCount(u8 *a0, int i)
{
    return *(u16 *)(a0 + i * 8 + 0x1c);
}

u32 G3D_UTIL_GetResource(u8 *a0, int i)
{
    return *(u32 *)((u8 *)((struct Obj17329 *)a0)->f0 + i * 4);
}

u32 G3D_UTIL_GetObject(u8 *a0, int i)
{
    return *(u32 *)((u8 *)((struct Obj17330 *)a0)->fC + i * 4);
}
