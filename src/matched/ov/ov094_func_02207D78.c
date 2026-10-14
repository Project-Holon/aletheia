/*
 * function: BTLV_GAUGE_TakeSlotEvent
 * address:  0x02207D78
 * packet:   pkt_ov094_02207D78
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lane S13 leaf of BTLV_INPUT_ClearSlotEvents
 */
typedef struct {
    unsigned int b0 : 27;
    unsigned int b27 : 1;
    unsigned int b28 : 4;
} Bits;

int BTLV_GAUGE_TakeSlotEvent(char *p, int i)
{
    int r = 0;

    if (*(int *)(p + i * 128 + 0x40) != 0) {
        Bits *q = (Bits *)(p + 0xb0 + i * 128);

        r = q->b27;
        q->b27 = 0;
    }
    return r;
}
