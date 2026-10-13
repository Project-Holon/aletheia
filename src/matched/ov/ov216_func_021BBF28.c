/*
 * function: func_021BBF28
 * address: 0x021BBF28
 * packet: pkt_ov216_021BBF28
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BCBA4 0x021BCBA4 thumb ov216
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 */
#include "../include/Obj03374.h"
struct PrintSys;
extern void func_021BCBA4(unsigned char *);
extern unsigned PRINTSYS_QUE_IsFinished(const struct PrintSys *);
int func_021BBF28(unsigned char *p){switch(((struct Obj03374 *)p)->f4){case 0:func_021BCBA4(p);(((struct Obj03374 *)p)->f4)++;break;case 1:if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj03374 *)p)->f12C)){((struct Obj03374 *)p)->f4=0;return 1;}break;}return 0;}
