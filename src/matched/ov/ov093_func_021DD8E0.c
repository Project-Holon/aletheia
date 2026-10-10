/*
 * function: func_021DD8E0
 * address: 0x021DD8E0
 * packet: pkt_ov093_021DD8E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DD87C.c and filed here.
 *
 * symbols:
 *   d_021F1D6C 0x021F1D6C data ov093 a4
 */

int *func_021DD8E0(int *p);

/* 021DD8EC  shifted 3-arg wrapper -> func_021DD9E8(..., 0x4, 1) */
extern int d_021F1D6C[];

int *func_021DD8E0(int *p)
{
    *p = 5;
    return d_021F1D6C;
}
