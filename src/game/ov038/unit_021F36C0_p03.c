/*
 * file:     unit_021F36C0_p03.c
 * unit:     yes
 * function: func_021F4200, func_021F42BC
 * address:  0x021F4200
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_0200B3A8 0x0200B3A8 thumb
 *   func_021BE700 0x021BE700 thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 *   func_021BE6CC 0x021BE6CC thumb ov021
 *   func_021BE4B4 0x021BE4B4 thumb ov021
 *   func_021BE480 0x021BE480 thumb ov021
 *   func_020061E4 0x020061E4 thumb
 *   d_021F4628    0x021F4628 data a1
 *   d_021F4632    0x021F4632 data a1
 */
struct Ctx;
struct Obj;
struct Big;
struct Rec94;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef signed char s8;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    u8 pad[0x20];
    int a[10];
    int b[10];
} Work;

extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern u8 *func_0200B3A8(struct Rec94 *p, u32 a1);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void *func_021BE674(char *base, int i, int j, u16 k);
extern void func_021BE6B0(unsigned char *p, int v);
extern int func_021BE6BC(int *p);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern int func_021BE480(char *p, unsigned i, int j);
extern void func_020061E4(u32 a);
int func_021F4200(int a0, int *a1);
int func_021F42BC(int a0, int *a1);
extern const s8 d_021F4628[];
extern const u8 d_021F4632[];


/*
 * note:     the case-0 byte must be held in a u8 (or u16) local: an int local
 *           swaps the 0x0201210C result and the 0x021897BC pointer between r4
 *           and r5.  func_020124E4/func_0201210C are argless as in the twin
 *           ov045_func_021F39B8.  func_021BE700/func_021BE674 take their
 *           fourth argument as u16 (the caller truncates it before the bl).
 *           func_021BE674's third parameter must be `int` here, as for
 *           func_021BE700: its own file's `unsigned int j` brings the r4/r5
 *           swap back even with the u8 local.
 */
int func_021F4200(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    int *p;
    unsigned int t;
    unsigned short *q;
    int i;
    u8 c;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC(sys, 1);
    t = (unsigned int)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys)));
    p = func_0200B3A4((struct Rec94 *)t, 6);
    q = (short unsigned int *)func_0200B3A8((struct Rec94 *)t, 6);
    switch (*a1) {
    case 0:
        c = *s;
        for (i = 0; i < 2; i++) {
            func_021BE700((void *)h, 0, c, (u16)i, 1);
            func_021BE6B0(func_021BE674((char *)h, 0, c, i), 0);
        }
        *a1 = *a1 + 1;
        break;
    case 1:
        if (func_021BE6BC(func_021BE674((char *)h, 0, *s, 0))) {
            p[*s] = 1;
            q[*s] = 1;
            return 1;
        }
        break;
    }
    return 0;
}


/*
 * note:     the work block's two int arrays are struct fields (index*4 then
 *           [#0x20]/[#0x48]); the flag test is `if (n != -1) { if (a[n])
 *           f = 1; } else f = 1;`, whose cross-jumped else arm gives the
 *           `beq SET ... beq SKIP; b SET` shape (an `||` or else-if does not).
 */
int func_021F42BC(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    Work *p;
    int i;
    int f;
    u8 c;
    u8 m;
    s8 n;
    Vec *v;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC((char *)sys, 1);
    p = (Work *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys))), 6);
    switch (*a1) {
    case 0:
        c = s[1] + 8;
        for (i = 0; i < 2; i++) {
            func_021BE700((void *)h, 0, c, (u16)i, 1);
            func_021BE6B0(func_021BE674((char *)h, 0, c, i), 0);
        }
        *a1 = *a1 + 1;
        break;
    case 1:
        f = 0;
        if (func_021BE6BC(func_021BE674((char *)h, 0, (u8)(s[1] + 8), 0))) {
            p->a[s[1]] = 1;
            n = d_021F4628[s[1]];
            if (n != -1) {
                if (p->a[n] != 0) {
                    f = 1;
                }
            } else {
                f = 1;
            }
            if (f) {
                m = d_021F4632[s[1]];
                if (p->b[m] == 0) {
                    s[4] = m;
                    c = m + 0x12;
                    func_021BE4B4((char *)h, 0, (u16)c, 1);
                    func_021BE4B4((char *)h, 0, (u16)0x21, 0);
                    v = (Vec *)func_021BE480((char *)h, 0, c);
                    *(Vec *)func_021BE480((char *)h, 0, 0x21) = *v;
                    for (i = 0; i < 4; i++) {
                        c = i + 4;
                        func_021BE700((void *)h, 0, 0x21, (u16)c, 1);
                        func_021BE6B0(func_021BE674((char *)h, 0, 0x21, c), 0);
                        func_021BE6CC((int)((void *)h), 0, 0x21, c, 0);
                    }
                    func_020061E4(0x6C8);
                    *a1 = *a1 + 1;
                    break;
                }
                return 1;
            }
            return 1;
        }
        break;
    case 2:
        if (func_021BE6BC(func_021BE674((char *)h, 0, 0x21, 4))) {
            for (i = 0; i < 4; i++) {
                func_021BE700((void *)h, 0, 0x21, (u16)((u8)(i + 4)), 0);
            }
            p->b[s[4]] = 1;
            m = s[4];
            func_021BE4B4((char *)h, 0, (u16)(m + 0x12), 1);
            func_021BE4B4((char *)h, 0, (u16)(m + 0x19), 0);
            func_021BE4B4((char *)h, 0, (u16)0x21, 1);
            func_020061E4(0x6DC);
            return 1;
        }
        break;
    }
    return 0;
}
