/*
 * function: func_021FC568, func_021FC598
 * address: 0x021FC568
 * packet: pkt_ov135_021FC568
 * region: ov135
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj14170.h"
#include "../include/Obj23406.h"
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *);
void func_021FC568(char *p) {int i;for(i=0;i<10;i++) STRBUF_Delete(*(struct U16Vec **)((unsigned)p+i*4+0xb90));STRBUF_Delete(*(struct U16Vec * *)&((struct Obj14170 *)p)->fB88);STRBUF_Delete(*(struct U16Vec * *)&((struct Obj14170 *)p)->fB8C);}
int func_021FC598(char *p) {((struct Obj23406 *)p)->f28=1;return 2;}
