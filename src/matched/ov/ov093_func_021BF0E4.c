/*
 * function: func_021BF0E4
 * address:  0x021BF0E4
 * packet:   pkt_ov093_021BF0E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BF138  0x021BF138  thumb  ov093
 *   func_021BF148  0x021BF148  thumb  ov093
 *   func_021BF158  0x021BF158  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 */
#include "../include/Obj21056.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021BF138(int c);
extern u8 *func_021BF148(int c, int k);
extern void func_021BF158(int c, u8 *x);
extern u8 func_021D5440(u8 *p);
extern int func_021D5BB0(void *q, u32 n);

void func_021BF0E4(int u, u8 *b, int c, u8 *d, int e)
{
    u8 *x;
    if (func_021BF138(c) == 1) {
        x = func_021BF148(c, 0);
        if (x != 0) {
            if (func_021D5440(x) == func_021D5440(b)) {
                if (((struct Obj21056 *)d)->fC != 7) {
                    if (func_021D5BB0(b, 12) != 0 || e != 0)
                        func_021BF158(c, x);
                }
            }
        }
    }
}
