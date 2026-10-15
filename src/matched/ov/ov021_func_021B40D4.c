/*
 * function: SCRCMD_PROC_FLD_PrintMoneyWindow
 * address:  0x021B40D4
 * packet:   pkt_ov021_021B40D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   GDS_PROFILE_GetScoreRecTotal 0x0200DABC thumb
 *   BEACON_GetPoints 0x0200C274 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj00037.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

struct Blk1AC;
struct Blk34;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u16 GDS_PROFILE_GetScoreRecTotal(struct Blk1AC *p);
extern u32 BEACON_GetPoints(struct Blk34 *p);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 a);
extern void STRBUF_Delete(struct U16Vec *vec);

void SCRCMD_PROC_FLD_PrintMoneyWindow(char *w)
{
    u32 t7, t6, s, bg;

    if (((struct Obj00037 *)w)->f163 == 1) {
        t7 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0x16);
        t6 = (u32)STRBUF_Create(10, ((struct Obj00037 *)w)->f4);
        WORDSET_SetSlotNumber((struct WordSet *)(*(u32 *)&((struct Obj00037 *)w)->f190), 0, GDS_PROFILE_GetScoreRecTotal((struct Blk1AC *)(((struct Obj00037 *)w)->f18)), 4, 1, 1);
    } else {
        t7 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00037 *)w)->f188), 0x15);
        t6 = (u32)STRBUF_Create(10, ((struct Obj00037 *)w)->f4);
        WORDSET_SetSlotNumber((struct WordSet *)(*(u32 *)&((struct Obj00037 *)w)->f190), 0, BEACON_GetPoints((struct Blk34 *)(((struct Obj00037 *)w)->fC)), 7, 1, 1);
    }
    WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&((struct Obj00037 *)w)->f190), (void *)t6, (void *)t7);
    s = (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00037 *)w)->f168);
    BMP_Clear((struct CharBuf *)s, 0);
    PRINTSYS_PrintColor((void *)s, 0, 0, (void *)t6, (void *)(((struct Obj00037 *)w)->f8), 0x3C4F);
    bg = ((struct Obj00037 *)w)->f168;
    BMP_WIN_TransferChars((struct Descriptor *)bg);
    BMP_WIN_MakeScreen((struct Cfg *)bg);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)bg));
    STRBUF_Delete((struct U16Vec *)t6);
    STRBUF_Delete((struct U16Vec *)t7);
}
