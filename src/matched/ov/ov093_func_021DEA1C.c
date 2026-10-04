/*
 * unit: yes
 * function: func_021DEA1C, func_021DEA4C
 * address: 0x021DEA1C
 * packet: pkt_ov093_021DEA1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes store-return follower 0x021DEA4C.
 * symbols:
 *   d_021F16BC 0x021F16BC data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
#include "../include/Obj07820.h"
extern int func_021D775C(int);
extern int d_021F16BC;
extern void func_021D7704(int,int);
extern void *func_021C88A4(void *,int,int);
extern void func_021C88C8(void *,void *);
void func_021DEA1C(int a,void *b,int c) { unsigned char *p; if(c==func_021D775C(2)) { p=func_021C88A4(b,11,c); ((struct Obj07820 *)p)->f4=27; p[8]=c; p[20]=1; p[21]=1; func_021C88C8(b,p); } }
int *func_021DEA4C(int *p) { *p=2; return &d_021F16BC; }
