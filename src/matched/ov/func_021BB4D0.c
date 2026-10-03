/*
 * function: func_021BB4D0
 * address:  0x021BB4D0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B639C  0x021B639C  thumb  ov067
 *
 * Releases the pointer 0x9AC bytes into the block and clears the slot.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021B639C(u8 *p);

void func_021BB4D0(char *p)
{
    void *q = *(void **)(p + 0x9AC);

    if (q != 0) {
        func_021B639C(q);
        *(void **)(p + 0x9AC) = 0;
    }
}
