/*
 * function: func_02197DE8
 * address: 0x02197DE8
 * packet: pkt_ov021_02197DE8
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/ircbattlemenu.c and filed here.
 */

typedef unsigned short u16;

typedef struct IrcTask {
    int state;
    int f4;
    int idx;
    int fc;
    u16 *data;
} IrcTask;

int func_02197DE8(IrcTask *w);

int func_02197DE8(IrcTask *w)
{
    w->idx = 0;
    w->state = 1;
    return 1;
}
