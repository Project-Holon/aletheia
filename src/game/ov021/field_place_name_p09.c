/*
 * file:     field_place_name_p09.c
 * unit:     yes
 * function: func_021BCB9C, func_021BCBC8, func_021BCC3C
 * address:  0x021BCB9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BD0A0  0x021BD0A0  thumb  ov021
 *   func_021BD0A8  0x021BD0A8  thumb  ov021
 *   func_021BD0C8  0x021BD0C8  thumb  ov021
 *   func_02040588  0x02040588  arm
 *   func_021BC92C  0x021BC92C  thumb  ov021
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   _fsub          0x0209CB8C  arm
 *   func_021BCA88  0x021BCA88  thumb  ov021
 *   func_021BCA6C  0x021BCA6C  thumb  ov021
 *   func_021BCA74  0x021BCA74  thumb  ov021
 *   func_021BCA8C  0x021BCA8C  thumb  ov021
 *   func_021BCA80  0x021BCA80  thumb  ov021
 */
#include "../../matched/include/Obj05061.h"

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

void func_021BD0A0(void *p, int v);
void func_021BD0A8(char *p);
void func_021BD0C8(char *p);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021BC92C(void *p);
extern u32 func_021BCA88(u8 *p);
extern u8 *func_021BCA6C(u8 *p);
extern u32 func_021BCA74(u8 *p);
extern int func_021BCA8C(void *p);
extern void func_021BCA80(u8 *p);
void func_021BCB9C(void *p, int keep);
void func_021BCBC8(char *p);
void func_021BCC3C(void *p);


void func_021BCB9C(void *p, int keep)
{
    func_021BD0A0(p, keep);
    func_021BD0A8(p);
    func_021BD0C8(p);
    if (keep == 0) {
        func_02040588(3, 0);
        func_021BC92C(p);
    }
}


void func_021BCBC8(char *p)
{
    int r6;
    int r5;

    switch (((struct Obj05061 *)p)->f3C) {
    case 0:
    case 4:
    case 6:
        return;
    case 3:
    case 5:
        r6 = 5;
        r5 = 30;
        break;
    case 2:
        r6 = 6;
        r5 = (int)(20.0f * (1.0f - (float)(u32)((struct Obj05061 *)p)->f42 / 10.0f));
        break;
    case 1:
        r6 = 0;
        r5 = 0;
        break;
    }
    func_021BCB9C(p, r6);
    ((struct Obj05061 *)p)->f42 = r5;
}


void func_021BCC3C(void *p)
{
    int r = 0;

    if (func_021BCA88(p)) {
        r = 1;
        func_021BCA6C(p);
    } else if (func_021BCA74(p)) {
        if (func_021BCA8C(p)) {
            r = 1;
        }
        func_021BCA80(p);
    }
    if (r) {
        func_021BCB9C(p, 1);
    }
}
