/*
 * function: func_021E0FAC
 * address: 0x021E0FAC
 * packet: pkt_ov137_021E0FAC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0203F5FC has no outside code witness; verified scratch-only EXACT.
 *   typedef unsigned short u16;
 *   extern const short FX_SinCosTable_[];
 *   int func_0203F5FC(u16 angle) {
 *       if (angle >= 360) return 0;
 *       return FX_SinCosTable_[((angle * 65535 / 360) >> 4) * 2];
 *   }
 *   symbols: FX_SinCosTable_ 0x020A1B38 data a2
 * symbols:
 *   func_021E15DC 0x021E15DC thumb ov137
 *   func_0203F5FC 0x0203F5FC arm
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned short u16;
extern void func_021E15DC(int *, int);
typedef unsigned int   u32;
extern int func_0203F5FC(u32 x);
extern void MI_CpuFill8(void *, int, unsigned);
void func_021E0FAC(int *p)
{
    int *q = (int *)p[5];
    int old;
    int amount;
    switch (p[1]) {
    case 0:
        q[13] = 0;
        p[4] = 0;
        p[2] = 0x1e000;
        p[3] = 0x14000;
        p[1]++;
    case 1:
        amount = func_0203F5FC((u16)(p[4] / 4096)) * (p[2] / 4096);
        q[13] = 0;
        func_021E15DC(q + 13, amount);
        old = p[4];
        func_021E15DC(p + 4, p[3]);
        if (p[4] < old) {
            p[2] = (unsigned)p[2] >> 1;
            if (p[2] == 0) {
                q[13] = 0;
                MI_CpuFill8(p, 0, 24);
            }
        }
        break;
    }
}
