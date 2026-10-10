/*
 * function: func_021E2370
 * address: 0x021E2370
 * packet: pkt_ov093_021E2370
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E2188.c and filed here.
 *
 * symbols:
 *   d_021F2E78 0x021F2E78 data ov093 a4
 */

int *func_021E2370(int *p);

/*
 * lever: Word return from func_021E896C reserves the unused aggregate slot;
 * u8 c schedules its stack reload after the zero store at 021E23CE.
 */
extern int d_021F2E78[];

int *func_021E2370(int *p)
{
    *p = 5;
    return d_021F2E78;
}
