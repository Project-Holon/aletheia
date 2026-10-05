/*
 * function: func_02014368
 * address:  0x02014368
 * packet:   pkt_02014314
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;

extern void func_0201433C(char *a0, int a1);

void func_02014368(char *a0, int a1, int a2)
{
    int i;

    for (i = a1; i <= a2; i++)
        func_0201433C(a0, (u16)i);
}
