/*
 * function: func_021C7730
 * address:  0x021C7730
 * packet:   pkt_ov021_021C7730
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   _ffltu         0x0209BE04  arm
 *   func_021C76C4  0x021C76C4  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    u8    st;
    u32   w4;
    u16   h8;
    u16   ha;
    float fc;
    u32   w10;
} Fx;

extern void *func_02188CB4(unsigned char *p);
extern int func_02188CD0(u32 a);
extern void func_021C76C4(Vec *out, float a, float b, float c);
extern void func_0216D8C0(u32 a, Vec *v);
extern void func_021AC528(u32 a, u32 b);
extern void func_020061E4(u32 a);

int func_021C7730(Fx *o)
{
    Vec v;
    u32 s;

    func_02188CB4((unsigned char *)o->w4);
    s = o->w10;
    switch (o->st) {
    case 0:
        func_021C76C4(&v, (float)(u32)o->h8, (float)(u32)o->ha, o->fc);
        func_0216D8C0(s, &v);
        func_020061E4(0x681);
        o->st = o->st + 1;
        break;
    case 1:
        o->h8 = o->h8 + 1;
        func_021C76C4(&v, (float)(u32)o->h8, (float)(u32)o->ha, o->fc);
        func_0216D8C0(s, &v);
        if (o->ha <= o->h8) {
            func_021AC528(s, func_02188CD0(o->w4));
            func_020061E4(0x682);
            return 1;
        }
        break;
    }
    return 0;
}
