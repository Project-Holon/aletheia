/*
 * function: func_0216E51C
 * address: 0x0216E51C
 * packet: pkt_ov010_0216E51C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0216E4EC 0x0216E4EC thumb ov010
 *   func_0216D67C 0x0216D67C thumb ov010
 *   func_0216E490 0x0216E490 thumb ov010
 */
#include "../include/Obj19138.h"

extern int func_0216E4EC(int a0, int a1);
extern void *func_0216D67C(void *);
extern int func_0216E490(void *);
int func_0216E51C(void *a, int a1) { int i; unsigned int base; i=func_0216E4EC((int)a, a1); if(i!=30) { base=((struct Obj19138 *)((char *)func_0216D67C(a)))->f2C; return func_0216E490((void *)(base+i*12)); } return 0; }
