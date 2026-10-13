/*
 * function: BTL_POKESET_AddWithDamage
 * address:  0x0689CBB8
 * packet:   pkt_ov095_0689CBB8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKESET_Add  0x0689CB48  thumb  ov095
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

void BTL_POKESET_Add(S *p, u32 id);

void BTL_POKESET_AddWithDamage(S *p, u32 id, u16 amt, int flag)
{
    u32 i;
    u32 t;

    BTL_POKESET_Add(p, id);
    for (i = 0; i < p->n; i++) {
        t = p->id[i];
        if (t == id) {
            if (flag) {
                p->b[i] += amt;
                p->c[i] = 2;
            } else {
                p->a[i] += amt;
                p->c[i] = 1;
            }
        }
    }
}
