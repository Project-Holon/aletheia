/*
 * file:     btl_server_p131.c
 * unit:     yes
 * function: func_021CDDDC, func_021CDE8C, func_021CDECC, func_021CDEE8
 * address:  0x021CDDDC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021E90A0  0x021E90A0  thumb  ov093
 *   func_021E90D0  0x021E90D0  thumb  ov093
 *   func_021BA5C4  0x021BA5C4  thumb  ov093
 *   func_021BA5D0  0x021BA5D0  thumb  ov093
 *   func_021F84E8  0x021F84E8  thumb  ov094
 *   func_021F8504  0x021F8504  thumb  ov094
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021D3FA8  0x021D3FA8  thumb  ov093
 *   func_021EAEA8  0x021EAEA8  thumb  ov093
 *   func_021EE688  0x021EE688  thumb  ov093
 *   func_021D3F54  0x021D3F54  thumb  ov093
 *   func_021CDF1C 0x021CDF1C thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../../matched/include/Obj01689.h"
#include "../../matched/include/Obj06232.h"
#include "../../matched/include/Obj04362.h"

struct Q3;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void *func_021B86B8(void ***p);
extern void func_021E90A0(unsigned int *o, unsigned int key);
extern int func_021E90D0(struct S *s);
extern u16 func_021BA5C4(u8 *p);
extern u16 func_021BA5D0(struct Q3 *p);
extern void func_021F84E8(int a, int b);
extern void func_021F8504(u32 a, u32 b, u32 c);
extern u32 func_021CD9E0(u8 *p);
extern u16 func_021D3FA8(u8 *p);
extern void func_021EAEA8(u8 *p, int v);
extern int func_021EE688(int, int);
extern void func_021D3F54(u8 *p);
extern void *func_021CDF1C(u8 *);
extern int func_021D59B4(u8 *p, int k);
extern u32 _u32_div_f(u32,u32);
int func_021CDDDC(u8 *p, int *st);
int func_021CDE8C(int a, int b);
void func_021CDECC(u8 *p);
u32 func_021CDEE8(u8 *p);


/*
 * Levers (from the DIFF note): case 0 is the call written in each arm, `!= 4` arm first
 * (a-boolean-argument-is-a-call-in-each-arm.md; a flag value hoists `movs r1,#1`);
 * func_021F84E8 takes two arguments as its own file says, the second being the 0xe4
 * halfword still live in r1 from the || test; func_021D3FA8 is declared u32 here because
 * the original narrows its result before the u16 parameter of func_021EAEA8.
 */
int func_021CDDDC(u8 *p, int *st)
{
    switch (*st) {
    case 0:
        if ((int)func_021B86B8(*(void *** *)&((struct Obj01689 *)p)->f0) != 4) {
            func_021E90A0(((struct Obj01689 *)p)->f54, 0);
        } else {
            func_021E90A0(((struct Obj01689 *)p)->f54, 1);
        }
        *st = *st + 1;
        break;
    case 1:
        if (func_021E90D0(((struct Obj01689 *)p)->f54) == 0) {
            break;
        }
        ((struct Obj01689 *)p)->fE4 = func_021BA5C4(((struct Obj01689 *)p)->f0);
        ((struct Obj01689 *)p)->fE6 = func_021BA5D0(((struct Obj01689 *)p)->f0);
        if (((struct Obj01689 *)p)->fE4 != 0 || ((struct Obj01689 *)p)->fE6 != 0) {
            func_021F84E8(((struct Obj01689 *)p)->fE6, ((struct Obj01689 *)p)->fE4);
            if (((struct Obj01689 *)p)->fE6 != 0) {
                func_021F8504(0, 1, 1);
            }
        }
        func_021CDECC(p);
        if (func_021CD9E0(p) != 0) {
            func_021EAEA8(((struct Obj01689 *)p)->f54, (u16)((u32)func_021D3FA8(p + 0x18)));
        }
        return 1;
    }
    return 0;
}


int func_021CDE8C(int a, int b)
{
    int r4;
    if (((struct Obj06232 *)a)->f54 != 0) {
        r4 = func_021CDDDC((u8 *)a, (int *)b);
        if (r4 != 0) {
            if (func_021EE688(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6) != 0)
                func_021D3F54((u8 *)(a + 0x18));
        }
        return r4;
    }
    func_021EE688(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6);
    return 1;
}

void func_021CDECC(u8 *p) { void *a; a=func_021CDF1C(p); if(a) ((struct Obj04362 *)p)->f19C=func_021D59B4(a,13); }

u32 func_021CDEE8(u8 *p) { void *a; u32 now,old; a=func_021CDF1C(p); if(a) { now=func_021D59B4(a,13); old=((struct Obj04362 *)p)->f19C; if(now>=old) return 0; return _u32_div_f((old-now)*100,now); } return 0; }
