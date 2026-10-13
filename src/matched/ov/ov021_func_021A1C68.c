/*
 * function: WEATHER_UpdateSequential
 * address:  0x021A1C68
 * packet:   pkt_ov021_021A1C68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D886C     0x021D886C  data  ov021  a4
 *   gWeatherTable     0x021D8868  data  ov021  a4
 *   WEATHER_TASK_RequestEnd  0x021A2050  thumb  ov021
 *   WEATHER_TASK_GetPhase  0x021A21B0  thumb  ov021
 *   WEATHER_UnloadOverlay  0x021A1C04  thumb  ov021
 *   WEATHER_LoadOverlay  0x021A1BF8  thumb  ov021
 *   WEATHER_TASK_Start  0x021A1FEC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00755.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u32 d_021D886C[];
extern const u32 gWeatherTable[];
struct O;
extern void WEATHER_TASK_RequestEnd(struct O *p, u32 a, u32 b);
extern int WEATHER_TASK_GetPhase(u8 *a0);
extern void WEATHER_UnloadOverlay(u8 *p);
extern void WEATHER_LoadOverlay(u32 *p, u32 v);
extern void WEATHER_TASK_Start(struct O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g);

void WEATHER_UpdateSequential(u8 *p, int x)
{
    switch (((struct Obj00755 *)p)->fA) {
    case 0:
        break;
    case 1:
        WEATHER_TASK_RequestEnd((struct O *)(((struct Obj00755 *)p)->f20), 1, 1);
        ((struct Obj00755 *)p)->fA = 2;
        break;
    case 2:
        if (WEATHER_TASK_GetPhase((u8 *)(((struct Obj00755 *)p)->f20)) == 0) {
            WEATHER_UnloadOverlay(p);
            ((struct Obj00755 *)p)->fA = 3;
        }
        break;
    case 3:
        WEATHER_LoadOverlay((u32 *)p, d_021D886C[((struct Obj00755 *)p)->fE * 2]);
        ((struct Obj00755 *)p)->fA = 4;
        break;
    case 4:
        WEATHER_TASK_Start((struct O *)(((struct Obj00755 *)p)->f20), gWeatherTable[((struct Obj00755 *)p)->fE * 2], 1, 1, 1,
                      ((struct Obj00755 *)p)->f10, x);
        ((struct Obj00755 *)p)->f10 = 1;
        ((struct Obj00755 *)p)->fC = ((struct Obj00755 *)p)->fE;
        ((struct Obj00755 *)p)->fE = 0xFFFF;
        ((struct Obj00755 *)p)->fA = 0;
        break;
    }
}
