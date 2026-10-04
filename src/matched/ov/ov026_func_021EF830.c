/*
 * function: func_021EF830
 * address:  0x021EF830
 * packet:   pkt_ov026_021EF830
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF830  0x021EF830  thumb  ov026
 *   func_021A244C  0x021A244C  thumb  ov021
 *   func_021A2564  0x021A2564  thumb  ov021
 *   func_021A2190  0x021A2190  thumb  ov021
 *   func_021A21A0  0x021A21A0  thumb  ov021
 *   func_021A2170  0x021A2170  thumb  ov021
 *   func_021A2180  0x021A2180  thumb  ov021
 */
#include "../include/Obj00086.h"

typedef signed short s16;

typedef signed int     s32;
typedef unsigned char  u8;
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern void func_021A2190(unsigned char *o, unsigned int v, int i);
extern void func_021A21A0(unsigned char *o, unsigned int v, int i);
extern void func_021A2170(unsigned char *o, unsigned int v, int i);
extern void func_021A2180(unsigned char *o, unsigned int v, int i);

void func_021EF830(int a, s16 *p)
{
    int x;
    int y;

    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    if (p[11] != 0) {
        p[2] = (p[2] + 9) % 256;
        p[3] = (p[3] + 3) % 256;
        p[4] = (p[4] + 9) % 256;
        p[5] = (p[5] + 2) % 256;
    } else {
        p[2] = (p[2] + 3) % 256;
        p[3] = (p[3] + 8) % 256;
    }
    func_021A2190((unsigned char *)a, -(p[2] + x), 0);
    func_021A21A0((unsigned char *)a, y - p[3], 0);
    func_021A2190((unsigned char *)a, -(p[4] + x), 1);
    func_021A21A0((unsigned char *)a, y - p[5], 1);
    func_021A2170((unsigned char *)a, ((struct Obj00086 *)p)->f1C, 1);
    func_021A2180((unsigned char *)a, ((struct Obj00086 *)p)->f1C, 1);
}
