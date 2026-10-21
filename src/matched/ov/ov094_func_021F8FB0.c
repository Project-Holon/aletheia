/*
 * function: BTLV_EFFECT_ClearTaskMaskM2
 * address:  0x021F8FB0
 * packet:   pkt_ov094_021F8FB0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the current task's mask bits from bits 16..17 of the word at 0x1ec of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   TCBL_GetOwnedWork 0x02030EE8 arm
 *   BTLV_EFFECT_GetBitMask 0x021F935C thumb ov094
 */
typedef struct {
    char pad[0x1ec];
    unsigned m0 : 8;
    unsigned m1 : 8;
    unsigned m2 : 2;
} Work;

extern Work *gBtlvEff;
typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_GetOwnedWork(struct S02030EE8 *p);
extern int BTLV_EFFECT_GetBitMask(int);

void BTLV_EFFECT_ClearTaskMaskM2(void *h)
{
    int m = BTLV_EFFECT_GetBitMask(((int *)TCBL_GetOwnedWork(h))[2]);
    gBtlvEff->m2 &= m ^ 0xffffffff;
}
