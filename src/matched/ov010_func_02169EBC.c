/*
 * function: func_02169EBC
 * address:  0x02169EBC
 * packet:   pkt_ov010_02169EBC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    void *f10;          /* 0x10 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    void *f24;          /* 0x24 */
    u16 f28;            /* 0x28 */
    u32 f2C;            /* 0x2C */
    void *f30;          /* 0x30 */
    u16 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
    void *f3C;          /* 0x3C */
    void *f40;          /* 0x40 */
} Res;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 *f08;            /* 0x08 */
    void *f0C;          /* 0x0C */
    u16 f10;            /* 0x10 */
    u8 pad12[0x18 - 0x12];
    Res *f18;           /* 0x18 */
} Work;

extern void *func_02045770(void *p);
extern void func_02043B5C(void *p, u32 v);
extern void func_0201F73C(void *p, u32 a, u32 b, u32 c);
extern u32 func_021904AC(void *p);
extern u32 func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u16 a8, u32 a9);
extern void func_02045334(void *p);
extern void func_02045374(void *p);
extern void func_02045730(void *p);
extern void func_02041B6C(void);

void func_02169EBC(Work *w)
{
    Res *r;
    u32 a;
    void *p;

    func_02043B5C(func_02045770(w->f18->f08), 15);
    func_0201F73C(w->f18->f08, 2, 1, 13);
    r = w->f18;
    a = func_021904AC(w->f0C);
    w->f18->f10 = func_0201CCE4(r->f08, 0, 0, r->f18, a, func_02012FFC(), r->f00, 10, w->f10, 15);
    w->f18->f20 = 0;
    p = w->f18->f08;
    func_02045334(p);
    func_02045374(p);
    func_02045730(p);
    func_02041B6C();
}
