/*
 * function: PDW_POSTMAN_DeleteListWin
 * address:  0x021B7494
 * packet:   pkt_021B7494
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   BG_SYS_PushTile  0x020409B4  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_Delete  0x0201ED04  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04890.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Rec;
struct U16Vec;
struct WordSet;
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 func_020307B0(void *p);
extern void BG_SYS_PushTile(u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern int FIELD_MSGBG_DeleteMsgWin(void *a);
extern void FIELD_MSGBG_ClearMsgWin(u8 *p);

int PDW_POSTMAN_DeleteListWin(void *a)
{
FIELD_MSGBG_ClearMsgWin((u8 *)(((struct Obj04890 *)((u8 *)(a)))->fC));
FIELD_MSGBG_DeleteMsgWin((void *)(((struct Obj04890 *)((u8 *)(a)))->fC));
BG_SYS_PushTile(1);
STRBUF_Delete((struct U16Vec *)(((struct Obj04890 *)((u8 *)(a)))->f18));
STRBUF_Delete((struct U16Vec *)(((struct Obj04890 *)((u8 *)(a)))->f1C));
WORDSET_Delete((struct WordSet *)(((struct Obj04890 *)((u8 *)(a)))->f14));
MSGDATA_Delete((struct Rec *)(((struct Obj04890 *)((u8 *)(a)))->f8));
return func_020307B0(a);
}

