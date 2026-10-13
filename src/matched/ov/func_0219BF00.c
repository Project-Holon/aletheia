/*
 * function: FLDMMDL_MOVE_HideKeepEffect
 * address:  0x0219BF00
 * packet:   pkt_0219BF00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_MOVE_GetHideEffect  0x0219BF48  thumb  ov021
 *   FLDMMDL_CheckDrawInitComp  0x0216DB24  thumb  ov010
 *   FLDEFF_HIDE_Create  0x0219BEB4  thumb  ov021
 *   FLDMMDL_MOVE_SetHideEffect  0x0219BF3C  thumb  ov021
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12076.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int FLDMMDL_CheckDrawInitComp(int a0);
extern int FLDEFF_HIDE_Create(u32 a, u32 b);
extern void FLDMMDL_MOVE_SetHideEffect(int a, u32 v);
extern int FLDMMDL_MOVE_GetHideEffect(u32 a);

int FLDMMDL_MOVE_HideKeepEffect(u32 a, u32 b, u32 c, u32 d)
{
if (((struct Obj12076 *)((u8 *)(b)))->f2 == 0) {
    if (FLDMMDL_MOVE_GetHideEffect(a) == 0) {
        if (FLDMMDL_CheckDrawInitComp(a) == 1) {
            FLDMMDL_MOVE_SetHideEffect(a, FLDEFF_HIDE_Create(a, ((struct Obj12076 *)((u8 *)(b)))->f1));
        }
    }
    FLDMMDL_SetMoveBit((void *)a, (2 << 14));
}
return 0;
}

