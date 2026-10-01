/*
 * function: func_021E0EAC
 * address: 0x021E0EAC
 * packet: pkt_ov137_021E0EAC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E15DC 0x021E15DC thumb ov137
 *   func_02082BCC 0x02082BCC arm
 */
extern void func_021E15DC(int *, int);
extern void func_02082BCC(void *, int, unsigned);
void func_021E0EAC(int *p)
{
    int *q = (int *)p[4];
    switch (p[1]) {
    case 0:
        p[3] = 0x18000;
        q[12] = 0;
        p[1]++;
    case 1:
        func_021E15DC(q + 12, p[3]);
        if (q[12] < 0x4000) {
            p[3] = (unsigned)p[3] >> 1;
            if (p[3] < 0x4000) {
                q[12] = 0;
                func_02082BCC(p, 0, 20);
            }
        }
        break;
    }
}
