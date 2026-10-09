/*
 * file:     eventdata_system_p02.c
 * unit:     yes
 * function: func_02161F14, func_02161F54, func_02161F68, func_02161F74, func_02161F90, func_02161FEC, func_02161FF0, func_02162008, func_02162024, func_0216202C, func_02162038, func_02162040, func_02162048
 * address:  0x02161F14
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021867C4  0x021867C4  thumb ov023
 *   func_0218682C  0x0218682C  thumb
 *   func_02186804  0x02186804  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02039338  0x02039338  arm
 *   func_0216210C  0x0216210C  thumb  ov010
 *   func_02162120  0x02162120  thumb  ov010
 *   func_02161DC4  0x02161DC4  thumb
 *   func_02186520  0x02186520  thumb
 *   func_02161E78  0x02161E78  thumb
 *   func_02161E60  0x02161E60  thumb
 *   func_0216220C  0x0216220C  thumb  ov010
 *   func_02162230  0x02162230  thumb  ov010
 *   func_021622AC 0x021622AC thumb ov010
 *   func_021622D8 0x021622D8 thumb ov010
 *   func_02162330 0x02162330 thumb ov010
 *   func_02162358 0x02162358 thumb ov010
 *   func_02162298  0x02162298  thumb
 *   d_0217144C     0x0217144C  data  ov010  a4
 */
#include "../../matched/include/Obj12331.h"
#include "../../matched/include/Obj17711.h"
#include "../../matched/include/Obj18948.h"
#include "../../matched/include/Obj18949.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 x;
    u16 b;
    u16 t;
} S;

extern int func_021867C4(int, int);
extern u16 *func_0218682C(int h);
extern void func_02186804(int);
extern int func_02082BCC();
extern u16 func_02039338(void);
extern int func_0216210C(int a0);
extern int func_02162120();
extern u8 *func_02161DC4(char *, int, int);
extern void func_02186520(u16 *, int, u8 *);
extern void func_02161E78(void *a0);
extern int func_02161E60(int a0, int a1);
extern int func_0216220C();
extern int func_02162230();
extern int func_021622AC(char *, int, void *);
extern int func_021622D8(char *, void *);
extern void func_02162330(char *, unsigned);
extern void func_02162358(int a0);
extern int func_02162298(int a0, int a1, int a2);
void func_02161F14(u16 *out, u8 *in, int c);
int func_02161F54(int a0);
void func_02161F68(void *p);
void func_02161F74(int a0, int a1, int a2);
void func_02161F90(int unused, u16 *x, char *y, int z, u16 w, u16 v);
/* * Unlabelled leaf, four bytes: strh r1, [r0, 4]; bx lr. */ void func_02161FEC(char *p, u16 v);
void func_02161FF0(int a0, int a1);
void func_02162008(int a0, int a1, int a2);
int func_02162024(char *p, int index, void *out);
int func_0216202C(char *p, void *out, u8 *index);
void func_02162038(char *p, int index);
/* * The full target body overwrites r1/r2 with 0/8 before use; neither * caller nor thunk supplies those legacy trailing parameters. */ void func_02162040(char *p);
void func_02162048(u16 *a, int b, int c);
extern int d_0217144C[];





void func_02161F14(u16 *out, u8 *in, int c)
{
    int h;
    u16 *q;
    if (((struct Obj12331 *)in)->f2 == 1) {
        h = func_021867C4(in[9], (u16)((c & 0x7FFF) | 0x8000));
        q = func_0218682C(h);
        out[0] = q[0x24 / 2];
        out[1] = q[8 / 2];
        func_02186804(h);
    } else {
        out[0] = 0;
        out[1] = 10;
    }
}





int func_02161F54(int a0)
{
    int a1;
    int a2;
    int t4;

a1 = 0;
a2 = 0x48;
t4 = a0 + 0;
    a0 = func_02082BCC(a0, a1, a2);
loc_02161F60:
    a0 = func_02039338();
loc_02161F64:
((struct Obj17711 *)((char *)t4))->f0 = a0;
    return a0;}





void func_02161F68(void *p)
{
    func_02082BCC(p, 0, 0x48);
}





void func_02161F74(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
t6 = a2 + 0;
    a0 = func_0216210C(a0);
loc_02161F80:
    if (a0 != 0) goto loc_02161F8E;
loc_02161F84:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = t6 + 0;
    a0 = func_02162120(a0, a1, a2);
loc_02161F8E:
    return;}





void func_02161F90(int unused, u16 *x, char *y, int z, u16 w, u16 v)
{
    u8 *r4;
    int h;
    u16 *q;

    r4 = func_02161DC4(y, w, 1);
    h = (int)func_021867C4(w, v);
    q = func_0218682C(h);
    if (x[1] == 0)
        r4[2] = q[3];
    else
        r4[2] = q[2];
    r4[3] = 7;
    func_02186804(h);
    func_02186520(x, z, r4);
    func_02161E78(r4);
    func_02161E60((int)y, 1);
}




/*
 * Unlabelled leaf, four bytes: strh r1, [r0, 4]; bx lr.
 */
/*
 * Unlabelled leaf, four bytes: strh r1, [r0, #4]; bx lr.
 */
void func_02161FEC(char *p, u16 v)
{
    ((struct Obj18948 *)p)->f4 = v;
}




void func_02161FF0(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0216210C(a0);
loc_02161FFA:
    if (a0 != 0) goto loc_02162006;
loc_02161FFE:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216220C(a0, a1);
loc_02162006:
    return;}




void func_02162008(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
t6 = a2 + 0;
    a0 = func_0216210C(a0);
loc_02162014:
    if (a0 != 0) goto loc_02162022;
loc_02162018:
a0 = t5 + 0;
a1 = t4 + 0;
a2 = t6 + 0;
    a0 = func_02162230(a0, a1, a2);
loc_02162022:
    return;}



int func_02162024(char *p, int index, void *out)
{
    return func_021622AC(p, index, out);
}



int func_0216202C(char *p, void *out, u8 *index)
{
    *index = ((struct Obj18949 *)p)->f4;
    return func_021622D8(p, out);
}


void func_02162038(char *p, int index)
{
    func_02162330(p, index);
}


/*
 * The full target body overwrites r1/r2 with 0/8 before use; neither
 * caller nor thunk supplies those legacy trailing parameters.
 */
void func_02162040(char *p)
{
    func_02162358((int)p);
}



void func_02162048(u16 *a, int b, int c)
{
    S s;
    int t;

    if (func_0216210C((int)a) == 0) {
        func_02162298((int)a, b, c);
        return;
    }
    t = d_0217144C[c];
    if (t != 4) {
        s.x = *a;
        s.b = b;
        s.t = t;
        func_0216220C(a, &s);
    }
}
