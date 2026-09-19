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

typedef unsigned short u16;

struct S02021944 {
    char pad[0x11a];
    u16 lo : 14;
    u16 hi : 2;
};

extern int func_02021930(int a0);

void func_02021944(struct S02021944 *p, int a1)
{
    if (func_02021930(p->lo) == 1)
        return;
    p->lo |= 1 << a1;
}
