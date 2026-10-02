/*
 * function: func_021B7868
 * address:  0x021B7868
 * packet:   pkt_ov070_021B7868
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BADF0  0x021BADF0  thumb  ov070
 *   func_021B7DF4  0x021B7DF4  thumb  ov070
 *   func_021B8DAC  0x021B8DAC  thumb  ov070
 *   func_020362DC  0x020362DC  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021B7DD0  0x021B7DD0  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_021B6204  0x021B6204  thumb  ov070
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BADAC  0x021BADAC  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B77E4  0x021B77E4  thumb  ov070
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_021B8DCC  0x021B8DCC  thumb  ov070
 */

typedef unsigned int u32;

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x7F4 - 0x52C];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj;

extern int func_021BADF0(Obj *o);
extern int func_021B7DF4(Obj *o);
extern int func_021B8DAC(void);
extern u32 func_020362DC(void);
extern void func_020355D8(int v);
extern void func_020061E4(unsigned int id);
extern void func_021B7DD0(Obj *o);
extern void func_02045CAC(void *arc, unsigned int entry, unsigned int dst);
extern void func_021B6204(Obj *o, int a, unsigned int b, int c, int d);
extern void func_0201EFA4(void *obj, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
extern void func_0201F250(void *obj, void *a, void *b);
extern void func_021BADAC(Obj *o);
extern void func_021B6100(Obj *o, void *fn);
extern void func_021B77E4();
extern void func_021B8C1C(Obj *o, int a, void *fn);
extern void func_021B8DCC();

void func_021B7868(Obj *o)
{
    int r;

    if (func_021BADF0(o) == 0)
        return;
    if (func_021B7DF4(o) == 1)
        return;
    r = func_021B8DAC();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        func_021B7DD0(o);
        func_02045CAC(o->f51C, 0x37, o->f524);
        func_021B6204(o, 0, o->f84C, o->f7F4 > 1, 0);
        func_0201EFA4(o->f520, 1, o->f7F4, 3, 0, 1);
        func_0201F250(o->f520, o->f528, (void *)o->f524);
        func_021BADAC(o);
        func_021B6100(o, (void *)func_021B77E4);
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        func_021B8C1C(o, 4, (void *)func_021B8DCC);
    }
}
