/*
 * function: func_02028528
 * address:  0x02028528
 * packet:   pkt_02028484
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT

 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);

u32 func_02028528(u32 a)
{
    u32 r = 0;

    if (a == 0) {
        r = 1;
    }

    if (a & 2) {
        if (func_0203630C() & 3) {
            r = 1;
        }
    }

    if (a & 4) {
        if (func_02035C38() != 0) {
            r = 1;
        }
    }

    return r;
}
