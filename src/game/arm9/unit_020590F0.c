/*
 * file:     unit_020590F0.c
 * unit:     yes
 * function: func_020590F0, func_020590F8, func_02059100
 * address:  0x020590F0
 * packet:   pkt_020590F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef struct S {
    int pad;
    int a;
    int b;
} S;

void func_020590F0(int *p, int v)
{
    p[2] = v;
}

void func_020590F8(S *p, int a, int b)
{
    p->a = a;
    p->b = b;
}

void func_02059100(int *p, int v)
{
    p[1] = v;
}
