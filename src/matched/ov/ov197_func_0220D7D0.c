/*
 * function: func_0220D7D0
 * address: 0x0220D7D0
 * packet: pkt_ov197_0220D7D0
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x0220D7EE.
 * symbols:
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj08356.h"
struct WordSet;struct PrintSys;
struct Rec;
struct U16Vec;
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_0220D7D0(char *p){MSGDATA_Delete(((struct Obj08356 *)p)->fC);WORDSET_DeleteStrbufED04(*(struct WordSet * *)&((struct Obj08356 *)p)->f10);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj08356 *)p)->f18);STRBUF_Delete(((struct Obj08356 *)p)->f14);}
