/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov057_021F36C0
 * region:   ov057
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resource setup; ov057_func_021F37BC is its teardown over the same arrays.
 * The second loop is an if/else with the call written in each arm (the
 * shared p->res[t] load is hoisted above the beq and the calls cross-jump);
 * a ternary third argument reloads in each arm. The four index tables
 * resolve as sole-ref only with the ov057 token dropped.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_02046E24  0x02046E24  arm
 *   func_02046F50  0x02046F50  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02046BE0  0x02046BE0  arm
 *   func_02049238  0x02049238  arm
 *   d_021F38A8     0x021F38A8  data  a4
 *   d_021F387C     0x021F387C  data  a4
 *   d_021F3888     0x021F3888  data  a4
 *   d_021F3898     0x021F3898  data  a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Res {
    u32 res[7];
    u32 tex[3];
    u32 anm[4];
    u32 obj[3];
} Res;

extern int func_02188C84(int a);
extern int func_020490F4(int, u16);
extern u32 func_02046E24(u32 a0, u32 a1);
extern int func_02046F50(u32, int);
extern void func_02046FF8(u32);
extern u32 func_02047400(u32 a, u32 b, u32 c);
extern u32 func_02047564(u32 a, u32 b, u32 c);
extern u32 func_0204767C(u32 a, u32 *b, u32 c);
extern void func_020477A4(u32 h, u16 i);
extern void func_02046BE0(u32 a, u32 b);
extern void func_02049238(int);

extern const u32 d_021F38A8[];
extern const u32 d_021F387C[];
extern const u32 d_021F3888[];
extern const u32 d_021F3898[];

void func_021F36C0(int a, int b, Res *p)
{
    int h;
    int i;
    u32 t;

    h = func_020490F4(0xbe, (func_02188C84(b) & 0x7fff) | 0x8000);
    for (i = 0; i < 7; i++) {
        if (func_02046F50(p->res[i] = func_02046E24(h, d_021F38A8[i]), 2)) {
            func_02046FF8(p->res[i]);
        }
    }
    for (i = 0; i < 3; i++) {
        t = d_021F387C[i];
        if (func_02046F50(p->res[t], 2)) {
            p->tex[i] = func_02047400(p->res[t], 0, p->res[t]);
        } else {
            p->tex[i] = func_02047400(p->res[t], 0, 0);
        }
    }
    for (i = 0; i < 4; i++) {
        p->anm[i] = func_02047564(p->tex[d_021F3888[i]], p->res[d_021F3898[i]], 0);
    }
    for (i = 0; i < 3; i++) {
        p->obj[i] = func_0204767C(p->tex[i], p->anm, 4);
    }
    func_020477A4(p->obj[0], 0);
    func_020477A4(p->obj[0], 3);
    func_020477A4(p->obj[1], 1);
    func_020477A4(p->obj[2], 2);
    func_02046BE0(1, 1);
    func_02049238(h);
}
