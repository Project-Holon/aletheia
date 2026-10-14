/*
 * function: ZUKAN_LIST_DeleteFrameList
 * address: 0x021BCB60
 * packet: pkt_ov209_021BCB60
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FRAME_LIST_Delete 0x021B796C thumb ov067
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj00088.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S;struct U16Vec;
extern void FRAME_LIST_Delete(struct S *);extern void STRBUF_Delete(struct U16Vec *);
void ZUKAN_LIST_DeleteFrameList(char *p) { u32 i;FRAME_LIST_Delete(*(struct S * *)&((struct Obj00088 *)p)->fC2C);for(i=0;i<649;i++){struct U16Vec *q=*(struct U16Vec **)((u32)p+i*4+76);if(q)STRBUF_Delete(q);} }
