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

extern int func_02188C58(int);
extern int func_0218E138(int);
extern void func_0218E13C(int, int);
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern void func_0216D8C0(int, Vec *);
extern int func_021BE92C(int, int, int, int, int, int, int);
extern void func_02012374(int, int);
extern int func_021C71D4(int, int, int);
extern int func_021C7858(int, int, Vec *);
extern int func_02188D38(int);
extern void func_021C6DE0(int, int, int);
extern int func_021C6E48(int);
extern int func_02188CD0(int);
extern void func_021AC528(int, int);
extern void func_020061E4(int);

int func_021BFB90(int task, int *state, int *q)
{
    int obj;
    int h;
    void *t;
    int w;
    int x;
    int d;

    obj = q[1];
    h = func_02188C58(obj);

    switch (*state) {
    case 0:
        q[2] = func_0218E138(h);
        func_0218E13C(h, 0);
        t = func_021A3074(func_02188CB4((void *)obj));
        {
            Vec v;
            v.y = 0xA000;
            v.x = 0;
            v.z = 0;
            func_0216D8C0(t, &v);
        }
        func_02012374(task, func_021BE92C(q[0], obj, 0, 1, 1, 0, 0));
        {
            Vec v2;
            v2.y = 0x96000;
            v2.x = 0;
            v2.z = 0;
            w = func_021C71D4(obj, 0x18, 3);
            x = func_021C7858(obj, -0x18, &v2);
        }
        d = func_02188D38(obj);
        func_021C6DE0(d, w, 0);
        func_021C6DE0(d, x, 0);
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(func_02188D38(obj)) != 0)
            (*state)++;
        break;
    case 2:
        t = func_021A3074(func_02188CB4((void *)obj));
        func_021AC528(t, func_02188CD0(q[1]));
        func_020061E4(0x67B);
        (*state)++;
        break;
    case 3:
        func_0218E13C(h, q[2]);
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
