/*
 * file:     field_player_grid_event_p13.c
 * unit:     yes
 * function: func_021C04C0, func_021C0598, func_021C05D4
 * address:  0x021C04C0
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C7814  0x021C7814  thumb  ov021
 *   func_021C7858  0x021C7858  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_0204E804  0x0204E804  arm
 *   sub_02030734  0x02030734  arm
 *   d_021DE3A0  0x021DE3A0  data  ov021  a1
 */
struct Obj00020;
typedef struct { int x, y, z; } Vec;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct { int x, y, w, h, f10, active; } Rect;

typedef struct {
    u32 n;
    u8 *e;
} Tab;

extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C58(void *p);
extern unsigned int func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, unsigned int s);
extern void *func_021C71D4(unsigned int a, unsigned int b, unsigned int c);
extern int func_021C7814(int, int, int, int, int);
extern int func_021C7858(unsigned int a, unsigned int b, unsigned int c);
extern unsigned int func_02188D38(u8 *p);
extern void func_021C6DE0(u8 *p, unsigned int *a, unsigned int b);
extern void func_020061E4(u32 a);
extern int func_021C6E48(int);
extern int func_0204E804(void);
extern void *sub_02030734(u32 heap, u32 size, int align, const char *file, unsigned short line);
int func_021C04C0(int task, int *state, int *q);
int func_021C0598(int x, int y, const Rect *r);
Tab *func_021C05D4(u32 n, u32 heap);
extern u8 d_021DE3A0[];


int func_021C04C0(int task, int *state, int *q)
{
    int obj;
    int h;
    int w;
    int e;
    int x;
    int d;

    obj = q[1];
    func_02188CB4((void *)obj);
    h = (int)func_02188C58((void *)obj);

    switch (*state) {
    case 0:
        q[2] = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        {
            Vec v;
            v.y = 0x96000;
            v.x = 0;
            v.z = 0;
            w = (int)func_021C71D4(obj, 0x18, 3);
            e = func_021C7814(obj, 3, 0, 0x10, 1);
            x = func_021C7858(obj, 0x18, (unsigned int)(&v));
        }
        d = func_02188D38((u8 *)obj);
        func_021C6DE0((u8 *)d, (unsigned int *)w, 0);
        func_021C6DE0((u8 *)d, (unsigned int *)x, 0);
        func_021C6DE0((u8 *)d, (unsigned int *)e, x);
        func_020061E4(0x676);
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(func_02188D38((u8 *)obj)) != 0 && func_0204E804() == 0)
            (*state)++;
        break;
    case 2:
        func_0218E13C((u8 *)h, q[2]);
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}


/*
 * Point-in-rectangle test against an active rect (EXACT*: trailing pad).
 */
int func_021C0598(int x, int y, const Rect *r)
{
    int l, t, rr, b;

    if (r->active == 0)
        return 0;
    l = r->x;
    t = r->y;
    rr = l + r->w - 1;
    b = t + r->h - 1;
    if (l <= x && x <= rr && t <= y && y <= b)
        return 1;
    return 0;
}


Tab *func_021C05D4(u32 n, u32 heap)
{
    u8 i;
    Tab *t;

    i = 0;
    t = (Tab *)sub_02030734(heap, 8, 0, (const char *)d_021DE3A0, 0x5a);
    t->e = (u8 *)sub_02030734(heap, n * 0x1c, 0, (const char *)d_021DE3A0, 0x5b);
    t->n = n;
    for (i = 0; i < n; i++) {
        *(u32 *)(t->e + i * 0x1c + 0x14) = 0;
    }
    return t;
}
