/*
 * function: func_021C1CD4
 * address:  0x021C1CD4
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C3720     0x021C3720  data   ov099
 */
typedef unsigned char u8;

typedef struct {
    char pad[0x8ed];
    u8 f8ed;                /* 0x8ed */
    u8 f8ee;                /* 0x8ee */
    u8 f8ef;                /* 0x8ef */
    u8 f8f0;                /* 0x8f0 */
    u8 f8f1;                /* 0x8f1 */
    u8 f8f2;                /* 0x8f2 */
} Work;

extern const u8 d_021C3720[];

void func_021C1CD4(Work *w)
{
    if (w->f8ed) {
        w->f8ee = d_021C3720[w->f8f2];
        w->f8f2++;
        w->f8f1 = 1;
        if (w->f8f2 >= 16) {
            w->f8f2 = 0;
            w->f8ee = 0;
            w->f8ef = 1;
        }
    }
}
