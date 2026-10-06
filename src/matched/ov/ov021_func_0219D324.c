/*
 * function: func_0219D324
 * address:  0x0219D324
 * packet:   pkt_ov021_0219D324
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0219C880  0x0219C880  thumb  ov021
 *   func_02050468  0x02050468  arm
 */
#include "../include/Obj02700.h"

extern int func_0216DA30(int a0, int a1);
typedef unsigned short u16;
typedef unsigned int   u32;
struct BbActSys;
extern int func_0216D7A8(void *p, unsigned int v);
extern u16 func_0216D598(void *p);
typedef unsigned char  u8;
extern void func_0219C880(u8 *o, u32 a, u32 b, u32 c);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);

void func_0219D324(int *obj, int *rec)
{
    int h;
    unsigned int n;

    h = rec[0];
    if (func_0216DA30(h, (int)rec) == 0) {
        func_0219C880((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, *((unsigned short *)(rec + 1) + 1));
        func_02050468((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
        return;
    }
    if ((unsigned short)func_0216D7A8((void *)h, 0) != 0xFFFF) {
        n = *((unsigned short *)(rec + 1) + 1);
        if (n != func_0216D598((void *)h)) {
            func_0219C880((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, n);
        }
        func_02050468((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
    }
}
