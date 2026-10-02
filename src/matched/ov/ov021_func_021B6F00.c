/*
 * function: func_021B6F00
 * address:  0x021B6F00
 * packet:   pkt_ov021_021B6F00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02012934(void *p);
extern int func_0201AA18(void *);

int func_021B6F00(void *a, void *b)
{
    if (func_0201AA18(func_02012934(b)) < 6) {
        return 1;
    }
    return 0;
}
