/*
 * function: INTRUDE_COMM_AdjustRemotePosition
 * address:  0x021751D4
 * packet:   pkt_ov011_021751D4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_LookupZonePair  0x02175144  thumb ov011
 *   INTRUDE_COMM_CompareZonePair  0x02175184  thumb ov011
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   INTRUDE_COMM_GetRelativeSlot  0x021751A8  thumb ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Ent {
    int f0;
    int f4;
    u8 pad8[0xc];
    u16 f14;
    u16 a : 3;
    u16 rest : 13;
} Ent;

int INTRUDE_COMM_LookupZonePair(u16 v, u8 *out);
int INTRUDE_COMM_CompareZonePair(u8 *a, u8 *b);
typedef unsigned int   u32;
u32 ZONEDATA_IsEntralink(u32 id);
int INTRUDE_COMM_GetRelativeSlot(u8 *p, int a);

void INTRUDE_COMM_AdjustRemotePosition(u8 *p, u16 a, int b, Ent *c)
{
    u8 x[4];
    u8 y[4];
    int r;
    int w;
    int k;
    int n;

    INTRUDE_COMM_LookupZonePair(a, x);
    INTRUDE_COMM_LookupZonePair(c->f14, y);
    r = INTRUDE_COMM_CompareZonePair(x, y);
    switch (r) {
    case 1:
        break;
    case 2:
        break;
    case 0:
        if (ZONEDATA_IsEntralink(a) != 0) {
            w = c->f4 % 0x400000;
            k = INTRUDE_COMM_GetRelativeSlot(p, c->a);
            n = p[0x902];
            if (k == n - 1 && w > 0x200000 && b < 0x200000) {
                c->f4 = w - 0x400000;
            } else if (k == 0 && w < 0x200000 && b > (n << 22) - 0x200000) {
                c->f4 = w + (n << 22);
            } else {
                c->f4 = w + (k << 22);
            }
        }
        break;
    }
}
