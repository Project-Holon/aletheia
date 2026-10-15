/*
 * function: SCRCMD_PROC_FLD_PrintQuantityWindow
 * address:  0x021B42D0
 * packet:   pkt_ov021_021B42D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D945C    0x021D945C data a4
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj01502.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern u32 d_021D945C[];

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 a);
extern void STRBUF_Delete(struct U16Vec *vec);

void SCRCMD_PROC_FLD_PrintQuantityWindow(char *w, u32 a, u32 b)
{
    u32 t1, t2, t3, s, bg;

    t1 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01502 *)w)->f188), 0x18);
    t2 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01502 *)w)->f188), d_021D945C[((struct Obj01502 *)w)->f163]);
    t3 = (u32)STRBUF_Create(0x14, ((struct Obj01502 *)w)->f4);
    s = (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01502 *)w)->f174);
    BMP_Clear((struct CharBuf *)s, 0xF);
    BMP_MENUWORK_DrawWindow((void *)(((struct Obj01502 *)w)->f174), 2, 0xE4, 9);
    WORDSET_SetSlotNumber((struct WordSet *)(((struct Obj01502 *)w)->f190), 0, a, 2, 0, 1);
    WORDSET_CopyTaggedText((struct WordSet *)(((struct Obj01502 *)w)->f190), (void *)t3, (void *)t1);
    PRINTSYS_PrintColor((void *)s, 0, 0, (void *)t3, (void *)(((struct Obj01502 *)w)->f8), 0x44F);
    WORDSET_SetSlotNumber((struct WordSet *)(((struct Obj01502 *)w)->f190), 0, a * b, 7, 1, 1);
    WORDSET_CopyTaggedText((struct WordSet *)(((struct Obj01502 *)w)->f190), (void *)t3, (void *)t2);
    if (((struct Obj01502 *)w)->f163 == 0) {
        PRINTSYS_PrintColor((void *)s, 0x23, 0, (void *)t3, (void *)(((struct Obj01502 *)w)->f8), 0x44F);
    } else {
        PRINTSYS_PrintColor((void *)s, 0x1D, 0, (void *)t3, (void *)(((struct Obj01502 *)w)->f8), 0x44F);
    }
    bg = ((struct Obj01502 *)w)->f174;
    BMP_WIN_TransferChars((struct Descriptor *)bg);
    BMP_WIN_MakeScreen((struct Cfg *)bg);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)bg));
    STRBUF_Delete((struct U16Vec *)t3);
    STRBUF_Delete((struct U16Vec *)t2);
    STRBUF_Delete((struct U16Vec *)t1);
}
