/*
 * function: func_021B6AB0
 * address:  0x021B6AB0
 * packet:   pkt_ov021_021B6AB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6AA4  0x021B6AA4  thumb ov021
 *   func_021B6AAC  0x021B6AAC  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_021B6AA4(void *, int);
extern void func_021B6AAC(u16 *);

int func_021B6AB0(void *a)
{
    int i;
    u16 *p;

    for (i = 0; i < 8; i++) {
        p = func_021B6AA4(a, i);
        func_021B6AAC(p);
        if (*p == 0xFFFF) {
            return i;
        }
    }
    return 0;
}
