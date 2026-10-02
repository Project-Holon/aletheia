/*
 * function: func_02021944
 * address:  0x02021944
 * packet:   pkt_02021944
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct S02021944 {
    char pad[0x11a];
    u16 lo : 14;
    u16 hi : 2;
};

extern u8 func_02021930(u32 val, int bit);

void func_02021944(struct S02021944 *p, int a1)
{
    if (func_02021930(p->lo, a1) == 1)
        return;
    p->lo |= 1 << a1;
}
