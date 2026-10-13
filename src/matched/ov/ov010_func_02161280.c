/*
 * function: EVENT_FIELD_PROCLINK_ReturnTownMapSelect
 * address: 0x02161280
 * packet: pkt_ov010_02161280
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
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[0x18]; int f28; u8 pad2C[4]; u32 f30; u32 f34; u32 f38; u32 f3C; } Sub_02161280;
typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[8]; Sub_02161280 *f18; } Work_02161280;
typedef struct { u8 pad00[4]; int f04; u16 f08; u8 pad0A[2]; u32 f0C; u32 f10; } Evt_02161280;
int EVENT_FIELD_PROCLINK_ReturnTownMapSelect(Work_02161280 *w, Evt_02161280 *e);

int EVENT_FIELD_PROCLINK_ReturnTownMapSelect(Work_02161280 *w, Evt_02161280 *e)
{
    int st = w->f18->f0C;
    if (st == 7) {
        switch (e->f04) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return 1;
        }
    } else if (st == 2) {
        switch (e->f04) {
        case 0:
            w->f0C = 2;
            return 4;
        case 1:
            return 1;
        default:
            return 1;
        }
    } else if (st == 0) {
        switch (e->f04) {
        case 0:
            w->f0C = 0;
            return 4;
        case 1:
            return 1;
        case 2:
            w->f18->f28 = 4;
            w->f18->f30 = e->f08;
            w->f18->f34 = e->f0C;
            w->f18->f38 = e->f10;
            w->f18->f3C = 0;
            return 2;
        default:
            return 1;
        }
    }
    return 1;
}
