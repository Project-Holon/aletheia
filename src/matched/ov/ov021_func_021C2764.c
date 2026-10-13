/*
 * function: FLD3D_CI_StartScreenCapture
 * address:  0x021C2764
 * packet:   pkt_ov021_021C2764
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the task slot and starts the FLD3D_CI_CaptureTask task.
 *
 * symbols:
 *   FLD3D_CI_CaptureTask  0x021C2784  thumb  ov021
 */
#include "../include/Obj20169.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_0208068C(u32 a);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void FLD3D_CI_CaptureTask(void *p, u32 *done);

void FLD3D_CI_StartScreenCapture(u8 *p)
{
    ((struct Obj20169 *)p)->f70 = 0;
    func_0208068C(8);
    func_020056A0(FLD3D_CI_CaptureTask, p + 0x70, 0);
}
