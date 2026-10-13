/*
 * function: BTLV_CORE_StartOpening
 * address:  0x021E90A0
 * packet:   pkt_ov093_021E90A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvOpeningStepTable  0x021F3840  data  a4
 *   d_021F3844  0x021F3844  data  a4
 */
struct E {
    unsigned int k;
    unsigned int v;
};

extern const struct E gBtlvOpeningStepTable[];
extern const struct E d_021F3844[];

void BTLV_CORE_StartOpening(unsigned int *o, unsigned int key)
{
    unsigned int i;

    for (i = 0; i < 2; i++) {
        if (key == gBtlvOpeningStepTable[i].k) {
            o[4] = key;
            o[5] = d_021F3844[i].k;
            o[6] = 0;
            return;
        }
    }
}
