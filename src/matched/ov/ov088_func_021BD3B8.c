/*
 * function: SAVE_CONTROL_INTR_Cancel
 * address:  0x021BD3B8
 * packet:   pkt_ov088_021BD3B8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SAVE_CONTROL_CancelSave  0x020071A8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    void *p0;
    u8 _4;
    u8 _5;
    u8 _6;
    u8 f7;
} Req;

extern int SAVE_CONTROL_CancelSave(int a0);

void SAVE_CONTROL_INTR_Cancel(Req *r)
{
    if (r->f7 == 0 && r->_4 != 3) {
        SAVE_CONTROL_CancelSave((int)r->p0);
        r->f7 = 1;
    }
}
