/*
 * function: WF2DMAP_OBJDRAW_GetOwnerPos
 * address: 0x021C5914
 * packet: pkt_ov127_021C5914
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WF2DMAP_OBJ_GetCurrentPos 0x021C4ADC thumb ov127
 */
#include "../include/Obj23055.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { short x,y; } Pos;
extern Pos WF2DMAP_OBJ_GetCurrentPos(char *);
void WF2DMAP_OBJDRAW_GetOwnerPos(char *p,short *x,short *y) { Pos a=WF2DMAP_OBJ_GetCurrentPos(*(char * *)&((struct Obj23055 *)p)->f0); *x=a.x; *y=a.y; }
