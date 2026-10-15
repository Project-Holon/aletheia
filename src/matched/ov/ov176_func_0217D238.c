/*
 * function: DIGITALCARDCHECK_IsRecord2Done
 * address: 0x0217D238
 * packet: pkt_ov176_0217D238
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_StepRecordWindow 0x021E777C thumb ov177
 */
#include "../include/Obj24424.h"
typedef unsigned char u8;
extern int WIFIBATTLEMATCH_VIEW_StepRecordWindow(void *);
int DIGITALCARDCHECK_IsRecord2Done(u8 *p){return WIFIBATTLEMATCH_VIEW_StepRecordWindow(((struct Obj24424 *)p)->f14);}
