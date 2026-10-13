/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_InitTrail
 * address: 0x021B9110
 * packet: pkt_ov103_021B9110
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   IRC_COMPATIBLE_TOUCH_TEST_GetSprite 0x021B793C thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_InitTrailSprite 0x021B9184 thumb ov103
 */
#include "../include/Obj07985.h"
typedef unsigned char u8;
extern void MI_CpuFill8(void *,int,int);
extern int IRC_COMPATIBLE_TOUCH_TEST_GetSprite(u8 *p, int i);
struct Obj;
extern void IRC_COMPATIBLE_TOUCH_TEST_InitTrailSprite(u8 *p, struct Obj *q, int v, u8 w);
void IRC_COMPATIBLE_TOUCH_TEST_InitTrail(u8 *p,void *q,int a,int b,int c,u8 d) {
 int i;
 MI_CpuFill8(p,0,0x590);
 ((struct Obj07985 *)p)->f580=a;((struct Obj07985 *)p)->f584=b;
 ((struct Obj07985 *)p)->f588=0;((struct Obj07985 *)p)->f58C=10;
 for(i=0;i<32;i++)IRC_COMPATIBLE_TOUCH_TEST_InitTrailSprite(p+i*0x2c,(struct Obj *)IRC_COMPATIBLE_TOUCH_TEST_GetSprite(q,c+i),b,d);
}
