/*
 * function: func_021B2104
 * address:  0x021B2104
 * packet:   pkt_ov021_021B2104
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_021C474C  0x021C474C  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5EC(void *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_0216DE94(void *map, u32 id);
extern int func_02158F58(int a0);
extern void *func_021C474C(void *a, u32 b, u32 c);
extern void func_0215897C(void *vm, void *task);

int func_021B2104(u32 a, u32 b)
{
    void *t;
    u32 v;
    u32 m;
    u32 o;
    void *w;

    w = func_0215A5DC((void *)b);
    t = func_0215A5F4((void *)b);
    m = (u32)func_0215A5EC((void *)b);
    o = (u32)func_0216DE94((void *)m, func_02159B10((void *)a, (void *)b));
    v = (u32)func_021C474C(w, ((u32 *)func_02158F58((int)t))[1], o);
    func_0215897C(t, (void *)v);
    return 1;
}
