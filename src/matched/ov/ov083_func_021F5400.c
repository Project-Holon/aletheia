/*
 * function: GPOWER_EVENT_FreeListWork
 * address: 0x021F5400
 * packet: pkt_ov083_021F5400
 * region: ov083
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GPOWER_FreePowerTable 0x02010F8C thumb
 *   FLDMMDL_SysResumeMove 0x0216D9E4 thumb ov010
 */
#include "../include/Obj05165.h"
typedef unsigned char u8;
struct Rec;
struct U16Vec;
struct WordSet;
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void GPOWER_FreePowerTable(void *p);
extern u32 *FLDMMDL_SysResumeMove(void *c);
void GPOWER_EVENT_FreeListWork(u8 *p) { STRBUF_Delete(((struct Obj05165 *)p)->f38);STRBUF_Delete(((struct Obj05165 *)p)->f34);WORDSET_Delete(((struct Obj05165 *)p)->f2C);MSGDATA_Delete(((struct Obj05165 *)p)->f28);GPOWER_FreePowerTable(((struct Obj05165 *)p)->f30);FLDMMDL_SysResumeMove(((struct Obj05165 *)p)->f1C); }
