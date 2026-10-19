/*
 * function: WORLDTRADE_BOX_UnlockBoxIfAllFull
 * address: 0x021F6E08
 * packet: pkt_ov135_021F6E08
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef struct { u8 pad[12]; void *save; } Ctx;
typedef struct { Ctx *ctx; u8 pad[0xC8-4]; unsigned count; } Work;
extern u8 func_020076A4(void *save);
extern int func_020078C4(void *save, unsigned i);
extern u8 func_020076B4(void *save);
void WORLDTRADE_BOX_UnlockBoxIfAllFull(Work *p)
{
    unsigned i;
    p->count = func_020076A4(p->ctx->save);
    if (p->count < 24) {
        for (i = 0; i < p->count; i++) {
            if (func_020078C4(p->ctx->save, i) == 0) break;
        }
        if (i == p->count) p->count = func_020076B4(p->ctx->save);
    }
}
