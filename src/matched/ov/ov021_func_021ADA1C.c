/*
 * function: func_021ADA1C
 * address:  0x021ADA1C
 * packet:   pkt_ov021_021ADA1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AD8A4  0x021AD8A4  thumb  ov021
 *   func_02046EFC  0x02046EFC  arm
 *   func_020470D0  0x020470D0  arm
 */
typedef unsigned char u8;

typedef struct Q {
    int f0;
    int f4;
    int f8[4];
    int f18[28];
    u8 n;
    u8 cnt : 3;
} Q;

extern void func_021AD8A4(void *a, Q *b);
typedef unsigned int   u32;
struct Tagged;
extern void func_02046EFC(struct Tagged *p);
extern int func_020470D0(u32 *p);

void func_021ADA1C(Q *a)
{
    int i;

    for (i = 0; i < a->cnt; i++) {
        func_021AD8A4((char *)a + 0x28 + i * 0x18, a);
    }
    for (i = 0; i < a->n * a->cnt; i++) {
        func_02046EFC((struct Tagged *)a->f18[i]);
    }
    for (i = 0; i < a->cnt; i++) {
        func_020470D0((u32 *)a->f8[i]);
        func_02046EFC((struct Tagged *)a->f8[i]);
    }
}
