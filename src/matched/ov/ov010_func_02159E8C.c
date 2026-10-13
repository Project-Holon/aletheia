/*
 * function: MAP_REPLACE_SetupFlags
 * address:  0x02159E8C
 * packet:   pkt_ov010_02159E8C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   COMM_PLAYER_SUPPORT_GetInfoCode  0x0202E83C  thumb
 *   INTRUDE_COMM_GetAreaOwnerVersion  0x0215843C  thumb  ov010
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb
 *   d_02170FB0  0x02170FB0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u16 f00;
    u16 f02;
    u16 f04;
} Ent;

struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int COMM_PLAYER_SUPPORT_GetInfoCode(void *a0);
extern int INTRUDE_COMM_GetAreaOwnerVersion(void *p);
extern u32 ZONEDATA_GetEventWorkAddress(u32 a, u32 b);
extern Ent d_02170FB0[];

void MAP_REPLACE_SetupFlags(u8 *out, int obj)
{
    int a = GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData((const struct Ctx *)obj));
    int b = GAMESYSTEM_GetGameComm((const struct Ctx *)obj);
    int c = COMM_PLAYER_SUPPORT_GetInfoCode((void *)obj);
    int i;
    out[0] = c;
    out[1] = (INTRUDE_COMM_GetAreaOwnerVersion((void *)b) != 0x15);
    out[2] = (out[1] == 0) ? 0 : c + 1;
    for (i = 0; i < 10; i++) {
        Ent *e = &d_02170FB0[i];
        u16 *p = (u16 *)ZONEDATA_GetEventWorkAddress(a, e->f02);
        if (*p == e->f04)
            out[3 + i] = 1;
        else
            out[3 + i] = 0;
    }
}
