/*
 * function: SODATEYA_DeclineEgg
 * address:  0x021C335C
 * packet:   pkt_ov021_021C335C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stops the running timer and closes the record.
 *
 * symbols:
 *   DAYCARE_GetEggReady  0x0200BCA0  thumb
 *   DAYCARE_ClearEggReady  0x0200BC20  thumb
 *   SODATEYA_ClearEggFlag  0x021C33E0  thumb  ov021
 */

struct Obj11233;
extern int DAYCARE_GetEggReady(struct Obj11233 *p);
struct Obj11232;
extern void DAYCARE_ClearEggReady(struct Obj11232 *p);
extern void SODATEYA_ClearEggFlag(void *a);

void SODATEYA_DeclineEgg(void **p)
{
    if (DAYCARE_GetEggReady(p[2]) == 1) {
        DAYCARE_ClearEggReady(p[2]);
        SODATEYA_ClearEggFlag(p[1]);
    }
}
