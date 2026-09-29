/*
 * unit:     yes
 * function: func_0689CAD8
 * function: func_0689CAE0
 * function: func_0689CAEC
 * function: func_0689CB08
 * function: func_0689CB14
 * function: func_0689CB18
 * function: func_0689CB1C
 * function: func_0689CB2C
 * address:  0x0689CAD8
 * packet:   pkt_ov095_0689CAD8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

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
