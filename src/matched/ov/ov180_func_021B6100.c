/*
 * function: HALL_OF_FAME_ProcInit
 * address: 0x021B6100
 * packet: pkt_ov180_021B6100
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 0203159C own source says void; caller consumes live allocation r0,
 * and full callee stores that pointer then leaves r0 unchanged through return.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm  arm9
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */
typedef unsigned int u32;
struct Proc;
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, u32, u32);
int HALL_OF_FAME_ProcInit(struct Proc *obj, void *unused, u32 value)
{
    u32 *p;
    GFL_HEAP_CreateChildHeap(1, 141, 0x60000);
    p = PROCSYS_AllocProcWork(obj, 0x919C, 141);
    MI_CpuFill8(p, 0, 0x919C);
    *p = value;
    return 1;
}
