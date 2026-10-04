/*
 * function: func_021D0AE4
 * address:  0x021D0AE4
 * packet:   pkt_ov021_021D0AE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   func_02168878  0x02168878  thumb  ov010
 */
#include "../include/Obj13002.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 func_020056EC(u32 range);
extern void func_02168878(void *p, u16 a, int b, int c, int d, int e, u16 f);

void func_021D0AE4(char *p, int mode)
{
    int a;
    int b;
    int s;
    u16 v;

    switch (mode) {
    case 0:
        a = 0x32;
        b = 0x14;
        break;
    case 1:
        a = 0x6E;
        b = 0x32;
        break;
    case 2:
        a = 0xA0;
        b = 0x14;
        break;
    case 3:
        a = 0xF0;
        b = 0x1E;
        break;
    case 4:
        a = 0x10E;
        b = 0x1E;
        break;
    default:
        a = 0x32;
        b = 0x14;
        break;
    }
    s = a + func_020056EC(b);
    v = ((struct Obj13002 *)p)->f120;
    func_02168878(p, s, ((struct Obj13002 *)p)->f124, 0, 0, 0, (v & 0x7FFF) | 0x8000);
}
