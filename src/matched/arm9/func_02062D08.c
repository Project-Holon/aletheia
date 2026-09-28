/*
 * function: func_02062D08
 * address:  0x02062D08
 * packet:   pkt_02062BF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_02062D08(void *p, u32 i)
{
    u8 *s = (u8 *)p;
    u8 *t = *(u8 **)(s + 0x1c);
    u8 *e;

    if (i < *(u16 *)t) {
        e = *(u8 **)(t + 0xc) + i * 8;
        *(u8 **)s = e;
        if (*(u16 *)(e + 4) != 0) {
            *(u8 **)(s + 4) = e;
        }
        return 1;
    }
    return 0;
}
