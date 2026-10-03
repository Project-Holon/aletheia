/*
 * function: func_022041E0
 * address: 0x022041E0
 * packet: pkt_ov094_022041E0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B22C 0x0204B22C arm
 *   func_02206A58 0x02206A58 thumb ov094
 *   func_022044C0 0x022044C0 thumb ov094
 *   func_022045A8 0x022045A8 thumb ov094
 *   func_02204838 0x02204838 thumb ov094
 *   func_02204698 0x02204698 thumb ov094
 *   func_02204960 0x02204960 thumb ov094
 *   func_0220687C 0x0220687C thumb ov094
 *   d_0220A4EC 0x0220A4EC data ov094 a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Main {
    char pad00[0x48];
    u32 f48;
    char pad4c[0x1c];
    unsigned int f0:1, st:3, pad4:15, mode:2, hi:11;
    char pad6c[0x18c];
    void *obj1f8;
    char pad1fc[0x2c];
    void *obj228;
    char pad22c[0x14];
    u16 h240;
} Main;
typedef struct { Main *main; int state, f8, fc, f10, f14, timer; } Ctx;
typedef struct { int a, b; } Pair;
extern const Pair d_0220A4EC[];
extern void func_020498F4(u32, u32, u32, u32, u32, u32, u16);
struct Bank;
struct Cfg;
struct Descriptor;
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_020409B4(u32 index);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_02206A58(Main *);
extern void func_022044C0(Main *, int, int, int, int);
extern void func_022045A8(Main *, int, int);
extern void func_02204838(Main *, int);
extern void func_02204698(Main *, int, int);
extern void func_02204960(Main *, int, int, int, int, int, int, int);
extern void func_0220687C(Main *, void *);
void func_022041E0(void *h, Ctx *c)
{
    switch (c->state) {
    case 0:
        func_020498F4(c->main->f48, 0x64, 4, 0, 0, 0, c->main->h240);
        func_02045374(c->main->obj228);
        func_02206A58(c->main);
        func_020409B4(6);
        func_022044C0(c->main, d_0220A4EC[c->main->mode].a, d_0220A4EC[c->main->mode].b, 8, 8);
        func_022045A8(c->main, 0, 0);
        func_02204838(c->main, 0);
        func_02204960(c->main, -1, 0, 0, 1, 1, 2, 0);
        c->timer = 4;
        c->state++;
        break;
    case 1:
        if (--c->timer == 0) {
            func_02204698(c->main, 0, 0);
            c->state++;
        }
        break;
    case 2:
    default:
        if (c->main->st == 0) {
            func_02045334(c->main->obj228);
            func_0204B22C(c->main->obj1f8, 1);
            func_02204960(c->main, 5, 0x100, 0xc0, 2, 2, 2, 2);
            func_0220687C(c->main, h);
        }
        break;
    }
}
