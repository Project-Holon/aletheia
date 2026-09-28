/*
 * function: func_021B6814
 * address:  0x021B6814
 * packet:   pkt_021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Startup: runs the ARM9 probe, then the three veneers, and latches the +0x10/+0x1c flags.
 *
 * symbols:
 *   func_02085D3C  0x02085D3C  arm
 *   func_021B6850  0x021B6850  arm    ov172
 *   func_021B6858  0x021B6858  arm    ov172
 *   func_021B6860  0x021B6860  arm    ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_02085D3C(void);
extern int func_021B6850(void);
extern int func_021B6858(int a);
extern int func_021B6860(int a);

void func_021B6814(void *a0)
{
    char *p = (char *)a0;
    int one = 1;

    if (*(u32 *)(p + 0x10) != 0)
        return;
    if ((func_02085D3C() == 1 ? func_021B6850() : 0) != 0)
        return;
    if (func_021B6858(one) == 1)
        func_021B6860(one);
    *(u32 *)(p + 0x10) = one;
    *(u32 *)(p + 0x1c) = one;
    *(u32 *)(p + 0x28) = 0;
}
