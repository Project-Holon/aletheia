/*
 * function: IRCBATTLEMATCH_OnChangeoverConnected
 * address: 0x021B9848
 * packet: pkt_ov100_021B9848
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj03737.h"
void IRCBATTLEMATCH_OnChangeoverConnected(int a)
{
 if(((struct Obj03737 *)a)->f24C!=5) {
  ((struct Obj03737 *)a)->fC80=1; ((struct Obj03737 *)a)->fC84=1; ((struct Obj03737 *)a)->fCA0=1;
 } else {
  if(((struct Obj03737 *)a)->fC7C!=0 && ((struct Obj03737 *)a)->fC98!=0) {
   ((struct Obj03737 *)a)->fC80=1; ((struct Obj03737 *)a)->fC84=1;
  }
 }
}
