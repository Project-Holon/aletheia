/*
 * function: WEATHER_TASK_Reset
 * address:  0x021A26D8
 * packet:   pkt_ov021_021A26D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

void MI_CpuFill8(void *p, int v, int n);

void WEATHER_TASK_Reset(int *p)
{
    int f0;
    int f4;
    int f10;
    int f8;
    int f18;
    int f14;
    int fc;
    unsigned short h;

    f0 = p[0];
    f4 = p[1];
    f14 = p[5];
    f10 = p[4];
    fc = p[3];
    f8 = p[2];
    h = *(unsigned short *)&p[7];
    f18 = p[6];
    MI_CpuFill8(p, 0, 0x784);
    p[5] = f14;
    p[0] = f0;
    p[3] = fc;
    p[1] = f4;
    *(unsigned short *)&p[7] = h;
    p[2] = f8;
    p[6] = f18;
    p[4] = f10;
}
