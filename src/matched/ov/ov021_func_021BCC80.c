/*
 * function: func_021BCC80
 * address:  0x021BCC80
 * packet:   pkt_ov021_021BCC80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BD0C0  0x021BD0C0  thumb  ov021
 *   func_021BCAB0  0x021BCAB0  thumb  ov021
 *   func_021BD0D0  0x021BD0D0  thumb  ov021
 *   func_020414C4  0x020414C4  arm
 *   func_020414EC  0x020414EC  arm
 *   func_021BC6D0  0x021BC6D0  thumb  ov021
 *   func_021BC720  0x021BC720  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_021BC838  0x021BC838  thumb  ov021
 *   func_021BC848  0x021BC848  thumb  ov021
 *   func_021BC910  0x021BC910  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 */
#include "../include/Obj00183.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 func_021BD0C0(u8 *p);
extern void func_021BCAB0(int *p);
extern void func_021BD0D0(char *p);
extern void func_020414C4(u32 idx);
extern void func_020414EC(u32 i);
extern void func_021BC6D0(char *p);
extern void func_021BC720(char *p);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern unsigned char func_02045730(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(int, int, int, int, int);
extern void func_021BC838(char *p);
extern void func_021BC848(char *p);
extern int func_021BC910(char *p);
extern void func_021BCB9C(void *p, int keep);

void func_021BCC80(char *p)
{
    u32 w;

    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        func_021BCAB0((int *)p);
        func_021BD0D0(p);
        break;
    case 1:
        func_020414C4(3);
        func_020414EC(3);
        func_021BC6D0(p);
        func_021BD0D0(p);
        break;
    case 2:
        func_021BC720(p);
        w = *(u32 *)&((struct Obj00183 *)p)->f24;
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        func_0204047C(3, 1);
        func_02040588(3, 0);
        func_0207D63C(0x04000050, 8, 0x11, 0x10, 4);
        func_021BC838(p);
        func_021BD0D0(p);
        break;
    case 3:
        func_021BC848(p);
        if (func_021BC910(p)) {
            func_021BCB9C(p, 2);
        }
        break;
    }
}
