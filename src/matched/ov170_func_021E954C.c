/*
 * function: func_021E954C
 * address:  0x021E954C
 * packet:   pkt_ov170_021E954C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    unsigned char pad[0x1A6];
    unsigned char flag : 1;
    unsigned char id : 7;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char state;
    unsigned char count;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
} Work;

typedef struct {
    unsigned char pad[0x28];
    int arg;
    Work *work;
} Sys;

int func_021E954C(Sys *p, int id, int lo, int arg)
{
    p->work->flag = 0;
    p->work->id = (unsigned char)id;
    p->work->lo = (unsigned char)lo;
    p->work->hi = 0;
    p->work->state = 0;
    p->work->count = 0;
    p->work->x = 0;
    p->work->y = 0;
    p->work->w = 0;
    p->work->h = 0;
    p->arg = arg;
    return 8;
}
