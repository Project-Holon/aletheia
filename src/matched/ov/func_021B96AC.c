/*
 * function: func_021B96AC
 * address:  0x021B96AC
 * packet:   pkt_021B96AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B87FC  0x021B87FC  thumb
 *   func_021B87D8  0x021B87D8  thumb
 *   func_021B93D4  0x021B93D4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09187.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *func_021B87FC(u8 *p, u32 idx);
u8 *func_021B87D8(u8 *p, u32 idx);
int func_021B93D4(int dir);

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
