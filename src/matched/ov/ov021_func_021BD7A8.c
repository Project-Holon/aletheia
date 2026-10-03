/*
 * function: func_021BD7A8
 * address:  0x021BD7A8
 * packet:   pkt_ov021_021BD7A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021BFE00  0x021BFE00  thumb  ov021
 *   func_02012374  0x02012374  thumb
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

extern void *func_021BFE00(int a, u32 b, u32 c);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);

int func_021BD7A8(void *task, u32 *state, Ctx *ctx)
{
    Cfg *cfg = ctx->cfg;
    u32 x = cfg->f04;
    u32 y = cfg->f0C;

    switch (*state) {
    case 0:
        func_02012374(task, func_021BFE00(0, x, y));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
