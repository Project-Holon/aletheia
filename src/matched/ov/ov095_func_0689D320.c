/*
 * function: func_0689D320
 * address: 0x0689D320
 * packet: pkt_ov095_0689D320
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0689D448 0x0689D448 thumb ov095
 */
typedef unsigned char u8;
typedef struct { u8 a, b, c; } Rec;
typedef struct { Rec r[6]; u8 idx[6]; } T;
extern void func_0689D448(T *, int, int);
void func_0689D320(T *p, int b, int c, int d)
{
    p->r[b].c = c;
    p->idx[c] = b;
    func_0689D448(p, b, d);
}
