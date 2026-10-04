/*
 * function: func_021DF404
 * address: 0x021DF404
 * packet: pkt_ov170_021DF404
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02007898 0x02007898 thumb
 *   func_0216C0C0 0x0216C0C0 thumb ov010
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06546.h"
#include "../include/Obj23861.h"
#include "../include/Obj23862.h"
#include "../include/Obj23863.h"
#include "../include/Obj23864.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void func_02007898(void *save, u32 box, const void *src);
extern int func_0216C0C0(int);
extern void func_02045808(struct U16Vec *);
extern void func_020307B0(void *);
int func_021DF404(u8 *p){char **q;q=*(char ** *)&((struct Obj06546 *)p)->fC;if(((struct Obj23861 *)(*q))->f1C==0)func_02007898(((struct Obj23862 *)(*(char * *)&((struct Obj06546 *)p)->f0))->f4,p[0x14],((struct Obj23863 *)(*q))->f20);((struct Obj06546 *)p)->f10=((struct Obj23864 *)(*q))->f1C;func_0216C0C0((int)*q);func_02045808((struct U16Vec *)q[1]);func_020307B0(((struct Obj06546 *)p)->fC);return 0;}
