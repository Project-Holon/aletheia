/*
 * function: func_0215FC40
 * address:  0x0215FC40
 * packet:   pkt_ov010_0215FC40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0215FD0C  0x0215FD0C  thumb  ov010
 *   func_0215FED4  0x0215FED4  thumb  ov010
 *   func_0215FEF0  0x0215FEF0  thumb  ov010
 *   func_0215FEF4  0x0215FEF4  thumb  ov010
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 *   func_020355D8  0x020355D8  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;
extern u32 func_02188CCC(u8 *p);
struct Desc;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC();
struct Ctx;
extern int func_0215FD0C(void *task, void *unused, struct Ctx *c);
extern int func_0215FED4(void *a0, void *a1);
extern int func_0215FEF0(void);
extern int func_0215FEF4(u32 *a0, u32 *a1);
extern u32 func_021A0F90(u8 *p);
extern int func_021A0EE4();
extern void func_020355D8(u8 v);

/* the 0x5C-byte record behind the descriptor */
struct Rec {
    u16          id;     /* 0x00 */
    struct Desc *desc;   /* 0x04 */
    int          owner;  /* 0x08 */
    int          field;  /* 0x0C */
    u32          f10;
    u32          f14;
    int          f18;
    int          owner2; /* 0x1C */
    int          field2; /* 0x20 */
    struct Desc *desc2;  /* 0x24 */
    u32          f28;
    int          f2C;
    void        *fn30;
    void        *fn34;
    void        *fn38;
    void        *self;   /* 0x3C */
    u8           pad40[0x5C - 0x40];
};

struct Desc *func_0215FC40(int a0, int a1, u16 a2)
{
    int x;
    int sz = 0x5c;
    struct Desc *r7;
    struct Rec *p;
    int r;

    x = func_02188CCC((u8 *)a1);
    r7 = func_020122C0((void *)a0, 0, (void *)func_0215FD0C, sz);
    p = (struct Rec *)func_020124E8((struct Obj *)r7);
    func_02082BCC(p, 0, sz);
    p->owner = a0;
    p->desc = r7;
    p->field = a1;
    p->id = a2;
    p->f14 = 0;
    p->owner2 = a0;
    p->field2 = a1;
    p->desc2 = r7;
    p->fn30 = (void *)func_0215FED4;
    p->fn34 = (void *)func_0215FEF0;
    p->fn38 = (void *)func_0215FEF4;
    p->self = p;
    p->f2C = sz - 0x5d;
    r = func_021A0F90((u8 *)x);
    switch (r) {
    case 3:
        r = 3;
        break;
    case 4:
        r = 4;
        break;
    default:
        r = func_021A0EE4(func_02188CCC((u8 *)p->field), 0);
        break;
    }
    p->f18 = r;
    func_020355D8(1);
    return r7;
}
