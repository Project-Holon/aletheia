/*
 * file:     field_nogrid_mapper_p05.c
 * unit:     yes
 * function: func_021B963C, func_021B96AC, func_021B9768
 * address:  0x021B963C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B87D8  0x021B87D8  thumb
 *   func_021B960C  0x021B960C  thumb
 *   func_021B93D4  0x021B93D4  thumb
 *   func_021B87FC  0x021B87FC  thumb
 */
#include "../../matched/include/Obj02052.h"
#include "../../matched/include/Obj09187.h"

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

u8 *func_021B87D8(u8 *p, u32 idx);
u32 func_021B960C(u32 *p, u8 *v, u8 *q);
int func_021B93D4(int dir);
u8 *func_021B87FC(u8 *p, u32 idx);
int func_021B963C(u8 *a, u8 *b);
int func_021B96AC(u8 *a, u8 *b);
void func_021B9768(void *a, void *b);


int func_021B963C(u8 *a, u8 *b)
{
    u8 *row1, *row2;
    u32 r1, r2;

    if (((struct Obj02052 *)a)->f0 == 0xFFFF || ((struct Obj02052 *)a)->f4 == 0xFFFF)
        return 0;
    row1 = func_021B87D8(b, ((struct Obj02052 *)a)->f0);
    row2 = func_021B87D8(b, ((struct Obj02052 *)a)->f4);
    r1 = func_021B960C((u32 *)row1, a, b);
    if (r1 == 0)
        return 0;
    if (r1 != ((struct Obj02052 *)a)->f8)
        return 0;
    r2 = func_021B960C((u32 *)row2, a, b);
    if (r2 == 0)
        return 0;
    if (r2 != (u32)func_021B93D4(((struct Obj02052 *)a)->f8))
        return 0;
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021B96AC(u8 *a, u8 *b)
{
    int i, j;

    for (i = 0; i < 4; i++) {
        u32 val = *(u32 *)(a + i * 4 + 0x10);
        u32 key = *(u32 *)(a + i * 4);
        u8 *row;
        u8 *r4;
        u8 *r0;

        if ((val == 0) != (key == 0xFFFF))
            return 0;
        if (key == 0xFFFF)
            continue;
        row = func_021B87FC(b, key);
        r4 = func_021B87D8(b, ((struct Obj09187 *)row)->f0);
        r0 = func_021B87D8(b, ((struct Obj09187 *)row)->f4);
        if (r4 != a && r0 != a)
            return 0;
        if (*(u32 *)(a + i * 4 + 0x10) == 0)
            continue;
        for (j = i + 1; j < 4; j++) {
            if (*(u32 *)(a + i * 4 + 0x10) == (u32)func_021B93D4(*(u32 *)(a + j * 4 + 0x10))) {
                if (((struct Obj09187 *)row)->f8 != *(u32 *)(func_021B87FC(b, *(u32 *)(a + j * 4)) + 8))
                    return 0;
            }
        }
    }
    return 1;
}


void func_021B9768(void *a, void *b)
{
}
