/*
 * file:     unit_06899A90.c
 * unit:     yes
 * function: func_06899A90, func_06899A9C
 * address:  0x06899A90
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9A40  0x021B9A40  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   d_0689D720 0x0689D720 data a4
 */
typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int);
extern u8 func_021B9A40(u8);
extern void BTL_EVENT_MultiplyVar(int, int);
void *func_06899A90(unsigned int *p);
void func_06899A9C(int a, int b, int c);
extern unsigned int d_0689D720;

void *func_06899A90(unsigned int *p)
{
    *p = 1;
    return &d_0689D720;
}

void func_06899A9C(int a, int b, int c)
{
    if (c == func_021B9A40(BTL_EVENT_GetVar(2)))
        BTL_EVENT_MultiplyVar(0x35, 0x400);
}
