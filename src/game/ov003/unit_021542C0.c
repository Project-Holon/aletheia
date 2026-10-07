/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: func_021542C0, func_0215437C
 * address:  0x021542C0
 * region:   ov003
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 */
struct Ctx;
struct IcaAnime;
struct Evt;
struct Desc;
struct Obj;
struct Comm;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

extern u32   func_02012138(const struct Ctx *a0);
extern u32 func_02026454(void *obj);
extern u16 func_02005C44(void);
extern void func_02005E30(u32 a);
extern int func_020144DC(int a0, int a1);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_020120F4(const struct Ctx *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void  func_02005D90(u32 a0, u32 a1);
extern void func_02005DF8(u32 a);
extern void *func_020145CC(void *a0);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void func_02026400(struct Comm *p);
void *func_020124E8(struct Obj *p);
u32 func_021542C0(void *obj, u32 *mode, u32 *args);
void *func_0215437C(void *p, int a, int b);


u32 func_021542C0(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[1];

    switch (*mode) {
    case 0:
        if (func_02026454((void *)func_02012138((const struct Ctx *)a0)) == 0) {
            args[0] = func_02005C44();
            func_02005E30(6);
            (*mode)++;
        }
        break;
    case 1:
        func_02012374(obj, (struct Evt **)func_020144DC(a0, args[2]));
        *mode = 2;
        break;
    case 2:
        args[3] = (u32)func_020120F4((const struct Ctx *)a0);
        args[4] = args[5];
        func_020120B4((struct IcaAnime *)a0, (u32)-1, (void *)0x0209DEFC, &args[3]);
        (*mode)++;
        break;
    case 3:
        if (func_020120F0((const struct Ctx *)a0) == 0)
            (*mode)++;
        break;
    case 4:
        (*mode)++;
        break;
    case 5:
        func_02005D90(args[0], 0xFFFF);
        func_02005DF8(0x3C);
        func_02012374(obj, func_020145CC((void *)a0));
        (*mode)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}


/*
 * Allocator + guard + three-field link setup.
 */
void *func_0215437C(void *p, int a, int b)
{
    void *r7 = func_020122C0(p, 0, func_021542C0, 0x1C);
    int *obj;

    if (func_02026454((void *)func_02012138(p)))
        func_02026400((struct Comm *)func_02012138(p));
    obj = func_020124E8(r7);
    obj[1] = (int)p;
    obj[2] = a;
    obj[5] = b;
    return r7;
}
