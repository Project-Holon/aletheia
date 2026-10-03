/*
 * function: func_0217CE08
 * address:  0x0217CE08
 * packet:   pkt_ov018_0217CE08
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217BED4  0x0217BED4  thumb  ov018
 *   func_02185140  0x02185140  thumb  ov020
 *   func_02185588  0x02185588  thumb  ov020
 */

typedef struct { int x, y, z; } V12;

struct Ctx;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012B70(const struct BigObj *p);
extern int func_02158344(int a0);
extern int func_0217BED4();
extern void *func_02185140();
extern void *func_02185588();

void *func_0217CE08(void *a0, void *a1, int a2, int a3)
{
    int h;
    void *c;
    V12 v;

    h = func_02012138(a0);
    c = func_020120F4(a0);
    func_02158344(h);
    if (func_0217BED4(a2, &v) == 0)
        return 0;
    if (func_02012B70(c) == 0 && a2 == 0x117)
        return func_02185140(a0, a2, &v, a3);
    return func_02185588(a0, a2, &v);
}
