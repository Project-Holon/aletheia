/*
 * function: WORLDTRADE_ADAPTER_CheckPartyHasOther
 * address:  0x022024DC
 * packet:   pkt_022024DC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_BOX_IsSpeciesFlagged  0x021F6DE8  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[8];
    void *party;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0xEB0 - 4];
    u16 species;
} Work;

extern int WORLDTRADE_BOX_IsSpeciesFlagged(u32 handle);
extern u32 POKEPARTY_GetCount(void *p);

int WORLDTRADE_ADAPTER_CheckPartyHasOther(Work *p, void *mon)
{
    if (WORLDTRADE_BOX_IsSpeciesFlagged((u32)mon) != 0 && POKEPARTY_GetCount(p->ctx->party) == 6) {
        return 2;
    }
    if (p->species == 0x2D0 && POKEPARTY_GetCount(p->ctx->party) == 6) {
        return 1;
    }
    return 0;
}
