/*
 * function: func_021C17C4
 * address:  0x021C17C4
 * packet:   pkt_021C17C4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  body byte-identical; only the loop scaffolding differs.  Original
 *           keeps n in lr and recomputes n-1 each iteration, the compiler
 *           hoists n-1 into lr once.  Tried for()/while()/bound-in-local
 *           spellings, all hoist; 132 vs 140 bytes.
 *
 * 2026-10-02 (C1 lane 05): also tried guard + do/while with a local m = n - 1 - i; still hoists n - 1
 * into lr (132 bytes, 115 bytes differ).
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

void func_021C17C4(u8 *p)
{
    u8 n = *(u8 *)(p + 0x1AC);
    int i = 0;
    int j;

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
