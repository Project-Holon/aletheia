/*
 * function: func_02203C2C
 * address: 0x02203C2C
 * packet: pkt_ov094_02203C2C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02206AF8 0x02206AF8 thumb ov094
 *   func_022043C0 0x022043C0 thumb ov094
 *   PALANM_RequestFadeOverwrite 0x02021848 thumb
 *   func_02040588 0x02040588 arm
 *   func_02206A14 0x02206A14 thumb ov094
 *   func_02205B80 0x02205B80 thumb ov094
 *   func_020498F4 0x020498F4 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045334 0x02045334 arm
 *   func_0204B22C 0x0204B22C arm
 *   func_022044C0 0x022044C0 thumb ov094
 *   func_022045A8 0x022045A8 thumb ov094
 *   func_02204838 0x02204838 thumb ov094
 *   func_02206A58 0x02206A58 thumb ov094
 *   func_02204698 0x02204698 thumb ov094
 *   func_02204960 0x02204960 thumb ov094
 *   func_0220687C 0x0220687C thumb ov094
 */
typedef unsigned short u16;
typedef struct Main {
    void *owner;
    unsigned char pad04[0x48 - 4];
    int f48;
    unsigned char pad4c[0x64 - 0x4c];
    void *pal;

    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[4];
    void *obj230;
    unsigned char pad234[0x240 - 0x234];
    u16 h240;
} Main;
typedef struct Ctx {
    Main *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
    int f1c;
    int mode;
} Ctx;
extern void func_020498F4(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
typedef unsigned int   u32;
struct Bank;
struct Cfg;
struct Descriptor;
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern void func_02045334(struct Descriptor *d);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_022044C0(Main *, int, int, int, int);
extern void func_022045A8(Main *, int, int);
extern void func_02204838(Main *, int);
extern void func_02206A58(char *p);
struct Obj;
extern void func_02204698(struct Obj *p, int a, int b);
extern void func_02204960(Main *, int, int, int, int, int, int, int);
extern void func_0220687C(char *, void *);
extern void func_02206A14(char *p);
extern void func_02205B80(char *p, int a);
typedef unsigned char u8;
typedef signed short s16;
extern void func_02206AF8(char *p);
extern void func_022043C0(Main *, int, int, int, int);
extern int PALANM_RequestFadeOverwrite(void *, u16, u16, s16, u8, u8, u16, void *);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_02203C2C(void *task, Ctx *c)
{
    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, 0x5d, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x6e, 5, 0, 0, 0, c->main->h240);
        func_02204960(c->main, 5, 0, 0xc0, 1, 1, 2, 0);
        c->state++;
        break;
    case 1:
        if (c->mode == 2 || c->mode == 5)
            func_02204698((struct Obj *)c->main, 0, 1);
        c->state++;
        c->timer = 4;
        break;
    case 2:
        if (--c->timer == 0) {
            func_022045A8(c->main, 0, 1);
            c->state++;
        }
        break;
    case 3:
        if (c->main->st == 0) {
            func_022043C0(c->main, 0x1000, 0x3000, 0x400, 0xa8);
            c->state++;
        }
        break;
    case 4:
        func_02040588(4, 0);
        func_02040588(5, 0);
        func_02040588(7, 1);
        c->state++;
        break;
    case 5:
    default:
        if (c->main->st == 0)
            func_0220687C((char *)c->main, task);
        break;
    }
}
