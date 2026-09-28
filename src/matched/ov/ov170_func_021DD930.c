/*
 * function: func_021DD930
 * address:  0x021DD930
 * packet:   pkt_ov170_021DD930
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC7B8 0x021EC7B8 thumb
 *   func_021EC548 0x021EC548 thumb
 *   func_021EF4A4 0x021EF4A4 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021EC768 0x021EC768 thumb
 *   func_021ED75C 0x021ED75C thumb
 *   func_021ED7C4 0x021ED7C4 thumb
 */

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short f4;
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
} Move;

extern void func_021EC7B8(char *p, int i, unsigned j, int flag);
extern void func_021EC548(unsigned i, short *x, short *y, int mode);
extern int func_021EF4A4(int p);
extern void func_021EC000(char *p, int i, int v);
extern void func_021EC08C(char *p, int i, short a, short b, short c);
extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021ED75C(char *p, int i);
extern void func_021ED7C4(char *p, int i);

int func_021DD930(unsigned char *p)
{
    Move *m = *(Move **)(*(char **)(p + 0x2C) + 0x60);
    Entry *e;
    unsigned i;
    int k;
    short t[2];
    if (m->count == 8) {
        for (i = 0; i < 7; i++) {
            e = &m->e[i];
            if (e->used == 0)
                continue;
            func_021EC7B8(*(char **)(p + 0x2C), e->id, e->slot, 1);
            k = *(unsigned char *)(*(char **)(p + 0x2C) + e->id + 0x3DD2);
            if (e->slot < 0x1E) {
                func_021EC548(e->slot, &t[1], &t[0], p[0x1A]);
            } else if (e->slot < 0x24) {
                func_021EC548(e->slot, &t[1], &t[0], p[0x1A]);
                if (p[0x1A] == 2 && func_021EF4A4(*(int *)(*(char **)(p + 0x2C) + 0x74)) == 0)
                    t[0] += 0xC0;
            } else {
                if (e->id >= 0x1E) {
                    func_021EC548(0x24, &t[1], &t[0], p[0x1A]);
                    if (p[0x1A] == 2 && func_021EF4A4(*(int *)(*(char **)(p + 0x2C) + 0x74)) == 0)
                        t[0] += 0xC0;
                } else {
                    func_021EC548(e->id, &t[1], &t[0], p[0x1A]);
                }
                func_021EC000(*(char **)(p + 0x2C), k, 0);
            }
            func_021EC08C(*(char **)(p + 0x2C), k, t[1], t[0], 0);
            if (e->used == 2)
                func_021EC000(*(char **)(p + 0x2C), k, 0);
        }
        func_021ED75C((char *)p, p[0x16]);
        func_021ED7C4(*(char **)(p + 0x2C), 0x24);
        return 0;
    }
    m->count++;
    for (i = 0; i < 7; i++) {
        e = &m->e[i];
        if (e->used == 0)
            continue;
        k = *(unsigned char *)(*(char **)(p + 0x2C) + e->id + 0x3DD2);
        t[1] = e->x + ((unsigned)(m->count * e->vx) >> 16) * e->dx;
        t[0] = e->y + ((unsigned)(m->count * e->vy) >> 16) * e->dy;
        func_021EC08C(*(char **)(p + 0x2C), k, t[1], t[0], 0);
        func_021EC768(*(char **)(p + 0x2C), e->id, 0);
    }
    func_021ED75C((char *)p, p[0x16]);
    func_021ED7C4(*(char **)(p + 0x2C), 0x24);
    return 1;
}
