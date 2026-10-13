/*
 * function: TOUCHPANEL_HitCont
 * address:  0x02035BA4
 * packet:   pkt_02035BA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035224   0x02035224  arm
 *   TOUCHPANEL_HitContSys   0x02035B58  arm
 */

typedef unsigned int   u32;
struct UiCtx;
extern struct UiCtx *func_02035224(void);
extern int TOUCHPANEL_HitContSys(u32 a, u32 b);

int TOUCHPANEL_HitCont(const void *p)
{
    return TOUCHPANEL_HitContSys((u32)func_02035224(), (u32)p);
}
