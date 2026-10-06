/*
 * function: func_02203BC0
 * address:  0x02203BC0
 * packet:   pkt_ov094_02203BC0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_022043C0  0x022043C0  thumb  ov094
 *   func_02040588  0x02040588  arm
 *   func_0220687C  0x0220687C  thumb  ov094
 */
typedef struct Main {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
} Main;

typedef struct Ctx {
    Main *main;
    int state;
} Ctx;

extern void func_022043C0(Main *m, int a1, int a2, int a3, int a4);
typedef unsigned int   u32;
extern void func_02040588(u32 which, unsigned char enable);
extern void func_0220687C(char *p, void *q);

void func_02203BC0(int a0, Ctx *c)
{
    switch (c->state) {
    case 0:
        func_022043C0(c->main, 0x1000, 0x3000, 0x400, 0xa8);
        c->state = c->state + 1;
        break;
    case 1:
        func_02040588(4, 0);
        func_02040588(5, 0);
        func_02040588(7, 1);
        c->state = c->state + 1;
        break;
    case 2:
    default:
        if (c->main->st == 0)
            func_0220687C((char *)c->main, (void *)a0);
        break;
    }
}
