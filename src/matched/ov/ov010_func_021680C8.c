/*
 * function: func_021680C8
 * address:  0x021680C8
 * packet:   pkt_ov010_021680C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0202435C  0x0202435C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216DE94  0x0216DE94  thumb
 *   func_0216D88C  0x0216D88C  thumb
 *   func_0219129C  0x0219129C  thumb ov021
 *   func_02168174  0x02168174  thumb
 *
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =func_02024368; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x0216C778), so the call
 * attests as `label`.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u8 pad0[0x18];
    u16 f18;
    u16 f1a;
    u8 pad1c[0x120 - 0x1c];
} E;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} R;

extern int func_020120F4(int);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C54(u8 *p);
extern int func_020122C0(int, int, void *, int);
extern R *func_020124E8(int);
extern int func_020457B0(int, int);
extern int func_02045B38(int, int, int, int);
extern void func_02045CAC(int, int, int);
extern void func_02045C04(int);
extern int func_0202435C(void *, int);
extern int func_02012964(int);
extern int func_0216DE94(int, int);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern int func_0219129C(int, int, void *, int, int, int);
extern int func_02168174(int a0, int a1, int a2);

int func_021680C8(int a, E *b, int c, int d)
{
    int hd;
    int h;
    int g;
    R *p;
    h = func_020120F4(a);
    g = func_02188C54(func_0201210C((void *)a));
    hd = func_020122C0(a, 0, func_02168174, 0x1c);
    p = func_020124E8(hd);
    p->f0 = a;
    if (b->f18 == 0xFFFF) {
        int t;
        p->f14 = func_020457B0(0x5c, 4);
        t = func_02045B38(0, 2, 0xb8, 4);
        func_02045CAC(t, b->f1a, p->f14);
        func_02045C04(t);
    } else {
        p->f14 = func_0202435C(&b[c].f18, 4);
    }
    func_0216D88C((const struct Actor *)func_0216DE94(func_02012964(h), d), (struct VecFx32 *)&p->f4);
    p->f10 = func_0219129C(g, 1, &p->f4, p->f14, 0, 0);
    return hd;
}
