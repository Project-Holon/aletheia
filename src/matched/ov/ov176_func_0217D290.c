/*
 * function: DIGITALCARDCHECK_DeleteRecord3
 * address: 0x0217D290
 * packet: pkt_ov176_0217D290
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_DeletePartyWindow 0x021E82BC thumb ov177
 */
#include "../include/Obj10703.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIFIBATTLEMATCH_VIEW_DeletePartyWindow(char *);
void DIGITALCARDCHECK_DeleteRecord3(u8 *p) {if(*(char * *)&((struct Obj10703 *)p)->f18) {WIFIBATTLEMATCH_VIEW_DeletePartyWindow(*(char * *)&((struct Obj10703 *)p)->f18);((struct Obj10703 *)p)->f18=0;}}
