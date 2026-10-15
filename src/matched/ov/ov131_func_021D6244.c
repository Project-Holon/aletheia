/*
 * function: P_STATUS_PrintWordSetMsgRight
 * address: 0x021D6244
 * packet: pkt_ov131_021D6244
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   STRBUF_Create 0x020457B0 arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 */
#include "../include/Obj06482.h"
typedef unsigned int   u32;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned short u16;
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void P_STATUS_PrintWordSetMsgRight(unsigned char *p,int a,void *b,int c,unsigned short d,short e,unsigned short f) {
 void *t=STRBUF_Create(16,((struct Obj06482 *)p)->f0);
 void *s=func_02045EC0(((struct Obj06482 *)p)->f7C,c);
 int w;
 WORDSET_CopyTaggedText(b,t,s);
 w=func_0201D304(t,((struct Obj06482 *)p)->f80,0);
 PRINTSYS_PrintQueColor(((struct Obj06482 *)p)->f84,a,(short)(d-w),e,(u32)t,((struct Obj06482 *)p)->f80,f);
 STRBUF_Delete(s);
 STRBUF_Delete(t);
}
