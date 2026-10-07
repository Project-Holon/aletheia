/*
 * file:     gtsnego_disp_p05.c
 * unit:     yes
 * function: func_021D4808, func_021D4864
 * address:  0x021D4808
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4584 0x021D4584 thumb ov120
 *   func_021D47D4 0x021D47D4 thumb ov120
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_020399EC 0x020399EC arm
 *   func_02039C68 0x02039C68 arm
 *   func_02009EA8 0x02009EA8 thumb
 */
#include "../../matched/include/Obj22827.h"
#include "../../matched/include/Obj02831.h"
#include "../../matched/include/Obj13929.h"

struct Entry;
struct Link;
struct Rec0200E6FC;
struct Sub02009D9CObj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern int func_0203CD98(void);
extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4584(u8 *p);
extern void func_021D47D4(u8 *p);
extern int func_021D7AF4(char *p);
extern int func_020399EC(void);
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
extern void *func_0200E6E8(u32 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void *func_02012F14(void **h);
extern u32 func_02009EA8(const struct Sub02009D9CObj *obj);
void func_021D4808(int *a);
void func_021D4864(u8 *p);

void func_021D4808(int *a)
{
    if (func_0203CD98() == 0) {
        func_021D4244(a, (int)((void (*)(int))func_021D4584), 0x2df);
        return;
    }
    if (func_02039CB4((struct Link *)func_020399A8(), 2, 0x22) != 0) {
        if (func_0203D3A8(func_020399A8(), 0x2200, 8, (u32)(*(char * *)&((struct Obj22827 *)a)->f48 + 4)) != 0)
            func_021D4244(a, (int)((void (*)(int))func_021D47D4), 0x2e7);
    }
}

void func_021D4864(u8 *p)
{
    u8 *q;
    int value;
    if (func_021D7AF4((char *)(((struct Obj02831 *)p)->f40))) {
        if (func_0203CD98() == 0) {
            func_021D4244((int *)p, (int)func_021D4808, 0x2fe);
            return;
        }
        if (((struct Obj02831 *)p)->f14 > 0) {
            ((struct Obj02831 *)p)->f14 = ((struct Obj02831 *)p)->f14 - 1;
            return;
        }
        if (func_020399EC() == 2) {
            q = *(u8 * *)&((struct Obj02831 *)p)->f48;
            value = (int)func_0200E6E8(((struct Obj02831 *)p)->f30);
            ((struct Obj13929 *)q)->f4 = ((struct Obj02831 *)p)->f144;
            ((struct Obj13929 *)q)->f8 = ((struct Obj02831 *)p)->f13C;
            func_0200E6FC((struct Rec0200E6FC *)value, 0, (struct Rec0200E6FC *)(p + 0x168));
            ((struct Obj02831 *)p)->f170 = func_02009EA8(func_02012F14((void **)(((struct Obj02831 *)p)->f2C)));
            func_02039C68((struct Link *)func_020399A8(), 2, 0x22);
            func_021D4244((int *)p, (int)func_021D4808, 0x314);
        }
    }
}
