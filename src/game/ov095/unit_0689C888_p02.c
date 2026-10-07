/*
 * file:     unit_0689C888_p02.c
 * unit:     yes
 * function: func_0689CA0C, func_0689CA1C, func_0689CA3C, func_0689CA5C, func_0689CAB0, func_0689CAD8
 * address:  0x0689CA0C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689C888  0x0689C888  thumb
 *   d_0689E330     0x0689E330  data  ov095  a2
 *   d_0689E346 0x0689E346 data a2
 *   d_0689E3D4 0x0689E3D4 data a2
 *   d_0689E3AC     0x0689E3AC  data  ov095  a2
 *   d_0689E2CE     0x0689E2CE  data  ov095  a2
 *   d_0689E3FC     0x0689E3FC  data  ov095  a4
 */
typedef unsigned char u8;

int func_0689C888(unsigned a, unsigned short *b, unsigned n);
int func_0689CA0C(unsigned a);
int func_0689CA1C(unsigned a);
int func_0689CA3C(unsigned a);
int func_0689CA5C(unsigned a);
int func_0689CA7C(unsigned a);
int *func_0689CA8C(int *p);
void func_0689CA98(int *p, int a, u8 b, u8 c);
void func_0689CAB0(u8 *p, u8 n);
void func_0689CAD8(u8 *p, u8 v, int i);
void func_0689CAE0(u8 *p, const u8 *q);
void func_0689CAEC(u8 *p, u8 a, u8 b);
void func_0689CB08(u8 *p);
int func_0689CB14(u8 *p);
int func_0689CB18(u8 *p);
int func_0689CB1C(u8 *p);
int func_0689CB2C(u8 *p, u8 i);
extern unsigned short d_0689E330[];
extern unsigned short d_0689E346[];
extern unsigned short d_0689E3D4[];
extern unsigned short d_0689E3AC[];
extern unsigned short d_0689E2CE[];
extern int d_0689E3FC[];


int func_0689CA0C(unsigned a)
{
    return func_0689C888(a, d_0689E330, 0xb);
}

int func_0689CA1C(unsigned a)
{
    if (func_0689CA0C(a)) return 1;
    return func_0689C888(a, d_0689E346, 11);
}

int func_0689CA3C(unsigned a)
{
    if (func_0689CA0C(a))
        return 1;
    return func_0689C888(a, d_0689E3D4, 20);
}


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

void func_0689CAB0(u8 *p, u8 n)
{
    u8 i;
    for (i = 0; i < n; i++)
        func_0689CAD8(p, 2, i);
}


void func_0689CAD8(u8 *p, u8 v, int i)
{
    (p + i)[5] = v;
}


void func_0689CAE0(u8 *p, const u8 *q)
{
    p[6] = 0;
    p[7] = q[4];
}


void func_0689CAEC(u8 *p, u8 a, u8 b)
{
    if (p[6] < p[7]) {
        p[p[6]] = b;
        (p + p[6])[3] = a;
        p[6]++;
    }
}


void func_0689CB08(u8 *p)
{
    if (p[6])
        p[6]--;
}


int func_0689CB14(u8 *p)
{
    return p[8];
}


int func_0689CB18(u8 *p)
{
    return p[6];
}


int func_0689CB1C(u8 *p)
{
    u8 n = p[6];
    if (n)
        return p[n - 1];
    return 6;
}


int func_0689CB2C(u8 *p, u8 i)
{
    if (i < p[6])
        return p[i];
    return 6;
}
