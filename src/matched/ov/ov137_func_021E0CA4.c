/*
 * function: func_021E0CA4
 * address: 0x021E0CA4
 * packet: pkt_ov137_021E0CA4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E078C 0x021E078C thumb ov137
 */
#include "../include/Obj08224.h"
#include "../include/Obj08225.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021E078C(char *,char *);
int func_021E0CA4(char *p) { char *q; q=*(char * *)&((struct Obj08224 *)p)->f10; ((struct Obj08225 *)q)->f38=4096; ((struct Obj08225 *)q)->f3C=4096; ((struct Obj08225 *)q)->f40=4096; ((struct Obj08225 *)q)->f54=0xc0000; func_021E078C(*(char * *)&((struct Obj08224 *)p)->f14,q); ((struct Obj08224 *)p)->fC=0x8000; ((struct Obj08224 *)p)->f0=1; return 0; }
