/*
 * function: func_021C24A4
 * address:  0x021C24A4
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005CBC  0x02005CBC  thumb
 *   func_02006734  0x02006734  thumb
 */
typedef unsigned char u8;

typedef struct {
    char pad[0x1340];
    u8 f1340;
    u8 f1341;
    u8 f1342;
    u8 f1343;
} Work;

extern void func_02005CBC(int v, int n);
extern void func_02006734(int v);

void func_021C24A4(Work *w, int v)
{
    if (w->f1342 != v) {
        w->f1341 = w->f1340;
        w->f1343 = 6;
        w->f1342 = v;
        func_02005CBC(v, 0x3f);
        func_02006734(v);
    }
}
