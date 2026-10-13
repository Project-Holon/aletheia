/*
 * function: SCRIPT_WORK_RestoreLocalWork
 * address: 0x021590D4
 * packet: pkt_ov010_021590D4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_GetLocalWork 0x02158FD0 thumb ov010
 *   MIi_CpuCopy16 0x02082A60 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned int   u32;
extern int SCRIPT_WORK_GetLocalWork(int a0, u32 a1, int a2);
extern void MIi_CpuCopy16(const void *, void *, unsigned int);
extern u32 func_020307B0(void *p);
void SCRIPT_WORK_RestoreLocalWork(void *a, void *b, int a2)
{
    void *p = (void *)SCRIPT_WORK_GetLocalWork((int)a, 0x8020, a2);
    MIi_CpuCopy16(b, p, 0x7e);
    func_020307B0(b);
}
