/*
 * function: func_021613A4
 * address: 0x021613A4
 * packet: pkt_ov010_021613A4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov010/event_field_proclink_p07.c and filed here.
 */

typedef unsigned char u8;
typedef struct { u8 pad00[0xc]; int f0C; } Sub_021613A4;
typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[8]; Sub_021613A4 *f18; } Work_021613A4;
typedef struct { u8 pad00[4]; int f04; } Evt_021613A4;
int func_021613A4(Work_021613A4 *w, Evt_021613A4 *e);

int func_021613A4(Work_021613A4 *w, Evt_021613A4 *e)
{
    if (w->f18->f0C == 8) {
        switch (e->f04) {
        case 0:
            return 0;
        default:
            return 1;
        }
    }
    switch (e->f04) {
    case 0:
        w->f0C = 2;
        return 4;
    default:
        return 1;
    }
}
