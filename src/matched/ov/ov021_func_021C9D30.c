/*
 * function: BSUBWAY_SCR_ResetPlayMode
 * address:  0x021C9D30
 * packet:   pkt_ov021_021C9D30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reads flag 0 of resource 0x39, resets it and forwards the flag to resource 0x3a.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200D884  0x0200D884  thumb
 *   func_0200DA14  0x0200DA14  thumb
 *   func_0200DB1C  0x0200DB1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Big;
struct Blk1AC;
struct Blk3C;
struct Sub020071CCCtrl;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u32 func_0200D884(struct Blk3C *p, u32 id, void *out);
extern void func_0200DA14(struct Blk3C *p);
extern void func_0200DB1C(struct Blk1AC *p, u32 i);

u32 BSUBWAY_SCR_ResetPlayMode(const struct Ctx *a0)
{
    u32 a = (u32)GAME_DATA_GetSaveControl((struct Big *)GAMESYSTEM_GetGameData(a0));
    u32 b = (u32)func_020071CC((struct Sub020071CCCtrl *)a, 0x39);
    u32 c = (u32)func_020071CC((struct Sub020071CCCtrl *)a, 0x3a);
    u8 r = func_0200D884((struct Blk3C *)b, 0, 0);

    func_0200DA14((struct Blk3C *)b);
    func_0200DB1C((struct Blk1AC *)c, r);
    return r;
}
