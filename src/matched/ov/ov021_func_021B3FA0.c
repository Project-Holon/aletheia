/*
 * function: SCRCMD_PROC_FLD_InitShopWindows
 * address:  0x021B3FA0
 * packet:   pkt_ov021_021B3FA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE18C    0x021DE18C data ov021 a4
 *   d_021DE170    0x021DE170 data ov021 a4
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj00037.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct {
    u32 f0;
    u8  f4;
    u8  f5;
    u8  f6;
    u8  f7;
    u16 f8;
} WinTmpl;

extern WinTmpl *d_021DE18C[];
extern WinTmpl *d_021DE170[];

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 a);

void SCRCMD_PROC_FLD_InitShopWindows(char *w)
{
    WinTmpl **tbl;
    WinTmpl *e;
    int i;
    u32 t;
    u32 bg;

    tbl = d_021DE18C;
    if (((struct Obj00037 *)w)->f163 != 1) {
        tbl = d_021DE170;
    }
    for (i = 0; i < 7; i++) {
        e = tbl[i];
        ((u32 *)(w + 0x164))[i] = BMP_WIN_Create((u8)e->f0, e->f4, e->f5, e->f6, e->f7, (u8)e->f8, 1);
    }
    t = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0x14);
    PRINTSYS_PrintColor((void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00037 *)w)->f164)), 0, 0, (void *)t, (void *)(((struct Obj00037 *)w)->f8), 0x3C4F);
    STRBUF_Delete((struct U16Vec *)t);
    ((struct Obj00037 *)w)->f1A8 = ((struct Obj00037 *)w)->f16C;
    ((struct Obj00037 *)w)->f1AC = 0;
    ((struct Obj00037 *)w)->f1B0 = PRINTSYS_QUE_Create((void *)(((struct Obj00037 *)w)->f4));
    if (((struct Obj00037 *)w)->f163 == 1) {
        bg = ((struct Obj00037 *)w)->f168;
        BMP_WIN_TransferChars((struct Descriptor *)bg);
        BMP_WIN_MakeScreen((struct Cfg *)bg);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)bg));
    } else {
        bg = ((struct Obj00037 *)w)->f164;
        BMP_WIN_TransferChars((struct Descriptor *)bg);
        BMP_WIN_MakeScreen((struct Cfg *)bg);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)bg));
        bg = ((struct Obj00037 *)w)->f168;
        BMP_WIN_TransferChars((struct Descriptor *)bg);
        BMP_WIN_MakeScreen((struct Cfg *)bg);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)bg));
    }
}
