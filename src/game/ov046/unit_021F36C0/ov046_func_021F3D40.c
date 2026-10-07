/*
 * function: func_021F3D40
 * address:  0x021F3D40
 * packet:   pkt_ov046_021F3D40
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 *   func_020122C0  0x020122C0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_021F3DE8  0x021F3DE8  thumb  ov046
 *   func_021F3BC8  0x021F3BC8  thumb  ov046
 *   func_021F3BE8  0x021F3BE8  thumb  ov046
 *   func_021F4078  0x021F4078  thumb  ov046
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Q {
    int a0;
    int a4;
    int *a8;
    u8 c;
    u8 d;
    u8 e;
    u8 pad;
    int p10;
    int p14;
    int p18;
    int p1c;
    int p20;
} Q;

struct Big;
struct Ctx;
struct Desc;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *);
struct Evt;
extern int *func_021897BC(char *p, int idx);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021F3DE8(void *a, int *st);
extern int func_021F3BC8(int *);
extern int func_021F3BE8(int *, int);
extern void func_021F4078(u32, int, int);

int func_021F3D40(u32 a, int *b)
{
    void *h = func_020124E4((void *)a);
    void *x = func_0201210C(h);
    Q *q;
    int t;
    int y;

    func_02188D2C(x);
    q = (Q *)func_021897BC(x, 1);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    switch (*b) {
    case 0:
        t = func_021F3BC8(q->a8);
        y = func_021F3BE8(q->a8, t);
        q->c = q->a0 * 5;
        q->d = 1;
        q->p18 = y;
        q->e = 8;
        q->p1c = 0x6d4;
        q->p20 = 0x6d9;
        func_02012374((void *)a, (struct Evt **)func_020122C0(h, 0, func_021F3DE8, 0));
        q->a8[0] = t;
        (*b)++;
        break;
    case 1:
        func_021F4078((u32)x, q->a0, *q->a8);
        return 1;
    }
    return 0;
}
