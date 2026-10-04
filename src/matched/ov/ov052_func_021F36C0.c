/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov052_021F36C0
 * region:   ov052
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021F3998  0x021F3998  thumb  ov052
 *   func_0200B3A4  0x0200B3A4  thumb
 *   d_021F3A2C     0x021F3A2C  data  a4
 */

typedef struct { void (*f0)(void *, void *); void (*f1)(void *, void *); void (*f2)(void *, void *); } Ent;

typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 func_02188C84(u8 *p);
struct Big;
struct Ctx;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u16 func_02188C9C(u8 *p);
extern void func_021F3998(int, int *, int *);
extern char *func_0200B3A4(unsigned, int);
extern Ent d_021F3A2C[];

void func_021F36C0(void *a)
{
    int s1;
    int s0;
    int r4;
    int r6;
    int r7;
    unsigned h;
    char *p;
    void (*f)(void *, void *);

    r4 = func_02188C84(a);
    r6 = (int)func_02188C80(a);
    h = (unsigned int)func_02012EC4(func_020120F4((const struct Ctx *)r6));
    r7 = func_02188C9C(a);
    func_021F3998(r7, &s0, &s1);
    p = func_0200B3A4(h, s0);
    *(unsigned short *)(p + 2) = s1;
    *(unsigned short *)(p + 4) = s0;
    *(int *)(p + 8) = r7;
    *(unsigned short *)(p + 0xc) = r4;
    *(int *)(p + 0x1c) = r6;
    *(void **)(p + 0x20) = a;
    f = d_021F3A2C[*(unsigned short *)(p + 2)].f0;
    if (f)
        f(p, a);
}
