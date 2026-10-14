/*
 * function: CircleGraph_SortSlices
 * address:  0x021C17C4
 * packet:   pkt_ov217_021C17C4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * note: bubble sort of 0x14-byte records by u32 key (descending). Counters and bound are int and are
 *   declared and assigned separately (int i; int n; int j; n = ...; i = 0;): that order puts n in lr and i
 *   in ip and keeps n - 1 unhoisted.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 f0;
    u32 f1;
    u32 f2;
    u32 f3;
    u32 f4;
} Rec;

void CircleGraph_SortSlices(u8 *p)
{
    int i;
    int n;
    int j;
    n = *(u8 *)(p + 0x1AC);
    i = 0;

    while (i < n - 1) {
        j = 0;
        while (j < n - 1 - i) {
            u8 *e = p + j * 0x14;
            if (*(u32 *)(e + 0x20) < *(u32 *)(e + 0x34)) {
                Rec t = *(Rec *)(e + 0x1C);
                *(Rec *)(e + 0x1C) = *(Rec *)(e + 0x30);
                *(Rec *)(e + 0x30) = t;
            }
            j++;
        }
        i++;
    }
}
