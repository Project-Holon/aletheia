/*
 * function: func_0689D448
 * address:  0x0689D448
 * packet:   pkt_ov095_0689D448
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B9934  0x021B9934  thumb
 *   func_021B9A24  0x021B9A24  thumb
 *   func_021D6DCC  0x021D6DCC  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Rec;

typedef struct {
    Rec r[6];
    u8 idx[6];
} T;

extern int func_021B9A24(int, int);
extern int func_021B9934(int, int);
extern int func_021D6DCC(int, int);

void func_0689D448(T *a, int b, int c)
{
    u32 k;
    u32 i;
    Rec *q;

    k = a->r[b].c;
    if (k == 0x1f)
        return;
    for (i = 0; i < 6; i++) {
        q = &a->r[i];
        if (q->c == 0x1f || k == q->c)
            continue;
        if (func_021B9A24(q->c, k) != 0)
            continue;
        func_021D6DCC(func_021B9934(c, q->c), k);
        func_021D6DCC(func_021B9934(c, k), q->c);
    }
}
