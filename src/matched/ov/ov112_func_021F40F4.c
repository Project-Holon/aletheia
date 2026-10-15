/*
 * function: MUSICAL_MCSS_DrawLabel
 * address: 0x021F40F4
 * packet: pkt_ov112_021F40F4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment at 0x021F427E; next code at 0x021F4280.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02049B40 0x02049B40 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_SetString 0x02045924 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 */
#include "../include/Obj00669.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u32 pad:9; u32 a:7; u32 b:5; u32 c:6; u32 tail:5; } Input;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
struct Strbuf;
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BG_SYS_PushTile(u32);
void MUSICAL_MCSS_DrawLabel(u8 *p)
{
    void *buf;
    void *t;
    void *f;
    void *b;
    ((struct Obj00669 *)p)->f54=(void *)BMP_WIN_Create(1,24,22,8,2,10,1);
    ((struct Obj00669 *)p)->f58=(void *)BMP_WIN_Create(1,1,1,30,2,10,1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00669 *)p)->f54),0);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00669 *)p)->f58),0);
    ((struct Obj00669 *)p)->f5C=GF_FONT_Create(23,3,0,0,((struct Obj00669 *)p)->f0);
    ((struct Obj00669 *)p)->f60=GF_FONT_Create(23,0,0,0,((struct Obj00669 *)p)->f0);
    func_02049B40(23,5,0,320,32,((struct Obj00669 *)p)->f0);
    buf=STRBUF_Create(128,((struct Obj00669 *)p)->f0);
    t=WORDSET_CreateDefault(((struct Obj00669 *)p)->f0);
    f=func_02045B38(0,2,78,((struct Obj00669 *)p)->f0);
    b=func_02045EC0(f,0);
    WORDSET_SetSlotNumber(t,0,(*(Input * *)&((struct Obj00669 *)p)->f4)->a,2,2,1);
    WORDSET_SetSlotNumber(t,1,(*(Input * *)&((struct Obj00669 *)p)->f4)->b,2,2,1);
    WORDSET_SetSlotNumber(t,2,(*(Input * *)&((struct Obj00669 *)p)->f4)->c,2,2,1);
    WORDSET_CopyTaggedText(t,buf,b);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00669 *)p)->f54),0,0,buf,((struct Obj00669 *)p)->f5C,3424);
    STRBUF_Delete(buf);
    STRBUF_Delete(b);
    WORDSET_DeleteStrbufED04(t);
    MSGDATA_Delete(f);
    buf=STRBUF_Create(37,((struct Obj00669 *)p)->f0);
    STRBUF_SetString(buf,(const u16 *)(*(u8 * *)&((struct Obj00669 *)p)->f4+356));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00669 *)p)->f58),0,0,buf,((struct Obj00669 *)p)->f60,15424);
    STRBUF_Delete(buf);
    BMP_WIN_TransferChars(((struct Obj00669 *)p)->f54);
    BMP_WIN_MakeScreen(((struct Obj00669 *)p)->f54);
    BMP_WIN_TransferChars(((struct Obj00669 *)p)->f58);
    BMP_WIN_MakeScreen(((struct Obj00669 *)p)->f58);
    BG_SYS_PushTile(1);
}
