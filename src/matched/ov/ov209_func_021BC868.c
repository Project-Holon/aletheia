/*
 * function: ZUKAN_LIST_DeleteFontAndPrinter
 * address: 0x021BC868
 * packet: pkt_ov209_021BC868
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj00088.h"
struct U16Vec;struct PrintSys;struct WordSet;struct Rec;extern void STRBUF_Delete(struct U16Vec *);extern void PRINTSYS_QUE_Delete(struct PrintSys *);extern void WORDSET_DeleteStrbufED04(struct WordSet *);extern void GF_FONT_Delete(void *);extern void MSGDATA_Delete(struct Rec *);
void ZUKAN_LIST_DeleteFontAndPrinter(char *p){STRBUF_Delete(*(struct U16Vec * *)&((struct Obj00088 *)p)->f44);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj00088 *)p)->f48);WORDSET_DeleteStrbufED04(*(struct WordSet * *)&((struct Obj00088 *)p)->f40);GF_FONT_Delete(((struct Obj00088 *)p)->f38);MSGDATA_Delete(*(struct Rec * *)&((struct Obj00088 *)p)->f3C);}
