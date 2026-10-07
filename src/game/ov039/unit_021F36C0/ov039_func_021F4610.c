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

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern Work *func_021897BC(void *p, int idx);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern u32 func_02188C80(void *p);
struct Big;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern int func_021587B0(int a0, int a1, int a2, int a3);
extern void func_021F3E04(void *p, u8 delta, u16 i, int frame);
extern int func_021F3DE4(void *p, u16 delta, u16 i);
extern void func_021BE6B0(unsigned char *p, int v);
extern int func_021BE6BC(int *p);
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
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys))), 2);
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
        func_021587B0((int)a0, 8, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 5:
        return 1;
    }
    return 0;
}
