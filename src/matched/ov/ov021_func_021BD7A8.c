/*
 * function: EVENT_ENTRANCE_IN_RunAppear
 * address:  0x021BD7A8
 * packet:   pkt_ov021_021BD7A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   EVENT_DISAPPEAR_CreateRisingSpin  0x021BFE00  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
} Cfg;

typedef struct {
    u32 f00;
    u32 f04;
    Cfg *cfg;
} Ctx;

extern void *EVENT_DISAPPEAR_CreateRisingSpin(int a0, void *p, int a2);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int EVENT_ENTRANCE_IN_RunAppear(void *task, u32 *state, Ctx *ctx)
{
    Cfg *cfg = ctx->cfg;
    u32 x = cfg->f04;
    u32 y = cfg->f0C;

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(task, EVENT_DISAPPEAR_CreateRisingSpin(0, (void *)x, y));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
