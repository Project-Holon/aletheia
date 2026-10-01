/*
 * function: func_020249B0
 * address:  0x020249B0
 * packet:   pkt_020249B0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf: true when a == b, or when the first of 13 halfword
 * groups that contains a also contains b. Filed as the relocation witness for
 * ov021 func_021D213C (wave A1).
 *
 * symbols:
 *   data_0209F7C8  0x0209F7C8  data
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Group {
    const u16 *list;
    int count;
} Group;

extern const Group data_0209F7C8[13];

int func_020249B0(u32 a, u32 b)
{
    u32 i;
    int j, k;

    if (a == b) {
        return 1;
    }
    for (i = 0; i < 13; i++) {
        for (j = 0; j < data_0209F7C8[i].count; j++) {
            if (a == data_0209F7C8[i].list[j]) {
                for (k = 0; k < data_0209F7C8[i].count; k++) {
                    if (b == data_0209F7C8[i].list[k]) {
                        return 1;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}
