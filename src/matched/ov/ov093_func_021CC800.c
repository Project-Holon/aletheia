/*
 * function: func_021CC800
 * address:  0x021CC800
 * packet:   pkt_ov093_021CC800
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8B9C  0x021B8B9C  thumb  ov093
 *   func_021B8BC4  0x021B8BC4  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 */
#include "../include/Obj09984.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern u8 func_021B8BC4(void *p, u8 k);
extern char *func_021B9AEC(char *p, int i);
struct Q1;
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(void *p, u32 i);
extern int func_021D59B4(u8 *p, int k);
extern u32 _u32_div_f(u32, u32);

void func_021CC800(u8 *a, u32 *out1, u32 *out2, u8 want)
{
    u32 sum;
    u32 j;
    u32 i;
    char *p;
    u32 n;
    u8 *t;

    sum = 0;
    *out1 = 0;
    *out2 = 0;
    for (j = 0; j < 4; j++) {
        if (func_021B8B9C(((struct Obj09984 *)a)->f4, j) != 0 &&
            want == func_021B8BC4(((struct Obj09984 *)a)->f4, j)) {
            p = func_021B9AEC(((struct Obj09984 *)a)->f8, j);
            n = func_021B9B94((struct Q1 *)p);
            for (i = 0; i < n; i++) {
                t = func_021B9C00(p, (u8)i);
                sum += func_021D59B4(t, 14);
                *out1 += func_021D59B4(t, 13);
            }
        }
    }
    *out2 = _u32_div_f(*out1 * 100, sum);
}
