/*
 * file:     colosseum_p01.c
 * unit:     yes
 * function: func_02174B58, func_02174B80, func_02174BB8, func_02174BEC, func_02174C34, func_02174C60, func_02174C90, func_02174CB8, func_02174CE4
 * address:  0x02174B58
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_0217562C 0x0217562C data a4
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_021751B4 0x021751B4 thumb ov012
 *   func_0203D378 0x0203D378 arm
 *   func_021750D8 0x021750D8 thumb ov012
 *   func_021750C0 0x021750C0 thumb ov012
 */
#include "../../matched/include/Obj19276.h"
#include "../../matched/include/Obj19277.h"
#include "../../matched/include/Obj19278.h"
#include "../../matched/include/Obj19279.h"
#include "../../matched/include/Obj19280.h"
#include "../../matched/include/Obj19281.h"
#include "../../matched/include/Obj19283.h"
#include "../../matched/include/Obj19284.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_02034714(const char *,u32,const char *);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void func_02082D44(void *,void *,u32);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
extern void func_021751B4(u8 *,u32,void *);
extern u32 func_0203D378(void);
extern int func_021750D8(u8 *p, int slot, int value);
extern u8 func_021750C0(char *);
u8 *func_02174B58(int a, u8 *b, int c);
void func_02174B7C(void);
void func_02174B80(u32 a, u32 b, void *c, u8 *d);
u32 func_02174BB8(u32 a, u32 b);
void func_02174BEC(u32 a, u32 b, void *c, u8 *d);
int func_02174C34(u32 a);
void func_02174C60(u32 a, u32 b, void *c, u8 *d);
u32 func_02174C90(u32 a);
void func_02174CB8(u32 a, u32 b, u8 *c, u8 *d);
u32 func_02174CE4(char *p);
extern const char d_0217562C[];

u8 *func_02174B58(int a, u8 *b, int c)
{
    if (c > 0x800) func_02034714(d_0217562C, 0, d_0217562C);
    return b + 4 + (a << 11);
}


void func_02174B7C(void)
{
}

void func_02174B80(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19276 *)d)->f355C;
    if (a == func_0203D1A4((struct Link *)((u32)func_020399A8()))) return;
    if (w == 0 || ((struct Obj19277 *)w)->f0 == 0) return;
    func_02082D44(c, w + 0x18 + a * 44, b);
}

u32 func_02174BB8(u32 a, u32 b)
{
    u32 v = 0;
    if (b != 1) v = 255;
    return func_0203D3F8((u32)func_020399A8(),(u8)v,0x1501,44,a,1,0,1);
}


void func_02174BEC(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19278 *)d)->f355C;

    if (a == func_0203D1A4((struct Link *)((u32)func_020399A8()))) {
        return;
    }
    if (w == 0 || ((struct Obj19279 *)w)->f0 == 0) {
        return;
    }
    if (*(void **)(w + a * 4 + 0x134) == 0) {
        return;
    }
    func_02082D44(c, *(void **)(w + a * 4 + 0x134), b);
    (w + a)[0x144] = 1;
}

int func_02174C34(u32 a)
{
    return func_0203D3F8((u32)func_020399A8(),255,0x1502,0x678,a,1,0,1);
}

void func_02174C60(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19280 *)d)->f355C;
    if (a == func_0203D1A4((struct Link *)((u32)func_020399A8()))) return;
    if (w == 0 || ((struct Obj19281 *)w)->f0 == 0) return;
    func_021751B4(w,a,c);
}

u32 func_02174C90(u32 a)
{
    return func_0203D3F8((u32)func_020399A8(),255,0x1503,20,a,0,1,1);
}

void func_02174CB8(u32 a, u32 b, u8 *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19283 *)d)->f355C;
    if (w == 0 || ((struct Obj19284 *)w)->f0 == 0) return;
    if (func_0203D378() == 0) return;
    func_021750D8(w,a,*c);
}

u32 func_02174CE4(char *p)
{
    u8 v = func_021750C0(p);
    return func_0203D3F8((u32)func_020399A8(),0,0x1504,1,(u32)&v,1,0,0);
}
