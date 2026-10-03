/*
 * function: func_021BF488
 * address:  0x021BF488
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEC00  0x021BEC00  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *
 *
 * Keyed +0x04 read of record `a`; -1 when the key is unknown.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEF08(void);
extern void *func_021BEF58(int p);
extern u8 *func_021BEC00(int, int);

int func_021BF488(int a)
{
    u8 *p = func_021BEC00((int)func_021BEF58((int)func_021BEF08()), a);
    if (p != 0)
        return *(u32 *)(p + 4);
    return -1;
}
