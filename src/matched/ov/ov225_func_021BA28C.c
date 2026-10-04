/*
 * function: func_021BA28C
 * address: 0x021BA28C
 * packet: pkt_ov225_021BA28C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj08469.h"
#include "../include/Obj26153.h"
struct PrintSys;struct Descriptor;struct CharBuf;extern void func_0201C6EC(struct PrintSys *);extern void *func_02045770(struct Descriptor *);extern void func_02043B5C(struct CharBuf *,unsigned char),func_02045334(struct Descriptor *);
void func_021BA28C(char *p){func_0201C6EC(*(struct PrintSys * *)&((struct Obj26153 *)(*(char * *)&((struct Obj08469 *)p)->f0))->f18);func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj08469 *)p)->f14),0);func_02045334(*(struct Descriptor * *)&((struct Obj08469 *)p)->f14);((struct Obj08469 *)p)->f1C=0;}
