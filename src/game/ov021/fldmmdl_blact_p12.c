/*
 * file:     fldmmdl_blact_p12.c
 * unit:     yes
 * function: func_0219D85C, func_0219D8DC, func_0219D930, func_0219D990, func_0219D9D8, func_0219DA20
 * address:  0x0219D85C
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
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0219E334  0x0219E334  thumb  ov021
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 *   func_0216D7E0  0x0216D7E0  thumb  ov010
 *   func_0216D7D8  0x0216D7D8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216DB24  0x0216DB24  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_0216D7E4  0x0216D7E4  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0219DA80  0x0219DA80  thumb  ov021
 *   func_0219DB04  0x0219DB04  thumb  ov021
 *   func_0219DB5C  0x0219DB5C  thumb  ov021
 *   func_0219DAA4  0x0219DAA4  thumb  ov021
 *   func_0219DAD0  0x0219DAD0  thumb  ov021
 *   func_0219DB0C  0x0219DB0C  thumb  ov021
 *   func_0219DBC8  0x0219DBC8  thumb  ov021
 *   func_0219DB44  0x0219DB44  thumb  ov021
 *   func_0219DB48  0x0219DB48  thumb  ov021
 */
typedef unsigned int u32;

typedef unsigned char  u8;

extern int func_0216DCB4(void *a0);
extern void *func_0216D67C(void *a0);
extern void *func_0216D530(void *p);
extern void func_0219E2F4(void *o, void *out);
extern int func_0219E334(u32 a, u32 b);
extern u32 func_021BB3C4(u8 *p, char *a1);
extern void func_0216D7E0(void *p, u32 v);
extern void func_0216D7D8(void *p, u32 v);
extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern int func_0216DB24(int a0);
extern u32 func_0216D7DC(void *p);
extern u32 func_0216D7E4(void *p);
extern void *func_0216E3C4(void *p);
extern void func_0219DA80(u32, u32, u32, u32);
extern int func_0219DB04(u32 a, u32 b, u32 c, u32 d);
extern void func_0219DB5C(void *a, u32 b, u32 c, u8 *d);
extern void func_0219DAA4(u32, u32, u32, u32);
extern void func_0219DAD0(u32 a, u32 x, u32 b, u8 *p);
extern void func_0219DB0C(u32, u32, u32, u32);
extern void func_0219DBC8(void *a, u32 b, u32 c, u8 *d);
extern void func_0219DB44(u32, u32, u32, u32);
extern int func_0219DB48(u32 a, u32 b, u32 c, u32 d);
u32 func_0219D85C(u32 a);
void func_0219D8DC(void *a);
void func_0219D930(void *a);
void func_0219D990(void *a);
void func_0219D9D8(void *a);
void func_0219DA20(void *a);


/*
 * Addresses are Black-image addresses.
 */
u32 func_0219D85C(u32 a)
{
    u32 v1[2];
    u32 v0[2];
    u32 r6 = -1;
    u32 r5 = -1;
    u32 t;
    if (func_0216DCB4((void *)a) == 0) {
        t = (u32)func_0216D530(func_0216D67C((void *)a));
        func_0219E2F4((void *)a, v0);
        func_0219E334(a, (u32)v1);
        r6 = func_021BB3C4((u8 *)t, (char *)v1);
        r5 = func_021BB3C4((u8 *)t, (char *)v0);
    }
    func_0216D7E0((void *)a, r6);
    func_0216D7D8((void *)a, r5);
    if (r5 == -1) {
        func_0216D568((void *)a, 0x800);
        return 0;
    }
    func_0216D570((char *)a, 0x800);
    return 1;
}


void func_0219D8DC(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DA80((u32)a, b, c, d);
        func_0219DB04((u32)a, b, c, d);
        func_0219DB5C(a, b, c, (u8 *)d);
    }
}


void func_0219D930(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DAA4((u32)a, b, c, d);
        func_0219DAD0((u32)a, b, c, (u8 *)d);
        func_0219DB0C((u32)a, b, c, d);
        func_0219DB5C(a, b, c, (u8 *)d);
    }
}


void func_0219D990(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DB0C((u32)a, b, c, d);
        func_0219DB5C(a, b, c, (u8 *)d);
    }
}


void func_0219D9D8(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DBC8(a, b, c, (u8 *)d);
        func_0219DB44((u32)a, b, c, d);
    }
}


void func_0219DA20(void *a)
{
    u32 b;
    u32 c;
    u32 d;
    if (func_0219D85C((u32)a) != 0 && func_0216DB24((int)a) == 1) {
        b = func_0216D7DC((void *)a);
        c = func_0216D7E4((void *)a);
        d = (u32)func_0216E3C4((void *)a);
        func_0219DBC8(a, b, c, (u8 *)d);
        func_0219DB44((u32)a, b, c, d);
        func_0219DAA4((u32)a, b, c, d);
        func_0219DB48((u32)a, b, c, d);
    }
}
