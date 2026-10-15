/*
 * function: SCRCMD_PROC_FLD_PrintOwnedWindow
 * address:  0x021B41AC
 * packet:   pkt_ov021_021B41AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The spilled second parameter is a u16 (SCRCMD_PROC_FLD_PickQuantityOutcome passes a u16 field
 * to func_02007FB8 in the same slot): as u32 its entry spill
 * `str r1, [sp, #8]` lands after the `lsls` instead of before it.
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   func_02007FB8 0x02007FB8 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   STRBUF_Delete 0x02045808 arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02712.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern void STRBUF_Delete(struct U16Vec *vec);

void SCRCMD_PROC_FLD_PrintOwnedWindow(char *w, u16 b)
{
    u32 t7, t6, s, bg;

    t7 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj02712 *)w)->f188), 0x17);
    t6 = (u32)STRBUF_Create(0x14, ((struct Obj02712 *)w)->f4);
    BMP_MENUWORK_DrawWindow((void *)(((struct Obj02712 *)w)->f170), 2, 0xE4, 9);
    WORDSET_SetSlotNumber((struct WordSet *)(((struct Obj02712 *)w)->f190), 0, func_02007FB8((u8 *)(((struct Obj02712 *)w)->f10), b, ((struct Obj02712 *)w)->f4), 3, 0, 1);
    WORDSET_CopyTaggedText((struct WordSet *)(((struct Obj02712 *)w)->f190), (void *)t6, (void *)t7);
    s = (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02712 *)w)->f170);
    BMP_Clear((struct CharBuf *)s, 0xF);
    PRINTSYS_PrintColor((void *)s, 0, 0, (void *)t6, (void *)(((struct Obj02712 *)w)->f8), 0x44F);
    bg = ((struct Obj02712 *)w)->f170;
    BMP_WIN_TransferChars((struct Descriptor *)bg);
    BMP_WIN_MakeScreen((struct Cfg *)bg);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)bg));
    STRBUF_Delete((struct U16Vec *)t6);
    STRBUF_Delete((struct U16Vec *)t7);
}
