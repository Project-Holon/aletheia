/*
 * function: func_021C14EC
 * address:  0x021C14EC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA928  0x021BA928  thumb  ov099
 *
 * True when the guard answers true or the pointer 0x190 bytes in is still unset.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_021BA928(void *p);
extern void func_021BA828(void *p);

BOOL func_021C14EC(char *p, int v)
{
    if (func_021BA928(p) != 0) {
        return 1;
    }

    if (*(void **)(p + 0x190) == 0) {
        return 1;
    }

    return 0;
}
