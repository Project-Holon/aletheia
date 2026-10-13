/*
 * function: EVENT_MAPCHANGE_SetupEnterEntranceParam
 * address:  0x02184120
 * packet:   pkt_ov020_02184120
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_GetExitEffect  0x021BE89C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_GetEntranceEffect  0x021BE8B8  thumb  ov021
 *   sub_0202E8A4   0x0202E8A4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 */
#include "../include/Obj00082.h"
#include "../include/Obj02069.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct { int w[7]; } Blk28;

extern int EVENT_FIELDMAP_CONTROL_GetExitEffect(int a, unsigned int b);
extern int EVENT_FIELDMAP_CONTROL_GetEntranceEffect(int a, int b);
extern u8 sub_0202E8A4(u8 a);
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern void *EVENTDATA_SYSTEM_GetConnectData(char *p, unsigned i);
extern u8 EVENTDATA_SYSTEM_GetConnectExitType(u8 *p);

void EVENT_MAPCHANGE_SetupEnterEntranceParam(u8 *p, int arg)
{
    u8 *q = p + 0x4c;

    ((struct Obj02069 *)q)->f4 = *(int *)&((struct Obj00082 *)p)->f0;
    ((struct Obj02069 *)q)->f8 = ((struct Obj00082 *)p)->f4;
    ((struct Obj02069 *)q)->fC = *(int *)&((struct Obj00082 *)p)->f8;
    ((struct Obj02069 *)q)->f10 = ((struct Obj00082 *)p)->f2C;
    ((struct Obj00082 *)p)->f4C = arg;
    ((struct Obj02069 *)q)->f18 = ((struct Obj00082 *)p)->fC;
    *(Blk28 *)(q + 0x1c) = *(Blk28 *)(p + 0x10);
    ((struct Obj02069 *)q)->f38 = EVENT_FIELDMAP_CONTROL_GetExitEffect(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02069 *)q)->f3C = EVENT_FIELDMAP_CONTROL_GetEntranceEffect(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02069 *)q)->f40 = (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) ? 1 : 0;
    ((struct Obj02069 *)q)->f44 = sub_0202E8A4(((struct Obj00082 *)p)->f48);
    ((struct Obj02069 *)q)->f45 = ((struct Obj00082 *)p)->f4A;
    if (((struct Obj00082 *)p)->f10 == 1) {
        ((struct Obj02069 *)q)->f14 = 0;
        return;
    }
    ((struct Obj02069 *)q)->f14 = EVENTDATA_SYSTEM_GetConnectExitType(EVENTDATA_SYSTEM_GetConnectData((char *)GAME_DATA_GetEventData((const struct BigObj *)(((struct Obj00082 *)p)->f4)), ((struct Obj00082 *)p)->f16));
}
