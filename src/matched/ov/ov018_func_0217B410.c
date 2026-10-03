/*
 * function: func_0217B410
 * address:  0x0217B410
 * packet:   pkt_ov018_0217B410
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02013D5C  0x02013D5C  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0217B5DC  0x0217B5DC  thumb  ov018
 *   func_0216B340  0x0216B340  thumb  ov010
 *   d_02182B90     0x02182B90  data   a4
 */

typedef unsigned char u8;

typedef struct { int x, y, z; } V12;

struct Ctx;

extern u8 *func_020120F8(const struct Ctx *p);
extern int func_02012AC8();
extern int func_02012138();
typedef unsigned int   u32;
extern int func_02158344(int a0);
extern u32 func_02013D5C(u32 id);
extern void func_021A3038();
extern int func_0217B5DC();
struct Desc;
extern struct Desc *func_0216B340(int a0, int a1, void *a2, int a3, int a4);
extern const V12 d_02182B90;

int func_0217B410(int a0, int a1, int a2)
{
    int h;
    int w;
    int i;
    int base;
    V12 pos;
    V12 v;

    h = func_02012AC8(func_020120F8((const struct Ctx *)a1));
    w = func_02158344(func_02012138(a1));
    if (func_02013D5C(h) == 0)
        return 0;
    func_021A3038(a2, &pos);
    for (i = 0; i < 3; i++) {
        if (pos.x >= (i << 22) + 0x1F8000 && pos.x <= (i << 22) + 0x1F8000 && pos.z >= 0x2C8000 && pos.z <= 0x2C8000)
            return func_0217B5DC(a1, a0, w);
    }
    base = 0x1F8000;
    for (i = 0; i < 3; i++) {
        if (pos.x >= base && pos.x < base + 0x20000 && pos.z == 0x158000) {
            v = d_02182B90;
            v.x += pos.x - base;
            return (int)func_0216B340(a1, 1, &v, 0, 4); /* int-typed on purpose: function returns int */
        }
        base += 0x400000;
    }
    return 0;
}
