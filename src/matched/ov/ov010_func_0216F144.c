/*
 * function: TRCARD_SYS_InitMinimal
 * address: 0x0216F144
 * packet: pkt_ov010_0216F144
 * region: ov010
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

typedef struct { int w[8]; } W;
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
int TRCARD_SYS_InitMinimal(void *a,int b,int c) { W *w; GFL_HEAP_CreateChildHeap(1,38,0x18000); w=PROCSYS_AllocProcWork(a,32,38); MI_CpuFill8(w,0,32); w->w[0]=38; w->w[6]=c; return 1; }
