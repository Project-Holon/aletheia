/*
 * file:     field_g3dobj_p02.c
 * unit:     yes
 * function: func_021C6078, func_021C60B8
 * address:  0x021C6078
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_021C1D68  0x021C1D68  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021C61D4  0x021C61D4  thumb  ov021
 *   func_021C61EC  0x021C61EC  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021A9F40  0x021A9F40  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 */
#include "../../matched/include/Obj06082.h"

struct Ctx;
struct Desc;
struct Obj;
struct Obj00020;
struct Evt;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {
    u8 f0;
    u8 pad1[3];
    u32 f4;
    u32 f8;
    void *fC;
    void *f10;
} Work;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_021A2F48(u8 *p, u32 a1);
extern int func_021A2F54(u8 *p);
extern void *func_021A3074(u8 *p);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D480(char *p);
extern void *func_02189A00(u8 *p);
extern int func_021C1D68(int a, int b, int c);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021C61D4(u32 a);
extern void func_021C61EC(void *a, void *b, void *c);
extern u32 func_02188CE8(u8 *p);
extern int func_021A9F40(struct Ctx *ctx, int mode);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern void *func_02188C7C(u8 *p);
extern u32 *func_0216D9E4(void *c);
void *func_021C6078(void *a, void *b, u8 c);
int func_021C60B8(void *task, int *state, Work *w);


void *func_021C6078(void *a, void *b, u8 c)
{
    void *task;
    u8 *w;

    task = func_020122C0(a, 0, func_021C60B8, 0x14);
    w = func_020124E8(task);
    func_02082BCC(w, 0, 0x14);
    w[0] = c;
    ((struct Obj06082 *)w)->f4 = a;
    ((struct Obj06082 *)w)->fC = b;
    ((struct Obj06082 *)w)->f10 = func_02188CB4(b);
    ((struct Obj06082 *)w)->f8 = func_020120F4(a);
    return task;
}


int func_021C60B8(void *task, int *state, Work *w)
{
    void *t;

    switch (*state) {
    case 0:
        if (w->f0 >= 6) {
            *state = 5;
            break;
        }
        func_021A2F48(w->f10, 0x80);
        (*state)++;
    case 1:
        if (func_021A2F54(w->f10) != 1)
            break;
        func_0216D410(func_021A3074(w->f10), 0xa2);
        (*state)++;
        break;
    case 2:
        if (func_0216D480(func_021A3074(w->f10)) != 1)
            break;
        t = (void *)func_021C1D68(w->f4, (int)func_02189A00(w->fC), w->f0);
        if (t != 0)
            func_02012374(task, t);
        (*state)++;
        break;
    case 3:
        func_021A2F48(w->f10, 8);
        (*state)++;
    case 4:
        if (func_021A2F54(w->f10) != 1)
            break;
        *state = 5;
        break;
    case 5:
        if (func_021C61D4((u32)w) == 0) {
            *state = 8;
            break;
        }
        func_021C61EC(task, (void *)w->f4, w->fC);
        *state = 6;
        break;
    case 6:
        t = (void *)func_021A9F40((struct Ctx *)func_02188CE8(w->fC), 2);
        if (t == 0) {
            *state = 7;
            break;
        }
        func_02012374(task, t);
        *state = 9;
        break;
    case 7:
        func_02158780(task, 0x2793, 0, 0, 0x15);
        *state = 9;
        break;
    case 8:
        func_02158780(task, 0x2794, 0, 0, 0x15);
        *state = 9;
        break;
    case 9:
        func_0216D9E4(func_02188C7C(w->fC));
        return 1;
    }
    return 0;
}
