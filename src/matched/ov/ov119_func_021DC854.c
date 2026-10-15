/*
 * function: POKETRADE_PROC_AllocTradeWork
 * address: 0x021DC854
 * packet: pkt_ov119_021DC854
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_RegisterBlockHeap 0x02030678 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   gTradeWorkHeapName 0x021E8560 data a4
 */
typedef unsigned int   u32;
extern void GFL_HEAP_RegisterBlockHeap(void *a, u32 b, u32 c);
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
extern char gTradeWorkHeapName[];
void *POKETRADE_PROC_AllocTradeWork(void *a,int t) {
 void *p;
 GFL_HEAP_RegisterBlockHeap(gTradeWorkHeapName,0xc000,0x91);
 GFL_HEAP_CreateChildHeap(1,31,t);
 p=PROCSYS_AllocProcWork(a,0x1d54,0x91);
 MI_CpuFill8(p,0,0x1d54);
 return p;
}
