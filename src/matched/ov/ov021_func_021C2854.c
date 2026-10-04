/*
 * function: func_021C2854
 * address:  0x021C2854
 * packet:   pkt_ov021_021C2854
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006984  0x02006984  thumb
 *   func_02006650  0x02006650  thumb
 *   func_02006B20  0x02006B20  thumb
 *   func_02006A8C  0x02006A8C  thumb
 *   func_020065D8  0x020065D8  thumb
 */
#include "../include/Obj01214.h"
#include "../include/Obj09680.h"

typedef unsigned short u16;

void func_02006CAC(char *a);
int func_02006984(int a, int b, int c, int d, int e, int f, int g, char *h);
int func_02006650(void);
typedef signed char    s8;
typedef unsigned int   u32;
s8 func_02006B20(u32 i);
void func_02006A8C(u32 idx, int delta);
void func_020065D8(void);

int func_021C2854(int a, char *b)
{
    int r;
    char *q;
    char buf[4];

    q = b + 0x9c;
    if (((struct Obj01214 *)q)->f14 != 0 && ((struct Obj01214 *)q)->f18 != 0) {
        (((struct Obj01214 *)q)->f18)--;
        if (((struct Obj01214 *)q)->f18 == 0) {
            if (((struct Obj01214 *)q)->f0 == 0x1b9) {
                func_02006CAC(buf);
                ((struct Obj01214 *)q)->f1C = func_02006984(((struct Obj01214 *)q)->f0, ((struct Obj01214 *)q)->f4, 0x40, 0, 0, 0, 0, buf);
            } else {
                ((struct Obj01214 *)q)->f1C = func_02006984(((struct Obj01214 *)q)->f0, ((struct Obj01214 *)q)->f4, 0x40, 0, 0, 0, 0, 0);
            }
        }
        ((struct Obj01214 *)q)->f1A = 0x1e;
        return 0;
    }
    r = 0;
    if (((struct Obj01214 *)q)->f18 == 0) {
        if (func_02006650() == 0) {
            r = 1;
        } else if (((struct Obj01214 *)q)->f1A != 0) {
            (((struct Obj01214 *)q)->f1A)--;
        } else if (func_02006B20(((struct Obj01214 *)q)->f1C) > 0) {
            func_02006A8C(((struct Obj01214 *)q)->f1C, r - 16);
        } else {
            func_020065D8();
            r = 1;
        }
    }
    if (((struct Obj09680 *)b)->f11C != 0 && ((struct Obj09680 *)b)->f120 != 0 && ((struct Obj09680 *)b)->f124 != 0 && r != 0)
        return 1;
    return 0;
}
