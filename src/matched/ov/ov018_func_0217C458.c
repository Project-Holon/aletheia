/*
 * function: func_0217C458
 * address:  0x0217C458
 * packet:   pkt_ov018_0217C458
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0217F2B4  0x0217F2B4  thumb  ov018
 *   func_02174E14  0x02174E14  thumb  ov011
 *   func_0217C4D0  0x0217C4D0  thumb  ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Desc;

typedef struct {
    int w[13];
} B52;

typedef struct {
    u16 h0;
    u16 pad2;
    int w4;
    u8 pad8[0x30];
    B52 b38;
    u8 pad6c[0x18];
    u8 b84;
    u8 pad85[3];
} Obj;

extern B52 *func_02175B34();
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern Obj *func_020124E8();
extern void func_02082BCC(void *, int, int);
extern void func_0217F2B4();
extern void func_02174E14();
extern void func_0217C4D0();

struct Desc *func_0217C458(int a0, int a1, int a2, int a3)
{
    B52 *src;
    Obj *o;
    struct Desc *x;

    src = func_02175B34(a2 + 0x1AC);
    func_020120F4((const struct Ctx *)a0);
    x = func_020122C0((void *)a0, 0, func_0217C4D0, 0x88);
    o = func_020124E8(x);
    func_02082BCC(o, 0, 0x88);
    o->h0 = a3;
    o->w4 = a1;
    o->b38 = *src;
    o->b84 = 1;
    func_0217F2B4((u8 *)o + 8, a0);
    func_02174E14(a2, 5);
    return x;
}
