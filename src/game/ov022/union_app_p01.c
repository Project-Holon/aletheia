/*
 * file:     union_app_p01.c
 * unit:     yes
 * function: func_02183B60, func_02183BE0, func_02183BE8, func_02183C3C, func_02183CC0, func_02183D34, func_02183D4C, func_02183D94
 * address:  0x02183B60
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02183FB8  0x02183FB8  thumb  ov022
 *   func_02184114  0x02184114  thumb  ov022
 *   func_0218416C  0x0218416C  thumb  ov022
 *   d_021841C0     0x021841C0  data  a1
 *   func_020307B0  0x020307B0  arm
 *   func_02080D24  0x02080D24  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_02183EE0  0x02183EE0  thumb  ov022
 *   func_02183DAC  0x02183DAC  thumb  ov022
 *   func_02183DDC  0x02183DDC  thumb  ov022
 *   func_02183E48  0x02183E48  thumb  ov022
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_0217410C  0x0217410C  thumb  ov011
 *   func_021840A4  0x021840A4  thumb  ov022
 *   func_02173F20 0x02173F20 thumb ov012
 *   func_02173E68 0x02173E68 thumb ov012
 */
#include "../../matched/include/Obj00660.h"

struct Entry;
struct Link;
struct C;
struct S;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Rec20 {
    u32 w[8];
} Rec20;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, unsigned short line);
extern u32 func_0203D378(void);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02087C6C(void *p);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void func_02183FB8(u8 *s, u8 *a, int idx, u8 *src);
extern int func_02184114(u8 *s);
extern void func_0218416C(char *p);
extern u32 func_020307B0(void *p);
extern u32 func_02080D24(u32 a);
extern u32 func_0200FB24(void);
extern void func_02172D38(u8 *p);
extern int func_02172D68(u8 *p);
extern void func_02183EE0(struct S *s, struct C *c);
extern void func_02183DAC(u8 *s);
extern void func_02183DDC(u8 *s);
extern void func_02183E48(struct S *s, struct C *c);
extern u32 func_0203D1C0(u32 index);
extern int func_0217410C(int a, int b);
extern void func_021840A4(u8 *s, int i);
extern u32 func_02173F20(void *p, u32 a);
extern u32 func_02173E68(u32 a);
u8 *func_02183B60(u8 *a, int heap, int kind, Rec20 *src);
void func_02183BE0(void *p);
int func_02183BE8(u8 *s, int i);
void func_02183C3C(u8 *s, u8 *c);
void func_02183CC0(u8 *s);
void func_02183D34(u8 *p);
void func_02183D4C(u8 *s);
void func_02183D94(u8 *p);
extern u8 d_021841C0[];


u8 *func_02183B60(u8 *a, int heap, int kind, Rec20 *src)
{
    u8 *s;
    u8 buf[0x28];

    s = func_02030734(heap, 0x100, 1, (const char *)d_021841C0, 0x4d);
    if (func_0203D378() == 1) {
        s[1] = 3;
    }
    s[0] = kind;
    s[0x10] = 0xff;
    s[0x11] = 0xff;
    func_02082BCC(buf, 0, 0x28);
    *(Rec20 *)buf = *src;
    func_02087C6C(buf + 0x20);
    func_02183FB8(s, a, func_0203D1A4((struct Link *)((u32)func_020399A8())), buf);
    func_02184114(s);
    func_0218416C((char *)s);
    return s;
}


/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3 / pool) in ov022; blocker of
 * ov012 func_021743A4.
 */
void func_02183BE0(void *p)
{
    func_020307B0(p);
}


/*
 * Addresses are Black-image addresses.
 */
int func_02183BE8(u8 *s, int i)
{
    u32 n;
    u32 c;

    if (s[9] == 1) {
        return 0;
    }
    n = func_02080D24(s[1]);
    if (s[9] == 2) {
        c = s[0xa];
        if (c + 1 > s[0xb]) {
            return 0;
        }
    }
    if (n + 1 <= s[0]) {
        s[4] = s[4] | (u8)(1 << i);
        if (s[9] == 2) {
            s[0xa] = s[0xa] + 1;
        }
        return 1;
    }
    return 0;
}


void func_02183C3C(u8 *s, u8 *c)
{
    if (func_0200FB24() != 0) {
        return;
    }
    if (((struct Obj00660 *)s)->f28 == 1) {
        return;
    }
    if (((struct Obj00660 *)s)->f20 == 1) {
        func_02172D38(c);
        ((struct Obj00660 *)s)->f20 = 0;
        ((struct Obj00660 *)s)->f24 = 1;
        return;
    }
    if (((struct Obj00660 *)s)->f24 == 1) {
        if (func_02172D68(c) == 0) {
            ((struct Obj00660 *)s)->f24 = 0;
            ((struct Obj00660 *)s)->f28 = 1;
        }
        return;
    }
    if (func_0203D378() == 1) {
        func_02183EE0((struct S *)s, (struct C *)c);
        func_02183D34(s);
        func_02183CC0(s);
        func_02183D4C(s);
        func_02183D94(s);
    }
    func_02183DAC(s);
    func_02183DDC(s);
    func_02183E48((struct S *)s, (struct C *)c);
}


void func_02183CC0(u8 *s)
{
    int i;
    u32 m;
    u32 r;
    u8 t;

    r = s[1];
    if (s[0x10] == 0xff) {
        for (i = 0; i < 5; i++) {
            m = 1 << i;
            if (s[1] & m) {
                if (func_0203D1C0((u8)i) == 0) {
                    r ^= m;
                }
            }
        }
        if (r != s[1]) {
            t = r;
            for (i = 0; i < 5; i++) {
                m = 1 << i;
                if (s[1] & m) {
                    if (!(r & m)) {
                        if (func_0217410C(t, i & 0xff) == 1) {
                            func_021840A4(s, (u8)i);
                            s[1] = s[1] ^ (u8)m;
                        }
                    }
                }
            }
        }
    }
}

void func_02183D34(u8 *p)
{
    if (p[12] != 0 && func_02173F20(p, p[12]) == 1) p[12] = 0;
}


void func_02183D4C(u8 *s)
{
    int i;
    u8 m;

    if (s[0x10] != 0xff) {
        if (func_0203D1C0(s[0x10]) != 0) {
            return;
        }
        s[0x10] = 0xff;
        s[0x11] = 0xff;
    }
    m = s[0xf];
    if (m != 0) {
        for (i = 0; i < 5; i++) {
            if (m & (1 << i)) {
                s[0x10] = i;
                s[0x11] = i;
                s[0xf] = s[0xf] ^ (u8)(1 << i);
                return;
            }
        }
    }
}

/*
 * Callee's filed definition says void; original caller reads r0 at
 * 02183DA2, and ov012 callee leaves func_0203D3F8 result live.
 */
void func_02183D94(u8 *p)
{
    if (p[17] != 255 && func_02173E68(p[17]) == 1) p[17] = 255;
}
