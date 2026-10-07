/*
 * file:     pokemontrade_3d_p10.c
 * unit:     yes
 * function: func_021E37D8, func_021E380C, func_021E3838
 * address:  0x021E37D8
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E3758  0x021E3758  thumb  ov119
 *   func_0207F7A0 0x0207F7A0 arm
 *   func_02030734 0x02030734 arm
 *   d_021E81C0 0x021E81C0 data ov119 a4
 *   func_02082BCC 0x02082BCC arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207F7FC 0x0207F7FC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0207F9B4 0x0207F9B4 arm
 *   func_021E3B2C 0x021E3B2C thumb ov119
 */
#include "../../matched/include/Obj10376.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021E3758(u16 *p, int x, int y, int colour);
extern void func_0207F7A0(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, int);
extern void func_020862F0(void *, int);
extern void func_0207F7FC(void *, int, int);
extern u32 func_020307B0(void *p);
extern void func_0207F9B4(void);
extern void func_021E3B2C(char *);
void func_021E37D8(u16 *p, u8 *src, int k, int a3);
void func_021E380C(u16 *p, u8 *src, int a2);
void func_021E3838(char *p, int count);
extern const char d_021E81C0[];


void func_021E37D8(u16 *p, u8 *src, int k, int a3)
{
    u8 *row;
    int i;
    int j;

    i = 0;
    row = src + k * 30;
    for (; i < 5; i++) {
        for (j = 0; j < 6; j++)
            func_021E3758(p, j, i, row[i * 6 + j]);
    }
}


void func_021E380C(u16 *p, u8 *src, int a2)
{
    int i;

    for (i = 0; i < 6; i++)
        func_021E3758(p, i % 2 + 2, i / 2 + 1, src[i]);
}

void func_021E3838(char *p, int count)
{
    char *v;
    int i;
    func_0207F7A0();
    v = func_02030734(((struct Obj10376 *)p)->f5F4, 0x200, 1, d_021E81C0, 0x510);
    for (i = 0; i < count; i++) {
        func_02082BCC(v, 0, 0x200);
        if (i == 0)
            func_021E380C((u16 *)v, (unsigned char *)(p + 0x5B6), 2);
        else
            func_021E37D8((u16 *)v, (u8 *)(p + 0x2E6), i - 1, 2);
        func_020862F0(v, 0x200);
        func_0207F7FC(v, i * 0x200 + 0x3000, 0x200);
    }
    func_020307B0(v);
    func_0207F9B4();
    func_021E3B2C(p);
}
