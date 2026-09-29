/*
 * function: func_0689CC14
 * address:  0x0689CC14
 * packet:   pkt_ov095_0689CC14
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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

void func_0689CC14(S *p, u32 id)
{
    u32 i;
    u32 j;
    u8 n = p->n;
    u32 t;

    for (i = 0; i < n; i++) {
        t = p->id[i];
        if (t == id) {
            for (j = i + 1; j < p->n; j++)
                p->id[j - 1] = p->id[j];
            p->n--;
            p->f44--;
            return;
        }
    }
}
