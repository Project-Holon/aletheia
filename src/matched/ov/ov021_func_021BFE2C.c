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

struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
typedef unsigned char  u8;
extern unsigned int func_02188CD0(u8 *p);
extern void *func_02188C58(void *p);
extern unsigned int func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, unsigned int s);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_02006148(u32 a0);
extern void func_0200616C(void *arg, int i);
extern u32 func_02188C98(u8 *p);
extern u32 func_0218DC6C(u8 *p);
extern int *func_0218C584(int, int *, int, int *);
extern u8 *func_0218C724(u8 *owner, u32 *obj);
extern void func_0218C88C(unsigned char *p, int v, int c);
extern u32 func_020307B0(void *p);
struct VecFx32;
extern void func_021A3038(unsigned char *, struct VecFx32 *);
extern int func_021C754C(int, int, int *);
extern u32 func_02188D38(u8 *p);
extern void func_021C6DE0(u8 *p, u32 *a, u32 b);
extern int func_0218C8FC(unsigned char *p, int i);
extern unsigned int func_0203630C(void);
extern void func_0216D410(void *a0, u16 a1);
extern void func_021AC528(u32 a, u32 b);
extern int func_021C6E48(int);
extern void func_020061E4(u32 a);
extern void func_0216D568(void *p, u32 v);
extern int func_021C7858(u32 a, u32 b, u32 c);
extern void *func_021C71D4(u32 a, u32 b, u32 c);
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

    s = func_02188CB4((struct Obj00020 *)q[1]);
    t = func_021A3074((void *)s);
    u = func_02188CD0((u8 *)q[1]);
    h = (int)func_02188C58((void *)q[1]);

    switch (*state) {
    case 0:
        q[2] = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        *state = 1;
        break;
    case 1:
        func_0200616C((void *)0x680, func_02006148(0x680));
        g = func_0218DC6C((u8 *)func_02188C98((u8 *)q[1]));
        rect[2] = q[5] - 0x20000;
        rect[3] = q[5] + 0x20000;
        rect[0] = q[7] - 0x20000;
        rect[1] = q[7] + 0x20000;
        r = func_0218C584(g, rect, 2, &cnt);
        if (*r != 0) {
            q[8] = (int)func_0218C724((u8 *)g, (u32 *)(*r));
            func_0218C88C((unsigned char *)q[8], 0, 0);
        } else {
            q[8] = 0;
        }
        func_020307B0(r);
        *state = 2;
        break;
    case 2:
        func_021A3038(s, (struct VecFx32 *)&v);
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
            func_021C6DE0((u8 *)func_02188D38((u8 *)q[1]), (u32 *)e, 0);
            *state = 3;
        } else {
            *state = 4;
        }
        q[3] = 0;
        break;
    case 3:
        if (q[8] != 0 && func_0218C8FC((unsigned char *)q[8], 0) != 0)
            func_0218C88C((unsigned char *)q[8], 0, 0);
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
            func_021AC528((u32)t, u);
        if (func_021C6E48(func_02188D38((u8 *)q[1])) != 0)
            *state = 4;
        break;
    case 4:
        func_020061E4(0x7A0);
        func_0216D568(t, 0x8000);
        w.x = 0;
        w.y = -0x1E000;
        w.z = 0;
        a = func_021C7858(q[1], 0x22, (u32)(&w));
        b = (int)func_021C71D4(q[1], 0x22, 5);
        c = func_021C6F00(q[1], 0x1e, 0xB4000);
        e = func_021C7814(q[1], 3, 0, 0x10, 0);
        d = func_02188D38((u8 *)q[1]);
        func_021C6DE0((u8 *)d, (u32 *)a, 0);
        func_021C6DE0((u8 *)d, (u32 *)b, 0);
        func_021C6DE0((u8 *)d, (u32 *)c, 0);
        func_021C6DE0((u8 *)d, (u32 *)e, c);
        q[3] = 0;
        *state = 5;
        break;
    case 5:
        if (func_021C6E48(func_02188D38((u8 *)q[1])) != 0)
            *state = 6;
        break;
    case 6:
        func_020061F8(func_02006148(0x680));
        func_0218E13C((u8 *)h, q[2]);
        if (q[8] != 0)
            func_0218C860(q[8]);
        return 1;
    }
    return 0;
}
