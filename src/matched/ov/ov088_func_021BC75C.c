/*
 * function: STARTMENU_ConfigPromptDrawQuestion
 * address:  0x021BC75C
 * packet:   pkt_ov088_021BC75C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   STARTMENU_ConfigPromptHighlightChoice  0x021BC870  thumb  ov088
 */
#include "../include/Obj06206.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

struct Cfg;
struct CharBuf;
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void STARTMENU_ConfigPromptHighlightChoice(u8 *p);

#define W(o) (*(u32 *)(p + (o)))

void STARTMENU_ConfigPromptDrawQuestion(u8 *p)
{
    u32 arc;
    u32 s;
    u8 i;
    u8 *q;

    arc = (u32)func_02045B38(0, 2, 0xab, 0x39);
    p[0] = 0;
    W(0xc) = BMP_WIN_Create((int)5, (int)1, (u8)0x13, (int)0x1d, (int)4, (int)0, (int)1);
    BMP_WIN_MakeScreen((struct Cfg *)W(0xc));
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)W(0xc))), 0xf);
    s = (u32)func_02045EC0((struct MsgBank *)arc, W(4));
    func_0201F73C((void *)W(0xc), 0, 1, 1);
    PRINTSYS_Print((void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)W(0xc))), 2, 2, (void *)s, (void *)W(8));
    STRBUF_Delete((struct U16Vec *)s);
    BMP_WIN_TransferChars((struct Descriptor *)W(0xc));
    for (i = 0; i < 2; i++) {
        q = p + i * 4;
        ((struct Obj06206 *)q)->f10 = BMP_WIN_Create((int)1, (int)6, (u8)(i * 4 + 0xc), (int)0x14, (int)2, (int)0, (int)1);
        BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj06206 *)q)->f10));
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj06206 *)q)->f10)), 0xf);
        s = (u32)func_02045EC0((struct MsgBank *)arc, i + 5 + W(4) * 2);
        PRINTSYS_Print((void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj06206 *)q)->f10)), 2, 2, (void *)s, (void *)W(8));
        STRBUF_Delete((struct U16Vec *)s);
        BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06206 *)q)->f10);
    }
    MSGDATA_Delete((struct Rec *)arc);
    STARTMENU_ConfigPromptHighlightChoice(p);
}
