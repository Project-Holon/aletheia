/*
 * file:     btlv_effvm_p92.c
 * unit:     yes
 * function: func_02203978, func_02203A78
 * address:  0x02203978
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
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
struct Bank;
struct Cfg;
struct Descriptor;
struct Obj;
typedef unsigned short u16;

typedef struct Main_02203978 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4c[0x68 - 0x4c];
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
} Main_02203978;

typedef struct Ctx_02203978 {
    Main_02203978 *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
} Ctx_02203978;

typedef unsigned int   u32;

typedef struct Main_02203A78 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x50 - 0x4C];
    int f50;
    unsigned char pad54[0x228 - 0x54];
    void *obj228;
    unsigned char pad22C[0x240 - 0x22C];
    u16 h240;
} Main_02203A78;

typedef struct Ctx_02203A78 {
    Main_02203A78 *main;
    unsigned char pad04[0xC - 0x4];
    int f0c;
} Ctx_02203A78;

extern void func_020498F4(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern void func_02045334(struct Descriptor *d);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_022044C0(Main_02203978 *, int, int, int, int);
extern void func_022045A8(Main_02203978 *, int, int);
extern void func_02204838(Main_02203978 *, int);
extern void func_02206A58(char *p);
extern void func_02204698(struct Obj *p, int a, int b);
extern void func_02204960(Main_02203978 *, int, int, int, int, int, int, int);
extern void func_0220687C(char *, void *);
extern void func_02206A14(char *p);
extern void func_02205B80(char *p, int a);
void func_02203978(void *task, Ctx_02203978 *c);
void func_02203A78(int a0, Ctx_02203A78 *c);

void func_02203978(void *task, Ctx_02203978 *c)
{
    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, c->fc, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x68, 5, 0, 0, 0, c->main->h240);
        func_02045374(c->main->obj230);
        func_02206A14((char *)c->main);
        func_020409B4(6);
        func_02204960(c->main, 5, 0, 0xc0, 1, 1, 2, 0);
        c->state++;
        break;
    case 1:
        func_02204698((struct Obj *)c->main, 0, 1);
        c->timer = 4;
        c->state++;
        break;
    case 2:
        if (--c->timer == 0) {
            func_022044C0(c->main, 0, 0x1c0, 8, 8);
            func_022045A8(c->main, 0, 1);
            func_02204838(c->main, 1);
            c->state++;
        }
        break;
    case 3:
    default:
        if (c->main->st == 0) {
            func_02205B80((char *)c->main, 1);
            func_02045334(c->main->obj230);
            func_0220687C((char *)c->main, task);
        }
        break;
    }
}


void func_02203A78(int a0, Ctx_02203A78 *c)
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
