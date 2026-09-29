/*
 * function: func_0689CD78
 * address:  0x0689CD78
 * packet:   pkt_ov095_0689CD78
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689CB3C  0x0689CB3C  thumb
 *   func_0689CD38  0x0689CD38  thumb  ov095
 *   func_0689CC70  0x0689CC70  thumb  ov095
 *   func_0689CDBC  0x0689CDBC  thumb
 *   func_0689CB48  0x0689CB48  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 id[6];
    u16 a[6];
    u16 b[6];
    u8 c[6];
    u16 d[6];
    u8 n;
    u8 max;
    u8 f44;
    u8 f45;
} S;

void func_0689CB3C(S *p);
int func_0689CD38(S *p);
u32 func_0689CC70(S *p, u32 i);
int func_0689CDBC(u32 x);
void func_0689CB48(S *p, u32 id);

int func_0689CD78(S *p, S *q)
{
    u32 i;
    u32 n;
    u32 x;

    func_0689CB3C(q);
    n = func_0689CD38(p);
    for (i = 0; i < n; i++) {
        x = func_0689CC70(p, i);
        if (!func_0689CDBC(x))
            func_0689CB48(q, x);
    }
    return func_0689CD38(q);
}
