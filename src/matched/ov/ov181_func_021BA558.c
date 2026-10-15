/*
 * unit: no
 * function: STAFF_ROLL_PrintRowText
 * address: 0x021BA558
 * packet: pkt_ov181_021BA558
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   STAFF_ROLL_PrintText 0x021BA4AC thumb ov181
 */
#include "../include/Obj14412.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void STAFF_ROLL_PrintText(char *,u8 *,void *,int);
void STAFF_ROLL_PrintRowText(char *p,u8 *q){if(q[9]==0)STAFF_ROLL_PrintText(p,q,BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj14412 *)p)->f2C4),192);else STAFF_ROLL_PrintText(p,q,BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj14412 *)p)->f2C4),194);}
