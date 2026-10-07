/*
 * file:     btl_server_p87.c
 * unit:     yes
 * function: func_021C7D54, func_021C7DAC, func_021C7E14, func_021C7EC4, func_021C7ED8, func_021C7EEC, func_021C7F04, func_021C7F24
 * address:  0x021C7D54
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   func_021B937C  0x021B937C  thumb  ov093
 *   func_021C64B4  0x021C64B4  thumb  ov093
 *   func_021C6E3C  0x021C6E3C  thumb  ov093
 *   func_0201C314  0x0201C314  thumb
 *   func_021C1E74  0x021C1E74  thumb  ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B997C 0x021B997C thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021C7FCC 0x021C7FCC thumb ov093
 *   func_021B9BC4 0x021B9BC4 thumb ov093
 */
#include "../../matched/include/Obj02135.h"
#include "../../matched/include/Obj18325.h"
#include "../../matched/include/Obj21110.h"
#include "../../matched/include/Obj21111.h"
#include "../../matched/include/Obj00003.h"

struct R4;
struct Out64B4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021BD2B4(u8 *it, u8 **q);
extern int func_021BD34C(u8 *it, u8 **q, u8 **x);
extern u8 func_021D5440(u8 *p);
extern int func_021B9A24(u32 a, u32 b);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D6C24(struct R4 *p);
extern u8 *func_021B937C(int a, char *b, u8 *c);
extern void func_021C64B4(u8 *p, int q, u8 *a, struct Out64B4 *out);
extern int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag);
extern u32 func_0201C314(void *p);
extern int func_021C1E74(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u32 e, u32 f, int g, u16 *out);
extern u8 func_021B8DDC(u32 x);
extern int func_021B997C(u8 *, unsigned int);
extern u8 *func_021BB85C(u8 *, unsigned int);
extern u32 func_021B8588(void **p);
extern char *func_021C7FCC(u8 *, int);
extern u8 func_021B9BC4(u8 *, int);
u8 func_021C7D54(u8 *p, u8 *k, u8 *out);
int func_021C7DAC(u8 *p, int a, int b, int c);
u16 func_021C7E14(u8 *p, u8 a, u8 b, u32 c, int e0, int e1);
/* 021C7EC4 nonzero test of the pooled offset 0x774 */ u32 func_021C7EC4(u8 *p);
int func_021C7ED8(u8 *p, int i);
int func_021C7EEC(u8 *p, int i);
int func_021C7F04(u8 *p, int i);
int func_021C7F24(u8 *p, int i);


u8 func_021C7D54(u8 *p, u8 *k, u8 *out)
{
    u32 it;
    u8 *x;
    u8 n = 0;
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        if (func_021B9A24((u32)k, func_021D5440(x)) == 0) {
            out[n++] = func_021D5440(x);
        }
    }
    return n;
}


int func_021C7DAC(u8 *p, int a, int b, int c)
{
    int buf[5];
    int r;
    u8 *x = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, a);
    u8 *y = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, b);
    ((struct Obj02135 *)p)->f774 += 1;
    if (func_021D6C24((struct R4 *)y)) {
        y = func_021B937C(((struct Obj02135 *)p)->f4, *(char * *)&((struct Obj02135 *)p)->f8, y);
    }
    func_021C64B4(p, c, x, (struct Out64B4 *)buf);
    r = func_021C6E3C(p, x, y, (u8 *)buf, 0);
    ((struct Obj02135 *)p)->f774 -= 1;
    return r;
}


u16 func_021C7E14(u8 *p, u8 a, u8 b, u32 c, int e0, int e1)
{
    int buf[5];
    u16 o;
    u8 *x;
    u8 *y;
    int z;
    if (c != 0 && func_0201C314((void *)c) != 0) {
        x = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, a);
        y = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, b);
        ((struct Obj02135 *)p)->f774 += 1;
        if (func_021D6C24((struct R4 *)y)) {
            y = func_021B937C(((struct Obj02135 *)p)->f4, *(char * *)&((struct Obj02135 *)p)->f8, y);
        }
        if (e0) {
            z = func_021C7DAC(p, a, b, c);
        } else {
            z = 3;
        }
        func_021C64B4(p, c, x, (struct Out64B4 *)buf);
        func_021C1E74(p, x, y, (u8 *)buf, z, 0x1000, 0, e1 == 0, &o);
        ((struct Obj02135 *)p)->f774 -= 1;
        return o;
    }
    return 0;
}


/* 021C7EC4  nonzero test of the pooled offset 0x774 */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021C7ED4; ldr r0, [r0, r1]; cmp r0, #0; beq loc_021C7ED0; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021C7EC4(u8 *p)
{
    return (((struct Obj18325 *)p)->f774 != 0);
}

int func_021C7ED8(u8 *p, int i) { return func_021B997C(*(u8 * *)&((struct Obj21110 *)p)->f4, func_021B8DDC(i)); }

int func_021C7EEC(u8 *p, int i) { return func_021BB85C(*(u8 * *)&((struct Obj21111 *)p)->f0, func_021B8DDC(i))[9]; }

int func_021C7F04(u8 *p, int i) { if (func_021B8588(((struct Obj00003 *)p)->f4) != 3) return func_021C7EEC(p, i); return 3; }

int func_021C7F24(u8 *p, int i) { char *q = func_021C7FCC(p, i); if (func_021B9BC4((u8 *)q, func_021C7F04(p, i))) return 1; return 0; }
