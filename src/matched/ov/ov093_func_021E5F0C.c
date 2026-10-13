/*
 * function: func_021E5F0C
 * address: 0x021E5F0C
 * packet: pkt_ov093_021E5F0C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E5B78.c and filed here.
 *
 * symbols:
 *   d_021F2EF0 0x021F2EF0 data ov093 a4
 */

int *func_021E5F0C(int *p);

/* 021E5F18  shape F1: gate on BTL_EVENT_GetVar(3) */
extern int d_021F2EF0[];

int *func_021E5F0C(int *p)
{
    *p = 5;
    return d_021F2EF0;
}
