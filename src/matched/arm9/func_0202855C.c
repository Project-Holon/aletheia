/*
 * function: func_0202855C
 * address:  0x0202855C
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
extern u32 func_02035C38(void);

u32 func_0202855C(u32 a)
{
    u32 r = 0;

    if (a == 0) {
        r = 1;
    }

    if (a & 2) {
        if (func_0203630C() == 0) {
            r = 1;
        }
    }

    if (a & 4) {
        if (func_02035C38() == 0) {
            r = 1;
        }
    }

    return r;
}
