/*
 * function: IRC_COMPATIBLE_HelpStepCreateArgs
 * address: 0x021B6E8C
 * packet: pkt_ov101_021B6E8C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   IRC_COMPATIBLE_SourceFileName 0x021B753C data a1
 */
#include "../include/Obj22124.h"
#include "../include/Obj22125.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,u32);
extern const char IRC_COMPATIBLE_SourceFileName[];
void *IRC_COMPATIBLE_HelpStepCreateArgs(u32 heap,u8 *p) { void *q; q=func_02030734(heap,4,0,IRC_COMPATIBLE_SourceFileName,0x49b); MI_CpuFill8(q,0,4); ((struct Obj22125 *)q)->f0=**(u32 * *)&((struct Obj22124 *)p)->f10; return q; }
