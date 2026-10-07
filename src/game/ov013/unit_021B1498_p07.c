/*
 * file:     unit_021B1498_p07.c
 * unit:     yes
 * function: func_021B2254, func_021B22B4
 * address:  0x021B2254
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   d_021B4BD0  0x021B4BD0  data  ov013  a4
 *   func_021B2A20  0x021B2A20  arm  ov013
 *   g_021B4BE0     0x021B4BE0  data  a4
 *   g_021B4BD0     0x021B4BD0  data  a4
 *   g_021B60D8     0x021B60D8  data  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_020870D0  0x020870D0  arm
 */
#include "../../matched/include/G_Sess.h"

struct N;
typedef struct Ctx {
    int f0;
    int (*cb)(int, int, int, int);
    int arg;
    int fC;
    int state;
} Ctx;

struct Node {
    unsigned int f0;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
    unsigned int f8;
    unsigned int fc;
    unsigned int f10;
    struct Node *next;
};

struct Pool {
    struct Node *nodes;
    unsigned int f4;
    void *tick;
    unsigned int mul;
    unsigned int add;
    struct Node freeList;
    struct Node active;
};

struct Config {
    struct Node *nodes;
    unsigned int count;
};

struct Stats {
    unsigned int f0;
    unsigned int f4;
};

extern struct N *func_021B2A20(int id);
extern void func_02082BCC(void *dst, int data, unsigned long size);
extern unsigned long long func_020870D0(void);
int func_021B2254(int a);
int func_021B22B4(struct Config *cfg);
extern Ctx d_021B60D8;
extern int d_021B4BD0;
extern struct Pool g_021B4BE0;
extern struct Stats g_021B4BD0;
extern struct Sess g_021B60D8;


int func_021B2254(int a)
{
    int r;

    if (d_021B60D8.state != 3)
        return -2;
    r = (int)func_021B2A20(a);
    if (r == 0)
        return -1;
    d_021B60D8.cb(a, 9, r, d_021B60D8.arg);
    d_021B4BD0--;
    return 0;
}


int func_021B22B4(struct Config *cfg)
{
    unsigned int i;

    if (cfg->nodes == 0 || cfg->count == 0 || cfg->count > 8)
        return 0;
    g_021B4BE0.nodes = cfg->nodes;
    func_02082BCC(cfg->nodes, 0, cfg->count * sizeof(struct Node));
    func_02082BCC(&g_021B4BE0.active, 0, sizeof(struct Node));
    func_02082BCC(&g_021B4BE0.freeList, 0, sizeof(struct Node));
    for (i = 0; i < cfg->count - 1; i++)
        g_021B4BE0.nodes[i].next = &g_021B4BE0.nodes[i + 1];
    (g_021B4BE0.nodes + cfg->count - 1)->next = 0;
    g_021B4BE0.f4 = 0;
    g_021B4BD0.f4 = 0;
    g_021B4BD0.f0 = 0;
    g_021B60D8.f14 = 0;
    g_021B4BE0.tick = (void *)func_020870D0;
    g_021B4BE0.mul = 0x5D588B65;
    g_021B4BE0.add = 0x269EC3;
    return 1;
}
