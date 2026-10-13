/*
 * function: VCT_AUDIO_InitReceiveSource
 * address:  0x021B19BC
 * packet:   pkt_ov013_021B19BC
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../include/Obj00751.h"

extern void MI_CpuFill8(void *p, int v, int n);

void VCT_AUDIO_InitReceiveSource(char *p, int a1, int a2)
{
    MI_CpuFill8(p, 0, 0x28);
    ((struct Obj00751 *)p)->f4 = 0x134DF;
    ((struct Obj00751 *)p)->f28 = 0;
    ((struct Obj00751 *)p)->f2C = 0;
    ((struct Obj00751 *)p)->f34 = a1;
    ((struct Obj00751 *)p)->f38 = a2;
    ((struct Obj00751 *)p)->f7C = 0;
    ((struct Obj00751 *)p)->f80 = 0;
    ((struct Obj00751 *)p)->f84 = 0;
    ((struct Obj00751 *)p)->f88 = 0;
    ((struct Obj00751 *)p)->f8C = 0x134DF;
    ((struct Obj00751 *)p)->f90 = 0;
    ((struct Obj00751 *)p)->f4C = 0;
    ((struct Obj00751 *)p)->f44 = 0;
    ((struct Obj00751 *)p)->f48 = 0;
    ((struct Obj00751 *)p)->f6C = 0;
    ((struct Obj00751 *)p)->f70 = 0;
    ((struct Obj00751 *)p)->f50 = 0;
    ((struct Obj00751 *)p)->f54 = 0;
    ((struct Obj00751 *)p)->f58 = 0;
    ((struct Obj00751 *)p)->f5C = 1;
    ((struct Obj00751 *)p)->f3C = 0;
    ((struct Obj00751 *)p)->f40 = 0;
    ((struct Obj00751 *)p)->f30 = 0;
}
