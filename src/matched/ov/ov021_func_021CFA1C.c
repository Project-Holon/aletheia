/*
 * function: SCRCMD_AddUniqueOtId
 * address:  0x021CFA1C
 * packet:   pkt_ov021_021CFA1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct IdList021CFA1C {
    int n;
    int ids[50];
} IdList021CFA1C;

int SCRCMD_AddUniqueOtId(int v, IdList021CFA1C *l)
{
    int i;

    if (l->n >= 50) {
        return 0;
    }
    for (i = 0; i < l->n; i++) {
        if (v == l->ids[i]) {
            return 0;
        }
    }
    l->ids[i] = v;
    l->n++;
    return 1;
}
