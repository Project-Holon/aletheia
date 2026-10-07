/*
 * file:     field_player_grid_event_p08.c
 * unit:     yes
 * function: func_021BFA5C, func_021BFA6C, func_021BFB90, func_021BFC98
 * address:  0x021BFA5C
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
 *   func_021BF9F4  0x021BF9F4  thumb  ov021
 *   func_021BF978  0x021BF978  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021C72AC  0x021C72AC  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FEC0  0x0218FEC0  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_0218FF20  0x0218FF20  thumb  ov021
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C7858  0x021C7858  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D410 0x0216D410 thumb ov010
 *   func_0216D454 0x0216D454 thumb ov010
 *   func_0216D480 0x0216D480 thumb ov010
 */
struct Evt;
struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    int w[8];
} V8;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    V8 v10;
    V8 v30;
    int f50;
    int f54;
    int f58;
} Q;

typedef struct { int x, y, z; } Vec;

extern int func_021BF9F4(void **a);
extern void func_021BF978(void *p);
extern void *func_02188C58(void *p);
extern u32 func_02188D38(u8 *p);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void *func_021C72AC(u32 a, u16 b, int c, int d);
extern void func_021C6DE0(u8 *p, u32 *a, u32 b);
extern void *func_0218FE80(void *a);
extern void func_0218FEA0(u8 *p, u32 v);
extern void func_0218FEA4(int);
extern void func_0218FE78(int, V8 *);
extern void func_0218FEC0(u8 *o);
extern int func_0218FF00(u32 a);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021C6E48(int);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u32 func_02188CD0(u8 *p);
extern void func_021AC528(u32 a, u32 b);
extern void func_0218FF20(u8 *a);
extern void func_0218FE98(void *a0);
extern unsigned int func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, unsigned int s);
extern void func_0216D8C0(void *, Vec *);
extern void *func_021C71D4(unsigned int a, unsigned int b, unsigned int c);
extern int func_021C7858(unsigned int a, unsigned int b, unsigned int c);
extern void func_020061E4(u32 a);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D454(void *);
extern int func_0216D480(char *p);
void func_021BFA5C(u8 *p);
int func_021BFA6C(int task, int *state, Q *q);
int func_021BFB90(int task, int *state, int *q);
int func_021BFC98(int a, int *s, int *q);


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFA5C(u8 *p)
{
    func_021BF9F4((void **)p);
    func_021BF978(p);
}


int func_021BFA6C(int task, int *state, Q *q)
{
    int q0;
    int obj;
    int h;
    int d;
    int r0;
    void *t;

    q0 = q->f0;
    obj = q->f4;
    h = (int)func_02188C58((void *)obj);
    d = func_02188D38((u8 *)obj);

    switch (*state) {
    case 0:
        func_0218F0A8((u8 *)h);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8((u8 *)h) == 0)
            (*state)++;
        break;
    case 2:
        func_021C6DE0((u8 *)d, (u32 *)func_021C72AC(obj, 0x3c, 8, 1), 0);
        r0 = (int)func_0218FE80((void *)obj);
        q->fc = 60;
        q->f50 = 1;
        q->f54 = 1;
        q->f58 = r0;
        func_0218FEA0((u8 *)r0, (u32)(&q->fc));
        func_0218FEA4(q->f58);
        func_0218FE78(h, &q->v30);
        q->v10 = q->v30;
        q->v10.w[1] = q->v10.w[1] - 0x64000;
        func_0218FEC0((u8 *)q->f58);
        func_0218FF00(q->f58);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)task, (struct Evt **)func_021BE92C((void *)q0, obj, 0, 1, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        if (func_021C6E48(d) != 0) {
            t = func_021A3074(func_02188CB4((struct Obj00020 *)obj));
            func_021AC528((u32)t, func_02188CD0((u8 *)obj));
            (*state)++;
        }
        break;
    case 5:
        func_0218FF20((u8 *)q->f58);
        func_0218FE98((void *)q->f58);
        return 1;
    }
    return 0;
}


int func_021BFB90(int task, int *state, int *q)
{
    int obj;
    int h;
    void *t;
    int w;
    int x;
    int d;

    obj = q[1];
    h = (int)func_02188C58((void *)obj);

    switch (*state) {
    case 0:
        q[2] = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        t = func_021A3074(func_02188CB4((struct Obj00020 *)obj));
        {
            Vec v;
            v.y = 0xA000;
            v.x = 0;
            v.z = 0;
            func_0216D8C0(t, &v);
        }
        func_02012374((struct Evt *)task, (struct Evt **)func_021BE92C((void *)q[0], obj, 0, 1, 1, 0, 0));
        {
            Vec v2;
            v2.y = 0x96000;
            v2.x = 0;
            v2.z = 0;
            w = (int)func_021C71D4(obj, 0x18, 3);
            x = func_021C7858(obj, -0x18, (unsigned int)(&v2));
        }
        d = func_02188D38((u8 *)obj);
        func_021C6DE0((u8 *)d, (unsigned int *)w, 0);
        func_021C6DE0((u8 *)d, (unsigned int *)x, 0);
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(func_02188D38((u8 *)obj)) != 0)
            (*state)++;
        break;
    case 2:
        t = func_021A3074(func_02188CB4((struct Obj00020 *)obj));
        func_021AC528((unsigned int)t, func_02188CD0((u8 *)q[1]));
        func_020061E4(0x67B);
        (*state)++;
        break;
    case 3:
        func_0218E13C((u8 *)h, q[2]);
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}


int func_021BFC98(int a, int *s, int *q)
{
    int h = (int)func_02188C58((void *)q[1]);
    void *t;

    t = func_021A3074(func_02188CB4((struct Obj00020 *)q[1]));
    switch (s[0]) {
    case 0:
        q[2] = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        func_0216D410(t, 0x44);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)q[0], q[1], 0, 1, 1, 0, 0));
        s[0] = s[0] + 1;
        break;
    case 1:
        if (func_0216D454(t) == 1) {
            func_0216D480(t);
            s[0] = s[0] + 1;
        }
        break;
    case 2:
        func_0218E13C((u8 *)h, q[2]);
        s[0] = s[0] + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}
