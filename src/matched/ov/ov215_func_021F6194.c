/*
 * function: EGG_DEMO_MENU_SetText
 * address: 0x021F6194
 * packet: pkt_ov215_021F6194
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * evidence: CCE4 return widened because original stores live r0 after call.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 */
#include "../include/Obj01590.h"
#include "../include/Obj02261.h"
typedef unsigned short u16;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
typedef unsigned int   u32;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(void *,unsigned,unsigned,void *,unsigned,unsigned,void *,unsigned,u16,u16);
void EGG_DEMO_MENU_SetText(char *object,char *p,unsigned entry)
{
    void *text,*words,*buffer;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj01590 *)p)->f58),15);
    if(((struct Obj01590 *)p)->f50) PRINTSYS_PrintStreamDelete(((struct Obj01590 *)p)->f50);
    if(((struct Obj01590 *)p)->f68) STRBUF_Delete(((struct Obj01590 *)p)->f68);
    text=func_02045EC0(((struct Obj01590 *)p)->f64,entry);
    words=GF_FONT_Create_EC64(((struct Obj01590 *)p)->f0);
    func_0201EE84(words,0,((struct Obj02261 *)object)->f4);
    buffer=STRBUF_Create(256,((struct Obj01590 *)p)->f0);
    ((struct Obj01590 *)p)->f68=buffer;
    func_0201F250(words,buffer,text);
    WORDSET_DeleteStrbufED04(words);
    STRBUF_Delete(text);
    ((struct Obj01590 *)p)->f50=PRINTSYS_PrintStream(((struct Obj01590 *)p)->f58,0,0,((struct Obj01590 *)p)->f68,((struct Obj01590 *)p)->f8,MSG_SPEED_GetWait(),((struct Obj01590 *)p)->f54,2,((struct Obj01590 *)p)->f0,15);
}
