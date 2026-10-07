/*
 * file:     unit_021B95A0_p07.c
 * unit:     yes
 * function: func_021B9E08, func_021B9E0C, func_021B9E50, func_021B9EA0
 * address:  0x021B9E08
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02049B40  0x02049B40  arm
 *   func_02040EBC  0x02040EBC  arm
 *   func_02049624  0x02049624  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   sub_0204A8D4  0x0204A8D4  arm
 *   sub_0204ADA4  0x0204ADA4  arm
 *   sub_0204AFD8  0x0204AFD8  arm
 */
typedef unsigned int u32_021B9E0C;

typedef unsigned short u16;

typedef unsigned int u32_021B9E50;

typedef struct {
    char pad[8];
    int f8;
    int fc;
    int f10;
} Obj;

typedef signed int     s32_021B9E50;

typedef unsigned char  u8;

typedef unsigned long  u32_021B9EA0;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32_021B9EA0;

typedef int BOOL;

typedef struct {
    char pad[8];
    void *f08;
    void *f0C;
    void *f10;
} S;

extern void func_02049B40(u32_021B9E0C a, u32_021B9E0C b, u32_021B9E0C c, u32_021B9E0C d, u32_021B9E0C e, u16 f);
extern void func_02040EBC(u32_021B9E0C a, u32_021B9E0C b);
extern u32_021B9E0C func_02049624(void *a0, void *a1, void *a2, void *a3, u32_021B9E0C a4, u32_021B9E0C a5, u16 a6);
extern s32_021B9E50 func_0204A6C8(void *a, u32_021B9E50 b, u32_021B9E50 c, u32_021B9E50 a3, u16 flags);
extern s32_021B9E50 func_0204AC18(void *a, u32_021B9E50 b, u32_021B9E50 c, u32_021B9E50 d, u16 e, u16 f, u16 g);
extern s32_021B9E50 func_0204AF28(void *owner, u32_021B9E50 first, u32_021B9E50 second, u32_021B9E50 mode);
extern void sub_0204A8D4(u32_021B9EA0 i);
extern void sub_0204ADA4(u32_021B9EA0 i);
extern void sub_0204AFD8(u32_021B9EA0 i);
void func_021B9E08(int a0);
void func_021B9E0C(void *a, u32_021B9E0C b, u32_021B9E0C c, u32_021B9E0C d);
void func_021B9E50(Obj *o, int a, u32_021B9E50 c);
void func_021B9EA0(S *s);

void func_021B9E08(int a0)
{
}


void func_021B9E0C(void *a, u32_021B9E0C b, u32_021B9E0C c, u32_021B9E0C d)
{
    u32_021B9E0C z = 0;
    func_02049B40(d, 7, 0, 0, 0x100, b);
    func_02040EBC(0, 0);
    func_02049624((void *)d, (void *)0x10, 0, 0, z, z, b);
}


void func_021B9E50(Obj *o, int a, u32_021B9E50 c)
{
    o->f8 = func_0204A6C8((void *)c, 0x11, 0, 0, a);
    o->fc = func_0204AC18((void *)c, 8, 0, 0x160, 0, 2, a);
    o->f10 = func_0204AF28((void *)c, 0x14, 0x20, (u16)a);
}


/*
 * Releases three pointers at +8, +0xC and +0x10 through three arm9 helpers.
 */
void func_021B9EA0(S *s)
{
    sub_0204A8D4((u32_021B9EA0)s->f08);
    sub_0204ADA4((u32_021B9EA0)s->f0C);
    sub_0204AFD8((u32_021B9EA0)s->f10);
}
