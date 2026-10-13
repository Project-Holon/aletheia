/*
 * function: WEATHER_Create
 * address:  0x021A19E8
 * packet:   pkt_ov021_021A19E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The two loops use separate counters (one shared counter swaps p and the
 * counter between r4 and r5).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELD_3DBG_CreateBillboard  0x021A15A4  thumb  ov021
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   CLACT_SetUnitRenderer  0x0204B258  arm
 *   WEATHER_TASK_Create  0x021A1DB4  thumb  ov021
 *   WEATHER_ReleaseBillboardVramTask  0x021A1C1C  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   g_WeatherSourceName     0x021DDE74  data
 *   gWeatherBillboardDescs     0x021D8850  data
 *   d_021D8840     0x021D8840  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 *f0[2];
    u16 f8;
    u16 fA;
    u16 fC;
    u16 fE;
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    void *f18;
    void *f1C;
    u32 *f20[2];
    int f28;
    int f2C;
} Obj021A19E8;

typedef struct {
    u8 b[12];
} Desc021A19E8;

extern char g_WeatherSourceName[];
extern Desc021A19E8 gWeatherBillboardDescs[];
extern u8 d_021D8840[];

struct Bank;
struct Obj;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *FIELD_3DBG_CreateBillboard(u8 *p, u32 heap);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);
extern u32 *WEATHER_TASK_Create(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 h, u16 i);
extern void WEATHER_ReleaseBillboardVramTask(int a, u32 *p);
extern int func_020056A0(void (*cb)(void *), void *arg, int pri);

Obj021A19E8 *WEATHER_Create(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5, u16 heap)
{
    int i;
    int j;
    Obj021A19E8 *p = func_02030734(heap, 0x30, 1, g_WeatherSourceName, 0x158);

    for (i = 0; i < 2; i++) {
        p->f0[i] = FIELD_3DBG_CreateBillboard(gWeatherBillboardDescs[i].b, heap);
    }
    p->f8 = 0;
    p->fA = 0;
    p->fC = 0xFFFF;
    p->fE = 0xFFFF;
    p->f14 = 0xFFFF;
    p->f28 = -1;
    p->f18 = CLACT_CreateUnit(0x40, 8, heap);
    p->f1C = CLACT_CreateRenderer(d_021D8840, 1, heap);
    CLACT_SetUnitRenderer(p->f18, p->f1C);
    for (j = 0; j < 2; j++) {
        p->f20[j] = WEATHER_TASK_Create((u32)p->f18, a0, a1, a2, a3, (u32)p, a4, a5, heap);
    }
    p->f2C = func_020056A0((void (*)(void *))WEATHER_ReleaseBillboardVramTask, p, 0x40);
    return p;
}
