/*
 * function: func_021BFE2C
 * address:  0x021BFE2C
 * packet:   pkt_ov021_021BFE2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_02006148  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C584  0x0218C584  thumb  ov021
 *   func_0218C724  0x0218C724  thumb  ov021
 *   func_0218C88C  0x0218C88C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021C754C  0x021C754C  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_0218C8FC  0x0218C8FC  thumb  ov021
 *   func_0203630C  0x0203630C  arm
 *   func_0216D410  0x0216D410  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_021C7858  0x021C7858  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C6F00  0x021C6F00  thumb  ov021
 *   func_021C7814  0x021C7814  thumb  ov021
 *   func_020061F8  0x020061F8  thumb
 *   func_0218C860  0x0218C860  thumb  ov021
 */

typedef struct { int x, y, z; } Vec;

extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern int func_02188CD0(int);
extern int func_02188C58(int);
extern int func_0218E138(int);
extern void func_0218E13C(int, int);
extern int func_02006148(int);
extern void func_0200616C(int, int);
extern int func_02188C98(int);
extern int func_0218DC6C(int);
extern int *func_0218C584(int, int *, int, int *);
extern int func_0218C724(int, int);
extern void func_0218C88C(int, int, int);
extern void func_020307B0(void *);
extern void func_021A3038(int, Vec *);
extern int func_021C754C(int, int, int *);
extern int func_02188D38(int);
extern void func_021C6DE0(int, int, int);
extern int func_0218C8FC(int, int);
extern unsigned int func_0203630C(void);
extern void func_0216D410(int, int);
extern void func_021AC528(int, int);
extern int func_021C6E48(int);
extern void func_020061E4(int);
extern void func_0216D568(int, int);
extern int func_021C7858(int, int, Vec *);
extern int func_021C71D4(int, int, int);
extern int func_021C6F00(int, int, int);
extern int func_021C7814(int, int, int, int, int);
extern void func_020061F8(int);
extern void func_0218C860(int);

int func_021BFE2C(int task, int *state, int *q)
{
    void *s;
    void *t;
    int u;
    int h;
    int g;
    int *r;
    int dx;
    int dz;
    int k;
    int e;
    int keys;
    int n;
    int a;
    int b;
    int c;
    int d;
    int rect[4];
    int cnt;
    Vec v;
    Vec w;

    s = func_02188CB4(q[1]);
    t = func_021A3074((void *)s);
    u = func_02188CD0(q[1]);
    h = func_02188C58(q[1]);

    switch (*state) {
    case 0:
        q[2] = func_0218E138(h);
        func_0218E13C(h, 0);
        *state = 1;
        break;
    case 1:
        func_0200616C(0x680, func_02006148(0x680));
        g = func_0218DC6C(func_02188C98(q[1]));
        rect[2] = q[5] - 0x20000;
        rect[3] = q[5] + 0x20000;
        rect[0] = q[7] - 0x20000;
        rect[1] = q[7] + 0x20000;
        r = func_0218C584(g, rect, 2, &cnt);
        if (*r != 0) {
            q[8] = func_0218C724(g, *r);
            func_0218C88C(q[8], 0, 0);
        } else {
            q[8] = 0;
        }
        func_020307B0(r);
        *state = 2;
        break;
    case 2:
        func_021A3038(s, &v);
        dx = (v.x >> 12) / 16 - (q[5] >> 12) / 16;
        dz = (v.z >> 12) / 16 - (q[7] >> 12) / 16;
        if (dx < 0)
            dx = -dx;
        if (dz < 0)
            dz = -dz;
        if (dx == 0 && dz == 0)
            k = 0;
        else if (dx < 2 && dz < 2)
            k = 0x3c;
        else
            k = 0x78;
        if (k > 0) {
            e = func_021C754C(q[1], k, &q[5]);
            func_021C6DE0(func_02188D38(q[1]), e, 0);
            *state = 3;
        } else {
            *state = 4;
        }
        q[3] = 0;
        break;
    case 3:
        if (q[8] != 0 && func_0218C8FC(q[8], 0) != 0)
            func_0218C88C(q[8], 0, 0);
        keys = func_0203630C();
        if (keys & 0x40)
            func_0216D410(t, 0x24);
        if (keys & 0x80)
            func_0216D410(t, 0x25);
        if (keys & 0x20)
            func_0216D410(t, 0x26);
        if (keys & 0x10)
            func_0216D410(t, 0x27);
        n = q[3];
        q[3] = n + 1;
        if (n % 10 == 0)
            func_021AC528(t, u);
        if (func_021C6E48(func_02188D38(q[1])) != 0)
            *state = 4;
        break;
    case 4:
        func_020061E4(0x7A0);
        func_0216D568(t, 0x8000);
        w.x = 0;
        w.y = -0x1E000;
        w.z = 0;
        a = func_021C7858(q[1], 0x22, &w);
        b = func_021C71D4(q[1], 0x22, 5);
        c = func_021C6F00(q[1], 0x1e, 0xB4000);
        e = func_021C7814(q[1], 3, 0, 0x10, 0);
        d = func_02188D38(q[1]);
        func_021C6DE0(d, a, 0);
        func_021C6DE0(d, b, 0);
        func_021C6DE0(d, c, 0);
        func_021C6DE0(d, e, c);
        q[3] = 0;
        *state = 5;
        break;
    case 5:
        if (func_021C6E48(func_02188D38(q[1])) != 0)
            *state = 6;
        break;
    case 6:
        func_020061F8(func_02006148(0x680));
        func_0218E13C(h, q[2]);
        if (q[8] != 0)
            func_0218C860(q[8]);
        return 1;
    }
    return 0;
}
