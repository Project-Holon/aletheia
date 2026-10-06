/*
 * function: func_021BFB90
 * address:  0x021BFB90
 * packet:   pkt_ov021_021BFB90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C7858  0x021C7858  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */

typedef struct { int x, y, z; } Vec;

typedef unsigned char  u8;
struct Evt;
extern void *func_02188C58(void *p);
extern unsigned int func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, unsigned int s);
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern void func_0216D8C0(void *, Vec *);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_021C71D4(unsigned int a, unsigned int b, unsigned int c);
extern int func_021C7858(unsigned int a, unsigned int b, unsigned int c);
extern unsigned int func_02188D38(u8 *p);
extern void func_021C6DE0(u8 *p, unsigned int a, unsigned int b);
extern int func_021C6E48(int);
extern unsigned int func_02188CD0(u8 *p);
extern void func_021AC528(unsigned int a, unsigned int b);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);

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
        t = func_021A3074(func_02188CB4((unsigned char *)obj));
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
        func_021C6DE0((u8 *)d, w, 0);
        func_021C6DE0((u8 *)d, x, 0);
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(func_02188D38((u8 *)obj)) != 0)
            (*state)++;
        break;
    case 2:
        t = func_021A3074(func_02188CB4((unsigned char *)obj));
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
