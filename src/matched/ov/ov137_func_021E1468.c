/*
 * function: GURU2_MAIN_PulseEffectTask
 * address: 0x021E1468
 * packet: pkt_ov137_021E1468
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GURU2_MAIN_UpdatePulseEffect 0x021E141C thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void GURU2_MAIN_UpdatePulseEffect(void *, int *);
void GURU2_MAIN_PulseEffectTask(void *unused, char *p)
{
    int i;
    int *q = (int *)(p + 0xc90);
    for (i = 0; i < 5; i++, q += 4) GURU2_MAIN_UpdatePulseEffect(p, q);
}
