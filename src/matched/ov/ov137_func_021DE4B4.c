/*
 * function: GURU2_RECEIPT_PrintMessage
 * address: 0x021DE4B4
 * packet: pkt_ov137_021DE4B4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj01414.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void *PRINTSYS_PrintStream(void *, int, int, void *, void *, int, void *, int, u16, u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
void GURU2_RECEIPT_PrintMessage(char *p, int message, int unused) {
    void *text;
    void *window;
    text = STRBUF_Create(0xb4, 0x72);
    MSGDATA_ReadString(((struct Obj01414 *)p)->f40, message, text);
    WORDSET_CopyTaggedText(((struct Obj01414 *)p)->f3C, ((struct Obj01414 *)p)->f5C, text);
    STRBUF_Delete(text);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj01414 *)p)->fD4), 0xf);
    BMP_MENUWORK_DrawWindow(((struct Obj01414 *)p)->fD4, 0, 1, 0xa);
    if (((struct Obj01414 *)p)->fF0 != 0)
        PRINTSYS_PrintStreamDelete(((struct Obj01414 *)p)->fF0);
    ((struct Obj01414 *)p)->fF0 = PRINTSYS_PrintStream(((struct Obj01414 *)p)->fD4, 0, 0, ((struct Obj01414 *)p)->f5C, ((struct Obj01414 *)p)->f38, 0, ((struct Obj01414 *)p)->fF4, 0, 0x72, 0xf);
    window = ((struct Obj01414 *)p)->fD4;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_020409B4(BMP_WIN_GetBgLayer(window));
}
