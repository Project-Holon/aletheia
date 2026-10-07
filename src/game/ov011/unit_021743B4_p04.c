/*
 * file:     unit_021743B4_p04.c
 * unit:     yes
 * function: func_021748CC, func_02174908, func_02174954
 * address:  0x021748CC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_02026478  0x02026478  thumb
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_0203D3A8 0x0203D3A8 arm
 */
#include "../../matched/include/Obj09346.h"

struct Entry;
struct SaveBlock;
struct Rec44;
struct Link;
typedef unsigned int u32;

typedef unsigned short u16;

int func_021736D8(void);
struct Entry *func_020399A8(void);
u32 func_0203D3F8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_02026478(void *obj);
u32 func_0203D1A4(struct Link *p);
void *func_020127A4(struct SaveBlock *p);
u16 func_02012AC8(const struct Rec44 *p);
unsigned int func_02013D9C(unsigned int id);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
int func_021748CC(char *p, int a);
void func_02174908(int a, int b, int c, unsigned char *d);
u32 func_02174954(u32 p);

int func_021748CC(char *p, int a)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), a, 0x229, 0x54, (u32)(p + 0x880), 0, 0, 0);
}


void func_02174908(int a, int b, int c, unsigned char *d)
{
    int h;

    h = func_02026478((void *)(((struct Obj09346 *)d)->f4));
    if (a != func_0203D1A4((struct Link *)func_020399A8()) && ((unsigned)(((struct Obj09346 *)d)->f86 << 29) >> 29) == a) {
        if (func_02013D9C(func_02012AC8(func_020127A4((struct SaveBlock *)h))) != 0) {
            d[0x8F8] |= 4;
        }
    }
}

/*
 * lever: caller consumes the live r0 result of legacy void forwarders.
 */
u32 func_02174954(u32 p)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3A8((struct Entry *)((u32)func_020399A8()), 0x22a, 4, p);
}
