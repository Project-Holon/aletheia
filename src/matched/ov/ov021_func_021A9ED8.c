/*
 * function: FIELD_ENCOUNT_Create
 * address:  0x021A9ED8
 * packet:   pkt_ov021_021A9ED8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetEncountData  0x0216255C  thumb  ov010
 *   EFFECT_ENCOUNT_Create  0x021AA77C  thumb  ov021
 *   EFFECT_ENCOUNT_Init  0x021AA7AC  thumb  ov021
 *   d_021DDFA4     0x021DDFA4  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int d_021DDFA4;

struct BigObj;
struct Ctx;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern u32 EVENTDATA_SYSTEM_GetEncountData(u32 a);
extern void *EFFECT_ENCOUNT_Create(int heap);
extern int EFFECT_ENCOUNT_Init(u32 a, u32 b);
extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);

u32 *FIELD_ENCOUNT_Create(u32 a)
{
    u32 heap = FIELDMAP_GetHeapId((u8 *)a);
    u32 *p = (u32 *)func_02030734(heap, 0x14, 1, (const char *)&d_021DDFA4, 0x62);
    u32 x;
    u32 t;
    u32 q;

    p[0] = a;
    x = (u32)FIELDMAP_GetGameSystem((void *)a);
    p[1] = x;
    t = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)x);
    p[2] = t;
    p[3] = EVENTDATA_SYSTEM_GetEncountData(GAME_DATA_GetEventData((const struct BigObj *)t));
    q = (u32)EFFECT_ENCOUNT_Create(heap);
    p[4] = q;
    EFFECT_ENCOUNT_Init((u32)p, q);
    return p;
}
