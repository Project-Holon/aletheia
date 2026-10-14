/*
 * function: GURU2_RECEIPT_FreeStrings
 * address: 0x021DD380
 * packet: pkt_ov137_021DD380
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GURU2_RECEIPT_FreeCharBuffer 0x021DE6DC thumb ov137
 *   func_020307B0 0x020307B0 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj08210.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern void GURU2_RECEIPT_FreeCharBuffer(u8 *);
extern u32 func_020307B0(void *p);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
void GURU2_RECEIPT_FreeStrings(u8 *p) {int i;GURU2_RECEIPT_FreeCharBuffer(p);func_020307B0(((struct Obj08210 *)p)->f24);for(i=0;i<5;i++)STRBUF_Delete(*(void **)((u32)p+i*4+68));STRBUF_Delete(((struct Obj08210 *)p)->f60);STRBUF_Delete(((struct Obj08210 *)p)->f5C);}
