/*
 * function: func_021AF30C
 * address: 0x021AF30C
 * packet: pkt_ov013_021AF30C
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B3C80 0x021B3C80 data ov013 a4
 *   func_021B074C 0x021B074C arm ov013
 *   func_021B0614 0x021B0614 arm ov013
 */

#include "../../../matched/include/G_Work.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern struct Work *d_021B3C80;
extern void func_021B074C(void *);
extern int func_021B0614(void *);
void func_021AF30C(int a)
{
    if (((u8 *)d_021B3C80) != 0) {
        *(u16 *)(((u8 *)d_021B3C80) + 0x19B2) = a;
        if (*(void **)(((u8 *)d_021B3C80) + 0x1A1C) != 0) {
            if (a != 0) func_021B074C(*(void **)(((u8 *)d_021B3C80) + 0x1A1C));
            else func_021B0614(*(void **)(((u8 *)d_021B3C80) + 0x1A1C));
        }
    }
}
