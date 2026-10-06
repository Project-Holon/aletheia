/*
 * function: func_02203A78
 * address:  0x02203A78
 * packet:   pkt_ov094_02203A78
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020498F4  0x020498F4  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045334  0x02045334  arm
 *   func_0220687C  0x0220687C  thumb  ov094
 */
typedef unsigned short u16;

typedef struct Main {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x50 - 0x4C];
    int f50;
    unsigned char pad54[0x228 - 0x54];
    void *obj228;
    unsigned char pad22C[0x240 - 0x22C];
    u16 h240;
} Main;

typedef struct Ctx {
    Main *main;
    unsigned char pad04[0xC - 0x4];
    int f0c;
} Ctx;

extern void func_020498F4(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
typedef unsigned int   u32;
struct Cfg;
struct Descriptor;
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern void func_02045334(struct Descriptor *d);
extern void func_0220687C(char *p, void *q);

void func_02203A78(int a0, Ctx *c)
{
    int z = 0;

    func_020498F4((void *)c->main->f48, 0x5d, 4, 0, z, z, c->main->h240);
    func_020498F4((void *)c->main->f48, c->f0c, 4, 0x440, 0x380, z, c->main->h240);
    func_02045374(c->main->obj228);
    func_020409B4(6);
    if (c->main->f50 == 2) {
        func_020498F4((void *)c->main->f48, 0x6a, 5, 0, z, z, c->main->h240);
    } else {
        func_020498F4((void *)c->main->f48, 0x69, 5, 0, z, z, c->main->h240);
    }
    func_02045334(c->main->obj228);
    func_0220687C((char *)c->main, (void *)a0);
}
