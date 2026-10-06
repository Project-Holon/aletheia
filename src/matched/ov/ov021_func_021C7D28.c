/*
 * function: func_021C7D28
 * address:  0x021C7D28
 * packet:   pkt_ov021_021C7D28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_021C7D78  0x021C7D78  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    int f0;
    int f4;
    void *f8;
    u8 fC;
    u8 padD;
    u16 fE;
    u16 f10;
    u16 f12;
} Obj;

typedef unsigned int   u32;
extern u16 func_02188C84(u8 *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_02188CD0(u8 *p);
extern void *func_021A3074(unsigned char *p);
extern int func_021C6C70(int, int, int (*)(Obj *));
extern u32 func_021C6CCC(u8 *p);
extern int func_021C7D78(Obj *);

int func_021C7D28(int a, int b, u16 c, u16 d)
{
    int w;
    void *s;
    int h;
    Obj *o;

    w = func_02188C84((u8 *)a);
    s = func_02188CB4((void *)a);
    h = func_021C6C70(w, 0x14, func_021C7D78);
    o = (Obj *)func_021C6CCC((u8 *)h);
    o->f0 = a;
    o->f4 = func_02188CD0((u8 *)a);
    o->f8 = func_021A3074((void *)s);
    o->fC = 0;
    o->fE = 0;
    o->f10 = c;
    o->f12 = d;
    return h;
}
