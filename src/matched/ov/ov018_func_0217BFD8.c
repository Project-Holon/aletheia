/*
 * function: func_0217BFD8
 * address:  0x0217BFD8
 * packet:   pkt_ov018_0217BFD8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B70  0x02012B70  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_0202647C  0x0202647C  thumb
 */

typedef unsigned char  u8;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
struct Ctx;
extern unsigned int func_02012138(const struct Ctx *p);
extern int func_02158344(int);
extern int func_02012B70(const struct BigObj *p);
extern int func_02012204(int);
typedef unsigned int   u32;
extern u32 func_02013D5C(u32 id);
extern u32 func_02013D9C(u32 id);
extern int func_0202648C(int);
extern int func_02026454(int);
extern int func_0202647C(int);

int func_0217BFD8(int a, int b)
{
    int h;
    int t;
    int w;

    h = (int)func_020120F4((const struct Ctx *)a);
    t = func_02012138((const struct Ctx *)a);
    w = func_02158344(t);
    if (func_02012B70((const struct BigObj *)h) == 0)
        return 0;
    if (w != 0)
        return 0;
    if (func_02012204(a) == 1)
        return 1;
    if (func_02013D5C(b) == 1) {
        if (func_0202648C(t) != 0)
            return 1;
        return 0;
    }
    if (func_02013D9C(b) == 1) {
        if (func_02026454(t) == 2 || (func_02026454(t) == 0 && func_0202647C(t) == 2 && func_0202648C(t) != 0))
            return 1;
        return 0;
    }
    return 1;
}
