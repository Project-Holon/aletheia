/*
 * function: BR_POKESEARCH_UpdatePrint
 * address: 0x021FFE34
 * packet: pkt_ov186_021FFE34
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC830 0x021FC830 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj24875.h"
struct PrintSys;extern int func_021FC830(void *);extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);
unsigned BR_POKESEARCH_UpdatePrint(char *p) {unsigned r=1;int i;for(i=0;i<9;i++){void *v=*(void **)((unsigned)p+i*4+64);if(v)r &= func_021FC830(v);}return r & PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj24875 *)p)->f3C);}
