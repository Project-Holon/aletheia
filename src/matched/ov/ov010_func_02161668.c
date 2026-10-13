/*
 * function: EVENT_FIELD_PROCLINK_ReturnReport
 * address: 0x02161668
 * packet: pkt_ov010_02161668
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov010/event_field_proclink_p08.c and filed here.
 */

typedef unsigned char u8;
typedef struct { u8 pad00[0xc]; int f0C; } Sub_02161668;
typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[8]; Sub_02161668 *f18; } Work_02161668;
typedef struct { u8 pad00[0xc]; int f0C; } Evt_02161668;
int EVENT_FIELD_PROCLINK_ReturnReport(Work_02161668 *w, Evt_02161668 *e);

int EVENT_FIELD_PROCLINK_ReturnReport(Work_02161668 *w, Evt_02161668 *e)
{
    if (w->f18->f0C == 0xb) {
        switch (e->f0C) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return 0;
        }
    }
    switch (e->f0C) {
    case 0:
        w->f0C = 2;
        return 4;
    case 1:
        return 1;
    default:
        return 0;
    }
}
