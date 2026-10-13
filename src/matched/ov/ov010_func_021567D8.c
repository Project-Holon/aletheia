/*
 * function: MUSICAL_EVENT_SpawnSeatEffect
 * address:  0x021567D8
 * packet:   pkt_ov010_021567D8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb  ov020
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   d_0216FEFC  0x0216FEFC  data
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Seq {
    void *f00;          /* 0x00 */
    u8 pad04[0x10 - 0x04];
    u8 state;           /* 0x10 */
    u8 pad11[3];
    u32 f14;            /* 0x14 */
    u8 pad18[0x4C - 0x18];
    u8 f4C;             /* 0x4C */
} Seq;

struct BigObj;
struct Ctx;
struct Evt;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
typedef struct Pos {
    u32 x;
    u32 y;
    u32 z;
} Pos;

typedef signed short   s16;
extern void *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(void *p, int u, s16 a, const int *s, u16 x);
extern const Pos d_0216FEFC;

void MUSICAL_EVENT_SpawnSeatEffect(void *evt, Seq *s)
{
    void *x;
    Pos pos;

    x = GAMESYSTEM_GetFieldMap(s->f00);
    pos = d_0216FEFC;
    pos.x += s->f4C << 17;
    GAME_EVENT_CallEvent(evt, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(s->f00, (int)x, 0x4E, (const int *)(&pos), 0));
}
