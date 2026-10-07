/*
 * file:     fldmmdl_blact_p23.c
 * unit:     yes
 * function: func_0219E27C, func_0219E29C, func_0219E2C0
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
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

extern void func_0219E084(u32, u32, u32, u32, u16, s16, u16);
extern void *func_0216D69C(void *);
extern void func_021B7EE4(void *p, void *r);
extern void func_0219EAD8(void *p, void *r);
extern void func_021B8028(void *p, void *out);
extern void func_0216D89C(void *, void *);
int func_0219E27C(u32 a);
int func_0219E29C(u32 a);
void func_0219E2C0(void *a, void *r);


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
