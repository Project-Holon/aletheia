/*
 * function: HALL_OF_FAME_ExitText
 * address: 0x021B6474
 * packet: pkt_ov180_021B6474
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj05469.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct WordSet; struct Rec;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);
void HALL_OF_FAME_ExitText(char *p) {STRBUF_Delete(((struct Obj05469 *)p)->f9040);WORDSET_Delete(*(struct WordSet * *)&((struct Obj05469 *)p)->f903C);GF_FONT_Delete(((struct Obj05469 *)p)->f9034);GF_FONT_Delete(((struct Obj05469 *)p)->f9030);MSGDATA_Delete(*(struct Rec * *)&((struct Obj05469 *)p)->f9038);}
