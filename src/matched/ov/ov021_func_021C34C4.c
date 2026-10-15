/*
 * function: SODATEYA_GetCompatibility
 * address:  0x021C34C4
 * packet:   pkt_ov021_021C34C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Compatibility of the two deposited Pokemon, 0 when fewer than two (EXACT*: pad).
 *
 * symbols:
 *   DAYCARE_GetInUseCount  0x0200BCB8  thumb
 *   DAYCARE_GetSlotMon  0x0200BC2C  thumb
 *   SODATEYA_CalcCompatibility  0x021C36EC  thumb  ov021
 */

typedef unsigned char u8;

extern void *DAYCARE_GetSlotMon(void *e, int i);
extern int DAYCARE_GetInUseCount(void *e);
typedef unsigned int   u32;
extern int SODATEYA_CalcCompatibility(u32 a, u32 b);

u8 SODATEYA_GetCompatibility(void **p)
{
    void *a;

    if (DAYCARE_GetInUseCount(p[2]) < 2)
        return 0;
    a = DAYCARE_GetSlotMon(p[2], 0);
    return SODATEYA_CalcCompatibility((u32)a, (u32)DAYCARE_GetSlotMon(p[2], 1));
}
