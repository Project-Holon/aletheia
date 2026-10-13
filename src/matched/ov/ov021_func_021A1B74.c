/*
 * function: WEATHER_SetImmediate
 * address:  0x021A1B74
 * packet:   pkt_ov021_021A1B74
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
 *   WEATHER_TASK_ForceEnd  0x021A20C8  thumb  ov021
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
extern void WEATHER_TASK_ForceEnd(struct O *p);
extern void WEATHER_UnloadOverlay(u8 *p);
extern void WEATHER_LoadOverlay(u32 *p, u32 v);
extern void WEATHER_TASK_Start(struct O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g);

void WEATHER_SetImmediate(u8 *p, int a, int f)
{
    int i;
    u32 t;

    if (a == ((struct Obj00755 *)p)->fC && a != 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        WEATHER_TASK_ForceEnd((struct O *)(*(u32 *)(p + 0x20 + i * 4)));
    }
    WEATHER_UnloadOverlay(p);
    ((struct Obj00755 *)p)->fA = 0;
    WEATHER_LoadOverlay((u32 *)p, d_021D886C[a * 2]);
    t = gWeatherTable[a * 2];
    WEATHER_TASK_Start((struct O *)(((struct Obj00755 *)p)->f20), t, 0, 0, 1, 1, f);
    ((struct Obj00755 *)p)->fC = a;
    ((struct Obj00755 *)p)->fE = 0xFFFF;
}
