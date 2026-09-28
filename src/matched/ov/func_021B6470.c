/*
 * function: func_021B6470
 * address:  0x021B6470
 * packet:   pkt_021B6470
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B69B8  0x021B69B8  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int func_021B69B8(void *e);

int func_021B6470(u8 *p)
{
    if (*(u32 *)(p + 8) == 1 && *(u32 *)p != 0xffffffff) {
        return func_021B69B8(p + 0x20 + *(u32 *)p * 0x38);
    }
    return -1;
}
