/*
 * function: IRC_RHYTHM_ClearBlendTask
 * address: 0x021B8F08
 * packet: pkt_ov104_021B8F08
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: BLDCNT at 04000050, the hardware halfword store at 021B8F16.
 */
#include "../include/Obj13750.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void IRC_RHYTHM_ClearBlendTask(void *task,u8 *p) {
 if(((struct Obj13750 *)p)->f8A8) {
  ((struct Obj13750 *)p)->f8A8=0;
  *(volatile u16 *)0x04000050=0;
 }
}
