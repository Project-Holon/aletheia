/*
 * function: func_021F3ED0
 * address: 0x021F3ED0
 * packet: pkt_ov194_021F3ED0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj10810.h"
struct S02031140;extern void PRINTSYS_PrintStreamDelete(int);extern void TCBL_Destroy(struct S02031140 *);extern void MI_CpuFill8(void *,int,int);
void func_021F3ED0(unsigned char *p){if(((struct Obj10810 *)p)->f0)PRINTSYS_PrintStreamDelete(((struct Obj10810 *)p)->f0);TCBL_Destroy(*(struct S02031140 * *)&((struct Obj10810 *)p)->f4);MI_CpuFill8(p,0,16);}
