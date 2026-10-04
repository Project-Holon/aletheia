/*
 * function: func_021B1FB8
 * address:  0x021B1FB8
 * packet:   pkt_ov021_021B1FB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02161AC0  0x02161AC0  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern unsigned int func_02159B10(void *a, void *b);
struct Tri;
extern void *func_0215A5EC(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0216DE94(void *map, u32 id);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void *func_02161AC0(void *p, void *a1, struct Tri *t, void *a3);
extern void func_0215897C(void *vm, void *task);

int func_021B1FB8(u32 a, u32 b)
{
    int buf[3];
    int vec[3];
    void *t;
    int i;
    int x;
    int y;
    int z;
    u32 m;
    void *w;
    u32 o;

    t = func_0215A5F4((void *)b);
    i = func_02159B10((void *)a, (void *)b);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    m = (u32)func_0215A5EC((void *)b);
    w = func_0215A5DC((void *)b);
    o = (u32)func_0216DE94((void *)m, i);
    func_0216D88C((const struct Actor *)o, (struct VecFx32 *)buf);
    vec[0] = (x << 16) + 0x8000;
    vec[1] = y << 16;
    vec[2] = (z << 16) + 0x8000;
    func_0215897C(t, func_02161AC0(w, (void *)o, (struct Tri *)buf, vec));
    return 1;
}
