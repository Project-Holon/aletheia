/*
 * function: func_021E19B4
 * address: 0x021E19B4
 * packet: pkt_ov093_021E19B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E18EC.c and filed here.
 *
 * symbols:
 *   d_021F2C30 0x021F2C30 data ov093 a4
 */

int *func_021E19B4(int *p);

/* 021E19C0  shifted 4-arg wrapper -> func_021E19F8(..., 0x0) */
extern int d_021F2C30[];

int *func_021E19B4(int *p)
{
    *p = 3;
    return d_021F2C30;
}
