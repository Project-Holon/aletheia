/*
 * function: TALKMSGWIN_ReleaseEntry
 * address:  0x02194B3C
 * packet:   pkt_ov021_02194B3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TALKMSGWIN_IsEntryFree  0x02194A74  thumb  ov021
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   TALKMSGWIN_ClearFrame  0x02195E90  thumb  ov021
 *   BMP_WIN_Delete  0x020452E8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04217.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
struct FrameStyle;
struct Rec3;
extern int TALKMSGWIN_IsEntryFree(u32 a);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void TALKMSGWIN_ClearFrame(struct FrameStyle *style, void *win);
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void TALKMSGWIN_ReleaseEntry(u8 *p, u8 *e)
{
    if (TALKMSGWIN_IsEntryFree((u32)e) == 0) {
        if (((struct Obj04217 *)e)->f8 != 0) {
            PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj04217 *)e)->f8));
            ((struct Obj04217 *)e)->f8 = 0;
        }
        TALKMSGWIN_ClearFrame((struct FrameStyle *)p, (void *)(((struct Obj04217 *)e)->fC));
        BMP_WIN_Delete((struct Descriptor *)(((struct Obj04217 *)e)->fC));
        ((struct Obj04217 *)e)->f2 = 0;
        ((struct Obj04217 *)e)->f0 = 0;
    }
}
