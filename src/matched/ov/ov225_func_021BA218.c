/*
 * function: MANUAL_COMMON_DeleteTouchbarSlots
 * address: 0x021BA218
 * packet: pkt_ov225_021BA218
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj26149.h"
#include "../include/Obj26150.h"
struct PrintSys;struct Descriptor;extern void PRINTSYS_QUE_Clear(struct PrintSys *),BMP_WIN_Delete(struct Descriptor *);
void MANUAL_COMMON_DeleteTouchbarSlots(char *p){unsigned char i;PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26150 *)(*(char * *)&((struct Obj26149 *)p)->f0))->f18);for(i=0;i<2;i++){*(unsigned *)((unsigned)p+i*4+24)=0;BMP_WIN_Delete(*(struct Descriptor **)((unsigned)p+i*4+16));}}
