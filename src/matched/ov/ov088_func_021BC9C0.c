/*
 * function: STARTMENU_LogoScreenInit
 * address:  0x021BC9C0
 * packet:   pkt_ov088_021BC9C0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */

extern void  GFL_HEAP_CreateChildHeap(unsigned int a, unsigned int heap, unsigned int size);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  MI_CpuFill8(void *p, int v, int n);

int STARTMENU_LogoScreenInit(struct Obj0203159C *a0)
{
    GFL_HEAP_CreateChildHeap(1, 0x16, 0x70000);
    MI_CpuFill8(PROCSYS_AllocProcWork(a0, 8, 0x16), 0, 8);
    return 1;
}
