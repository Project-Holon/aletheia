/*
 * function: func_021DD88C
 * address: 0x021DD88C
 * packet: pkt_ov093_021DD88C
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
 *   d_021F1CF4 0x021F1CF4 data ov093 a4
 */

int *func_021DD88C(int *p);

/* 021DD898  shifted 3-arg wrapper -> func_021DD9E8(..., 0x2, 1) */
extern int d_021F1CF4[];

int *func_021DD88C(int *p)
{
    *p = 5;
    return d_021F1CF4;
}
