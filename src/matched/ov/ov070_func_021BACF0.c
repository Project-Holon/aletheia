/*
 * function: ITEMMENU_ShowMessage
 * address:  0x021BACF0
 * packet:   pkt_ov070_021BACF0
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the window at p+0x4FC on first use, clears it, then either prints
 * through PRINTSYS_PrintStream (mode 1) or through ITEMMENU_PrintToWindow, and finishes the
 * window. The window address is a named local taken after the clear calls:
 * without it the 0x4FC offset went to r4 and mode to r6, the mode-1 arm
 * consumed the offset register destructively and the join reloaded it
 * (4 bytes short).
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   ITEMMENU_PrintToWindow  0x021BB6E0  thumb  ov070
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   ITEMMENU_FlushWindowAt  0x021BB724  thumb  ov070
 */
#include "../include/Obj00002.h"
#include "../include/Obj04334.h"

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern signed char MSG_SPEED_GetWait(void);
extern int PRINTSYS_PrintStream(int, int, int, int, int, int, int, int, int, int);
extern void ITEMMENU_PrintToWindow(int p, u32 *obj, u32 str, u16 x, s16 y, u16 color);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void ITEMMENU_FlushWindowAt(void **p);

void ITEMMENU_ShowMessage(int p, int mode)
{
    int win;

    if (((struct Obj00002 *)p)->f4FC == 0) {
        ((struct Obj00002 *)p)->f4FC = BMP_WIN_Create(3, 1, 1, 0x1E, 4, 0xC, 1);
    }
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00002 *)p)->f4FC)), 0xF);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00002 *)p)->f4FC);
    win = p + 0x4FC;
    if (mode == 1) {
        ((struct Obj00002 *)p)->f510 = PRINTSYS_PrintStream(((struct Obj00002 *)p)->f4FC, 0, 0, *(int *)&((struct Obj00002 *)p)->f528,
                                            ((struct Obj00002 *)p)->f530, MSG_SPEED_GetWait(),
                                            ((struct Obj00002 *)p)->f730, 2, ((struct Obj00002 *)p)->f544, 0xF);
    } else {
        ITEMMENU_PrintToWindow(p, (u32 *)win, *(int *)&((struct Obj00002 *)p)->f528, 0, 0, 0x44F);
    }
    BMP_MENUWORK_DrawWindow((void *)(*(int *)&((struct Obj04334 *)win)->f0), 1, (u16)((struct Obj00002 *)p)->f838, 0xD);
    ITEMMENU_FlushWindowAt((void **)win);
}
