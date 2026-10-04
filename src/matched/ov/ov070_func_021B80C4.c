/*
 * function: func_021B80C4
 * address:  0x021B80C4
 * packet:   pkt_ov070_021B80C4
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020355D8  0x020355D8  arm
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_021BB398  0x021BB398  thumb  ov070
 *   func_0202EB04  0x0202EB04  thumb
 *   func_021B97E8  0x021B97E8  thumb  ov070
 */

typedef unsigned char u8;

typedef struct Obj {
    unsigned char pad000[0x81C];
    int f81C;
    unsigned char pad820[0x850 - 0x820];
    void *f850;
} Obj;

struct CodeIn;
extern void func_020355D8(u8 v);
extern int func_021B61C8(Obj *o);
typedef unsigned int   u32;
extern void func_021BB398(int p, u32 val);
extern void func_0202EB04(struct CodeIn *p);
extern void func_021B97E8(Obj *o, int v);

void func_021B80C4(Obj *o, int flag)
{
    if (o->f81C == 1)
        flag = 1;
    if (flag)
        func_020355D8(0);
    else
        func_020355D8(1);
    if (func_021B61C8(o) == 0)
        flag = 0;
    if (flag == 0) {
        func_021BB398((int)o, 0);
    } else {
        func_021BB398((int)o, 1);
        func_0202EB04(o->f850);
    }
    func_021B97E8(o, flag);
}
