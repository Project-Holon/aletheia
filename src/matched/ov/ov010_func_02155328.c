/*
 * function: MUSICAL_EVENT_BindParticipantSlots
 * address:  0x02155328
 * packet:   pkt_ov010_02155328
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Binds each party slot's list (+0x3c) and party member into the 16-byte
 * slot records at +0x8c, indexed through the position byte at +0x78,
 * remapped through a small constant table when the local player is not
 * on the first side. The two tables are the unit's rodata copied into
 * locals ({1, 0} at 0x0216FED8, {2, 3, 0, 1} at 0x0216FEDC).
 *
 * The ABS32 to 0x0216FED8 resolves as sole-ref/data since
 * overlay_data_structure() ends each extent at its last instruction's real
 * length (TOWN_MAP_SPOT_CountVisited ends in the 2-byte pop at 0x0216FED6).
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb
 *   MUSICAL_EVENT_TwoPlayerPositionRemap     0x0216FED8  data  ov010  a1
 *   MUSICAL_EVENT_FourPlayerPositionRemap     0x0216FEDC  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u8 v[2]; } Map2;
typedef struct { u8 v[4]; } Map4;

struct Info {
    u8 pad00[0x22];
    u8 f22;
};

struct Slot {
    void *list;
    void *mon;
    u8 pad08[8];
};

struct Ctx {
    u8 pad00[0x3c];
    void *f3c[4];
    u8 pad4c[0x2c];
    u8 b78[4];
    u8 pad7c[0x0c];
    struct Info *f88;
    struct Slot slot[4];
};

extern const Map2 MUSICAL_EVENT_TwoPlayerPositionRemap;
extern const Map4 MUSICAL_EVENT_FourPlayerPositionRemap;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
struct Rec44;
struct Sub24;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i);

void MUSICAL_EVENT_BindParticipantSlots(struct Ctx *ctx, void *party)
{
    Map4 m4;
    Map2 m2;
    int i;

    if (ctx->f88->f22 != 0) {
        if (ctx->b78[GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()))] < 2) {
            for (i = 0; i < 4; i++) {
                ctx->slot[ctx->b78[i]].list = ctx->f3c[i];
                ctx->slot[ctx->b78[i]].mon = GAME_DATA_GetMyStatusPlayer(GAMESYSTEM_GetGameData(party), i);
            }
        } else {
            i = 0;
            m4 = MUSICAL_EVENT_FourPlayerPositionRemap;
            for (; i < 4; i++) {
                ctx->slot[m4.v[ctx->b78[i]]].list = ctx->f3c[i];
                ctx->slot[m4.v[ctx->b78[i]]].mon = GAME_DATA_GetMyStatusPlayer(GAMESYSTEM_GetGameData(party), i);
            }
        }
    } else {
        if (GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())) == 0) {
            for (i = 0; i < 2; i++) {
                ctx->slot[ctx->b78[i]].list = ctx->f3c[i];
                ctx->slot[ctx->b78[i]].mon = GAME_DATA_GetMyStatusPlayer(GAMESYSTEM_GetGameData(party), i);
            }
        } else {
            i = 0;
            m2 = MUSICAL_EVENT_TwoPlayerPositionRemap;
            for (; i < 2; i++) {
                ctx->slot[m2.v[ctx->b78[i]]].list = ctx->f3c[i];
                ctx->slot[m2.v[ctx->b78[i]]].mon = GAME_DATA_GetMyStatusPlayer(GAMESYSTEM_GetGameData(party), i);
            }
        }
    }
}
