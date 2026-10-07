/*
 * file:     field_player_grid_event_p16.c
 * unit:     yes
 * function: func_021C0810, func_021C0820, func_021C0844, func_021C0904
 * address:  0x021C0810
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
 *   func_02012124  0x02012124  thumb
 *   _s32_div_f  0x0209C0A4  arm
 *   func_021C09B0  0x021C09B0  thumb  ov021
 *   func_021C09A8  0x021C09A8  thumb  ov021
 *   func_021C0A10  0x021C0A10  thumb  ov021
 *   func_021C0A48  0x021C0A48  thumb  ov021
 *   func_021C0A70  0x021C0A70  thumb  ov021
 *   func_021C0988  0x021C0988  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02029830  0x02029830  thumb
 *   func_02029620  0x02029620  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218C584  0x0218C584  thumb  ov021
 *   func_0218C6D0  0x0218C6D0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj00707.h"
#include "../../matched/include/Obj02394.h"

struct Ctx;
struct Desc;
struct Obj;
struct Evt;
struct Obj00020;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_02012124(struct Ctx *p, u32 v);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
extern void func_021C09B0(u8 *p);
extern void func_021C09A8(u8 *p, int *st, int v);
extern void func_021C0A10(u8 *p);
extern void func_021C0A48(u8 *p);
extern int func_021C0A70(u8 *p);
extern void func_021C0988(u8 *p);
extern void *func_02188C80(void *p);
extern void *func_02029830(void *a, u32 b);
extern void *func_02029620(void *a, u32 b, u32 c);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_0201210C(const struct Ctx *p);
extern u16 func_02188C84(u8 *p);
extern u32 func_02188C98(u8 *p);
extern u32 func_0218DC6C(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *a, struct VecFx32 *pos);
extern u32 *func_0218C584(u32 a, int *rect, u32 n, int *cnt);
extern void func_0218C6D0(int *p, int b);
extern u32 func_020307B0(void *p);
int func_021C0810(u32 a, u32 b, u32 c, u32 d);
void *func_021C0820(void *p, int a1, u32 n);
int func_021C0844(u32 a, int *st, u8 *p);
void func_021C0904(u8 *p, u32 a, u32 n);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C0810(u32 a, u32 b, u32 c, u32 d)
{
func_02012124((struct Ctx *)c, 0);
return 1;
}


void *func_021C0820(void *p, int a1, u32 n)
{
    void *t = func_020122C0(p, (void *)a1, func_021C0844, 0x38);
    u8 *w = func_020124E8(t);

    func_021C0904(w, (u32)p, n);
    return t;
}


int func_021C0844(u32 a, int *st, u8 *p)
{
    switch (*st) {
    case 0:
        if ((int)((struct Obj00707 *)p)->f16 % 15 == 0) {
            func_021C09B0(p);
            if (p[0x14] <= p[0x15]) {
                func_021C09A8(p, st, 1);
            }
        }
        break;
    case 1:
        if (((struct Obj00707 *)p)->f16 > 10) {
            func_021C0A10(p);
            func_02012374((struct Evt *)a, func_02029830(func_02188C80((void *)(((struct Obj00707 *)p)->f4)), 0x514));
            func_021C09A8(p, st, 2);
        }
        break;
    case 2:
        if (func_021C0A70(p) != 0) {
            func_021C0A48(p);
            func_021C09A8(p, st, 3);
        }
        break;
    case 3:
        func_02012374((struct Evt *)a, func_02029620(func_02188C80((void *)(((struct Obj00707 *)p)->f4)), 0, 6));
        func_021C09A8(p, st, 4);
        break;
    case 4:
        func_021C0988(p);
        return 1;
    }
    ((struct Obj00707 *)p)->f16 = ((struct Obj00707 *)p)->f16 + 1;
    return 0;
}


void func_021C0904(u8 *p, u32 a, u32 n)
{
    void *s;
    u32 w;
    u32 t;
    u32 *r;
    int pos[3];
    int rect[4];
    int cnt;

    s = func_0201210C((void *)a);
    w = func_02188C84(s);
    t = func_02188C98(s);
    ((struct Obj02394 *)p)->f0 = w;
    p[0x14] = n;
    ((struct Obj02394 *)p)->f4 = s;
    p[0x15] = 0;
    ((struct Obj02394 *)p)->f18 = func_0218DC6C((u8 *)t);
    ((struct Obj02394 *)p)->f34 = 0;
    if (p[0x14] > 6) {
        p[0x14] = 6;
    }
    func_021A3038(func_02188CB4(((struct Obj02394 *)p)->f4), (struct VecFx32 *)pos);
    rect[0] = pos[2] - 0x50000;
    rect[1] = pos[2] + 0x50000;
    rect[2] = pos[0] - 0x50000;
    rect[3] = pos[0] + 0x50000;
    r = func_0218C584(((struct Obj02394 *)p)->f18, rect, 3, &cnt);
    if (r) {
        ((struct Obj02394 *)p)->f34 = *r;
        func_0218C6D0((int *)(*r), (int)(p + 8));
    }
    func_020307B0(r);
}
