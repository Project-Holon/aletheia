/*
 * file:     scrcmd_musical_p04.c
 * unit:     yes
 * function: func_0215DF6C, func_0215DF78, func_0215DFB4, func_0215E010
 * address:  0x0215DF6C
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
 *   func_020307B0  0x020307B0  arm
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_021FC81C  0x021FC81C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02012F80  0x02012F80  thumb
 *   func_021CD688  0x021CD688  thumb
 *   func_021FC804  0x021FC804  thumb
 *   func_021CD5A4  0x021CD5A4  thumb
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj09156.h"
#include "../../matched/include/Obj02658.h"

struct Ctx;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

struct W {
    u8 pad00[4];
    void *f4;
    void *f8;
    u8 pad0c[0x24];
    u16 *f30;
};

extern u32 func_020307B0(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u32 func_02012138(const struct Ctx *p);
extern int func_021FC81C();
extern void *func_0215A5F4(void *p);
extern int func_02012F80(char *base);
extern int func_021CD688();
extern int func_021FC804();
extern int func_021CD5A4();
void func_0215DF6C(void **p);
void func_0215DF78(int a0, int a1, int a2);
int func_0215DFB4(int a0, int a1);
int func_0215E010(void *a, void *b);

void func_0215DF6C(void **p) { func_020307B0(*p); }


void func_0215DF78(int a0, int a1, int a2)
{
    int t4;
    void *v0;
    void *v1;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    v0 = func_0215A5DC((void *)a0);
loc_0215DF82:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    v1 = func_0215A5E4((void *)a0);
loc_0215DF8A:
    a0 = func_02012138(v0);
loc_0215DF90:
a2 = *(int *)&((struct Obj00005 *)t4)->f4;
a0 = ((struct Obj09156 *)a2)->f28;
    if (a0 == 0xc) goto loc_0215DFAC;
loc_0215DF98:
    if (a0 == 0xd) goto loc_0215DFAC;
loc_0215DF9C:
a0 = ((struct Obj09156 *)a2)->f30;
a1 = 1;
*(u16 *)&((struct Obj00005 *)((char *)a0))->f0 = a1;
a0 = *(int *)&((struct Obj00005 *)t4)->f4;
a0 = *(int *)&((struct Obj00005 *)a0)->f4;
    a0 = func_021FC81C(a0, a1);
loc_0215DFAA:
    return;
loc_0215DFAC:
a0 = ((struct Obj09156 *)a2)->f30;
a1 = 0;
*(u16 *)&((struct Obj00005 *)((char *)a0))->f0 = a1;
    return;}


/*
 * blocked:  listing 92 compiled 90
 */
int func_0215DFB4(int a0, int a1)
{
    int t4;
    int t5;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215DFBE:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0215DFC4:
    a0 = func_02012F80(v1);
loc_0215DFC8:
t4 = a0 + 0;
a0 = ((struct Obj02658 *)t4)->f8;
    a0 = func_021CD688(a0);
loc_0215DFD0:
t5 = 0;
    if (a0 == 1) goto loc_0215DFE0;
loc_0215DFD6:
    if (a0 == 2) goto loc_0215DFEC;
loc_0215DFDA:
    if (a0 == 4) goto loc_0215DFF4;
loc_0215DFDE:
    goto loc_0215DFFC;
loc_0215DFE0:
a0 = ((struct Obj02658 *)t4)->f30;
((struct Obj02658 *)((char *)a0))->f0 = t5;
a0 = ((struct Obj02658 *)t4)->f4;
    a0 = func_021FC804(a0);
loc_0215DFEA:
    goto loc_0215DFFA;
loc_0215DFEC:
a0 = ((struct Obj02658 *)t4)->f30;
t5 = 1;
((struct Obj02658 *)((char *)a0))->f0 = t5;
    goto loc_0215DFFC;
loc_0215DFF4:
a0 = ((struct Obj02658 *)t4)->f30;
a1 = 2;
((struct Obj02658 *)((char *)a0))->f0 = a1;
loc_0215DFFA:
t5 = 1;
loc_0215DFFC:
    if (t5 != 1) goto loc_0215E00A;
loc_0215E000:
a0 = ((struct Obj02658 *)t4)->f8;
    a0 = func_021CD5A4(a0);
loc_0215E006:
a0 = 0;
((struct Obj02658 *)t4)->f8 = a0;
loc_0215E00A:
a0 = t5 + 0;
    return a0;}


int func_0215E010(void *a, void *b)
{
    struct W *w;
    int r;
    int v;

    func_0215A5F4(b);
    w = (struct W *)func_02012F80(func_0215A5E4(b));
    r = 0;
    switch (func_021CD688(w->f8)) {
    case 1:
        *w->f30 = 3;
        func_021FC804(w->f4);
        r = 1;
        break;
    case 2:
        v = 4;
        *w->f30 = v;
        r = 1;
        break;
    case 4:
        v = 2;
        *w->f30 = v;
        r = 1;
        break;
    }
    if (r == 1) {
        func_021CD5A4(w->f8);
        w->f8 = 0;
    }
    return r;
}
