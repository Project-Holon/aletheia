/*
 * function: GAMESYSTEM_CanStartAutoComm
 * address:  0x02012164
 * packet:   pkt_02012164
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   ZONEDATA_IsNoGameEventZone  0x02013D34  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   GAMESYSTEM_GetAlwaysNetFlag  0x0201214C  thumb
 *   INTRUDE_COMM_CheckEntryAllowed  0x02158318  thumb  ov010
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_0200921C  0x0200921C  thumb
 *   func_020090E0  0x020090E0  thumb
 *
 * blocker:  label -- INTRUDE_COMM_CheckEntryAllowed (ov010, thumb) is traced in ov010's
 *           listing but its only caller in the whole image is the bl at
 *           +0x38 inside this range, so `label` has no outside witness and
 *           sole-ref/code does not consider overlay starts.  Every concrete
 *           byte is right (MATCH*: the extent runs over the 2-byte pad).
 *
 * The note's 4-byte r0/r1 "tie" (docs/notes/pkt_02012164.c.txt) was a
 * misread arity: GAME_DATA_GetPlayerZoneId is `ldrh r0, [r0]; bx lr`, a getter taking
 * the pointer GAMESYSTEM_GetMyPlayerWork returns, and ZONEDATA_IsNoGameEventZone takes that u16 in
 * r0 -- so the image keeps it in r0 across the p->f32 test and reads the
 * byte through r1.  `id = GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(p))` then
 * `ZONEDATA_IsNoGameEventZone(id)` closes it.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x1c];
    void *f1c;
    u8  pad20[0x12];
    u8  f32;
};

struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u8   *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct Rec44;
extern u16   GAME_DATA_GetPlayerZoneId(const struct Rec44 *h);
struct Sub02009210Obj;
extern u32 ZONEDATA_IsNoGameEventZone(u32 id);
extern u32   func_0200FB24(void);
extern u32   GAMESYSTEM_GetAlwaysNetFlag(const struct Ctx *p);
extern int INTRUDE_COMM_CheckEntryAllowed(int a0);
extern u32   func_02035390(void);
extern int func_020353B0(void);
extern struct Sub02009210Obj *func_0200921C(void *p);
struct Sub020090B0Obj;
extern u8 func_020090E0(const struct Sub020090B0Obj *obj);

u32 GAMESYSTEM_CanStartAutoComm(struct IcaAnime *p)
{
    u16 id;

    GAMESYSTEM_GetGameComm((const struct Ctx *)p);
    id = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork((const struct Ctx *)p));
    if (p->f32 == 0
     && ZONEDATA_IsNoGameEventZone(id) == 0
     && func_0200FB24() == 0
     && GAMESYSTEM_GetAlwaysNetFlag((const struct Ctx *)p) == 1
     && INTRUDE_COMM_CheckEntryAllowed((int)p) == 1
     && !(func_02035390() == 1 && func_020353B0() == 1)) {
        if (func_020090E0((const struct Sub020090B0Obj *)func_0200921C(p->f1c)) != 0) {
            return 1;
        }
    }
    return 0;
}
