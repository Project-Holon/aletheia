/*
 * function: func_021EA984
 * address: 0x021EA984
 * packet: pkt_ov170_021EA984
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EF480 0x021EF480 thumb ov170
 */
#include "../include/Obj23960.h"
#include "../include/Obj23961.h"
#define WORK(p) (*(char **)((p)+0x2C))
struct WinMgr;
extern void func_021ECB20(char *p, int f, int c);
extern void func_021ED888(char *,int);
extern int func_021EF480(struct WinMgr *mgr);
void func_021EA984(unsigned char *p) {
 switch(((struct Obj23961 *)(*(char * *)&((struct Obj23960 *)p)->f0))->f24) {
 case 0: func_021ECB20((char *)p,2,1); return;
 case 1: case 3: func_021ED888(WORK(p),0); func_021ECB20((char *)p,1,1); return;
 case 2: case 4: case 5:
  func_021ED888(WORK(p),0);
  if(func_021EF480(*(struct WinMgr **)(WORK(p)+0x74))==1) {
   func_021ECB20((char *)p,2,1); return;
  } else { func_021ECB20((char *)p,1,1); return; }
 }
}
