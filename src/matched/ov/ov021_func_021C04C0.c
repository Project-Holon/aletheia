/*
 * function: func_021C04C0
 * address:  0x021C04C0
 * packet:   pkt_ov021_021C04C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 */

typedef struct { int x, y, z; } Vec;

extern void *func_02188CB4(unsigned char *p);
extern void *func_02188C58(void *p);
typedef unsigned char  u8;
extern unsigned int func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, unsigned int s);
extern void *func_021C71D4(unsigned int a, unsigned int b, unsigned int c);
extern int func_021C7814(int, int, int, int, int);
extern int func_021C7858(unsigned int a, unsigned int b, unsigned int c);
extern unsigned int func_02188D38(u8 *p);
extern void func_021C6DE0(u8 *p, unsigned int a, unsigned int b);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern int func_021C6E48(int);
extern int func_0204E804(void);

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
        func_021C6DE0((u8 *)d, w, 0);
        func_021C6DE0((u8 *)d, x, 0);
        func_021C6DE0((u8 *)d, e, x);
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
