/*
 * function: PDC_ProcInit
 * address:  0x021B615C
 * packet:   pkt_ov098_021B615C
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov094_id       0x0000005E  data
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   PDC_MAIN_Create  0x021B61E8  thumb  ov098
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct W {
    u32 f00;
    u32 f04;
    u16 f08;
};

extern char ov094_id[];
extern int func_02034AC4(int id);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MIi_CpuClearFast(int v, void *p, u32 n);
extern u32 PDC_MAIN_Create(int a, int b);

int PDC_ProcInit(struct Proc *a, int b, int c)
{
    struct W *p;

    func_02034AC4((int)ov094_id);
    GFL_HEAP_CreateChildHeap(1, 0x85, 0xc0000);
    p = PROCSYS_AllocProcWork(a, 0xc, 0x85);
    MIi_CpuClearFast(0, p, 0xc);
    p->f08 = 0x85;
    p->f00 = PDC_MAIN_Create(c, p->f08);
    p->f04 = c;
    return 1;
}
