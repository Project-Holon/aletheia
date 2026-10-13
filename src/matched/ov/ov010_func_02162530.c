/*
 * function: EVENTDATA_SYSTEM_ClearEventTables
 * address: 0x02162530
 * packet: pkt_ov010_02162530
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj02059.h"
typedef unsigned short u16;
extern void MI_CpuFill8(void *, int, int);
void EVENTDATA_SYSTEM_ClearEventTables(char *p) { ((struct Obj02059 *)p)->f2C=0; ((struct Obj02059 *)p)->f2E=0; ((struct Obj02059 *)p)->f30=0; ((struct Obj02059 *)p)->f32=0; ((struct Obj02059 *)p)->f12=0; ((struct Obj02059 *)p)->f14=0; ((struct Obj02059 *)p)->f16=0; ((struct Obj02059 *)p)->f18=0; ((struct Obj02059 *)p)->f1C=0; ((struct Obj02059 *)p)->f20=0; ((struct Obj02059 *)p)->f24=0; ((struct Obj02059 *)p)->f28=0; MI_CpuFill8(p+0x128,0,0x880); }
