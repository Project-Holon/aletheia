/*
 * file:     unit_021F36C0_p04.c
 * unit:     yes
 * function: func_021F3EFC, func_021F3FA8, func_021F4020, func_021F4064, func_021F4078
 * address:  0x021F3EFC
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   d_021F4130  0x021F4130  data  a4
 *   func_021BE4B4  0x021BE4B4  thumb  ov203
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216DAC8 0x0216DAC8 thumb ov010
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB3DC  0x021BB3DC  thumb  ov021
 *   d_021F4430  0x021F4430  data  ov046  a4
 */
struct Big;
struct Ctx;
struct Obj;
struct Rec94;
struct Obj00020;
struct VecFx32;
struct Rec;
typedef unsigned int u32;

typedef unsigned char u8;

typedef signed int     s32;

typedef unsigned short u16;

extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *);
extern int *func_021897BC(char *, int);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void func_020061E4(u32 a);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern void func_021BE4B4(char *ctx, int b, int c, u32 d);
extern void *func_02188C7C(unsigned char *p);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern u16 func_0216D588(void *p);
extern void func_0216DAC8(u32 *,u32);
extern u32 func_02188C5C(u8 *p);
extern void func_021BB3DC(u32 *p, int b, int c);
int func_021F3EFC(u32 a, int *b);
void func_021F3FA8(char *a, u32 b, u32 c);
int func_021F4020(u32 a, int b);
void func_021F4064(u32 a,int b,u32 c);
void func_021F4078(u32 a, int b, int c);
extern int d_021F4130[];
extern int d_021F4430[][4][6];


/*
 * The ov046 token is dropped from d_021F4130 (contested hint).
 */
int func_021F3EFC(u32 a, int *b)
{
    void *x;
    int *w;
    int r = 1;
    void *c;
    int v[3];

    x = func_0201210C(func_020124E4((void *)a));
    func_02188D2C(x);
    w = func_021897BC(x, 1) + 3;
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    switch (*b) {
    case 0:
        func_020061E4(0x55e);
        (*b)++;
        break;
    case 1:
        c = func_02188CB4((void *)x);
        func_021A3038(c, (struct VecFx32 *)v);
        v[0] = v[0] + w[1];
        v[1] = w[2] + (d_021F4130[((u8 *)w)[3]] << 12);
        func_021A3044(c, v);
        ((u8 *)w)[3] = ((u8 *)w)[3] + 1;
        if (((u8 *)w)[3] >= 8) {
            func_020061E4(0x6d3);
            return r;
        }
        break;
    }
    return 0;
}


void func_021F3FA8(char *a, u32 b, u32 c)
{
    func_021BE4B4(a, 0, 15, c);
    func_021BE4B4(a, 0, 10, c);
    func_021BE4B4(a, 0, 11, c);
    func_021BE4B4(a, 0, 12, c);
    func_021BE4B4(a, 0, 13, c);
    func_021BE4B4(a, 0, 14, c);
    func_021F4064(b, 4, c);
    func_021F4064(b, 5, c);
    func_021F4064(b, 9, c);
    func_021F4064(b, 6, c);
}


int func_021F4020(u32 a, int b)
{
    int s1 = 0;
    int s0;
    void *it = func_02188C7C((void *)a);

    while (func_0216DD1C(it, (struct Rec **)(&s0), (u32 *)(&s1)) == 1) {
        if (b == func_0216D588((void *)s0))
            return s0;
    }
    return 0;
}

void func_021F4064(u32 a,int b,u32 c) { u32 *p; p=(u32 *)func_021F4020(a,b); if(p) func_0216DAC8(p,c); }


/*
 * The table row is indexed inside the loop; the compiler hoists the
 * invariant row address (b's register reused for it). A `t = d[b][c]`
 * local before the loop colours b and the counter apart.
 * func_021BB3DC is ov021's thunk (reads r0-r2); ov214's label at the same
 * address is a different two-argument function.
 */
void func_021F4078(u32 a, int b, int c)
{
    int v1[6];
    int v2[6];
    u32 h = func_02188C5C((u8 *)a);
    int i;

    for (i = 0; i < 6; i++) {
        v1[i] = d_021F4430[b][c][i];
        v2[i] = 0;
    }
    if (c != 1) {
        v2[0] = 1;
        v2[1] = 1;
    }
    for (i = 0; i < 6; i++)
        func_021BB3DC((u32 *)h, v1[i], v2[i]);
}
