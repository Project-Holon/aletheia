/*
 * function: func_021BFA6C
 * address:  0x021BFA6C
 * packet:   pkt_ov021_021BFA6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
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
 */

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

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
extern void *func_02188C58(void *p);
extern u32 func_02188D38(u8 *p);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void *func_021C72AC(u32 a, u16 b, int c, int d);
extern void func_021C6DE0(u8 *p, u32 a, u32 b);
extern void *func_0218FE80(void *a);
extern void func_0218FEA0(u8 *p, u32 v);
extern void func_0218FEA4(int);
extern void func_0218FE78(int, V8 *);
extern void func_0218FEC0(u8 *o);
extern void func_0218FF00(int);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021C6E48(int);
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern u32 func_02188CD0(u8 *p);
extern void func_021AC528(u32 a, u32 b);
extern void func_0218FF20(u8 *a);
extern void func_0218FE98(int);

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
        func_021C6DE0((u8 *)d, (u32)func_021C72AC(obj, 0x3c, 8, 1), 0);
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
            t = func_021A3074(func_02188CB4((unsigned char *)obj));
            func_021AC528((u32)t, func_02188CD0((u8 *)obj));
            (*state)++;
        }
        break;
    case 5:
        func_0218FF20((u8 *)q->f58);
        func_0218FE98(q->f58);
        return 1;
    }
    return 0;
}
