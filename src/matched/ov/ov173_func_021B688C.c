/*
 * function: POKE_SUMMARY_MAIN_DeleteText
 * address: 0x021B688C
 * packet: pkt_ov173_021B688C
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj06565.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec;
struct U16Vec;
struct WordSet;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void STRBUF_Delete(struct U16Vec *vec);
void POKE_SUMMARY_MAIN_DeleteText(char *p) { MSGDATA_Delete(((struct Obj06565 *)p)->f44); WORDSET_Delete(((struct Obj06565 *)p)->f48); STRBUF_Delete(((struct Obj06565 *)p)->f4C); STRBUF_Delete(((struct Obj06565 *)p)->f50); STRBUF_Delete(((struct Obj06565 *)p)->f54); }
