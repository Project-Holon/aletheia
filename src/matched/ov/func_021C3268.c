/*
 * function: ZUKAN_DETAIL_VOICE_DeleteTimerWindow
 * address:  0x021C3268
 * packet:   pkt_021C3268
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   BMP_WIN_Delete  0x020452E8  arm  arm9
 *   (none)

 * Clears +0x10 and releases the two handles at +8 and +0xC.
 */
#include "../include/Obj09209.h"


struct Descriptor;
struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void ZUKAN_DETAIL_VOICE_DeleteTimerWindow(void *unused, char *p, void *a2)
{
    ((struct Obj09209 *)p)->f10 = 0;
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj09209 *)p)->f8));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj09209 *)p)->fC));
}

