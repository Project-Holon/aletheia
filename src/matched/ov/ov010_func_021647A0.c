/*
 * function: CALENDER_Create
 * address: 0x021647A0
 * packet: pkt_ov010_021647A0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   CalenderFileName 0x021729B0 data ov010 a1
 *   CALENDER_ClearResources 0x021647F0 thumb ov010
 *   CALENDER_OpenArchive 0x021647FC thumb ov010
 *   CALENDER_LoadZoneTable 0x02164890 thumb ov010
 */
#include "../include/Obj04133.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char CalenderFileName[];
extern int CALENDER_ClearResources(int a0);
extern void *CALENDER_OpenArchive(int a0);
extern void CALENDER_LoadZoneTable(u8 *);
u8 *CALENDER_Create(void *a,u32 b){u8 *p=func_02030734(b,0x11c,0,CalenderFileName,0x53);CALENDER_ClearResources((int)p);((struct Obj04133 *)p)->f0=b;((struct Obj04133 *)p)->f4=a;CALENDER_OpenArchive((int)p);CALENDER_LoadZoneTable(p);return p;}
