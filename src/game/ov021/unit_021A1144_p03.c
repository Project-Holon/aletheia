/*
 * file:     unit_021A1144_p03.c
 * unit:     yes
 * function: func_021A12D4, func_021A1358, func_021A136C, func_021A1388, func_021A139C, func_021A13C0, func_021A13E4
 * address:  0x021A12D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049658  0x02049658  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D3270  0x021D3270  thumb  ov021
 *   func_021D3244  0x021D3244  thumb  ov021
 *   func_02034AC4  0x02034AC4  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021EFEC0  0x021EFEC0  thumb  ov031
 *   abs_id_1f      0x0000001F  data
 *   func_021EFFE8  0x021EFFE8  thumb  ov031
 *   func_02034A5C  0x02034A5C  arm
 *   func_0217394C  0x0217394C  thumb  ov012
 *   func_021F0054  0x021F0054  thumb  ov031
 *   func_021F00D4  0x021F00D4  thumb  ov031
 *   func_0217CFE4  0x0217CFE4  thumb  ov018
 */
struct St021D3244;
struct Ctx;
struct Obj;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef signed short   s16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049BDC(void *h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u32 heap);
extern void func_02049658(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 heap);
extern void func_02049990(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 heap);
extern void func_02049238(void *h);
extern u32 func_02188E30(u8 *p);
extern void func_021D3270(u32 a, int b, int c, int d, int e, int f);
extern void func_021D3244(struct St021D3244 *p, int i, u8 v);
extern int func_02034AC4(int);
extern void *func_02188C80(void *p);
extern u32 *func_021EFEC0(void *a);
extern void func_021EFFE8(u32 *p);
extern void func_02034A5C(int handle);
extern int func_0217394C(const struct Ctx *p);
extern void func_021F0054(struct Obj *p, int mode);
extern void func_021F00D4(char *p, int mode);
extern u8 *func_0217CFE4(void *a);
void func_021A12D4(u32 *p, u32 x);
u32 func_021A1358(u32 *p);
void func_021A136C(u32 *p);
void func_021A1388(u32 *p);
void func_021A139C(u32 *p, u32 a);
void func_021A13C0(u32 *p, u32 a);
void ov021_func_021A13E4(u32 *p);
extern unsigned char abs_id_1f[];


/*
 * Lever: func_020490F4 takes (id, heap); passing x as its second argument
 * is what gives x its register before the constant's.
 */
void func_021A12D4(u32 *p, u32 x)
{
    void *h = func_020490F4(0x47, x);
    func_02049BDC(h, 0, 0, 0x140, 0x140, 0x20, x);
    func_02049658(h, 3, 1, 0x64, 0, 0, x);
    func_02049990(h, 0xf, 1, 0, 0x64, 0, 0, x);
    func_02049238(h);
    func_021D3270(func_02188E30((u8 *)p[5]), 1, 0, 0, 0, -6);
    func_021D3244((struct St021D3244 *)func_02188E30((u8 *)p[5]), 1, 1);
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021A1358(u32 *p)
{
    if (p[0] == 0 || p[0] == 8)
        return p[8];
    return 0;
}


void func_021A136C(u32 *p)
{
    func_02034AC4((int)abs_id_1f);
    p[8] = (u32)func_021EFEC0(func_02188C80((void *)p[5]));
}


void func_021A1388(u32 *p)
{
    func_021EFFE8((u32 *)p[8]);
    func_02034A5C((int)abs_id_1f);
}


void func_021A139C(u32 *p, u32 a)
{
    u32 h = (u32)func_02188C80((void *)p[5]);
    if (a == 1 && func_0217394C((const struct Ctx *)h) == 0)
        a = 0;
    func_021F0054((struct Obj *)p[8], a);
}


void func_021A13C0(u32 *p, u32 a)
{
    u32 h = (u32)func_02188C80((void *)p[5]);
    if (a == 1 && func_0217394C((const struct Ctx *)h) == 0)
        a = 0;
    func_021F00D4((char *)p[8], a);
}


void ov021_func_021A13E4(u32 *p)
{
    p[8] = (u32)func_0217CFE4(func_02188C80((void *)p[5]));
}
