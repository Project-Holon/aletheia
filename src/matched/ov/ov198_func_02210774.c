/*
 * function: B_PLIST_MAIN_DeleteTextResources
 * address: 0x02210774
 * packet: pkt_ov198_02210774
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj06656.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec;struct WordSet;struct PrintSys;struct U16Vec;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern void STRBUF_Delete(struct U16Vec *);
void B_PLIST_MAIN_DeleteTextResources(u8 *p) { MSGDATA_Delete(*(struct Rec * *)&((struct Obj06656 *)p)->f1EA0);GF_FONT_Delete(((struct Obj06656 *)p)->f1E9C);WORDSET_Delete(*(struct WordSet * *)&((struct Obj06656 *)p)->f1EA4);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj06656 *)p)->f1EAC);STRBUF_Delete(*(struct U16Vec * *)&((struct Obj06656 *)p)->f1EA8); }
