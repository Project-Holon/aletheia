/*
 * function: PDC_MSG_PrintMessage3
 * address: 0x021B694C
 * packet: pkt_ov098_021B694C
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   PDC_GetMyStatus 0x021B6148 thumb ov098
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PDC_MSG_StartPrint 0x021B6B8C thumb ov098
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj07935.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index); extern u32 PDC_GetMyStatus(u8 *); extern void WORDSET_SetSlotMyStatus(void *,u32,void *); extern void WORDSET_CopyTaggedText(void *,void *,void *); extern void PDC_MSG_StartPrint(int,int); extern void STRBUF_Delete(void *);
void PDC_MSG_PrintMessage3(u8 *p,u8 *q) { void *r; u32 t; r=func_02045EC0(((struct Obj07935 *)p)->f20,3); t=PDC_GetMyStatus(q); WORDSET_SetSlotMyStatus(((struct Obj07935 *)p)->f30,0,(void *)t); WORDSET_CopyTaggedText(((struct Obj07935 *)p)->f30,((struct Obj07935 *)p)->f2C,r); PDC_MSG_StartPrint((int)p,0); STRBUF_Delete(r); }
