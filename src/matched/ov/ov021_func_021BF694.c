/*
 * function: func_021BF694
 * address:  0x021BF694
 * packet:   pkt_ov021_021BF694
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021C7684  0x021C7684  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   d_021DA080     0x021DA080  data   a4
 */

typedef struct { int x, y, z; } Vec;

extern const Vec d_021DA080;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
extern void *func_02188C58(void *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_02188D38(u8 *p);
extern void *func_021A3074(unsigned char *p);
extern u32 func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);
extern void func_0216D8C0(void *, Vec *);
typedef unsigned short u16;
extern void func_0216D410(void *a0, u16 a1);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_021C7684(u32 a, u32 b, int c, int d);
extern void func_021C6DE0(u8 *p, u32 *a, u32 b);
extern int func_021C6E48(int);

int func_021BF694(int a, int *s, int *q)
{
    int h = (int)func_02188C58((void *)q[1]);
    Vec rot;
    void *t;
    int r;

    switch (s[0]) {
    case 0:
        q[2] = func_0218E138((u8 *)h);
        func_0218E13C((u8 *)h, 0);
        rot = d_021DA080;
        t = func_021A3074(func_02188CB4((struct Obj00020 *)q[1]));
        func_0216D8C0(t, &rot);
        func_0216D410(t, 1);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)q[0], q[1], 0, 1, 1, 0, 0));
        r = (int)func_021C7684(q[1], (u32)func_021A3074(func_02188CB4((struct Obj00020 *)q[1])), 0x28, 0xfa);
        func_021C6DE0((u8 *)func_02188D38((u8 *)q[1]), (u32 *)r, 0);
        s[0] = s[0] + 1;
        break;
    case 1:
        if (func_021C6E48(func_02188D38((u8 *)q[1])) != 0)
            s[0] = s[0] + 1;
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
