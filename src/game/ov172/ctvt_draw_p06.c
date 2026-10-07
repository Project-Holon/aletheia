/*
 * file:     ctvt_draw_p06.c
 * unit:     yes
 * function: func_021BDCB8, func_021BDD6C, func_021BDEF0, func_021BDFDC, func_021BDFE4, func_021BDFEC, func_021BDFFC, func_021BE004, func_021BE00C, func_021BE010, func_021BE018, func_021BE024, func_021BE02C, func_021BE030, func_021BE034, func_021BE03C, func_021BE044, func_021BE04C, func_021BE054, func_021BE058, func_021BE05C, func_021BE078, func_021BE07C, func_021BE08C, func_021BE0A0, func_021BE0A4
 * address:  0x021BDCB8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8FB8 0x021B8FB8 thumb ov172
 *   func_021BBE5C 0x021BBE5C thumb ov172
 *   func_021BA8C4 0x021BA8C4 thumb ov172
 *   func_021B8CC8 0x021B8CC8 thumb ov172
 *   func_021BBA94 0x021BBA94 thumb ov172
 *   func_021BA2C4 0x021BA2C4 thumb ov172
 *   func_0202223C 0x0202223C thumb
 *   func_021B8084 0x021B8084 thumb ov172
 *   func_021B7578 0x021B7578 thumb ov172
 *   func_021B7B80 0x021B7B80 thumb ov172
 *   func_021B8BA4 0x021B8BA4 thumb ov172
 *   func_021B8B8C 0x021B8B8C thumb ov172
 *   func_021B7B30 0x021B7B30 thumb ov172
 *   func_021B8B94 0x021B8B94 thumb ov172
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_021BE210 0x021BE210 thumb ov172
 *   func_02008510 0x02008510 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_021B9F98  0x021B9F98  thumb
 *   func_021B8720 0x021B8720 thumb ov172
 */
#include "../../matched/include/Obj02215.h"
#include "../../matched/include/Obj02216.h"
#include "../../matched/include/Obj24107.h"
#include "../../matched/include/Obj24108.h"
#include "../../matched/include/Obj24109.h"
#include "../../matched/include/Obj24110.h"
#include "../../matched/include/Obj24111.h"
#include "../../matched/include/Obj24113.h"
#include "../../matched/include/Obj24114.h"
#include "../../matched/include/Obj24115.h"
#include "../../matched/include/Obj24116.h"
#include "../../matched/include/Obj24117.h"
#include "../../matched/include/Obj24118.h"
#include "../../matched/include/Obj24119.h"
#include "../../matched/include/Obj24120.h"
#include "../../matched/include/Obj24121.h"
#include "../../matched/include/Obj24122.h"
#include "../../matched/include/Obj24123.h"
#include "../../matched/include/Obj24125.h"
#include "../../matched/include/Obj24126.h"
#include "../../matched/include/Obj24127.h"

struct PrintSys;
struct Cfg;
struct Descriptor;
struct StrObj;
struct U16Vec;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

extern void func_021B8FB8(void *,char *);
extern void func_021BBE5C(void *,char *);
extern void func_021BA8C4(u16 *a0, char *p);
extern void func_021B8CC8(void *,char *);
extern void func_021BBA94(void *a0, u8 *p);
extern void func_021BA2C4(void *a0, u8 *p);
extern void func_0202223C(u32 a, u32 color);
extern void func_021B8084(void *,char *);
extern void func_021B7578(int x, char *p);
extern void func_021B7B80(int x, char *p);
extern u32 func_021B8BA4(int unused, char *base, int i);
extern u32 func_021B8B8C(int unused, char *base, int i);
extern u32 func_021B7B30(int unused, char *base, int i);
extern char *func_021B8B94(int unused, char *base, int i);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u8 func_021B8B68(int unused, char *p);
extern void func_021BE210(u8 *p, u32 v);
extern void *func_02008510(void *a, int tag);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(u32 owner, void *b, short y, u32 c, void *d, u32 e, u32 f);
extern void func_02045808(struct U16Vec *vec);
extern int func_021B9F98(int unused, int *p);
extern void func_021B8720(void *a0, u32 *a1, u32 a2);
void func_021BDCB8(u8 *p);
void func_021BDD6C(u8 *p);
void func_021BDEF0(u8 *p, char *a, u32 b);
u32 func_021BDFDC(void *p);
u32 func_021BDFE4(void *p);
int func_021BDFEC(void *p);
u32 func_021BDFFC(void *p);
u32 func_021BE004(void *p);
u16 func_021BE00C(u16 *p);
u32 func_021BE010(void *p);
u32 func_021BE018(void *p, int i);
u32 func_021BE024(void *p);
u32 func_021BE02C(void *p);
void func_021BE030(void *p, u32 v);
u32 func_021BE034(void *p);
u32 func_021BE03C(void *p);
u32 func_021BE044(void *p);
u32 func_021BE04C(void *p);
u8 func_021BE054(void *p);
void func_021BE058(void *p, u32 v);
int func_021BE05C(void *p);
u32 func_021BE078(void *p);
void func_021BE07C(u32 *p, u32 v);
void func_021BE08C(void *p);
void func_021BE0A0(void *p, u32 v);
u32 func_021BE0A4(void *p);

void func_021BDCB8(u8 *p)
{
    switch (*(u32 *)(p+8)) {
    case 1: func_021B8FB8(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBE5C(p,*(char **)(p+0x1f0)); break;
    case 3: func_021BA8C4((u16 *)p,*(char **)(p+0x1ec)); break;
    }
    *(u32 *)(p+8)=*(u32 *)(p+12);
    switch (*(u32 *)(p+8)) {
    case 0: break;
    case 1: func_021B8CC8(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBA94(p,(u8 *)(*(char **)(p+0x1f0))); break;
    case 3: func_021BA2C4(p,(u8 *)(*(char **)(p+0x1ec))); break;
    case 5:
        func_0202223C(0,0);
        func_0202223C(1,0);
    case 4:
        func_021B8084(p,*(char **)(p+0x1e4));
        func_021B7578((int)p,*(char **)(p+0x1e0));
        func_021B7B80((int)p,*(char **)(p+0x1e0));
        break;
    }
}

void func_021BDD6C(u8 *p)
{
    u8 i;
    u32 found;
    u32 r;
    u32 m;
    u32 b;
    u32 w;
    found = 0;
    if (((struct Obj02215 *)p)->f8 == 3) {
        return;
    }
    r = func_021BE05C(p);
    for (i = found; i < 4; i++) {
        if (func_021B8BA4((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i) != 1) continue;
        if (func_021B8B8C((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i) != 1) continue;
        if (func_021B7B30((int)p, *(char * *)&((struct Obj02215 *)p)->f1E0, i) != 0) continue;
        m = 1 << i;
        if (m & p[0x1b4]) continue;
        {
            char *k = func_021B8B94((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i);
            if (r == 1) {
                if (i == 0) b = 2; else b = 3;
            } else {
                b = i;
            }
            func_021BDEF0(p, k, *(u32 *)(p + b * 4 + 0x1b8));
        }
        p[0x1b4] += (u8)m;
        p[0x1b5] += (u8)(1 << b);
    }
    for (i = 0; i < 4; i++) {
        m = 1 << i;
        if (!(p[0x1b5] & m)) continue;
        if (func_0201C6C4(((struct Obj02215 *)p)->f1D0, func_02045770((struct Descriptor *)*(u32 *)(p + i * 4 + 0x1b8))) != 0) continue;
        w = *(u32 *)(p + i * 4 + 0x1b8);
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        p[0x1b5] -= (u8)m;
        found = 1;
    }
    if (found == 1) {
        u32 v = func_021B8B68((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4);
        if (v != 0xff) {
            func_021BE210(p, v);
        }
    }
}

void func_021BDEF0(u8 *p, char *a, u32 b)
{
    void *s;
    int x;
    s = func_02008510(a, ((struct Obj02216 *)p)->f0);
    x = (0x60 - (u8)func_0201D304(s, ((struct Obj02216 *)p)->f1C8, 0)) / 2;
    func_0201C724(((struct Obj02216 *)p)->f1D0, func_02045770((struct Descriptor *)b), x + 1, 1, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    func_0201C724(((struct Obj02216 *)p)->f1D0, func_02045770((struct Descriptor *)b), x - 1, 1, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    func_0201C724(((struct Obj02216 *)p)->f1D0, func_02045770((struct Descriptor *)b), x, 2, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    func_0201C724(((struct Obj02216 *)p)->f1D0, func_02045770((struct Descriptor *)b), x, 0, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    func_0201C724(((struct Obj02216 *)p)->f1D0, func_02045770((struct Descriptor *)b), x, 1, s, ((struct Obj02216 *)p)->f1C8, 0x3c00);
    func_02045808(s);
}


u32 func_021BDFDC(void *p)
{
    return ((struct Obj24107 *)p)->f1E0;
}


/*
 * Field getter, u32 at +0x1e4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BDFE4(void *p)
{
    return ((struct Obj24108 *)p)->f1E4;
}


/*
 * Tail call to func_021B9F98, second argument the field at +0x1e8.
 *
 * Addresses are Black-image addresses.
 *
 * evidence: func_021B9F98 is ov172's own code ("ldr r0, [r1, #0x10]; bx lr"
 * after the pop at 0x021B9F94), inside ov172's window, so only ov172 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov172's own listing.
 */
int func_021BDFEC(void *p)
{
    return func_021B9F98((int)p, (int *)(((struct Obj24109 *)p)->f1E8));
}


/*
 * Field getter, u32 at +0x1f4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BDFFC(void *p)
{
    return ((struct Obj24110 *)p)->f1F4;
}


/*
 * Field getter, u32 at +0x1f8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE004(void *p)
{
    return ((struct Obj24111 *)p)->f1F8;
}


/*
 * Field getter, u16 at +0.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021BE00C(u16 *p)
{
    return *p;
}


u32 func_021BE010(void *p)
{
    return ((struct Obj24113 *)p)->f17C;
}


/*
 * Field getter, u32 at +0x180 of element i (stride 4).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE018(void *p, int i)
{
    return *(u32 *)((char *)p + i * 4 + 0x180);
}


/*
 * Field getter, u32 at +0x1ac.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE024(void *p)
{
    return ((struct Obj24114 *)p)->f1AC;
}

u32 func_021BE02C(void *p)
{
    return ((struct Obj24115 *)p)->f10;
}

void func_021BE030(void *p, u32 v)
{
    ((struct Obj24116 *)p)->f10 = v;
}


/*
 * Field getter, u32 at +0x1c8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE034(void *p)
{
    return ((struct Obj24117 *)p)->f1C8;
}


u32 func_021BE03C(void *p)
{
    return ((struct Obj24118 *)p)->f1CC;
}


/*
 * Field getter, u32 at +0x1d0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE044(void *p)
{
    return ((struct Obj24119 *)p)->f1D0;
}


/*
 * Field getter, u32 at +0x1d4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE04C(void *p)
{
    return ((struct Obj24120 *)p)->f1D4;
}


/*
 * Field getter, u8 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021BE054(void *p)
{
    return ((struct Obj24121 *)p)->f18;
}


/*
 * Set the u8 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE058(void *p, u32 v)
{
    ((struct Obj24122 *)p)->f18 = v;
}


/*
 * 1 for states 1 and 2, else 2.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE05C(void *p)
{
    u8 v = func_021BE054(p);
    if (v == 1) {
        return 1;
    }
    if (v == 2) {
        return 1;
    }
    return 2;
}


u32 func_021BE078(void *p)
{
    return ((struct Obj24123 *)p)->f1C;
}

void func_021BE07C(u32 *p, u32 v)
{
    func_021B8720(p, (u32 *)p[0x79], v);
}


/*
 * Tail call passing the inverted flag at +0x1c as the second argument.
 *
 * Addresses are Black-image addresses.
 *
 * evidence: func_021BE07C is ov172's own code (a tail call to func_021B8720
 * right after func_021BE078's bx lr), inside ov172's window, so only ov172
 * can be resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov172's own listing.
 */
void func_021BE08C(void *p)
{
    u32 v = ((struct Obj24125 *)p)->f1C;
    if (v == 0) {
        v = 1;
    } else {
        v = 0;
    }
    func_021BE07C(p, v);
}

void func_021BE0A0(void *p, u32 v)
{
    ((struct Obj24126 *)p)->f1C = v;
}


/*
 * Field getter, u8 at +0x19.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE0A4(void *p)
{
    return ((struct Obj24127 *)p)->f19;
}
