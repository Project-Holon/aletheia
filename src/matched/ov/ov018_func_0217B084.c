/*
 * function: func_0217B084
 * address:  0x0217B084
 * packet:   pkt_ov018_0217B084
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02190788  0x02190788  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02045C04  0x02045C04  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    unsigned char *f0;
    int f4;
    int f8;
    int fc;
    int f10;
    u16 f14;
} Obj;

typedef unsigned char  u8;
extern int func_0216D3CC(int a0);
extern int func_0216D5F8();
extern void func_0216D410();
extern int func_0216D454();
extern void func_0216D480();
extern void func_0216D9A0(void *map);
extern void func_0216D9E4(void *c);
extern void *func_02188C7C(unsigned char *p);
extern u32 func_02188C54(u8 *p);
extern int func_021904B0(u32 a, u32 b);
extern int func_021907A8();
extern int func_0219077C();
extern void func_02190788();
extern int func_02190740(u32 a, u32 b, u32 c, u32 d);
extern int func_02190728(u32 a);
extern u32 func_020362DC(void);
extern void func_02045C04();

int func_0217B084(int a0, int *state, Obj *o)
{
    u16 m;
    int t;
    int h;

    switch (*state) {
    case 0:
        if (func_0216D3CC(o->f4) == 1) {
            if (o->f14 == 3)
                t = 3;
            else
                t = 2;
            m = t;
            if (o->f14 != func_0216D5F8(o->f4)) {
                func_0216D410(o->f4, m);
                *state += 1;
            } else {
                *state = 2;
            }
        }
        break;
    case 1:
        if (func_0216D454(o->f4) == 1) {
            func_0216D480(o->f4);
            *state += 1;
        }
        break;
    case 2:
        func_0216D9A0(func_02188C7C(o->f0));
        h = func_02188C54(o->f0);
        o->f8 = func_021904B0(h, 0x2D);
        o->fc = func_021907A8(h, o->f8);
        func_02190740(o->fc, 0, 0, o->f10 == 0 ? 0x52 : 0x4F);
        *state += 1;
        break;
    case 3:
        if (func_0219077C(o->fc) == 1)
            *state += 1;
        break;
    case 4:
        if (o->f10 == 0) {
            if (func_020362DC() & 3)
                *state += 1;
        } else {
            if (func_020362DC() & 0xF3)
                *state = 8;
        }
        break;
    case 5:
        func_02190788(o->fc);
        func_02190740(o->fc, 0, 0, 0x53);
        *state += 1;
        break;
    case 6:
        if (func_0219077C(o->fc) == 1)
            *state += 1;
        break;
    case 7:
        if (func_020362DC() & 0xF3)
            *state += 1;
        break;
    case 8:
        func_02190728(o->fc);
        func_02045C04(o->f8);
        *state += 1;
        break;
    case 9:
        if (func_0216D3CC(o->f4) == 1) {
            func_0216D410(o->f4, (u16)(o->f14 == 3 ? 10 : 11));
            *state += 1;
        }
        break;
    case 10:
        if (func_0216D454(o->f4) == 1) {
            func_0216D480(o->f4);
            func_0216D9E4(func_02188C7C(o->f0));
            return 1;
        }
        break;
    }
    return 0;
}
