/*
 * function: FLDMMDL_RAIL_MOVE_GetLocationAttr
 * address:  0x0219D724
 * packet:   pkt_0219D724
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FLDMMDL_SysGetNogridMapper (0x0216D530) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb
 *   FIELD_NOGRID_MAPPER_GetAttribute  0x021BB3C4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetNogridMapper(u32);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FIELD_NOGRID_MAPPER_GetAttribute(u8 *p, char *a1);

int FLDMMDL_RAIL_MOVE_GetLocationAttr(u32 a, char *b)
{
return FIELD_NOGRID_MAPPER_GetAttribute((u8 *)FLDMMDL_SysGetNogridMapper((u32)FLDMMDL_GetMmdlSys((void *)a)), b);
}

