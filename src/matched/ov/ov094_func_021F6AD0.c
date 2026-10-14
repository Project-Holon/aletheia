/*
 * function: BTLV_STAGE_IsAnyLayerArmed
 * address:  0x021F6AD0
 * packet:   pkt_ov094_021F6AD0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Returns 1 when any entry of either table is armed.
 */
typedef struct {
    int state;
    int armed;
    int a;
    int b;
} Entry;

typedef struct {
    int pad0;
    int n;              /* 0x04 */
    Entry *x;           /* 0x08 */
    Entry *y;           /* 0x0c */
} Obj;

int BTLV_STAGE_IsAnyLayerArmed(Obj *p)
{
    int i;

    for (i = 0; i < p->n; i++) {
        if (p->x[i].armed == 1 || p->y[i].armed == 1)
            return 1;
    }
    return 0;
}
