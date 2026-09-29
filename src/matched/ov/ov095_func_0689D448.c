/*
 * function: func_0689D448
 * address:  0x0689D448
 * packet:   pkt_ov095_0689D448
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0689D4A0  0x0689D4A0  thumb
 *   func_0689D4B0  0x0689D4B0  thumb
 *   func_0689D4C0  0x0689D4C0  thumb
 *   func_0689D4D0  0x0689D4D0  thumb
 *   func_0689D4E0  0x0689D4E0  thumb
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

extern int func_0689D4A0(int, int);
extern int func_0689D4B0(int, int);
extern int func_0689D4C0(int, int);
extern int func_0689D4D0(int, int);
extern int func_0689D4E0(int, int);

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
        if (func_0689D4A0(q->c, k) != 0)
            continue;
        func_0689D4C0(func_0689D4B0(c, q->c), k);
        func_0689D4E0(func_0689D4D0(c, k), q->c);
    }
}
