/*
 * function: FIELDMAP_UpdateG3d
 * address:  0x02189004
 * packet:   pkt_ov021_02189004
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BILLBOARD_ACT_UpdateEntries  0x020504D8  arm
 *   FIELD_NOGRID_MAPPER_Main  0x021BB36C  thumb
 *   FLD_SCENEAREA_Update  0x021AB660  thumb
 *   FIELD_ZONEFOG_Main  0x021A030C  thumb
 *   WEATHER_Update  0x021A1AF4  thumb
 *   FIELD_FOG_Main  0x021A0140  thumb
 *   GF_STANDARD_GetSecondsOfDay  0x0203F4FC  arm
 *   FIELD_LIGHT_Main  0x021A0458  thumb
 *   FIELD_G3D_MAPPER_UpdateStep  0x0218CB34  thumb
 *   GFL_NET_SetDeviceModeIfRunning  0x0203D12C  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02367.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Obj;
struct Owner;
extern void BILLBOARD_ACT_UpdateEntries(struct Owner *o);
extern void FIELD_NOGRID_MAPPER_Main(u32 a);
extern int FLD_SCENEAREA_Update(struct Obj *o, void *arg);
extern void FIELD_ZONEFOG_Main(u8 *p, u32 a);
extern void WEATHER_Update(u8 *p, int x);
extern void FIELD_FOG_Main(u8 *p);
extern u32 GF_STANDARD_GetSecondsOfDay(void);
extern void FIELD_LIGHT_Main(u8 *a, s32 b);
extern int FIELD_G3D_MAPPER_UpdateStep(char *p);
extern void GFL_NET_SetDeviceModeIfRunning(int a);

void FIELDMAP_UpdateG3d(u8 *a)
{
    u32 t;

    BILLBOARD_ACT_UpdateEntries((struct Owner *)(((struct Obj02367 *)a)->fB0));
    BILLBOARD_ACT_UpdateEntries((struct Owner *)(((struct Obj02367 *)a)->fB4));
    BILLBOARD_ACT_UpdateEntries((struct Owner *)(((struct Obj02367 *)a)->fB8));
    FIELD_NOGRID_MAPPER_Main(((struct Obj02367 *)a)->f3C);
    FLD_SCENEAREA_Update((struct Obj *)(((struct Obj02367 *)a)->f40), a + 0xF4);
    FIELD_ZONEFOG_Main((u8 *)(((struct Obj02367 *)a)->f1C), ((struct Obj02367 *)a)->f0);
    WEATHER_Update((u8 *)(((struct Obj02367 *)a)->f20), 0x92);
    FIELD_FOG_Main((u8 *)(((struct Obj02367 *)a)->f18));
    FIELD_LIGHT_Main((u8 *)(((struct Obj02367 *)a)->f14), GF_STANDARD_GetSecondsOfDay());
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    t = FIELD_G3D_MAPPER_UpdateStep((char *)(((struct Obj02367 *)a)->f48));
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    if (t != 0)
        GFL_NET_SetDeviceModeIfRunning(2);
}
