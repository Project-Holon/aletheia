/*
 * function: BTL_SERVER_FLOW_SortActionOrder
 * address:  0x021BC874
 * packet:   pkt_ov093_021BC874
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u32 a, b, key, d; } E;

extern u32 BTL_CALC_Random(u32 range);

void BTL_SERVER_FLOW_SortActionOrder(E *p, u32 n)
{
    u32 i;
    u32 j;
    E *a;
    E *b;
    E t;
    for (i = 0; i < n; i++) {
        j = i + 1;
        if (j < n) {
            a = &p[i];
            do {
                b = &p[j];
                if (a->key <= b->key && (a->key != b->key || BTL_CALC_Random(2) != 0)) {
                    t = *a;
                    *a = *b;
                    *b = t;
                }
                j++;
            } while (j < n);
        }
    }
}
