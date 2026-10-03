/*
 * function: func_021B5A18
 * address:  0x021B5A18
 * packet:   pkt_ov021_021B5A18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the Ramp record func_021B5B0C steps (its own matched source
 * names the fields) and starts it as a task.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216CDB8  0x0216CDB8  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0218ED50  0x0218ED50  thumb  ov021
 *   func_0218FE70  0x0218FE70  thumb  ov021
 *   func_021B5B0C  0x021B5B0C  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DE25C     0x021DE25C  data  a1
 *   g_021EE724     0x021EE724  data  a2
 *   g_021EE724_ref 0x021EE724  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Ramp;

extern const char d_021DE25C[];
extern u16 g_021EE724;
extern u16 g_021EE724_ref;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u32 func_02159B10(void *, void *);
extern void func_0216CDB8(u8 *p, u32 v);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188D30(u8 *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *p);
extern void *func_02188C7C(u8 *p);
extern u8 *func_0218ED50(u8 *p);
extern u8 *func_0218FE70(u8 *p);
extern void func_021B5B0C(int a0, Ramp *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02030DA8(u32, void (*)(), void *, u32);

int func_021B5A18(void *a, void *b)
{
    void *sys;
    u32 task;
    u32 heap;
    u8 *obj;
    u8 *snd;
    Ramp *p;
    u32 n;
    u8 *q;
    int v;
    u32 m;
    int d;

    func_0215A5F4(b);
    sys = func_0215A5DC(b);
    func_0215A5E4(b);
    sys = func_0201210C(sys);
    task = func_02188D30(sys);
    heap = func_02188C84(sys);
    obj = func_02188C58(sys);
    snd = func_02188C7C(sys);
    n = func_02159B10(a, b);
    p = func_02030734(heap, 0x10, 1, d_021DE25C, 0x5d);
    g_021EE724 = *(u16 *)func_0218ED50(obj);
    func_0216CDB8(snd, (u32)&g_021EE724_ref);
    q = func_0218FE70(obj);
    p->f0 = g_021EE724;
    v = *(u16 *)(q + 0x26);
    p->f4 = v;
    m = v % 0x4000;
    if (m >= 0x2000) {
        p->f4 = v + (0x4000 - m);
    } else {
        p->f4 = v - m;
    }
    p->f4 -= p->f0;
    d = p->f4;
    if ((d < 0 ? -d : d) >= 0x8000) {
        if (d > 0) {
            p->f4 -= 0x10000;
        } else {
            p->f4 += 0x10000;
        }
    }
    p->f8 = 0;
    p->fc = n;
    func_02030DA8(task, (void (*)())func_021B5B0C, p, 0);
    return 0;
}
