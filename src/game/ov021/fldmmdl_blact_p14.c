/*
 * file:     fldmmdl_blact_p14.c
 * unit:     yes
 * function: func_0219E27C, func_0219E29C, func_0219E2C0, func_0219E2F4
 * address:  0x0219E27C
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
 *   func_0219E084  0x0219E084  thumb  ov021
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_0219EAD8  0x0219EAD8  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_021B7DC0  0x021B7DC0  thumb
 *   func_021B7E60  0x021B7E60  thumb
 *   func_021B8038  0x021B8038  thumb
 *   func_021B8040  0x021B8040  thumb
 *   func_021BB480  0x021BB480  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed int     s32;

extern void func_0219E084(u32, u32, u32, u32, u16, s16, u16);
extern void *func_0216D69C(void *);
extern void func_021B7EE4(void *p, void *r);
extern void func_0219EAD8(void *p, void *r);
extern void func_021B8028(void *p, void *out);
extern void func_0216D89C(void *, void *);
extern void *func_0216D67C(void *o);
extern void *func_0216D530(void *p);
extern void *func_021BB480(void *p);
extern u8 func_021B8040(u8 *p);
extern u8 func_021B8038(u8 *p);
extern void func_021B7E60(void *p, u32 a, void *out, u32 b);
extern void func_021B7DC0(void *p, void *out);
int func_0219E27C(u32 a);
int func_0219E29C(u32 a);
void func_0219E2C0(void *a, void *r);
void func_0219E2F4(void *o, void *out);



/*
 * Addresses are Black-image addresses.
 */
int func_0219E27C(u32 a)
{
    func_0219E084(a, 2, 0x2000, 16, 3, 0, 0x100);
    return 1;
}



int func_0219E29C(u32 a)
{
    func_0219E084(a, 3, 0x2000, 16, 3, 0, 0x100);
    return 1;
}



void func_0219E2C0(void *a, void *r)
{
    void **p = func_0216D69C(a);
    u8 buf[12];
    func_021B7EE4(*p, r);
    func_0219EAD8(p, r);
    func_021B8028(*p, buf);
    func_0216D89C(a, buf);
}


void func_0219E2F4(void *o, void *out)
{
    void **h;

    func_021BB480(func_0216D530(func_0216D67C(o)));
    h = func_0216D69C(o);
    if (func_021B8040(*h))
        func_021B7E60(*h, func_021B8038(*h), out, 0);
    else
        func_021B7DC0(*h, out);
}
