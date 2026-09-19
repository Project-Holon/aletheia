/*
 * function: func_02058180
 * address:  0x02058180
 * packet:   pkt_02057830
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned short u16;
typedef short s16;

struct A {
    int x;
    int y;
    int z;
    s16 scale;
};

struct B {
    int pad_00[2];
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
};

void func_02058180(struct A *a, struct B *b, volatile int *c)
{
    c[0] = c[0] + (a->scale * (a->x - b->f08 - b->f14) >> 12);
    c[1] = c[1] + (a->scale * (a->y - b->f0c - b->f18) >> 12);
    c[2] = c[2] + (a->scale * (a->z - b->f10 - b->f1c) >> 12);
}
