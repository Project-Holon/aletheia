/*
 * function: func_02203B08
 * address:  0x02203B08
 * packet:   pkt_ov094_02203B08
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020498F4  0x020498F4  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045334  0x02045334  arm
 *   func_0204B22C  0x0204B22C  arm
 *   func_02204960  0x02204960  thumb  ov094
 *   func_0220687C  0x0220687C  thumb  ov094
 */
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Main {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x1f8 - 0x4C];
    void *obj1f8;
    unsigned char pad1FC[0x228 - 0x1FC];
    void *obj228;
    unsigned char pad22C[0x240 - 0x22C];
    u16 h240;
} Main;

typedef struct Ctx {
    Main *main;
    int state;
    int f8;
    int fc;
} Ctx;

extern void func_020498F4(int a, int b, int c, int d, int e, int f, int g);
extern void func_02045374(void *p);
extern void func_020409B4(u8 id);
extern void func_02045334(void *p);
extern void func_0204B22C(void *bank, int mode);
extern void func_02204960(Main *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void func_0220687C(Main *m, int a);

void func_02203B08(int a0, Ctx *c)
{
    switch (c->state) {
    case 0:
        func_020498F4(c->main->f48, c->fc, 4, 0, 0, 0, c->main->h240);
        func_02204960(c->main, 5, 0, 0xc0, 2, 2, 2, 2);
        c->state = c->state + 1;
        break;
    case 1:
        func_02045374(c->main->obj228);
        func_020409B4(6);
        func_020498F4(c->main->f48, 0x68, 5, 0, 0, 0, c->main->h240);
        func_02045334(c->main->obj228);
        func_0204B22C(c->main->obj1f8, 1);
        func_02204960(c->main, 5, 0x100, 0xc0, 2, 2, 2, 2);
        func_0220687C(c->main, a0);
        break;
    }
}
