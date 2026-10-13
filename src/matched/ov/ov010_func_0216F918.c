/*
 * function: WAZA_OSHIE_Create
 * address: 0x0216F918
 * packet: pkt_ov010_0216F918
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_02172B74 0x02172B74 data ov010 a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_02172B74[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,int);
void *WAZA_OSHIE_Create(u32 heap) { void *p; p=func_02030734(heap,28,0,d_02172B74,35); MI_CpuFill8(p,0,28); return p; }
