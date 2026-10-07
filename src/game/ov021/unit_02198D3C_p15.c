/*
 * file:     unit_02198D3C_p15.c
 * unit:     yes
 * function: func_0219A260, func_0219A270, func_0219A280, func_0219A290, func_0219A2B8, func_0219A3D8
 * address:  0x0219A260
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
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0219B0F0  0x0219B0F0  thumb  ov021
 *   func_0219B104  0x0219B104  thumb  ov021
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0219A4CC  0x0219A4CC  thumb  ov021
 *   func_021639C0  0x021639C0  thumb  ov010
 *   func_0216DA44  0x0216DA44  thumb  ov010
 *   d_021D4FA4     0x021D4FA4  data  a4
 *   func_0216D7E8  0x0216D7E8  thumb  ov010
 *   func_0216D7F8  0x0216D7F8  thumb  ov010
 *   func_0216D660  0x0216D660  thumb  ov010
 *   func_0216D66C  0x0216D66C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    s16 state;
    s16 timer;
    int mode;
    u32 arg;
    u32 v;
} St;

typedef struct { int left, top, right, bottom; } Rect;

extern void *func_0216D684(int a0, int a1, u32 a2, u32 a3);
extern void func_0216D674(void *p, u16 v);
extern void func_0216DA50(u8 *p);
extern void *func_0216D69C(void *p);
extern void func_0216DA7C(u8 *p);
extern u16 func_0216D5F8(void *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(char *a0, int a1);
extern u32 func_02197EDC(u8 *p);
extern int func_0219B0F0(u32 a, u32 b);
extern u32 func_0219B104(u32, u32);
extern void func_0216D60C(u32, u16);
extern int func_0219A4CC(u32, u32);
extern int func_021639C0(u32, u16);
extern void func_0216DA44(u32);
extern int func_0216D7E8(void *p);
extern int func_0216D7F8(void *p);
extern int func_0216D660(void *p);
extern int func_0216D66C(void *p);
extern u16 func_0216D5A0(void *p);
void func_0219A260(u32 a1);
void func_0219A270(u32 a1);
void func_0219A280(u32 a1);
void func_0219A290(u32 a, u32 b, u32 c, u32 d);
void func_0219A2B8(u32 a);
void func_0219A3D8(u32 a, Rect *r);
extern u8 d_021D4FA4[];


/*
 * Calls func_0219A290(its own argument 1, 0xc, 0xc, 0x0) and returns nothing.
 */
void func_0219A260(u32 a1)
{
    func_0219A290(a1, 0xc, 0xc, 0x0);
}


/*
 * Calls func_0219A290(its own argument 1, 0xc, 0xd, 0x0) and returns nothing.
 */
void func_0219A270(u32 a1)
{
    func_0219A290(a1, 0xc, 0xd, 0x0);
}


/*
 * Calls func_0219A290(its own argument 1, 0xc, 0xd, 0x2) and returns nothing.
 */
void func_0219A280(u32 a1)
{
    func_0219A290(a1, 0xc, 0xd, 0x2);
}


void func_0219A290(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p = func_0216D684(a, 16, c, d);
    p[1] = d;
    p[2] = b;
    p[3] = c;
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
}


/*
 * Addresses are Black-image addresses.
 */
void func_0219A2B8(u32 a)
{
    St *p;
    u32 r;
    int f;

    p = func_0216D69C((void *)a);
    switch (p->state) {
    case 0:
        func_0216DA50((u8 *)a);
        func_0216DA7C((u8 *)a);
        func_0216D438((char *)a, (u16)((u32)func_02197E7C((u16)((u32)func_0216D5F8((void *)a)), (u16)0)));
        p->state++;
        break;
    case 1:
        if (func_02197EDC((u8 *)a) == 0)
            break;
        p->timer = func_0219B0F0((u32)d_021D4FA4, -1);
        p->state++;
    case 2:
        p->timer--;
        if (p->timer != 0)
            break;
        p->state++;
    case 3:
        r = func_0219B104(p->v, 9);
        func_0216D60C(a, r);
        if (p->mode == 1 && func_0219A4CC(a, r) == 0) {
            p->state = 0;
            return;
        }
        f = func_021639C0(a, r);
        if (f != 0) {
            if (p->mode == 2) {
                if (f & 1) {
                    p->state = 0;
                    return;
                }
            } else {
                p->state = 0;
                return;
            }
        }
        func_0216D438((char *)a, (u16)((u32)func_02197E7C((u16)r, (u16)p->arg)));
        func_0216DA44(a);
        p->state++;
    case 4:
        if (func_02197EDC((u8 *)a) != 0) {
            func_0216DA50((u8 *)a);
            p->state = 0;
        }
        break;
    }
}


/*
 * Addresses are Black-image addresses.
 * Store order in each arm is left, right, top, bottom (x pair, then y pair);
 * the field order left, top, right, bottom puts stores to +0/+8 first.
 */
void func_0219A3D8(u32 a, Rect *r)
{
    int x;
    int y;
    int w;
    int h;

    x = func_0216D7E8((void *)a);
    y = func_0216D7F8((void *)a);
    w = func_0216D660((void *)a);
    h = func_0216D66C((void *)a);
    switch (func_0216D5A0((void *)a)) {
    case 6:
        r->left = x - w;
        r->right = x;
        r->top = y - h;
        r->bottom = y;
        break;
    case 7:
        r->left = x;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y;
        break;
    case 8:
        r->left = x - w;
        r->right = x;
        r->top = y;
        r->bottom = y + h;
        break;
    case 9:
        r->left = x;
        r->right = x + w;
        r->top = y;
        r->bottom = y + h;
        break;
    case 10:
        r->left = x - w;
        r->right = x;
        r->top = y - h;
        r->bottom = y + h;
        break;
    case 11:
        r->left = x;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y + h;
        break;
    case 12:
        r->left = x - w;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y;
        break;
    case 13:
        r->left = x - w;
        r->right = x + w;
        r->top = y;
        r->bottom = y + h;
        break;
    }
}
