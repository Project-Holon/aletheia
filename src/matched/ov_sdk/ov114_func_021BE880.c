/*
 * function: func_021BE880
 * address:  0x021BE880
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEC2C  0x021BEC2C  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *
 *
 * Keyed field read: -1 unknown key, -1 when unset, else the +0x18 word.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEF08(void);
extern u8 *func_021BEF58(int);
extern int func_021BEC2C(int, int);

int func_021BE880(int a)
{
    u8 *p = (u8 *)func_021BEC2C((int)func_021BEF58((int)func_021BEF08()), a);
    if (p == 0)
        return -1;
    if (*(u32 *)(p + 0x14) != 0)
        return *(u32 *)(p + 0x18);
    return -1;
}
