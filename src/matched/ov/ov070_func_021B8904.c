/*
 * function: ITEMMENU_Main
 * address:  0x021B8904
 * packet:   pkt_ov070_021B8904
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   ITEMMENU_SnapSelectorToCursor  0x021BA41C  thumb  ov070
 *   ITEMMENU_UploadSlotGraphics  0x021BA4A4  thumb  ov070
 *   ITEMMENU_FreeActionMenuResources  0x021B9ED8  thumb  ov070
 *   ITEMMENU_FlushDirtyWindows  0x021BB73C  thumb  ov070
 *   TCBL_Main  0x020310C4  arm
 */
#include "../include/Obj01365.h"

typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
typedef unsigned char  u8;
struct Tcbl;
extern void ITEMMENU_SnapSelectorToCursor(char *p);
extern void ITEMMENU_UploadSlotGraphics(char *p);
extern void ITEMMENU_FreeActionMenuResources(char *p);
extern void ITEMMENU_FlushDirtyWindows(u8 *p);
extern void TCBL_Main(struct Tcbl *p);

int ITEMMENU_Main(int a, int b, int c, int p)
{
    void (*fn)(int) = *(void (**)(int))((char *)p + 0x4F8);
    if (fn == 0) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, ((struct Obj01365 *)p)->f544);
        return 1;
    }
    ((struct Obj01365 *)p)->f818 = ((struct Obj01365 *)p)->f814;
    fn(p);
    if (((struct Obj01365 *)p)->f83E != 0) {
        ITEMMENU_SnapSelectorToCursor((char *)p);
        ((struct Obj01365 *)p)->f83E = 0;
    }
    if (((struct Obj01365 *)p)->f83C != 0) {
        ITEMMENU_UploadSlotGraphics((char *)p);
        ((struct Obj01365 *)p)->f83C = 0;
    }
    ITEMMENU_FreeActionMenuResources((char *)p);
    ITEMMENU_FlushDirtyWindows((u8 *)p);
    TCBL_Main((struct Tcbl *)(((struct Obj01365 *)p)->f730));
    return 0;
}
