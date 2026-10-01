/*
 * function: func_0200BD48
 * address:  0x0200BD48
 * packet:   pkt_0200BD48
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 func_021C3378
 * (wave A1, lane 13).
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    int active;
    u8 data[0xDC];
    u32 count;
} E;

void func_0200BD48(E *e, u32 add)
{
    int i;
    u64 v;

    for (i = 0; i < 2; i++) {
        if (e[i].active == 1) {
            v = (u64)e[i].count + add;
            if (v > 0xFFFFFFFF)
                v = 0xFFFFFFFF;
            e[i].count = v;
        }
    }
}
