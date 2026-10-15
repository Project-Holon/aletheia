/*
 * function: SCRCMD_PROC_FLD_ShowMessage
 * address:  0x021B4894
 * packet:   pkt_ov021_021B4894
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStreamCallBack 0x0201CD10 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj01121.h"

typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef signed int     s32;
typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern signed char MSG_SPEED_GetWait(void);
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 a);

void SCRCMD_PROC_FLD_ShowMessage(char *w, u32 b)
{
    u32 t;
    u32 win;

    t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01121 *)w)->f188), b);
    WORDSET_CopyTaggedText((struct WordSet *)(((struct Obj01121 *)w)->f190), (void *)(((struct Obj01121 *)w)->f198), (void *)t);
    STRBUF_Delete((struct U16Vec *)t);
    ((struct Obj01121 *)w)->f1B8 = (u32)PRINTSYS_PrintStreamCallBack(((struct Obj01121 *)w)->f17C, 0, 0, ((struct Obj01121 *)w)->f198,
                                        ((struct Obj01121 *)w)->f8, MSG_SPEED_GetWait(), ((struct Obj01121 *)w)->f1B4, 0,
                                        ((struct Obj01121 *)w)->f4, 0xFFFF, 0);
    win = ((struct Obj01121 *)w)->f17C;
    BMP_WIN_TransferChars((struct Descriptor *)win);
    BMP_WIN_MakeScreen((struct Cfg *)win);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)win));
}
