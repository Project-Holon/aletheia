/*
 * function: BR_BTN_DeleteRecord
 * address: 0x021FACE0
 * packet: pkt_ov186_021FACE0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   memset 0x02082BCC arm
 */
#include "../include/Obj10784.h"
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *);
extern void BR_BTN_DeleteObject(char *p);
extern void *memset(void *,int,unsigned);
void BR_BTN_DeleteRecord(char *p) { if(((struct Obj10784 *)p)->f0!=0){STRBUF_Delete(*(struct U16Vec * *)&((struct Obj10784 *)p)->f40);BR_BTN_DeleteObject(((struct Obj10784 *)p)->f8);memset(p,0,0x44);} }
