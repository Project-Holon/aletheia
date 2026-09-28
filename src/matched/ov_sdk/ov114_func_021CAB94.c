/*
 * function: func_021CAB94
 * address:  0x021CAB94
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CAB34  0x021CAB34  arm  ov114
 *
 *
 * Last element of the pointer table at p: resolves entry n-1 and offsets by n-1 records.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021CAB34(int);

char *func_021CAB94(u8 *p)
{
    u32 n = *(u32 *)(p + 4);
    u32 i;
    if (n == 0)
        return 0;
    i = n - 1;
    return (char *)(func_021CAB34(*(u32 *)(*(u8 **)p + i * 4)) + i * 0x20);
}
