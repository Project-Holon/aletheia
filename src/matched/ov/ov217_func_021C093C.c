/*
 * function: func_021C093C
 * address:  0x021C093C
 * packet:   pkt_ov217_021C093C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF734  0x021BF734  thumb  ov217
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Ctx;
struct IcaAnime;

extern u32 func_021BF734(u8 *a0);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 GAME_COMM_GetKind(void *obj);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);

int func_021C093C(u8 *a0)
{
    u32 r;
    r = func_021BF734(a0);
    switch (GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)r))) {
    case 0:
        GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)r);
        return 1;
    default:
        return 1;
    case 2:
        return 0;
    }
}
