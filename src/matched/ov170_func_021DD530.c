/*
 * function: func_021DD530
 * address:  0x021DD530
 * packet:   pkt_ov170_021DD530
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02007610 0x02007610 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021DD330 0x021DD330 thumb
 *   func_021DD39C 0x021DD39C thumb
 *   func_021DD3DC 0x021DD3DC thumb
 *   func_021DD414 0x021DD414 thumb
 *   func_021DD42C 0x021DD42C thumb
 *   func_021DD464 0x021DD464 thumb
 *   func_021DD4B8 0x021DD4B8 thumb
 *   func_021DD810 0x021DD810 thumb
 *   func_021EDAB0 0x021EDAB0 thumb
 *   func_021EDB34 0x021EDB34 thumb
 */

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short src;
    unsigned short used;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Entry;

typedef struct {
    Entry e[7];
    int count;
    unsigned a;
    unsigned b;
} Move;

extern unsigned func_0201AA18(void *party);
extern void func_02007610(void *save, unsigned b1, unsigned a, unsigned b2, unsigned c);
extern unsigned func_021DD25C(unsigned char *p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021DD330(unsigned char *p, Entry *a, Entry *b);
extern void func_021DD39C(unsigned char *p, Entry *a);
extern void func_021DD3DC(unsigned char *p, Entry *a);
extern void func_021DD414(unsigned char *p, Move *m);
extern void func_021DD42C(unsigned char *p, Entry *a);
extern void func_021DD464(unsigned char *p, unsigned box, unsigned a, unsigned b);
extern void func_021DD4B8(unsigned char *p, unsigned a, unsigned b);
extern void func_021DD810(unsigned char *p, unsigned b, unsigned a, unsigned box);
extern void func_021EDAB0(unsigned char *p, unsigned box);
extern void func_021EDB34(unsigned char *p, unsigned box);

void func_021DD530(unsigned char *p)
{
    Move *m = *(Move **)(*(char **)(p + 0x2C) + 0x60);
    unsigned short n;
    if (m->a == 0xFF)
        return;
    n = func_0201AA18(((void **)*(void **)p)[2]);
    if (m->b >= 0x24) {
        if (m->a < 0x1E)
            func_021DD464(p, p[0x17], m->a, m->b - 0x24);
        else
            func_021DD4B8(p, m->a, m->b - 0x24);
        return;
    }
    if (m->a < 0x1E) {
        if (m->b < 0x1E) {
            func_02007610(((void **)*(void **)p)[1], p[0x17], m->a, p[0x14], m->b);
            func_021EDAB0(p, p[0x14]);
            func_021EDB34(p, p[0x14]);
            if (p[0x14] != p[0x17]) {
                func_021EDAB0(p, p[0x17]);
                func_021EDB34(p, p[0x17]);
            }
            return;
        }
        if (m->b - 0x1E < n) {
            func_021DD330(p, &m->e[0], &m->e[1]);
            func_021DD810(p, m->b, m->a, p[0x17]);
        } else {
            func_021DD39C(p, &m->e[0]);
            func_021DD810(p, m->b, m->a, p[0x17]);
        }
        return;
    }
    if (m->b < 0x1E) {
        if (func_021DD25C(p, m->b, p[0x14], 0xA9, 0)) {
            func_021DD330(p, &m->e[1], &m->e[0]);
            func_021DD810(p, m->b, m->a, p[0x14]);
        } else {
            func_021DD3DC(p, &m->e[m->a - 0x1E]);
            func_021DD810(p, m->b, m->a, p[0x14]);
        }
        return;
    }
    if (m->b - 0x1E < n)
        func_021DD414(p, m);
    else
        func_021DD42C(p, &m->e[m->a - 0x1E]);
}
