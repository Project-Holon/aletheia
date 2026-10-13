/*
 * function: FLDMMDL_MOVE_StartFellowTracking
 * address:  0x0219BCC0
 * packet:   pkt_0219BCC0
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
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03525.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);

int FLDMMDL_MOVE_StartFellowTracking(int a, u8 *b, int c)
{
((struct Obj03525 *)((u8 *)(b)))->f1 = 1;
((struct Obj03525 *)((u8 *)(b)))->f2 = FLDMMDL_GetGridNowX((void *)c);
((struct Obj03525 *)((u8 *)(b)))->f4 = FLDMMDL_GetGridNowZ((void *)c);
((struct Obj03525 *)((u8 *)(b)))->f6 = 255;
((struct Obj03525 *)((u8 *)(b)))->f8 = c;
return 255;
}

