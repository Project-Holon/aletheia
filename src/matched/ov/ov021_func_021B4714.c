/*
 * function: SCRCMD_PROC_FLD_ShowItemMessage
 * address:  0x021B4714
 * packet:   pkt_ov021_021B4714
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   WORDSET_SetSlotFromBank  0x0201EF6C  thumb
 *   FILE_UTIL_GetItemParam  0x02020FE4  thumb
 *   WORDSET_SetSlotFromMsg37  0x0201F14C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   SCRCMD_PROC_FLD_ReturnZero  0x021B4710  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01503.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef signed short   s16;
typedef signed int     s32;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void WORDSET_SetSlotFromBank(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
extern u32 FILE_UTIL_GetItemParam(void *a, u32 sel, u32 id);
extern void WORDSET_SetSlotFromMsg37(struct WordSet *p, u32 i, u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern signed char MSG_SPEED_GetWait(void);
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
extern int SCRCMD_PROC_FLD_ReturnZero();

void SCRCMD_PROC_FLD_ShowItemMessage(u8 *p, u32 sel, u32 c, u32 d)
{
    u32 flag;
    u32 v;
    u32 h;

    if (sel == 9 && d != 0)
        flag = 1;
    else
        flag = 0;
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01503 *)p)->f17C)), 0xf);
    BMP_MENUWORK_DrawWindow((void *)(((struct Obj01503 *)p)->f17C), 0, 0xe4, 9);
    WORDSET_SetSlotFromBank((struct WordSet *)(((struct Obj01503 *)p)->f190), 0, c, flag, 0);
    WORDSET_SetSlotFromMsg37((struct WordSet *)(((struct Obj01503 *)p)->f190), 1, FILE_UTIL_GetItemParam((void *)c, 5, ((struct Obj01503 *)p)->f4));
    v = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01503 *)p)->f188), sel);
    WORDSET_CopyTaggedText((struct WordSet *)(((struct Obj01503 *)p)->f190), (void *)(((struct Obj01503 *)p)->f198), (void *)v);
    STRBUF_Delete((struct U16Vec *)v);
    ((struct Obj01503 *)p)->f1B8 = (u32)PRINTSYS_PrintStreamCallBack(((struct Obj01503 *)p)->f17C, 0, 0, ((struct Obj01503 *)p)->f198,
                                        ((struct Obj01503 *)p)->f8, MSG_SPEED_GetWait(),
                                        ((struct Obj01503 *)p)->f1B4, 0, ((struct Obj01503 *)p)->f4, 0xffff,
                                        (u32)SCRCMD_PROC_FLD_ReturnZero);
    h = ((struct Obj01503 *)p)->f17C;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)h));
}
