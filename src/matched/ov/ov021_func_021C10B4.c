/*
 * function: func_021C10B4
 * address:  0x021C10B4
 * packet:   pkt_ov021_021C10B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ACB38  0x021ACB38  thumb  ov021
 *   func_021A2F8C  0x021A2F8C  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AA900  0x021AA900  thumb  ov021
 *   func_021AAB1C  0x021AAB1C  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_021A2F98  0x021A2F98  thumb  ov021
 *   func_021ACBB8  0x021ACBB8  thumb  ov021
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_021A35A0  0x021A35A0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

typedef struct {
    u16 state;
    s16 count;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 padA;
    u32 fC;
    u8 *f10;
    u32 f14;
} Work;

extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *obj);
extern int func_0216D83C(void *obj);
extern int func_0216D86C(void *obj);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_02164280(int x, int y, Vec *v);
extern void func_02164208(u32 dir, Vec *v, int step);
extern int func_02163E58(void *obj, Vec *v, int *h);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021ACB38(u32, u32, Vec *, void *, int);
extern void func_021A2F8C(u8 *a, u32 b);
extern u32 func_02188CE8(u8 *p);
struct Self;
extern int func_021AA900(struct Self *self, short *pos);
extern void func_021AAB1C(void *p, int b);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *obj, u32 a);
extern int func_0216D454(void *obj);
extern int func_0216D480(char *p);
extern u32 func_021A2F98(u8 *a);
extern void func_021ACBB8(u32 a, u8 v);
extern void func_021A2F48(u8 *a, int b);
extern int func_021A2F54(u8 *a);
extern void func_021A35A0(u8 *a, int b);

void func_021C10B4(u32 task, Work *w)
{
    void *obj;
    u16 dir;
    u32 r;
    int x;
    int y;
    Vec v;
    int h;
    s16 pos[3];
    void *q;
    int step;

    obj = func_021A3074(w->f10);
    switch (w->state) {
    case 0:
        dir = func_0216D5F8(obj);
        x = func_0216D83C(obj);
        y = func_0216D86C(obj);
        func_0216D88C(obj, (struct VecFx32 *)&v);
        func_02164280(x, y, &v);
        step = 0x10000;
        if (w->f8 == 1)
            step = 0x20000;
        func_02164208(dir, &v, step);
        h = 0;
        func_02163E58(obj, &v, &h);
        v.y = h;
        func_021A2F8C(w->f10, func_021ACB38(func_02188CD0((u8 *)w->fC), dir, &v, obj, 0));
        q = (void *)func_02188CE8((u8 *)w->fC);
        pos[0] = (v.x >> 4) / 0x1000;
        pos[1] = (v.y >> 4) / 0x1000;
        pos[2] = (v.z >> 4) / 0x1000;
        if (func_021AA900(q, pos))
            func_021AAB1C(q, 1);
        w->state++;
        break;
    case 1:
        w->count++;
        if (w->count > 15)
            w->state++;
        break;
    case 2:
        dir = func_0216D5F8(obj);
        r = func_02197E7C(dir, 0x34);
        if (w->f8 == 1)
            r = func_02197E7C(dir, 0x38);
        func_0216D410(obj, r);
        w->state++;
        break;
    case 3:
        if (func_0216D454(obj) == 0)
            break;
        func_0216D480(obj);
        func_021ACBB8(func_021A2F98(w->f10), 1);
        func_021A2F48(w->f10, 4);
        w->state++;
    case 4:
        if (func_021A2F54(w->f10) == 1) {
            func_021A35A0(w->f10, 1);
            w->f4 = 1;
            w->state++;
        }
        break;
    case 5:
        break;
    }
}
