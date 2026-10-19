/*
 * function: POKETRADE_PROC_IsCurrentSideMonInvalid
 * address:  0x021D95D0
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Select the alternate buffer when the object is idle.
 *
 * symbols:
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb  ov119
 *   POKETRADE_PROC_IsMonBadEggOrInvalid  0x021D95A0  thumb  ov119
 */

extern int POKETRADE_PROC_IsHostSide(void *p);
extern void *POKETRADE_PROC_GetSideMon(void *p, int i);
typedef unsigned int   u32;
extern u32 POKETRADE_PROC_IsMonBadEggOrInvalid(void *mon);

int POKETRADE_PROC_IsCurrentSideMonInvalid(void *p)
{
    int b = 0;

    if (POKETRADE_PROC_IsHostSide(p))
        b = 1;
    return POKETRADE_PROC_IsMonBadEggOrInvalid(POKETRADE_PROC_GetSideMon(p, b));
}

