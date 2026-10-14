/*
 * function: GURU2_MAIN_UpdateSettleEffect
 * address: 0x021E0EAC
 * packet: pkt_ov137_021E0EAC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GURU2_MAIN_AddAngleWrapped 0x021E15DC thumb ov137
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void GURU2_MAIN_AddAngleWrapped(int *, int);
extern void MI_CpuFill8(void *, int, unsigned);
void GURU2_MAIN_UpdateSettleEffect(int *p)
{
    int *q = (int *)p[4];
    switch (p[1]) {
    case 0:
        p[3] = 0x18000;
        q[12] = 0;
        p[1]++;
    case 1:
        GURU2_MAIN_AddAngleWrapped(q + 12, p[3]);
        if (q[12] < 0x4000) {
            p[3] = (unsigned)p[3] >> 1;
            if (p[3] < 0x4000) {
                q[12] = 0;
                MI_CpuFill8(p, 0, 20);
            }
        }
        break;
    }
}
