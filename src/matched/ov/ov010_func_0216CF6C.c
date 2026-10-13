/*
 * function: FLDMMDL_DeleteAllMmdl
 * address:  0x0216CF6C
 * packet:   pkt_ov010_0216CF6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_SysCheckDrawInit  0x0216D948  thumb  ov010
 *   FLDMMDL_CallDrawDeleteProc  0x0216D76C  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_SysDecMmdlCount  0x0216D508  thumb  ov010
 *   FLDMMDL_ClearMmdlWork  0x0216E180  thumb  ov010
 */
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_SysCheckDrawInit(int a0);
extern void FLDMMDL_CallDrawDeleteProc(void *a0);
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern int FLDMMDL_SysDecMmdlCount(int a0);
extern void FLDMMDL_ClearMmdlWork(void *a0);

void FLDMMDL_DeleteAllMmdl(u32 x)
{
    int n;
    u8 *o;
    u32 k = 2;

    n = 0;
    while (FLDMMDL_SysSearchUseMmdl((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n))) {
        if (FLDMMDL_SysCheckDrawInit(x) == 1)
            FLDMMDL_CallDrawDeleteProc(o);
        FLDMMDL_CheckStatusBit((int)o, k);
        FLDMMDL_SysDecMmdlCount(*(u32 *)&((struct Obj00113 *)o)->f88);
        FLDMMDL_ClearMmdlWork(o);
    }
}
