/*
 * function: ZUKAN_LIST_StartVBlankTask
 * address: 0x021BC298
 * packet: pkt_ov209_021BC298
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056A0 0x020056A0 thumb
 *   ZUKAN_LIST_VBlankTask 0x021BC2BC thumb ov209
 */
#include "../include/Obj00123.h"
extern void *func_020056A0(unsigned,unsigned,unsigned);extern void ZUKAN_LIST_VBlankTask(void *,char *);
void ZUKAN_LIST_StartVBlankTask(char *p){((struct Obj00123 *)p)->f4=func_020056A0((unsigned)ZUKAN_LIST_VBlankTask,(unsigned)p,0);}
