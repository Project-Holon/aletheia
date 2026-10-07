/*
 * function: func_021C5098
 * address:  0x021C5098
 * packet:   pkt_ov093_021C5098
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8640  0x021B8640  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B902C  0x021B902C  thumb  ov093
 *   func_021C50F8  0x021C50F8  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */
#include "../../../matched/include/Obj07755.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern unsigned int func_021B8640(unsigned int **p);
extern u8 func_021B8FF4(u8 *m);
extern u8 func_021B8DE4(char *p, int i);
extern int func_021B902C(int a, int b);
extern u8 func_021C50F8(u8 *q, u8 i);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D59B4(u8 *p, int k);

u32 func_021C5098(u8 *p)
{
    u32 best = 1;
    u32 n = func_021B8640((unsigned int **)(*(u8 * *)&((struct Obj07755 *)p)->f4));
    u8 x = func_021B8FF4(*(u8 * *)&((struct Obj07755 *)p)->f4);
    u32 i;
    for (i = 0; i <= n; i++) {
        if (func_021B902C(x, func_021B8DE4((char *)(*(u8 * *)&((struct Obj07755 *)p)->f4), (u8)i)) == 0) {
            int r = func_021C50F8(p + 0x1AB8, i);
            if (r != 0x1f) {
                u32 t = func_021D59B4((u8 *)func_021B9934(*(char * *)&((struct Obj07755 *)p)->f8, r), 0xf);
                if (t > best) {
                    best = t;
                }
            }
        }
    }
    return best;
}
