/*
 * function: func_02203E30
 * address: 0x02203E30
 * packet: pkt_ov094_02203E30
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   func_02206AF8 0x02206AF8 thumb ov094
 *   func_02204960 0x02204960 thumb ov094
 *   func_022043C0 0x022043C0 thumb ov094
 *   PALANM_RequestFadeOverwrite 0x02021848 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B22C 0x0204B22C arm
 *   func_022044C0 0x022044C0 thumb ov094
 *   func_022045A8 0x022045A8 thumb ov094
 *   func_02204838 0x02204838 thumb ov094
 *   func_02204698 0x02204698 thumb ov094
 *   func_0220687C 0x0220687C thumb ov094
 *   d_0220A4EC 0x0220A4EC data ov094 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Main {
    void *owner;
    char pad04[0x44];
    u32 f48;
    char pad4c[0x18];
    void *pal64;
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
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
struct Obj;
extern void func_02206AF8(char *p);
extern void func_02204960(Main *, int, int, int, int, int, int, int);
extern void func_022043C0(Main *, int, int, int, int);
extern int PALANM_RequestFadeOverwrite(void *, u16, u16, s16, u8, u8, u16, void *);
struct Bank;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_020409B4(u32 index);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_022044C0(Main *, int, int, int, int);
extern void func_022045A8(Main *, int, int);
extern void func_02204838(Main *, int);
extern void func_02204698(struct Obj *p, int a, int b);
extern void func_0220687C(char *p, void *q);
void func_02203E30(void *h, Ctx *c)
{
    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, 0x5d, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x6f, 5, 0, 0, 0, c->main->h240);
        func_02206AF8((char *)c->main);
        func_02204960(c->main, 5, 0, 0, 0, 0, 2, 1);
        func_022043C0(c->main, 0x3000, 0x1000, -0x400, 0x98);
        func_020409B4(6);
        PALANM_RequestFadeOverwrite(c->main->pal64, 2, 3, 1, 0xc, 0, 0x842, c->main->owner);
        c->state++;
        break;
    case 1:
        if (c->main->st == 0) {
            func_020498F4((void *)c->main->f48, 0x64, 4, 0, 0, 0, c->main->h240);
            BMP_WIN_MakeScreen(c->main->obj228);
            func_020409B4(6);
            func_022044C0(c->main, d_0220A4EC[c->main->mode].a, d_0220A4EC[c->main->mode].b, 8, 8);
            func_022045A8(c->main, 0, 0);
            func_02204838(c->main, 0);
            func_02204960(c->main, -1, 0, 0, 1, 1, 2, 0);
            c->timer = 4;
            c->state++;
        }
        break;
    case 2:
        if (--c->timer == 0) {
            func_02204698((struct Obj *)c->main, 0, 0);
            c->state++;
        }
        break;
    case 3:
    default:
        if (c->main->st == 0) {
            BMP_WIN_TransferChars(c->main->obj228);
            func_0204B22C(c->main->obj1f8, 1);
            func_02204960(c->main, 5, 0x100, 0xc0, 2, 2, 2, 2);
            func_0220687C((char *)c->main, h);
        }
        break;
    }
}
