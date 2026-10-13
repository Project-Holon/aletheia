/*
 * function: func_021DC860
 * address: 0x021DC860
 * packet: pkt_ov171_021DC860
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: PROCSYS_AllocProcWork returns the allocated buffer in r0 despite its legacy void declaration; original 021DC882 copies r0 to r4 and clears/stores through it.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj0203159C;
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C*,u32,u32);
extern void MI_CpuFill8(void*,u32,u32);
int func_021DC860(struct Obj0203159C*p,void*unused,u32 n){u32*q;GFL_HEAP_CreateChildHeap(1,0x8c,0x60000);q=PROCSYS_AllocProcWork(p,0xc78,0x8c);MI_CpuFill8(q,0,0xc78);*q=n;return 1;}
