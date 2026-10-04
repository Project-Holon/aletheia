/*
 * function: func_021F44C0
 * address:  0x021F44C0
 * packet:   pkt_ov038_021F44C0
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: The handed extent includes rodata after 0x021F45E8.
 *         0200B3A4 receives the visibly loaded second argument 6.
 *         Enum id plus u16 extern arguments preserves the observed #16
 *         truncations at 021F4594/459A and 021F45C4/45CA; u16 local alone
 *         folds them away. Matched callee's wide id receives the same bits.
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021BE700 0x021BE700 thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_021BE6CC 0x021BE6CC thumb ov021
 *   func_021BE480 0x021BE480 thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 *   func_02158780 0x02158780 thumb ov010
 *   func_021587B0 0x021587B0 thumb ov010
 *   d_021F465C 0x021F465C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { ID_ZERO } Id;
typedef struct { int x, y, z; } V3;
struct Big;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int i);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int *func_0200B3A4(void *p, int i);
extern void func_021BE700(void *p, int i, int j, u16 k, int flag);
extern void *func_021BE674(char *p, int i, unsigned int j, u16 k);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6CC(int p, int i, int j, u16 k, int v);
extern V3 *func_021BE480(void *p, int i, u16 j);
extern int func_021BE6BC(int *p);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern int func_021587B0(void *p, u16 b, int c, int d);
extern const V3 d_021F465C[];

int func_021F44C0(void *a, int *state)
{
    void *sys;
    void *h;
    u8 *s;
    int i;
    Id id;

    sys = (void *)func_0201210C(func_020124E4(a));
    h = (void *)func_02188D2C(sys);
    s = (u8 *)func_021897BC(sys, 1);
    func_0200B3A4(func_02012EC4(func_020120F4((void *)func_02188C80(sys))), 6);
    switch (*state) {
    case 0:
        for (i = 0; i < 2; i++) {
            func_021BE700(h, 0, 0x20, i, 1);
            func_021BE6B0(func_021BE674(h, 0, 0x20, i), 0);
            func_021BE6CC((int)h, 0, 0x20, i, 0);
        }
        *func_021BE480(h, 0, 0x20) = d_021F465C[s[2]];
        *state = *state + 1;
        break;
    case 1:
        id = 4;
        if (s[2] == 0)
            id = 3;
        func_02158780(a, id, 0, 0, 0x8015);
        *state = *state + 1;
        break;
    case 2:
        if (func_021BE6BC(func_021BE674(h, 0, 0x20, 0))) {
            id = 6;
            if (s[2] == 0)
                id = 5;
            func_021587B0(a, id, 0, 0x8015);
            *state = *state + 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
