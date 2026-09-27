/*
 * function: func_02173B18
 * address:  0x02173B18
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_ClearGameMatchKeys: frees every game match key value and clears the key table.
 *
 * symbols:
 *   g_021AAA40  0x021AAA40  data
 *   DWC_Free  0x0205A1B0  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 */

typedef struct {
    int key;
    void *value;
    int type;
} MatchKey;

extern MatchKey g_021AAA40[];
extern void DWC_Free(int kind, void *p, int size);
extern void MIi_CpuClear32(int v, void *p, int size);

void func_02173B18(void)
{
    int i;

    for (i = 0; i < 0x9a; i++) {
        if (g_021AAA40[i].value != 0) {
            DWC_Free(4, g_021AAA40[i].value, 0);
        }
    }
    MIi_CpuClear32(0, g_021AAA40, sizeof(MatchKey) * 0x9a);
}
