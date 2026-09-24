/*
 * function: func_021BE21C
 * address:  0x021BE21C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Files v in the first free slot of the 0x21-entry table at +0x814.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

void func_021BE21C(char *p, void *v)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (*(void **)(p + i * 4 + 0x814) == 0) {
            *(void **)(p + i * 4 + 0x814) = v;
            return;
        }
    }
}
