/*
 * function: func_0216BEC0
 * address:  0x0216BEC0
 * packet:   pkt_ov010_0216BEC0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0202F488  0x0202F488  thumb
 *   func_0202F630  0x0202F630  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern int func_02159B10();
extern void *func_0201AB28(void *p, u32 idx);
extern int func_0202F488();
extern void func_0202F630();

int func_0216BEC0(int c, int vm)
{
    void *r7;
    int k;
    int m;
    int t;
    void *obj;

    r7 = func_02012934(func_0215A5E4((void *)vm));
    k = func_02159B10(c, vm);
    m = func_02159B10(c, vm);
    switch (k) {
    case 0xFB:
        t = 0;
        break;
    case 0xF3:
    case 0xF4:
    case 0xF5:
        t = 2;
        break;
    case 0xF6:
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    default:
        return 0;
    }
    obj = func_0201AB28((void *)r7, m);
    if (func_0202F488(obj, t) == 0) {
        return 0;
    }
    func_0202F630(obj, t);
    return 0;
}
