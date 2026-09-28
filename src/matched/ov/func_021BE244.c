/*
 * function: func_021BE244
 * address:  0x021BE244
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the first slot of the table at +0x814 that holds v.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

void func_021BE244(char *p, void *v)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (*(void **)(p + i * 4 + 0x814) == v) {
            *(void **)(p + i * 4 + 0x814) = 0;
            return;
        }
    }
}
