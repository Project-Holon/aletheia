/*
 * function: func_021FE178
 * address: 0x021FE178
 * packet: pkt_ov135_021FE178
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj08190.h"
#include "../include/Obj23413.h"
struct U16Vec;
extern void func_020307B0(void *);extern void func_02045808(struct U16Vec *);
void func_021FE178(char *p) {func_020307B0(((struct Obj23413 *)(*(char * *)&((struct Obj08190 *)p)->fE00))->f14);func_020307B0(((struct Obj08190 *)p)->fE00);func_02045808(*(struct U16Vec * *)&((struct Obj08190 *)p)->fB88);func_02045808(*(struct U16Vec * *)&((struct Obj08190 *)p)->fB8C);}
