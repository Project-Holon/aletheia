/*
 * function: TOUCHPANEL_HitTrg
 * address:  0x02035C08
 * packet:   pkt_02035C08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035224   0x02035224  arm
 *   TOUCHPANEL_HitTrgSys   0x02035BBC  arm
 */

struct UiCtx;
extern struct UiCtx *func_02035224(void);
extern int TOUCHPANEL_HitTrgSys(void *ctx, void *param);

int TOUCHPANEL_HitTrg(const void *p)
{
    return TOUCHPANEL_HitTrgSys((void *)((int)func_02035224()), (void *)p);
}
