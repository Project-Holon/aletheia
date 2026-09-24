/*
 * function: func_021BE7FC
 * address:  0x021BE7FC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BBCF0  0x021BBCF0  arm  ov114
 *   func_021BEC2C  0x021BEC2C  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *
 *
 * Keyed lookup then dispatch; -1 when the key is unknown.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEF08(void);
extern u8 *func_021BEF58(int);
extern int func_021BEC2C(int, int);
extern int func_021BBCF0(u8 *, int, int);

int func_021BE7FC(int a, int b, int c)
{
    u8 *p = (u8 *)func_021BEC2C((int)func_021BEF58((int)func_021BEF08()), a);
    if (p == 0)
        return -1;
    return func_021BBCF0(p, b, c);
}
