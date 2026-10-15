/*
 * function: STARTMENU_SaveEraseInit
 * address:  0x021BCCCC
 * packet:   pkt_ov088_021BCCCC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent runs 2 bytes past the compiled function;
 *           trailing alignment padding, no byte difference.
 *
 * Init of the second title proc (heap 0x81, 0x30000 bytes; 0x2C-byte work
 * area zeroed).  Same shape as STARTMENU_TitleDemoInit.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */

extern void  GFL_HEAP_CreateChildHeap(unsigned int a, unsigned int heap, unsigned int size);
typedef unsigned int   u32;
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void  MI_CpuFill8(void *p, int v, int n);

int STARTMENU_SaveEraseInit(struct Proc *a0)
{
    GFL_HEAP_CreateChildHeap(1, 0x81, 0x30000);
    MI_CpuFill8(PROCSYS_AllocProcWork(a0, 0x2c, 0x81), 0, 0x2c);
    return 1;
}
