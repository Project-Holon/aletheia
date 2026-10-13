/*
 * function: func_021BC240
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
 *   func_02082BCC 0x02082BCC arm
 */
struct Obj0203159C;extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);extern void *PROCSYS_AllocProcWork(struct Obj0203159C *,unsigned,unsigned);extern void func_02082BCC(void *,int,int);
int func_021BC240(struct Obj0203159C *p,int unused,unsigned v){unsigned *q;GFL_HEAP_CreateChildHeap(1,107,0x60000);q=PROCSYS_AllocProcWork(p,0xc44,107);func_02082BCC(q,0,0xc44);*q=v;return 1;}
