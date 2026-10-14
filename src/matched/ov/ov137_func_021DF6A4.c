/*
 * function: GURU2_MAIN_StateShowEndMessage
 * address: 0x021DF6A4
 * packet: pkt_ov137_021DF6A4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GURU2_MAIN_PrintMessage 0x021E0130 thumb ov137
 */
#include "../include/Obj23763.h"
typedef unsigned char u8;extern void GURU2_MAIN_PrintMessage(u8 *,int);
int GURU2_MAIN_StateShowEndMessage(u8 *p){GURU2_MAIN_PrintMessage(p,12);((struct Obj23763 *)p)->f0=46;return 0;}
