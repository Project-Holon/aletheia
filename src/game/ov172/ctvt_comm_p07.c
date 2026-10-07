/*
 * file:     ctvt_comm_p07.c
 * unit:     yes
 * function: func_021B85D0, func_021B8614, func_021B8628
 * address:  0x021B85D0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021BE0D8 0x021BE0D8 thumb ov172
 *   func_021BE2F0 0x021BE2F0 thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   func_0203EA70 0x0203EA70 arm
 *   func_021B7724 0x021B7724 thumb ov172
 *   func_021B7830 0x021B7830 thumb ov172
 *   func_021B77B8 0x021B77B8 thumb ov172
 *   func_021B77E8 0x021B77E8 thumb ov172
 *   func_0203E96C 0x0203E96C arm
 *   func_0203E9DC 0x0203E9DC arm
 *   func_021BFFC4 0x021BFFC4 arm ov172
 *   func_021B7714 0x021B7714 thumb ov172
 */
#include "../../matched/include/Obj04551.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern u32 func_021BDFDC(void *p);
extern int func_021BE0D8(void *p);
extern void func_021BE2F0(u32 *p, void *q);
extern u32 func_021B8740(int a, int b, u8 c, u32 d);
extern int func_0203EA70(unsigned int idx);
extern void func_021B7724(void *a, char *b, int c);
extern int func_021B7830(void *a0, char *a1, int a2);
extern u32 func_021B77B8(void *p, char *q);
extern u32 func_021B77E8(void *p, char *q);
extern int func_0203E96C(unsigned int idx);
extern int func_0203E9DC(unsigned int idx);
extern int func_021BFFC4(unsigned char *data, unsigned long size, void *dst,
                         short *width, short *height, unsigned long option);
extern void func_021B7714(void *a, char *b, int c);
int func_021B85D0(unsigned char *p, unsigned char *q);
void func_021B8614(int unused, int unused2, void *p);
void func_021B8628(void *a, int b, int *t, int c);


/*
 * True when one of three 6-byte records at +0x22 matches the probe string.
 *
 * Addresses are Black-image addresses.
 */
int func_021B85D0(unsigned char *p, unsigned char *q)
{
    unsigned char i;

    for (i = 0; i < 3; i++) {
        unsigned char j;
        int ok = 1;

        for (j = 0; j < 6; j++) {
            if (p[i * 6 + j + 0x22] != q[j]) {
                ok = 0;
                break;
            }
        }
        if (ok == 1) {
            return 1;
        }
    }
    return 0;
}


void func_021B8614(int unused, int unused2, void *p)
{
    ((struct Obj04551 *)p)->fC = 0;
    ((struct Obj04551 *)p)->f0 = 0;
    ((struct Obj04551 *)p)->f4 = 0;
    ((struct Obj04551 *)p)->f8 = 0;
    ((struct Obj04551 *)p)->f10 = 0;
    ((struct Obj04551 *)p)->f14 = 0xff;
    ((struct Obj04551 *)p)->f18 = 0;
}

void func_021B8628(void *a, int b, int *t, int c)
{
    char *r;
    int x, data;
    short dims[2];
    r = (char *)func_021BDFDC(a);
    if (t[0] != 0 && t[3] != 1) {
        if (t[2] == 0 && t[1] == 1) {
            if (func_021BE0D8(a) == 0)
                func_021BE2F0((u32 *)a, t + 7);
            t[2] = 1;
        }
        switch (t[6]) {
        case 0:
        case 4:
            break;
        case 1:
            if (func_021B8740((int)a, b, 0, 0) == 1)
                t[6] = 2;
            break;
        case 2:
            if (func_0203EA70(c) == 0) {
                func_021B7724(a, r, c);
                t[6] = 3;
            }
            break;
        case 3:
            if (func_0203EA70(c) == 1) {
                x = func_021B7830(a, r, c);
                dims[1] = func_021B77B8(a, r);
                dims[0] = func_021B77E8(a, r);
                data = func_0203E96C(c);
                func_021BFFC4((unsigned char *)data, func_0203E9DC(c), (void *)x, &dims[1], &dims[0], 0);
                func_021B7714(a, r, c);
                t[6] = 1;
            }
            break;
        }
    }
}
