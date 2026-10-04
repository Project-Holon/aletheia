/*
 * function: func_021DE428
 * address:  0x021DE428
 * packet:   pkt_ov170_021DE428
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/ov170_func_021DE158.c.
 *
 * symbols:
 *   func_021DDE20 0x021DDE20 thumb
 *   func_021DDEFC 0x021DDEFC thumb
 *   func_021DDFD4 0x021DDFD4 thumb
 *   func_0201AA18 0x0201AA18 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23843.h"

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

extern int func_021DDE20(unsigned char *p, unsigned a, unsigned b);
extern void func_021DDEFC(unsigned char *p, Entry *e);
extern void func_021DDFD4(unsigned char *p, Entry *e);
extern unsigned func_0201AA18(void *party);

void func_021DE428(unsigned char *p, unsigned a, unsigned b)
{
    Move *m = *(Move * *)&((struct Obj23843 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    unsigned i;
    unsigned n;
    unsigned short t;
    Entry *e;
    for (i = 0; i < 7; i++) {
        m->e[i].id = 0;
        m->e[i].slot = 0;
        m->e[i].src = 0;
        m->e[i].used = 0;
    }
    if (b == 0xFF || func_021DDE20(p, a, b) == 0) {
        m->a = 0xFF;
        m->b = 0xFF;
        m->e[0].id = 0x24;
        t = a;
        m->e[0].slot = t;
        m->e[0].src = t;
        m->e[0].used = 1;
        m->e[1].id = t;
        m->e[1].slot = t;
        m->e[1].src = t;
        m->e[1].used = 1;
        func_021DDEFC(p, &m->e[0]);
        return;
    }
    m->a = a;
    m->b = b;
    n = func_0201AA18(((void **)((struct Obj00000 *)p)->f0)[2]);
    if (b < 0x1E) {
        unsigned k = a - 0x1E;
        for (i = k + 1; i < n; i++) {
            e = &m->e[i];
            t = i + 0x1E;
            e->id = t;
            e->slot = i + 0x1D;
            e->src = t;
            e->used = 1;
            func_021DDFD4(p, e);
        }
        m->e[k].id = 0x24;
        m->e[k].slot = b;
        m->e[k].src = a;
        m->e[k].used = 1;
        func_021DDFD4(p, &m->e[k]);
        e = &m->e[n];
        t = b;
        e->id = t;
        e->slot = n + 0x1D;
        e->src = t;
        e->used = 1;
        func_021DDFD4(p, e);
    }
}
