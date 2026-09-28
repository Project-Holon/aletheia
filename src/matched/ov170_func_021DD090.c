/*
 * function: func_021DD090
 * address:  0x021DD090
 * packet:   pkt_ov170_021DD090
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CF98 0x0202CF98 thumb
 *   func_0202CFC0 0x0202CFC0 thumb
 *   func_0202CF8C 0x0202CF8C thumb
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
    unsigned char pad[0x2C];
    Work *work;
} Sys;

extern void func_0202CF98(int, int, signed char *, signed char *);
extern void func_0202CFC0(int mgr, unsigned idx, unsigned short *w, unsigned short *h);
extern unsigned char func_0202CF8C(int mgr, unsigned idx);

void func_021DD090(Sys *p, unsigned idx)
{
    unsigned short w;
    unsigned short h;
    signed char pos[2];
    func_0202CF98(*(int *)((char *)p->work + 0x74), idx, &pos[1], &pos[0]);
    func_0202CFC0(*(int *)((char *)p->work + 0x74), idx, &w, &h);
    p->work->flag = 1;
    p->work->id = func_0202CF8C(*(int *)((char *)p->work + 0x74), idx);
    p->work->lo = 0xD;
    p->work->hi = 0xC;
    p->work->state = 0;
    p->work->count = 0;
    p->work->x = pos[1];
    p->work->y = pos[0];
    p->work->w = w;
    p->work->h = h;
}
