/*
 * function: UNION_MSG_CheckRegulationPrintEnd
 * address: 0x0217F794
 * packet: pkt_ov019_0217F794
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetMsgBg 0x02188C54 thumb ov021
 *   FIELD_MSGBG_GetPrintQue 0x021904A8 thumb ov021
 *   func_0201C6B4 0x0201C6B4 thumb
 */
#include "../include/Obj00033.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 FIELD_MSGBG_GetPrintQue(u32 *p);
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
u32 UNION_MSG_CheckRegulationPrintEnd(char *p,u32 a) { u32 h=FIELD_MSGBG_GetPrintQue((u32 *)FIELDMAP_GetMsgBg((u8 *)a)); if(((struct Obj00033 *)p)->f3530==0) return 1; return func_0201C6B4((void *)h); }
