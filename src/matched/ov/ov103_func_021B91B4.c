/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_RecordStroke
 * address: 0x021B91B4
 * packet: pkt_ov103_021B91B4
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * volatile: 021B91E6 and 021B91EC reread the halfword at offset 0x50.
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld 0x021B8D9C thumb ov103
 */
#include "../include/Obj03741.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(u32 *,u32 *);
int IRC_COMPATIBLE_TOUCH_TEST_RecordStroke(u8 *p,u32 *rect) {
 u16 n;
 if(((struct Obj03741 *)p)->f5C)return 1;
 if((((struct Obj03741 *)p)->f54)++>150) {
  IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(rect,(u32 *)(p+0x48));
  ((struct Obj03741 *)p)->f5C=1;
  return 1;
 }
 if(((struct Obj03741 *)p)->f58==0) {
  n=*(volatile u16 *)&((struct Obj03741 *)p)->f50;
  (*(volatile u16 *)&((struct Obj03741 *)p)->f50)++;
  IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(rect,(u32 *)(p+n*8));
 }
 if((((struct Obj03741 *)p)->f58)++>15)((struct Obj03741 *)p)->f58=0;
 return 0;
}
