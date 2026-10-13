/*
 * function: EVENT_MAPCHANGE_SetupExitEntranceParam
 * address:  0x0218409C
 * packet:   pkt_ov020_0218409C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_GetExitEffect  0x021BE89C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_GetEntranceEffect  0x021BE8B8  thumb  ov021
 *   sub_0202E8A4   0x0202E8A4  thumb
 */
#include "../include/Obj00082.h"
#include "../include/Obj02068.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct { int w[7]; } Blk28;

typedef unsigned int   u32;
extern int EVENT_FIELDMAP_CONTROL_GetExitEffect(int a, u32 b);
extern int EVENT_FIELDMAP_CONTROL_GetEntranceEffect(int a, int b);
extern u8 sub_0202E8A4(u8 a);

void EVENT_MAPCHANGE_SetupExitEntranceParam(u8 *p, int arg)
{
    u8 *q = p + 0x4c;

    ((struct Obj02068 *)q)->f4 = *(int *)&((struct Obj00082 *)p)->f0;
    ((struct Obj02068 *)q)->f8 = ((struct Obj00082 *)p)->f4;
    ((struct Obj02068 *)q)->fC = *(int *)&((struct Obj00082 *)p)->f8;
    ((struct Obj02068 *)q)->f10 = ((struct Obj00082 *)p)->f2C;
    ((struct Obj00082 *)p)->f4C = arg;
    ((struct Obj02068 *)q)->f18 = ((struct Obj00082 *)p)->fC;
    *(Blk28 *)(q + 0x1c) = *(Blk28 *)(p + 0x10);
    ((struct Obj02068 *)q)->f38 = EVENT_FIELDMAP_CONTROL_GetExitEffect(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02068 *)q)->f3C = EVENT_FIELDMAP_CONTROL_GetEntranceEffect(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02068 *)q)->f40 = (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) ? 1 : 0;
    ((struct Obj02068 *)q)->f44 = sub_0202E8A4(((struct Obj00082 *)p)->f48);
    ((struct Obj02068 *)q)->f45 = ((struct Obj00082 *)p)->f4A;
    ((struct Obj02068 *)q)->f48 = 0;
    ((struct Obj02068 *)q)->f4C = 0;
}
