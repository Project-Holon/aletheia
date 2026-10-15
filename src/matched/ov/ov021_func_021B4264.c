/*
 * function: SCRCMD_PROC_FLD_PrintItemDescription
 * address:  0x021B4264
 * packet:   pkt_ov021_021B4264
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj07523.h"

typedef unsigned int u32;
typedef short s16;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 a);

void SCRCMD_PROC_FLD_PrintItemDescription(char *w, u32 b)
{
    u32 win;
    u32 t;
    u32 bg;

    win = (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj07523 *)w)->f178);
    BMP_Clear((struct CharBuf *)win, 0);
    if (b <= 0x272) {
        t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj07523 *)w)->f18C), b);
        PRINTSYS_PrintColor((void *)win, 0, 0, (void *)t, (void *)(((struct Obj07523 *)w)->f8), 0x3C40);
        STRBUF_Delete((struct U16Vec *)t);
    }
    bg = ((struct Obj07523 *)w)->f178;
    BMP_WIN_TransferChars((struct Descriptor *)bg);
    BMP_WIN_MakeScreen((struct Cfg *)bg);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)bg));
}
