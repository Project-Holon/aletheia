/*
 * function: STARTMENU_CloseDescWindow
 * address:  0x021BBD10
 * packet:   pkt_ov088_021BBD10
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 *   STARTMENU_ClearFrameBox  0x021BBB84  thumb  ov088
 *   BG_SYS_ClearLayerEx  0x02041570  arm
 *   BG_SYS_ResetSlot  0x02041EE4  arm
 *   STARTMENU_ShowRowActors  0x021BB9DC  thumb  ov088
 */
#include "../include/Obj00263.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void STARTMENU_ClearFrameBox(u8 x, u8 y, u8 w, u8 h, u8 bg);
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
extern void BG_SYS_ResetSlot(u32, u32, u32);
extern void STARTMENU_ShowRowActors(char *, int);

void STARTMENU_CloseDescWindow(char *p, int mode)
{
    BMP_WIN_Delete(((struct Obj00263 *)p)->fF0);
    if (mode != 1) {
        STARTMENU_ClearFrameBox(0x20, 1, 0x20, 0x16, 2);
        BG_SYS_ClearLayerEx(0, 0);
        BG_SYS_ResetSlot(1, 0, 0);
        BG_SYS_ResetSlot(1, 3, ((struct Obj00263 *)p)->f130);
        BG_SYS_ResetSlot(2, 0, 0);
        BG_SYS_ResetSlot(2, 3, ((struct Obj00263 *)p)->f130);
        if (((struct Obj00263 *)p)->f120 == 0)
            STARTMENU_ShowRowActors(p, 1);
    }
}
