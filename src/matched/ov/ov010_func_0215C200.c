/*
 * function: func_0215C200
 * address:  0x0215C200
 * packet:   pkt_ov010_0215C200
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command, sibling of func_0215C180: reads a destination variable
 * and eight arguments, three of them clamped to 2 when 3 or more, fills
 * the 0x24-byte spec func_0215C4C8 consumes and stores its result.
 *
 * The arguments are u16 (func_02159B10 returns u16): the widening copy
 * into each int field is why the clamp of the spilled one reloads its
 * slot, and comparing the int field (not the u16 local) gives blt.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215C4C8  0x0215C4C8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Spec {
    u16 f00;            /* 0x00 */
    u16 pad02;
    int f04;            /* 0x04 */
    int f08;            /* 0x08 */
    int f0c;            /* 0x0C */
    int f10;            /* 0x10 */
    int f14;            /* 0x14 */
    int f18;            /* 0x18 */
    int f1c;            /* 0x1C */
    int f20;            /* 0x20 */
} Spec;

extern void *func_0215A5DC(void *vm);
extern void *func_0215A5E4(void *vm);
extern u16 func_0215A5CC(void *vm);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern u16 *func_02159AE8(void *c, void *vm);
extern u16 func_02159B10(void *c, void *vm);
extern int func_0215C4C8(void *a, void *b);

int func_0215C200(void *c, void *vm)
{
    void *sys;
    u16 v;
    u16 *dst;
    u16 a;
    u16 b;
    u16 d;
    u16 e;
    u16 f;
    u16 g;
    u16 h;
    u16 i;
    Spec s;

    func_0215A5DC(vm);
    sys = func_0215A5E4(vm);
    v = func_0215A5CC(vm);
    func_02012934(sys);
    func_02012944(sys);
    dst = func_02159AE8(c, vm);
    a = func_02159B10(c, vm);
    b = func_02159B10(c, vm);
    d = func_02159B10(c, vm);
    e = func_02159B10(c, vm);
    f = func_02159B10(c, vm);
    g = func_02159B10(c, vm);
    h = func_02159B10(c, vm);
    i = func_02159B10(c, vm);
    s.f00 = v;
    s.f04 = a;
    s.f08 = b;
    s.f0c = d;
    s.f10 = h;
    s.f14 = e;
    if (s.f14 >= 3) {
        s.f14 = 2;
    }
    s.f18 = f;
    if (s.f18 >= 3) {
        s.f18 = 2;
    }
    s.f1c = g;
    if (s.f1c >= 3) {
        s.f1c = 2;
    }
    s.f20 = i;
    *dst = func_0215C4C8(sys, &s);
    return 0;
}
