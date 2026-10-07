/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: func_021542C0, func_021543E8
 * address:  0x021542C0
 * region:   ov002
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
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   ov199_id       0x000000C7  data   a1
 *   d_02213C4C     0x02213C4C  data   ov199  a4
 *   d_02154460     0x02154460  data   ov002  a4
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

typedef unsigned char  u8;

typedef unsigned short u16;

extern u32 func_02012138(const struct Ctx *p);
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
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void func_02026400(struct Comm *p);
void *func_020124E8(struct Obj *p);
u32 func_021542C0(void *obj, u32 *mode, u32 *args);
void *func_021543E8(void *p, int a1, int a2, int a3, int a4);
extern char ov199_id[];
extern char d_02213C4C[];
extern char d_02154460[];


u32 func_021542C0(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[1];
    u32 *p;

    switch (*mode) {
    case 0:
        if (func_02026454((void *)func_02012138((const struct Ctx *)a0)) == 0) {
            args[0] = func_02005C44();
            func_02005E30(6);
            (*mode)++;
        }
        break;
    case 1:
        if (args[7])
            func_02012374(obj, (struct Evt **)func_021BE8D4((void *)a0, args[2], 0, 0));
        (*mode)++;
        break;
    case 2:
        func_02012374(obj, (struct Evt **)func_020144DC(a0, args[2]));
        (*mode)++;
        break;
    case 3:
        p = func_02030734(4, 0x14, 1, d_02154460, 0x86);
        args[3] = (u32)p;
        p[2] = args[4];
        p[0] = (u32)func_020120F4((const struct Ctx *)a0);
        p[1] = args[6];
        p[3] = args[5];
        func_020120B4((struct IcaAnime *)a0, (u32)ov199_id, d_02213C4C, (void *)args[3]);
        (*mode)++;
        break;
    case 4:
        if (func_020120F0((const struct Ctx *)a0) == 0) {
            func_020307B0((void *)args[3]);
            (*mode)++;
        }
        break;
    case 5:
        (*mode)++;
        break;
    case 6:
        func_02012374(obj, func_020145CC((void *)a0));
        func_02005D90(args[0], 0xFFFF);
        func_02005DF8(0x3C);
        (*mode)++;
        break;
    case 7:
        if (args[7])
            func_02012374(obj, (struct Evt **)func_021BE92C((void *)a0, args[2], 0, 0, 1, 0, 0));
        (*mode)++;
        break;
    case 8:
        return 1;
    }
    return 0;
}


/*
 * Allocator + guard + link setup, stores five constructor arguments.
 */
void *func_021543E8(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_021542C0, 0x20);
    int *obj;

    if (func_02026454((void *)func_02012138(p)))
        func_02026400((struct Comm *)func_02012138(p));
    obj = func_020124E8(r0v);
    obj[1] = (int)p;
    obj[2] = a1;
    obj[4] = (u16)a2;
    obj[5] = a3;
    obj[6] = a4;
    obj[7] = 0;
    return r0v;
}
