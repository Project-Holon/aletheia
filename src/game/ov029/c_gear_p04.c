/*
 * file:     c_gear_p04.c
 * unit:     yes
 * function: func_021F0CDC, func_021F0CF0, func_021F0D00, func_021F0D08, func_021F0D10, func_021F0D14, func_021F0D48, func_021F0D80, func_021F0DB4, func_021F0E70, func_021F0EB0, func_021F0F28, func_021F0F70, func_021F0FB0, func_021F0FF0, func_021F1000
 * address:  0x021F0CDC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3344     0x021F3344  data  a4
 *   func_020221A4 0x020221A4 thumb
 *   func_0207D55C 0x0207D55C arm
 *   func_0201210C 0x0201210C thumb
 *   func_02189A48 0x02189A48 thumb ov021
 *   func_021F2B9C 0x021F2B9C thumb ov029
 *   func_02021728  0x02021728  thumb
 *   func_02021730  0x02021730  thumb
 *   func_02021F64  0x02021F64  thumb
 *   func_02082D44  0x02082D44  arm
 *   d_021F31B6     0x021F31B6  data  a2
 *   func_0202173C  0x0202173C  thumb
 *   func_02021B18 0x02021B18 thumb
 *   func_02021ED8  0x02021ED8  thumb
 */
#include "../../matched/include/Obj00106.h"
#include "../../matched/include/Obj05115.h"
#include "../../matched/include/Obj09786.h"
#include "../../matched/include/Obj00042.h"
#include "../../matched/include/Obj20390.h"
#include "../../matched/include/Obj20391.h"

struct Ctx;
struct Obj02021B18;
typedef struct { int a, b; } Pair;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed   short s16;

extern unsigned int func_020221A4(void);
extern int func_0207D55C(volatile u16 *reg);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A48(char *p);
extern u32 func_021F2B9C(u8 *p, int row, int col);
extern int func_02021728(char *p, int i);
extern int func_02021730(char *p, int i);
extern void func_02021F64(u16 *src, u16 *dst, int count, int weight, u16 color);
extern void func_02082D44(void *src, void *dst, int n);
extern int func_0202173C(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
extern void func_02021B18(struct Obj02021B18 *o);
extern u32 func_02021ED8(const char *ptr);
int func_021F0CDC(unsigned short *p, int i);
void func_021F0CF0(unsigned char *p, int i);
void func_021F0D00(unsigned short *p, int i);
unsigned short func_021F0D08(unsigned short *p, int i);
void func_021F0D10(char *p, char v);
void func_021F0D14(int a, int b, int *c, int *d);
int func_021F0D48(char *p);
int func_021F0D80(void *p, int value);
void func_021F0DB4(char *p, int mode);
void func_021F0E70(char *p);
void func_021F0EB0(char *p, int flag);
void func_021F0F28(char *p, int flag);
void func_021F0F70(char *p);
void func_021F0FB0(char *p);
void func_021F0FF0(char *p);
int func_021F1000(char *p);
extern const Pair d_021F3344;
extern u16 d_021F31B6[];

int func_021F0CDC(unsigned short *p, int i)
{
    if (p[i] >= p[3]) return 1;
    return 0;
}

void func_021F0CF0(unsigned char *p, int i)
{
    if (p[8] != 0) ((unsigned short *)p)[i] = 0;
}

void func_021F0D00(unsigned short *p, int i)
{
    p[i] = 0;
}


unsigned short func_021F0D08(unsigned short *p, int i)
{
    return p[i];
}


void func_021F0D10(char *p, char v)
{
    p[9] = v;
}


void func_021F0D14(int a, int b, int *c, int *d)
{
    Pair t = d_021F3344;
    *c = a * 4 - 2;
    *d = ((int *)&t)[a % 2] + b * 4;
}

/*
 * 2026-10-04 (wD2 lane 09): bytes are identical; only the relocation at +0024 is open.
 * Filed the callee as matched ov021_func_02189A48.c (EXACT, returns *(u32 *)(p+0x144)).
 * The tool still reports no independent witness for 02189A48 (3 overlays overlap).
 * Needs the integrator to regenerate the witness index, nothing left in the source.
 * interface: 0201210C returns the full word at +0x20; it is passed directly
 * to 02189A48, whose ov021 body reads the full word at +0x144. No value lost.
 */
int func_021F0D48(char *p)
{
    if (!func_020221A4()) return 0;
    if (func_0207D55C((unsigned short *)0x0400106c)) return 0;
    if (!func_02189A48((char *)func_0201210C(*(void **)(p + 0x1c)))) return 1;
    return 0;
}

int func_021F0D80(void *p, int value)
{
    int j, i, count;
    if (value == 4) return 1;
    count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 9; j++) {
            if (value == func_021F2B9C(p, j, i)) count++;
        }
    }
    return count;
}


void func_021F0DB4(char *p, int mode)
{
    char *a, *b;
    int i;

    if (mode == 0) {
        a = (char *)func_02021728(*(char **)(p + 0x210), 3);
        b = (char *)func_02021730(*(char **)(p + 0x210), 3);
        for (i = 0; i < 14; i++) {
            if (0xFBEE & (1 << i)) {
                func_02021F64((u16 *)(a + i * 0x20), (u16 *)(a + i * 0x20), 0x10, 8,
                              d_021F31B6[*(u8 *)(p + 0x459)]);
                func_02082D44(a + i * 0x20, b + i * 0x20, 0x20);
            }
        }
        a = (char *)func_02021728(*(char **)(p + 0x210), 1);
        b = (char *)func_02021730(*(char **)(p + 0x210), 1);
        for (i = 0; i < 14; i++) {
            if (0x3E & (1 << i)) {
                func_02021F64((u16 *)(a + i * 0x20), (u16 *)(a + i * 0x20), 0x10, 8,
                              d_021F31B6[*(u8 *)(p + 0x459)]);
                func_02082D44(a + i * 0x20, b + i * 0x20, 0x20);
            }
        }
    }
}


void func_021F0E70(char *p)
{
    func_0202173C(((struct Obj00106 *)p)->f210, 8, 0xFFFF, -120, 0, 0x10,
                  d_021F31B6[((struct Obj00106 *)p)->f459], ((struct Obj00106 *)p)->f204);
}


void func_021F0EB0(char *p, int flag)
{
    int c = 8;
    if (flag == 0)
        c = 0;
    func_0202173C(((struct Obj05115 *)p)->f210, 8, 0xFFFF, -120, 0, c,
                  d_021F31B6[((struct Obj05115 *)p)->f459], ((struct Obj05115 *)p)->f204);
    func_0202173C(((struct Obj05115 *)p)->f210, 2, 0x3E, -120, 0, c,
                  d_021F31B6[((struct Obj05115 *)p)->f459], ((struct Obj05115 *)p)->f204);
}


void func_021F0F28(char *p, int flag)
{
    int c = 8;
    if (flag == 0)
        c = 0;
    func_0202173C(((struct Obj09786 *)p)->f210, 8, 0x3C0, -120, 0, c,
                  d_021F31B6[((struct Obj09786 *)p)->f459], ((struct Obj09786 *)p)->f204);
}


void func_021F0F70(char *p)
{
    func_0202173C(((struct Obj00106 *)p)->f210, 8, 0xFFFF, 1, 0, 0x10,
                  d_021F31B6[((struct Obj00106 *)p)->f459], ((struct Obj00106 *)p)->f204);
}


void func_021F0FB0(char *p)
{
    func_0202173C(((struct Obj00042 *)p)->f210, 8, 0xFFFF, 1, 0x10, 0,
                  d_021F31B6[((struct Obj00042 *)p)->f459], ((struct Obj00042 *)p)->f204);
}

/*
 * extent: followed by existing ov029_func_021F1000.c.
 */
void func_021F0FF0(char *p)
{
    func_02021B18(((struct Obj20390 *)p)->f210);
}


int func_021F1000(char *p)
{
    return func_02021ED8((const char *)(((struct Obj20391 *)p)->f210));
}
