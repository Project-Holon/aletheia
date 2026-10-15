/*
 * function: BOX2_MAIN_MoveCursorWithMon
 * address:  0x021DE158
 * packet:   pkt_ov170_021DE158
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_AdvanceMover 0x021DDEFC thumb
 *   BOX2_MAIN_HandleMonPickup 0x021DDC00 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   BOX2_MAIN_UpdateMoverY 0x021DE07C thumb
 *   BOX2_MAIN_StepMover 0x021DE120 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23841.h"

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
    unsigned req;
} Move;

extern void BOX2_MAIN_AdvanceMover(unsigned char *p, Entry *e);
extern int BOX2_MAIN_HandleMonPickup(unsigned char *p, unsigned a, unsigned b);
extern unsigned POKEPARTY_GetCount(void *party);
extern void BOX2_MAIN_UpdateMoverY(unsigned char *p, Entry *e);
extern void BOX2_MAIN_StepMover(char *p, int a, int b);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);

int BOX2_MAIN_MoveCursorWithMon(unsigned char *p, unsigned a, unsigned b)
{
    Move *m = *(Move * *)&((struct Obj23841 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
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
    m->req = b;
    if (b == 0xFF) {
        m->a = 0xFF;
        m->b = 0xFF;
        m->e[0].id = 0x24;
        t = a;
        m->e[0].slot = t;
        m->e[0].src = t;
        m->e[0].used = 1;
        if (p[0x14] == p[0x17]) {
            m->e[1].id = t;
            m->e[1].slot = t;
            m->e[1].src = t;
            m->e[1].used = 1;
        }
        BOX2_MAIN_AdvanceMover(p, &m->e[0]);
        return 0;
    }
    if ((a == b && (a >= 0x1E || p[0x14] == p[0x17])) || BOX2_MAIN_HandleMonPickup(p, a, b) == 0) {
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
        BOX2_MAIN_AdvanceMover(p, &m->e[0]);
        return 0;
    }
    m->a = a;
    m->b = b;
    n = POKEPARTY_GetCount(((void **)((struct Obj00000 *)p)->f0)[2]);
    if (b >= 0x24) {
        m->e[0].id = 0x24;
        m->e[0].slot = b;
        m->e[0].src = 0x24;
        m->e[0].used = 1;
        BOX2_MAIN_AdvanceMover(p, &m->e[0]);
        if (a >= 0x1E) {
            for (i = a - 0x1D; i < n; i++) {
                e = &m->e[i];
                t = i + 0x1E;
                e->id = t;
                e->slot = i + 0x1D;
                e->src = t;
                e->used = 1;
                BOX2_MAIN_UpdateMoverY(p, e);
            }
            e = &m->e[n];
            t = a;
            e->id = t;
            e->slot = n + 0x1D;
            e->src = t;
            e->used = 1;
            BOX2_MAIN_UpdateMoverY(p, e);
        }
        return 1;
    }
    if (p[0x14] != p[0x17] && a < 0x1E) {
        if (b >= 0x1E && b > n + 0x1E)
            b = n + 0x1E;
        m->e[0].id = 0x24;
        t = b;
        m->e[0].slot = t;
        m->e[0].src = a;
        m->e[0].used = 1;
        m->e[1].id = t;
        m->e[1].slot = t;
        m->e[1].src = t;
        m->e[1].used = 2;
        BOX2_MAIN_AdvanceMover(p, &m->e[0]);
        BOX2_MAIN_AdvanceMover(p, &m->e[1]);
        return 1;
    }
    if (a < 0x1E) {
        if (b < 0x1E)
            BOX2_MAIN_StepMover((char *)p, a, b);
        else if (b - 0x1E < n)
            BOX2_MAIN_StepMover((char *)p, a, b);
        else
            BOX2_MAIN_StepMover((char *)p, a, n + 0x1E);
    } else if (b < 0x1E) {
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, b, p[0x14], 0xA9, 0) != 0) {
            BOX2_MAIN_StepMover((char *)p, a, b);
        } else {
            unsigned k = a - 0x1E;
            for (i = k + 1; i < n; i++) {
                e = &m->e[i];
                t = i + 0x1E;
                e->id = t;
                e->slot = i + 0x1D;
                e->src = t;
                e->used = 1;
                BOX2_MAIN_AdvanceMover(p, e);
            }
            m->e[k].id = 0x24;
            m->e[k].slot = b;
            m->e[k].src = a;
            m->e[k].used = 1;
            BOX2_MAIN_AdvanceMover(p, &m->e[k]);
            e = &m->e[n];
            t = b;
            e->id = t;
            e->slot = n + 0x1D;
            e->src = t;
            e->used = 1;
            BOX2_MAIN_AdvanceMover(p, e);
        }
    } else if (b - 0x1E < n) {
        BOX2_MAIN_StepMover((char *)p, a, b);
    } else {
        unsigned k = a - 0x1E;
        for (i = k + 1; i < n; i++) {
            e = &m->e[i];
            t = i + 0x1E;
            e->id = t;
            e->slot = i + 0x1D;
            e->src = t;
            e->used = 1;
            BOX2_MAIN_AdvanceMover(p, e);
        }
        m->e[k].id = 0x24;
        m->e[k].slot = n + 0x1D;
        m->e[k].src = a;
        m->e[k].used = 1;
        BOX2_MAIN_AdvanceMover(p, &m->e[k]);
    }
    return 1;
}
