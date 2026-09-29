/*
 * unit:     yes
 * function: func_0689CA5C
 * function: func_0689CA7C
 * function: func_0689CA8C
 * function: func_0689CA98
 * address:  0x0689CA5C
 * packet:   pkt_ov095_0689CA5C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689CA0C  0x0689CA0C  thumb  ov095
 *   func_0689C888  0x0689C888  thumb
 *   d_0689E3AC     0x0689E3AC  data  ov095  a2
 *   d_0689E2CE     0x0689E2CE  data  ov095  a2
 *   d_0689E3FC     0x0689E3FC  data  ov095  a4
 */

typedef unsigned char u8;

extern unsigned short d_0689E3AC[];
extern unsigned short d_0689E2CE[];
extern int d_0689E3FC[];

int func_0689CA0C(unsigned a);
int func_0689C888(unsigned a, unsigned short *b, unsigned n);

int func_0689CA5C(unsigned a)
{
    if (func_0689CA0C(a))
        return 1;
    return func_0689C888(a, d_0689E3AC, 0x14);
}

int func_0689CA7C(unsigned a)
{
    return func_0689C888(a, d_0689E2CE, 6);
}

int *func_0689CA8C(int *p)
{
    *p = 0x29;
    return d_0689E3FC;
}

void func_0689CA98(int *p, int a, u8 b, u8 c)
{
    unsigned i;
    ((u8 *)p)[0xb] = c;
    ((u8 *)p)[4] = b;
    *p = a;
    for (i = 0; i < 6; i++)
        ((u8 *)p)[5 + i] = 0;
}
