/*
 * file:     field_place_name_p11.c
 * unit:     yes
 * function: func_021BCD84, func_021BCDD8, func_021BCE88, func_021BCEAC, func_021BCEB0, func_021BCEB4, func_021BCF18
 * address:  0x021BCD84
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
 *   func_021BD0C0  0x021BD0C0  thumb  ov021
 *   func_021BD0D0  0x021BD0D0  thumb  ov021
 *   func_021BC948  0x021BC948  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 *   func_021BD20C  0x021BD20C  thumb  ov021
 *   func_021BC9C0  0x021BC9C0  thumb  ov021
 *   func_021BC9CC  0x021BC9CC  thumb  ov021
 *   func_021BCA48  0x021BCA48  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_021BC92C  0x021BC92C  thumb  ov021
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   _fsub          0x0209CB8C  arm
 *   _fadd          0x0209C95C  arm
 */
#include "../../matched/include/Obj01123.h"
#include "../../matched/include/Obj20118.h"

struct Descriptor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u8 func_021BD0C0(u8 *p);
extern void func_021BD0D0(char *p);
extern void func_021BC948(char *p);
extern void func_021BCB9C(void *p, int keep);
extern unsigned int func_021BD20C(char *p);
extern void func_021BC9C0(char *p);
extern void func_021BC9CC(char *p);
extern int func_021BCA48(char *p);
extern void func_02045334(struct Descriptor *d);
extern void func_021BC92C(char *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(int, int, int, int, int);
void func_021BCD84(char *p);
void func_021BCDD8(char *p);
void func_021BCE88(char *p);
void func_021BCEAC(int a);
void func_021BCEB0(int a);
void func_021BCEB4(char *p);
void func_021BCF18(int a);


void func_021BCD84(char *p)
{
    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        p[0x149] = 0;
        func_021BD0D0(p);
        break;
    case 1:
        if (((struct Obj01123 *)p)->f42 % 3 == 0) {
            func_021BC948(p);
            if (((struct Obj01123 *)p)->f20 <= ((struct Obj01123 *)p)->f149) {
                func_021BCB9C(p, 5);
            }
        }
        break;
    }
}


void func_021BCDD8(char *p)
{
    int r6 = 1;
    int i;

    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        for (i = 0; i < ((struct Obj01123 *)p)->f20; i++) {
            u32 v = *(u32 *)(p + 0xc8 + i * 4);
            if (v != 0 && func_021BD20C((char *)v) != 0) {
                r6 = 0;
                break;
            }
        }
        if (r6 != 0) {
            func_021BC9C0(p);
            func_021BD0D0(p);
        }
        break;
    case 1:
        func_021BC9CC(p);
        if (func_021BCA48(p) != 0) {
            func_021BD0D0(p);
        }
        break;
    case 2:
        func_02045334((struct Descriptor *)((struct Obj01123 *)p)->f24);
        func_021BD0D0(p);
        break;
    case 3:
        func_021BC92C(p);
        func_021BD0D0(p);
        break;
    case 4:
        if (((struct Obj01123 *)p)->f42 > 0x1e) {
            func_021BCB9C(p, 6);
        }
        break;
    }
}


void func_021BCE88(char *p)
{
    if (((struct Obj01123 *)p)->f42 > 0x14) {
        func_021BCB9C(p, 0);
        func_02040588(3, 0);
        func_021BC92C(p);
    }
}

void func_021BCEAC(int a)
{
}

/*
 * Unlabelled leaf (bx lr stub) filed as the blocker of func_021BC4F0.
 */
void func_021BCEB0(int a)
{
}


void func_021BCEB4(char *p)
{
    float t;
    int a;

    t = (float)(u32)((struct Obj20118 *)p)->f42 / 10.0f;
    a = (int)(16.0f * t);
    func_0207D63C(0x04000050, 8, 0x11, a, (int)(4.0f + 12.0f * (1.0f - t)));
}

void func_021BCF18(int a)
{
}
