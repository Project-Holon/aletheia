/*
 * function: PARTY_STATUS_CreateSub
 * address:  0x021E5838
 * packet:   pkt_021E5838
 * region:   ov178
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap   0x0203064C  arm
 *   PROCSYS_AllocProcWork   0x0203159C  arm
 *   MI_CpuFill8   0x02082BCC  arm
 *   PARTY_STATUS_Noop   0x021E58F0  thumb
 *   PARTY_STATUS_CreateSubWork   0x021E5A70  thumb
 *
 * Allocate the 0x58-byte subobject and dispatch on track[1].
 */


extern void GFL_HEAP_CreateChildHeap(unsigned int, unsigned int, unsigned int);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(int, int, int);
extern void PARTY_STATUS_Noop(int, int *, int);
typedef unsigned int   u32;
extern void PARTY_STATUS_CreateSubWork(u32 *out, u32 **pp, u32 v);

int PARTY_STATUS_CreateSub(struct Proc *a, int b, int *p)
{
    int h;
    GFL_HEAP_CreateChildHeap(1, 0x58, 0x10000);
    h = (int)PROCSYS_AllocProcWork(a, 4, 0x58);
    MI_CpuFill8(h, 0, 4);
    p[2] = 0;
    switch (p[1]) {
    case 0:
        PARTY_STATUS_Noop(h, p, 0x58);
        break;
    case 1:
        PARTY_STATUS_CreateSubWork((u32 *)h, (u32 **)p, 0x58);
        break;
    }
    return 1;
}
