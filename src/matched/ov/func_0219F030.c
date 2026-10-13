/*
 * function: func_0219F030
 * address:  0x0219F030
 * packet:   pkt_0219F030
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
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);

int func_0219F030(void *a, u32 b, u32 c, u32 d)
{
FLDMMDL_SetStatusBitVanish((unsigned int *)a, 1);
return (int)FLDMMDL_SetMoveBit(a, (1 << 15));
}

