/*
 * unit:     yes
 * function: GAMESYSTEM_TryStartAutoComm
 * address:  0x020121CC
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm     0x02012138  thumb
 *   GFL_NET_GetRunState     0x0203CD98  arm
 *   func_02026454     0x02026454  thumb
 *   GAMESYSTEM_CanStartAutoComm     0x02012164  thumb
 *   GAME_COMM_Start     0x020263D8  thumb
 *
 * Three tests, one epilogue: the handle returned by GAMESYSTEM_GetGameComm(p) is
 * checked with two externals (both called with it - r0 is not reloaded), then
 * the object is driven through GAMESYSTEM_CanStartAutoComm and only a result of exactly 1
 * reaches GAME_COMM_Start(handle, 1, p).  The nested ifs are what give all
 * three the same `return 0` at the end.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_TryStartAutoComm.c \
 *       --func GAMESYSTEM_TryStartAutoComm --addr 0x020121CC --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x1C];
    u32 f1c;
};

struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int GFL_NET_GetRunState(void);
struct Comm;
extern u32 func_02026454(void *obj);
extern u32 GAMESYSTEM_CanStartAutoComm(struct IcaAnime *p);
extern void GAME_COMM_Start(struct Comm *p, u32 a1, u32 a2);

u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p)
{
    u32 h = GAMESYSTEM_GetGameComm((const struct Ctx *)p);

    if (GFL_NET_GetRunState() == 0) {
        if (func_02026454((void *)h) == 0) {
            if (GAMESYSTEM_CanStartAutoComm(p) == 1) {
                GAME_COMM_Start((struct Comm *)h, 1, (u32)p);
                return 1;
            }
        }
    }
    return 0;
}
