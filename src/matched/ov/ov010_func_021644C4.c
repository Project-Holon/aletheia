/*
 * function: FIELD_SKILL_CHECK_CallHandler
 * address:  0x021644C4
 * packet:   pkt_ov010_021644C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls entry i of the handler table at 0x021714DC, or returns 1 when the
 * slot is empty.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   d_021714DC     0x021714DC  data
 */

typedef unsigned int u32;
typedef int (*Handler)(void *sys, void *b, void *save);

struct Ctx;
struct SaveBlock;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern Handler d_021714DC[];

int FIELD_SKILL_CHECK_CallHandler(int i, void *a, void *b)
{
    void *sys;
    void *save;
    Handler fn;

    sys = GAMESYSTEM_GetGameData(a);
    save = GAME_DATA_GetMyPlayerWork(sys);
    fn = d_021714DC[i];
    if (fn == 0)
        return 1;
    return fn(sys, b, save);
}
