/*
 * function: func_021DABB0
 * address: 0x021DABB0
 * packet: pkt_ov119_021DABB0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E5098 0x021E5098 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAB34 0x021DAB34 thumb ov119
 */
#include "../include/Obj00001.h"
extern void func_021E5098(char *,int);
extern void func_021E4E64(int a, char *p, int b);
extern void func_021D8E84(void *p, int v);
extern void func_021DAB34(char *);
void func_021DABB0(char *p) {
 func_021E5098(p,((struct Obj00001 *)p)->fF2C-1);
 if(((struct Obj00001 *)p)->fF2C>25) {
  func_021E4E64(*(int *)&((struct Obj00001 *)p)->f828,p,0);
  func_021D8E84(p,(int)func_021DAB34);
 }
}
