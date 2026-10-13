/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_HandleAbort
 * address: 0x021B8A44
 * packet: pkt_ov103_021B8A44
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 *   IRC_COMPATIBLE_TOUCH_TEST_SetFinished 0x021B8358 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_PrintMessage 0x021B8138 thumb ov103
 *   COMPATIBLE_IRC_SYS_StepShareValue 0x021B630C thumb ov101
 */
#include "../include/Obj06369.h"
#include "../include/Obj22204.h"
#include "../include/Obj22205.h"
#include "../include/Obj22206.h"
#include "../include/Obj22207.h"
#include "../include/Obj22208.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int COMPATIBLE_IRC_SYS_GetValueDifference(int *);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetFinished(u8 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(u8 *p, void *q, int c, int x, s16 y);
extern int COMPATIBLE_IRC_SYS_StepShareValue(int *,int);
void IRC_COMPATIBLE_TOUCH_TEST_HandleAbort(u8 *p,u16 *s) {
 switch(*s) {
 case 0:
  if(COMPATIBLE_IRC_SYS_GetValueDifference(*(int * *)&((struct Obj22204 *)(*(u8 * *)&((struct Obj06369 *)p)->fB0C))->f4)>0)*s=1;
  else if(COMPATIBLE_IRC_SYS_GetValueDifference(*(int * *)&((struct Obj22205 *)(*(u8 * *)&((struct Obj06369 *)p)->fB0C))->f4)<0) {(*(u8 **)(p+0xb0c))[16]=0;((struct Obj22206 *)(*(u8 * *)&((struct Obj06369 *)p)->fB0C))->fC=2;IRC_COMPATIBLE_TOUCH_TEST_SetFinished(p);}
  break;
 case 1:(*(u8 **)(p+0xb0c))[16]=0;((struct Obj22207 *)(*(u8 * *)&((struct Obj06369 *)p)->fB0C))->fC=2;*s=2;break;
 case 2:IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(p+0x184,p+0x174,6,0,0);*s=3;break;
 case 3:if(COMPATIBLE_IRC_SYS_StepShareValue(*(int * *)&((struct Obj22208 *)(*(u8 * *)&((struct Obj06369 *)p)->fB0C))->f4,6))*s=4;break;
 case 4:IRC_COMPATIBLE_TOUCH_TEST_SetFinished(p);break;
 }
}
