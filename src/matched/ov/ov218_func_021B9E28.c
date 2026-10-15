/*
 * function: UN_SELECT_DeleteFrameList
 * address: 0x021B9E28
 * packet: pkt_ov218_021B9E28
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   FRAME_LIST_Delete 0x021B796C thumb ov067
 */
#include "../include/Obj14772.h"
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
struct U16Vec;struct S; extern void STRBUF_Delete(struct U16Vec *);extern void FRAME_LIST_Delete(struct S *);
void UN_SELECT_DeleteFrameList(char *p){int i;for(i=0;i<130;i++)STRBUF_Delete(*(struct U16Vec **)(((struct Obj14772 *)p)->f28+i*4+0x2c));FRAME_LIST_Delete(*(struct S * *)&((struct Obj14772 *)p)->f2C);}
