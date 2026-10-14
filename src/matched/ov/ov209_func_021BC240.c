/*
 * function: ZUKAN_LIST_ProcInit
 * address: 0x021BC240
 * packet: pkt_ov209_021BC240
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 */
struct Obj0203159C;extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);extern void *PROCSYS_AllocProcWork(struct Obj0203159C *,unsigned,unsigned);extern void MI_CpuFill8(void *,int,int);
int ZUKAN_LIST_ProcInit(struct Obj0203159C *p,int unused,unsigned v){unsigned *q;GFL_HEAP_CreateChildHeap(1,107,0x60000);q=PROCSYS_AllocProcWork(p,0xc44,107);MI_CpuFill8(q,0,0xc44);*q=v;return 1;}
