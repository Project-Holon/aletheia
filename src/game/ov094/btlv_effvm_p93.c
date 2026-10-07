/*
 * file:     btlv_effvm_p93.c
 * unit:     yes
 * function: func_02203B08, func_02203BC0
 * address:  0x02203B08
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
 *   func_020498F4  0x020498F4  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045334  0x02045334  arm
 *   func_0204B22C  0x0204B22C  arm
 *   func_02204960  0x02204960  thumb  ov094
 *   func_0220687C  0x0220687C  thumb  ov094
 *   func_022043C0  0x022043C0  thumb  ov094
 *   func_02040588  0x02040588  arm
 */
struct Bank;
struct Cfg;
struct Descriptor;
typedef unsigned short u16;

typedef unsigned char u8;

typedef struct Main_02203B08 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x1f8 - 0x4C];
    void *obj1f8;
    unsigned char pad1FC[0x228 - 0x1FC];
    void *obj228;
    unsigned char pad22C[0x240 - 0x22C];
    u16 h240;
} Main_02203B08;

typedef struct Ctx_02203B08 {
    Main_02203B08 *main;
    int state;
    int f8;
    int fc;
} Ctx_02203B08;

typedef unsigned int   u32;

typedef struct Main_02203BC0 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
} Main_02203BC0;

typedef struct Ctx_02203BC0 {
    Main_02203BC0 *main;
    int state;
} Ctx_02203BC0;

extern void func_020498F4(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern void func_02045334(struct Descriptor *d);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_02204960(Main_02203B08 *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void func_0220687C(char *p, void *q);
extern void func_022043C0(Main_02203BC0 *m, int a1, int a2, int a3, int a4);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_02203B08(int a0, Ctx_02203B08 *c);
void func_02203BC0(int a0, Ctx_02203BC0 *c);


void func_02203B08(int a0, Ctx_02203B08 *c)
{
    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, c->fc, 4, 0, 0, 0, c->main->h240);
        func_02204960(c->main, 5, 0, 0xc0, 2, 2, 2, 2);
        c->state = c->state + 1;
        break;
    case 1:
        func_02045374(c->main->obj228);
        func_020409B4(6);
        func_020498F4((void *)c->main->f48, 0x68, 5, 0, 0, 0, c->main->h240);
        func_02045334(c->main->obj228);
        func_0204B22C(c->main->obj1f8, 1);
        func_02204960(c->main, 5, 0x100, 0xc0, 2, 2, 2, 2);
        func_0220687C((char *)c->main, (void *)a0);
        break;
    }
}


void func_02203BC0(int a0, Ctx_02203BC0 *c)
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
