/*
 * function: DIGITALCARDCHECK_IsRecordDone
 * address: 0x0217D188
 * packet: pkt_ov176_0217D188
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_StepMainWindow 0x021E64C8 thumb ov177
 */
#include "../include/Obj00053.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFIBATTLEMATCH_VIEW_StepMainWindow(void *);
int DIGITALCARDCHECK_IsRecordDone(u8 *p) {return WIFIBATTLEMATCH_VIEW_StepMainWindow(((struct Obj00053 *)p)->f10);}
