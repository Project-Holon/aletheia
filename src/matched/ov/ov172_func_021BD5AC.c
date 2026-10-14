/*
 * function: func_021BD5AC
 * address:  0x021BD5AC
 * packet:   pkt_ov172_021BD5AC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CTVT_CAMVIEW_UploadWindows  0x021B71B8  thumb  ov172
 *   DRAW_SYSTEM_FlushStrokes  0x021B6C4C  thumb  ov172
 *   func_021B9574  0x021B9574  thumb  ov172
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 */
#include "../include/Obj10666.h"

typedef unsigned int u32;

struct Q;
extern void CTVT_CAMVIEW_UploadWindows(void *p, struct Q *q);
extern void CLACT_VBlankSystem(void);
extern void DRAW_SYSTEM_FlushStrokes(char *p);
extern void func_021B9574(int unused, char *p);

void func_021BD5AC(int unused, char *ctx)
{
    CTVT_CAMVIEW_UploadWindows(ctx, (struct Q *)(((struct Obj10666 *)ctx)->f1E0));
    CLACT_VBlankSystem();
    DRAW_SYSTEM_FlushStrokes((char *)(((struct Obj10666 *)ctx)->f1F4));
    func_021B9574((int)ctx, (char *)(((struct Obj10666 *)ctx)->f1E8));
}
