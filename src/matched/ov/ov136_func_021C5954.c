/*
 * function: MB_SEQ_DeleteMessageResources
 * address:  0x021C5954
 * packet:   pkt_ov136_021C5954
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_DeleteMessageResources 0x021C5954 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj10601.h"
typedef unsigned char u8;
struct Rec;
struct U16Vec;
struct WordSet;
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
void MB_SEQ_DeleteMessageResources(u8 *p)
{
    STRBUF_Delete(((struct Obj10601 *)p)->f1D8);
    func_0201ED04(((struct Obj10601 *)p)->f1D4);
    MSGDATA_Delete(((struct Obj10601 *)p)->f1D0);
}
