/*
 * file:     unit_021E2188_p03.c
 * unit:     yes
 * function: func_021E2678, func_021E269C
 * address:  0x021E2678
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021E26C8  0x021E26C8  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void func_021E26C8(void *u, int a, int b, int *p);
void func_021E2678(void *u, int a, int b, int *p);
void func_021E269C(void *u, int a, int b, int *p);


void func_021E2678(void *u, int a, int b, int *p)
{
    if (b == func_021D775C(2))
        func_021E26C8(u, a, b, p);
}


void func_021E269C(void *u, int a, int b, int *p)
{
    if (b == func_021D775C(2)) {
        if (func_021D775C(0x51) == 0)
            func_021E26C8(u, a, b, p);
    }
}
