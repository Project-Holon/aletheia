/*
 * function: func_021B9B80
 * address:  0x021B9B80
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9A34  0x021B9A34  thumb  ov099
 *
 * Releases every occupied one of the 0x30 records of 0x1C bytes at +0x30.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021B9A34(void *p);

void func_021B9B80(char *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32 *)(p + i * 0x1C + 0x30) != 0) {
            func_021B9A34(p + 0x30 + i * 0x1C);
        }
    }
}
