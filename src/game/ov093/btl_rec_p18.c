/*
 * file:     btl_rec_p18.c
 * unit:     yes
 * function: func_021EF90C, func_021EF91C, func_021EF934, func_021EF948, func_021EF958, func_021EF980
 * address:  0x021EF90C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EFB34  0x021EFB34  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 *   func_021EFC1C  0x021EFC1C  thumb  ov093
 *   gBottomScreen  0x021F63F4  data   ov093  a4
 *   func_021EFC78  0x021EFC78  thumb  ov093
 *   HeapMem        0x021F63F4  data   ov093  a4
 *   func_021EFCE4  0x021EFCE4  thumb  ov093
 *   func_02030734  0x02030734  arm
 *   d_021F3AF8  0x021F3AF8  data  a4
 *   func_021EF988  0x021EF988  thumb  ov093
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/G_Countdown.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u32 v; } Slot;

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
    Slot c[8];          /* 0x028 */
    u32 z48[8];         /* 0x048 */
    u32 w[8][6];        /* 0x068 */
    u32 z128[8];        /* 0x128 */
    u32 used[8];        /* 0x148 */
} S;

typedef unsigned short u16;

extern int func_021EFB34(void *mem, int a);
extern void func_021EFC1C(void *screen, int line, int color, char *text);
extern int func_021EFC78(void *mem, int a, int b);
extern void *func_021EFCE4(char *arg0, int arg1);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021EF988(S *p, u32 v);
extern u32 func_020307B0(void *p);
int func_021EF90C(int a);
void SetBottomScreenLineCentered(int line, int color, char *text);
int DWC_StartUtilityEx(int a, int b);
int func_021EF948(int a);
S *func_021EF958(u32 heap);
void func_021EF980(void *p);
extern struct Countdown d_021F63F4;
extern char gBottomScreen;
extern char HeapMem;
extern char d_021F3AF8[];


int func_021EF90C(int a)
{
    return func_021EFB34(&(*(char *)&d_021F63F4), a);
}


void SetBottomScreenLineCentered(int line, int color, char *text)
{
    func_021EFC1C(&gBottomScreen, line, color, text);
}


int DWC_StartUtilityEx(int a, int b)
{
    return func_021EFC78(&HeapMem, a, b);
}


int func_021EF948(int a)
{
    return (int)func_021EFCE4(&(*(char *)&d_021F63F4), a);
}


S *func_021EF958(u32 heap)
{
    S *p = func_02030734(heap, 0x168, 1, d_021F3AF8, 0x10c);

    func_021EF988(p, 0);
    return p;
}

void func_021EF980(void *p) { func_020307B0(p); }
