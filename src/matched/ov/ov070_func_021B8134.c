/*
 * function: func_021B8134
 * address:  0x021B8134
 * packet:   pkt_ov070_021B8134
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_0202E448  0x0202E448  thumb
 *   func_021B83A0  0x021B83A0  thumb  ov070
 *   func_02012BE0  0x02012BE0  thumb
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned short u16;

typedef struct Obj {
    void *f000;
    unsigned char pad004[0x80C - 0x4];
    int f80C;
    unsigned char pad810[0x814 - 0x810];
    int f814;
    int f818;
} Obj;

extern int func_021B61C8(Obj *o);
extern u16 *func_021B616C(Obj *o, int k);
extern int func_0202E448(u16 v);
extern int func_021B83A0(Obj *o, u16 v);
extern void func_02012BE0(void *p, int a, int b);
extern void func_020061E4(unsigned int id);

int func_021B8134(Obj *o, int k)
{
    u16 *p;
    int v;

    k += o->f814 + 1;
    if (o->f80C == 4) {
        if (func_021B61C8(o) <= k)
            return 0;
        p = func_021B616C(o, k);
        v = func_0202E448(*p);
        if (v == 0x19)
            return 0;
        if (func_021B83A0(o, *p) == 1)
            func_02012BE0(o->f000, v, 0);
        else
            func_02012BE0(o->f000, v, 1);
        func_020061E4(0x646);
        o->f818 = 0xFFFF;
        return 1;
    }
    return 0;
}
