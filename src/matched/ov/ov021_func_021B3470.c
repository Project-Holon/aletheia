/*
 * function: SCRCMD_PROC_FLD_PollItemList
 * address:  0x021B3470
 * packet:   pkt_ov021_021B3470
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_PROC_FLD_PollItemList 0x021B3470 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   SCRCMD_PROC_FLD_PickQuantityOutcome 0x021B3370 thumb ov021
 */
#include "../include/Obj00030.h"
#include "../include/Obj12842.h"

typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
struct Obj;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern void SCRCMD_PROC_FLD_PickQuantityOutcome(char *w);

void SCRCMD_PROC_FLD_PollItemList(char *p)
{
    void *q;
    int r;
    char *e;

    if (PRINTSYS_QUE_IsFinished(((struct Obj00030 *)p)->f1B0) == 0) {
        return;
    }
    if (((struct Obj00030 *)p)->f20A == 0) {
        q = ((struct Obj00030 *)p)->f16C;
        BMP_WIN_TransferChars(q);
        BMP_WIN_MakeScreen(q);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
        ((struct Obj00030 *)p)->f20A = ((struct Obj00030 *)p)->f20A + 1;
    }
    r = BMP_MENULIST_Main(((struct Obj00030 *)p)->f1A4);
    if (r == -1) {
        return;
    }
    if (r == -2) {
        *p = 11;
        return;
    }
    e = p + r * 8;
    ((struct Obj00030 *)p)->f1FC = ((struct Obj12842 *)e)->f20;
    *(int *)&((struct Obj00030 *)p)->f200 = ((struct Obj12842 *)e)->f24;
    ((struct Obj00030 *)p)->f208 = 1;
    SCRCMD_PROC_FLD_PickQuantityOutcome(p);
}
