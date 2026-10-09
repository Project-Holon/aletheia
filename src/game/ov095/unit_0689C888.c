/*
 * file:     unit_0689C888.c
 * unit:     yes
 * function: func_0689C888, func_0689C8AC, func_0689C8BC, func_0689C8CC, func_0689C8DC, func_0689C8EC, func_0689C8FC, func_0689C90C, func_0689C91C, func_0689C93C, func_0689C944, func_0689C954, func_0689C974, func_0689C980, func_0689C990, func_0689C9A0, func_0689C9B0, func_0689C9C0, func_0689C9D4, func_0689C9E4, func_0689C9F8, func_0689CA0C, func_0689CA1C, func_0689CA3C, func_0689CA5C, func_0689CAB0, func_0689CAD8
 * address:  0x0689C888
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
 *   d_0689E2DA 0x0689E2DA data a2
 *   d_0689E31C 0x0689E31C data a2
 *   d_0689E2B6 0x0689E2B6 data a2
 *   d_0689E2C4 0x0689E2C4 data a2
 *   d_0689E2B0 0x0689E2B0 data a2
 *   d_0689E2F6 0x0689E2F6 data a2
 *   d_0689E2AA 0x0689E2AA data a2
 *   d_0689E2E6 0x0689E2E6 data a2
 *   d_0689E2A4 0x0689E2A4 data a2
 *   d_0689E38C 0x0689E38C data a2
 *   d_0689E2BC 0x0689E2BC data a2
 *   d_0689E308 0x0689E308 data a2
 *   d_0689E450 0x0689E450 data a2
 *   d_0689E35C 0x0689E35C data a2
 *   d_0689E374 0x0689E374 data a4
 *   d_0689E4C0 0x0689E4C0 data a4
 *   d_0689E330     0x0689E330  data  ov095  a2
 *   d_0689E346 0x0689E346 data a2
 *   d_0689E3D4 0x0689E3D4 data a2
 *   d_0689E3AC     0x0689E3AC  data  ov095  a2
 *   d_0689E2CE     0x0689E2CE  data  ov095  a2
 *   d_0689E3FC     0x0689E3FC  data  ov095  a4
 */
typedef unsigned char u8;

int func_0689C888(unsigned a, unsigned short *b, unsigned n);
int func_0689C8AC(unsigned a);
int func_0689C8BC(unsigned a);
int func_0689C8CC(unsigned a);
int func_0689C8DC(unsigned a);
int func_0689C8EC(unsigned a);
int func_0689C8FC(unsigned a);
int func_0689C90C(unsigned a);
int func_0689C91C(unsigned a);
int func_0689C93C(unsigned a);
int func_0689C944(unsigned a);
int func_0689C954(unsigned a);
int func_0689C974(int a);
int func_0689C980(unsigned a);
int func_0689C990(unsigned a);
int func_0689C9A0(unsigned a);
int func_0689C9B0(unsigned a);
int func_0689C9C0(unsigned a);
int func_0689C9D4(unsigned a);
unsigned int func_0689C9E4(unsigned a);
unsigned int func_0689C9F8(unsigned a);
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
extern unsigned short d_0689E2DA[];
extern unsigned short d_0689E31C[];
extern unsigned short d_0689E2B6[];
extern unsigned short d_0689E2C4[];
extern unsigned short d_0689E2B0[];
extern unsigned short d_0689E2F6[];
extern unsigned short d_0689E2AA[];
extern unsigned short d_0689E2E6[];
extern unsigned short d_0689E2A4[];
extern unsigned short d_0689E38C[];
extern unsigned short d_0689E2BC[];
extern unsigned short d_0689E308[];
extern unsigned short d_0689E450[];
extern unsigned short d_0689E35C[];
extern const unsigned int d_0689E374[];
extern const unsigned int d_0689E4C0[];
extern unsigned short d_0689E330[];
extern unsigned short d_0689E346[];
extern unsigned short d_0689E3D4[];
extern unsigned short d_0689E3AC[];
extern unsigned short d_0689E2CE[];
extern int d_0689E3FC[];

int func_0689C888(unsigned a, unsigned short *b, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        if (a == b[i])
            return 1;
    }
    return 0;
}


int func_0689C8AC(unsigned a)
{
    return func_0689C888(a, d_0689E2DA, 6);
}


int func_0689C8BC(unsigned a)
{
    return func_0689C888(a, d_0689E31C, 10);
}


int func_0689C8CC(unsigned a)
{
    return func_0689C888(a, d_0689E2B6, 3);
}


int func_0689C8DC(unsigned a)
{
    return func_0689C888(a, d_0689E2C4, 5);
}


int func_0689C8EC(unsigned a)
{
    return func_0689C888(a, d_0689E2B0, 3);
}


int func_0689C8FC(unsigned a)
{
    return func_0689C888(a, d_0689E2F6, 9);
}


int func_0689C90C(unsigned a)
{
    return func_0689C888(a, d_0689E2AA, 3);
}


int func_0689C91C(unsigned a)
{
    if (func_0689C974(a)) return 1;
    return func_0689C888(a, d_0689E2E6, 8);
}


int func_0689C93C(unsigned a) { return func_0689C944(a); }



int func_0689C944(unsigned a)
{
    if (a == 25) return 0;
    return func_0689C91C(a);
}



int func_0689C954(unsigned a)
{
    if (func_0689C974(a)) return 1;
    return func_0689C888(a, d_0689E2A4, 3);
}



int func_0689C974(int a)
{
    return a == 0x79;
}


int func_0689C980(unsigned a)
{
    return func_0689C888(a, d_0689E38C, 16);
}


int func_0689C990(unsigned a)
{
    return func_0689C888(a, d_0689E2BC, 4);
}


int func_0689C9A0(unsigned a)
{
    return func_0689C888(a, d_0689E308, 10);
}


int func_0689C9B0(unsigned a)
{
    return func_0689C888(a, d_0689E450, 55);
}


int func_0689C9C0(unsigned a)
{
    return a == 0x1ed;
}


int func_0689C9D4(unsigned a)
{
    return func_0689C888(a, d_0689E35C, 12);
}


unsigned int func_0689C9E4(unsigned a)
{
    if (a < 6) return d_0689E374[a];
    return 0;
}


unsigned int func_0689C9F8(unsigned a)
{
    if (a < 0x23) return d_0689E4C0[a];
    return 0;
}



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
