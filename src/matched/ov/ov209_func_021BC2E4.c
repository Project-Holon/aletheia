/*
 * function: ZUKAN_LIST_StartHBlankTask
 * address: 0x021BC2E4
 * packet: pkt_ov209_021BC2E4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02005624 0x02005624 thumb
 *   ZUKAN_LIST_HBlankTask 0x021BC308 thumb ov209
 */
#include "../include/Obj00123.h"
extern void *func_02005624(unsigned,unsigned,unsigned);extern void ZUKAN_LIST_HBlankTask(void);
void ZUKAN_LIST_StartHBlankTask(char *p){((struct Obj00123 *)p)->f8=func_02005624((unsigned)ZUKAN_LIST_HBlankTask,(unsigned)p,0);}
