/*
 * function: BTLV_SCU_RunProc
 * address:  0x021EB52C
 * packet:   pkt_ov093_021EB52C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned int u32;

typedef struct {
    u32 pad[0x38];
    int (*cb1)(void *, u32);   /* 0xe0 */
    int (*cb2)(void *, u32);   /* 0xe4 */
    u32 arg;                   /* 0xe8 */
    u32 obj;                   /* 0xec */
} CbSlot;

int BTLV_SCU_RunProc(CbSlot *s)
{
    if (s->cb1 != 0) {
        if (s->cb1(&s->obj, s->arg) != 0) {
            s->cb1 = 0;
            s->obj = 0;
        }
        return 0;
    }
    if (s->cb2 != 0) {
        if (s->cb2(&s->obj, s->arg) != 0) {
            s->cb2 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}
