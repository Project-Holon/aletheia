/*
 * function: FLDMMDL_MOVECODE_HasLeftOldGrid
 * address:  0x0219B494
 * packet:   pkt_0219B494
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
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_GetGridOldX(void *p);
extern int FLDMMDL_GetGridOldZ(void *p);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);

int FLDMMDL_MOVECODE_HasLeftOldGrid(int a)
{
if (FLDMMDL_GetGridNowX((void *)a) != FLDMMDL_GetGridOldX((void *)a)) {
    return 1;
}
if (FLDMMDL_GetGridNowZ((void *)a) != FLDMMDL_GetGridOldZ((void *)a)) {
    return 1;
}
return 0;
}

