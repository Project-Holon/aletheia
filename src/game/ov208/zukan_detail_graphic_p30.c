/*
 * file:     zukan_detail_graphic_p30.c
 * unit:     yes
 * function: func_021C2234, func_021C2238, func_021C2304, func_021C231C, func_021C232C, func_021C239C
 * address:  0x021C2234
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   data_021C8E14  0x021C8E14  data
 *   data_021C8E1A  0x021C8E1A  data
 *   func_0207D63C 0x0207D63C  arm
 *   func_021BC518 0x021BC518  thumb  ov208
 *   func_021C2430 0x021C2430 thumb ov208
 */
#include "../../matched/include/Obj18287.h"
#include "../../matched/include/Obj18288.h"

#define W(o) (*(u32 *)(p + (o)))
#define REG32(a) (*(volatile u32 *)(a))
#define REG16(a) (*(volatile u16 *)(a))
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16;

typedef int            s32;

typedef struct {
    u8 f0;
    u8 f1;
    u8 b[0x3c];
} Entry;

typedef int BOOL;

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_021BC518(int *p);
extern void func_021C2430(u8 *p);
void ov208_func_021C2234(u16 *heap, u8 *p, int key);
void func_021C2238(u16 *heap, u8 *p, int key);
void func_021C2304(char *a0);
void func_021C231C(char *p);
void func_021C232C(char *p);
void func_021C239C(char *p);
extern const u8 data_021C8E14[3][2];
extern u8 data_021C8E1A[3][4];


void ov208_func_021C2234(u16 *heap, u8 *p, int key)
{
}


/*
 * note: 2026-10-05 (D6-04): closed by declaring data_021C8E1A non-const; the
 *   image keeps the x0 table load below the stack argument stores (a plain
 *   extern cannot move past them).
 */
void func_021C2238(u16 *heap, u8 *p, int key)
{
    u8 on[3] = {0, 0, 0};
    u8 idx, k, i;

    if (W(0x90) == 1 && p[0x79] != 0xff) {
        idx = W(0x8c) != 0 ? p[0x78] : 0;
        k = (p + p[0x79])[0x3cc];
        if ((*(Entry **)(p + 0x94))[idx].b[k] & 7)
            on[0] = 1;
        if ((*(Entry **)(p + 0x94))[idx].b[k] & 0x18)
            on[1] = 1;
        if ((*(Entry **)(p + 0x94))[idx].b[k] & 0x60)
            on[2] = 1;
    }
    for (i = 0; i < 3; i++)
        func_020413B0(7, data_021C8E1A[i][0], data_021C8E1A[i][1], data_021C8E1A[i][2],
                      data_021C8E1A[i][3], data_021C8E14[i][on[i]]);
    func_02041B6C(7);
}


/*
 * Writes 4 on the stack and calls the SDK function at 0x0207D63C with
 * (0x04000050, 0, 0x3F, 0xC, 4).
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0207D63C is the ARM
 * SDK symbol G2x_SetBlendAlpha_, and the `sdk` class attests the call once
 * the symbols block declares `arm`.  The old `thumb` declaration fought the
 * image's ISA and suppressed the witness.  Verified EXACT, 24 bytes.
 */
void func_021C2304(char *a0)
{
    func_0207D63C((void *)0x04000050, 0, 0x3f, 0xc, 4);
}


/*
 * Loads the word at +0x418 and tail-calls func_021BC518 with it.
 */
void func_021C231C(char *p)
{
    func_021BC518((int *)(((struct Obj18287 *)p)->f418));
}

static inline void GX_SetVisibleWnd(int window)
{
    REG32(0x04000000) = (u32)((REG32(0x04000000) & ~0xe000) | (window << 13));
}

static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    REG16(0x04000040) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000044) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

static inline void G2_SetWnd1Position(int x1, int y1, int x2, int y2)
{
    REG16(0x04000042) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000046) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

static inline void G2_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x04000048) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(0x04000048) = (u16)tmp;
}

static inline void G2_SetWnd1InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x04000048) & ~0x3f00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    REG16(0x04000048) = (u16)tmp;
}

static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x0400004a) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(0x0400004a) = (u16)tmp;
}

void func_021C232C(char *p)
{
    GX_SetVisibleWnd(3);
    G2_SetWnd0Position(0, 0, 160, 168);
    G2_SetWnd1Position(160, 0, 0, 168);
    G2_SetWnd0InsidePlane(31, 1);
    G2_SetWnd1InsidePlane(31, 1);
    G2_SetWndOutsidePlane(31, 0);
    func_021C2430((u8 *)p);
}


/*
 * Masks 0x04000000 with 0xFFFF1FFF, then tail-calls func_021BC518 on the word at +0x418.
 */
void func_021C239C(char *p)
{
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    func_021BC518((int *)(((struct Obj18288 *)p)->f418));
}
