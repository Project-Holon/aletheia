/*
 * function: func_021B7B08
 * address:  0x021B7B08
 * packet:   pkt_ov070_021B7B08
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB0F8  0x021BB0F8  thumb  ov070
 *   func_021B619C  0x021B619C  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BADAC  0x021BADAC  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7B80  0x021B7B80  thumb  ov070
 */

typedef unsigned short u16;

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x7F4 - 0x546];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj;

extern void func_021BB0F8(Obj *o);
extern int func_021B619C(unsigned int a, int b, u16 c);
extern void func_02045CAC(void *arc, unsigned int entry, unsigned int dst);
extern void func_0201EFA4(void *obj, unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
extern void func_0201F250(void *obj, void *a, void *b);
extern void func_021BADAC(Obj *o);
extern void func_021B6100(Obj *o, void *fn);
extern void func_021B7B80();

void func_021B7B08(Obj *o)
{
    int v;

    func_021BB0F8(o);
    v = func_021B619C(o->f84C, o->f7F4, o->f544);
    func_02045CAC(o->f51C, 0x4F, o->f524);
    func_0201EFA4(o->f520, 0, v, 7, 0, 1);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100(o, (void *)func_021B7B80);
}
