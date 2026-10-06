/*
 * function: func_020284F4
 * address:  0x020284F4
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
extern u32 func_020362DC(void);
extern int func_02035C60(void);

u32 func_020284F4(u32 a)
{
    u32 r = 0;

    if (a == 0) {
        r = 1;
    }

    if (a & 2) {
        if (func_020362DC() & 3) {
            r = 1;
        }
    }

    if (a & 4) {
        if (func_02035C60() != 0) {
            r = 1;
        }
    }

    return r;
}
