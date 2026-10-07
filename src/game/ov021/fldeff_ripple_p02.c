/*
 * file:     fldeff_ripple_p02.c
 * unit:     yes
 * function: func_021C38F4, func_021C3A00, func_021C3A44, func_021C3A70
 * address:  0x021C38F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C3A7C  0x021C3A7C  thumb  ov021
 *   func_021C3A90  0x021C3A90  thumb  ov021
 *   func_021C3AAC  0x021C3AAC  thumb  ov021
 *   func_021C3ADC  0x021C3ADC  thumb  ov021
 *   func_021C3B0C  0x021C3B0C  thumb  ov021
 *   func_021C3B2C  0x021C3B2C  thumb  ov021
 *   func_021C3BCC  0x021C3BCC  thumb  ov021
 *   func_021C3BD4  0x021C3BD4  thumb  ov021
 *   func_021C3C04  0x021C3C04  thumb  ov021
 *   func_021C3C30  0x021C3C30  thumb  ov021
 *   func_021C3C78  0x021C3C78  thumb  ov021
 *   func_021C3C88  0x021C3C88  thumb  ov021
 *   func_021C3D1C  0x021C3D1C  thumb  ov021
 *   func_021C3DA8  0x021C3DA8  thumb  ov021
 *   func_021C3DE4  0x021C3DE4  thumb  ov021
 *   func_021C3E38  0x021C3E38  thumb  ov021
 *   func_021C3E64  0x021C3E64  thumb  ov021
 *   func_021C3F60  0x021C3F60  thumb  ov021
 *   func_021C3FC0  0x021C3FC0  thumb  ov021
 *   func_021C4018  0x021C4018  thumb  ov021
 *   func_021C4024  0x021C4024  thumb  ov021
 *   func_021C4030  0x021C4030  thumb  ov021
 *   func_021C4084  0x021C4084  thumb  ov021
 *   func_021C40F8  0x021C40F8  thumb  ov021
 *   func_021C4160  0x021C4160  thumb  ov021
 *   func_021C4238  0x021C4238  thumb  ov021
 *   func_021C42BC  0x021C42BC  thumb  ov021
 *   func_021C4340  0x021C4340  thumb  ov021
 *   func_02017E1C  0x02017E1C  thumb
 */
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 w[0x23]; } S;

extern void func_021C3A7C(S *s);
extern void func_021C3A90(void *a, u32 *out);
extern void func_021C3AAC(void *a, u32 *out);
extern void func_021C3ADC(void *a, u32 *out);
extern void func_021C3B0C(void *a, u32 *out);
extern void func_021C3B2C(u32 *p, u32 *q);
extern int func_021C3BCC(u32 a, u32 b);
extern void func_021C3BD4(void *a, u32 *out);
extern void func_021C3C04(void *a, u32 *out);
extern void func_021C3C30(void *a, u32 *out);
extern void func_021C3C78(void *a, u32 *out);
extern void func_021C3C88(u32 *p, u32 *q);
extern void func_021C3D1C(u32 *p, u32 *q, u32 d);
extern void func_021C3DA8(void **p, u32 *out);
extern void func_021C3DE4(u32 *m, u32 *s, u32 heap);
extern void func_021C3E38(u32 *p, u32 heap);
extern void func_021C3E64(u32 *m, S *s);
extern void func_021C3F60(int a, u32 *p);
extern void func_021C3FC0(u32 *a, u32 *b);
extern void func_021C4018(int a, char *p);
extern void func_021C4024(int a, char *p);
extern void func_021C4030(u32 *p, u32 *q);
extern void func_021C4084(u32 *p);
extern void func_021C40F8(u32 *p, u32 *q, u32 heap);
extern void func_021C4160(u32 *p, u32 *q);
extern void func_021C4238(u32 *a, u32 *b, u32 *c);
extern void func_021C42BC(void **p, u32 *q);
extern void func_021C4340(void *mon, S *s, void *b, void *c, u16 heap);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
void func_021C38F4(u16 heap, void *b, void *c, u32 m0, u32 m1, void *mon);
void func_021C3A00(u32 *p);
void func_021C3A44(void **p);
void func_021C3A70(u32 *p);


/*
 * Day-care offspring builder: runs every step of the 0x8C-byte work
 * record over the parent pair m and hands the result to func_021C4340.
 * Callee prototypes without a matched file are written from the call
 * site's argument registers.
 */
void func_021C38F4(u16 heap, void *b, void *c, u32 m0, u32 m1, void *mon)
{
    S s;
    u32 m[2];

    m[0] = m0;
    m[1] = m1;
    func_021C3A00(m);
    func_021C3A44((void **)m);
    func_021C3A7C(&s);
    func_021C3A90(m, (u32 *)(&s));
    func_021C3AAC(m, (u32 *)(&s));
    func_021C3ADC(m, (u32 *)(&s));
    func_021C3B0C(m, (u32 *)(&s));
    func_021C3B2C(m, (u32 *)(&s));
    func_021C3BCC((u32)m, (u32)(&s));
    func_021C3BD4(m, (u32 *)(&s));
    func_021C3C04(m, (u32 *)(&s));
    func_021C3C30(m, (u32 *)(&s));
    func_021C3C78(m, (u32 *)(&s));
    func_021C3C88(m, (u32 *)(&s));
    func_021C3D1C(m, (u32 *)(&s), heap);
    func_021C3DA8((void **)m, (u32 *)(&s));
    func_021C3DE4(m, (u32 *)&s, heap);
    func_021C3E38((u32 *)(&s), heap);
    func_021C3E64(m, &s);
    func_021C3F60((int)m, (u32 *)(&s));
    func_021C3FC0(m, (u32 *)(&s));
    func_021C4018((int)b, (char *)(&s));
    func_021C4024((int)m, (char *)(&s));
    func_021C4030(m, (u32 *)(&s));
    func_021C4084((u32 *)(&s));
    func_021C40F8(m, (u32 *)(&s), heap);
    func_021C4160(m, (u32 *)(&s));
    func_021C4238(m, (u32 *)(&s), (u32 *)heap);
    func_021C42BC((void **)m, (u32 *)(&s));
    func_021C4340(mon, &s, b, c, heap);
}


void func_021C3A00(u32 *p)
{
    u32 a = func_02017E1C((void *)p[0], 0x6e, 0);

    func_02017E1C((void *)p[1], 0x6e, 0);
    if (a == 1)
        func_021C3A70(p);
    func_02017E1C((void *)p[0], 0x6e, 0);
    if (func_02017E1C((void *)p[1], 0x6e, 0) == 0)
        func_021C3A70(p);
}


/*
 * Applies the special-case hook for species 0x84 holding item 2 (EXACT*: pad).
 */
void func_021C3A44(void **p)
{
    u32 sp = func_02017E1C(p[0], 5, 0);
    u32 item = func_02017E1C(p[1], 0x6E, 0);

    if (sp == 0x84 && item == 2)
        func_021C3A70((u32 *)p);
}


void func_021C3A70(u32 *p)
{
    u32 t = p[0];

    p[0] = p[1];
    p[1] = t;
}
