/*
 * file:     colosseum_p02.c
 * unit:     yes
 * function: func_02174D10, func_02174D2C, func_02174D64, func_02174D98
 * address:  0x02174D10
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
 *   func_021750C8 0x021750C8 thumb ov012
 *   func_021750C0 0x021750C0 thumb ov012
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_02082D44 0x02082D44 arm
 *   func_0201A918 0x0201A918 thumb
 */
#include "../../matched/include/Obj19286.h"
#include "../../matched/include/Obj19287.h"
#include "../../matched/include/Obj19288.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_021750C8(u8 *p, int v);
extern u8 func_021750C0(char *);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
extern void func_02082D44(void *,void *,u32);
extern int func_0201A918(void);
void func_02174D10(u32 a, u32 b, u32 *c, u8 *d);
int func_02174D2C(char *a, u32 b, u32 c);
void func_02174D64(u32 a, u32 b, void *c, u8 *d);
u32 func_02174D98(u32 p);

void func_02174D10(u32 a, u32 b, u32 *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19286 *)d)->f355C;
    if (w == 0 || ((struct Obj19287 *)w)->f0 == 0) return;
    func_021750C8(w, *c);
}

/*
 * lever: The address-taken payload is the third parameter: sp+0x20
 *        after the 16-byte home area, 8-byte save and 16-byte call frame.
 *        Taking the first parameter's address added a reload and gave DIFF.
 */
int func_02174D2C(char *a, u32 b, u32 c)
{
    func_021750C0(a);
    return func_0203D3F8((u32)func_020399A8(),(u8)b,0x1505,4,(u32)&c,1,0,0);
}

/*
 * lever: (w+a)[0x158] preserves the base-plus-index store address;
 *        w[a+0x158] produced an 8-byte concrete scheduling/addressing DIFF.
 */
void func_02174D64(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19288 *)d)->f355C;
    if (w == 0) return;
    if (*(void **)(w + a * 4 + 0x148) == 0) return;
    func_02082D44(c, *(void **)(w + a * 4 + 0x148), b);
    (w + a)[0x158] = 1;
}

/*
 * Caller consumes 020399A8's live r0 despite its filed void return.
 */
u32 func_02174D98(u32 p)
{
    u32 a = (u32)func_020399A8();
    return func_0203D3F8(a,255,0x1506,func_0201A918(),p,1,0,1);
}
