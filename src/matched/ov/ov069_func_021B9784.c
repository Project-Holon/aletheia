/*
 * function: BSUBWAY_RECORD_LIST_FreeWork
 * address:  0x021B9784
 * packet:   pkt_ov069_021B9784
 * region:   ov069
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_02030EAC  0x02030EAC  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj01132.h"

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
struct Node;
struct Rec;
struct U16Vec;
struct WordSet;
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_02030EAC(struct Node *n);
extern void ARC_TOOL_DeleteHandle(void *p);

void BSUBWAY_RECORD_LIST_FreeWork(u8 *p)
{
    int i;

    func_020307B0(((struct Obj01132 *)p)->f8);
    for (i = 0; i < 7; i++) {
        STRBUF_Delete(*(void **)(p + i * 4 + 0x100));
    }
    STRBUF_Delete(((struct Obj01132 *)p)->fFC);
    WORDSET_DeleteStrbufED04(((struct Obj01132 *)p)->fF8);
    MSGDATA_Delete(((struct Obj01132 *)p)->fF4);
    func_02030EAC(((struct Obj01132 *)p)->f150);
    ARC_TOOL_DeleteHandle(((struct Obj01132 *)p)->f0);
}
