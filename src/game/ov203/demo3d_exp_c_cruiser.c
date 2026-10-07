/*
 * file:     demo3d_exp_c_cruiser.c
 * unit:     yes
 * function: func_021BF9D0, func_021BFA20, func_021BFAE4
 * address:  0x021BF9D0
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02030734 0x02030734 arm
 *   func_021BE620 0x021BE620 thumb ov203
 *   func_021BDF30 0x021BDF30 thumb ov203
 *   func_021B6208 0x021B6208 thumb ov067
 *   func_021B629C 0x021B629C thumb ov067
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02040588 0x02040588 arm
 *   func_02043598 0x02043598 arm
 *   d_021C3D5C 0x021C3D5C data a1
 *   d_021C3BD0 0x021C3BD0 data a2
 *   func_0204B404 0x0204B404 arm
 */
#include "../../matched/include/Obj04607.h"
#include "../../matched/include/Obj14600.h"

struct Obj;
typedef unsigned short u16;

typedef unsigned int   u32;

struct Vec2 { short x, y; };

typedef struct { int f0, f4, f8, fC; } Out;

typedef struct { int f0; unsigned f4; int f8, fC, f10, f14, f18; unsigned char b1c, b1d, b1e; } In;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *, unsigned, unsigned, unsigned, unsigned, unsigned short);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned short);
extern void func_02049238(void *);
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern int func_021BE620(char *p);
extern int func_021BDF30(char *p);
extern void func_021B6208(Out *, In *, int, unsigned short);
extern int func_021B629C(Out *, int, unsigned char, unsigned char, unsigned char, unsigned short);
extern void func_0204B3DC(struct Obj *, unsigned);
extern void func_0204B92C(struct Obj *, unsigned);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02043598(unsigned, unsigned);
extern void func_0204B404(struct Obj *, const struct Vec2 *, unsigned);
void func_021BF9D0(unsigned short heap);
void func_021BFA20(char *p);
void func_021BFAE4(char *p);
extern const char d_021C3D5C[];
extern const struct Vec2 d_021C3BD0[];

void func_021BF9D0(unsigned short heap)
{
    void *h = func_020490F4(85, heap);
    func_02049B68(h, 3, 4, 0, 0, heap);
    func_02049658(h, 9, 6, 0, 0, 0, heap);
    func_020498F4(h, 18, 6, 0, 0, 0, heap);
    func_02049238(h);
}

/*
 * note: 2026-10-05 wave P13 lane B1: closed from the 6 B DIFF draft (movs r7,#0 sat after movs r1,#0x14 instead of before str r1,[sp,#0x1c]). The store `config.f4 = 0;` moves to between f10 and f14; the other constant stores keep the listing order. 4 compiles. Callee shapes follow the matched ov203 siblings (021BF9D0, 021BDF30, 021BE620, 021BFAE4). The d_021C3BD2 pool word is the .y field of d_021C3BD0 (struct Vec2 array), folded by the compiler. The volatile read at 021BFA50 rereads the byte just stored at 021BFA4E, the same form as matched sibling 021BFAE4 (volatile: 021BFB12). No constant locals. EXACT in c99 and c.
 */
void func_021BFA20(char *p)
{
    unsigned char *a;
    int resource;
    In config;
    a = func_02030734(*(unsigned short *)p, 24, 1, d_021C3D5C, 0xB3);
    *(unsigned char **)(p + 0x10) = a;
    func_021BF9D0(*(unsigned short *)p);
    *a = (func_021BE620(*(void **)(p + 8)) >> 12) / 100;
    if (*(volatile unsigned char *)a >= 54) *a = 53;
    resource = func_021BDF30(*(void **)(p + 4));
    config.f0 = 1;
    config.f8 = 85;
    config.fC = 4;
    config.f10 = 10;
    config.f4 = 0;
    config.f14 = 13;
    config.f18 = 20;
    config.b1c = 0;
    config.b1d = 0;
    config.b1e = 1;
    func_021B6208((Out *)(a + 4), &config, resource, *(unsigned short *)p);
    *(int *)(a + 0x14) = func_021B629C((Out *)(a + 4), resource, d_021C3BD0[*a].x, d_021C3BD0[*a].y, 0, *(unsigned short *)p);
    func_0204B3DC(*(struct Obj **)(a + 0x14), 1);
    func_0204B92C(*(struct Obj **)(a + 0x14), 1);
    func_02040588(6, 1);
    func_02043598(16, 1);
}

void func_021BFAE4(char *p)
{
    unsigned char *a = *(unsigned char * *)&((struct Obj14600 *)p)->f10;
    int progress = func_021BE620(((struct Obj14600 *)p)->f8) >> 12;
    if (*a < 54 && *a * 100 <= progress) {
        func_0204B404(*(struct Obj * *)&((struct Obj04607 *)a)->f14, d_021C3BD0 + *a, 1);
        ++*a;
        if (*(volatile unsigned char *)&((struct Obj04607 *)a)->f0 == 54)
            func_0204B3DC(*(struct Obj * *)&((struct Obj04607 *)a)->f14, 0);
    }
}
