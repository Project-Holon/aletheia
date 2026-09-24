/*
 * function: func_021C1C70
 * address:  0x021C1C70
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C1A44  0x021C1A44  thumb  ov099
 *
 * Clears the flag block 0x8ED bytes in and sets the keep flag when the entry test answers 1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_021C1A44(void *p);

void func_021C1C70(char *p)
{
    if (func_021C1A44(p) != 1) {
        return;
    }

    p[0x8ED] = 0;
    p[0x8EE] = 0;
    p[0x8EF] = 0;
    p[0x8F1] = 1;
    *(u32 *)(p + 0x8F4) = 1;
}
