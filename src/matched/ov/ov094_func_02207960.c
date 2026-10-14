/*
 * function: BTLV_GAUGE_DeleteSlotTask
 * address:  0x02207960
 * packet:   pkt_ov094_02207960
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_GAUGE_PlaceSlot  0x022079C0  thumb  ov094
 *   func_02030EAC  0x02030EAC  arm
 *   gBtlvGaugeSlideOutOffset     0x0220AAB4  data   ov094  a2
 */
typedef struct {
    short x;
    short y;
} Pt;

typedef struct {
    unsigned int lo : 3;
    unsigned int b3 : 1;
} Bf;

extern const Pt gBtlvGaugeSlideOutOffset;
extern void BTLV_GAUGE_PlaceSlot(char *p, int i, Pt *pt);
struct Node;
extern void func_02030EAC(struct Node *n);

void BTLV_GAUGE_DeleteSlotTask(char *p, int i)
{
    char *q = p + 0xb0;
    int o = i * 128;
    void *t;

    if (((Bf *)(q + o))->b3) {
        Pt pt = gBtlvGaugeSlideOutOffset;

        if (i & 1)
            pt.x *= -1;
        BTLV_GAUGE_PlaceSlot(p, i, &pt);
        ((Bf *)(q + o))->b3 = 0;
    }
    t = *(void **)(p + o + 0xbc);
    if (t != 0) {
        func_02030EAC(t);
        *(int *)(p + o + 0xbc) = 0;
    }
}
