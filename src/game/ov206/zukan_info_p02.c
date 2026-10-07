/*
 * file:     zukan_info_p02.c
 * unit:     yes
 * function: func_021BA374, func_021BA4CC, func_021BA4F4
 * address:  0x021BA374
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BBC9C 0x021BBC9C thumb ov206
 *   func_0207D658 0x0207D658 arm
 *   func_02006984 0x02006984 thumb
 *   func_0204B53C 0x0204B53C arm
 *   func_0204B528 0x0204B528 arm
 *   func_021BAF7C 0x021BAF7C thumb ov206
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BAF50 0x021BAF50 thumb ov206
 *   func_021BA934 0x021BA934 thumb ov206
 *   func_021BBBD8 0x021BBBD8 thumb ov206
 *   func_021BB92C 0x021BB92C thumb ov206
 */
#include "../../matched/include/Obj00316.h"
#include "../../matched/include/Obj00173.h"
#include "../../matched/include/Obj14635.h"
#include "../../matched/include/Obj14636.h"
#include "../../matched/include/Obj25395.h"
#include "../../matched/include/Obj25396.h"
#include "../../matched/include/Obj25397.h"
#include "../../matched/include/Obj25398.h"

struct S;
struct Actor;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

struct Pt { s16 x; s16 y; };

typedef signed int     s32;

extern s32 func_021BBC9C(struct S *p);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern u32 func_02006984(u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_0204B53C(const struct Actor *actor, struct Pt *out);
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
extern void func_021BAF7C(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021BAF50(char *p);
extern void func_021BA934(char *p);
extern void func_021BBBD8(struct S *p, int i);
extern void func_021BB92C(char *p, int index);
void func_021BA374(char *p);
void func_021BA4CC(char *p);
void func_021BA4F4(char *p);
void func_021BA514(char *p);
void func_021BA51C(char *p);
int func_021BA524(char *p);
int func_021BA534(char *p);
void func_021BA544(char *p);

void func_021BA374(char *p)
{
    if (((struct Obj00316 *)p)->f18 == 0) func_021BBC9C((struct S *)p);
    ((struct Obj00316 *)p)->f64 += 1;
    if (((struct Obj00316 *)p)->f64 == 4) {
        ((struct Obj00316 *)p)->f39 |= 1;
        ((struct Obj00316 *)p)->f64 = 0;
    }
    switch (((struct Obj00316 *)p)->f54) {
    case 0: case 6: case 7: break;
    case 1:
        ((struct Obj00316 *)p)->f60 += 1;
        if (((struct Obj00316 *)p)->f60 == 15) ((struct Obj00316 *)p)->f54 = 2;
        break;
    case 2: {
        int v = ((struct Obj00316 *)p)->f68 - 1;
        ((struct Obj00316 *)p)->f68 = v;
        *(volatile u16 *)0x04000040 = 100;
        *(volatile u16 *)0x04000044 = (u16)(((8 << 8) & 0xFF00) | (v & 0xFF));
        if (((struct Obj00316 *)p)->f68 == 16) {
            *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
            func_0207D658((u32)((volatile u16 *)0x04000050), 0x10, 0);
            func_02006984(((struct Obj00316 *)p)->fC, ((struct Obj00316 *)p)->fE, 0x40, 0, 0, 0, 0, 0);
            ((struct Obj00316 *)p)->f54 = 3;
        }
        break;
    }
    case 3:
        if (((struct Obj00316 *)p)->f58 != 0) ((struct Obj00316 *)p)->f54 = 4;
        break;
    case 4: {
        struct Pt pt;
        int fx = 0;
        int fy = 0;
        void *obj = *(void **)(p + ((struct Obj00316 *)p)->fB4 * 4 + 0xac);
        func_0204B53C(obj, &pt);
        pt.x += 1;
        pt.y += 1;
        if (pt.x > 0x80) { pt.x = 0x80; fx = 1; }
        if (pt.y > 0x48) { pt.y = 0x48; fy = 1; }
        func_0204B528(*(void **)(p + ((struct Obj00316 *)p)->fB4 * 4 + 0xac), &pt);
        if (fx && fy) ((struct Obj00316 *)p)->f54 = 6;
        break;
    }
    case 5:
        if (((struct Obj00316 *)p)->f5C != 0) {
            func_02006984(((struct Obj00316 *)p)->fC, ((struct Obj00316 *)p)->fE, 0x40, 0, 0, 0, 0, 0);
            ((struct Obj00316 *)p)->f54 = 6;
        }
        break;
    }
    if (((struct Obj00316 *)p)->f18 == 0 || ((struct Obj00316 *)p)->f18 == 2) func_021BAF7C(p);
    func_0201C4E4(((struct Obj00316 *)p)->f2C);
}

void func_021BA4CC(char *p)
{
    func_021BAF50(p);
    func_021BA934(p);
    func_021BBBD8((struct S *)p,((struct Obj00173 *)p)->f190);
    func_021BB92C(p,((struct Obj00173 *)p)->fE0);
}

void func_021BA4F4(char *p)
{
    func_021BAF50(p);
    func_021BBBD8((struct S *)p,((struct Obj14635 *)p)->f190);
    func_021BB92C(p,((struct Obj14635 *)p)->fE0);
}

void func_021BA514(char *p)
{
    ((struct Obj25395 *)p)->f58=1;
}

void func_021BA51C(char *p)
{
    ((struct Obj25396 *)p)->f5C=1;
}

int func_021BA524(char *p)
{
    int result=0;
    if(((struct Obj25397 *)p)->f54==4) result=1;
    return result;
}

int func_021BA534(char *p)
{
    int result=0;
    if(((struct Obj25398 *)p)->f54==6) result=1;
    return result;
}

void func_021BA544(char *p)
{
    if(((struct Obj14636 *)p)->f54==0) ((struct Obj14636 *)p)->f54=1;
}
