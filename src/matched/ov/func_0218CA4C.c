/*
 * function: FIELD_G3D_MAPPER_Delete
 * address:  0x0218CA4C
 * packet:   pkt_0218CA4C
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
 *   HEIGHT_EX_FreeTable  0x021C0674  thumb  ov021
 *   FIELD_G3D_MAPPER_ReleaseBlocks  0x0218D05C  thumb  ov021
 *   FIELD_WFBC_Delete  0x021938D4  thumb  ov021
 *   FIELD_BUILDMODEL_Delete  0x0218B7F8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05856.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern void FIELD_BUILDMODEL_Delete(char *p);
extern void FIELD_G3D_MAPPER_ReleaseBlocks(char *p);
extern u32 FIELD_WFBC_Delete(void *a);
extern void HEIGHT_EX_FreeTable(void **p);

int FIELD_G3D_MAPPER_Delete(void *a)
{
HEIGHT_EX_FreeTable((void **)(((struct Obj05856 *)((u8 *)(a)))->f70));
FIELD_G3D_MAPPER_ReleaseBlocks((char *)a);
FIELD_WFBC_Delete((void *)(((struct Obj05856 *)((u8 *)(a)))->f6C));
if (((struct Obj05856 *)((u8 *)(a)))->f64 != 0) {
    FIELD_BUILDMODEL_Delete((char *)(((struct Obj05856 *)((u8 *)(a)))->f64));
    ((struct Obj05856 *)((u8 *)(a)))->f64 = 0;
}
return func_020307B0(a);
}

