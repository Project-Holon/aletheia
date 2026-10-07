/*
 * file:     fldmmdl_p03.c
 * unit:     yes
 * function: func_0216C44C, func_0216C484
 * address:  0x0216C44C
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
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0216C2FC 0x0216C2FC thumb ov010
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02188C58 0x02188C58 thumb ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj05905.h"
#include "../../matched/include/Obj02353.h"

struct Desc;
struct Obj;
struct Evt;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Work Work;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
extern void *func_020124E8(struct Obj *p);
extern int func_0216C2FC(void *evt, u32 *state, struct Work *w);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C58(void *);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int, int);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *func_020145CC(void *a0);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02082D44(void *, void *, int);
extern u32 func_020307B0(void *p);
void *func_0216C44C(void *a,void *b);
int func_0216C484(int a, int *st, int *o);

void *func_0216C44C(void *a,void *b) {
    void *t; u8 *p;
    t=func_020122C0(a,0,(void *)func_0216C2FC,0x14); p=func_020124E8(t);
    ((struct Obj05905 *)p)->f0=func_02188C84(b); ((struct Obj05905 *)p)->f4=a; ((struct Obj05905 *)p)->f8=b;
    ((struct Obj05905 *)p)->fC=func_02188C58(b); ((struct Obj05905 *)p)->f10=0; return t;
}


int func_0216C484(int a, int *st, int *o)
{
    int x = o[0];
    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE8D4((void *)x, o[1], 0, 0));
        (*st)++;
        break;
    case 1:
        func_02012374((struct Evt *)a, (struct Evt **)func_020144DC(x, o[1]));
        (*st)++;
        break;
    case 2:
        func_02012374((struct Evt *)a, func_02014910((char *)x, o[1], (int)((char *)o + 0x30), (int)((char *)o + 8)));
        (*st)++;
        break;
    case 3:
        func_02012374((struct Evt *)a, func_020145CC((void *)x));
        (*st)++;
        break;
    case 4:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, o[1], 0, 0, 1, 0, 0));
        func_02082D44((char *)o + 0x79, ((struct Obj02353 *)o)->fD0, 6);
        **(short * *)&((struct Obj02353 *)o)->fCC = o[0x6c / 4];
        **(short * *)&((struct Obj02353 *)o)->fC8 = o[0x70 / 4];
        func_020307B0((void *)o[0x44 / 4]);
        (*st)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}
