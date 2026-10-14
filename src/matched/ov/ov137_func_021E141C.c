/*
 * function: GURU2_MAIN_UpdatePulseEffect
 * address: 0x021E141C
 * packet: pkt_ov137_021E141C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGuru2PulseScaleTable 0x021E2278 data a4
 */
extern const int gGuru2PulseScaleTable[];
void GURU2_MAIN_UpdatePulseEffect(void *unused, int *p)
{
    switch (p[0]) {
    case 0: break;
    case 1:
        *(int *)(p[3] + 0x54) = gGuru2PulseScaleTable[p[1]] << 12;
        p[1]++;
        if (p[1] >= 16) {
            p[1] = 0;
            p[0]++;
        }
        break;
    case 2:
        p[2]++;
        if (p[2] >= 15) {
            p[2] = 0;
            p[0] = 1;
        }
        break;
    }
}
