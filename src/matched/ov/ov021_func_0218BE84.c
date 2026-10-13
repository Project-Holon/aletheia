/*
 * function: FIELD_BUILDMODEL_DeleteAnimSets
 * address:  0x0218BE84
 * packet:   pkt_ov021_0218BE84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   FIELD_BUILDMODEL_FreeAnimSet  0x0218C0D8  thumb  ov021
 */
#include "../include/Obj01114.h"
#include "../include/Obj04986.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020307B0(void *p);
extern void FIELD_BUILDMODEL_FreeAnimSet(void **s);

void FIELD_BUILDMODEL_DeleteAnimSets(u8 *s, u8 *e)
{
    u32 i;

    if (((struct Obj04986 *)e)->f0 != 0) {
        func_020307B0(((struct Obj04986 *)e)->f0);
        ((struct Obj04986 *)e)->f0 = 0;
    }
    if (((struct Obj04986 *)e)->f8 != 0) {
        func_020307B0(((struct Obj04986 *)e)->f8);
        ((struct Obj04986 *)e)->f8 = 0;
    }
    if (*(u8 * *)&((struct Obj01114 *)s)->f1D8 != 0) {
        for (i = 0; i < ((struct Obj01114 *)s)->f1D4; i++)
            FIELD_BUILDMODEL_FreeAnimSet((void **)(*(u8 * *)&((struct Obj01114 *)s)->f1D8 + i * 0x18));
        func_020307B0(*(u8 * *)&((struct Obj01114 *)s)->f1D8);
        ((struct Obj01114 *)s)->f1D4 = 0;
        *(u8 * *)&((struct Obj01114 *)s)->f1D8 = 0;
    }
}
