/*
 * file:     unit_021E0284_p02.c
 * unit:     yes
 * function: func_021E03D8, func_021E03E8
 * address:  0x021E03D8
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
 *   func_021D5440   0x021D5440  thumb
 *   func_021E03F8   0x021E03F8  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021E03F8(int a, int b);
/* 021E03D8 pass-through: second callee takes the first one's result */ void func_021E03D8(u8 *a, int b);
int func_021E03E8(void *n, u32 *q);


/* 021E03D8  pass-through: second callee takes the first one's result */
void func_021E03D8(u8 *a, int b)
{
    func_021E03F8(func_021D5440(a), b);
}


int func_021E03E8(void *n, u32 *q)
{
    if (q[6] != 0) return 1;
    return 0;
}
