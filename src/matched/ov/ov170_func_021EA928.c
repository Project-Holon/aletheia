/*
 * function: func_021EA928
 * address: 0x021EA928
 * packet: pkt_ov170_021EA928
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02007A80 0x02007A80 thumb
 *   func_021E8F50 0x021E8F50 thumb ov170
 *   func_021E949C 0x021E949C thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23959.h"
#define WORK(p) (*(char **)((p)+0x2C))
extern int func_02007A80(void *,unsigned);
extern int func_021E8F50(char *p, int v);
extern int func_021E949C(char *p, int a, int b);
int func_021EA928(unsigned char *p,int a) {
 if((unsigned char)WORK(p)[0xA17C]<=4 || ((unsigned char)WORK(p)[0xA17C]==5 && func_02007A80(((struct Obj23959 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f4,2)==0))
  WORK(p)[0xA17B]=((unsigned char)WORK(p)[0xA17C]-1)*4+a-1;
 else WORK(p)[0xA17B]=((unsigned char)WORK(p)[0xA17C]-1)*4+a;
 return func_021E949C((char *)p,a,func_021E8F50((char *)p,0x66));
}
