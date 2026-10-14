/*
 * function: BTLV_EFFVM_SePlayTaskMain
 * address:  0x021FE54C
 * packet:   pkt_ov094_021FE54C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFVM_PlaySeWithParams  0x021FDB40  thumb  ov094
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 */
typedef unsigned int   u32;
extern void BTLV_EFFVM_PlaySeWithParams(u32 a0, int m, int a2, int a3, unsigned int e, unsigned int f, unsigned int g);
extern void BTLV_EFFECT_DeleteTask(void *h);

void BTLV_EFFVM_SePlayTaskMain(void *h, int *s)
{
    if (--s[4] == 0) {
        BTLV_EFFVM_PlaySeWithParams(s[1], s[2], s[3], s[5], s[6], s[7], s[8]);
        BTLV_EFFECT_DeleteTask(h);
    }
}
