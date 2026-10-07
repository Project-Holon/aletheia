/*
 * file:     unit_021BF050_p22.c
 * unit:     yes
 * function: func_021C1A44, func_021C1A58, func_021C1AC0, func_021C1B04
 * address:  0x021C1A44
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
 *   func_02082BCC 0x02082BCC arm
 *   func_02043598 0x02043598 arm
 *   func_02051B84 0x02051B84 arm
 *   d_021C377C 0x021C377C data a4
 *   func_021C1C9C 0x021C1C9C thumb ov099
 *   func_0201EC64 0x0201EC64 thumb
 *   func_021C1D1C 0x021C1D1C thumb ov099
 *   func_021C208C 0x021C208C thumb ov099
 *   func_021C2090 0x021C2090 thumb ov099
 *   func_021C1F74 0x021C1F74 thumb ov099
 *   func_02051C6C 0x02051C6C arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021B9800 0x021B9800 thumb ov099
 *   func_021B984C 0x021B984C thumb ov099
 *   func_021BB2F0 0x021BB2F0 thumb ov099
 *   func_021BB42C 0x021BB42C thumb ov099
 *   func_021BB4D0 0x021BB4D0 thumb ov099
 *   func_021BB4EC 0x021BB4EC thumb ov099
 *   func_02051C88 0x02051C88 arm
 *   func_021C1CD4 0x021C1CD4 thumb ov099
 *   func_021C1C10 0x021C1C10 thumb ov099
 *   func_021C19DC 0x021C19DC thumb ov099
 */
#include "../../matched/include/Obj18281.h"
#include "../../matched/include/Obj10212.h"
#include "../../matched/include/Obj00008.h"

struct WordSet;
struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021C1A44;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32_021C1A44;

typedef int BOOL;

typedef unsigned int   u32_021C1A58;

typedef unsigned int   u32_021C1AC0;

typedef unsigned int u32_021C1B04;

typedef signed int     s32_021C1B04;

extern void func_02082BCC(void *, int, int);
extern void func_02043598(u32_021C1A58 mask, u32_021C1A58 enable);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_021C1C9C(u32_021C1A58 a, int b, u32_021C1A58 p);
extern struct WordSet *func_0201EC64(u32_021C1A58 heap);
extern void func_021C1D1C(u8 *p, void *a, int heap);
extern void func_021C208C(char *);
extern void func_021C2090(char *);
extern void func_021C1F74(char *);
extern void func_02051C6C(void *);
extern u32_021C1AC0 func_0201ED04(struct WordSet *p);
extern u32_021C1B04 func_021B9800(void *);
extern u32_021C1B04 func_021B984C(void *);
extern void func_021BB2F0(char *, int);
extern void func_021BB42C(void *);
extern void func_021BB4D0(char *);
extern void func_021BB4EC(void *);
extern s32_021C1B04 func_02051C88(struct Ctx *c);
extern void func_021C1CD4(void *);
extern int func_021C1C10(void *);
extern void func_021C19DC(char *, int);
BOOL func_021C1A44(char *p);
void func_021C1A58(char *p, int a, int heap);
void func_021C1AC0(char *p);
u8 func_021C1B04(char *p, int heap);
extern const int d_021C377C[];


/*
 * True when the word 0x8C8 bytes into the block is set.
 */
BOOL func_021C1A44(char *p)
{
    if (((struct Obj18281 *)p)->f8C8 != 0) {
        return 1;
    }

    return 0;
}

void func_021C1A58(char *p, int a, int heap)
{
    func_02082BCC(p + 0x8b0, 0, 0xf4);
    func_02043598(7, 1);
    func_02043598(8, 0);
    ((struct Obj10212 *)p)->f8C8 = func_02051B84((u8 *)d_021C377C, (int)func_021C1C9C, (int)p, heap);
    ((struct Obj10212 *)p)->f8B0 = func_0201EC64((u16)heap);
    func_021C1D1C((u8 *)p, (void *)a, heap);
    ((struct Obj10212 *)p)->f8F4 = 1;
    func_021C208C(p);
    func_021C2090(p);
}

void func_021C1AC0(char *p)
{
    if (func_021C1A44(p)) {
        func_021C1F74(p);
        func_02051C6C(((struct Obj00008 *)p)->f8C8);
        ((struct Obj00008 *)p)->f8C8 = 0;
        func_0201ED04(((struct Obj00008 *)p)->f8B0);
        ((struct Obj00008 *)p)->f8B0 = 0;
        func_02043598(1, 1);
        func_02043598(14, 0);
    }
}

/*
 * lever: byte addition of 254 emits adds #0xfe; subtraction emits subs #2.
 * prototype: B9800/B984C leave their C4864 result live; this caller reads r0.
 */
u8 func_021C1B04(char *p, int heap)
{
    u32_021C1B04 first, second;
    first = func_021B9800(p + 0x274);
    second = func_021B984C(p + 0x274);
    if (second >= 3 && second <= 6) first = second;
    if (first >= 3 && first <= 6 && ((struct Obj00008 *)p)->f8EC != first - 3) {
        ((struct Obj00008 *)p)->f8EC = first - 3;
        func_021C208C(p);
        ((struct Obj00008 *)p)->f8F1 = 1;
        ((struct Obj00008 *)p)->f8F4 = 1;
    }
    if (((struct Obj00008 *)p)->f8EF == 1) {
        ((struct Obj00008 *)p)->f8EF = 2;
        func_021BB2F0(p, heap);
    }
    if (((struct Obj00008 *)p)->f8EF == 0) {
        func_021BB42C(p);
        func_021BB4D0(p);
        func_021BB4EC(p);
        func_02051C88(((struct Obj00008 *)p)->f8C8);
        func_021C1CD4(p);
        if (((struct Obj00008 *)p)->f8F1 == 1) {
            func_021C2090(p);
            ((struct Obj00008 *)p)->f8F1 = 0;
        }
    }
    if ((u8)(((struct Obj00008 *)p)->f8EF + 254) <= 1 && func_021C1C10(p) == 1) {
        ((struct Obj00008 *)p)->f8ED = 0;
        ((struct Obj00008 *)p)->f8EE = 0;
        ((struct Obj00008 *)p)->f8F1 = 1;
        ((struct Obj00008 *)p)->f8F4 = 1;
        func_021C19DC(p, heap);
        ((struct Obj00008 *)p)->f8EF = 0;
        ((struct Obj00008 *)p)->f8F4 = 1;
    }
    return ((struct Obj00008 *)p)->f8ED;
}
