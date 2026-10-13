/*
 * function: FLD_EXP_OBJ_RemoveUnit
 * address:  0x021BE418
 * packet:   pkt_ov021_021BE418
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   G3D_UTIL_RemoveUnit  0x020480E4  arm
 *
 * The listing extent (172) runs on into unlabelled leaves 0x021BE480,
 * 0x021BE4A4 and 0x021BE4B4; the function itself is 102 bytes.
 * Three spellings together give the image's frame: i is a u16 parameter
 * (spilled to [sp] at entry and reloaded for the i < 4 test), the slot and
 * entry offsets are `i << 4` (one CSE kept in r7 to the final store), and
 * the tail recomputes `(u32)i * 16` from the spilled i, which the compiler
 * does not merge with the `<< 4` value. slot is assigned p first, then
 * p + 8: both stores to its stack slot survive.
 */
#include "../include/Obj12902.h"
#include "../include/Obj20141.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020307B0(void *p);
struct Ctx;
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);

void FLD_EXP_OBJ_RemoveUnit(u8 *p, u16 i)
{
    u8 *slot = p;
    u16 k;
    u8 *e;

    slot = p + 8;
    if (*(u32 *)(slot + (i << 4)) != 0 && i < 4) {
        e = p + (i << 4);
        for (k = 0; k < ((struct Obj12902 *)e)->f16; k++)
            func_020307B0(*(u8 **)(*(u8 * *)&((struct Obj12902 *)e)->f10 + k * 8 + 4));
        func_020307B0(*(void **)(p + 0x10 + (u32)i * 16));
        func_020307B0(*(void **)(p + 0xC + (u32)i * 16));
        G3D_UTIL_RemoveUnit((struct Ctx *)(((struct Obj20141 *)p)->f4), *(u16 *)(p + 0x14 + (u32)i * 16));
        *(u32 *)(slot + (i << 4)) = 0;
    }
}
