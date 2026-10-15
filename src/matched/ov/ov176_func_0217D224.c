/*
 * function: DIGITALCARDCHECK_DeleteRecord2
 * address: 0x0217D224
 * packet: pkt_ov176_0217D224
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_DeleteRecordWindow 0x021E7710 thumb ov177
 */
#include "../include/Obj10702.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(char *);
void DIGITALCARDCHECK_DeleteRecord2(int *p) {if(*(char * *)&((struct Obj10702 *)p)->f14) {WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(*(char * *)&((struct Obj10702 *)p)->f14);((struct Obj10702 *)p)->f14=0;}}
