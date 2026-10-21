/*
 * function: FLDMMDL_ACMD_ListCheckEnd
 * address:  0x02197DA0
 * packet:   pkt_02197DA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   TCBL_GetOwnedWork  0x02030EE8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17950.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct S02030EE8;
extern u32 TCBL_GetOwnedWork(struct S02030EE8 *p);

int FLDMMDL_ACMD_ListCheckEnd(u32 a)
{
return ((struct Obj17950 *)((u8 *)(TCBL_GetOwnedWork((struct S02030EE8 *)a))))->f4;
}

