/*
 * file:     unit_021A1144.c
 * unit:     yes
 * function: func_021A1144, func_021A117C, func_021A1190, func_021A119C, ov021_func_021A11A8, func_021A1244, func_021A1288, func_021A1298, func_021A12A4, func_021A12BC, func_021A12D4, func_021A1358, func_021A136C, func_021A1388, func_021A139C, func_021A13C0, func_021A13E4, func_021A13F8, func_021A1404, func_021A1410, func_021A141C
 * address:  0x021A1144
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217D160  0x0217D160  thumb  ov018
 *   func_0217D1C0  0x0217D1C0  thumb  ov018
 *   func_0217D3AC  0x0217D3AC  thumb  ov018
 *   func_0217D4DC  0x0217D4DC  thumb  ov018
 *   func_02034AC4  0x02034AC4  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_021F00C8  0x021F00C8  thumb  ov030
 *   abs_id_1e      0x0000001E  data
 *   func_021E0118  0x021F0118  thumb  ov030
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F0114  0x021F0114  thumb  ov030
 *   func_021F00F8  0x021F00F8  thumb  ov030
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_020414AC  0x020414AC  arm
 *   func_0204152C  0x0204152C  arm
 *   func_02043598  0x02043598  arm
 *   func_021A836C  0x021A836C  thumb  ov021
 *   func_021A8B18  0x021A8B18  thumb  ov021
 *   func_02024A20  0x02024A20  thumb
 *   func_021A8AFC  0x021A8AFC  thumb  ov021
 *   d_021D8708     0x021D8708  data  a4
 *   func_02024DCC  0x02024DCC  thumb
 *   func_021A84BC  0x021A84BC  thumb  ov021
 *   func_020403F4  0x020403F4  arm
 *   func_021A85B4  0x021A85B4  thumb  ov021
 *   func_02024ABC  0x02024ABC  thumb
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A8E10  0x021A8E10  thumb  ov021
 *   func_021A8E20  0x021A8E20  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049658  0x02049658  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D3270  0x021D3270  thumb  ov021
 *   func_021D3244  0x021D3244  thumb  ov021
 *   func_021EFEC0  0x021EFEC0  thumb  ov031
 *   abs_id_1f      0x0000001F  data
 *   func_021EFFE8  0x021EFFE8  thumb  ov031
 *   func_0217394C  0x0217394C  thumb  ov012
 *   func_021F0054  0x021F0054  thumb  ov031
 *   func_021F00D4  0x021F00D4  thumb  ov031
 *   func_0217CFE4  0x0217CFE4  thumb  ov018
 */
#include "../../matched/include/Obj17993.h"

struct Big;
struct Ctx;
struct Sub02009210Obj;
struct BigObj;
struct Obj;
struct Rec44;
struct BgTemplate;
struct W;
struct St021D3244;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed char    s8;

extern int func_02034AC4(signed int);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern char *func_021F00C8(u32 a, u32 *b, u32 c);
extern void func_021E0118(char *p);
extern void func_02034A5C(int);
extern void func_021F0114(void *a);
extern void func_021F00F8(char *p);
extern unsigned char *func_020120F8(const struct Ctx *);
extern u16 func_02012AC8(const struct Rec44 *);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_0204152C(int channel, u16 val);
extern void func_02043598(u32, u32);
extern struct Obj *func_021A836C(u16 heap, u16 a1, int a2, void *a3, int a4);
extern u32 func_021A8B18(void *a, void *b, u32 c);
extern void func_02024A20(u8 a0, u8 a1, void *a2, u16 heap);
extern void func_021A8AFC(int a, int b);
extern int func_02024DCC(void);
extern void func_021A84BC(struct Obj *p);
extern void func_020403F4(u32);
extern u32 func_021A85B4(struct Obj *p);
extern void func_02024ABC(u32);
extern void func_021A8840(void *s);
extern u32 func_021A0F90(u8 *p);
extern u32 func_021A8E10(u32);
extern void func_021A8E20(struct W *w, u32 v);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049BDC(void *h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u32 heap);
extern void func_02049658(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 heap);
extern void func_02049990(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 heap);
extern void func_02049238(void *h);
extern u32 func_02188E30(u8 *p);
extern void func_021D3270(u32 a, int b, int c, int d, int e, int f);
extern void func_021D3244(struct St021D3244 *p, int i, u8 v);
extern u32 *func_021EFEC0(void *a);
extern void func_021EFFE8(u32 *p);
extern int func_0217394C(const struct Ctx *p);
extern void func_021F0054(struct Obj *p, int mode);
extern void func_021F00D4(char *p, int mode);
extern u8 *func_0217CFE4(void *a);
void func_021A1144(u32 *p);
void func_021A117C(u32 *p);
void func_021A1190(u32 *p);
void func_021A119C(u32 *p);
void ov021_func_021A11A8(u32 *p, u32 x);
void ov021_func_021A1244(u32 *p);
void func_021A1288(u32 *p);
void func_021A1298(u32 *p);
u32 func_021A12A4(void *a);
void func_021A12BC(u32 *p, u32 a);
void func_021A12D4(u32 *p, u32 x);
u32 func_021A1358(u32 *p);
void func_021A136C(u32 *p);
void func_021A1388(u32 *p);
void func_021A139C(u32 *p, u32 a);
void func_021A13C0(u32 *p, u32 a);
void ov021_func_021A13E4(u32 *p);
extern unsigned char abs_id_1e[];
extern unsigned char d_021D8708[];
extern unsigned char abs_id_1f[];







/*
 * Addresses are Black-image addresses.
 */
void func_021A1144(u32 *p)
{
    u32 x;
    func_02034AC4((int)abs_id_1e);
    x = (u32)func_02009210(func_02012EBC(func_020120F4(func_02188C80((void *)p[5]))));
    p[8] = (u32)func_021F00C8(x, p, (u32)func_02188C80((void *)p[5]));
}







void func_021A117C(u32 *p)
{
    func_021E0118((char *)p[8]);
    func_02034A5C((int)abs_id_1e);
}





void func_021A1190(u32 *p) { func_021F0114((void *)p[8]); }




void func_021A119C(u32 *p) { func_021F00F8((char *)p[8]); }





void ov021_func_021A11A8(u32 *p, u32 x)
{
    u32 a, b, c, d;
    u32 f;
    a = (u32)func_02188C80((void *)p[5]);
    b = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a));
    c = (u32)func_020120F4((const struct Ctx *)a);
    d = func_0201296C((const struct BigObj *)c);
    f = 0;
    if (x == 0 || x - 2 <= 4)
        f = 1;
    func_0203FCA0(4, (const struct BgTemplate *)d_021D8708, 0);
    func_02040588(4, 1);
    func_020414AC(4);
    func_0204152C(4, 0);
    func_02043598(0x10, 1);
    p[8] = (u32)func_021A836C(0x70, ((u16 *)p)[6], (int)p, (void *)p[5], f);
    if (func_021A8B18((void *)c, (void *)d, b) != 1)
        func_02024A20(4, 0xe, (void *)c, ((u16 *)p)[6]);
    func_021A8AFC(((u16 *)p)[6], f);
}






void ov021_func_021A1244(u32 *p)
{
    u32 a, b, c;
    a = (u32)func_02188C80((void *)p[5]);
    b = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a));
    c = (u32)func_020120F4((const struct Ctx *)a);
    if (func_021A8B18((void *)c, (void *)func_0201296C((const struct BigObj *)c), b) != 1)
        func_02024DCC();
    func_021A84BC((struct Obj *)p[8]);
    func_020403F4(4);
}






void func_021A1288(u32 *p)
{
    func_02024ABC(func_021A85B4((struct Obj *)p[8]));
}


void func_021A1298(u32 *p) { func_021A8840((void *)p[8]); }




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A12A4(void *a)
{
if (func_021A0F90((u8 *)a) != 1) {
    return 0;
}
return func_021A8E10(((struct Obj17993 *)((u8 *)(a)))->f20);
}




void func_021A12BC(u32 *p, u32 a)
{
    if (func_021A0F90((u8 *)p) == 1)
        func_021A8E20((struct W *)p[8], a);
}




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

void func_0217D160(int a0);
typedef struct HidObj_021A13F8 {
    int f0[8];
    int f20;
} HidObj_021A13F8;

void func_021A13F8(HidObj_021A13F8 *w)
{
    func_0217D160(w->f20);
}

void func_0217D1C0(u8 *w, int b);
typedef struct HidObj_021A1404 {
    int f0[8];
    u8 *f20;
} HidObj_021A1404;

void func_021A1404(HidObj_021A1404 *w, int b)
{
    func_0217D1C0(w->f20, b);
}

void func_0217D3AC(int id);
typedef struct HidObj_021A1410 {
    int f0[8];
    int f20;
} HidObj_021A1410;

void func_021A1410(HidObj_021A1410 *w)
{
    func_0217D3AC(w->f20);
}

void *func_0217D4DC(void *w, int b, int c);
typedef struct HidObj_021A141C {
    int f0[8];
    void *f20;
} HidObj_021A141C;

void *func_021A141C(HidObj_021A141C *w, int b)
{
    return func_0217D4DC(w->f20, b, (int)w);
}
