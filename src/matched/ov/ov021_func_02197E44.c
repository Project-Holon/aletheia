/*
 * function: func_02197E44
 * address: 0x02197E44
 * packet: pkt_ov021_02197E44
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

int func_02197E44(IrcTask *w);

int func_02197E44(IrcTask *w)
{
    u16 *p = w->data;
    int i = ++w->idx;
    if (i < p[1]) {
        w->state = 1;
        return 1;
    }
    w->data = p + 2;
    if (p[2] != 0xfe) {
        w->state = 0;
        return 1;
    }
    w->f4 = 1;
    w->state = 5;
    return 0;
}
