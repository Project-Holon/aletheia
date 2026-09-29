/*
 * function: func_0217357C
 * address:  0x0217357C
 * packet:   pkt_ov012_0217357C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   memcmp        0x0203EFC8  arm
 *   MI_CpuCopy8   0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 mac[6];
    u8 f6;
    u8 b0 : 1;
    u8 b1 : 1;
} Rec;

extern int memcmp(const void *a, const void *b, int n);
extern void MI_CpuCopy8(const void *src, void *dst, int n);

int func_0217357C(u8 *self, const u8 *mac, u8 a2, u8 a3)
{
    int j;
    Rec *r;
    int i;
    Rec *e;

    i = 0;
    r = (Rec *)(self + 0x1c);
    for (; i < 5; i++) {
        if (r[i].b1 == 1 && memcmp(mac, &r[i], 6) == 0) {
            return i;
        }
    }
    for (j = 0; j < 5; j++) {
        e = (Rec *)(self + 0x1c) + j;
        if (e->b1 == 0) {
            MI_CpuCopy8(mac, e, 6);
            e->f6 = a2;
            e->b0 = a3;
            e->b1 = 1;
            return j;
        }
    }
    return 0;
}
