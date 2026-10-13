/*
 * function: FLDMMDL_ACMD_EndCmd
 * address:  0x02197F5C
 * packet:   pkt_02197F5C
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
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);

int FLDMMDL_ACMD_EndCmd(u32 a, u32 b, u32 c, u32 d)
{
FLDMMDL_SetMoveBit((void *)a, (1 << 10));
return 0;
}

