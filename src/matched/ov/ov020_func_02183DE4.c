/*
 * function: func_02183DE4
 * address:  0x02183DE4
 * packet:   pkt_ov020_02183DE4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct at 376 of 376 bytes.  Four wildcarded call sites, all of
 * them unlabelled tail-call leaves with no witness outside this range.
 * Each leaf's C below was verified EXACT with `match.py one` in a scratch
 * file; none is filed, because the arm9 one belongs to Ilias:
 *   +0xD4  func_02029DF4 (arm9, Ilias's): ldr r3,=func_02029EB4+1; bx r3
 *          int func_02029DF4(int a, int b, int c)
 *          { return func_02029EB4(a, b, c); }
 *   +0x96  func_02164474 (ov010): void f(int a, int b) { func_0215E364(a, b); }
 *   +0xB6  func_0216E29C (ov010): void f(u8 *p, int n)
 *          { func_02048F4C(*(int *)(p + 0x44), 0x3a, n); }   (02048F4C arm)
 *   +0xBC  func_0216CCCC (ov010): void f(u8 *p)
 *          { func_02082BCC(*(int *)(p + 0x44), 0, 0x310); }  (02082BCC arm)
 * Filing the three ov010 leaves (region hint ov010: ov009 overlaps them)
 * and the arm9 leaf makes this file EXACT unchanged.  This is the callback
 * func_02183F5C registers through func_020122C0.
 *
 * 2026-10-04 (wD2 lane 02): the last blocker, the ov010 leaf func_02164474, is now filed as
 * src/matched/ov/ov010_func_02164474.c (EXACT); the other three leaves were already filed. The tool still reports
 * it unresolved because the manifest is stale. Expected EXACT after the integrator's manifest refresh.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201445C  0x0201445C  thumb
 *   func_02012894  0x02012894  thumb
 *   func_02185B70  0x02185B70  thumb  ov020
 *   func_02185A68  0x02185A68  thumb  ov020
 *   func_0218601C  0x0218601C  thumb  ov020
 *   func_021857C0  0x021857C0  thumb  ov020
 *   func_0202735C  0x0202735C  thumb
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_02164474  0x02164474  thumb  ov010
 *   func_0202C860  0x0202C860  thumb
 *   func_0201405C  0x0201405C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216E29C  0x0216E29C  thumb  ov010
 *   func_0216CCCC  0x0216CCCC  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020145FC  0x020145FC  thumb
 *   func_020143CC  0x020143CC  thumb
 *   func_02158780  0x02158780  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC578  0x021BC578  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Evt;
struct Obj;
struct Rec1C;
struct Sub02014444Obj;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012B38(const struct BigObj *p);
extern void func_0201445C(struct Sub02014444Obj *o, u8 v);
extern struct Rec1C *func_02012894(const struct BigObj *p);
extern void func_02185B70(void *p);
extern void func_02185A68(void *a, int b);
extern void func_0218601C(int a);
extern void func_021857C0(void *a, int b);
extern void func_0202735C(u32 a0, u32 a1);
extern void func_02168EEC(int a);
extern void func_02164474(int a, int b);
extern void func_0202C860(u8 *a0, int a1);
extern u8 func_0201405C(u32 id);
extern u32 func_02012964(const struct BigObj *p);
extern void func_0216E29C(struct Obj *o, int v);
extern void func_0216CCCC(struct Obj *o);
extern u8 func_02012984(const struct BigObj *p);
extern unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
extern void *func_020298A0(void *a, u32 b, u16 c, u16 d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020145FC(int a);
extern u32 func_020143CC(u32 a, u32 b);
extern int func_02158780(void *p, int b, int c, int d, u16 e);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021BE92C(int a, int b, int c, int d, int e, int f, int g);
extern u32 func_02188D20(u8 *p);
extern void func_021BC578(void *p, int v);

int func_02183DE4(int ctx, int *state, u8 *p)
{
    int a;
    int s;
    int m;
    u8 *q;
    int n;
    int t;

    a = *(int *)(p + 0);
    s = (int)func_020120F4((const struct Ctx *)a);
    m = func_0201296C((const struct BigObj *)s);

    switch (*state) {
    case 0:
        func_0201445C(func_02012B38((const struct BigObj *)s), 1);
        if (*(int *)(p + 0xc) != 0) {
            q = (u8 *)func_02012894((const struct BigObj *)s);
            *(s16 *)(p + 8) = *(s16 *)(q + 4);
            func_02185B70((void *)a);
            func_02185A68((void *)a, *(u16 *)(p + 8));
            func_0218601C(s);
            func_021857C0((void *)a, (int)q);
            func_0202735C(*(u16 *)(q + 4), s);
        } else {
            func_02185A68((void *)a, *(u16 *)(p + 8));
            func_0218601C(s);
            func_02168EEC(s);
            func_02164474(s, *(u16 *)(p + 8));
            func_0202C860((u8 *)s, *(u16 *)(p + 8));
            n = func_0201405C(*(u16 *)(p + 8));
            t = func_02012964((const struct BigObj *)s);
            if (n < 16) {
                func_0216E29C((struct Obj *)t, n);
            } else {
                func_0216CCCC((struct Obj *)t);
            }
        }
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, func_020298A0((void *)a, func_02029DF4((void *)s, *(u16 *)(p + 8), func_02012984((const struct BigObj *)s)), 0, 0x3c));
        (*state)++;
        break;
    case 2:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_020145FC(a));
        (*state)++;
        break;
    case 3:
        if (*(int *)(p + 0xc) != 0 && *((u16 *)func_020143CC(m, 0x4041)) != 0) {
            func_02158780((void *)ctx, 0x83b, 0, 0, 0x15);
        } else {
            n = func_02012984((const struct BigObj *)s);
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C(a, (int)func_0201210C((const struct Ctx *)a), 3, 0, 0, n, n));
        }
        (*state)++;
        break;
    case 4:
        t = (int)func_0201210C((const struct Ctx *)a);
        if (func_02188D20((u8 *)t) != 0) {
            func_021BC578((void *)func_02188D20((u8 *)t), *(u16 *)(p + 8));
        }
        return 1;
    }
    return 0;
}
