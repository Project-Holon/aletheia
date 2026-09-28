/*
 * function: func_021A2E44
 * address:  0x021A2E44
 * packet:   pkt_021A2E44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02188CA4  0x02188CA4  thumb
 */

typedef unsigned int u32;

void *func_02188CA4(void);

void func_021A2E44(int a, u32 v)
{
    *(u32 *)((char *)func_02188CA4() + 0xc) = v;
}
