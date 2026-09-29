/*
 * function: func_021828B8
 * address:  0x021828B8
 * packet:   pkt_ov018_021828B8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0201232C  0x0201232C  thumb
 *   func_02182920  0x02182920  thumb  ov018
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02034714  0x02034714  arm
 *   d_02183B4C     0x02183B4C  data   a1
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x10];
    void *f10;
    u8 pad14[0x42 - 0x14];
    u8 f42;
    u8 pad43[0x78 - 0x43];
    u8 f78[0x20];
} Src;

typedef struct {
    u8 pad00[0x9C];
    u16 f9C;
} Dst;

extern void *func_020124E4(void *);
extern void *func_02012138(void *);
extern u8 *func_02158344(void *);
extern void func_0201232C(void *, void (*)(), int);
extern void func_02182920();
extern Dst *func_020124E8(void *);
extern void func_02082D44(void *, void *, int);
extern void func_0201F02C(void *, int, void *);
extern void func_02034714(const char *, int, const char *);
extern const char d_02183B4C[];

void func_021828B8(void *a, Src *b, u16 *c)
{
    u8 *v;
    Dst *p;

    v = func_02158344(func_02012138(func_020124E4(a)));
    func_0201232C(a, func_02182920, 0xAC);
    p = func_020124E8(a);
    func_02082D44(b, p, 0x98);
    if (v != 0) {
        p->f9C = c[b->f42];
        func_0201F02C(b->f10, 0, b->f78);
    } else {
        func_02034714(d_02183B4C, 0, d_02183B4C);
    }
}
