/*
 * function: func_06899DD8
 * address: 0x06899DD8
 * packet: pkt_ov095_06899DD8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045808  0x02045808  arm
 *   func_022021F4  0x022021F4  thumb
 */
#include "../../matched/include/Obj10162.h"
typedef unsigned int u32;
extern void func_0201C4C0(u32);
extern void func_02045808(u32);
extern void func_022021F4(u32);
extern void func_020307B0(void *);
void func_06899DD8(unsigned char *p) {
 func_0201C4C0(((struct Obj10162 *)p)->f14);
 func_02045808(((struct Obj10162 *)p)->fC);
 func_022021F4(((struct Obj10162 *)p)->fB0);
 func_020307B0(p);
}
