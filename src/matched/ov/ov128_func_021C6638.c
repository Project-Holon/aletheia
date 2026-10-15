/*
 * function: func_021C6638
 * address: 0x021C6638
 * packet: pkt_ov128_021C6638
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   WF2DMAP_TOUCH_UpdateSlots 0x021CA478 thumb ov128
 *   TCBL_Main 0x020310C4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 */
#include "../include/Obj06477.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
struct Tcbl;
extern void WF2DMAP_TOUCH_UpdateSlots(char *p);
extern void TCBL_Main(struct Tcbl *p);
extern void CLACT_DrawSystem(void);
void func_021C6638(u8 *p) { if(((struct Obj06477 *)p)->f34) { PRINTSYS_QUE_Main(((struct Obj06477 *)p)->f34);WF2DMAP_TOUCH_UpdateSlots((char *)p); } if(((struct Obj06477 *)p)->f28) TCBL_Main(((struct Obj06477 *)p)->f28);CLACT_DrawSystem(); }
