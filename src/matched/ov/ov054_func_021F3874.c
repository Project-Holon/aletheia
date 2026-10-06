/*
 * function: func_021F3874
 * address: 0x021F3874
 * packet: pkt_ov054_021F3874
 * region: ov054
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048F60 0x02048F60 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021F394C 0x021F394C data a4
 */
#include "../include/Obj03165.h"

typedef struct { int v[2]; } Pair;
extern Pair d_021F394C;
extern void *func_02048F60(unsigned int,unsigned int,unsigned int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021F3874(char *p) { Pair t=d_021F394C; int i; for(i=0;i<2;i++){ int *q=func_02048F60(0x7f,t.v[i],((struct Obj03165 *)p)->f0); ((int *)(p+0x18))[i]=q[0]; ((int *)(p+0x20))[i]=q[1]; func_020307B0(q); } }
