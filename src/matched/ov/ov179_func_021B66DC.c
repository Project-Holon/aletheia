/*
 * unit: yes
 * function: CDEMO_SCENE_DispatchCommand, CDEMO_SCENE_CmdCount
 * address: 0x021B66DC
 * packet: pkt_ov179_021B66DC
 * region: ov179
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B6A40 0x021B6A40 data a4
 *   d_021B6A90 0x021B6A90 data a4
 */
#include "../include/Obj08293.h"
#include "../include/Obj10717.h"
extern int (*d_021B6A40[])(char *,int *);
extern const unsigned d_021B6A90[];
int CDEMO_SCENE_DispatchCommand(char *p) {
 int *q; int result; q=*(int * *)&((struct Obj10717 *)p)->f601C;
 result=d_021B6A40[q[0]](p,q);
 if(result) {
  q=*(int * *)&((struct Obj10717 *)p)->f601C;
  *(int * *)&((struct Obj10717 *)p)->f601C=q+d_021B6A90[q[0]];
 }
 return result;
}
int CDEMO_SCENE_CmdCount(char *p,int *q) {
 if(((struct Obj08293 *)p)->f6020==q[1]) { ((struct Obj08293 *)p)->f6020=0; return 2; }
 ((struct Obj08293 *)p)->f6020=((struct Obj08293 *)p)->f6020+1; return 0;
}
