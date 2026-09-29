/*
 * function: func_0689CB48
 * address:  0x0689CB48
 * packet:   pkt_ov095_0689CB48
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

void func_0689CB48(S *p, u32 id)
{
    u32 i;
    u8 n = p->n;

    if (n < 6) {
        for (i = 0; i < n; i++) {
            u32 t = p->id[i];
            if (t == id)
                return;
        }
        p->id[n] = id;
        p->c[p->n] = 0;
        p->a[p->n] = 0;
        p->b[p->n] = 0;
        p->n = p->n + 1;
        if (p->n > p->max)
            p->max = p->n;
    }
}
