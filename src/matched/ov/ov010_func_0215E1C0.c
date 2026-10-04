/*
 * function: func_0215E1C0
 * address:  0x0215E1C0
 * packet:   pkt_ov010_0215E1C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command with a six-way sub-command switch over an ov021 service
 * (0x021B76B4..0x021B7794) on the save-data block func_02009448 returns;
 * sub-commands 0, 1 and 4 write a halfword result through the destination
 * variable, 5 formats a value into the word set.
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_02009370  0x02009370  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021B76F8  0x021B76F8  thumb  ov021
 *   func_021B7794  0x021B7794  thumb  ov021
 *   func_021B76B4  0x021B76B4  thumb  ov021
 *   func_021B7740  0x021B7740  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0201EF5C  0x0201EF5C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *c, void *vm);
extern u16 func_0215A5CC(void *vm);
extern void *func_0215A5DC(void *vm);
extern void *func_0215A5E4(void *vm);
extern void *func_0215A5F4(void *vm);
struct Big;
struct Ctx;
struct Sub02009448Obj;
struct WordSet;
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern int func_02009370(void *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021B76F8(void *p, int key, void *q);
extern void *func_021B7794(void *p);
extern void func_021B76B4(void *a, u16 b, void *c);
extern u32 func_021B7740(void *a, u16 b, void *c, u16 d);
extern void func_0215897C(void *a, void *b);
extern void *func_02158F74(void *p);
extern void func_0201EF5C(struct WordSet *p, u32 i, u32 v);

int func_0215E1C0(void *c, void *vm)
{
    u32 cmd;
    u16 *dst;
    u16 v;
    void *sys;
    void *x;
    void *blk;
    u32 lim;
    void *t;
    void *ws;

    cmd = func_02159B10(c, vm);
    dst = func_02159AE8(c, vm);
    v = func_0215A5CC(vm);
    sys = func_0215A5DC(vm);
    x = func_0215A5E4(vm);
    blk = func_02009448(func_02012EBC(x));
    lim = func_02009370(blk);
    if (func_0201210C(sys) == 0 && cmd != 0) {
        return 0;
    }
    switch (cmd) {
    case 0:
        *dst = func_02009370(blk) > 0 ? 1 : 0;
        break;
    case 1:
        if (func_021B76F8(x, v, blk) < lim) {
            *dst = 1;
        } else {
            *dst = 0;
        }
        break;
    case 2:
        t = func_021B7794(sys);
        func_0215897C(func_0215A5F4(vm), t);
        return 1;
    case 3:
        func_021B76B4(x, v, blk);
        break;
    case 5:
        ws = func_02158F74(func_0215A5F4(vm));
        func_0201EF5C(ws, 0, func_021B7740(x, v, blk, *dst));
        break;
    case 4:
        *dst = func_021B76F8(x, v, blk);
        break;
    }
    return 0;
}
