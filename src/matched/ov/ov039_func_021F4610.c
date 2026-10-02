/*
 * function: func_021F4610
 * address:  0x021F4610
 * packet:   pkt_ov039_021F4610
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02158780 0x02158780 thumb ov010
 *   func_021587B0 0x021587B0 thumb ov010
 *   func_021F3E04 0x021F3E04 thumb ov039
 *   func_021F3DE4 0x021F3DE4 thumb ov039
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 *   func_020061E4 0x020061E4 thumb
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 sel;
    u8 pad5[3];
    int timer[4];
    u8 pad18[0x21F0 - 0x18];
    s8 slot[4];
} Work;

extern void *func_020124E4(void *p);
extern void *func_0201210C(void *p);
extern int func_02188D2C(void *p);
extern Work *func_021897BC(void *p, int idx);
extern void *func_021BE674(char *base, int i, int j, u16 k);
extern u32 func_02188C80(void *p);
extern unsigned int func_020120F4(unsigned int);
extern unsigned int func_02012EC4(unsigned int);
extern void *func_0200B3A4(unsigned int, unsigned int);
extern void *func_02158780(void *a, u32 id, u32 b, u32 c, u32 d);
extern void func_021587B0(void *a, u32 id, u32 b, u32 c);
extern void func_021F3E04(void *a, u8 b, u8 c, int d);
extern int func_021F3DE4(void *a, u8 b, u8 c);
extern int func_021BE6B0(void *s, int b);
extern int func_021BE6BC(void *p);
extern void func_020061E4(u32 a);

int func_021F4610(void *a0, int *a1)
{
    void *sys;
    int h;
    Work *s;
    int c;
    u8 j;
    void *o;

    sys = func_0201210C(func_020124E4(a0));
    h = func_02188D2C(sys);
    s = func_021897BC(sys, 1);
    c = (u8)(s->sel >> 1);
    j = c;
    o = func_021BE674((char *)h, 0, j, 0);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(sys))), 2);
    switch (*a1) {
    case 0:
        func_02158780(a0, 0xF, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 1:
        func_021F3E04((void *)h, j, 0, 0);
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 2:
        if (func_021F3DE4((void *)h, j, 0) < 0xF000) {
            break;
        }
        func_021BE6B0(o, 1);
        func_02158780(a0, 7, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 3:
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 4:
        if (func_021BE6BC(o) == 0) {
            break;
        }
        func_021BE6B0(o, 1);
        func_021BE6B0(func_021BE674((char *)h, 0, j, (u8)(s->sel + 1)), 0);
        s->timer[c] = 0;
        s->slot[c] = -1;
        s->sel = 0xff;
        func_021587B0(a0, 8, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 5:
        return 1;
    }
    return 0;
}
