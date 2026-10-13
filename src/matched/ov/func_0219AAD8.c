/*
 * function: FLDMMDL_MOVECODE_InitRoutePatrolRoute15
 * address:  0x0219AAD8
 * packet:   pkt_0219AAD8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls FLDMMDL_MOVECODE_InitRoutePatrol(its own argument 1, 0x2, 0x1, 0x15) and returns nothing.
 *
 * symbols:
 *   FLDMMDL_MOVECODE_InitRoutePatrol  0x0219AA38  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FLDMMDL_MOVECODE_InitRoutePatrol(u32 a1, u32 a2, u32 a3, u32 a4);

void FLDMMDL_MOVECODE_InitRoutePatrolRoute15(u32 a1)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(a1, 0x2, 0x1, 0x15);
}

