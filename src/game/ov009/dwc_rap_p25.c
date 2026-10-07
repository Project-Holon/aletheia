/*
 * file:     dwc_rap_p25.c
 * unit:     yes
 * function: func_02157048, func_021570B8
 * address:  0x02157048
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A8268  0x021A8268  data  ov009  a4
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_02060C5C  0x02060C5C  arm
 *   func_02156F14  0x02156F14  thumb  ov009
 *   func_02060C94  0x02060C94  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/G_Obj.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u16 f20;
} Obj;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heap, u32 size, int align, const char *file, u16 line);
extern void *func_02060C5C(void *start, u32 size, u32 attr);
extern void func_02156F14(void);
extern void func_02060C94(void *heap);
extern u32 func_020307B0(void *p);
void func_02157048(u32 a, u32 b);
void func_021570B8(void);
extern Obj *d_021A8268;
extern char d_021A1C78[];
extern char d_021A1C7C[];


void func_02157048(u32 a, u32 b)
{
    if (d_021A8268 != 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    d_021A8268 = (Obj *)func_02030734(0, 0x24, 1, d_021A1C7C, 0x14C);
    d_021A8268->f4 = (u32)func_02030734(a, b - 0x80, 0, d_021A1C7C, 0x14D);
    d_021A8268->f0 = (u32)func_02060C5C((void *)((d_021A8268->f4 + 0x1f) & ~0x1f), b - 0xc0, 0);
    d_021A8268->f20 = 0;
}


void func_021570B8(void)
{
    if (d_021A8268 == 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->f1C == 1 || d_021A8268->fC != 0) {
        func_02156F14();
    }
    func_02060C94((void *)d_021A8268->f0);
    func_020307B0((void *)d_021A8268->f4);
    func_020307B0(d_021A8268);
    d_021A8268 = 0;
}
