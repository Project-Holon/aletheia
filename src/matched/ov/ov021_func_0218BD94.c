/*
 * function: FIELD_BUILDMODEL_DeleteModels
 * address:  0x0218BD94
 * packet:   pkt_ov021_0218BD94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   FIELD_BUILDMODEL_FreeModel  0x0218BF84  thumb  ov021
 */
#include "../include/Obj01114.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020307B0(void *p);
extern void FIELD_BUILDMODEL_FreeModel(void *p);

void FIELD_BUILDMODEL_DeleteModels(u8 *s)
{
    u32 i;

    if (*(u8 * *)&((struct Obj01114 *)s)->f1CC != 0) {
        for (i = 0; i < ((struct Obj01114 *)s)->f1C8; i++)
            FIELD_BUILDMODEL_FreeModel(*(u8 * *)&((struct Obj01114 *)s)->f1CC + i * 0x18);
        func_020307B0(*(u8 * *)&((struct Obj01114 *)s)->f1CC);
        ((struct Obj01114 *)s)->f1C8 = 0;
        *(u8 * *)&((struct Obj01114 *)s)->f1CC = 0;
    }
}
