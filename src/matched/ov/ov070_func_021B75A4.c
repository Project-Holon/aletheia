/*
 * function: func_021B75A4
 * address:  0x021B75A4
 * packet:   pkt_ov070_021B75A4
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02006238  0x02006238  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_020212B0  0x020212B0  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7584  0x021B7584  thumb  ov070
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x84C - 0x52C];
    unsigned int f84C;
} Obj;

extern int func_02006238(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_02045CAC(void *arc, unsigned int entry, unsigned int dst);
extern u16 func_020212B0(u16 id);
extern void func_0201EF34(void *a, int b, unsigned int c);
extern void func_0201F250(void *obj, void *a, void *b);
extern void func_021BACF0(Obj *o, int v);
extern void func_021B6100(Obj *o, void *fn);
extern void func_021B7584();

void func_021B75A4(Obj *o)
{
    if (func_02006238() == 1)
        return;
    if ((func_020362DC() & 3) == 0 && func_02035C60() == 0)
        return;
    func_02045CAC(o->f51C, 0x3E, o->f524);
    func_0201EF34(o->f520, 0, func_020212B0(o->f84C));
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BACF0(o, 1);
    func_021B6100(o, (void *)func_021B7584);
}
