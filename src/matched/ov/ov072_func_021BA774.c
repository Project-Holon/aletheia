/*
 * function: func_021BA774
 * address: 0x021BA774
 * packet: pkt_ov072_021BA774
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BBB3C 0x021BBB3C thumb ov072
 * call width: r1 is explicitly narrowed before the call, so extern takes u16.
 */
#include "../include/Obj03179.h"
typedef unsigned short u16;
extern unsigned short func_021BBB3C(char *p, int a, int b);
int func_021BA774(char *p, int i) {
 if (i>=2 && i<=10) return *(int *)((unsigned int)p+(i-2)*4+12);
 if (i==12) return ((struct Obj03179 *)p)->f3C;
 return func_021BBB3C(*(char * *)&((struct Obj03179 *)p)->f4,(u16)(((struct Obj03179 *)p)->f8),i);
}
