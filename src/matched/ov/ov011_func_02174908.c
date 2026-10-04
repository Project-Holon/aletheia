/*
 * function: func_02174908
 * address:  0x02174908
 * packet:   pkt_ov011_02174908
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D9C  0x02013D9C  thumb
 */
#include "../include/Obj09346.h"

typedef unsigned int   u32;
struct SaveBlock;
u32 func_02026478(void *obj);
typedef unsigned short u16;
struct Entry;
struct Rec44;
struct Entry *func_020399A8(void);
unsigned int func_0203D1A4(void *p);
void *func_020127A4(struct SaveBlock *p);
u16 func_02012AC8(const struct Rec44 *p);
unsigned int func_02013D9C(unsigned int id);

void func_02174908(int a, int b, int c, unsigned char *d)
{
    int h;

    h = func_02026478((void *)(((struct Obj09346 *)d)->f4));
    if (a != func_0203D1A4(func_020399A8()) && ((unsigned)(((struct Obj09346 *)d)->f86 << 29) >> 29) == a) {
        if (func_02013D9C(func_02012AC8(func_020127A4((struct SaveBlock *)h))) != 0) {
            d[0x8F8] |= 4;
        }
    }
}
