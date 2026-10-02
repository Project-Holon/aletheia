/*
 * function: func_021F3734
 * address:  0x021F3734
 * packet:   pkt_ov056_021F3734
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five-step init/run/teardown state machine for the ov056 work block.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   func_021BBA6C  0x021BBA6C  thumb  ov021
 *   func_021BBA1C  0x021BBA1C  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_021F3B10  0x021F3B10  thumb  ov056
 *   func_021F392C  0x021F392C  thumb  ov056
 *   func_021F3D60  0x021F3D60  thumb  ov056
 *   func_021F3890  0x021F3890  thumb  ov056
 *   func_021F3BF0  0x021F3BF0  thumb  ov056
 *   func_021F3CC4  0x021F3CC4  thumb  ov056
 *   func_021F3904  0x021F3904  thumb  ov056
 *   func_021F3A78  0x021F3A78  thumb  ov056
 *   func_021F3C84  0x021F3C84  thumb  ov056
 *   func_021F3DB8  0x021F3DB8  thumb  ov056
 *   func_021F3918  0x021F3918  thumb  ov056
 *   func_021F3C4C  0x021F3C4C  thumb  ov056
 *   func_021F3D9C  0x021F3D9C  thumb  ov056
 *   func_021F3A14  0x021F3A14  thumb  ov056
 *   func_021F38D4  0x021F38D4  thumb  ov056
 *   d_021F42C0     0x021F42C0  data  a4
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct Work {
    int f0;
    int f4;
    int idx;
    u8 cam[0x30];
    u8 obj[0x80];
    u8 f_bc[0xc];
    u8 f_c8[4];
    u32 task;
    void *fd0;
} Work;

extern int func_02188C84(int a);
extern void *func_02188CB4(unsigned char *p);
extern int func_02188C58(int a);
extern int func_02188C98(int a);
extern u32 func_02188D24(int a);
extern void func_0218F0A8(int a);
extern int func_0218F0E8(int a);
extern int func_0218DC6C(int a);
extern u32 func_021BB990(int a, u32 b, const void *c);
extern void **func_021BBA6C(u32 a);
extern void func_021BBA1C(u32 a);
extern int func_020120F4(int a);
extern int func_02012944(int a);
extern void func_02030EAC(void *p);
extern void func_021F3B10(void *o, void *a1, int a2, int a3, int idx);
extern void func_021F392C(void *o, int a1, int heap, int idx);
extern void func_021F3D60(void *o, int idx, int heap);
extern void func_021F3890(void *o, int a, int idx);
extern void func_021F3BF0(void *o);
extern void func_021F3CC4(void *o, int flag);
extern void func_021F3904(void *o);
extern int func_021F3A78(void *o);
extern int func_021F3C84(void *o);
extern int func_021F3DB8(void *o);
extern int func_021F3918(void *o);
extern void func_021F3C4C(void *o);
extern void func_021F3D9C(void *o);
extern void func_021F3A14(void *o);
extern void func_021F38D4(void *o);

extern const u8 d_021F42C0[];

int func_021F3734(void *a0, int *state, Work *p)
{
    int heap;
    int h;
    int a;
    int b;
    int c;

    heap = func_02188C84(p->f0);
    switch (*state) {
    case 0:
        h = func_02012944(func_020120F4(p->f4));
        func_021F3B10(p->obj, func_02188CB4((void *)p->f0), h, heap, p->idx);
        (*state)++;
        break;
    case 1:
        func_0218F0A8(func_02188C58(p->f0));
        (*state)++;
        break;
    case 2:
        h = func_02188C58(p->f0);
        if (func_0218F0E8(h) != 0) {
            break;
        }
        func_021F392C(p->cam, h, heap, p->idx);
        func_021F3D60(p->f_c8, p->idx, heap);
        func_021F3890(p->f_bc, func_0218DC6C(func_02188C98(p->f0)), p->idx);
        func_021F3BF0(p->obj);
        p->task = func_021BB990(-1, func_02188D24(p->f0), d_021F42C0);
        *func_021BBA6C(p->task) = p->obj;
        func_021F3CC4(p->obj, 1);
        func_021F3904(p->f_bc);
        (*state)++;
        break;
    case 3:
        a = func_021F3A78(p->cam);
        func_021F3C84(p->obj);
        b = func_021F3DB8(p->f_c8);
        c = func_021F3918(p->f_bc);
        if (a && c && b) {
            (*state)++;
        }
        break;
    case 4:
        func_021F3CC4(p->obj, 0);
        func_021BBA1C(p->task);
        func_02030EAC(p->fd0);
        func_021F3C4C(p->obj);
        func_021F3D9C(p->f_c8);
        func_021F3A14(p->cam);
        func_021F38D4(p->f_bc);
        return 1;
    }
    return 0;
}
