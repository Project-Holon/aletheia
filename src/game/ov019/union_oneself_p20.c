/*
 * file:     union_oneself_p20.c
 * unit:     yes
 * function: func_0217FD88, func_0217FDC8, func_0217FDF8, func_0217FE24, func_0217FE38, func_0217FE44, func_0217FEB8, func_0217FEF4, func_0217FF14
 * address:  0x0217FD88
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217FCA4  0x0217FCA4  thumb  ov019
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   d_02180794     0x02180794  data  ov019  a4
 *   d_0218079C     0x0218079C  data  ov019  a4
 *   func_02080D24 0x02080D24 arm
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   d_021807AC     0x021807AC  data  ov019  a4
 *   d_021807C0     0x021807C0  data  ov019  a4
 */
#include "../../matched/include/Obj04188.h"

struct Obj00020;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16;

extern void func_0217FCA4(u32 *p);
extern int func_0203D1B4(void);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern unsigned int func_02080D24(int a);
extern void func_021A3038(unsigned char *p, struct VecFx32 *v);
extern u16 func_02188C9C(u8 *p);
u8 *func_0217FD88(u8 *base);
int func_0217FDC8(u8 *p);
int func_0217FDF8(u8 *p);
int func_0217FE24(u8 *p);
void func_0217FE38(u8 *p);
int func_0217FE44(int a, int mode, unsigned *out);
int func_0217FEB8(u8 *p);
int func_0217FEF4(u8 *p);
int func_0217FF14(void *a);
extern s16 d_02180794[][2];
extern s16 d_0218079C[][2];
extern s16 d_021807AC[][2];
extern s16 d_021807C0[][2];


u8 *func_0217FD88(u8 *base)
{
    int i;
    int best = 0;
    u8 *e;

    for (i = 0; i < 10; i++) {
        e = base + i * 20;
        if (*(int *)&((struct Obj04188 *)e)->fC == 0)
            return e;
        if (((struct Obj04188 *)e)->f10 < *(u16 *)(base + best * 20 + 16))
            best = i;
    }
    e = base + best * 20;
    func_0217FCA4((u32 *)e);
    return e;
}

int func_0217FDC8(u8 *p)
{
    int n=0; int i;
    for (i=0;i<4;i++) { if (p[0x3e + i*0x2c] == 1) n++; }
    if (n >= func_0203D1B4()) return 1;
    return 0;
}


int func_0217FDF8(u8 *p)
{
    int i;
    int n = 0;

    for (i = 0; i < 4; i++) {
        if (p[0x144 + i] == 1)
            n++;
    }
    if (n >= func_0203D1B4())
        return 1;
    return 0;
}


/*
 * note:     unlabelled leaf (prints as .word in ov019.s); called from
 *           func_0217E440.
 */
int func_0217FE24(u8 *p)
{
    if (p[0x160] == 1)
        return 1;
    return 0;
}


void func_0217FE38(u8 *p)
{
    p[0x160] = 0;
}


int func_0217FE44(int a, int mode, unsigned *out)
{
    unsigned i;
    int x;
    void *y;
    int y2;
    void *h;

    h = func_02188CB4((void *)a);
    *out = 0;
    y = func_021A3074((void *)h);
    x = func_0216D83C(y);
    y2 = func_0216D86C(y);
    if (mode == 2) {
        for (i = 0; i < 2; i++) {
            if (d_02180794[i][0] == x && d_02180794[i][1] == y2) {
                *out = i;
                return 1;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (d_0218079C[i][0] == x && d_0218079C[i][1] == y2) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}

int func_0217FEB8(u8 *p)
{
    int n=0; int i; int value=p[0x16e];
    for (i=0;i<4;i++) { if(p[0x162+i] == 1) n++; }
    if (n >= func_0203D1B4() || n >= (int)func_02080D24(value)) return 1;
    return 0;
}

int func_0217FEF4(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p[i + 0x162] == 1) return 1;
    }
    return 0;
}


int func_0217FF14(void *a)
{
    int v[3];
    s16 (*t)[2];
    int i;
    int n;

    func_021A3038(func_02188CB4(a), (struct VecFx32 *)v);
    v[0] >>= 12;
    v[2] >>= 12;
    if (func_02188C9C(a) == 0x96) {
        t = d_021807AC;
        n = 5;
    } else {
        t = d_021807C0;
        n = 5;
    }
    for (i = 0; i < n; i++) {
        if (v[0] == t[i][0] && v[2] == t[i][1])
            return 1;
    }
    return 0;
}
