/*
 * function: func_0216E544
 * address: 0x0216E544
 * packet: pkt_ov010_0216E544
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216E4EC 0x0216E4EC thumb ov010
 *   func_0216D67C 0x0216D67C thumb ov010
 *   func_0216E490 0x0216E490 thumb ov010
 */
#include "../include/Obj19139.h"

typedef struct { int x,y,z; } Vec;
extern int func_0216E4EC(int a0, int a1);
extern void *func_0216D67C(void *);
extern int func_0216E490(int a0);
int func_0216E544(void *a, Vec *out) { int i; Vec *p; unsigned int base; i=func_0216E4EC((int)a, (int)out); if(i!=30) { base=((struct Obj19139 *)((char *)func_0216D67C(a)))->f2C; p=(Vec *)(base+i*12); if(func_0216E490((int)p)) { *out=*p; return 1; } } return 0; }
