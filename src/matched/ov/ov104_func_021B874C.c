/*
 * function: IRC_RHYTHM_ExitNetSync
 * address: 0x021B874C
 * packet: pkt_ov104_021B874C
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   COMPATIBLE_IRC_SYS_DeleteCommandTable 0x021B6508 thumb ov101
 */
#include "../include/Obj22232.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
extern void COMPATIBLE_IRC_SYS_DeleteCommandTable(u32 p, u32 a);
void IRC_RHYTHM_ExitNetSync(u8 *p) { COMPATIBLE_IRC_SYS_DeleteCommandTable(((struct Obj22232 *)p)->f0,0xf00); MI_CpuFill8(p,0,0x198); }
