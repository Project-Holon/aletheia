/*
 * file:     unit_021B1498_p06.c
 * unit:     yes
 * function: func_021B21A4
 * address:  0x021B21A4
 * packet:   pkt_ov013_021B21A4
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * func_021B2A20 takes the id: r0 stays live through the guards, so their
 * loads use r1. id must be unsigned char (plain strb r4 stores).
 *
 * symbols:
 *   d_021B60D8     0x021B60D8  data  ov013  a4
 *   d_021B4BD0     0x021B4BD0  data  ov013  a4
 *   func_021B2A20  0x021B2A20  arm   ov013
 *   func_021B1F2C  0x021B1F2C  arm   ov013
 */

struct Sess {
    unsigned char id;
    unsigned char pad[3];
    void (*cb)(int, int, void *, unsigned int);
    unsigned int arg;
    unsigned int pad2;
    int f10;
};

struct Chan {
    unsigned char pad[4];
    unsigned char f4;
    unsigned char f5;
    unsigned char pad6[2];
    unsigned int f8;
    int fc;
};

extern struct Sess d_021B60D8;
extern int d_021B4BD0;
struct N;
extern struct N *func_021B2A20(int id);
struct Node;
extern struct Node *func_021B1F2C(unsigned int i);

int func_021B21A4(unsigned char id)
{
    struct Chan *c;

    if (d_021B60D8.f10 != 3)
        return -2;
    if (d_021B4BD0 == 3)
        return -6;
    if (id == d_021B60D8.id)
        return -1;
    if (func_021B2A20(id))
        return 0;
    c = (struct Chan *)func_021B1F2C(id);
    if (c == 0)
        return -1;
    c->f4 = id;
    c->f5 = id;
    c->fc = 2;
    c->f8 = 1 << id;
    d_021B60D8.cb(id, 7, c, d_021B60D8.arg);
    d_021B4BD0++;
    return 0;
}
