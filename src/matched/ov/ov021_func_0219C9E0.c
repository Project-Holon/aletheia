/*
 * function: FLDMMDL_BLACT_GetActorSize
 * address:  0x0219C9E0
 * packet:   pkt_ov021_0219C9E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   sBlactDrawSize  0x021D75D0  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetObjCodeParam(void *p);
extern u16 sBlactDrawSize[][2];

void FLDMMDL_BLACT_GetActorSize(u32 a, u16 *x, u16 *y)
{
    u8 *d = FLDMMDL_GetObjCodeParam((void *)a);
    u16 *t = sBlactDrawSize[d[7]];
    *x = t[0];
    *y = t[1];
}
