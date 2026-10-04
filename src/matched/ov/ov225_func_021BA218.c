/*
 * function: func_021BA218
 * address: 0x021BA218
 * packet: pkt_ov225_021BA218
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj26149.h"
#include "../include/Obj26150.h"
struct PrintSys;struct Descriptor;extern void func_0201C6EC(struct PrintSys *),func_020452E8(struct Descriptor *);
void func_021BA218(char *p){unsigned char i;func_0201C6EC(*(struct PrintSys * *)&((struct Obj26150 *)(*(char * *)&((struct Obj26149 *)p)->f0))->f18);for(i=0;i<2;i++){*(unsigned *)((unsigned)p+i*4+24)=0;func_020452E8(*(struct Descriptor **)((unsigned)p+i*4+16));}}
