/*
 * function: INTRO_MSG_Main
 * address: 0x021BF228
 * packet: pkt_ov204_021BF228
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj14621.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Tcbl;struct PrintSys;
extern void TCBL_Main(struct Tcbl*);
extern u32 PRINTSYS_QUE_Main(struct PrintSys*);
void INTRO_MSG_Main(u8*p){TCBL_Main(*(struct Tcbl* *)&((struct Obj14621 *)p)->f18);PRINTSYS_QUE_Main(*(struct PrintSys* *)&((struct Obj14621 *)p)->f4);}
