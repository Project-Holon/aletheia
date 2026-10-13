/*
 * function: PMS_WORD_MakeWordId
 * address:  0x02024888
 * packet:   pkt_02024838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_tbl0   0x0209F7AC  data
 *   g_tbl1   0x0209F792  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 g_tbl0[];
extern u16 g_tbl1[];

u16 PMS_WORD_MakeWordId(u32 idx, u16 add)
{
    u32 i;
    u16 sum;
    u16 k;

    for (i = 0; i < 0xD; i++) {
        if (idx == g_tbl0[i]) {
            k = 0;
            sum = 0;
            for (; k < i; k++) {
                sum = (u16)(sum + g_tbl1[k]);
            }
            return (u16)(sum + add);
        }
    }
    return 0xFFFF;
}
