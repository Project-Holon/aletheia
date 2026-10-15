/*
 * function: STAFF_ROLL_DeleteText
 * address: 0x021B9B6C
 * packet: pkt_ov181_021B9B6C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x021B9B96.
 * symbols:
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj08302.h"
struct Rec;
struct U16Vec;
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
void STAFF_ROLL_DeleteText(char *p){GF_FONT_Delete(((struct Obj08302 *)p)->fAC);GF_FONT_Delete(((struct Obj08302 *)p)->fA8);STRBUF_Delete(((struct Obj08302 *)p)->fB4);MSGDATA_Delete(((struct Obj08302 *)p)->fB0);}
